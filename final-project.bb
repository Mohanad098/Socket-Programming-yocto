DESCRIPTION = "Socket Programming Project with CMake"
SECTION = "examples"
LICENSE = "CLOSED"

SRC_URI = "file://CMakeLists.txt \
	   file://Socket/CMakeLists.txt \
           file://Channel/CMakeLists.txt \
           file://Application/CMakeLists.txt \
           file://Socket/src/TCPsocket.cpp \
           file://Socket/inc/TCPsocket.hpp \
           file://Socket/src/UDPsocket.cpp \
           file://Socket/inc/UDPsocket.hpp \
           file://Socket/inc/socket.hpp \
           file://Channel/src/server.cpp \
           file://Channel/src/client.cpp \
           file://Channel/inc/server.hpp \
           file://Channel/inc/client.hpp \
           file://Channel/inc/channel.hpp \
           file://Application/TCP_serv_main.cpp \
           file://Application/TCP_cli_main.cpp \
           file://Application/UDP_serv_main.cpp \
           file://Application/UDP_cli1_main.cpp \
           file://Application/UDP_cli2_main.cpp"

S = "${WORKDIR}"

inherit cmake

