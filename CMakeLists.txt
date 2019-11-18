cmake_minimum_required(VERSION 2.8.12)
project(R-Type)

# Configure CONAN extension.
if (NOT EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
	message(FATAL_ERROR "Conan build info file is missing.")
else()
	include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
	if(APPLE)
		conan_basic_setup(KEEP_RPATHS)
	else()
		conan_basic_setup()
	endif()
endif ()

# Set the include directory.
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(PROJECT_DIR "${PROJECT_SOURCE_DIR}/src")

# Set sources.
set(R_TYPE_CLIENT
	./src/client/main.cpp
)

set(R_TYPE_SERVER
	./src/server/main.cpp
)

# Create executable.
add_executable(r-type_client ${BABEL_CLIENT_SOURCES})
add_executable(r-type_server ${BABEL_SERVER_SOURCES})
# Include headers.
target_include_directories(r-type_client PRIVATE "${INCLUDE_DIR}")
target_include_directories(r-type_server PRIVATE "${INCLUDE_DIR}")
