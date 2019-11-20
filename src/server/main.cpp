/*
** EPITECH PROJECT, 2019
** main
** File description:
** Main file for launch the server.
** @Author: Cédric Hennequin
** @Date:   18-11-2019 15:54:03
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 20-11-2019 16:48:06
*/

#include <iostream>
#include <memory>
#include "CLI.hpp"
#include "Exception.hpp"

using namespace App;

int main(int argc, char *argv[])
{
	std::unique_ptr<CLI> cli(new CLI(argc, argv));

	try {
		cli->launchCLI();
	}
	catch (const std::bad_alloc &e) {
		std::cerr << "Allocation failed: " << e.what() << std::endl;
		return 84;
	}
	catch (const std::runtime_error &e) {
		std::cerr << e.what() << std::endl;
		return 84;
	}
	catch (const Exception &e) {
		std::cerr << e.what() << std::endl;
		return 84;
	}
	catch (...) {
		std::cerr << "An internal error occured." << std::endl;
		return 84;
	}
	return 0;
}
