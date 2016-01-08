#include <iostream>

#include "UDPClient.h"
#include "Utils.h"

using boost::asio::ip::udp;

int main(int argc, char *argv[]) {
    try {
        if (argc != 5)
        {
            return Utils::print_usage();
        }

        std::string port = Utils::get_parameter(argv[2]);
        std::string host = Utils::get_parameter(argv[1]);
        std::string operation = Utils::get_parameter(argv[3]);
        std::string filename = Utils::get_parameter(argv[4]);

        if(port.empty() || host.empty() || operation.empty())
            return Utils::print_usage();

        std::string message;
        if(operation != "CREATE_FILE")
            message = operation + ";;" + filename;
        else {
            std::cerr << "NOT SUPPORT YET!" << std::endl;
            return Utils::print_usage();
        }

        boost::asio::io_service io_service;
        UDPClient client{io_service, host, port};
        client.send_message(message);

    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
