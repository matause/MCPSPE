#ifndef STATEPLAY_H_
#define STATEPLAY_H_

#include <Aurora/Utils/StateManager.h>
#include <Aurora/Utils/GameState.h>

#include <math.h>
#include <psptypes.h>

#include <Aurora/Graphics/RenderManager.h>
#include <Aurora/Utils/Logger.h>
#include <Aurora/Utils/Timer.h>
#include <Aurora/System/SystemManager.h>
#include <Aurora/Graphics/Models/ObjModel.h>
#include <Aurora/Graphics/Camera.h>
#include <Aurora/Graphics/Sprite.h>
#include <Aurora/Graphics/Effects/SkyDome.h>
#include <Aurora/Graphics/Effects/SkyLight.h>

#include "CraftWorld2.h"
#include "InputHelper.h"
#include "SoundManager.h"

using namespace Aurora::Graphics;
using namespace Aurora::Utils;
using namespace Aurora::System;
using namespace Aurora;


class StatePlay : public CGameState
{
public:
	StatePlay();
	virtual ~StatePlay();

	void Init();
	void InitParametric(int terrainType,bool makeFlat,bool makeTrees,bool makePumpkins,bool makeClouds,bool makeTypes,bool makeWater,bool makeCaves,bool makeSnow,bool makeCoal,bool makeGold,bool makeRedStone,bool makeDiamond,bool makeDirt,bool makeLapis,bool makeEmerald,bool makeLifeBlocks);
	void Enter();
	void CleanUp();

	void Pause();
	void Resume();

	//Extra info
	void UnderwaterBreathing();

	void LoadTextures();

	void HandleEvents(StateManager* sManager);
	void Update(StateManager* sManager);
	void Draw(StateManager* sManager);

	void LoadMap(std::string fileName,bool compressed);
	void SetWorldAndSaveName(std::string worldName,std::string fileName);
	void WorldSize(std::string worldSize);
	void InitCamera();

	//keys helpers
	bool keyPressed(int currentKey);
	bool keyHold(int currentKey);

void TakeDamage(int damage_amt);
void SetupPlayerStats();

private:

	void advancedBlit(int sx, int sy, int sw, int sh, int dx, int dy, int slice);
	bool TryToMove(Vector3 moveVector,float dt);

	void SetDayTimeAfterLoad();

private:

	RenderManager *mRender;
	SystemManager *mSystemMgr;
	SoundManager *mSoundMgr;
	InputHelper *mIhelper;
	Camera *fppCam;

	std::string saveFileName;
	int freeMemory;
	float freeMemoryTimer;

	CraftWorld *mWorld;
	ObjModel *cubeModel;
	SkyDome *skyDome;
	SkyLight *skyLight;
	float sunTime;
	float sunTimeTick;
	bool sunMoonSwitch;

	Vector3 cubePos;
	bool showCube;

	//zmienne do poruszania
	float GRAVITY;
	float JUMPVELOCITY;
	float CLIMBVELOCITY;

	Vector3 playerVelocity;
	Vector3 playerPosition;
	Vector3 newPlayerPos;
	Vector3 oldPlayerPos;
	Vector3 specialPosition;

	bool walkingOnGround;
	bool jumping;
	bool headInWater;
	bool footInWater;
	bool legsInWater;
	bool headInLava;
	bool footInLava;
	bool legsInLava;

	int allcubes;
	int cubesSets;
	int selectedCube;
	int selectedCubeSet;
	int selectedNumberSet;
	int selectedCubeStart;
	int selectedCubeEnd;

	int fuseTimer;

	int ram1;
	int ram2;

	int changeTimer;

	int terrainType;

	Timer mTimer;
	float dt;

	//textures info
	int texture;
	int blue;
	int red;
	Sprite *barSprite;
	Sprite *hungerBar;
	Sprite *halfHungerBar;
	Sprite *hungerBarBG;
	Sprite *heart;
	Sprite *halfheart;
	Sprite *heartbg;
	Sprite *heartbgChange;
	Sprite *bubble;
	Sprite *bubble_splash;
	Sprite *crossSprite;
	Sprite *selectSprite;
	Sprite *InventorySprite;
	Sprite *ThinksSprite;
	Sprite *biloSprite;
	Sprite *char1Sprite;
	Sprite *invchar1Sprite;
	Sprite *SPS;
	
	float cameraSpeed;
	float cameraMoveSpeed;

	//menu sprites
	Sprite *buttonSprite;
	Sprite *sbuttonSprite;

	int menuState;//0 game,1 menu
	int animalState;
	bool menuOptions;
	int optionsMenuPos;
	int selectPos;

	//some settings
	bool canFly;
	bool devMode;
	bool analogLeft,analogRight,analogUp,analogDown;

	bool CanBigCubes;

	bool CanSpawnMobs;

	bool cubeMove;

	//for sound of walkinng
	float walkSoundAccu;
	bool  isWalking;

	//for sound of water
	float waterSoundAccu;
	float hurt_time;

	//Next music track
	int nextMusic;

	int headYank;

	//Headbob
	bool canHeadBob;
	float bobCycle;
	float cubeCycle;

	bool heathChange;

	//damage fade effect
	float damage_fade;
	float damage_fade_time;

	//Lava
	float lava_time;

	int timeToRemove;

	//Runs on each second
	int ticker;

    //for moving of mobs and animals
	int moveTime;

	int neededScore;

	int hungerTime;

	bool makeScreen;
};

#endif
