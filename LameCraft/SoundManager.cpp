#include "SoundManager.h"

SoundManager SoundManager::m_SoundManager;

SoundManager* SoundManager::Instance()
{
	return &m_SoundManager;
}

SoundManager::SoundManager()
{

}

SoundManager::~SoundManager()
{

}

void SoundManager::Precache_Sounds()
{
    //door
    door = oslLoadSoundFile("Assets/Sounds/door.wav",OSL_FMT_NONE);

    //water sounds
    waterSound = oslLoadSoundFile("Assets/Sounds/underwater.wav",OSL_FMT_NONE);
    splash = oslLoadSoundFile("Assets/Sounds/splash.wav",OSL_FMT_NONE);

    //plop sound
	plopSound = oslLoadSoundFile("Assets/Sounds/plop.wav",OSL_FMT_NONE);

    //button sound
	buttonSound = oslLoadSoundFile("Assets/Sounds/button1.wav",OSL_FMT_NONE);

	//TNT
	tnt = oslLoadSoundFile("Assets/Sounds/tnt.wav",OSL_FMT_NONE);

	//Ice/glass breaking
	breakice = oslLoadSoundFile("Assets/Sounds/misc/glass3.wav",OSL_FMT_NONE);

    //player sounds
    eat = oslLoadSoundFile("Assets/Sounds/player/eat.wav",OSL_FMT_NONE);
    //hit
	hit[0] = oslLoadSoundFile("Assets/Sounds/player/hit1.wav",OSL_FMT_NONE);
	hit[1] = oslLoadSoundFile("Assets/Sounds/player/hit2.wav",OSL_FMT_NONE);
	hit[2] = oslLoadSoundFile("Assets/Sounds/player/hit3.wav",OSL_FMT_NONE);

    //zombie
	zombie_death = oslLoadSoundFile("Assets/Sounds/mob/zombie/death.wav",OSL_FMT_NONE);

	//enderman
	enderman_death = oslLoadSoundFile("Assets/Sounds/mob/enderman/death.wav",OSL_FMT_NONE);

	//grass sounds
	grassSounds[0] = oslLoadSoundFile("Assets/Sounds/walking/grass1.wav",OSL_FMT_NONE);
	grassSounds[1] = oslLoadSoundFile("Assets/Sounds/walking/grass2.wav",OSL_FMT_NONE);
	grassSounds[2] = oslLoadSoundFile("Assets/Sounds/walking/grass3.wav",OSL_FMT_NONE);
	grassSounds[3] = oslLoadSoundFile("Assets/Sounds/walking/grass4.wav",OSL_FMT_NONE);

	//grawel
	grawelSounds[0] = oslLoadSoundFile("Assets/Sounds/walking/gravel1.wav",OSL_FMT_NONE);
	grawelSounds[1] = oslLoadSoundFile("Assets/Sounds/walking/gravel2.wav",OSL_FMT_NONE);
	grawelSounds[2] = oslLoadSoundFile("Assets/Sounds/walking/gravel3.wav",OSL_FMT_NONE);
	grawelSounds[3] = oslLoadSoundFile("Assets/Sounds/walking/gravel4.wav",OSL_FMT_NONE);

	//stone
	stoneSounds[0] = oslLoadSoundFile("Assets/Sounds/walking/stone1.wav",OSL_FMT_NONE);
	stoneSounds[1] = oslLoadSoundFile("Assets/Sounds/walking/stone2.wav",OSL_FMT_NONE);
	stoneSounds[2] = oslLoadSoundFile("Assets/Sounds/walking/stone3.wav",OSL_FMT_NONE);
	stoneSounds[3] = oslLoadSoundFile("Assets/Sounds/walking/stone4.wav",OSL_FMT_NONE);

	//wood
	woodSounds[0] = oslLoadSoundFile("Assets/Sounds/walking/wood1.wav",OSL_FMT_NONE);
	woodSounds[1] = oslLoadSoundFile("Assets/Sounds/walking/wood2.wav",OSL_FMT_NONE);
	woodSounds[2] = oslLoadSoundFile("Assets/Sounds/walking/wood3.wav",OSL_FMT_NONE);
	woodSounds[3] = oslLoadSoundFile("Assets/Sounds/walking/wood4.wav",OSL_FMT_NONE);

	//Wool
	woolSounds[0] = oslLoadSoundFile("Assets/sounds/walking/cloth1.wav", OSL_FMT_NONE);
	woolSounds[1] = oslLoadSoundFile("Assets/sounds/walking/cloth2.wav", OSL_FMT_NONE);
	woolSounds[2] = oslLoadSoundFile("Assets/sounds/walking/cloth3.wav", OSL_FMT_NONE);
	woolSounds[3] = oslLoadSoundFile("Assets/sounds/walking/cloth4.wav", OSL_FMT_NONE);

	//Snow
	snowSounds[0] = oslLoadSoundFile("Assets/sounds/walking/snow1.wav", OSL_FMT_NONE);
	snowSounds[1] = oslLoadSoundFile("Assets/sounds/walking/snow2.wav", OSL_FMT_NONE);
	snowSounds[2] = oslLoadSoundFile("Assets/sounds/walking/snow3.wav", OSL_FMT_NONE);
	snowSounds[3] = oslLoadSoundFile("Assets/sounds/walking/snow4.wav", OSL_FMT_NONE);

	//Sand
	sandSounds[0] = oslLoadSoundFile("Assets/sounds/walking/sand1.wav", OSL_FMT_NONE);
	sandSounds[1] = oslLoadSoundFile("Assets/sounds/walking/sand2.wav", OSL_FMT_NONE);
	sandSounds[2] = oslLoadSoundFile("Assets/sounds/walking/sand3.wav", OSL_FMT_NONE);
	sandSounds[3] = oslLoadSoundFile("Assets/sounds/walking/sand4.wav", OSL_FMT_NONE);

	// Ambient
	ambientSounds[0] = oslLoadSoundFile("Assets/Sounds/ambient/track1.bgm",OSL_FMT_STREAM);
	ambientSounds[1] = oslLoadSoundFile("Assets/Sounds/ambient/track2.bgm",OSL_FMT_STREAM);
	ambientSounds[2] = oslLoadSoundFile("Assets/Sounds/ambient/track3.bgm",OSL_FMT_STREAM);
	ambientSounds[3] = oslLoadSoundFile("Assets/Sounds/ambient/track4.bgm",OSL_FMT_STREAM);
	ambientSounds[4] = oslLoadSoundFile("Assets/Sounds/ambient/track5.bgm",OSL_FMT_STREAM);
	ambientSounds[5] = oslLoadSoundFile("Assets/Sounds/ambient/track6.bgm",OSL_FMT_STREAM);
}

void SoundManager::Init()
{
	//first of all init audio engine
	VirtualFileInit();
	//oslInitAudioME(OSL_FMT_MP3);
	oslInitAudio();

	srand(time(NULL));

	Precache_Sounds();

	//set default values
	currentWalkSound = 0;
	lastWalkSound = 0;
	lastAmbientSound = 0;

	playerSounds = true;
	ambientSoundsEnabled = true;
}


void SoundManager::PlayMenuSound()
{
	oslPlaySound(buttonSound, 1);
}

void SoundManager::PlayPlopSound()
{
	if(playerSounds)
		oslPlaySound(plopSound,1);
}

void SoundManager::PlayWaterSound()
{
	if(playerSounds)
		oslPlaySound(waterSound,4);
}

void SoundManager::StopWaterSound()
{
	oslStopSound(waterSound);
}

void SoundManager::SplashSound()
{
	if(playerSounds)
		oslPlaySound(splash,3);
}

void SoundManager::TNTSound()
{
	if(playerSounds)
		oslPlaySound(tnt,6);
}

void SoundManager::HurtSound()
{
	if(playerSounds)
	{
        currentWalkSound = rand() % 3;

        //stop last sound
        oslStopSound(hit[lastWalkSound]);

        //play new sound
        oslPlaySound(hit[currentWalkSound],1);

        //set last sound as current
        lastWalkSound = currentWalkSound;
	}
}

void SoundManager::ZombieDeathSound()
{
	if(playerSounds)
		oslPlaySound(zombie_death,4);
}

void SoundManager::EndermanDeathSound()
{
	if(playerSounds)
		oslPlaySound(enderman_death,4);
}

void SoundManager::EatSound()
{
	if(playerSounds)
		oslPlaySound(eat,6);
}

void SoundManager::doorSound()
{
	if(playerSounds)
		oslPlaySound(door,1);
}

void SoundManager::GlassBreak()
{
	if(playerSounds)
		oslPlaySound(breakice,1);
}

void SoundManager::PlayWalkSound(int type)
{
	if(playerSounds)
	{
		switch(type)
		{
			case 0://grass
			{
				currentWalkSound = rand() % 4;

				//stop last sound
				oslStopSound(grassSounds[lastWalkSound]);

				//play new sound
				oslPlaySound(grassSounds[currentWalkSound],1);

				//set last sound as current
				lastWalkSound = currentWalkSound;
			}
			break;
			case 1://gravel
			{
				currentWalkSound = rand() % 4;

				//stop last sound
				oslStopSound(grawelSounds[lastWalkSound]);

				//play new sound
				oslPlaySound(grawelSounds[currentWalkSound],1);

				//set last sound as current
				lastWalkSound = currentWalkSound;
			}
			break;
			case 2://stone
			{
				currentWalkSound = rand() % 4;

				//stop last sound
				oslStopSound(stoneSounds[lastWalkSound]);

				//play new sound
				oslPlaySound(stoneSounds[currentWalkSound],1);

				//set last sound as current
				lastWalkSound = currentWalkSound;
			}
			break;
			case 3://wood
			{
				currentWalkSound = rand() % 4;

				//stop last sound
				oslStopSound(woodSounds[lastWalkSound]);

				//play new sound
				oslPlaySound(woodSounds[currentWalkSound],1);

				//set last sound as current
				lastWalkSound = currentWalkSound;
			}
			break;
			case 4://wool
			{
				currentWalkSound = rand() % 4;

				//stop last sound
				oslStopSound(woolSounds[lastWalkSound]);

				//play new sound
				oslPlaySound(woolSounds[currentWalkSound],1);

				//set last sound as current
				lastWalkSound = currentWalkSound;
			}
			break;
			case 5://Snow
			{
				currentWalkSound = rand() % 4;

				//stop last sound
				oslStopSound(snowSounds[lastWalkSound]);

				//play new sound
				oslPlaySound(snowSounds[currentWalkSound],1);

				//set last sound as current
				lastWalkSound = currentWalkSound;
			}
			break;
			case 6://Sand
			{
				currentWalkSound = rand() % 4;

				//stop last sound
				oslStopSound(sandSounds[lastWalkSound]);

				//play new sound
				oslPlaySound(sandSounds[currentWalkSound],1);

				//set last sound as current
				lastWalkSound = currentWalkSound;
			}
			break;
		}
	}
}

int SoundManager::PlayRandomAmbient()
{
 	currentAmbientSound = rand() % 7;

	//stop last sound
	oslStopSound(ambientSounds[lastAmbientSound]);

	//play new sound
	if(ambientSounds[currentAmbientSound]&&ambientSoundsEnabled)
		oslPlaySound(ambientSounds[currentAmbientSound],2);

	//set last sound as current
	lastAmbientSound = currentAmbientSound;

	switch(currentAmbientSound)
	{
		case 0:
			{
				return 230;
			}
			break;
		case 1:
			{
				return 210;
			}
			break;
		case 2:
			{
				return 220;
			}
			break;
		case 3:
			{
				return 280;
			}
			break;
		case 4:
			{
				return 90;
			}
			break;
		case 5:
			{
				return 90;
			}
			break;
	}
	return 1;
}
