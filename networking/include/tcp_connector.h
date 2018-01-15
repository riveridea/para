#ifndef __tcpconnector_h__
#define __tcpconnector_h__

#include <netinet/in.h>
#include "tcp_stream.h"

class tcp_connector
{
public:
    tcp_stream* connect(const char* server, int port);
    tcp_stream* connect(const char* server, int port, int timeout);    

private:
    int resolve_host_name(const char* host, struct in_addr* addr);
};

#endif
