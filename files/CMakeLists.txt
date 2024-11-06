cmake_minimum_required(VERSION 3.10)
project(socket_project LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectories
add_subdirectory(Socket)
add_subdirectory(Channel)
add_subdirectory(Application)

