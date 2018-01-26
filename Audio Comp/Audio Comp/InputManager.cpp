#include "InputManager.h"
#include <iostream>


InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::AddListener(EventListener::Event evt,EventListener *listener)
{
	if (listeners.find(evt) == listeners.end()) { //event not in map add it.
		listeners[evt] = new std::vector<EventListener*>();
	}

	listeners[evt]->push_back(listener);

}

//Send the events to interested objects
void InputManager::Dispatch(EventListener::Event evt)
{

	if (listeners.find(evt) != listeners.end()) {
		
		for (auto const &listener : *listeners[evt]) { //go through all listeners for this event
			listener->onEvent(evt); //Call on event for the listener

		}
	}
	
}


//Gnereate events
void InputManager::ProcessInput(bool endGame)
{

	SDL_Event e;

	while (SDL_PollEvent(&e) != 0)
	{
		//	Init(e);       
		switch (e.type) {

		case SDL_KEYDOWN:
			switch (e.key.keysym.sym) {
			case SDLK_w:
				Dispatch(EventListener::Event::UP);
				break;
			case SDLK_s:
				Dispatch(EventListener::Event::DOWN);
				break;
			case SDLK_a:
				Dispatch(EventListener::Event::LEFT);
				break;
			case SDLK_d:
				Dispatch(EventListener::Event::RIGHT);
				break;
			case SDLK_1:
				Dispatch(EventListener::Event::one);
				break;
			case SDLK_2:
				Dispatch(EventListener::Event::two);
				break;
			case SDLK_3:
				Dispatch(EventListener::Event::three);
				break;
			case SDLK_4:
				Dispatch(EventListener::Event::four);
				break;
			case SDLK_5:
				Dispatch(EventListener::Event::five);
				break;
			case SDLK_6:
				Dispatch(EventListener::Event::six);
				break;
			case SDLK_7:
				Dispatch(EventListener::Event::seven);
				break;
			case SDLK_8:
				Dispatch(EventListener::Event::eight);
				break;
			case SDLK_9:
				Dispatch(EventListener::Event::nine);
				break;
			case SDLK_0:
				Dispatch(EventListener::Event::ten);
				break;

			case SDLK_SPACE:
				Dispatch(EventListener::Event::INTERACT);
				std::cout << "ENTER";
				break;
			}


		//	/* Keyboard Down Event */
		//case SDL_KEYDOWN:
		//	switch (e.key.keysym.sym) {
		//	case SDLK_p:
		//		Dispatch(EventListener::Event::RESUMEGAME);
		//		break;
		//	case SDLK_w:
		//		Dispatch(EventListener::Event::OPTIONUP);
		//		break;
		//	case SDLK_s:
		//		Dispatch(EventListener::Event::OPTIONDOWN);
		//		break;
		//	case SDLK_a:
		//		Dispatch(EventListener::Event::VOLUMEDOWN);
		//		break;
		//	case SDLK_d:
		//		Dispatch(EventListener::Event::VOLUMEUP);
		//		break;
		//	case SDLK_x:
		//		Dispatch(EventListener::Event::BREAKGLASS);
		//		break;

		//	case SDLK_r:
		//		Dispatch(EventListener::Event::STARTGAME);
		//		break;

		//	case SDLK_o:
		//		Dispatch(EventListener::Event::OPTIONS);
		//		break;
		//		
		//	case SDLK_SPACE:
		//		Dispatch(EventListener::Event::ENTER);
		//		std::cout << "ENTER";
		//		break;

		//	case SDLK_z:
		//		Dispatch(EventListener::Event::ENDGAME);
		//		break;

		//	case SDLK_LEFT:
		//		Dispatch(EventListener::Event::MOVELEFT);
		//		break;
		//	case SDLK_RIGHT:
		//		Dispatch(EventListener::Event::MOVERIGHT);
		//		break;
		//	}



		//	isKeyPressed2 = true;
		//	break;

		//	/* Keyboard Released Event */
		//case SDL_KEYUP:

		//	if (!isKeyPressed) {
		//		switch (e.key.keysym.sym) {
		//		case SDLK_LEFT:
		//			Dispatch(EventListener::Event::RELEASE);
		//			break;
		//		case SDLK_RIGHT:
		//			Dispatch(EventListener::Event::RELEASE);
		//			break;
		//		case SDLK_q:
		//			if (endGame)
		//			{
		//				Dispatch(EventListener::Event::QUIT);
		//			}
		//			break;
		//		}

		//		//If it's the last level, end the game
		//		if (endGame)
		//		{
		//			Dispatch(EventListener::Event::NEXTLEVEL);
		//		}
		//	}

		//	else
		//	{
		//		isKeyPressed = false;
		//	}

		//	isKeyPressed2 = false;
		//	break;



		}
		//check for exit
	}

}