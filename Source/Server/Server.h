#pragma once

#include <boost/asio.hpp>

class Server final
{
    using BoostTCPSocket = boost::asio::ip::tcp::socket;

public:
    explicit Server();

    void run();

private:
    void startAccept();

    void startRead(const std::shared_ptr<BoostTCPSocket>& socket);
    void broadcast(const std::string& message, const std::shared_ptr<BoostTCPSocket>& sender);
    void handleMessage(const std::shared_ptr<BoostTCPSocket> &sender, const std::string& message);

private:
    boost::asio::io_context _ioContext;
    boost::asio::ip::tcp::acceptor _acceptor;
    std::unordered_map<std::string, std::shared_ptr<BoostTCPSocket>> _clients;
};