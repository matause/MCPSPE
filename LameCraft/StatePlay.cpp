#include "StatePlay.h"
#include "TextureHelper.h"
#include "LoadingScreen.h"
#include "StateMenu.h"
#include "CraftWorld2.h"

#include "vfpu.h"

#include "WorldGenerator.h"

#define PI 3.1415926535897f
#define DEG_TO_RAD (PI / 180.0f)
#define TEXTURE_CHUNKS 8

StatePlay::StatePlay()
{
    mRender = NULL;
    mSystemMgr = NULL;
    fppCam = NULL;

    //utils
    freeMemory = 0;
    freeMemoryTimer = 0.0f;

    timeToRemove = 0;

    showCube = true;

    //zmienne do poruszania
    GRAVITY = -9.8f;
    JUMPVELOCITY = 4.0f;
    CLIMBVELOCITY = 2.5f;

    walkingOnGround = false;
    jumping = false;
    headInWater = false;
    footInWater = false;
    legsInWater = false;
    headInLava = false;
    footInLava = false;
    legsInLava = false;

    selectedCube = 0;
    selectedCubeSet = 0;
    selectedCubeStart = 0;

    ram1 = 0;
    ram2 = 0;
    dt = 0.0f;
    sunTime = 21600.0f;//6 am
    sunTimeTick = 0.0f;
    sunMoonSwitch = true;

    cameraSpeed = 2.0f / 60.0f;
    cameraMoveSpeed = 4.0f/ 60.0f;

    //stete to game
    selectPos = 0;

    //flying
    canFly = false;
    devMode = false;
    makeScreen = false;

    CanBigCubes = false;

    heathChange = false;

    //bob
    canHeadBob = true;
    bobCycle = 0.0f;

    CanSpawnMobs = true;
}

StatePlay::~StatePlay()
{

}

void StatePlay::TakeDamage(int damage_amt)
{
    damage_fade = 0.5;
    mWorld->player.health -= damage_amt;

    mSoundMgr->HurtSound();

    if (mWorld->player.health < 0)	//Make the health counter look good
        mWorld->player.health = 0;
}

void StatePlay::SetupPlayerStats()
{
    mWorld->player.air_time = 100;
    //damage_fade = 0;
    mWorld->player.safe_spawn = true;

    //half hunger bar
    halfHungerBar = new Sprite("Assets/Lamecraft/utils.png",237,9,9,9);
    halfHungerBar->Scale(2.0f,2.0f);

    //hunger bar
    hungerBar = new Sprite("Assets/Lamecraft/utils.png",228,9,9,9);
    hungerBar->Scale(2.0f,2.0f);

    //hunger bar bg
    hungerBarBG = new Sprite("Assets/Lamecraft/utils.png",219,9,9,9);
    hungerBarBG->Scale(2.0f,2.0f);

    //Life sprite
    heart = new Sprite("Assets/Lamecraft/utils.png",201,2,7,7);
    heart->Scale(2.0f,2.0f);

    //Half heart
    halfheart = new Sprite("Assets/Lamecraft/utils.png",239,1,7,7);
    halfheart->Scale(2.0f,2.0f);

    //Life Background
    heartbg = new Sprite("Assets/Lamecraft/utils.png",209,1,9,9);
    heartbg->Scale(2.0f,2.0f);

    heartbgChange = new Sprite("Assets/Lamecraft/utils.png",247,1,9,9);
    heartbgChange->Scale(2.0f,2.0f);

    //Bubble sprite
    bubble = new Sprite("Assets/Lamecraft/utils.png",219,0,9,9);
    bubble->Scale(2.0f,2.0f);

    //Bubble splash sprite
    bubble_splash = new Sprite("Assets/Lamecraft/utils.png",229,0,9,9);
    bubble_splash->Scale(2.0f,2.0f);

    //Inventory
    InventorySprite = new Sprite(TextureHelper::Instance()->GetTexture(TextureHelper::Inventory),0,0,264,250);    
    
    //SPS
    SPS = new Sprite("Assets/Lamecraft/mod/things.png");
    
    //bilo
    biloSprite = new Sprite(TextureHelper::Instance()->GetTexture(TextureHelper::bilo),0,0,246,166);
    biloSprite->Scale(2.0f,2.0f);
    
    //charakter
    char1Sprite = new Sprite(TextureHelper::Instance()->GetTexture(TextureHelper::char1),0,0,32,64);
    char1Sprite->Scale(2.0f,2.0f);
    
    //invcharakter
    invchar1Sprite = new Sprite(TextureHelper::Instance()->GetTexture(TextureHelper::invchar1),0,0,16,32);
    invchar1Sprite->Scale(2.0f,2.0f);
}

void StatePlay::InitCamera()
{
    fppCam = new Camera();
    fppCam->PositionCamera(playerPosition.x,playerPosition.y,playerPosition.z, playerPosition.x,playerPosition.y,playerPosition.z-5.0f, 0.0f,1.0f,0.0f);
    mRender->SetActiveCamera(fppCam);
}

void StatePlay::Init()
{
    //set render manager instance
    mRender = RenderManager::InstancePtr();
    mSystemMgr = SystemManager::Instance();
    mSoundMgr = SoundManager::Instance();
    mIhelper = InputHelper::Instance();

    playerPosition = newPlayerPos = oldPlayerPos = Vector3(64.0f,80.0f,64.0f);

    WorldGenerator *mGen = new WorldGenerator();

    //then create our perfect world
    mWorld = new CraftWorld();
    mWorld->initWorld(128, 16);
    mGen->initRandompMap(128, 16, mWorld);
    delete mGen;
    //mWorld->initRandompMap(128,16);
    mWorld->setTextureSize(512,16);
    mWorld->initWorldBlocksLight();
    mWorld->SetWolrdTime(5);
    mWorld->UpdatePlayerZoneBB(playerPosition);
    mWorld->buildMap();
    mWorld->buildblocksVerts();

    dt = mTimer.GetDeltaTime();

    //block sets info
    allcubes = mWorld->GetBlockTypesCount();
    //selectedCubeEnd = allcubes - 2;//because we don't want first one and last one
    cubesSets = std::floor(allcubes / 9);//9 cubes is set

    LoadTextures();

    menuOptions = false;
    optionsMenuPos = 0;

    menuState = 3;

    analogLeft = analogRight = analogUp = analogDown = false;

    walkSoundAccu = 0.0f;
    isWalking = false;

    SetupPlayerStats();
    mWorld->player.maxhealth = 100;
    mWorld->player.health = 100;
    mWorld->player.Apples = 0;
	mWorld->player.GrassNumber = 0;
	mWorld->player.DirtNumber = 0;
	mWorld->player.LogNumber = 0;
	mWorld->player.PlankNumber = 0;
    mWorld->player.melons = 0;
    mWorld->player.hunger = 100;
    mWorld->player.score = 0;
    mWorld->player.NumMobs = 0;
    mWorld->player.jumpHeight = 0;
    mWorld->player.walkSpeed = 0;
    mWorld->player.fireResistance = 0;


    mSoundMgr->PlayRandomAmbient();
}

void StatePlay::InitParametric(int terrainType,bool makeFlat,bool makeTrees,bool makePumpkins,bool makeClouds,bool makeWater,bool makeCaves,bool makeTypes,bool makeIron,bool makeCoal,bool makeGold,bool makeRedStone,bool makeDiamond,bool makeDirt,bool makeLapis,bool makeEmerald,bool makeLifeBlocks)
{
    //set render manager instance
    mRender = RenderManager::InstancePtr();
    mSystemMgr = SystemManager::Instance();
    mSoundMgr = SoundManager::Instance();
    mIhelper = InputHelper::Instance();

    //
    playerPosition = newPlayerPos = oldPlayerPos = Vector3(64.0f,80.0f,64.0f);

    //then create our perfect world
    mWorld = new CraftWorld();
    mWorld->initWorld(128, 16);

    WorldGenerator *mGen = new WorldGenerator();
    mGen->initRandompMap(128,16, mWorld, terrainType,makeFlat,makeTrees,makePumpkins,makeClouds,makeTypes,makeWater,makeIron,makeCaves,makeCoal,makeGold,makeRedStone,makeDiamond,makeDirt,makeLapis,makeEmerald,makeLifeBlocks);
    delete mGen;
    //mWorld->initRandompMap(128,16,terrainType,makeFlat,makeTrees,makeWater,makeCaves);
    mWorld->setTextureSize(512,16);
    mWorld->initWorldBlocksLight();
    mWorld->SetWolrdTime(5);
    mWorld->UpdatePlayerZoneBB(playerPosition);
    mWorld->buildMap();
    mWorld->buildblocksVerts();

    dt = mTimer.GetDeltaTime();

    //block sets info
    allcubes = mWorld->GetBlockTypesCount();
    //selectedCubeEnd = allcubes - 2;//because we don't want first one and last one
    cubesSets = std::floor(allcubes / 9);//9 cubes is set

    LoadTextures();

    menuOptions = false;
    optionsMenuPos = 0;

    menuState = 3;

    analogLeft = analogRight = analogUp = analogDown = false;

    walkSoundAccu = 0.0f;
    isWalking = false;

    SetupPlayerStats();
    mWorld->player.maxhealth = 100;
    mWorld->player.health = 100;
    mWorld->player.Apples = 0;
	mWorld->player.GrassNumber = 0;
	mWorld->player.DirtNumber = 0;
	mWorld->player.LogNumber = 0;
	mWorld->player.PlankNumber = 0;
    mWorld->player.melons = 0;
    mWorld->player.hunger = 100;
    mWorld->player.score = 0;
    mWorld->player.NumMobs = 0;
    mWorld->player.jumpHeight = 0;
    mWorld->player.walkSpeed = 0;
    mWorld->player.fireResistance = 0;
}

void StatePlay::SetWorldAndSaveName(std::string worldName,std::string fileName)
{
    if(mWorld != NULL)
    {
        sprintf(mWorld->worldName,"%s",worldName.c_str());
    }
    saveFileName = fileName;
}

void StatePlay::LoadMap(std::string fileName,bool compressed)
{
    //set render manager instance
    mRender = RenderManager::InstancePtr();
    mSystemMgr = SystemManager::Instance();
    mSoundMgr = SoundManager::Instance();
    mIhelper = InputHelper::Instance();

    //save name
    saveFileName = fileName;
    //
    playerPosition = newPlayerPos = oldPlayerPos = Vector3(64.0f,80.0f,64.0f);

    //then create our perfect world
    mWorld = new CraftWorld();

    if(compressed)
    {
        mWorld->LoadCompressedWorld(saveFileName);
        //set player pos from map
        playerPosition = mWorld->GetPlayerPos();
        newPlayerPos  = mWorld->GetPlayerPos();
        oldPlayerPos = mWorld->GetPlayerPos();
        mWorld->player.health = mWorld->GetPlayerhealth();
        mWorld->player.maxhealth = mWorld->GetPlayermaxhealth();
        mWorld->player.Apples = mWorld->Apples();
		mWorld->player.GrassNumber = mWorld->GrassNumber();
		mWorld->player.DirtNumber = mWorld->DirtNumber();
		mWorld->player.LogNumber = mWorld->LogNumber();
		mWorld->player.PlankNumber = mWorld->PlankNumber();
        mWorld->player.melons = mWorld->melons();
        mWorld->player.hunger = mWorld->hunger();
        mWorld->player.score = mWorld->score();
        mWorld->SetWolrdTime(mWorld->worldDayTime);
        mWorld->player.NumMobs = mWorld->NumMobs();
        mWorld->player.gamemode = mWorld->gamemode();
        mWorld->player.jumpHeight = mWorld->jumpHeight();
        mWorld->player.walkSpeed = mWorld->walkSpeed();
        mWorld->player.fireResistance = mWorld->fireResistance();
    }
    else
    {
        mWorld->LoadWorld(saveFileName.c_str());
        mWorld->SetWolrdTime(5);
    }

    mWorld->setTextureSize(512,16);
    mWorld->UpdatePlayerZoneBB(playerPosition);
    mWorld->buildMap();
    mWorld->buildblocksVerts();

    dt = mTimer.GetDeltaTime();

    //block sets info
    allcubes = mWorld->GetBlockTypesCount();
    //selectedCubeEnd = allcubes - 2;//because we don't want first one and last one
    cubesSets = std::floor(allcubes / 9);//9 cubes is set

    LoadTextures();

    menuOptions = false;
    optionsMenuPos = 0;

    menuState = 0;//dont show gamemode setting again

    analogLeft = analogRight = analogUp = analogDown = false;

    walkSoundAccu = 0.0f;
    isWalking = false;

    SetupPlayerStats();

    SetDayTimeAfterLoad();
}

void StatePlay::LoadTextures()
{
    //terrain texure
    texture = TextureHelper::Instance()->GetTexture(TextureHelper::Terrain);

    //water filter
    blue = TextureHelper::Instance()->GetTexture(TextureHelper::Blue);


    red = TextureHelper::Instance()->GetTexture(TextureHelper::Red);


    //bar image
    barSprite = new Sprite(TextureHelper::Instance()->GetTexture(TextureHelper::Utils),0,0,182,22);
    barSprite->SetPosition(240,253);
    barSprite->Scale(1.75f,1.75f);

    selectSprite = new Sprite(TextureHelper::Instance()->GetTexture(TextureHelper::Utils),1,23,22,22);
    selectSprite->SetPosition(100,253);
    selectSprite->Scale(1.75f,1.75f);

    crossSprite = new Sprite(TextureHelper::Instance()->GetTexture(TextureHelper::Utils),201,13,9,9);
    crossSprite->SetPosition(240,136);
    crossSprite->Scale(2.0f,2.0f);

    buttonSprite = new Sprite(TextureHelper::Instance()->GetTexture(TextureHelper::Utils),24,22,200,20);
    buttonSprite->SetPosition(240,150);

    sbuttonSprite = new Sprite(TextureHelper::Instance()->GetTexture(TextureHelper::Utils),24,42,200,20);
    sbuttonSprite->SetPosition(240,150);

    cubeModel = new ObjModel();
    cubeModel->LoadObj("Assets/Lamecraft/textureCube.obj");
    cubeModel->Optimize();


    //sky dome
    skyDome = new SkyDome();
    skyDome->CreateSkyDomeMesh();

    skyDome->SetTexture(TextureHelper::Instance()->GetTexture(TextureHelper::Sky));
    skyDome->timeOfDay = 0.1f;

    skyLight = new SkyLight();
    skyLight->SetTexture(TextureHelper::Instance()->GetTexture(TextureHelper::Sun));
}

void StatePlay::SetDayTimeAfterLoad()
{
    if(!mWorld->freezeDayTime)
    {
        if(mWorld->worldVersion >=3)
        {
            if(mWorld->worldDayTime >= 5.0f && mWorld->worldDayTime < 21.0f)
            {
                skyLight->SetTexture(TextureManager::Instance()->GetTextureNumber("Assets/Lamecraft/sun.png"));
                sunMoonSwitch = true;
            }
            else
            {
                skyLight->SetTexture(TextureManager::Instance()->GetTextureNumber("Assets/Lamecraft/moon.png"));
                sunMoonSwitch = false;
            }

            sunTime = mWorld->sunTime;
            skyDome->timeOfDay = mWorld->worldDayTime * 0.041666f;
        }
    }
}
void StatePlay::Enter()
{
    RenderManager::InstancePtr()->SetPerspective(55.0f, 480.0f / 272.0f, 0.18f, 1000.f);
}
void StatePlay::CleanUp()
{
    delete mRender->mCam;
    mRender->mCam = NULL;

    delete buttonSprite;
    delete sbuttonSprite;
    delete barSprite;
    delete selectSprite;
    delete crossSprite;
    delete hungerBar;
    delete halfHungerBar;
    delete hungerBarBG;
    delete heart;
    delete halfheart;
    delete heartbg;
    delete bubble;
    delete cubeModel;
    delete skyDome;
    delete skyLight;
    //delete fppCam;
    delete mWorld;
}

void StatePlay::Pause()
{

}

void StatePlay::Resume()
{

}

void StatePlay::HandleEvents(StateManager* sManager)
{
    //update delta time
    dt = mTimer.GetDeltaTime();

    cameraSpeed = 2.0f * dt;
    cameraMoveSpeed = 4.0f * dt;

    Vector3 delta = fppCam->m_vView - fppCam->m_vPosition;
    playerPosition = fppCam->m_vPosition;

    //gravity
    Vector3 footPosition = playerPosition + Vector3(0.0f, -1.5f, 0.0f);
    Vector3 legsPosition = playerPosition + Vector3(0.0f, -1.0f, 0.0f);
    Vector3 headPosition = playerPosition + Vector3(0.0f, 0.1f, 0.0f);


    //free memory counter
    if(devMode)
    {
        freeMemoryTimer += dt;
        if(freeMemoryTimer > 1.0f)
        {
            freeMemory = mSystemMgr->ramAvailable();
            freeMemoryTimer = 0.0f;
        }
    }

    //update input
    mSystemMgr->InputUpdate();

    if(menuState == 0)//game state
    {
        if(keyPressed(InputHelper::Instance()->getButtonToAction(14)) && keyPressed(InputHelper::Instance()->getButtonToAction(13)) && mWorld->player.health > 0 && (mWorld->player.gamemode == 0 || mWorld->player.gamemode == 2))
        {
            menuState = 2;
        }

        if(keyPressed(InputHelper::Instance()->getButtonToAction(5)) 	//He presses craft button
                && mWorld->player.health <= 0)								//Player is dead
        {
            if(mWorld->player.gamemode == 2)
            {
                sManager->Quit();
            }
            else
            {
                mWorld->player.health = mWorld->player.maxhealth;
                mWorld->player.air_time = 100;
                mWorld->player.safe_spawn = true;
                mWorld->player.hunger = 100;
                mWorld->player.score = 0;

                playerPosition.x = newPlayerPos.x;
                playerPosition.y = newPlayerPos.y;
                playerPosition.z = newPlayerPos.z;

                mWorld->UpdatePlayerZoneBB(playerPosition);	//Move player back to original spawn point
                fppCam->m_vPosition = playerPosition;
                cameraSpeed = 2.0/ 60.0f;	//Possibly fix camera bug
                fppCam->RotateView(0,0,90,0);


                //Make sure the player is on the ground so chunks can be rebuilt
                if (walkingOnGround)
                {
                    int chunkTarget = mWorld->getChunkId(playerPosition-Vector3(0, -1.5, 0));	//Get the ground cube

                    mWorld->rebuildChunk(chunkTarget);			//Rebuild the world around you
                    mWorld->rebuildTransparentChunk(chunkTarget);
                    mWorld->rebuildNearestChunks(chunkTarget,playerPosition);
                }
                return;
            }
        }

        if (mWorld->player.health <= 0)	//No moving or pressing any button
            return;

        if (menuState == 3)
            return;

        //menu
        if(keyPressed(InputHelper::Instance()->getButtonToAction(15)))
        {
            menuState = 1;
            menuOptions = false;
            optionsMenuPos = 0;
        }

        //camera input
        //rotate down
        if(keyHold(InputHelper::Instance()->getButtonToAction(5)))
        {
            fppCam->PitchView(-cameraSpeed);
        }
        //rotate up
        if(keyHold(InputHelper::Instance()->getButtonToAction(4)))
        {
            fppCam->PitchView(cameraSpeed);
        }
        //rotate right
        if(keyHold(InputHelper::Instance()->getButtonToAction(7)))
        {
            fppCam->RotateView(-cameraSpeed,0,1,0);
        }
        //rotate left
        if(keyHold(InputHelper::Instance()->getButtonToAction(6)))
        {
            fppCam->RotateView(cameraSpeed,0,1,0);
        }

        //move right
        if(keyHold(InputHelper::Instance()->getButtonToAction(3)))
        {
            fppCam->StrafePhysic(cameraMoveSpeed);
        }
        //move left
        if(keyHold(InputHelper::Instance()->getButtonToAction(2)))
        {
            fppCam->StrafePhysic(-cameraMoveSpeed);
        }

        //move back
        if(keyHold(InputHelper::Instance()->getButtonToAction(1)))
        {
            if(canFly)
                fppCam->MovePhysic(-cameraMoveSpeed);
            else
                fppCam->MovePhysicNoY(-cameraMoveSpeed);
        }

        //move forward
        if(keyHold(InputHelper::Instance()->getButtonToAction(0)))
        {
            if(canFly)
                fppCam->MovePhysic(cameraMoveSpeed);
            else
                fppCam->MovePhysicNoY(cameraMoveSpeed);
        }

        //cubes management
        //switch right
        if(keyPressed(InputHelper::Instance()->getButtonToAction(9)))
        {
            selectedCube++;
            if(selectedCubeSet == (cubesSets - 1) * 9)
            {
                if(selectedCube > (allcubes - ((cubesSets - 1) * 9) - 14))
                    selectedCube = 0;
            }
            else
            {
                if(selectedCube > 8)
                    selectedCube = 0;
            }

            selectSprite->SetPosition(100 + (selectedCube * 35),253);
        }
        //switch right
        if(keyPressed(InputHelper::Instance()->getButtonToAction(8)))
        {
            selectedCube--;
            if(selectedCube < 0)
            {
                if(selectedCubeSet == (cubesSets - 1) * 9)
                    selectedCube = allcubes - ((cubesSets - 1) * 9) - 14;
                else
                    selectedCube = 8;
            }

            selectSprite->SetPosition(100 + (selectedCube * 35),253);
        }
        //switch down
        if(keyPressed(InputHelper::Instance()->getButtonToAction(11)))
        {
            selectedCubeSet-=9;
            if(selectedCubeSet < 0)
            {
                selectedCubeSet = (cubesSets - 1) * 9;

                //don't allow to select empty block
                if(selectedCube > (allcubes - ((cubesSets - 1) * 9) - 14))
                {
                    selectedCube = allcubes - ((cubesSets - 1) * 9) - 14;
                    selectSprite->SetPosition(100 + (selectedCube * 35),253);
                }
            }
        }
        //switch up
        if(keyPressed(InputHelper::Instance()->getButtonToAction(10)))
        {
            selectedCubeSet+=9;

            if(selectedCubeSet == (cubesSets - 1) * 9)
            {
                //don't allow to select empty block
                if(selectedCube > (allcubes - ((cubesSets - 1) * 9) - 14))
                {
                    selectedCube = allcubes - ((cubesSets - 1) * 9) - 14;
                    selectSprite->SetPosition(100 + (selectedCube * 35),253);
                }
            }

            if(selectedCubeSet > ((cubesSets - 1) * 9))
                selectedCubeSet = 0;
        }

        //add cube
        if(keyPressed(InputHelper::Instance()->getButtonToAction(14)))
        {
		    
			
			keyPressed(InputHelper::Instance()->getButtonToAction(14));
            cubeMove = true;

            //add cube
            Vector3 rayDir = fppCam->m_vView - fppCam->m_vPosition;
            rayDir.normalize();
			


            //get position and view vector
            Vector3 testPos;

            //move to the target +=0.5
            for(float i = 0; i < 5.25f; i+=0.25f)
            {
                testPos = fppCam->m_vPosition + (rayDir * i);





                //check if we are touch something
				
				
				
				
                if(mWorld->BlockEditable(testPos.x,testPos.y,testPos.z))
                {

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == Door2::getID())
                    {
                        mSoundMgr->doorSound();

                        int	curchunkTarget = mWorld->getChunkId(testPos);
                        for(int x = 0; x <= 0; x++)
                        {
                            for(int y = 1; y <= 1; y++)
                            {
                                for(int z = 0; z <= 0; z++)
                                {
                                    if(mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != IronBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != WaterBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != Cloud::getID())

                                        mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) = Door3::getID();
                                }
                            }
                        }
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = Door4::getID();
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;

                    }
                    



                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == Door1::getID())
                    {
                        mSoundMgr->doorSound();

                        int	curchunkTarget = mWorld->getChunkId(testPos);
                        for(int x = 0; x <= 0; x++)
                        {
                            for(int y = -1; y <= -1; y++)
                            {
                                for(int z = 0; z <= 0; z++)
                                {
                                    if(mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != IronBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != WaterBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != Cloud::getID())

                                        mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) = Door4::getID();
                                }
                            }
                        }
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = Door3::getID();
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;

                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == Door3::getID())
                    {
                        mSoundMgr->doorSound();

                        int	curchunkTarget = mWorld->getChunkId(testPos);
                        for(int x = 0; x <= 0; x++)
                        {
                            for(int y = -1; y <= -1; y++)
                            {
                                for(int z = 0; z <= 0; z++)
                                {
                                    if(mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != IronBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != WaterBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != Cloud::getID())

                                        mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) = Door2::getID();
                                }
                            }
                        }
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = Door1::getID();
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;

                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == Cake::getID())
                    {
                        mSoundMgr->EatSound();
                        mWorld->player.health = mWorld->player.maxhealth;

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;

                    }
					
					
					if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == 105)
                    {
                        menuState = 4;
                        selectPos = 0;

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 105;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;
                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == 129)
                    {
                        menuState = 4;
                        selectPos = 0;

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 129;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;
                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == Door4::getID())
                    {
                        mSoundMgr->doorSound();

                        int	curchunkTarget = mWorld->getChunkId(testPos);
                        for(int x = 0; x <= 0; x++)
                        {
                            for(int y = 1; y <= 1; y++)
                            {
                                for(int z = 0; z <= 0; z++)
                                {
                                    if(mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != IronBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != WaterBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != Cloud::getID())

                                        mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) = Door1::getID();
                                }
                            }
                        }
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = Door2::getID();
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;

                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == Furnace::getID())
                    {

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        //Delete the actual TNT just in case
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = Furnace2::getID();
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;
                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == Furnace2::getID())
                    {

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        //Delete the actual TNT just in case
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = Furnace::getID();
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;
                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == Grass::getID())
                    {
                        if(mWorld->LightSourceBlock(selectedCubeSet + selectedCube+1))
                        {
                            mWorld->SetLigtSourcePosition(testPos.x,testPos.y,testPos.z,selectedCubeSet + selectedCube+1);
                        }

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = selectedCubeSet + selectedCube + 1;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;
                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == TrapDoor::getID())
                    {
                        mSoundMgr->doorSound();

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        //Delete the actual TNT just in case
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = TrapDoor2::getID();
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;
                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == TrapDoor2::getID())
                    {
                        mSoundMgr->doorSound();

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        //Delete the actual TNT just in case
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = TrapDoor::getID();
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;
                    }
					
					if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == GrassBlock::getID())
                    {
                      mWorld->player.GrassNumber -= 1;
					  keyPressed(InputHelper::Instance()->getButtonToAction(14));
					  
                    }
                     
					 
					 if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == DirtBlock::getID())
                    {
                       mWorld->player.DirtNumber -= 1;
					   keyPressed(InputHelper::Instance()->getButtonToAction(14));
                    }
					
					 if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == WoodBlock::getID())
                    {
					keyPressed(InputHelper::Instance()->getButtonToAction(14));
                       mWorld->player.LogNumber -= 1;
                    }
					
					 if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == BoxBlock::getID())
                    {
					keyPressed(InputHelper::Instance()->getButtonToAction(14));
                       mWorld->player.PlankNumber -= 1;
                    }
					
					
					
				
					
					
					
					 
                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == JukeBox::getID())
                    {
                        mRender->DebugPrint(220,220,"track: %d",mSoundMgr->currentAmbientSound);

                        mSoundMgr->PlayRandomAmbient();

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        //Delete the actual TNT just in caseo
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = JukeBox::getID();
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;
                    }

                    BoundingBox testBox = BoundingBox(Vector3(cubePos.x - 0.5f,cubePos.y - 0.5f,cubePos.z - 0.5f),Vector3(cubePos.x + 0.5f,cubePos.y + 0.5f,cubePos.z + 0.5f));
                    Ray tesRay = Ray(fppCam->m_vPosition,rayDir);

                    float distance = -1.0f;
                    tesRay.hasIntersected(testBox,distance);

                    if(distance != -1.0f)
                    {
                        Vector3 hitPos = fppCam->m_vPosition + (rayDir * distance);
                        Vector3 normal = (hitPos - cubePos);
                        normal.normalize();

                        Vector3 testPos2;

                        if(normal.x < -0.66f)
                            testPos2.x = -1.0f;
                        else if(normal.x > 0.66f)
                            testPos2.x = 1.0f;
                        else
                            testPos2.x = 0.0f;

                        if(normal.y < -0.66f)
                            testPos2.y = -1.0f;
                        else if(normal.y > 0.66f)
                            testPos2.y = 1.0f;
                        else
                            testPos2.y = 0.0f;

                        if(normal.z < -0.66f)
                            testPos2.z = -1.0f;
                        else if(normal.z > 0.66f)
                            testPos2.z = 1.0f;
                        else
                            testPos2.z = 0.0f;


                        testPos2 += testPos;
						
						
		
                        //check if this block is empty
                        if(mWorld->GetBlock(testPos2.x,testPos2.y,testPos2.z) == Fire::getID() || mWorld->GetBlock(testPos2.x,testPos2.y,testPos2.z) == WaterFlow::getID() || mWorld->GetBlock(testPos2.x,testPos2.y,testPos2.z) == Lava::getID() || mWorld->GetBlock(testPos2.x,testPos2.y,testPos2.z) == 4 || mWorld->GetBlock(testPos2.x,testPos2.y,testPos2.z) == 0 || mWorld->GetBlock(testPos2.x,testPos2.y,testPos2.z) == Cloud::getID())
                        {

                            //now check if player is not there ;) we don't want to place cubes where we stand
                            int boxX = (int)testPos2.x;
                            int boxY = (int)testPos2.y;
                            int boxZ = (int)testPos2.z;
							
					

                            BoundingBox blockBox = BoundingBox(Vector3(boxX,boxY,boxZ),Vector3(boxX + 1,boxY + 1,boxZ + 1));
                            BoundingBox playerBox = BoundingBox(Vector3(playerPosition.x - 0.15f,playerPosition.y - 1.5f,playerPosition.z - 0.15f),Vector3(playerPosition.x + 0.15f,playerPosition.y + 0.2f,playerPosition.z + 0.15f));

                            if(!blockBox.intersect(playerBox))
                            {
                                //check if you want put light source or normal block
                                if(mWorld->CanPutBlockHere(testPos2.x,testPos2.y,testPos2.z,selectedCubeSet + selectedCube+1))
                                {
                                    if(mWorld->LightSourceBlock(selectedCubeSet + selectedCube+1))
                                    {
                                        mWorld->SetLigtSourcePosition(testPos2.x,testPos2.y,testPos2.z,selectedCubeSet + selectedCube+1);
                                    }
                                    if (mWorld->GetBlock(testPos2.x,testPos2.y,testPos2.z) == Lava::getID() && selectedCubeSet + selectedCube+1 != Lava::getID())
                                    {
                                        mWorld->RemoveLigtSourceAtPosition(testPos.x,testPos.y,testPos.z, Lava::getID());
                                    }

                                    if(CanBigCubes)
                                    {
                                        for(int x = -4; x <= 4; x++)
                                        {
                                            for(int y = -4; y <= 4; y++)
                                            {
                                                for(int z = -4; z <= 4; z++)
                                                {
                                                    if(mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != IronBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != WaterBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != Cloud::getID())

                                                        if(sqrt(pow(sqrt(pow(x,2)+pow(y,2)),2)+pow(z,2))<=4)
                                                            mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) = selectedCubeSet + selectedCube + 1;
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        mWorld->GetBlock(testPos2.x,testPos2.y,testPos2.z) = selectedCubeSet + selectedCube+1;//set block type
                                    }

                                    int chunkTarget = mWorld->getChunkId(testPos2);

                                    if(chunkTarget != -1)
                                    {
                                        mSoundMgr->PlayPlopSound();

                                        //rebuild
                                        if(mWorld->LightSourceBlock(selectedCubeSet + selectedCube+1))
                                        {
                                            mWorld->RebuildChunksLight(testPos2,chunkTarget,(selectedCubeSet + selectedCube+1));
                                        }
                                        else
                                        {
                                            //check if there are light sources nearby
                                            mWorld->UpdateLightAreaIn(testPos2);

                                            //rebuild chunks
                                            mWorld->rebuildChunk(chunkTarget);
                                            mWorld->rebuildTransparentChunk(chunkTarget);
                                            //rebuild chunks that are near this chunk
                                            mWorld->rebuildNearestChunks(chunkTarget,testPos2);
                                        }
                                    }
                                }

                                fppCam->needUpdate = true;
                            }
                        }
                    }

                    break;
                }
            }


        }



        //remove cube
        if(keyHold(InputHelper::Instance()->getButtonToAction(13)) && (mWorld->player.gamemode == 0 || mWorld->player.gamemode == 2))
        {
            if(canHeadBob)
            {
                cubeCycle += dt*3;
                if(cubeCycle>1.0f)
                {
                    cubeCycle=0.0f;
                }
            }

            timeToRemove += 1;

            bool wasLight = false;
            block_t oldBlock = 0;
            //remove cube
            Vector3 rayDir = fppCam->m_vView - fppCam->m_vPosition;
            rayDir.normalize();

            //we are takin our positiona and view vector
            Vector3 testPos;


            //we are moving slowly to the target +=0.5
            for(float i = 0; i < 5.25f; i+=0.25f)
            {
                testPos = fppCam->m_vPosition + (rayDir * i);
                
				
				
				
                //check if we touch something
                if(mWorld->BlockEditable(testPos.x,testPos.y,testPos.z))
                {

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == ZombieLegs::getID() && mWorld->GetBlock(testPos.x, testPos.y+1, testPos.z) == ZombieTop::getID())
                    {
                        mSoundMgr->ZombieDeathSound();

                        mWorld->player.NumMobs -= 1;

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        mWorld->GetBlock(testPos.x, testPos.y+1, testPos.z) = 0;
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;
                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == ZombieTop::getID() && mWorld->GetBlock(testPos.x, testPos.y-1, testPos.z) == ZombieLegs::getID())
                    {
                        mSoundMgr->ZombieDeathSound();

                        mWorld->player.NumMobs -= 1;

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        mWorld->GetBlock(testPos.x, testPos.y-1, testPos.z) = 0;
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;
                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == EnderLegs::getID() && mWorld->GetBlock(testPos.x, testPos.y+1, testPos.z) == EnderTop::getID())
                    {
                        mSoundMgr->EndermanDeathSound();

                        mWorld->player.NumMobs -= 1;

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        mWorld->GetBlock(testPos.x, testPos.y+1, testPos.z) = 0;
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;
                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == EnderTop::getID() && mWorld->GetBlock(testPos.x, testPos.y-1, testPos.z) == EnderLegs::getID())
                    {
                        mSoundMgr->EndermanDeathSound();

                        mWorld->player.NumMobs -= 1;

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        mWorld->GetBlock(testPos.x, testPos.y-1, testPos.z) = 0;
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;
                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == Pumpkin::getID() && mWorld->GetBlock(testPos.x, testPos.y-1, testPos.z) == AllSnowBlock::getID())
                    {

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        mWorld->GetBlock(testPos.x, testPos.y-1, testPos.z) = 0;
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;

                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == AllSnowBlock::getID() && mWorld->GetBlock(testPos.x, testPos.y+1, testPos.z) == Pumpkin::getID())
                    {

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        mWorld->GetBlock(testPos.x, testPos.y+1, testPos.z) = 0;
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;

                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == Grass::getID())
                    {

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;

                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == Nuclear::getID())
                    {
                        mSoundMgr->TNTSound();
                        int	curchunkTarget = mWorld->getChunkId(testPos);
                        for(int x = -24; x <= 24; x++)
                        {
                            for(int y = -24; y <= 24; y++)
                            {
                                for(int z = -24; z <= 24; z++)
                                {
                                    if(mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != IronBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != WaterBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != Cloud::getID())
                                    {
                                        if(sqrt(pow(sqrt(pow(x,2)+pow(y,2)),2)+pow(z,2))<=24)
                                            mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) = 0;
                                    }
                                }
                            }
                        }
                        //Delete the actual TNT just in case
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;
                    }


                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == TNT::getID())
                    {
                        mSoundMgr->TNTSound();
                        int	curchunkTarget = mWorld->getChunkId(testPos);
                        for(int x = -4; x <= 4; x++)
                        {
                            for(int y = -4; y <= 4; y++)
                            {
                                for(int z = -4; z <= 4; z++)
                                {
                                    if(mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != IronBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != WaterBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != Cloud::getID())

                                        if(sqrt(pow(sqrt(pow(x,2)+pow(y,2)),2)+pow(z,2))<=4)
                                            mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) = 0;
                                }

                            }
                        }
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;
                    }

                    if(timeToRemove == 5 || timeToRemove == 10 || timeToRemove == 15 || timeToRemove == 20)
                    {
                        mSoundMgr->PlayWalkSound(mWorld->BlockSoundAtPos(testPos));
                    }

                    if(timeToRemove == 20)
                    {
                        timeToRemove = 0;

                        if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == LifeBlock::getID())
                        {
                            if(mWorld->player.maxhealth < 100)
                            {
                                mWorld->player.maxhealth += 10;
                                mWorld->player.health = mWorld->player.maxhealth;
                            }
                            else if(mWorld->player.maxhealth == 100)
                            {
                                mWorld->player.health = mWorld->player.maxhealth;
                            }

                            int	curchunkTarget = mWorld->getChunkId(testPos);

                            mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                            fppCam->needUpdate = true;
                            //Rebuild nearby world
                            mWorld->rebuildChunk(curchunkTarget);
                            mWorld->rebuildTransparentChunk(curchunkTarget);
                            mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                            return;

                        }

                        if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == Door2::getID())
                        {

                            int	curchunkTarget = mWorld->getChunkId(testPos);
                            for(int x = 0; x <= 0; x++)
                            {
                                for(int y = 1; y <= 1; y++)
                                {
                                    for(int z = 0; z <= 0; z++)
                                    {
                                        if(mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != IronBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != WaterBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != Cloud::getID())

                                            mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) = 0;
                                    }
                                }
                            }
                            mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                            fppCam->needUpdate = true;
                            //Rebuild nearby world
                            mWorld->rebuildChunk(curchunkTarget);
                            mWorld->rebuildTransparentChunk(curchunkTarget);
                            mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                            return;

                        }

                        if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == MelonBlock::getID())
                        {

                            mWorld->player.melons += 1 + rand()% 2;

                            int	curchunkTarget = mWorld->getChunkId(testPos);

                            mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                            fppCam->needUpdate = true;
                            //Rebuild nearby world
                            mWorld->rebuildChunk(curchunkTarget);
                            mWorld->rebuildTransparentChunk(curchunkTarget);
                            mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                            return;

                        }




                        if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == Door1::getID())
                        {

                            int	curchunkTarget = mWorld->getChunkId(testPos);
                            for(int x = 0; x <= 0; x++)
                            {
                                for(int y = -1; y <= -1; y++)
                                {
                                    for(int z = 0; z <= 0; z++)
                                    {
                                        if(mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != IronBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != WaterBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != Cloud::getID())

                                            mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) = 0;
                                    }
                                }
                            }
                            mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                            fppCam->needUpdate = true;
                            //Rebuild nearby world
                            mWorld->rebuildChunk(curchunkTarget);
                            mWorld->rebuildTransparentChunk(curchunkTarget);
                            mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                            return;

                        }

                        if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == Door3::getID())
                        {

                            int	curchunkTarget = mWorld->getChunkId(testPos);
                            for(int x = 0; x <= 0; x++)
                            {
                                for(int y = -1; y <= -1; y++)
                                {
                                    for(int z = 0; z <= 0; z++)
                                    {
                                        if(mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != IronBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != WaterBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != Cloud::getID())

                                            mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) = 0;
                                    }
                                }
                            }
                            mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                            fppCam->needUpdate = true;
                            //Rebuild nearby world
                            mWorld->rebuildChunk(curchunkTarget);
                            mWorld->rebuildTransparentChunk(curchunkTarget);
                            mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                            return;

                        }



                        if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == Door4::getID())
                        {

                            int	curchunkTarget = mWorld->getChunkId(testPos);
                            for(int x = 0; x <= 0; x++)
                            {
                                for(int y = 1; y <= 1; y++)
                                {
                                    for(int z = 0; z <= 0; z++)
                                    {
                                        if(mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != IronBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != WaterBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != Cloud::getID())

                                            mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) = 0;
                                    }
                                }
                            }
                            mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                            fppCam->needUpdate = true;
                            //Rebuild nearby world
                            mWorld->rebuildChunk(curchunkTarget);
                            mWorld->rebuildTransparentChunk(curchunkTarget);
                            mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                            return;

                        }

                        if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == IceBlock::getID())
                        {

                            mSoundMgr->GlassBreak();

                            int	curchunkTarget = mWorld->getChunkId(testPos);

                            //Delete the actual TNT just in case
                            mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = WaterBlock::getID();
                            fppCam->needUpdate = true;
                            //Rebuild nearby world
                            mWorld->rebuildChunk(curchunkTarget);
                            mWorld->rebuildTransparentChunk(curchunkTarget);
                            mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                            return;
                        }

                        if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == GlassBlock::getID())
                        {

                            mSoundMgr->GlassBreak();

                            int	curchunkTarget = mWorld->getChunkId(testPos);

                            //Delete the actual TNT just in case
                            mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                            fppCam->needUpdate = true;
                            //Rebuild nearby world
                            mWorld->rebuildChunk(curchunkTarget);
                            mWorld->rebuildTransparentChunk(curchunkTarget);
                            mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                            return;
                        }

                        if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == 9)
                        {

                            int random = rand()% 10;

                            if(random == 5)
                            {
                                mWorld->player.Apples += 1;
                            }
                        }
						
						if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == 1)
                        {

                            
                                mWorld->player.GrassNumber += 1;
                            
                        }
						
						if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == 2)
                        {

                            
                                mWorld->player.DirtNumber += 1;
                            
                        }
						
						if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == 8)
                        {

                            
                                mWorld->player.LogNumber += 1;
                            
                        }
						
						if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == 34)
                        {

                            
                                mWorld->player.PlankNumber += 1;
                            
                        }
						
						
                        


                        if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == IronBlock::getID())
                        {

                            int	curchunkTarget = mWorld->getChunkId(testPos);

                            //Delete the actual TNT just in case
                            mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = IronBlock::getID();
                            fppCam->needUpdate = true;
                            //Rebuild nearby world
                            mWorld->rebuildChunk(curchunkTarget);
                            mWorld->rebuildTransparentChunk(curchunkTarget);
                            mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                            return;
                        }

                        if(mWorld->LightSourceBlock(mWorld->GetBlock(testPos.x,testPos.y,testPos.z)))//if it's light block
                        {
                            oldBlock = mWorld->GetBlock(testPos.x,testPos.y,testPos.z);
                            wasLight = true;
                        }


                        //remove block
                        (mWorld->BlockSoundAtPos(testPos));

                        mWorld->GetBlock(testPos.x,testPos.y,testPos.z) = 0;
                    }

                    //check if this block is a support for light block
                    mWorld->CheckForTorchSupport(testPos.x,testPos.y,testPos.z,mWorld->GetBlock(testPos.x,testPos.y,testPos.z));

                    int    chunkTarget = mWorld->getChunkId(testPos);

                    //before rebuilding update light info
                    if(wasLight)
                    {
                        mWorld->RemoveLigtSourceAtPosition(testPos.x,testPos.y,testPos.z,oldBlock);
                    }

                    if(chunkTarget != -1)
                    {
                        //rebuild
                        if(wasLight)
                        {
                            mWorld->RebuildChunksLight(testPos,chunkTarget,oldBlock);
                        }
                        else
                        {
                            //check if there are light sources nearby
                            mWorld->UpdateLightAreaIn(testPos);

                            //rebuild chunks
                            mWorld->rebuildChunk(chunkTarget);
                            mWorld->rebuildTransparentChunk(chunkTarget);
                            mWorld->rebuildNearestChunks(chunkTarget,testPos);
                        }
                    }

                    fppCam->needUpdate = true;
                    break;
                }
            }
        }
        else
        {
            timeToRemove = 0;
        }

        //remove cube
        if(keyPressed(InputHelper::Instance()->getButtonToAction(13)) && mWorld->player.gamemode == 1)
        {
            cubeMove = true;

            bool wasLight = false;
            block_t oldBlock = 0;
            //remove cube
            Vector3 rayDir = fppCam->m_vView - fppCam->m_vPosition;
            rayDir.normalize();

            //we are takin our positiona and view vector
            Vector3 testPos;


            //we are moving slowly to the target +=0.5
            for(float i = 0; i < 5.25f; i+=0.25f)
            {
                testPos = fppCam->m_vPosition + (rayDir * i);

                //check if we touch something
                if(mWorld->BlockEditable(testPos.x,testPos.y,testPos.z))
                {

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == ZombieLegs::getID() && mWorld->GetBlock(testPos.x, testPos.y+1, testPos.z) == ZombieTop::getID())
                    {
                        mSoundMgr->ZombieDeathSound();

                        mWorld->player.NumMobs -= 1;

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        mWorld->GetBlock(testPos.x, testPos.y+1, testPos.z) = 0;
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;
                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == ZombieTop::getID() && mWorld->GetBlock(testPos.x, testPos.y-1, testPos.z) == ZombieLegs::getID())
                    {
                        mSoundMgr->ZombieDeathSound();

                        mWorld->player.NumMobs -= 1;

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        mWorld->GetBlock(testPos.x, testPos.y-1, testPos.z) = 0;
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;
                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == EnderLegs::getID() && mWorld->GetBlock(testPos.x, testPos.y+1, testPos.z) == EnderTop::getID())
                    {
                        mSoundMgr->EndermanDeathSound();

                        mWorld->player.NumMobs -= 1;

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        mWorld->GetBlock(testPos.x, testPos.y+1, testPos.z) = 0;
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;
                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == EnderTop::getID() && mWorld->GetBlock(testPos.x, testPos.y-1, testPos.z) == EnderLegs::getID())
                    {
                        mSoundMgr->EndermanDeathSound();

                        mWorld->player.NumMobs -= 1;

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        mWorld->GetBlock(testPos.x, testPos.y-1, testPos.z) = 0;
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;
                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == Pumpkin::getID() && mWorld->GetBlock(testPos.x, testPos.y-1, testPos.z) == AllSnowBlock::getID())
                    {

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        mWorld->GetBlock(testPos.x, testPos.y-1, testPos.z) = 0;
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;

                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == AllSnowBlock::getID() && mWorld->GetBlock(testPos.x, testPos.y+1, testPos.z) == Pumpkin::getID())
                    {

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        mWorld->GetBlock(testPos.x, testPos.y+1, testPos.z) = 0;
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;

                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == Grass::getID())
                    {

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;

                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == Nuclear::getID())
                    {
                        mSoundMgr->TNTSound();
                        int	curchunkTarget = mWorld->getChunkId(testPos);
                        for(int x = -24; x <= 24; x++)
                        {
                            for(int y = -24; y <= 24; y++)
                            {
                                for(int z = -24; z <= 24; z++)
                                {
                                    if(mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != IronBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != WaterBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != Cloud::getID())
                                    {
                                        if(sqrt(pow(sqrt(pow(x,2)+pow(y,2)),2)+pow(z,2))<=24)
                                            mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) = 0;
                                    }
                                }
                            }
                        }
                        //Delete the actual TNT just in case
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;
                    }


                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == TNT::getID())
                    {
                        mSoundMgr->TNTSound();
                        int	curchunkTarget = mWorld->getChunkId(testPos);
                        for(int x = -4; x <= 4; x++)
                        {
                            for(int y = -4; y <= 4; y++)
                            {
                                for(int z = -4; z <= 4; z++)
                                {
                                    if(mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != IronBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != WaterBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != Cloud::getID())
                                    {
                                        if(sqrt(pow(sqrt(pow(x,2)+pow(y,2)),2)+pow(z,2))<=24)
                                            mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) = 0;
                                    }
                                }
                            }
                        }
                        //Delete the actual TNT just in case
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;
                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == LifeBlock::getID())
                    {
                        if(mWorld->player.maxhealth <= 90)
                        {
                            mWorld->player.maxhealth += 10;
                            mWorld->player.health = mWorld->player.maxhealth;
                        }

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;

                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == Door2::getID())
                    {

                        int	curchunkTarget = mWorld->getChunkId(testPos);
                        for(int x = 0; x <= 0; x++)
                        {
                            for(int y = 1; y <= 1; y++)
                            {
                                for(int z = 0; z <= 0; z++)
                                {
                                    if(mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != IronBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != WaterBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != Cloud::getID())

                                        mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) = 0;
                                }
                            }
                        }
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;

                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == MelonBlock::getID())
                    {

                        mWorld->player.melons += 1 + rand()% 2;

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;

                    }




                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == Door1::getID())
                    {

                        int	curchunkTarget = mWorld->getChunkId(testPos);
                        for(int x = 0; x <= 0; x++)
                        {
                            for(int y = -1; y <= -1; y++)
                            {
                                for(int z = 0; z <= 0; z++)
                                {
                                    if(mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != IronBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != WaterBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != Cloud::getID())

                                        mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) = 0;
                                }
                            }
                        }
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;

                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == Door3::getID())
                    {

                        int	curchunkTarget = mWorld->getChunkId(testPos);
                        for(int x = 0; x <= 0; x++)
                        {
                            for(int y = -1; y <= -1; y++)
                            {
                                for(int z = 0; z <= 0; z++)
                                {
                                    if(mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != IronBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != WaterBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != Cloud::getID())

                                        mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) = 0;
                                }
                            }
                        }
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;

                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == Door4::getID())
                    {

                        int	curchunkTarget = mWorld->getChunkId(testPos);
                        for(int x = 0; x <= 0; x++)
                        {
                            for(int y = 1; y <= 1; y++)
                            {
                                for(int z = 0; z <= 0; z++)
                                {
                                    if(mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != IronBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != WaterBlock::getID() || mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) != Cloud::getID())

                                        mWorld->GetBlock(x+testPos.x,y+testPos.y,z+testPos.z) = 0;
                                }
                            }
                        }
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;

                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == IceBlock::getID())
                    {

                        mSoundMgr->GlassBreak();

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        //Delete the actual TNT just in case
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = WaterBlock::getID();
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;
                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == GlassBlock::getID())
                    {

                        mSoundMgr->GlassBreak();

                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        //Delete the actual TNT just in case
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = 0;
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;
                    }

                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == 9)
                    {

                        int random = rand()% 10;

                        if(random == 5)
                        {
                            mWorld->player.Apples += 1;
                        }
                    }
					
					if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == 1)
                    {

                     

                        
                            mWorld->player.GrassNumber += 1;
                        
                    }
                    
					
					if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == 2)
                        {

                            
                                mWorld->player.DirtNumber += 1;
                            
                        }
						
						if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == 8)
                        {

                            
                                mWorld->player.LogNumber += 1;
                            
                        }
						
						if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == 34)
                        {

                            
                                mWorld->player.PlankNumber += 1;
                            
                        }
						
						
					
                    if (mWorld->GetBlock(testPos.x, testPos.y, testPos.z) == IronBlock::getID())
                    {
                        int	curchunkTarget = mWorld->getChunkId(testPos);

                        //Delete the actual TNT just in case
                        mWorld->GetBlock(testPos.x, testPos.y, testPos.z) = IronBlock::getID();
                        fppCam->needUpdate = true;
                        //Rebuild nearby world
                        mWorld->rebuildChunk(curchunkTarget);
                        mWorld->rebuildTransparentChunk(curchunkTarget);
                        mWorld->rebuildNearestChunks(curchunkTarget,testPos);
                        return;
                    }

                    if(mWorld->LightSourceBlock(mWorld->GetBlock(testPos.x,testPos.y,testPos.z)))//if it's light block
                    {
                        oldBlock = mWorld->GetBlock(testPos.x,testPos.y,testPos.z);
                        wasLight = true;
                    }


                    //remove block
                    mSoundMgr->PlayWalkSound(mWorld->BlockSoundAtPos(testPos));

                    mWorld->GetBlock(testPos.x,testPos.y,testPos.z) = 0;

                    //check if this block is a support for light block
                    mWorld->CheckForTorchSupport(testPos.x,testPos.y,testPos.z,mWorld->GetBlock(testPos.x,testPos.y,testPos.z));

                    int    chunkTarget = mWorld->getChunkId(testPos);

                    //before rebuilding update light info
                    if(wasLight)
                    {
                        mWorld->RemoveLigtSourceAtPosition(testPos.x,testPos.y,testPos.z,oldBlock);
                    }

                    if(chunkTarget != -1)
                    {
                        //rebuild
                        if(wasLight)
                        {
                            mWorld->RebuildChunksLight(testPos,chunkTarget,oldBlock);
                        }
                        else
                        {
                            //check if there are light sources nearby
                            mWorld->UpdateLightAreaIn(testPos);

                            //rebuild chunks
                            mWorld->rebuildChunk(chunkTarget);
                            mWorld->rebuildTransparentChunk(chunkTarget);
                            mWorld->rebuildNearestChunks(chunkTarget,testPos);
                        }
                    }

                    fppCam->needUpdate = true;
                    break;
                }
            }
        }


        //jump
        if (mWorld->PlayerOnHalfBlock(legsPosition) && !mWorld->PlayerOnHalfBlock(headPosition))
        {
            if(keyPressed(InputHelper::Instance()->getButtonToAction(12)))
                jumping = true;
        }
        if(keyHold(InputHelper::Instance()->getButtonToAction(12)))
        {
            if (headInWater || headInLava)	//Legit swimming
            {
                if (walkingOnGround)
                    jumping = true;
                else
                {
                    playerVelocity.y = 0.4 * JUMPVELOCITY;
                    walkingOnGround = false;
                }
            }
            if ((!headInWater || !headInLava) && !walkingOnGround && (footInWater || footInLava))	//Your above he water, so Jump out
            {
                playerVelocity.y = 0.9 * JUMPVELOCITY;
                walkingOnGround = false;
            }
            if(walkingOnGround || mWorld->PlayerOnHalfBlock(legsPosition))	//Just in case...
            {
                jumping = true;
            }
            else
                jumping = false;	//Don't bounce
        }
    }
    else if(menuState == 1) //menu state
    {
        //turn off menu with the same key
        if(keyPressed(InputHelper::Instance()->getButtonToAction(15)))
        {
            menuState = 0;
            menuOptions = false;
            optionsMenuPos = 0;
            selectPos = 0;
        }

        //menu keys
        if(menuOptions)
        {
            //up, down
            if(mSystemMgr->KeyPressed(PSP_CTRL_UP))
            {
                if(mWorld->player.gamemode == 0 || mWorld->player.gamemode == 2)
                {
                    optionsMenuPos--;
                    if(optionsMenuPos < 0)
                        optionsMenuPos = 5;
                }
                else
                {
                    optionsMenuPos--;
                    if(optionsMenuPos < 0)
                        optionsMenuPos = 9;
                }

                mSoundMgr->PlayMenuSound();
            }

            if(mSystemMgr->KeyPressed(PSP_CTRL_DOWN))
            {
                if(mWorld->player.gamemode == 0)
                {
                    optionsMenuPos++;
                    if(optionsMenuPos > 5)
                        optionsMenuPos = 0;
                }
                else
                {
                    optionsMenuPos++;
                    if(optionsMenuPos > 9)
                        optionsMenuPos = 0;
                }
                mSoundMgr->PlayMenuSound();
            }

            //back
            if(mSystemMgr->KeyPressed(PSP_CTRL_CIRCLE))
            {
                selectPos = 0;
                menuOptions = false;
            }

            if(mSystemMgr->KeyPressed(PSP_CTRL_CROSS))
            {
                if(mWorld->player.gamemode == 0 || mWorld->player.gamemode == 2)
                {
                    //take screenshot
                    if(optionsMenuPos == 0)
                        makeScreen = true;

                    //rename
                    if(optionsMenuPos == 1)
                    {
                        unsigned short test[128];
                        unsigned short opis[10] = {'W','o','r','l','d',' ','n','a','m','e'};
                        if(mSystemMgr->ShowOSK(opis,test,128) != -1)
                        {
                            std::string newWorldName = "";
                            for(int j = 0; test[j]; j++)
                            {
                                unsigned c = test[j];

                                if(32 <= c && c <= 127) // print ascii only
                                    newWorldName += c;
                            }

                            sprintf(mWorld->worldName,"%s",newWorldName.c_str());
                        }
                    }

                    if(optionsMenuPos == 2)
                        mSoundMgr->playerSounds = !mSoundMgr->playerSounds;

                    if(optionsMenuPos == 3)
                    {
                        canHeadBob = !canHeadBob;

                        bobCycle = 0.0f;
                    }

                    //back to ingame menu
                    if(optionsMenuPos == 4)
                    {
                        mSoundMgr->ambientSoundsEnabled = !mSoundMgr->ambientSoundsEnabled;

                        int curtime = (int)time(NULL);
                        int interval = mSoundMgr->PlayRandomAmbient();
                        nextMusic = curtime + interval;
                    }
                    if(optionsMenuPos == 5)
                    {
                        CanSpawnMobs = !CanSpawnMobs;
                    }
                }
                else
                {
                    //fly
                    if(optionsMenuPos == 0)
                        canFly = !canFly;

                    //devmode
                    if(optionsMenuPos == 1)
                        devMode = !devMode;

                    //take screenshot
                    if(optionsMenuPos == 2)
                        makeScreen = true;

                    //rename
                    if(optionsMenuPos == 3)
                    {
                        unsigned short test[128];
                        unsigned short opis[10] = {'W','o','r','l','d',' ','n','a','m','e'};
                        if(mSystemMgr->ShowOSK(opis,test,128) != -1)
                        {
                            std::string newWorldName = "";
                            for(int j = 0; test[j]; j++)
                            {
                                unsigned c = test[j];

                                if(32 <= c && c <= 127) // print ascii only
                                    newWorldName += c;
                            }

                            sprintf(mWorld->worldName,"%s",newWorldName.c_str());
                        }
                    }

                    if(optionsMenuPos == 4)
                        mSoundMgr->playerSounds = !mSoundMgr->playerSounds;

                    if(optionsMenuPos == 5)
                    {
                        canHeadBob = !canHeadBob;

                        bobCycle = 0.0f;
                    }


                    if(optionsMenuPos == 6)
                        mWorld->freezeDayTime = !mWorld->freezeDayTime;

                    //back to ingame menu
                    if(optionsMenuPos == 7)
                    {
                        mSoundMgr->ambientSoundsEnabled = !mSoundMgr->ambientSoundsEnabled;

                        int curtime = (int)time(NULL);
                        int interval = mSoundMgr->PlayRandomAmbient();
                        nextMusic = curtime + interval;
                    }
                    if(optionsMenuPos == 8)
                    {
                        CanSpawnMobs = !CanSpawnMobs;
                    }
                    if(optionsMenuPos == 9)
                    {
                        CanBigCubes = !CanBigCubes;
                    }
                }
            }
        }
        else
        {
            //up, down
            if(mSystemMgr->KeyPressed(PSP_CTRL_UP))
            {
                selectPos--;
                if(selectPos < 0)
                    selectPos = 4;

                mSoundMgr->PlayMenuSound();
            }

            if(mSystemMgr->KeyPressed(PSP_CTRL_DOWN))
            {
                selectPos++;
                if(selectPos > 4)
                    selectPos = 0;

                mSoundMgr->PlayMenuSound();
            }

            if(mSystemMgr->KeyPressed(PSP_CTRL_CIRCLE))
            {
                menuState = 0;
                selectPos = 0;
                optionsMenuPos = 0;
                menuOptions = false;
            }

            if(mSystemMgr->KeyPressed(PSP_CTRL_CROSS))
            {
                if(selectPos == 0)//resume
                {
                    menuState = 0;
                }
                if(selectPos == 1)//options
                {
                    optionsMenuPos = 0;
                    menuOptions = true;
                }
                if(selectPos == 2)//save
                {
                    mWorld->sunTime = sunTime;
                    mWorld->SaveCompressedWorld(saveFileName.c_str());
                    menuState = 0;
                }
                if(selectPos == 3)//save end exit
                {
                    //save
                    mWorld->sunTime = sunTime;
                    mWorld->SaveCompressedWorld(saveFileName.c_str());
                    //exit
                    sManager->PopState();
                }
                if(selectPos == 4)//exit
                {
                    //exit
                    sManager->PopState();
                }
            }
        }
    }
    else if(menuState == 2)
    {
        //up, down
        if(mSystemMgr->KeyPressed(PSP_CTRL_UP))
        {
            selectPos--;
            if(selectPos < 0)
                selectPos = 2;

            mSoundMgr->PlayMenuSound();
        }

        if(mSystemMgr->KeyPressed(PSP_CTRL_DOWN))
        {
            selectPos++;
            if(selectPos > 2)
                selectPos = 0;

            mSoundMgr->PlayMenuSound();
        }
		

        if(mSystemMgr->KeyPressed(PSP_CTRL_CIRCLE))
        {
            menuState = 0;
            selectPos = 0;
            optionsMenuPos = 0;
            menuOptions = false;
        }

        if(mSystemMgr->KeyPressed(PSP_CTRL_CROSS))
        {
            if(selectPos == 0)//apple
            {
                if(mWorld->player.Apples >= 1)
                {
                    mSoundMgr->EatSound();

                    if (mWorld->player.hunger == 100)
                    {
                        mWorld->player.health += 20;
                        mWorld->player.Apples -= 1;

                        if(mWorld->player.health > mWorld->player.maxhealth)
                        {
                            mWorld->player.health = mWorld->player.maxhealth;
                        }
                    }
                    else if(mWorld->player.hunger < 100)
                    {
                        hungerTime = 0;
                        mWorld->player.hunger += 20;
                        mWorld->player.Apples -= 1;
                    }
                    else if(mWorld->player.hunger > 100)
                    {
                        mWorld->player.hunger  = 100;
                    }
                }
                else
                {
                    return;
                }
            }
            if(selectPos == 1)//melon
            {
                if(mWorld->player.melons >= 1)
                {
                    mSoundMgr->EatSound();

                    if (mWorld->player.hunger == 100)
                    {
                        mWorld->player.health += 10;
                        mWorld->player.melons -= 1;

                        if(mWorld->player.health > mWorld->player.maxhealth)
                        {
                            mWorld->player.health = mWorld->player.maxhealth;
                        }
                    }
                    else if(mWorld->player.hunger < 100)
                    {
                        hungerTime = 0;
                        mWorld->player.hunger += 10;
                        mWorld->player.melons -= 1;
                    }
                    else if(mWorld->player.hunger > 100)
                    {
                        mWorld->player.hunger  = 100;
                    }
                }
                else
                {
                    return;
                }
            }
			if(selectPos == 2)//First crafting :)
            {
                if(mWorld->player.LogNumber >= 1)
                {
                   
                        
						if(mWorld->player.LogNumber -= 1);
						{
						mWorld->player.PlankNumber += 4;
						}

          
                }
                else
                {
                    return;
                }
            }
        }
    }
    else if(menuState == 3)
    {
        if(mSystemMgr->KeyPressed(PSP_CTRL_UP))
        {
            selectPos--;
            if(selectPos < 0)
                selectPos = 2;

            mSoundMgr->PlayMenuSound();
        }

        if(mSystemMgr->KeyPressed(PSP_CTRL_DOWN))
        {
            selectPos++;
            if(selectPos > 2)
                selectPos = 0;

            mSoundMgr->PlayMenuSound();
        }

        if(mSystemMgr->KeyPressed(PSP_CTRL_CROSS))
        {
            if(selectPos == 0)//survival
            {
                mWorld->player.gamemode = 0;
                menuState = 0;
            }
            if(selectPos == 1)//creative
            {
                mWorld->player.gamemode = 1;
                menuState = 0;
                mWorld->player.score += 10000;
            }
            if(selectPos == 2)//hardcore
            {
                mWorld->player.gamemode = 2;
                menuState = 0;
                mWorld->player.health -= 70;
                mWorld->player.maxhealth -= 70;
            }
        }
    }
    else if(menuState == 4)
    {
        if(mSystemMgr->KeyPressed(PSP_CTRL_UP))
        {
            selectPos--;
            if(selectPos < 0)
                selectPos = 2;

            mSoundMgr->PlayMenuSound();
        }

        if(mSystemMgr->KeyPressed(PSP_CTRL_DOWN))
        {
            selectPos++;
            if(selectPos > 2)
                selectPos = 0;

            mSoundMgr->PlayMenuSound();
        }

        if(mSystemMgr->KeyPressed(PSP_CTRL_CIRCLE))
        {
            menuState = 0;
            selectPos = 0;
            optionsMenuPos = 0;
            menuOptions = false;
        }

        if(mSystemMgr->KeyPressed(PSP_CTRL_CROSS))
        {
            if(selectPos == 0)//jump
            {
                if(mWorld->player.jumpHeight == 0 || mWorld->player.jumpHeight == 1)
                {
                    if(mWorld->player.score >= 60)
                    {
                        mWorld->player.jumpHeight += 1;
                        mWorld->player.score -= 60;
                    }
                }
                else if(mWorld->player.jumpHeight == 2 || mWorld->player.jumpHeight == 3)
                {
                    if(mWorld->player.score >= 90)
                    {
                        mWorld->player.jumpHeight += 1;
                        mWorld->player.score -= 90;
                    }
                }
                else if(mWorld->player.jumpHeight == 4)
                {
                    return;
                }
            }

            if(selectPos == 1)//walk
            {
                if(mWorld->player.walkSpeed == 0 || mWorld->player.walkSpeed == 1)
                {
                    if(mWorld->player.score >= 60)
                    {
                        mWorld->player.walkSpeed += 1;
                        mWorld->player.score -= 60;
                    }
                }
                else if(mWorld->player.walkSpeed == 2 || mWorld->player.walkSpeed == 3)
                {
                    if(mWorld->player.score >= 90)
                    {
                        mWorld->player.walkSpeed += 1;
                        mWorld->player.score -= 90;
                    }
                }
                else if(mWorld->player.walkSpeed == 4)
                {
                    return;
                }
            }

            if(selectPos == 2)//fire resisnatce
            {
                if(mWorld->player.fireResistance == 0 || mWorld->player.fireResistance == 1)
                {
                    if(mWorld->player.score >= 60)
                    {
                        mWorld->player.fireResistance += 1;
                        mWorld->player.score -= 60;
                    }
                }
                else if(mWorld->player.fireResistance == 2 || mWorld->player.fireResistance == 3)
                {
                    if(mWorld->player.score >= 90)
                    {
                        mWorld->player.fireResistance += 1;
                        mWorld->player.score -= 90;
                    }
                }
                else if(mWorld->player.fireResistance == 4)
                {
                    return;
                }
            }
        }
    }
}


float update_timer;
//Deal with underwater breathing
void StatePlay::UnderwaterBreathing()
{
    if(mWorld->player.gamemode == 0 || mWorld->player.gamemode == 2)
    {
        Vector3 headPosition = playerPosition + Vector3(0, 0.1, 0);

        if (mWorld->player.air_time == 0)	//If you're out of air, start inflicting damage
        {
            TakeDamage(10);

            heathChange = true;
        }

        if (mWorld->player.air_time > 0)	//Reduce air time underwater
            mWorld->player.air_time -= 10;
        if (mWorld->player.air_time <= 0)	//Set it to zero
            mWorld->player.air_time = 0;

        hurt_time = 0;
    }
}

void StatePlay::Update(StateManager* sManager)
{
    Vector3 delta = fppCam->m_vView - fppCam->m_vPosition;
    playerPosition = fppCam->m_vPosition;

    //gravity
    Vector3 footPosition = playerPosition + Vector3(0.0f, -1.5f, 0.0f);
    Vector3 legsPosition = playerPosition + Vector3(0.0f, -1.0f, 0.0f);
    Vector3 headPosition = playerPosition + Vector3(0.0f, 0.1f, 0.0f);

    int curtime = (int)time(NULL);

    if(curtime>nextMusic)
    {
        int interval = mSoundMgr->PlayRandomAmbient();
        nextMusic = curtime + interval;
    }

    if(menuState == 0)//game state
    {
        if(fppCam->needUpdate)
        {
            showCube = false;

            //show pick cube
            Vector3 rayDir = fppCam->m_vView - fppCam->m_vPosition;
            rayDir.normalize();

            //we take position and view vector
            Vector3 testPos ;

            //moving slowly to the target
            for(float i = 0; i < 5.25f; i+=0.25f)
            {
                testPos = fppCam->m_vPosition + (rayDir * i);

                //check if we touching something
                if(mWorld->BlockEditable(testPos.x,testPos.y,testPos.z))
                {
                    //if yes then show pick cube
                    cubePos.x = (int)testPos.x + 0.5f;
                    cubePos.y = (int)testPos.y + 0.5f;
                    cubePos.z = (int)testPos.z + 0.5f;

                    showCube = true;
                    break;
                }
            }

        }

        int soundBlockType = -1;

        //update player position
        if(dt < 0.1f)
        {
            if(heathChange == true)
            {
                changeTimer++;

                if(changeTimer == 3)
                {
                    changeTimer = 0;
                    heathChange = false;
                }
            }

            if(mWorld->player.gamemode == 0 || mWorld->player.gamemode == 2)
            {
                //You are touching the cactus, take damage
                if (mWorld->PlayerTouchCactus(playerPosition) == true						//Your Touching a cactus
                        && mWorld->player.safe_spawn == false)									//Your safe spawn has worn off
                {
                    if (hurt_time > 1.0)
                    {
                        if (mWorld->player.health > 0)
                        {
                            TakeDamage(10);

                            heathChange = true;

                            /* If the player is about to go into a wall, push him out
                            if (mWorld->SolidAtPointForPlayer(legsPosition) || mWorld->SolidAtPointForPlayer(headPosition))
                                playerPosition.x -= 0.3;
                            else
                                playerPosition.x += 0.1;*/

                            hurt_time = 0;
                        }
                    }
                    hurt_time += dt;
                }

                if (mWorld->player.hunger == 0)
                {
                    if (hurt_time > 2.0)
                    {
                        if (mWorld->player.health > 0)
                        {
                            TakeDamage(10);

                            heathChange = true;

                            hurt_time = 0;
                        }
                    }
                    hurt_time += dt;
                }
                if(mWorld->player.hunger < 0)
                {
                    mWorld->player.hunger = 0;
                }
            }

            //foot in water
            if(mWorld->PlayerInWater(footPosition))
            {
                footInWater = true;
            }
            else
            {
                footInWater = false;
            }

            //foot in Lava
            if(mWorld->PlayerInLava(footPosition))
            {
                footInLava = true;
            }
            else
            {
                footInLava = false;
            }

            if(mWorld->PlayerInWater(headPosition))
            {
                if(mWorld->player.gamemode == 0 || mWorld->player.gamemode == 2)
                {
                    if ((hurt_time > 1.5 || hurt_time == 0) && mWorld->player.health > 0)
                    {
                        UnderwaterBreathing();
                    }
                    hurt_time += dt;
                }

                //---
                //change gravity
                //---
                playerVelocity.y += (GRAVITY/3.0f) * dt;
                headInWater = true;
            }
            else
            {
                if(mWorld->player.gamemode == 0 || mWorld->player.gamemode == 2)
                {
                    mWorld->player.air_time += 1;	//Give the player back air

                    if (mWorld->player.air_time > 100)
                        mWorld->player.air_time = 100;
                }

                headInWater = false;
                playerVelocity.y += GRAVITY * dt;
            }

            //---
            //check if head is is in the Lava
            //---
            if(mWorld->PlayerInLava(headPosition))
            {
                //---
                //change gravity
                //---
                playerVelocity.y += (GRAVITY/3.0f) * dt;
                headInLava = true;
            }
            else
            {
                headInLava = false;
            }

            if(mWorld->PlayerInWeb(headPosition) || mWorld->PlayerInWeb(legsPosition))
            {
                playerVelocity.y += (GRAVITY/7.0f) * dt;
            }


            //---
            //check if Legs are in the water or lava
            //---
            if(mWorld->PlayerInWater(legsPosition))
            {
                if (!mWorld->player.entered_water)	//Play the splash sound
				{
					mSoundMgr->SplashSound();
					mWorld->player.entered_water = true;
				}
                legsInWater = true;
            }
            else
            {
                mWorld->player.entered_water = false;
                legsInWater = false;
            }

            if (mWorld->PlayerInLava(legsPosition))
                legsInLava = true;
            else
                legsInLava = false;


            //---
            //check if we are standing on ground
            //---
            if(mWorld->SolidAtPointForPlayer(footPosition) || mWorld->SolidAtPointForPlayer(headPosition) || mWorld->PlayerOnHalfBlock(legsPosition))
            {
                walkingOnGround = true;

                //Safe spawning
                if (mWorld->player.safe_spawn == true)
                {
                    if (mWorld->player.objective_time[SAFE_SPAWN_TIME] > 1)	//You have had enough time to be safe, so reset
                    {
                        mWorld->player.safe_spawn = false;
                        mWorld->player.objective_time[SAFE_SPAWN_TIME] = 0;
                    }
                    mWorld->player.objective_time[SAFE_SPAWN_TIME] += dt;
                }

                soundBlockType = mWorld->BlockSoundAtPos(footPosition);

                // If the player has their head stuck in a block, push them down.
                if (mWorld->SolidAtPointForPlayer(headPosition))
                {
                    int blockIn = (int)(headPosition.y);
                    playerPosition.y = (float)(blockIn - 0.15f);
                }

                // If the player is stuck in the ground, bring them out.
                // This happens because we're standing on a block at -1.5, but stuck in it at -1.4, so -1.45 is the sweet spot.
                if (mWorld->SolidAtPointForPlayer(footPosition))
                {
                    int blockOn = (int)(footPosition.y);
                    playerPosition.y = (float)(blockOn + 1 + 1.45f);
                }

                //---
                //take damage from falling a distance. Don't take damage if you fall in the water
                //---

                if (walkingOnGround && playerVelocity.y <= -9 &&		//If your falling fast, take damage
                        (!mWorld->PlayerInWater(headPosition) || !mWorld->PlayerInLava(headPosition)) &&				//If you fall in the water, don't take damage
                        mWorld->player.safe_spawn == false && (mWorld->player.gamemode == 0 || mWorld->player.gamemode == 2))				//Make sure you didn't just spawn
                {
                    TakeDamage(rint(pow(playerVelocity.y,2)/4));

                    heathChange = true;
                }

                playerVelocity.y = 0.0f;

                //additional logic while standing on the block
            }
            else
            {
                walkingOnGround = false;
            }

            if(jumping)
            {
                if(mWorld->player.jumpHeight == 0)
                {
                    playerVelocity.y = 1.2f * JUMPVELOCITY;
                }
                else if(mWorld->player.jumpHeight == 1)
                {
                    playerVelocity.y = 1.5f * JUMPVELOCITY;
                }
                else if(mWorld->player.jumpHeight == 2)
                {
                    playerVelocity.y = 1.8f * JUMPVELOCITY;
                }
                else if(mWorld->player.jumpHeight == 3)
                {
                    playerVelocity.y = 2.1f * JUMPVELOCITY;
                }
                else if(mWorld->player.jumpHeight == 4)
                {
                    playerVelocity.y = 2.4f * JUMPVELOCITY;
                }
                jumping = false;
                walkingOnGround = false;
            }




            if (mWorld->PlayerOnHalfBlock(legsPosition) && !mWorld->PlayerOnHalfBlock(headPosition))
            {
                int blockOn = (int)(legsPosition.y);
                playerPosition.y = (float)(blockOn + 0.5 + 1.45f);
                playerVelocity.y = 0.0f;
                walkingOnGround = true;
            }

            if (mWorld->PlayerOnHalfBlock(headPosition))
            {
                int blockIn = (int)(headPosition.y);
                playerPosition.y = (float)(blockIn - 0.15f);
            }

            if(mWorld->PlayerOnHalfBlock(legsPosition))
            {
                walkingOnGround = true;
            }

            if(mWorld->PlayerOnLilyPad(legsPosition) && mWorld->PlayerInWater(footPosition))
            {
                playerVelocity.y = 0.0f;
                walkingOnGround = true;
            }

            //---
            //update position
            //---
            if(!canFly)
                playerPosition += playerVelocity * dt;
            else
            {
                mWorld->player.safe_spawn = false;
                playerVelocity.y = 0.0f;
            }

            //Now collisions with œciankami
            isWalking = false;
            Vector3 moveVector = fppCam->m_vVelocity;

            if(moveVector.x != 0.0f || moveVector.z != 0.0f)
            {
                if(TryToMove(moveVector,dt))
                {
                    isWalking = true;
                }
                else if(TryToMove(Vector3(0,0,moveVector.z),dt))
                {
                    isWalking = true;
                }
                else if(TryToMove(Vector3(moveVector.x,0,0),dt))
                {
                    isWalking = true;
                }
            }

            if(mWorld->player.gamemode == 0 || mWorld->player.gamemode == 2)
            {
                if (mWorld->PlayerInLava(footPosition) || mWorld->PlayerInLava(headPosition) || mWorld->PlayerInLava(legsPosition))
                {
                    if (lava_time > 0.6)
                    {
                        if (mWorld->player.health > 0)
                        {
                            if(mWorld->player.fireResistance == 0)
                                TakeDamage(15);
                            else if(mWorld->player.fireResistance == 1)
                                TakeDamage(10);
                            else if(mWorld->player.fireResistance == 2)
                                TakeDamage(5);
                            else
                                TakeDamage(0);

                            heathChange = true;
                        }
                        lava_time = 0;
                    }
                }
                lava_time += dt;

                if(mWorld->PlayerTouchZombieBody(headPosition) || mWorld->PlayerTouchZombieBody(legsPosition) || mWorld->PlayerTouchZombieBody(footPosition) ||
                        mWorld->PlayerTouchZombieLegs(headPosition) || mWorld->PlayerTouchZombieLegs(legsPosition) || mWorld->PlayerTouchZombieLegs(footPosition))
                {
                    if (hurt_time > 0.5)
                    {
                        if (mWorld->player.health > 0)
                        {
                            TakeDamage(20);

                            heathChange = true;

                            hurt_time = 0;
                        }
                    }
                    hurt_time += dt;
                }

                if(mWorld->PlayerTouchEndermanBody(headPosition) || mWorld->PlayerTouchEndermanBody(legsPosition) || mWorld->PlayerTouchEndermanBody(footPosition) ||
                        mWorld->PlayerTouchEndermanLegs(headPosition) || mWorld->PlayerTouchEndermanLegs(legsPosition) || mWorld->PlayerTouchEndermanLegs(footPosition))
                {
                    if (hurt_time > 0.5)
                    {
                        if (mWorld->player.health > 0)
                        {
                            TakeDamage(30);

                            heathChange = true;

                            hurt_time = 0;
                        }
                    }
                    hurt_time += dt;
                }
            }

            //---
            //update camera
            //---
            fppCam->m_vPosition = playerPosition;
            fppCam->m_vView = fppCam->m_vPosition + delta;

            fppCam->m_vVelocity = Vector3(0,0,0);

            fppCam->needUpdate = true;

        }

        if(cubeMove == true)
        {
            if(canHeadBob)
            {
                cubeCycle += dt*3;
                if(cubeCycle>1.0f)
                {
                    cubeMove = false;
                    cubeCycle=0.0f;
                }
            }
        }

        if(fppCam->needUpdate)
        {
            mWorld->UpdatePlayerZoneBB(fppCam->m_vPosition);
        }

        if(isWalking && walkingOnGround && (!footInWater || !footInLava))
        {
            if(walkSoundAccu > 0.5f || walkSoundAccu == 0.0f)
            {
                mSoundMgr->PlayWalkSound(soundBlockType);
                walkSoundAccu = 0.0f;
            }
            walkSoundAccu += dt;

            if(canHeadBob)
            {
                bobCycle += dt*2;
                if(bobCycle>1.0f)
                {
                    bobCycle=0.0f;
                }
                float bobSine = sinf(bobCycle*180.0f*DEG_TO_RAD);

                fppCam->m_vOffset = Vector3(0.0f,0.05f*bobSine,0.0f);
            }

        }
        else
        {
            walkSoundAccu = 0.0f;
            fppCam->m_vOffset = Vector3(0.0f,0.0f,0.0f);
            if(bobCycle > 0)
            {
                bobCycle -= dt*2;
            }

            if(bobCycle < 0)
                bobCycle = 0;

        }

        if(headInWater)
        {
            if(waterSoundAccu > 1.177f || waterSoundAccu == 0.0f)
            {
                mSoundMgr->PlayWaterSound();
                waterSoundAccu = 0.0f;
            }
            waterSoundAccu += dt;
        }
        else
        {
            mSoundMgr->StopWaterSound();
            waterSoundAccu = 0.0f;
        }
    }
    if(neededScore >= 30)
    {
        mWorld->player.score += 1;
        neededScore = 0;
    }

    if(hungerTime == 10)
    {
        mWorld->player.hunger -= 5;
        hungerTime = 0;
    }

    if(curtime>ticker) //runs every second
    {
        if(mWorld->player.hunger >= 100 && mWorld->player.health < mWorld->player.maxhealth && mWorld->player.health > 0 && (mWorld->player.gamemode == 0 || mWorld->player.gamemode == 2))
        {
            mWorld->player.health += 5;

            heathChange = true;
        }

        if(mWorld->player.health > mWorld->player.maxhealth)
        {
            mWorld->player.health = mWorld->player.maxhealth;
        }

        neededScore += 1;

        if(isWalking || headInWater || footInWater)
        {
            if(mWorld->player.gamemode == 0 || mWorld->player.gamemode == 2)
                hungerTime += 1;
        }

        int chunkId = mWorld->getChunkId(fppCam->m_vPosition);
        mWorld->UpdateChunkBlocks(chunkId);
        mWorld->rebuildChunk(chunkId);
        mWorld->rebuildTransparentChunk(chunkId);
        mWorld->rebuildNearestChunks(chunkId,fppCam->m_vPosition);

        if(CanSpawnMobs)
        {
            mWorld->SpawnMobs(chunkId);
        }
        else
        {
            mWorld->RemoveMobs(chunkId);
        }

        ticker = curtime + 1;
    }

    if(curtime>moveTime)
    {
        int chunkId = mWorld->getChunkId(fppCam->m_vPosition);
        mWorld->UpdateAnimalPos(chunkId);
        mWorld->UpdateMobPos(chunkId);

        mWorld->rebuildChunk(chunkId);
        mWorld->rebuildTransparentChunk(chunkId);
        mWorld->rebuildNearestChunks(chunkId,fppCam->m_vPosition);

        moveTime = curtime + 0.1;
    }

    mWorld->UpdateWorldTime(dt);

    if(!mWorld->freezeDayTime)
    {
        //update skydome - every hour
        skyDome->timeOfDay = mWorld->worldDayTime * 0.041666f;

        //update sky and sun light time
        //23 000 morning
        //62 500 evening
        //39500 whole day
        //16 normal hours of day
        //2468,75 - hour / 50 seconds(hour in game)
        //49,375
        //8 hours of night
        //4937,5 - hour / 50 seconds
        //98,75  in the night

        if(mWorld->worldDayTime >= 5.0f && mWorld->worldDayTime < 21.0f)
        {
            sunTime += 49.375f * dt;//72
            if(!sunMoonSwitch)//switch to sun texture and reset position
            {
                skyLight->SetTexture(TextureManager::Instance()->GetTextureNumber("Assets/Lamecraft/sun.png"));
                sunTime = 21600.0f;//6 am
                sunMoonSwitch = true;
            }
        }
        else
        {
            sunTime += 98.75 * dt;//72
            if(sunMoonSwitch)//switch to sun texture and reset position
            {
                skyLight->SetTexture(TextureManager::Instance()->GetTextureNumber("Assets/Lamecraft/moon.png"));

                sunTime = 21600.0f;//6 am
                sunMoonSwitch = false;
            }
        }
    }
}

void StatePlay::Draw(StateManager* sManager)
{
    //start rendering
    bool needUpdate = fppCam->needUpdate;
    mRender->StartFrame();

    //draw sky and sun/moon
    {
        sceGumPushMatrix();
        ScePspFVector3 move = {-64,-64,-64};
        sceGumTranslate(&move);

        //draw skydome
        skyDome->Render();

        //draw sun/moon
        skyLight->UpdateLightSource(skyLight->TimeToAngle(sunTime));
        skyLight->Render();

        sceGumPopMatrix();
    }

    TextureManager::Instance()->SetTextureModeulate(texture);

    //draw level

    sceGuFog( 0.0f, 100.75f,GU_COLOR(mWorld->fogColor.x,mWorld->fogColor.y,mWorld->fogColor.z,1.0f));	// Fog parameters
    //sceGuAmbientColor(0xff282828);
    //sceGuFog( 0.0f, 128.75f, 0x00CCCCff );	// Fog parameters
    sceGuEnable(GU_FOG );	// Enable fog

    sceGumPushMatrix();
    mWorld->drawWorld(fppCam->mFrustum,needUpdate);
    sceGumPopMatrix();

    if(mWorld->player.gamemode == 0 || mWorld->player.gamemode == 2)
    {
        if(heathChange == true)
        {
            //Draw heart background
            for (int i = 0; i < rint(mWorld->player.maxhealth/10); i++)
            {
                heartbgChange->Draw();
                heartbgChange->SetPosition(85+(i*15),225);
            }
        }
        else
        {
            //Draw heart background
            for (int i = 0; i < rint(mWorld->player.maxhealth/10); i++)
            {
                heartbg->Draw();
                heartbg->SetPosition(85+(i*15),225);
            }
        }

        mWorld->player.active_heart = rint(mWorld->player.health/10);
        //TODO: Add support for half hearts?
        //draw actual hearts
        for (int j = 0; j < rint(mWorld->player.health/10); j++)
        {

            if(j != mWorld->player.active_heart)
            {
                heart->Draw();
                heart->SetPosition(85+(j*15),225);
            }

            //Half heart support
            //Check for half life
            if ((mWorld->player.health > 3 && mWorld->player.health < 8)   ||
                    (mWorld->player.health > 13 && mWorld->player.health < 18) ||
                    (mWorld->player.health > 23 && mWorld->player.health < 28) ||
                    (mWorld->player.health > 33 && mWorld->player.health < 38) ||
                    (mWorld->player.health > 43 && mWorld->player.health < 48) ||
                    (mWorld->player.health > 53 && mWorld->player.health < 58) ||
                    (mWorld->player.health > 63 && mWorld->player.health < 68) ||
                    (mWorld->player.health > 73 && mWorld->player.health < 78) ||
                    (mWorld->player.health > 83 && mWorld->player.health < 88) ||
                    (mWorld->player.health > 93 && mWorld->player.health < 98))
            {
                halfheart->Draw();
                halfheart->SetPosition((85+(mWorld->player.active_heart*15)),225);
            }
            /*
            			else
            {
            	heart->Draw();
            	heart->SetPosition((85+(mWorld->player.active_heart*15)),225);
            }
            */
        }

        //Draw hunger background
        for (int i = 0; i < rint(100/10); i++)
        {
            hungerBarBG->Draw();
            hungerBarBG->SetPosition(255+(i*15),225);
        }

        mWorld->player.active_hunger = rint(mWorld->player.hunger/10);
        //TODO: Add support for half hearts?
        //draw actual hearts
        for (int j = 0; j < rint(mWorld->player.hunger/10); j++)
        {

            if(j != mWorld->player.active_hunger)
            {
                hungerBar->Draw();
                hungerBar->SetPosition(255+(j*15),225);
            }

            if ((mWorld->player.hunger > 3 && mWorld->player.hunger < 8)   ||
                    (mWorld->player.hunger > 13 && mWorld->player.hunger < 18) ||
                    (mWorld->player.hunger > 23 && mWorld->player.hunger < 28) ||
                    (mWorld->player.hunger > 33 && mWorld->player.hunger < 38) ||
                    (mWorld->player.hunger > 43 && mWorld->player.hunger < 48) ||
                    (mWorld->player.hunger > 53 && mWorld->player.hunger < 58) ||
                    (mWorld->player.hunger > 63 && mWorld->player.hunger < 68) ||
                    (mWorld->player.hunger > 73 && mWorld->player.hunger < 78) ||
                    (mWorld->player.hunger > 83 && mWorld->player.hunger < 88) ||
                    (mWorld->player.hunger > 93 && mWorld->player.hunger < 98))
            {
                halfHungerBar->Draw();
                halfHungerBar->SetPosition((255+(mWorld->player.active_hunger*15)),225);
            }
            /*
            			else
            {
            	heart->Draw();
            	heart->SetPosition((85+(mWorld->player.active_heart*15)),225);
            }
            */
        }

        //draw bubbles repleneshing
        if (mWorld->player.air_time < 100 && !headInWater)
        {
            for (int k = 0; k < rint(mWorld->player.air_time/10); k++)
            {
                bubble->Draw();
                bubble->SetPosition(85+(k*15),208);
            }
        }
        //draw bubbles in general
        else if (headInWater)
        {
            for (int l = 0; l < rint(mWorld->player.air_time/10); l++)
            {
                bubble->Draw();
                bubble->SetPosition(85+(l*15),208);
            }
        }
    }


    sceGuDisable(GU_FOG );	// disable fog

    if(makeScreen)
    {
        //end frame now to update frame buffer
        mRender->EndFrame();
        //make screenshot
        mRender->TakeNextScreenshot();
        makeScreen = false;
    }

    //render pick cube
    if(showCube)
    {
        //cubePos = fppCam->m_vPosition;
        sceGumPushMatrix();

        ScePspFVector3 move = {cubePos.x,cubePos.y,cubePos.z};
        sceGumTranslate(&move);

        sceGuEnable(GU_BLEND);
        sceGuColor(0xFFFFFFFF);

        //GU_COLOR()
        mRender->Draw(cubeModel);
        sceGuDisable(GU_BLEND);

        sceGumPopMatrix();
    }

    //render cube in right hand
    {
        TextureManager::Instance()->SetTextureModeulate(texture);
        sceGumPushMatrix();

        //set view matrix to identity
        sceGumMatrixMode(GU_VIEW);
        sceGumLoadIdentity();

        //translate
        float cubeBob = + sinf(bobCycle*180.0f*DEG_TO_RAD)*-0.1f+0.05f;
        float cubeEffect = + sinf(cubeCycle*180.0f*DEG_TO_RAD)*-0.1f+0.05f;
        if(keyHold(InputHelper::Instance()->getButtonToAction(13)))
        {
            ScePspFVector3 move = {0.47f+cubeEffect,-0.32f+cubeEffect,-0.7f+cubeEffect};
            sceGumTranslate(&move);
        }
        else if(cubeMove == true)
        {
            ScePspFVector3 move = {0.47f+cubeEffect,-0.32f+cubeEffect,-0.7f+cubeEffect};
            sceGumTranslate(&move);
        }
        else
        {
            ScePspFVector3 move = {0.47f+cubeBob,-0.32f+cubeBob,-0.7f};
            sceGumTranslate(&move);
        }
        //rotate
        sceGumRotateX(0.2792f);
        sceGumRotateY(0.7853f);
        //scale
        ScePspFVector3 scale = {0.25f,0.25f,0.25f};
        sceGumScale(&scale);

        //draw cube
        sceGuDisable(GU_DEPTH_TEST);
        sceGuDepthMask(1);
        mWorld->drawCubes((selectedCubeSet + selectedCube+1));
        sceGuEnable(GU_DEPTH_TEST);
        sceGuDepthMask(0);

        sceGumMatrixMode(GU_MODEL);
        sceGumPopMatrix();
    }



    //gui
    mRender->SetOrtho(0,0,0,0,0,0);

    if(headInWater)
    {
        sceGuDisable(GU_DEPTH_TEST);
        sceGuDepthMask(1);
        sceGuEnable(GU_BLEND);
        sceGuEnable(GU_TEXTURE_2D);
        sceGuColor(GU_COLOR(1,1,1,0.7f));
        TextureManager::Instance()->SetTextureModeulate(blue);
        advancedBlit(0,0,SCR_WIDTH,SCR_HEIGHT,0,0,32);
        sceGuDisable(GU_BLEND);
        sceGuDisable(GU_TEXTURE_2D);
        sceGuEnable(GU_DEPTH_TEST);
        sceGuDepthMask(0);
    }

    if(headInLava || mWorld->player.health == 0)
    {
        sceGuDisable(GU_DEPTH_TEST);
        sceGuDepthMask(1);
        sceGuEnable(GU_BLEND);
        sceGuEnable(GU_TEXTURE_2D);
        sceGuColor(GU_COLOR(1,1,1,0.7f));
        TextureManager::Instance()->SetTextureModeulate(red);
        advancedBlit(0,0,SCR_WIDTH,SCR_HEIGHT,0,0,32);
        sceGuDisable(GU_BLEND);
        sceGuDisable(GU_TEXTURE_2D);
        sceGuEnable(GU_DEPTH_TEST);
        sceGuDepthMask(0);
    }

    //gui
    sceGuDisable(GU_DEPTH_TEST);
    sceGuDepthMask(1);
    sceGuEnable(GU_BLEND);
    sceGuColor(GU_COLOR(1,1,1,1.0f));

    barSprite->Draw();
    selectSprite->Draw();
    crossSprite->Draw();

    if(mWorld->player.gamemode == 0 || mWorld->player.gamemode == 2)
    {
        if(heathChange == true)
        {
            //Draw heart background
            for (int i = 0; i < rint(mWorld->player.maxhealth/10); i++)
            {
                heartbgChange->Draw();
                heartbgChange->SetPosition(85+(i*15),225);
            }
        }
        else
        {
            //Draw heart background
            for (int i = 0; i < rint(mWorld->player.maxhealth/10); i++)
            {
                heartbg->Draw();
                heartbg->SetPosition(85+(i*15),225);
            }
        }

        mWorld->player.active_heart = rint(mWorld->player.health/10);
        //TODO: Add support for half hearts?
        //draw actual hearts
        for (int j = 0; j < rint(mWorld->player.health/10); j++)
        {

            if(j != mWorld->player.active_heart)
            {
                heart->Draw();
                heart->SetPosition(85+(j*15),225);
            }

            //Half heart support
            //Check for half life
            if ((mWorld->player.health > 3 && mWorld->player.health < 8)   ||
                    (mWorld->player.health > 13 && mWorld->player.health < 18) ||
                    (mWorld->player.health > 23 && mWorld->player.health < 28) ||
                    (mWorld->player.health > 33 && mWorld->player.health < 38) ||
                    (mWorld->player.health > 43 && mWorld->player.health < 48) ||
                    (mWorld->player.health > 53 && mWorld->player.health < 58) ||
                    (mWorld->player.health > 63 && mWorld->player.health < 68) ||
                    (mWorld->player.health > 73 && mWorld->player.health < 78) ||
                    (mWorld->player.health > 83 && mWorld->player.health < 88) ||
                    (mWorld->player.health > 93 && mWorld->player.health < 98))
            {
                halfheart->Draw();
                halfheart->SetPosition((85+(mWorld->player.active_heart*15)),225);
            }
            /*
            			else
            {
            	heart->Draw();
            	heart->SetPosition((85+(mWorld->player.active_heart*15)),225);
            }
            */
        }

        //Draw heart background
        for (int i = 0; i < rint(100/10); i++)
        {
            hungerBarBG->Draw();
            hungerBarBG->SetPosition(255+(i*15),225);
        }

        mWorld->player.active_hunger = rint(mWorld->player.hunger/10);
        //TODO: Add support for half hearts?
        //draw actual hearts
        for (int j = 0; j < rint(mWorld->player.hunger/10); j++)
        {

            if(j != mWorld->player.active_hunger)
            {
                hungerBar->Draw();
                hungerBar->SetPosition(255+(j*15),225);
            }

            //Half heart support
            //Check for half life
            if ((mWorld->player.hunger > 3 && mWorld->player.hunger < 8)   ||
                    (mWorld->player.hunger > 13 && mWorld->player.hunger < 18) ||
                    (mWorld->player.hunger > 23 && mWorld->player.hunger < 28) ||
                    (mWorld->player.hunger > 33 && mWorld->player.hunger < 38) ||
                    (mWorld->player.hunger > 43 && mWorld->player.hunger < 48) ||
                    (mWorld->player.hunger > 53 && mWorld->player.hunger < 58) ||
                    (mWorld->player.hunger > 63 && mWorld->player.hunger < 68) ||
                    (mWorld->player.hunger > 73 && mWorld->player.hunger < 78) ||
                    (mWorld->player.hunger > 83 && mWorld->player.hunger < 88) ||
                    (mWorld->player.hunger > 93 && mWorld->player.hunger < 98))
            {
                halfHungerBar->Draw();
                halfHungerBar->SetPosition((255+(mWorld->player.active_hunger*15)),225);
            }
            /*
            			else
            {
            	heart->Draw();
            	heart->SetPosition((85+(mWorld->player.active_heart*15)),225);
            }
            */
        }

        //draw bubbles repleneshing
        if (mWorld->player.air_time < 100 && !headInWater)
        {
            for (int k = 0; k < rint(mWorld->player.air_time/10); k++)
            {
                bubble->Draw();
                bubble->SetPosition(85+(k*15),208);
            }
        }
        //draw bubbles in general
        else if (headInWater)
        {
            for (int l = 0; l < rint(mWorld->player.air_time/10); l++)
            {
                bubble->Draw();
                bubble->SetPosition(85+(l*15),208);
            }
        }
    }

    sceGuDisable(GU_BLEND);


    //draw 3d cubes on 2d panel
    TextureManager::Instance()->SetTextureModeulate(texture);
    int bloStartPos = 100;
    int selectionEnd = 10;
    if(selectedCubeSet == (cubesSets - 1) * 9)
    {
        selectionEnd = allcubes - ((cubesSets - 1) * 9) - 12;
    }


    for(int blo = 1 + selectedCubeSet; blo < selectionEnd + selectedCubeSet; blo++)
    {
        sceGumPushMatrix();

        ScePspFVector3 loc = {bloStartPos,253,0.0f};
        sceGumTranslate(&loc);

        ScePspFVector3 sca = {17,17,17.0f};
        sceGumScale(&sca);

        //rotate
        sceGumRotateX(2.61f);
        sceGumRotateY(0.78f);

        sceGuFrontFace(GU_CW);
        mWorld->drawCubes(blo);
        sceGuFrontFace(GU_CCW);

        sceGumPopMatrix();

        bloStartPos+=35;
    }

	
	{
	//Info panel
	
	//Text Start
	
	mRender->DebugPrint(255,10,"Score.: %i", mWorld->player.score); // show your score
	 mRender->DebugPrint(255,30,"Grass: %i", mWorld->player.GrassNumber);
	  mRender->DebugPrint(255,50,"Dirt: %i", mWorld->player.DirtNumber);
	   mRender->DebugPrint(255,70,"Log: %i", mWorld->player.LogNumber);
	    mRender->DebugPrint(255,90,"Plank: %i", mWorld->player.PlankNumber);


	
	//End of text
	}
	
    sceGuEnable(GU_DEPTH_TEST);
    sceGuDepthMask(0);
    
	
	
    //menu buttons
    if(menuState == 1)
    {
        if(menuOptions)
        {
            if(mWorld->player.gamemode == 0 || mWorld->player.gamemode == 2)
            {
                sceGuDisable(GU_DEPTH_TEST);
                sceGuEnable(GU_BLEND);
                sceGuColor(GU_COLOR(1,1,1,1.0f));

                buttonSprite->SetPosition(130,100);
                buttonSprite->Draw();

                //fly
                buttonSprite->SetPosition(350,100);
                buttonSprite->Draw();

                //dev menu
                buttonSprite->SetPosition(130,130);
                buttonSprite->Draw();

                //screenshot
                buttonSprite->SetPosition(350,130);
                buttonSprite->Draw();

                //rename map
                buttonSprite->SetPosition(130,160);
                buttonSprite->Draw();

                //player sounds
                buttonSprite->SetPosition(350,160);
                buttonSprite->Draw();

                //selected button
                if(optionsMenuPos >= 0 && optionsMenuPos <=9)
                {
                    if(optionsMenuPos%2 == 0)
                    {
                        sbuttonSprite->SetPosition(130,((int)(optionsMenuPos/2) * 30) + 100);
                        sbuttonSprite->Draw();
                    }
                    else
                    {
                        sbuttonSprite->SetPosition(350,((int)(optionsMenuPos/2) * 30) + 100);
                        sbuttonSprite->Draw();
                    }
                }
                else
                {
                    sbuttonSprite->SetPosition(240,250);
                    sbuttonSprite->Draw();
                }


                sceGuDisable(GU_BLEND);
                sceGuEnable(GU_DEPTH_TEST);

                mRender->DebugPrint(240,50,"OPTIONS");

                //draw subtitles on buttons
                mRender->DebugPrint(130,105,"Take Screenshot");
                mRender->DebugPrint(350,105,"CHange map name");
                mSoundMgr->playerSounds == true ? mRender->DebugPrint(130,135,"sounds: ON"):mRender->DebugPrint(130,135,"sounds: OFF");
                canHeadBob == true ? mRender->DebugPrint(350,135,"Head bob: ON"):mRender->DebugPrint(350,135,"Head bob: OFF");
                mSoundMgr->ambientSoundsEnabled == true ? mRender->DebugPrint(130,165,"Ambient sounds: ON"):mRender->DebugPrint(130,165,"Ambient sounds: OFF");
                CanSpawnMobs == true ? mRender->DebugPrint(350,165,"Mobs: ON"):mRender->DebugPrint(350,165,"Mobs: OFF");
            }
            else
            {
                sceGuDisable(GU_DEPTH_TEST);
                sceGuEnable(GU_BLEND);
                sceGuColor(GU_COLOR(1,1,1,1.0f));

                buttonSprite->SetPosition(130,100);
                buttonSprite->Draw();

                //fly
                buttonSprite->SetPosition(350,100);
                buttonSprite->Draw();

                //dev menu
                buttonSprite->SetPosition(130,130);
                buttonSprite->Draw();

                //screenshot
                buttonSprite->SetPosition(350,130);
                buttonSprite->Draw();

                //rename map
                buttonSprite->SetPosition(130,160);
                buttonSprite->Draw();

                //player sounds
                buttonSprite->SetPosition(350,160);
                buttonSprite->Draw();

                //headBob
                buttonSprite->SetPosition(130,190);
                buttonSprite->Draw();

                //ambient music
                buttonSprite->SetPosition(350,190);
                buttonSprite->Draw();

                //canSpawn
                buttonSprite->SetPosition(130,220);
                buttonSprite->Draw();

                //place spheres
                buttonSprite->SetPosition(350,220);
                buttonSprite->Draw();

                //selected button
                if(optionsMenuPos >= 0 && optionsMenuPos <=9)
                {
                    if(optionsMenuPos%2 == 0)
                    {
                        sbuttonSprite->SetPosition(130,((int)(optionsMenuPos/2) * 30) + 100);
                        sbuttonSprite->Draw();
                    }
                    else
                    {
                        sbuttonSprite->SetPosition(350,((int)(optionsMenuPos/2) * 30) + 100);
                        sbuttonSprite->Draw();
                    }
                }
                else
                {
                    sbuttonSprite->SetPosition(240,250);
                    sbuttonSprite->Draw();
                }


                sceGuDisable(GU_BLEND);
                sceGuEnable(GU_DEPTH_TEST);

                mRender->DebugPrint(240,50,"OPTIONS");

                //draw subtitles on buttons
                canFly == true ? mRender->DebugPrint(130,105,"Fly : ON"): mRender->DebugPrint(130,105,"Fly : OFF");
                devMode == true ? mRender->DebugPrint(350,105,"DevMode : ON"): mRender->DebugPrint(350,105,"DevMode : OFF");
                mRender->DebugPrint(130,135,"Take Screenshot");
                mRender->DebugPrint(350,135,"Change map name");
                mSoundMgr->playerSounds == true ? mRender->DebugPrint(130,165,"sounds: ON"):mRender->DebugPrint(130,165,"sounds: OFF");
                canHeadBob == true ? mRender->DebugPrint(350,165,"Head bob: ON"):mRender->DebugPrint(350,165,"Head bob: OFF");
                mWorld->freezeDayTime == true ? mRender->DebugPrint(130,195,"Day time freeze: ON"):mRender->DebugPrint(130,195,"Day time freeze: OFF");
                mSoundMgr->ambientSoundsEnabled == true ? mRender->DebugPrint(350,195,"Ambient sounds: ON"):mRender->DebugPrint(350,195,"Ambient sounds: OFF");
                CanSpawnMobs == true ? mRender->DebugPrint(130,225,"Mobs: ON"):mRender->DebugPrint(130,225,"Mobs: OFF");
                CanBigCubes == true ? mRender->DebugPrint(350,225,"Place spheres: ON"):mRender->DebugPrint(350,225,"Place spheres: OFF");
            }
        }
        else
        {
            sceGuDisable(GU_DEPTH_TEST);
            sceGuEnable(GU_BLEND);
            sceGuColor(GU_COLOR(1,1,1,1.0f));

            //resume
            buttonSprite->SetPosition(240,100);
            buttonSprite->Draw();

            //options
            buttonSprite->SetPosition(240,130);
            buttonSprite->Draw();

            //save
            buttonSprite->SetPosition(240,160);
            buttonSprite->Draw();

            //quit
            buttonSprite->SetPosition(240,190);
            buttonSprite->Draw();

            //quit and save
            buttonSprite->SetPosition(240,220);
            buttonSprite->Draw();

            //selected button
            sbuttonSprite->SetPosition(240,(selectPos * 30) + 100);
            sbuttonSprite->Draw();

            sceGuDisable(GU_BLEND);
            sceGuEnable(GU_DEPTH_TEST);

            //draw subtitles on buttons
            mRender->DebugPrint(240,105,"Resume");
            mRender->DebugPrint(240,135,"Options");
            mRender->DebugPrint(240,165,"Save");
            mRender->DebugPrint(240,195,"Save and Exit");
            mRender->DebugPrint(240,225,"Exit");
        }
    }
 else if(menuState == 2)
    {
        sceGuDisable(GU_DEPTH_TEST);
        sceGuEnable(GU_BLEND);
        sceGuColor(GU_COLOR(1,1,1,1.0f));
        
        buttonSprite->SetPosition(240,120);
        buttonSprite->Draw();

       
        buttonSprite->SetPosition(240,160);
        buttonSprite->Draw();


        buttonSprite->SetPosition(240,200);
        buttonSprite->Draw();

        //selected button
        sbuttonSprite->SetPosition(240,(selectPos * 40) + 120);
        sbuttonSprite->Draw();

        sceGuDisable(GU_BLEND);
        sceGuEnable(GU_DEPTH_TEST);

        //draw subtitles on buttons

        mRender->DebugPrint(240,125,"Apples: %i", mWorld->player.Apples);
        mRender->DebugPrint(240,165,"Melons: %i", mWorld->player.melons);		
        mRender->DebugPrint(240,205,"Craft Plank from Log");

     
    }
    else if(menuState == 3)
    {
        sceGuDisable(GU_DEPTH_TEST);
        sceGuEnable(GU_BLEND);
        sceGuColor(GU_COLOR(1,1,1,1.0f));

        //survival
        buttonSprite->SetPosition(240,100);
        buttonSprite->Draw();

        //creative
        buttonSprite->SetPosition(240,130);
        buttonSprite->Draw();

        //hardcore
        buttonSprite->SetPosition(240,160);
        buttonSprite->Draw();

        //selected button
        sbuttonSprite->SetPosition(240,(selectPos * 30) + 100);
        sbuttonSprite->Draw();

        sceGuDisable(GU_BLEND);
        sceGuEnable(GU_DEPTH_TEST);

        mRender->DebugPrint(240,50,"GAMEMODE");

        //draw subtitles on buttons
        mRender->DebugPrint(240,105,"Survival");
        mRender->DebugPrint(240,135,"Creative");
        mRender->DebugPrint(240,165,"Hardcore");
    }
    else if(menuState == 4)
    {
        sceGuDisable(GU_DEPTH_TEST);
        sceGuEnable(GU_BLEND);
        sceGuColor(GU_COLOR(1,1,1,1.0f));

        //jumping
        buttonSprite->SetPosition(240,100);
        buttonSprite->Draw();

        //walk speed
        buttonSprite->SetPosition(240,130);
        buttonSprite->Draw();

        //fire resistance
        buttonSprite->SetPosition(240,160);
        buttonSprite->Draw();



        //selected button
        sbuttonSprite->SetPosition(240,(selectPos * 30) + 100);
        sbuttonSprite->Draw();

        sceGuDisable(GU_BLEND);
        sceGuEnable(GU_DEPTH_TEST);

        mRender->DebugPrint(240,25,"BEACON BLOCK");

        mRender->DebugPrint(60,25,"score: %i", mWorld->player.score);

        //draw subtitles on buttons
        mRender->DebugPrint(240,105,"jump level: %i", mWorld->player.jumpHeight);

        //draw subtitles on buttons
        mRender->DebugPrint(240,135,"walk speed level: %i", mWorld->player.walkSpeed);

        //draw subtitles on buttons
        mRender->DebugPrint(240,165,"fire resistance: %i", mWorld->player.fireResistance);


        if(selectPos == 0)
        {
            if(mWorld->player.jumpHeight == 0)
            {
                mRender->DebugPrint(50,50,"needed: 60");
            }
            else if(mWorld->player.jumpHeight == 1 || mWorld->player.jumpHeight == 2)
            {
                mRender->DebugPrint(50,50,"needed: 90");
            }
            else if(mWorld->player.jumpHeight == 3)
            {
                mRender->DebugPrint(50,50,"needed: 120");
            }
            else
            {
                mRender->DebugPrint(120,50,"max");
            }
        }

        if(selectPos == 1)
        {
            if(mWorld->player.walkSpeed == 0)
            {
                mRender->DebugPrint(50,50,"needed: 60");
            }
            else if(mWorld->player.walkSpeed == 1 || mWorld->player.walkSpeed == 2)
            {
                mRender->DebugPrint(50,50,"needed: 90");
            }
            else if(mWorld->player.walkSpeed == 3)
            {
                mRender->DebugPrint(50,50,"needed: 120");
            }
            else
            {
                mRender->DebugPrint(120,50,"max");
            }
        }

        if(selectPos == 2)
        {
            if(mWorld->player.fireResistance == 0)
            {
                mRender->DebugPrint(50,50,"needed: 60");
            }
            else if(mWorld->player.fireResistance == 1 || mWorld->player.fireResistance == 2)
            {
                mRender->DebugPrint(50,50,"needed: 90");
            }
            else if(mWorld->player.fireResistance == 3)
            {
                mRender->DebugPrint(50,50,"needed: 120");
            }
            else
            {
                mRender->DebugPrint(120,50,"max");
            }
        }

    }
	
	else if(menuState == 5)
    {
        sceGuDisable(GU_DEPTH_TEST);
        sceGuEnable(GU_BLEND);
        sceGuColor(GU_COLOR(1,1,1,1.0f));

     
        buttonSprite->SetPosition(240,100);
        buttonSprite->Draw();


        buttonSprite->SetPosition(240,130);
        buttonSprite->Draw();

 
        buttonSprite->SetPosition(240,160);
        buttonSprite->Draw();



        //selected button
        sbuttonSprite->SetPosition(240,(selectPos * 30) + 100);
        sbuttonSprite->Draw();

        sceGuDisable(GU_BLEND);
        sceGuEnable(GU_DEPTH_TEST);

        mRender->DebugPrint(240,25,"CRAFTING TABLE");

        mRender->DebugPrint(60,25,"score: %i", mWorld->player.score);

        //draw subtitles on buttons
        mRender->DebugPrint(240,105,"No crafting recipes :(");

        //draw subtitles on buttons
        mRender->DebugPrint(240,135,"No crafting recipes :(");

        //draw subtitles on buttons
        mRender->DebugPrint(240,165,"No crafting recipes :(");


        if(selectPos == 0)
        {
            if(mWorld->player.jumpHeight == 0)
            {
                mRender->DebugPrint(50,50,"needed: 60");
            }
            else if(mWorld->player.jumpHeight == 1 || mWorld->player.jumpHeight == 2)
            {
                mRender->DebugPrint(50,50,"needed: 90");
            }
            else if(mWorld->player.jumpHeight == 3)
            {
                mRender->DebugPrint(50,50,"needed: 120");
            }
            else
            {
                mRender->DebugPrint(120,50,"max");
            }
        }

        if(selectPos == 1)
        {
            if(mWorld->player.walkSpeed == 0)
            {
                mRender->DebugPrint(50,50,"needed: 60");
            }
            else if(mWorld->player.walkSpeed == 1 || mWorld->player.walkSpeed == 2)
            {
                mRender->DebugPrint(50,50,"needed: 90");
            }
            else if(mWorld->player.walkSpeed == 3)
            {
                mRender->DebugPrint(50,50,"needed: 120");
            }
            else
            {
                mRender->DebugPrint(120,50,"max");
            }
        }

        if(selectPos == 2)
        {
            if(mWorld->player.fireResistance == 0)
            {
                mRender->DebugPrint(50,50,"needed: 60");
            }
            else if(mWorld->player.fireResistance == 1 || mWorld->player.fireResistance == 2)
            {
                mRender->DebugPrint(50,50,"needed: 90");
            }
            else if(mWorld->player.fireResistance == 3)
            {
                mRender->DebugPrint(50,50,"needed: 120");
            }
            else
            {
                mRender->DebugPrint(120,50,"max");
            }
        }

    }

    if(mWorld->player.gamemode == 0 || mWorld->player.gamemode == 2)
    {
        //Nice little effect to make the screen flash red
        if(damage_fade > 0 && mWorld->player.health > 0)
        {
            if (damage_fade_time > 0.1)
            {
                damage_fade -= 0.1;
                damage_fade_time = 0;

                if (damage_fade < 0)
                    damage_fade = 0;
            }

            sceGuDisable(GU_DEPTH_TEST);
            sceGuDepthMask(1);
            sceGuEnable(GU_BLEND);
            sceGuEnable(GU_TEXTURE_2D);
            sceGuColor(GU_COLOR(1,1,1, damage_fade));
            TextureManager::Instance()->SetTextureModeulate(red);
            advancedBlit(0,0,SCR_WIDTH,SCR_HEIGHT,0,0,32);
            sceGuDisable(GU_BLEND);
            sceGuDisable(GU_TEXTURE_2D);
            sceGuEnable(GU_DEPTH_TEST);
            sceGuDepthMask(0);

        }
        damage_fade_time += dt;

        //Player dead screen
        if(mWorld->player.health <= 0)
        {

            sceGuDisable(GU_DEPTH_TEST);
            sceGuEnable(GU_BLEND);
            sceGuColor(GU_COLOR(1,1,1,1.0f));

            sbuttonSprite->SetPosition(240,145);
            sbuttonSprite->Draw();

            sceGuDisable(GU_BLEND);
            sceGuEnable(GU_DEPTH_TEST);

            mRender->SetFontStyle(1.2f,0xFFFFFFFF,0xFF000000,0x00000000);
            mRender->DebugPrint(150,80,"You Died!\n");


            mRender->SetFontStyle(0.5f,0xFFFFFFFF,0xFF000000,0x00000200);
            mRender->DebugPrint(240,120,"Score: %i", mWorld->player.score); // show your score

            if(mWorld->player.gamemode == 2)
                mRender->DebugPrint(240,150,"quit");
            else
                mRender->DebugPrint(240,150,"respawn");
        }
    }

    //debug info
    if(devMode)
    {
        mRender->SetFontStyle(0.5f,0xFFFFFFFF,0xFF000000,0x00000000);

        if(dt > 0.0f)
            mRender->DebugPrint(20,20,"fps: %4.2f",(1.0f/dt));
        mRender->DebugPrint(20,30,"cpu: %d%%",mRender->GetCpuUsage());
        mRender->DebugPrint(20,40,"gpu: %d%%",mRender->GetGpuUsage());
        mRender->DebugPrint(20,50,"memory: %d",freeMemory);
        mRender->DebugPrint(20,60,"poly: %d",(mWorld->GetDrawntTrianglesCount() / 3));
        mRender->DebugPrint(20,70,"verts: %d",mWorld->GetDrawntTrianglesCount());
        mRender->DebugPrint(20,80,"day time: %f",mWorld->worldDayTime);
        mRender->DebugPrint(20,90,"sky time: %f",skyDome->timeOfDay);
        mRender->DebugPrint(20,100,"sun time: %f",sunTime);
        mRender->DebugPrint(20,110,"ambient track: %d",mSoundMgr->currentAmbientSound);
        mRender->DebugPrint(20,120,"mobs: %d",mWorld->player.NumMobs);

        mRender->SetFontStyle(0.5f,0xFFFFFFFF,0xFF000000,0x00000200);
    }

    //end frame
    mRender->EndFrame();
}

//additional functions
void StatePlay::advancedBlit(int sx, int sy, int sw, int sh, int dx, int dy, int slice)
{
    int start, end;

    // blit maximizing the use of the texture-cache

    for (start = sx, end = sx+sw; start < end; start += slice, dx += slice)
    {
        TexturesPSPVertex16* vertices = (TexturesPSPVertex16*)sceGuGetMemory(2 * sizeof(TexturesPSPVertex16));
        int width = (start + slice) < end ? slice : end-start;

        vertices[0].u = start;
        vertices[0].v = sy;
        vertices[0].x = dx;
        vertices[0].y = dy;
        vertices[0].z = 0;

        vertices[1].u = start + width;
        vertices[1].v = sy + sh;
        vertices[1].x = dx + width;
        vertices[1].y = dy + sh;
        vertices[1].z = 0;

        sceGuDrawArray(GU_SPRITES,GU_TEXTURE_16BIT|GU_VERTEX_16BIT|GU_TRANSFORM_2D,2,0,vertices);
    }
}

bool StatePlay::TryToMove(Vector3 moveVector,float dt)
{
    // Build a "test vector" that is a little longer than the move vector.
    float moveLength = moveVector.magnitude();
    Vector3 testVector = moveVector;
    testVector.normalize();
    testVector = testVector * (moveLength + 0.2f);

    // Apply this test vector.
    Vector3 movePosition = playerPosition + testVector;
    Vector3 midBodyPoint = movePosition + Vector3(0, -0.7f, 0);
    Vector3 lowerBodyPoint = movePosition + Vector3(0, -1.4f, 0);
    Vector3 moveHeadPosition = movePosition + Vector3(0, 0.1f, 0);

    Vector3 footPosition = playerPosition + Vector3(0.0f, -1.5f, 0.0f);
    Vector3 legsPosition = playerPosition + Vector3(0.0f, -1.0f, 0.0f);
    Vector3 headPosition = playerPosition + Vector3(0.0f, 0.1f, 0.0f);

    if (!mWorld->SolidAtPointForPlayer(movePosition) && !mWorld->SolidAtPointForPlayer(lowerBodyPoint) && !mWorld->SolidAtPointForPlayer(midBodyPoint) && !mWorld->PlayerOnHalfBlock(moveHeadPosition) && !mWorld->PlayerOnLilyPad(moveHeadPosition))
    {
        if(mWorld->PlayerOnHalfBlock(legsPosition) && mWorld->PlayerOnHalfBlock(movePosition))
        {
            playerPosition = playerPosition;
        }
        else
        {
            if(mWorld->PlayerInWeb(headPosition) || mWorld->PlayerInWeb(legsPosition))
            {
                playerPosition = playerPosition + moveVector/7;
                return true;
            }
            else if(mWorld->PlayerOnSoulSand(footPosition))
            {
                playerPosition = playerPosition + moveVector/3;
                return true;
            }
            else
            {
                if(mWorld->player.walkSpeed == 1)
                {
                    playerPosition = playerPosition + moveVector * 1.25;
                    return true;
                }
                else if(mWorld->player.walkSpeed == 2)
                {
                    playerPosition = playerPosition + moveVector * 1.5;
                    return true;
                }
                else if(mWorld->player.walkSpeed == 3)
                {
                    playerPosition = playerPosition + moveVector * 1.75;
                    return true;
                }
                else if(mWorld->player.walkSpeed == 4)
                {
                    playerPosition = playerPosition + moveVector * 2;
                    return true;
                }
                else
                {
                    playerPosition = playerPosition + moveVector;
                    return true;
                }
            }
        }
    }

    //teraz mo¿na robiæ ciekawe rzeczy

    testVector = moveVector;
    testVector.normalize();
    testVector = testVector * (moveLength + 0.35f);
    movePosition = playerPosition + testVector;
    midBodyPoint = movePosition + Vector3(0, -0.7f, 0);
    lowerBodyPoint = movePosition + Vector3(0, -1.4f, 0);

    unsigned char lowerBlock = mWorld->BlockAtPoint(lowerBodyPoint);
    unsigned char midBlock = mWorld->BlockAtPoint(midBodyPoint);
    unsigned char upperBlock = mWorld->BlockAtPoint(movePosition);

    for(float testY = 0; testY <= 5.0f; testY++)
    {
        //gravity
        Vector3 specialPosition = playerPosition + Vector3(0.0f,-1.0f - testY, 0.0f);

        //kolizja z drabin¹ :>
        if (mWorld->PlayerOnLadder(footPosition) || mWorld->PlayerOnLadder(legsPosition) || mWorld->PlayerOnLadder(headPosition))
        {
            playerVelocity.y = CLIMBVELOCITY;
            Vector3 footPosition = playerPosition + Vector3(0.0f, -1.5f, 0.0f);
            if (mWorld->SolidAtPointForPlayer(footPosition))
                playerPosition.y += 0.1f;
            return true;
        }


        if (mWorld->PlayerOnHalfBlock(legsPosition) && !mWorld->PlayerOnHalfBlock(midBodyPoint) && !mWorld->SolidAtPointForPlayer(moveHeadPosition))
        {
            walkingOnGround = true;
            playerVelocity.y = CLIMBVELOCITY;
            playerPosition.y += 0.3f;
            return true;
        }

        //if (lowerBlock == 82)
        //{
        //  playerVelocity.y = CLIMBVELOCITY;
        //Vector3 footPosition = playerPosition + Vector3(0.0f, -1.5f, 0.0f);
        //if (mWorld->SolidAtPointForPlayer(footPosition))
        //  playerPosition.y += 0.75f;
        //return true;
        //}
    }
    return false;
}

bool StatePlay::keyPressed(int currentKey)
{
    //analog reset
    if(analogUp)
    {
        if(mSystemMgr->GetAnalogY() < InputHelper::Instance()->analogYup)
            analogUp = false;
    }
    if(analogDown)
    {
        if(mSystemMgr->GetAnalogY() > InputHelper::Instance()->analogYdown)
            analogDown = false;
    }
    if(analogLeft)
    {
        if(mSystemMgr->GetAnalogX() > InputHelper::Instance()->analogXleft)
            analogLeft = false;
    }
    if(analogRight)
    {
        if(mSystemMgr->GetAnalogX() < InputHelper::Instance()->analogXright)
            analogRight = false;
    }

    //keys
    if(currentKey == 0)//cross
        return mSystemMgr->KeyPressed(PSP_CTRL_UP);
    if(currentKey == 1)//cross
        return mSystemMgr->KeyPressed(PSP_CTRL_DOWN);
    if(currentKey == 2)//cross
        return mSystemMgr->KeyPressed(PSP_CTRL_LEFT);
    if(currentKey == 3)//cross
        return mSystemMgr->KeyPressed(PSP_CTRL_RIGHT);

    if(currentKey == 4)//cross
        return mSystemMgr->KeyPressed(PSP_CTRL_TRIANGLE);
    if(currentKey == 5)//cross
        return mSystemMgr->KeyPressed(PSP_CTRL_CROSS);
    if(currentKey == 6)//cross
        return mSystemMgr->KeyPressed(PSP_CTRL_SQUARE);
    if(currentKey == 7)//cross
        return mSystemMgr->KeyPressed(PSP_CTRL_CIRCLE);

    if(currentKey == 8)//cross
        return mSystemMgr->KeyPressed(PSP_CTRL_LTRIGGER);
    if(currentKey == 9)//cross
        return mSystemMgr->KeyPressed(PSP_CTRL_RTRIGGER);
    if(currentKey == 10)//cross
        return mSystemMgr->KeyPressed(PSP_CTRL_SELECT);
    if(currentKey == 15)//cross
        return mSystemMgr->KeyPressed(PSP_CTRL_START);

    //analog stick....
    if(currentKey == 12)//cross
    {
        if(!analogUp)
        {
            if(mSystemMgr->GetAnalogY() > InputHelper::Instance()->analogYup)
            {
                analogUp = true;
                return true;//analog up
            }
        }
    }
    if(currentKey == 11)//cross
    {
        if(!analogDown)
        {
            if(mSystemMgr->GetAnalogY() < InputHelper::Instance()->analogYdown)
            {
                analogDown = true;
                return true;//analog down
            }
        }
    }
    if(currentKey == 13)//cross
    {
        if(!analogLeft)
        {
            if(mSystemMgr->GetAnalogX() < InputHelper::Instance()->analogXleft)
            {
                analogLeft = true;
                return true;//analog left
            }
        }
    }
    if(currentKey == 14)//cross
    {
        if(!analogRight)
        {
            if(mSystemMgr->GetAnalogX() > InputHelper::Instance()->analogXright)
            {
                analogRight = true;
                return true;//analog right
            }
        }
    }

    return false;
}

bool StatePlay::keyHold(int currentKey)
{
    if(currentKey == 0)//cross
        return mSystemMgr->KeyHold(PSP_CTRL_UP);
    if(currentKey == 1)//cross
        return mSystemMgr->KeyHold(PSP_CTRL_DOWN);
    if(currentKey == 2)//cross
        return mSystemMgr->KeyHold(PSP_CTRL_LEFT);
    if(currentKey == 3)//cross
        return mSystemMgr->KeyHold(PSP_CTRL_RIGHT);

    if(currentKey == 4)//cross
        return mSystemMgr->KeyHold(PSP_CTRL_TRIANGLE);
    if(currentKey == 5)//cross
        return mSystemMgr->KeyHold(PSP_CTRL_CROSS);
    if(currentKey == 6)//cross
        return mSystemMgr->KeyHold(PSP_CTRL_SQUARE);
    if(currentKey == 7)//cross
        return mSystemMgr->KeyHold(PSP_CTRL_CIRCLE);

    if(currentKey == 8)//cross
        return mSystemMgr->KeyHold(PSP_CTRL_LTRIGGER);
    if(currentKey == 9)//cross
        return mSystemMgr->KeyHold(PSP_CTRL_RTRIGGER);
    if(currentKey == 10)//cross
        return mSystemMgr->KeyHold(PSP_CTRL_SELECT);
    if(currentKey == 15)//cross
        return mSystemMgr->KeyHold(PSP_CTRL_START);

    //analog stick....
    if(currentKey == 12)//cross
        return (mSystemMgr->GetAnalogY() > InputHelper::Instance()->analogYup);//analog up
    if(currentKey == 11)//cross
        return (mSystemMgr->GetAnalogY() < InputHelper::Instance()->analogYdown);//analog down
    if(currentKey == 13)//cross
        return (mSystemMgr->GetAnalogX() < InputHelper::Instance()->analogXleft);//analog left
    if(currentKey == 14)//cross
        return (mSystemMgr->GetAnalogX() > InputHelper::Instance()->analogXright);//analog right

    return false;
}
