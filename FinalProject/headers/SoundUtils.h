#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class SoundUtils {
public:
	SoundUtils();
	void stopFail();
	void playFail();
	void stopSuccess();
	void playSuccess();
	void stopGift();
	void playGift();
	void playIntro();
	void stopIntro();
	void playExplosion();
	void stopExplosion();
	void playSteps();
	void stopSteps();
	void playGameOver();
	void stopGameOver();
	void playRestart();
	void stopRestart();
 private:
	sf::Music intro, explosion, steps,gameover,gift,success,fail;
};
