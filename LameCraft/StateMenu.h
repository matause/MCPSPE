#ifndef STATEMENU_H_
#define STATEMENU_H_

#include <stdlib.h>

#include <Aurora/Utils/StateManager.h>
#include <Aurora/Utils/GameState.h>

#include <Aurora/Graphics/RenderManager.h>
#include <Aurora/Utils/Logger.h>
#include <Aurora/Utils/Timer.h>
#include <Aurora/System/SystemManager.h>
#include <Aurora/Graphics/Models/ObjModel.h>
#include <Aurora/Graphics/Camera.h>
#include <Aurora/Graphics/Sprite.h>

#include "SoundManager.h"

using namespace Aurora::Graphics;
using namespace Aurora::Utils;
using namespace Aurora::System;
using namespace Aurora;

class SaveFile
{
public:

	int saveVersion;
	bool compression;
	char worldName[50];
	std::string fileName;
};

class StateMenu : public CGameState
{
public:
	StateMenu();
	virtual ~StateMenu();

	void Init();
	void Enter();
	void CleanUp();

	void Pause();
	void Resume();

	void HandleEvents(StateManager* sManager);
	void Update(StateManager* sManager);
	void Draw(StateManager* sManager);

    void ScanSaveFiles(const char* dirName);
	int nextSaveFileNumber;
	std::string nextSaveFileName;

private:
	Sprite *buttonSprite;
	Sprite *sbuttonSprite;
	Sprite *backSprite;
	Sprite *logoSprite;
	Sprite *selectSaveSprite;
	Sprite *lamecraftSprite;
	Sprite *Panorama1Sprite;
	Sprite *Panorama2Sprite;
	Sprite *Panorama3Sprite;
	Sprite *Panorama4Sprite;
	Sprite *menuTool;

	RenderManager *mRender;
	SystemManager *mSystemMgr;
	SoundManager *mSoundMgr;

	int selectPos;
	int loadSelectPos;
	int loadSavePos;
	int aboutPos;
	char worldName[32];

	bool saveSubmenu;
	int saveSubMenuSelect;

	int loadSaveStart;
	int loadSaveEnd;
	int loadSaveMax;

	int timer;

	int animPart;

	int menuState;//0 main,1 load,2 options

	std::vector<SaveFile> saveFilesList;

	//options for parametric map generation
	int terrainType;
	bool makeFlat;
	bool makeTrees;
	bool makeWater;
	bool makeCaves;
    bool makePumpkins;
    bool makeClouds;
    bool makeTypes;
    bool makeIron;
    bool makeCoal;
    bool makeGold;
    bool makeRedStone;
    bool makeDiamond;
    bool makeDirt;
    bool makeLapis;
    bool makeEmerald;
    bool makeLifeBlocks;
	int generateSelectPose;

	//game version
	int currentVersion;
};

#endif
