#include "Session.h"
#include <iostream>
#include "Logger.h"
using namespace std;

GG_NAMESPACE_BEGIN
Session::Session(tcp::socket socket)
    : socket_(std::move(socket))
{
    GG_LOG_DEBUG("Session create");
    this->mProtocol.mSession = this;
}

std::string Session::Convert2Printable(std::string &_szData)
{
	char *pcTemp = (char *)calloc(1UL, _szData.size() * 3 + 1);
	int iCurPos = 0;

	if (NULL != pcTemp)
	{
		for (int i = 0; i < _szData.size(); ++i)
		{
			iCurPos += sprintf(pcTemp + iCurPos, "%02X ", (unsigned char)_szData[i]);
		}
		pcTemp[iCurPos] = 0;
	}

	std::string szRet = std::string(pcTemp);
	free(pcTemp);

	return szRet;
}

void Session::start()
{
    GG_LOG_DEBUG("Session start");
    mProtocol.mRole.Init();
    do_read();
}
void Session::do_read()
{
    GG_LOG_DEBUG("Session do_read");
    auto self(shared_from_this());
    socket_.async_read_some(
        boost::asio::buffer(data_, max_length),
        [this, self](boost::system::error_code ec, std::size_t length)
        {
            cout<<"on read"<<endl;
            if (!ec)
            {
                string data(data_,length);
                string readableStr = Convert2Printable(data);
                auto socketHandle = this->socket_.native_handle();
                cout<<"get data from : " <<socketHandle<<endl;
                cout<<"-----------------------------------"<<endl;
                cout<<readableStr<<endl;
                cout<<"-----------------------------------"<<endl;
                auto ud = this->mProtocol.raw2request(data);
                this->mRole.ProcMsg(*ud);
                delete ud;
                do_read();
            }
            else
            {
                cerr<<"Error in read"<<endl;
                mProtocol.mRole.Fini();
            }
        });
}

void Session::do_write(string &out)
{
    string readableStr = Convert2Printable(out);
    auto socketHandle = this->socket_.native_handle();
    cout<<"write data to : " <<socketHandle<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<readableStr<<endl;
    cout<<"-----------------------------------"<<endl;

    auto self(shared_from_this());
    boost::asio::async_write(socket_, boost::asio::buffer(out.data(), out.size()),
        [this, self](boost::system::error_code ec, std::size_t /*length*/)
        {
            if (!ec)
            {
            }
            else
            {
                cerr<<"Error in write"<<endl;
            }
        });
}

GG_NAMESPACE_END
