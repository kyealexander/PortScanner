#ifndef SCANNER_H
#define SCANNER_H

void scan_ports(const char *host, int start, int end);
int check_port_tcp(const char *ip, int port);
int check_port_udp(const char *ip, int port);

#endif