#include "Server.h"

#include <iostream>

Server::Server()
    : _ioContext(),
      _acceptor(_ioContext, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 8080))
{
    startAccept();
}

void Server::run() { _ioContext.run(); }

void Server::startAccept()
{
    auto socket = std::make_shared<BoostTCPSocket>(_acceptor.get_executor());
    _acceptor.async_accept(*socket,
                           [this, socket](boost::system::error_code ec)
                           {
                               if (!ec)
                               {
                                   std::cout << "New client connected!\n";
                                   startRead(socket);
                               }
                               startAccept();
                           });
}

void Server::startRead(const std::shared_ptr<BoostTCPSocket>& socket)
{
    auto buffer = std::make_shared<std::vector<char>>(1024);
    socket->async_read_some(boost::asio::buffer(*buffer),
                            [this, socket, buffer](boost::system::error_code ec, std::size_t length)
                            {
                                if (!ec)
                                {
                                    std::string msg(buffer->begin(), buffer->begin() + length);
                                    handleMessage(socket, msg);
                                    startRead(socket);
                                }
                            });
}

void Server::broadcast(const std::string& message, const std::shared_ptr<BoostTCPSocket>& sender) {}

void Server::handleMessage(const std::shared_ptr<BoostTCPSocket> &sender, const std::string& message)
{
    if (message.starts_with("USER:"))
    {
        std::string username = message.substr(5);
        _clients[username] = sender;
        std::cout << "Client " << username << " registered\n";
        return;
    }

    if (message.starts_with("TO:"))
    {
        size_t first_colon = message.find(':', 3);
        if (first_colon == std::string::npos)
            return;

        std::string recipient = message.substr(3, first_colon - 3);
        std::string msg_content = message.substr(first_colon + 1);

        auto it = _clients.find(recipient);
        // if (it != _clients.end())
        //     boost::asio::write(*it->second, boost::asio::buffer(msg_content + "\n"));
        // else
        //     boost::asio::write(*sender, boost::asio::buffer("User not found\n"));
    }
}