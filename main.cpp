#include <iostream>

#include "UDPClient.h"
#include "Utils.h"

using boost::asio::ip::udp;

int main(int argc, char *argv[]) {
    try {
        if (argc != 4)
        {
            return Utils::print_usage();
        }

        std::string port = Utils::get_parameter(argv[2]);
        std::string host = Utils::get_parameter(argv[1]);
        std::string message = Utils::get_parameter(argv[3]);

        if(port.empty() || host.empty() || message.empty())
            return Utils::print_usage();

        boost::asio::io_service io_service;
        UDPClient client{io_service, host, port};
        client.send_message(message);

    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
