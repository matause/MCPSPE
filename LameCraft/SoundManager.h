#ifndef SOUNDMANAGER_H_
#define SOUNDMANAGER_H_

extern "C"
{
	#include "sound_utils/oslib.h"
}

#include <stdlib.h>
#include <time.h>

class SoundManager
{
public:
	SoundManager();
	~SoundManager();

	static SoundManager m_SoundManager;
	static SoundManager* Instance();

	void Precache_Sounds();
	void Init();

	void PlayMenuSound();
	void PlayPlopSound();
	void PlayWalkSound(int type);
	void PlayWaterSound();
	void StopWaterSound();
	void SplashSound();
	void TNTSound();
	void HurtSound();
	void ZombieDeathSound();
	void EndermanDeathSound();
	void EatSound();
	void doorSound();
	void GlassBreak();

	int PlayRandomAmbient();

	bool playerSounds;
	bool ambientSoundsEnabled;

	int lastAmbientSound;
	int currentAmbientSound;

private:

	int currentWalkSound;
	int lastWalkSound;

	//sounds
	OSL_SOUND *buttonSound;

	//plop sound
	OSL_SOUND *plopSound;

	OSL_SOUND *grassSounds[4];
	OSL_SOUND *grawelSounds[4];
	OSL_SOUND *stoneSounds[4];
	OSL_SOUND *woodSounds[4];
    OSL_SOUND *ambientSounds[6];
    OSL_SOUND *woolSounds[4];
	OSL_SOUND *snowSounds[4];
	OSL_SOUND *sandSounds[4];

	OSL_SOUND *hit[3];

	//TNT
	OSL_SOUND *tnt;

	//water sound
	OSL_SOUND *waterSound;
	OSL_SOUND *splash;

	//player
	OSL_SOUND *eat;

    //zombie
	OSL_SOUND *zombie_death;

	//enderman
	OSL_SOUND *enderman_death;

	//Breaking sounds
	OSL_SOUND *breakice;

	OSL_SOUND *door;




};

#endif

