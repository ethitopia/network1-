#include <http_tcpServer.h>
#include <iostream>
#include <fstream>
#include <unistd.h>

namespace
{

 void log(const std::string &message)
 {
  std::cout << message << std::endl;
 }

 void exitWithError(const std::string &message)
 {
  log("Error: " + message);
  exit(1);
 }

}

namespace http
{
 TcpServer::TcpServer(std::string ip_address, int port) : m_ip_address(ip_address), m_port(port), m_socket(), m_new_socket(), m_newMessage(), m_serverMessage(), m_socket_Address(), m_socketAddress_len(sizeof(m_socket_Address)), m_serverMessage(buildResponse())
 {
  startserver();
 }
 TcpServer::~TcpServer()
 {
  closeserver();
 }

 int TcpServer::startserver()
 {
  m_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (m_socket < 0)
  {
   exitWithError("Cannot Create Socket");
   return 1;
  }
  return 0;
 }

 void TcpServer::closeserver()
 {
  close(m_socket);
  close(m_new_socket);
  exit(0);
 }

} // namespace http

struct sockaddr_in
{
 short sin_family;        // socket family
 unsigned short sin_port; // port used by server
 struct in_addr sin_addr; // ip address
 char sin_zero[8];
}; // socket address

struct in_addr
{
 unsigned long s_addr;
};