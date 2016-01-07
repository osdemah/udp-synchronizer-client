//
// Created by hamed on 1/7/16.
//

#include "UDPClient.h"

UDPClient::UDPClient(boost::asio::io_service& io_service, std::string host, std::string port):
     socket_{io_service}
{
    udp::resolver resolver(io_service);
    udp::resolver::query query(udp::v4(), host, port);
    sender_endpoint_ = *resolver.resolve(query);
    socket_.open(udp::v4());
}

UDPClient::~UDPClient(){
    socket_.close();
}

void UDPClient::send_message(std::string message) {
    socket_.send_to(boost::asio::buffer(message), sender_endpoint_);
}