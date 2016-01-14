#include <iostream>

#include "UDPClient.h"
#include "utils.h"

#include <boost/filesystem.hpp>
#include <fstream>

using namespace boost::filesystem;
using boost::asio::ip::udp;

const int CHUNK_SIZE = 512;

int main(int argc, char *argv[]) {
    try {
        if (argc != 5) {
            return utils::print_usage();
        }

        std::string port = utils::get_parameter(argv[2]);
        std::string host = utils::get_parameter(argv[1]);
        std::string operation = utils::get_parameter(argv[3]);
        std::string filename = utils::get_parameter(argv[4]);

        if (port.empty() || host.empty() || operation.empty() || filename.empty() || !utils::check_operation(operation))
            return utils::print_usage();

        boost::asio::io_service io_service;
        UDPClient client{io_service, host, port};

        path p{filename};

        if(exists(p) && ((utils::contains(operation, "FILE") && is_regular_file(p)) ||
                    (utils::contains(operation, "DIR") && is_directory(p)))) {
            if (operation.compare("CREATE_FILE") == 0) {
                std::ifstream file (filename, std::ios::in|std::ios::binary|std::ios::ate);
                if (file.is_open())
                {
                    std::cout << "sending chunks of file" << std::endl;
                    unsigned long size = file.tellg();
                    char * buffer = new char[CHUNK_SIZE];
                    unsigned long pos = 0;
                    for(unsigned long i = 0; i < size / CHUNK_SIZE + 1; i ++){
                        std::string content;
                        if(i != size / CHUNK_SIZE) {
                            file.seekg(pos, std::ios::beg);
                            file.read(buffer, CHUNK_SIZE);
                            content = std::string{buffer, CHUNK_SIZE};
                        }else{
                            int s = static_cast<int>(size - pos);
                            file.read(buffer, s);
                            content = std::string{buffer, s};
                        }
                        std::string bare_message = filename + ";" + std::to_string(pos) + ";" + content;
                        std::string hash_code = utils::hash_message(bare_message);
                        std::string message = hash_code + ";" + "CH;" + bare_message;
                        client.send_message(message);
                        std::cout << "#" << i << " chunk!" << std::endl;
                        pos += CHUNK_SIZE;
                    }
                    file.close();
                    delete[] buffer;
                    std::cout << "all chunks sent!" << std::endl;
                }
            }else{
                std::string message = operation + ";" + filename;
                std::string hash = utils::hash_message(message);
                message = hash + ";" + "OP" + ";" + message;
                client.send_message(message);
                std::cout << "message sent" << std::endl;
            }
        }else{
            std::cout << "no such file or directory!" << std::endl;
        }

    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

