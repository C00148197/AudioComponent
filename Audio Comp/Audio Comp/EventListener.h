#pragma once

/**Used as an interface for the event dispatcher*/
/*Objects wanting to receive events must inherit from this*/

class EventListener
{
public:

	//list of possible events
	enum Event {
		PAUSE,
		QUIT,
		NEXTLEVEL,
		STARTGAME,
		RESUMEGAME,
		ENDGAME,
		OPTIONS,
		OPTIONUP,
		OPTIONDOWN,
		VOLUMEUP,
		VOLUMEDOWN,
		ENTER, 
		MOVELEFT, 
		MOVERIGHT,
		RELEASE,
		BREAKGLASS,
		UP,
		DOWN,
		LEFT,
		RIGHT,
		INTERACT,
		one,
		two,
		three,
		four,
		five,
		six,
		seven,
		eight,
		nine,
		ten
	};


	virtual void onEvent(Event)=0;
};

