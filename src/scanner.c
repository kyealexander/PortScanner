/*
 * scanner.c
 *
 * A simple TCP port scanner written in C.
 *
 * This file implements two cool functions:
 *   - check_port_tcp: Tries to connect to a TCP port on a target host.
 *   - scan_ports: Goes through a range of ports and prints out the open ones.
 *
 * I’m working on this as a fun hobby project while at uni,
 * so please excuse the casual style and extra comments!
 *
 * Created: 2025-02-17
 * Author: Kye Murphy
 */

 #define _POSIX_C_SOURCE 200112L  // Enable necessary POSIX functionality before any includes

 /* Standard libraries for input/output, string handling, etc. */
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <errno.h>
 
 /* System headers for networking (sockets, address resolution, etc.) */
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netdb.h>
 #include <netinet/in.h>
 #include <unistd.h>
 
 /* Our header file that declares the functions used in this project */
 #include "scanner.h"
 
 /**
  * check_port_tcp - Checks if a given TCP port is open on the specified host.
  *
  * @host: The target host (could be a domain name or IP address).
  * @port: The TCP port number to check.
  *
  * Return: 1 if the port is open (i.e., connection succeeded), 0 otherwise.
  */
 int check_port_tcp(const char *host, int port) {
     struct addrinfo hints;       // Hints for what kind of address info we want
     struct addrinfo *result;     // Pointer to hold the list of address structures
     struct addrinfo *rp;         // For iterating through the list
     int sockfd;                  // Our socket descriptor
     int port_open = 0;           // Flag to track if the port is open (1 = open, 0 = closed)
     char port_str[6];            // Buffer to hold the port number as a string ("65535" + null)
 
     // Clear the hints structure and set desired properties
     memset(&hints, 0, sizeof(hints));
     hints.ai_family = AF_UNSPEC;      // Allow IPv4 or IPv6
     hints.ai_socktype = SOCK_STREAM;  // We're using TCP (stream sockets)
 
     // Convert the port number to a string for getaddrinfo()
     snprintf(port_str, sizeof(port_str), "%d", port);
 
     // Resolve the host and port into a list of address structures
     int gai_status = getaddrinfo(host, port_str, &hints, &result);
     if (gai_status != 0) {
         fprintf(stderr, "Error in getaddrinfo for %s:%s -> %s\n", host, port_str, gai_strerror(gai_status));
         return 0;  // Return 0 (closed) if we couldn't resolve the host/port
     }
 
     // Loop through each address and try to connect
     for (rp = result; rp != NULL; rp = rp->ai_next) {
         sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
         if (sockfd == -1) {
             // Could not create socket, so skip to the next address
             continue;
         }
 
         // Try to connect to the current address
         if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) == 0) {
             // Connection successful: the port is open!
             port_open = 1;
             close(sockfd);
             break;
         }
         // Connection failed; close the socket and try the next one
         close(sockfd);
     }
 
     // Free the address info list
     freeaddrinfo(result);
 
     return port_open;
 }
 
 /**
  * scan_ports - Scans a range of TCP ports on the given host.
  *
  * @host: The target hostname or IP address.
  * @start: The starting port number.
  * @end: The ending port number.
  *
  * This function loops through the specified port range and uses
  * check_port_tcp() to determine if each port is open. It prints the result.
  */
 void scan_ports(const char *host, int start, int end) {
     printf("Scanning host '%s' for open TCP ports in the range %d to %d...\n", host, start, end);
 
     for (int port = start; port <= end; port++) {
         if (check_port_tcp(host, port)) {
             printf("Port %d is open!\n", port);
         }
     }
 }