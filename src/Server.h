#pragma once
#include <boost/asio.hpp>
#include "Macro.h"
#include "Session.h"

using boost::asio::ip::tcp;
GG_NAMESPACE_BEGIN
class Server
{
public:
    Server(int port);
    void Run();

private:
    boost::asio::io_context io_context;
    tcp::acceptor acceptor_;
    void do_accept();
    int mPort;
};

GG_NAMESPACE_END
