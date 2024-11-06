# Include the Socket and Channel include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/Socket/inc
    ${CMAKE_SOURCE_DIR}/Channel/inc
)

# TCP Server Executable
add_executable(TCP_server TCP_serv_main.cpp)
target_link_libraries(TCP_server socket channel)
set_target_properties(TCP_server PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out
)

# TCP Client Executable
add_executable(TCP_client TCP_cli_main.cpp)
target_link_libraries(TCP_client socket channel)
set_target_properties(TCP_client PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out
)

# UDP Server Executable
add_executable(UDP_server UDP_serv_main.cpp)
target_link_libraries(UDP_server socket channel)
set_target_properties(UDP_server PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out
)

# UDP Client1 Executable
add_executable(UDP_client1 UDP_cli1_main.cpp)
target_link_libraries(UDP_client1 socket channel)
set_target_properties(UDP_client1 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out
)

# UDP Client2 Executable
add_executable(UDP_client2 UDP_cli2_main.cpp)
target_link_libraries(UDP_client2 socket channel)
set_target_properties(UDP_client2 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out
)

# Install rules
install(TARGETS TCP_server TCP_client UDP_server UDP_client1 UDP_client2
        DESTINATION bin)

