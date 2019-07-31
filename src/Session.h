#pragma once
#include <boost/asio.hpp>
#include "Macro.h"
#include "GameProtocol.h"
#include "GameRole.h"
using boost::asio::ip::tcp;
GG_NAMESPACE_BEGIN
class Session
    : public std::enable_shared_from_this<Session>
{
public:
    Session(tcp::socket socket);
    void start();
private:
    friend GameProtocol;
    GameProtocol mProtocol;
    GameRole mRole;
    void do_read();
    void do_write(std::string &out);
    tcp::socket socket_;
    enum { max_length = 1024 };
    char data_[max_length];
    std::string Convert2Printable(std::string &_szData);
};
GG_NAMESPACE_END
