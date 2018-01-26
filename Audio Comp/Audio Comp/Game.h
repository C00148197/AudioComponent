#pragma once

#include <vector>
#include "InputManager.h"
#include "EventListener.h"
#include "LTimer.h"
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include "InputManager.h"
#include <iostream>
#include "Box2D\Box2D.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include "Renderer.h"
//test
#include "Audio.h"
//#include "Ball.h"
//#include "Contact.h"
//#include "Emitter.h"
/** The game objct whic manages the game loop*/
class Game:public EventListener
{
	InputManager inputManager;
	unsigned int lastTime;//time of last update;
	bool pause = true;
	bool quit;
	Renderer renderer;
	enum GameState {
		STARTSCREEN,
		GAMEPLAY,
		PAUSE,
		OPTIONS,
		ENDSCREEN,
	};
	SDL_Window* gameWindow;
	SDL_Renderer* gameRenderer;
	bool gameRunning = true;
	bool musicPlaying = false;
	bool wallBroke = false;
	Audio* audio;

public:
	Game();
	~Game();
	bool init();
	void destroy();
	void update();
	void render();
	void loop();
	void onEvent(EventListener::Event);

private:
	GameState gameState;
	b2World* World;

};

