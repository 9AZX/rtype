/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** GameEngine
*/

#ifndef GAMEENGINE_HPP_
#define GAMEENGINE_HPP_

#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Audio.hpp>
#include "Network.hpp"

#define SONG "assets/songs/r-type_song.ogg"

class GameEngineClient
{
public:
	GameEngineClient();
	~GameEngineClient();
	void TreatmentEvent(sf::Event event, std::shared_ptr<Network>);
	void songLevel(bool level);
	void playSong();
	void songPause();

protected:
	bool _isSong = false;
	int _volumeSong = 50;
	bool _songStatus = true;
	sf::Music _music;

private:
};

#endif /* !GAMEENGINE_HPP_ */
