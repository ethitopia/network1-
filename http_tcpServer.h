#ifndef INCLUDED_HTTP_TCPSERVER
#define INCLUDED_HTTP_TCPSERVER

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string>

namespace
{
    void log();
    void exitWithError();

}

namespace http
{

    class TcpServer
    {
    public:
        TcpServer();
        ~TcpServer();

    private:
        std::string m_ip_address;
        int m_port;
        int m_socket;
        int m_new_socket;
        long m_newMessage;

        std::string m_serverMessage;
        unsigned int m_socketAddress_len;
        struct sockaddr_in m_socket_Address;

        int startserver();
        void closeserver();
    };
} // namespace http

#endif
