//
// Created by hamed on 1/7/16.
//

#ifndef ZAEIMCO_CLIENT_UDPCLIENT_H
#define ZAEIMCO_CLIENT_UDPCLIENT_H

#include <boost/array.hpp>
#include <boost/asio.hpp>

#include <string>

using boost::asio::ip::udp;

class UDPClient {
public:
    UDPClient(boost::asio::io_service& io_service, std::string host, std::string port);
    ~UDPClient();
    void send_message(std::string message);
private:
    udp::socket socket_;
    udp::endpoint sender_endpoint_;
};


#endif //ZAEIMCO_CLIENT_UDPCLIENT_H
