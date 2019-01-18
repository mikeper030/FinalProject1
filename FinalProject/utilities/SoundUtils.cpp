#include "headers/SoundUtils.h"

SoundUtils::SoundUtils()
{
	
	intro.openFromFile("res/intro.wav");
	intro.setVolume(70);
	intro.setLoop(true);

	
	explosion.openFromFile("res/boom.wav");
	explosion.setVolume(80);
	

	steps.openFromFile("res/steps.wav");
	steps.setVolume(60);
	steps.setLoop(true);

	gameover.openFromFile("res/gameover.wav");
	gameover.setVolume(60);

	gift.openFromFile("res/gift.wav");
	gift.setVolume(60);

	fail.openFromFile("res/fail.wav");
	fail.setVolume(60);

	success.openFromFile("res/success.wav");
	success.setVolume(60);
}
void SoundUtils::stopFail()
{
	fail.stop();
}
void SoundUtils::playFail()
{

	fail.play();
}
void SoundUtils::stopSuccess()
{
	success.stop();
}
void SoundUtils::playSuccess()
{
	success.play();
}
void SoundUtils::stopGift()
{
	gift.stop();
}
void SoundUtils::playGift()
{
	gift.play();
}
void SoundUtils::playIntro()
{
	intro.play();
}

void SoundUtils::stopIntro()
{
	intro.stop();
}

void SoundUtils::playExplosion()
{
	explosion.play();
}

void SoundUtils::stopExplosion()
{
	explosion.stop();
}

void SoundUtils::playSteps()
{
	steps.play();
}

void SoundUtils::stopSteps()
{
	steps.stop();
}

void SoundUtils::playGameOver()
{
	gameover.play();
}

void SoundUtils::stopGameOver()
{
	gameover.stop();
}


