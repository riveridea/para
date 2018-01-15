#ifndef __tcpconnector_h__
#define __tcpconnector_h__

#include <netinet/in.h>
#include "tcpstream.h"

class tcp_connector
{
public:
    tcp_stream* connect(int port, const char* server);
    tcp_stream* connect(const char* server, int port, int timeout);    

private:
    int resolve_host(const char* host, struct in_addr* addr);
};

#endif
