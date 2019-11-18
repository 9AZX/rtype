#!/bin/sh
# @Author: Cédric Hennequin
# @Date:   19-09-2019 00:51:03
# @Last Modified by:   Cédric Hennequin
# @Last Modified time: 18-11-2019 15:50:19

clear
set -e
project_name="R-Type"

# ███████╗██╗   ██╗███╗   ██╗ ██████╗████████╗██╗ ██████╗ ███╗   ██╗███████╗
# ██╔════╝██║   ██║████╗  ██║██╔════╝╚══██╔══╝██║██╔═══██╗████╗  ██║██╔════╝
# █████╗  ██║   ██║██╔██╗ ██║██║        ██║   ██║██║   ██║██╔██╗ ██║███████╗
# ██╔══╝  ██║   ██║██║╚██╗██║██║        ██║   ██║██║   ██║██║╚██╗██║╚════██║
# ██║     ╚██████╔╝██║ ╚████║╚██████╗   ██║   ██║╚██████╔╝██║ ╚████║███████║
# ╚═╝      ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝

function display_help
{
	if [[ "${OSTYPE}" = "darwin"* ]]; then
		echo "SYNOPSIS"
		echo "\t${project_name} - build assistant tool\n"
		echo "\t./build.sh [-b/--build] [-c/--clean] [-h/--help]\n"
		echo "DESCRIPTION"
		echo "\t-b, --build\tBuild the project."
		echo "\t-p, --pretty\tPretty mode (build and clean)."
		echo "\t-c, --clean\tClean the project."
		echo "\t-h, --help\tDisplay help informations.\n"
		echo "EXAMPLES"
		echo "\t./build.sh --build"
		echo "\t./build.sh --clean"
	else
		echo -e "SYNOPSIS"
		echo -e "\t${project_name} - build assistant tool\n"
		echo -e "\t./build.sh [-b/--build] [-c/--clean] [-h/--help]\n"
		echo -e "DESCRIPTION"
		echo -e "\t-b, --build\tBuild the project."
		echo -e "\t-p, --pretty\tPretty mode (build and clean)."
		echo -e "\t-c, --clean\tClean the project."
		echo -e "\t-h, --help\tDisplay help informations.\n"
		echo -e "EXAMPLES"
		echo -e "\t./build.sh --build"
		echo -e "\t./build.sh --clean"
	fi
}

function run_build
{
	run_clean
	mkdir "./build"
	cd "./build"
	conan install ".."
	cmake ".."
	make
}

function run_pretty
{
	run_build
	if [[ -d "./bin" ]]; then
		if [ -f "./bin/r-type_client" ]; then
			mv "./bin/r-type_client" ".."
		fi
		if [ -f "./bin/r-type_server" ]; then
			mv "./bin/r-type_server" ".."
		fi
	fi
	cd ".."
	if [[ -d "./build" ]]; then
		rm -rf "./build"
	fi
}

function run_clean
{
	if [[ -d "./build" ]]; then
		rm -rf "./build"
	fi
	if [[ -f "./r-type_client" ]]; then
		rm "./r-type_client"
	fi
	if [[ -f "./r-type_server" ]]; then
		rm "./r-type_server"
	fi
}

function args_get
{
	while [ "$1" != "" ]; do
		case "$1" in
			-b | --build )
				run_build
				exit 0
				;;
			-p | --pretty )
				run_pretty
				exit 0
				;;
			-c | --clean )
				run_clean
				exit 0
				;;
			-h | --help )
				display_help
				exit 0
				;;
			* )
				echo "Error: invalid argument \"${1}\"."
				echo "Display help with the flag -h or --help."
				exit 84
		esac
		shift
	done
	echo "Error: invalid argument \"${1}\"."
	echo "Display help with the flag -h or --help."
	exit 84
}

function main
{
	args_get "$@"
}

main "$@";
