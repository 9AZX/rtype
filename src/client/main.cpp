/*
** EPITECH PROJECT, 2019
** main
** File description:
** Main file for launch the client.
** @Author: Cédric Hennequin
** @Date:   18-11-2019 15:54:15
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 19-11-2019 10:50:58
*/

#include "App.hpp"

int main()
{
	std::unique_ptr<App> app = std::make_unique<App>();

	app->run();
	return 0;
}
