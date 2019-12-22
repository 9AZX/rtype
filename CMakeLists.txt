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

# Enable compilation database for clang tooling.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the include directory.
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(PROJECT_DIR "${PROJECT_SOURCE_DIR}/src")

# Set sources.
set(R_TYPE_CLIENT
	# Main file.
	./src/client/main.cpp
	# Exception file(s).
	./src/Exception.cpp
	# Other(s).
	./src/client/App.cpp
	./src/client/Game.cpp
	./src/client/GameEngine.cpp
	./src/client/Network.cpp
	./src/client/Entity.cpp
	./src/client/Menu.cpp
)
set(R_TYPE_SERVER
	# Main file.
	./src/server/main.cpp
	# Exception file(s).
	./src/Exception.cpp
	# Commands for the CLI.
	./src/server/CLI.cpp
	./src/server/Commands.cpp
	# Server files.
	./src/server/Server.cpp
	./src/server/GameServer.cpp
	# Other(s).
	./src/server/Instance.cpp
	./src/server/GameEngine.cpp
	# Network.
	./src/NetworkUDP.cpp
)

# Class shared between client and server.
set(R_TYPE_CLIENT
	${R_TYPE_CLIENT}
	./src/entity/GameEntity.cpp
	./src/entity/Missile.cpp
	./src/entity/Mob.cpp
	./src/entity/Player.cpp
	)
set(R_TYPE_SERVER
	${R_TYPE_SERVER}
	./src/entity/GameEntity.cpp
	./src/entity/Missile.cpp
	./src/entity/Mob.cpp
	./src/entity/Player.cpp
)

# Class load only on Linux and Darwin.
if (NOT WIN32)
	set(R_TYPE_SERVER
		${R_TYPE_SERVER}
		./src/server/Fork.cpp
	)
endif()

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
	add_definitions("-std=c++14")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	add_definitions("/Wall")
	add_definitions("/w4")
	add_definitions("/std:c++14")
endif()

# Create executable.
add_executable(r-type_client ${R_TYPE_CLIENT})
add_executable(r-type_server ${R_TYPE_SERVER})
# Include headers.
target_include_directories(r-type_client PRIVATE "${INCLUDE_DIR}")
target_include_directories(r-type_client PRIVATE "${INCLUDE_DIR}/client")
target_include_directories(r-type_client PRIVATE "${INCLUDE_DIR}/entity")
target_include_directories(r-type_server PRIVATE "${INCLUDE_DIR}")
target_include_directories(r-type_server PRIVATE "${INCLUDE_DIR}/server")
target_include_directories(r-type_server PRIVATE "${INCLUDE_DIR}/entity")
# Link librarie(s).
target_link_libraries(r-type_client PRIVATE ${CONAN_LIBS})
target_link_libraries(r-type_server PRIVATE ${CONAN_LIBS})
