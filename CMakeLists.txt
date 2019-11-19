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

# Set option(s).
set(CONAN_SYSTEM_INCLUDES ON)

# Set the include directory.
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(PROJECT_DIR "${PROJECT_SOURCE_DIR}/src")

# Set sources.
set(R_TYPE_CLIENT
	./src/client/main.cpp
	./src/client/render/Sprites.cpp
)

set(R_TYPE_SERVER
	./src/server/main.cpp
)

# Find packages.
find_package(SFML 2 REQUIRED network audio graphics window system)

# Check if SFML is found.
if (NOT SFML_FOUND)
	message(FATAL_ERROR "SFML doesn't found.")
endif()

# Set compilation flags.
if (
	(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	OR
	(CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
	OR
	(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
)
	add_definitions("-Wall")
	add_definitions("-Wextra")
	add_definitions("-std=c++11")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	add_definitions("/Wall")
	add_definitions("/w4")
	add_definitions("/std:c++11")
endif()

# Create executable.
add_executable(r-type_client ${R_TYPE_CLIENT})
add_executable(r-type_server ${R_TYPE_SERVER})
# Include headers.
target_include_directories(r-type_client PRIVATE "${INCLUDE_DIR}")
target_include_directories(r-type_client PRIVATE "${INCLUDE_DIR}/client")
target_include_directories(r-type_client PRIVATE "${INCLUDE_DIR}/client/render")
target_include_directories(r-type_server PRIVATE "${INCLUDE_DIR}")
target_include_directories(r-type_server PRIVATE "${INCLUDE_DIR}/server")

# Link librarie(s).
target_link_libraries(r-type_client PRIVATE ${CONAN_LIBS})
target_link_libraries(r-type_server PRIVATE ${CONAN_LIBS})
