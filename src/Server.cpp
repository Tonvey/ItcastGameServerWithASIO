#include "Server.h"
#include <iostream>
#include "Logger.h"
using namespace std;
GG_NAMESPACE_BEGIN
//server(boost::asio::io_context& io_context, short port)
//    : acceptor_(io_context, tcp::endpoint(tcp::v4(), port))
//{
//    do_accept();
//}
Server::Server(int port)
    :acceptor_(io_context, tcp::endpoint(tcp::v4(), port))
{
}
void Server::Run()
{
    do_accept();
    io_context.run();
}
void Server::do_accept()
{
    acceptor_.async_accept(
        [this](boost::system::error_code ec, tcp::socket socket)
        {
            if (!ec)
            {
                GG_LOG_DEBUG("OnAccept");
                std::make_shared<Session>(std::move(socket))->start();
            }

            do_accept();
        });
}
GG_NAMESPACE_END
