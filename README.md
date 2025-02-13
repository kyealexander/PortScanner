# **PortScanner**

A **TCP/UDP port scanner** written in C, featuring multi-threading for speed and optional banner grabbing for service detection.

## **Table of Contents**
- [Overview](#overview)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [License](#license)
- [Contributing](#contributing)

---

## **📝 Overview**

**PortScanner** is a fast and lightweight command-line tool for scanning TCP/UDP ports on a target host. It uses multiple threads to improve scanning speed and can optionally grab service banners to identify running services.

**Current Status**: _Basic skeleton completed; scanning logic under development._

---

## Features

- **TCP Port Scanning**: Check if a specific TCP port is open or closed.
- **UDP Port Scanning**: (planned) Validate open/closed UDP ports.
- **Multi-threading**: (planned) Scan multiple ports in parallel for speed.
- **Banner Grabbing**: (planned) Capture service banners on open ports to identify running services.

---

## Requirements

- A C compiler (e.g., `gcc`) supporting C99 or later.
- POSIX threads library (`pthread`) – typically available on Linux/Mac by default.
- Basic networking headers/libraries (e.g., `<netdb.h>`, `<sys/socket.h>`, `<arpa/inet.h>`) which are standard on Unix-like systems.

---

## **🚀Installation**

1. **Clone the Repository**
```bash
git clone https://github.com/kyealexander/PortScanner.git
cd PortScanner
```

2. **Build the Project**
```bash
make
```
This command uses the provided **Makefile** to build the source code into the `port_scanner` executable.

3. **(Optional) Install**  
You can manually copy or move the resulting `port_scanner` binary to a location in your `$PATH`, or just run it from this directory.

---

## Usage

After building, run:
```bash
./port_scanner <hostname/IP> <start_port> <end_port>
```
Example:
```bash
./port_scanner 127.0.0.1 1 1024
```

**Note**: Functionality for actually scanning ports is under construction. Future updates will add real port scanning logic.

**Usage Notes**:

- **Permissions**: Some ports below 1024 may require elevated privileges to scan (depending on your OS).
- **UDP**: A future version will support a `--udp` or similar flag to enable UDP scans.

---

## **📂Project Structure**
```less
PortScanner/ 
├── src/ 
│ ├── main.c            // Entry point 
│ ├── scanner.c         // Basic scanning logic (TCP/UDP functions) 
│ ├── threads.c         // Thread management (planned) 
│ └── bannergrab.c      // Banner grabbing (planned) 
├── include/ 
│ ├── scanner.h         // Prototypes for scanner-related functions 
│ ├── threads.h         // Prototypes for threading 
│ └── bannergrab.h      // Prototypes for banner grabbing 
├── obj/                // Build artifacts (object files) 
├── Makefile            // Build instructions 
├── .gitignore          // Ignore build artifacts 
├── LICENSE             // License information
└── README.md           // Project documentation (this file)
```

---

## License

This project is licensed under the [MIT License](LICENSE) - see the `LICENSE` file for details.

---

## Contributing

Contributions are welcome!

- Fork the project
- Create a new branch (`git checkout -b my-new-feature`)
- Commit your changes (`git commit -am 'Add some feature'`)
- Push to the branch (`git push origin my-new-feature`)
- Create a new Pull Request

---

### Next Steps

1. **Finalize/Refine the scanning logic** in `scanner.c`.
2. **Add multi-threading** to improve performance and scan multiple ports simultaneously.
3. **Implement banner grabbing** for open ports.

If you have any questions or suggestions, feel free to open an issue or submit a pull request!