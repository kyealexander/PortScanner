#include "scanner.h"
#include <stdio.h>
// For getaddrinfo, socket, etc.:
// might need sys/socket.h, netdb.h, unistd.h, etc.
// #include <sys/types.h>
// #include <sys/socket.h>
// #include <netdb.h>
// #include <unistd.h>


void scan_ports(const char *host, int start, int end) {
    (void)host;
    (void)start;
    (void)end;
    // TODO: implement scanning

    // 1. Use getaddrinfo to resolve host
    // 2. Loop from start to end:
    //     check_port_tcp(host, port) or check_port_udp(...)
    // 3. Print the results
}

int check_port_tcp(const char *ip, int port) {
    (void)ip;
    (void)port;

    // Create socket
    // Connect -> if success, port is open; else closed
    // Close socket
    // Return status
    return 0;
}

int check_port_udp(const char *ip, int port) {
    (void)ip;
    (void)port;
    // Similar logic but with sendto() or connect()
    return 0;
}