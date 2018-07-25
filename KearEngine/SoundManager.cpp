#include "SoundManager.h"
#include <Windows.h>
#include <MMSystem.h>


SoundManager::SoundManager()
{
}


SoundManager::~SoundManager()
{
	
}

void SoundManager::playSound()
{
	PlaySound("bgm.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}

void SoundManager::stopSound()
{
	PlaySound(NULL,NULL,0);
}