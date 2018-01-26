#pragma once

#define SDL_MAIN_HANDLED
#ifdef __APPLE__
#include "SDL2/SDL.h"
#elif defined(_WIN64) || defined(_WIN32)
#include "SDL.h"
//#include "SDL_image.h"
#endif


#include<map>
#include<vector>
#include "EventListener.h"

/*Convert input into logical events*/
class InputManager
{
	//dictionary holding a list of litener objs for each event type
	std::map<
		EventListener::Event, 
		std::vector<EventListener*>* //pointer to vec of eventlisteners
		> listeners;
public:
	InputManager();
	~InputManager();
	bool pressed;
	void AddListener(EventListener::Event, EventListener*);
	void Dispatch(EventListener::Event);

	void ProcessInput(bool endGame);
private:
	bool isKeyPressed = false; //bool used to stop game instantly reseting after win
	bool isKeyPressed2 = false; //bool used to see if any key is being pressed

	
	
};

