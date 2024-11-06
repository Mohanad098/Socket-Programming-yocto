# Channel Library
add_library(channel STATIC src/server.cpp src/client.cpp)

# Include directories
target_include_directories(channel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Link to socket library
target_link_libraries(channel PUBLIC socket)

# Output directory
set_target_properties(channel PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out
)

