# Socket Library
add_library(socket STATIC src/TCPsocket.cpp src/UDPsocket.cpp)

# Include directories
target_include_directories(socket PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Output directory
set_target_properties(socket PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out
)

