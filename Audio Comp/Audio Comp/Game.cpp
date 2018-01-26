#include <iostream>
using namespace std;

#include "LTimer.h"
#include "Game.h"
#include <stdlib.h>
#include <stdio.h>
#include "InputManager.h"
#include <iostream>
#include "Box2D\Box2D.h"





const int SCREEN_FPS = 100;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;




Game::Game()
{
	musicPlaying = false;

	pause = false;
	quit = false;

	gameWindow = SDL_CreateWindow("Demo Audio Component", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_PRESENTVSYNC);



	inputManager.AddListener(EventListener::Event::one, this);
	inputManager.AddListener(EventListener::Event::two, this);
	inputManager.AddListener(EventListener::Event::three, this);
	inputManager.AddListener(EventListener::Event::four, this);
	inputManager.AddListener(EventListener::Event::five, this);
	inputManager.AddListener(EventListener::Event::six, this);
	inputManager.AddListener(EventListener::Event::seven, this);
	inputManager.AddListener(EventListener::Event::eight, this);
	inputManager.AddListener(EventListener::Event::nine, this);
	inputManager.AddListener(EventListener::Event::ten, this);

}


Game::~Game()
{
}


bool Game::init() {
	audio = new Audio();

	audio->Init();

	return true;
}

void Game::destroy()
{
	SDL_DestroyWindow(gameWindow);
	SDL_DestroyRenderer(gameRenderer);
	SDL_Quit();
}

//** calls update on all game entities*/
void Game::update()
{
	unsigned int currentTime = LTimer::gameTime();//millis since game started
	unsigned int deltaTime = currentTime - lastTime;//time since last update
	//save the curent time for next frame
	lastTime = currentTime;
}

//** calls render on all game entities*/

void Game::render()
{

	if (gameState == GameState::OPTIONS)
	{
		SDL_RenderClear(gameRenderer);
		SDL_SetRenderDrawColor(gameRenderer, 180, 0, 255, 0);
	}

	SDL_RenderPresent(gameRenderer);
}

/** update and render game entities*/
void Game::loop()
{
	LTimer capTimer;//to cap framerate

	int frameNum = 0;
	while (!quit) { //game loop

		if (GameState::GAMEPLAY)
		{
			if (musicPlaying == false)
			{
				musicPlaying = true;
				audio->Play();
			}
			audio->Update();
		}
		capTimer.start();
		inputManager.ProcessInput(false);

		update();

		render();

		int frameTicks = capTimer.getTicks();//time since start of frame
		if (frameTicks < SCREEN_TICKS_PER_FRAME)
		{
			//Wait remaining time before going to next frame
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
		}
	}
}

void Game::onEvent(EventListener::Event evt) {

	if (evt == EventListener::Event::one) {

		cout << "SFX play, duck music" << endl;
		audio->SfxPlay();
		audio->Duck(10);
	}


	if (evt == EventListener::Event::two) {

		cout << "SFX play, layered" << endl;
		audio->Layering(7);
	}


	if (evt == EventListener::Event::three) {

		cout << "SFX play, Decay" << endl;
		audio->Decay(500);
	}



	if (evt == EventListener::Event::four) {

		cout << "SFX play, distance far" << endl;
		audio->Distance(150, 0);
	}

	if (evt == EventListener::Event::five) {

		cout << "SFX play, distance close" << endl;
		audio->Distance(1, 1);
	}


	if (evt == EventListener::Event::six) {

		cout << "SFX play, reverb" << endl;
		audio->Reverb(1, 5, 0.1f);
	}


	if (evt == EventListener::Event::seven) {

		cout << "SFX play/pause" << endl;
		audio->Pause();
	}

}