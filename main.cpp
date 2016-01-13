#include <iostream>

#include "UDPClient.h"
#include "utils.h"

using boost::asio::ip::udp;

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

        std::string message = operation + ";;" + filename;
        std::string hash = utils::hash_message(message);
        message = hash + ";;" + message;

        boost::asio::io_service io_service;
        UDPClient client{io_service, host, port};
        client.send_message(message);

    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

