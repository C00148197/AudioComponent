#pragma once
#include <string>
#include <time.h>

class timer
{
private:
	float begTime;
public:
	void start() {
		begTime = clock();
	}

	float elapsedTime() {
		return ((float)clock() - begTime) / CLOCKS_PER_SEC;
	}

	bool isTimeout(float seconds) {
		return seconds >= elapsedTime();
	}
};

class Audio
{

public:

	Audio();
	~Audio();

	void Init();
	void Layering(int layering);
	bool Play();
	void Decay(int decay);
	void Duck(float duck);

	void Reverb(int distance, int numReflections, float seconds);
	void Distance(int distance, int channel);
	void Update();
	void Pause();
	void CloseSFX();
	void SfxPlay();

	int m_test = 5;

private:
	timer t;
	bool m_play;
	bool m_play2;
	bool m_paused;
	float m_duck;
	float* pm_duck = &m_duck;
	float m_musicVol;
	float m_masterVol;
	float m_soundVol;
	float m_fade;
	float m_reverb;
	float m_layering;
	float m_decay;
	int m_distance;
	std::string m_config = "";
	std::string m_data = "";
};

