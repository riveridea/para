#include <string>
#include <netinet/in.h>
#include "tcpstream.h"
 
using namespace std;
 
class tcp_acceptor
{
    int    m_lsd;
    string m_address;
    int    m_port;
    bool   m_listening;
 
  public:
    tcp_acceptor(int port, const char* address="");
    ~tcp_acceptor();
 
    int        start(); //start listenting
    tcp_stream* accept(); //accept a connecting
 
  private:
    tcp_acceptor() {}
};
