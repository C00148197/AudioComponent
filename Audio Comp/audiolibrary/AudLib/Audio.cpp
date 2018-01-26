#pragma once

#include "Audio.h"
#include "SDL.h"
#include"SDL_mixer.h"
using namespace std;
#include <iostream>

#include <fstream>
Audio::Audio()
{
	m_musicVol = 10;
	m_masterVol = 10;
	m_soundVol = 10;
	m_duck = 0;
	m_decay = 0;
	m_fade = 0;
	m_layering = 0;
}

Audio::~Audio()
{
}


void fin(int channel);

void Audio::Init()
{
	/*m_duck = 5;
	m_test -= 1;*/
	m_musicVol = 10;
	m_masterVol = 10;
	m_soundVol = 10;
	m_duck = 0;
	m_decay = 0;
	m_fade = 0;
	m_layering = 0;
	m_paused = false;
	
}
void Audio::CloseSFX()
{
	Mix_ChannelFinished(fin);

	

	//this->Duck(0);
}




void Audio::SfxPlay()
{
	Mix_Chunk *scratch = NULL;
	scratch = Mix_LoadWAV("sfx.wav");


	Mix_PlayChannel(-1, scratch, 0);



	ofstream myfile;
	myfile.open("channelLog.txt");
	myfile << "open";
	myfile.close();
}

void Audio::Duck(float duck)
{
	m_duck = duck;



	//m_musicVol = 100;
	/*m_duck = 0;

	m_duck = duck;*/
}

bool Audio::Play()
{



	SDL_INIT_AUDIO;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		exit(0);
	}
	//if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	//{
	//	exit(0);
	//}

	//The music that will be played
	Mix_Music *music = NULL;

	//The sound effects that will be used

	Mix_Chunk *high = NULL;
	Mix_Chunk *med = NULL;
	Mix_Chunk *low = NULL;

	//Initialize SDL_mixer
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
	}

	//Load the music
	music = Mix_LoadMUS("music3.mp3");








	Mix_VolumeMusic(3);

	//If there was a problem loading the music
	if (music == NULL)
	{
		cout << Mix_GetError() << endl;
		return false;
	}

	////Load the sound effects
	//scratch = Mix_LoadWAV("scratch.wav");
	//high = Mix_LoadWAV("high.wav");
	//med = Mix_LoadWAV("medium.wav");
	//low = Mix_LoadWAV("low.wav");

	//If there was a problem loading the sound effects
	//if ((scratch == NULL) || (high == NULL) || (med == NULL) || (low == NULL))
	//{

	//}


	//If there is no music playing
	if (Mix_PlayingMusic() == 0)
	{
		//Play the music
		if (Mix_PlayMusic(music, -1) == -1)
		{
			return 1;
		}
	}

}

void Audio::Layering(int layering)
{
	m_layering = layering;

	for (int i = 0; i < layering; i++)
	{
		SfxPlay();
			
	}

}

void Audio::Reverb(int distance, int numReflections, float seconds)
{
	m_distance = distance;
	for (int i = 0; i < numReflections; i++)
	{
		t;
		t.start();
		cout << "timer started . . ." << endl;
		while (true) {
			if (t.elapsedTime() >= seconds) {
				break;
			}
			else {
				// do other things
			}
		}
		//cout << seconds << " seconds elapsed" << m_distance << endl;
		m_distance += 50;

		if (m_distance > 255)
		{
			m_distance = 255; //distance cap
		}
		cout << seconds << " seconds elapsed + dist: " << m_distance << endl;
		Distance(m_distance, i);
	}
}

void Audio::Pause()
{
	if (m_paused == false)
	{
		for (int i = 0; i < MIX_CHANNELS; i++)
		{
			Mix_Pause(i);
		}
		Mix_PauseMusic();
		m_paused = true;
	}
	else
	{

		for (int i = 0; i < MIX_CHANNELS; i++)
		{
			Mix_Resume(i);
		}
		Mix_ResumeMusic();
		m_paused = false;
	}
	
}

void Audio::Distance(int distance, int channel)
{
	//m_distance = distance;
	//CONSIDER PASSING CHANNEL FOR THINGS LIKE THIS FOR FLEXIBILITY
	Mix_SetDistance(channel, distance);
	SfxPlay();
}


void Audio::Decay(int decay)
{
	m_decay = decay;
	SfxPlay();
	Mix_FadeOutChannel(0, decay);

}

void Audio::Update()
{
	if (!m_paused)
	{
		if (m_duck > 0)
		{

			int muVol = (m_musicVol * (m_masterVol)) / m_duck;

			Mix_VolumeMusic((muVol));

			int sfxVol = m_soundVol * (m_masterVol);
			Mix_Volume(-1, (sfxVol));

			//	cout << muVol << endl;
		}

		else
		{

			int muVol = m_musicVol * (m_masterVol);
			Mix_VolumeMusic((muVol));

			int sfxVol = m_soundVol * (m_masterVol);
			Mix_Volume(-1, (sfxVol));
			//	cout << muVol << endl;
		}

		CloseSFX();


		string sum;
		string x;
		ifstream inFile;

		inFile.open("channelLog.txt"); //work around to check if sound channel has closed since cant return from "fin" function due to library param restrictions
		if (!inFile) {
			cout << "Unable to open file";
			exit(1); // terminate with error
		}

		while (inFile >> x) {
			sum = sum + x;
		}

		inFile.close();
		if (sum == "closed")
		{
			//	cout << "Sum = " << sum << endl;
			Duck(0);
		}
	}
}



void fin(int channel)
{
	cout << "close channel " << channel << endl;

	
	ofstream myfile;
	myfile.open("channelLog.txt");
	myfile << "closed";
	myfile.close();



}