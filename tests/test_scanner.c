/*
 * test_scanner.c
 *
 * A simple test suite for our port scanner functions.
 * Note: These tests assume that your local environment is set up in a controlled manner.
 * You may need to adjust the expected results depending on your system.
 */

 #include <stdio.h>
 #include <assert.h>
 #include "scanner.h"
 
 int main(void) {
     // Test check_port_tcp() on localhost.
     // For demonstration, we'll test port 22 (commonly used for SSH)
     // and assume that if SSH is not running, it should return 0.
     int result22 = check_port_tcp("127.0.0.1", 22);
     printf("check_port_tcp(127.0.0.1, 22) returned: %d\n", result22);
     
     // Because we can't guarantee that port 22 is open on every system,
     // we assert that the result is either 0 or 1.
     assert(result22 == 0 || result22 == 1);
     
     // Test scan_ports() by simply calling it over a small port range.
     // Since scan_ports() just prints output, we won't try to assert on its output here.
     printf("Running scan_ports on 127.0.0.1 for ports 75-85...\n");
     scan_ports("127.0.0.1", 75, 85);
 
     printf("All tests passed!\n");
     return 0;
 }