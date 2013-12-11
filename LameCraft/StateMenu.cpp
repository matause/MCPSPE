#include "StateMenu.h"
#include "StateOptions.h"
#include "StatePlay.h"
#include "LoadingScreen.h"
#include "InputHelper.h"
#include "TextureHelper.h"

#include <Aurora/System/NetworkManager.h>

#include <zlib.h>
#include <dirent.h>
#include <fcntl.h>


StateMenu::StateMenu()
{

}

StateMenu::~StateMenu()
{

}

void StateMenu::Init()
{
    //set render manager instance
    mRender = RenderManager::InstancePtr();
    mSystemMgr = SystemManager::Instance();
    mSoundMgr = SoundManager::Instance();

    logoSprite = new Sprite(TextureHelper::Instance()->GetTexture(TextureHelper::Logo),0,0,256,64);
    logoSprite->Scale(1.5f,1.5f);
    logoSprite->SetPosition(240,50);

    buttonSprite = new Sprite(TextureHelper::Instance()->GetTexture(TextureHelper::Utils),24,22,200,20);
    buttonSprite->SetPosition(240,150);

    sbuttonSprite = new Sprite(TextureHelper::Instance()->GetTexture(TextureHelper::Utils),24,42,200,20);
    sbuttonSprite->SetPosition(240,150);

    backSprite = new Sprite(TextureHelper::Instance()->GetTexture(TextureHelper::Dirt),0,0,16,16);
    backSprite->Scale(2,2);

    selectSaveSprite = new Sprite(TextureHelper::Instance()->GetTexture(TextureHelper::Glass),0,0,64,64);
    selectSaveSprite->Scale(7,0.6f);

    lamecraftSprite = new Sprite(TextureHelper::Instance()->GetTexture(TextureHelper::lameCraft),0,0,256,64);
    lamecraftSprite->Scale(1.5f,1.5f);
    lamecraftSprite->SetPosition(240,50);

    Panorama1Sprite = new Sprite(TextureHelper::Instance()->GetTexture(TextureHelper::Panorama1));
    Panorama1Sprite->SetPosition(240,136);

    Panorama2Sprite = new Sprite(TextureHelper::Instance()->GetTexture(TextureHelper::Panorama2));
    Panorama2Sprite->SetPosition(240,136);

    Panorama3Sprite = new Sprite(TextureHelper::Instance()->GetTexture(TextureHelper::Panorama3));
    Panorama3Sprite->SetPosition(240,136);

    Panorama4Sprite = new Sprite(TextureHelper::Instance()->GetTexture(TextureHelper::Panorama4));
    Panorama4Sprite->SetPosition(240,136);

    menuTool = new Sprite(TextureHelper::Instance()->GetTexture(TextureHelper::menuTool));
    menuTool->SetPosition(240,136);

    selectPos = 0;

    //load save info
    ScanSaveFiles("Save/");

    menuState = 0;
    loadSelectPos = 0;
    loadSavePos = 0;
    aboutPos = 0;

    //for map generation
    terrainType = 0;
    makeFlat = false;
    makeTrees = true;
    makeWater = true;
    makeCaves = true;
    makePumpkins = true;
    makeClouds = true;
    makeTypes = true;
    makeIron = true;
    makeCoal = true;
    makeGold = true;
    makeRedStone = true;
    makeDiamond = true;
    makeDirt = true;
    makeLapis = true;
    makeEmerald = true;
    makeLifeBlocks = true;
    generateSelectPose = 0;

    saveSubmenu = false;
    saveSubMenuSelect = 2;

    currentVersion = 30;

    //input helper
    InputHelper::Instance()->Init();
    InputHelper::Instance()->Load();

    animPart = 1;
    timer = 1;
}

void StateMenu::Enter()
{
    mRender->SetOrtho(0,0,0,0,0,0);
    selectPos = 0;
}

void StateMenu::CleanUp()
{

}

void StateMenu::Pause()
{

}

void StateMenu::Resume()
{
    menuState = 0;
    loadSelectPos = 0;
    loadSavePos = 0;
    mRender->SetOrtho(0,0,0,0,0,0);
}

void StateMenu::HandleEvents(StateManager* sManager)
{
    //update input
    mSystemMgr->InputUpdate();

    switch(menuState)
    {
    case 0://main menu
    {
        //if triangle button pressed the exit
        if(mSystemMgr->KeyPressed(PSP_CTRL_START))
        {
            //running = false;
            sManager->Quit();
        }

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

        if(mSystemMgr->KeyPressed(PSP_CTRL_CROSS))
        {
            if(selectPos == 0)//play state
            {
                menuState = 7;
                generateSelectPose = 0;
            }

            if(selectPos == 1)
            {
                //w teori opcje
                StateOptions *stateOptions = new StateOptions();
                stateOptions->Init();
                sManager->PushState(stateOptions);
            }
            if(selectPos == 2)
            {
                //about
                menuState = 3;
                aboutPos = 1;
            }
        }
    }
    break;
    case 1://load
    {
        if(saveSubmenu)
        {
            if(mSystemMgr->KeyPressed(PSP_CTRL_UP))
            {
                saveSubMenuSelect--;
                if(saveSubMenuSelect < 1)
                    saveSubMenuSelect = 2;

                mSoundMgr->PlayMenuSound();
            }

            if(mSystemMgr->KeyPressed(PSP_CTRL_DOWN))
            {
                saveSubMenuSelect++;
                if(saveSubMenuSelect > 2)
                    saveSubMenuSelect = 1;

                mSoundMgr->PlayMenuSound();
            }

            if(mSystemMgr->KeyPressed(PSP_CTRL_CROSS))
            {
                if(saveSubMenuSelect == 1)//remove file
                {
                    //remove file
                    if(saveFilesList.size() > 0)
                    {
                        if(saveFilesList[loadSavePos].compression)
                        {
                            //remove normal file
                            remove(saveFilesList[loadSavePos].fileName.c_str());

                            //remove compressed one
                            saveFilesList[loadSavePos].fileName += "c";
                            remove(saveFilesList[loadSavePos].fileName.c_str());

                        }
                        else
                        {
                            remove(saveFilesList[loadSavePos].fileName.c_str());
                        }

                        ScanSaveFiles("Save/");

                        loadSelectPos = 0;
                        loadSavePos = 0;
                        loadSaveStart = 0;
                        loadSaveEnd = saveFilesList.size();
                        loadSaveMax = 4;
                        if(loadSaveMax > loadSaveEnd)
                            loadSaveMax = loadSaveEnd;

                        saveSubmenu = false;
                        saveSubMenuSelect = 2;
                    }
                }
                if(saveSubMenuSelect == 2)//return
                {
                    saveSubMenuSelect = 2;
                    saveSubmenu = false;
                }
            }


        }
        else
        {
            if(mSystemMgr->KeyPressed(PSP_CTRL_UP))
            {
                loadSelectPos--;
                if(loadSelectPos < 0)
                    loadSelectPos = 2;

                mSoundMgr->PlayMenuSound();
            }

            if(mSystemMgr->KeyPressed(PSP_CTRL_DOWN))
            {
                loadSelectPos++;
                if(loadSelectPos > 2)
                    loadSelectPos = 0;

                mSoundMgr->PlayMenuSound();
            }

            if(mSystemMgr->KeyPressed(PSP_CTRL_LTRIGGER))
            {
                loadSavePos--;
                if(loadSaveEnd > 4)
                {
                    loadSaveStart--;
                    loadSaveMax--;

                    if(loadSaveMax < 4)
                    {
                        loadSaveStart = 0;
                        loadSaveMax = 4;
                    }
                }

                if(loadSavePos < 0)
                {
                    loadSavePos = saveFilesList.size() - 1;
                    loadSaveMax = loadSaveEnd;
                    loadSaveStart = loadSaveEnd - 4;
                    if(loadSaveStart < 0)
                        loadSaveStart = 0;
                }
            }

            if(mSystemMgr->KeyPressed(PSP_CTRL_RTRIGGER))
            {
                loadSavePos++;
                if(loadSavePos == loadSaveMax)
                {
                    loadSaveStart++;
                    loadSaveMax++;
                    if(loadSaveMax > loadSaveEnd)
                    {
                        loadSaveStart = loadSaveEnd - 4;
                        if(loadSaveStart < 0)
                            loadSaveStart = 0;
                        loadSaveMax = loadSaveEnd;
                    }
                }
                if(loadSavePos >= saveFilesList.size())
                {
                    loadSavePos = 0;
                    loadSaveStart = 0;
                    loadSaveMax = 4;
                    if(loadSaveMax > loadSaveEnd)
                        loadSaveMax = loadSaveEnd;
                }
            }

            if(mSystemMgr->KeyPressed(PSP_CTRL_CIRCLE))
            {
                menuState = 7;
            }

            if(mSystemMgr->KeyPressed(PSP_CTRL_CROSS))
            {
                if(loadSelectPos == 0)//play state
                {
						//load map
                    if(saveFilesList.size() > 0)
                    {
                        StatePlay *statePlay = new StatePlay();
                        LoadingScreen *loading = new LoadingScreen();
                        statePlay->LoadMap(saveFilesList[loadSavePos].fileName,saveFilesList[loadSavePos].compression);
                        statePlay->InitCamera();
                        loading->KillLoadingScreen();
                        delete loading;
                        sManager->PushState(statePlay);
                    }

                }
                if(loadSelectPos == 1)//daelete save
                {
                    if(saveFilesList.size() > 0)
                    {
                        saveSubmenu = true;
                        saveSubMenuSelect = 2;
                    }
                }
                if(loadSelectPos == 2)
                {
                    menuState = 7;

                }
            }
        }
    }
    break;
    case 3://about
    {
        if(mSystemMgr->KeyPressed(PSP_CTRL_UP))
        {
            aboutPos--;
            if(aboutPos < 0)
                aboutPos = 1;

            mSoundMgr->PlayMenuSound();
        }

        if(mSystemMgr->KeyPressed(PSP_CTRL_DOWN))
        {
            aboutPos++;
            if(aboutPos > 1)
                aboutPos = 0;

            mSoundMgr->PlayMenuSound();
        }

        if(mSystemMgr->KeyPressed(PSP_CTRL_CROSS))
        {
            if(aboutPos == 1)
            {
                menuState = 0;
            }
            if(aboutPos == 0)
            {
                //checking for new update
                NetworkManager::Instance()->Init();
                //initialize connection
                if(NetworkManager::Instance()->InitializeConnection())
                {
                    //show network dialog and connect to ap
                    if(SystemManager::Instance()->ShowNetworkDialog())
                    {
                        //download update info
                        if(NetworkManager::Instance()->GetFile("http://drakon.ixan.net/psp/version.txt","version.txt"))
                        {
                            //check what version is inside
                            int fileVersion = 0;
                            FILE * pFile;
                            pFile = fopen("version.txt","r");
                            if (pFile!=NULL)
                            {
                                char buffer[3];
                                fread(buffer,1,3,pFile);
                                fileVersion = atoi(buffer);
                                fclose (pFile);

                                if(fileVersion > currentVersion)
                                {
                                    SystemManager::Instance()->ShowMessage("There is new version!!!");

                                    //ask question if user want to download updater
                                    if(SystemManager::Instance()->ShowMessageYesNo("Do you want to dowload LameCraft updater?") == 1)
                                    {
                                        //make new directory
                                        mkdir("ms0:/PSP/GAME/LameUpdater",777);
                                        //download updater there
                                        NetworkManager::Instance()->GetFile("http://drakon.ixan.net/psp/updater/EBOOT.PBP","ms0:/PSP/GAME/LameUpdater/EBOOT.PBP");
                                        //
                                        SystemManager::Instance()->ShowMessage("LameUpdater was installed.");
                                    }
                                }
                                else
                                {
                                    SystemManager::Instance()->ShowMessage("You have latest version of the game.");
                                }
                            }
                            else
                            {
                                SystemManager::Instance()->ShowMessage("Can't open version.txt .");
                            }
                        }
                        else
                        {
                            SystemManager::Instance()->ShowMessage("Can't download update info.");
                        }
                    }
                    else
                    {
                        SystemManager::Instance()->ShowMessage("You must connect to AP.");
                    }
                }
                else
                {
                    SystemManager::Instance()->ShowMessage("Can't initialize network.");
                }

                //turn off connection
                NetworkManager::Instance()->ShutDownConnection();
            }
        }

        if(mSystemMgr->KeyPressed(PSP_CTRL_CIRCLE))
        {
            menuState = 0;
        }
    }
    break;
    case 4://chooose to generate randomly or marametric
    {




        if(mSystemMgr->KeyPressed(PSP_CTRL_UP))
        {
            generateSelectPose--;
            if(generateSelectPose < 0)
                generateSelectPose = 2;

            mSoundMgr->PlayMenuSound();
        }

        if(mSystemMgr->KeyPressed(PSP_CTRL_DOWN))
        {
            generateSelectPose++;
            if(generateSelectPose > 2)
                generateSelectPose = 0;

            mSoundMgr->PlayMenuSound();
        }

        if(mSystemMgr->KeyPressed(PSP_CTRL_CIRCLE))
        {
            generateSelectPose = 0;
            menuState = 7;
        }

        if(mSystemMgr->KeyPressed(PSP_CTRL_CROSS))
        {
            if(generateSelectPose == 0)
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
                    StatePlay *statePlay = new StatePlay();
                    LoadingScreen *loading = new LoadingScreen();
                    statePlay->InitParametric(terrainType,makeFlat,makeTrees,makeWater,makeCaves,makePumpkins,makeClouds,makeTypes,makeIron,makeCoal,makeGold,makeRedStone,makeDiamond,makeDirt,makeLapis,makeEmerald,makeLifeBlocks);
                    loading->KillLoadingScreen();
                    delete loading;
                    statePlay->InitCamera();
                    statePlay->SetWorldAndSaveName(newWorldName,nextSaveFileName);
                    sManager->PushState(statePlay);

                }
            }

            if(generateSelectPose == 1)
            {
                generateSelectPose = 0;
                menuState = 5;

                terrainType = 0;
                makeFlat = false;
                makeTrees = true;
                makeWater = true;
                makeCaves = true;
                makePumpkins = true;
                makeClouds = true;
                makeTypes = true;
                makeIron = true;
                makeCoal = true;
                makeGold = true;
                makeRedStone = true;
                makeDiamond = true;
                makeDirt = true;
                makeLapis = true;
                makeEmerald = true;
                makeLifeBlocks = true;
            }
            if(generateSelectPose == 2)
            {
                generateSelectPose = 0;
                menuState = 7;
            }
        }
    }
    break;
    case 5://parametric terrain
    {


        if(mSystemMgr->KeyPressed(PSP_CTRL_UP))
        {
            generateSelectPose--;
            if(generateSelectPose < 0)
                generateSelectPose = 5;

            mSoundMgr->PlayMenuSound();
        }

        if(mSystemMgr->KeyPressed(PSP_CTRL_DOWN))
        {
            generateSelectPose++;
            if(generateSelectPose > 5)
                generateSelectPose = 0;

            mSoundMgr->PlayMenuSound();
        }

        if(mSystemMgr->KeyPressed(PSP_CTRL_CIRCLE))
        {
            generateSelectPose = 0;
            menuState = 4;
        }

        if(mSystemMgr->KeyPressed(PSP_CTRL_CROSS))
        {
            if(generateSelectPose == 0)
            {
                    //push new state
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
                    StatePlay *statePlay = new StatePlay();
                    LoadingScreen *loading = new LoadingScreen();
                    statePlay->InitParametric(terrainType,makeFlat,makeTrees,makeWater,makeCaves,makePumpkins,makeClouds,makeTypes,makeIron,makeCoal,makeGold,makeRedStone,makeDiamond,makeDirt,makeLapis,makeEmerald,makeLifeBlocks);
                    loading->KillLoadingScreen();
                    delete loading;
                    statePlay->InitCamera();
                    statePlay->SetWorldAndSaveName(newWorldName,nextSaveFileName);
                    sManager->PushState(statePlay);

                }
            }

            if(generateSelectPose == 1)
            {
                terrainType++;

                if(terrainType > 9)
                    terrainType = 0;

                if(terrainType == 5)
                {
                     makeFlat = false;
                }
                if(terrainType == 7)
                {
                    makeFlat = false;
                }
            }
            if(generateSelectPose == 2)
            {
                makeFlat = !makeFlat;

                if(makeFlat)
                {
                    terrainType = 6;
                    makeWater = false;
                    makeTrees = false;
                    makeTypes = false;
                }
            }

            if(generateSelectPose == 3)
            {
                makeTrees = !makeTrees;
                 makeTypes = !makeTypes;

                 if(makeTrees)
                {
                    makeFlat = false;
                }
                if(makeTypes)
                {
                    makeFlat = false;
                }
            }

            if(generateSelectPose == 4)
            {
                //generate parametric terrain
                makeWater = !makeWater;

                //don't make water type terrain without hills
                if(makeWater)
                {
                    makeFlat = false;
                }
            }

            if(generateSelectPose == 5)
            {
                makeCaves = !makeCaves;
            }
        }
    }
    break;
    case 6://check new version menu
    {

    }
    break;
    case 7://load or new map
    {
         if(mSystemMgr->KeyPressed(PSP_CTRL_UP))
        {
            generateSelectPose--;
            if(generateSelectPose < 0)
                generateSelectPose = 1;

            mSoundMgr->PlayMenuSound();
        }

        if(mSystemMgr->KeyPressed(PSP_CTRL_DOWN))
        {
            generateSelectPose++;
            if(generateSelectPose > 1)
                generateSelectPose = 0;

            mSoundMgr->PlayMenuSound();
        }

        if(mSystemMgr->KeyPressed(PSP_CTRL_CIRCLE))
        {
            generateSelectPose = 0;
            menuState = 0;
        }

        if(mSystemMgr->KeyPressed(PSP_CTRL_CROSS))
        {
            if(generateSelectPose == 0) //new game
            {
                 generateSelectPose = 0;
                 menuState = 4;

            }

            if(generateSelectPose == 1) //load game
            {
                ScanSaveFiles("Save/");

                menuState = 1;
                loadSelectPos = 0;
                loadSavePos = 0;
                loadSaveStart = 0;
                loadSaveEnd = saveFilesList.size();
                loadSaveMax = 4;
                if(loadSaveMax > loadSaveEnd)
                loadSaveMax = loadSaveEnd;
            }
        }
    }
    break;
     case 8://survival or creative
    {
         if(mSystemMgr->KeyPressed(PSP_CTRL_UP))
        {
            generateSelectPose--;
            if(generateSelectPose < 0)
                generateSelectPose = 1;

            mSoundMgr->PlayMenuSound();
        }

        if(mSystemMgr->KeyPressed(PSP_CTRL_DOWN))
        {
            generateSelectPose++;
            if(generateSelectPose > 1)
                generateSelectPose = 0;

            mSoundMgr->PlayMenuSound();
        }

        if(mSystemMgr->KeyPressed(PSP_CTRL_CIRCLE))
        {
            generateSelectPose = 0;
            menuState = 0;
        }

        if(mSystemMgr->KeyPressed(PSP_CTRL_CROSS))
        {
            if(generateSelectPose == 0) //survival
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
                    StatePlay *statePlay = new StatePlay();
                    LoadingScreen *loading = new LoadingScreen();
                    statePlay->InitParametric(terrainType,makeFlat,makeTrees,makeWater,makeCaves,makePumpkins,makeClouds,makeTypes,makeIron,makeCoal,makeGold,makeRedStone,makeDiamond,makeDirt,makeLapis,makeEmerald,makeLifeBlocks);
                    loading->KillLoadingScreen();
                    delete loading;
                    statePlay->InitCamera();
                    statePlay->SetWorldAndSaveName(newWorldName,nextSaveFileName);
                    sManager->PushState(statePlay);

                }
            }

            if(generateSelectPose == 1) //creative
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
                    StatePlay *statePlay = new StatePlay();
                    LoadingScreen *loading = new LoadingScreen();
                    statePlay->InitParametric(terrainType,makeFlat,makeTrees,makeWater,makeCaves,makePumpkins,makeClouds,makeTypes,makeIron,makeCoal,makeGold,makeRedStone,makeDiamond,makeDirt,makeLapis,makeEmerald,makeLifeBlocks);
                    loading->KillLoadingScreen();
                    delete loading;
                    statePlay->InitCamera();
                    statePlay->SetWorldAndSaveName(newWorldName,nextSaveFileName);
                    sManager->PushState(statePlay);

                }
            }
        }
    }
    break;
    }

}

void StateMenu::Update(StateManager* sManager)
{
    timer++;

    if(timer < 800)
    {
        animPart = 1;
    }
    else if(timer > 800 && timer < 1600)
    {
        animPart = 2;
    }
    else if(timer > 1600 && timer < 2400)
    {
        animPart = 3;
    }
    else if(timer > 2400 && timer < 3200)
    {
        animPart = 4;
    }
    else if(timer > 3200)
    {
        timer = 1;
        animPart = 1;
    }

}

void StateMenu::Draw(StateManager* sManager)
{
    //start rendering
    mRender->StartFrame();

    switch(menuState)
    {
    case 0://main menu
    {
        sceGuDisable(GU_DEPTH_TEST);
        sceGuEnable(GU_BLEND);
        sceGuColor(GU_COLOR(1,1,1,1.0f));

        if(animPart == 1)
        {
            Panorama1Sprite->SetPosition(240,136);
            Panorama1Sprite->Draw();
        }
        else if(animPart == 2)
        {
            Panorama2Sprite->SetPosition(240,136);
            Panorama2Sprite->Draw();
        }
        else if (animPart == 3)
        {
            Panorama3Sprite->SetPosition(240,136);
            Panorama3Sprite->Draw();
        }
        else if(animPart == 4)
        {
            Panorama4Sprite->SetPosition(240,136);
            Panorama4Sprite->Draw();
        }

        //logo
        lamecraftSprite->Draw();

        //singlePlayer
        buttonSprite->SetPosition(240,120);
        buttonSprite->Draw();

        //about
        buttonSprite->SetPosition(240,160);
        buttonSprite->Draw();

        //options
        buttonSprite->SetPosition(240,200);
        buttonSprite->Draw();

        //selected button
        sbuttonSprite->SetPosition(240,(selectPos * 40) + 120);
        sbuttonSprite->Draw();

        sceGuDisable(GU_BLEND);
        sceGuEnable(GU_DEPTH_TEST);

        //draw subtitles on buttons

        mRender->DebugPrint(240,125,"SinglePlayer");
        mRender->DebugPrint(240,165,"Options");
        mRender->DebugPrint(240,205,"About");

        mRender->DebugPrint(240,265,"MCPSPE v0.3 - Gnu GPL v2 or later");

        //Text
        float time_s = ((float)(clock() % CLOCKS_PER_SEC)) / ((float)CLOCKS_PER_SEC);
        //mRender->DebugPrint(240,50,"Time: %f", time_s);
        float fontsize = (time_s < 0.5f) ? time_s*511 : (1.0f-time_s)*511;
        //mRender->DebugPrint(240,25,"Size: %f", (fontsize/500));

        int randomTextNumber = 0;
        char *randomText;

        //Randomly generate the text number - because is in "while" not working yet
        //randomTextNumber = rand() % 2; // 0-2

        switch (randomTextNumber)
        {
        case 0:
            randomText = "Crafting test!";
            break;
        case 1:
            randomText = "It's free!";
            break;
        case 2:
            randomText = "Casual gaming!";
            break;
        case 3:
            randomText = "Fan fiction";
            break;
        case 4:
            randomText = "!STOP ACTA! ";
            break;
        case 5:
            randomText = "Like a boss ";
            break;
        case 6:
            randomText = "MC forever";
            break;
        }

        mRender->SetFontStyle( (fontsize/500+0.5) ,0xFF00FFFF,0xFF000000,0x00000200);
        mRender->DebugPrint(400,80,randomText);

        //Reset de original font for next menu items
        mRender->SetFontStyle(0.5f,0xFFFFFFFF,0xFF000000,0x00000200);
    }
    break;
    case 1://load menu
    {
        sceGuDisable(GU_DEPTH_TEST);
        sceGuEnable(GU_BLEND);
        sceGuColor(GU_COLOR(1,1,1,1.0f));

        for(int x = 0; x < 16; x++)
        {
            for(int y = 0; y < 9; y++)
            {
                backSprite->SetPosition(x*32,y*32);
                backSprite->Draw();
            }
        }

        menuTool->Draw();

        //select sprite
        if(saveFilesList.size() > 0)
        {
            selectSaveSprite->SetPosition(240,50 + (loadSavePos * 40) - (loadSaveStart * 40));
            selectSaveSprite->Draw();
        }

        //save files
        for(int i = loadSaveStart; i <loadSaveMax; i++)
        {
            if(loadSavePos == i)
            {
                mRender->SetFontStyle(1.0f,0xFF000000,0xFFFFFFFF,0x00000000);
                mRender->DebugPrint(30,50 + (i * 40) - (loadSaveStart * 40),"%s",saveFilesList[i].worldName);

                mRender->SetFontStyle(0.7f,0xFF7F7F7F,0xFF000000,0x00000000);
                mRender->DebugPrint(40,65 + (i * 40) - (loadSaveStart * 40),"%s",saveFilesList[i].fileName.c_str());
            }
            else
            {
                mRender->SetFontStyle(0.8f,0xFFFFFFFF,0xFF000000,0x00000000);
                mRender->DebugPrint(30,50 + (i * 40) - (loadSaveStart * 40),"%s",saveFilesList[i].worldName);

                mRender->SetFontStyle(0.5f,0xFF7F7F7F,0xFF000000,0x00000000);
                mRender->DebugPrint(40,60 + (i * 40) - (loadSaveStart * 40),"%s",saveFilesList[i].fileName.c_str());
            }

        }

        //play
        buttonSprite->SetPosition(240,210);
        buttonSprite->Draw();

        //delete
        buttonSprite->SetPosition(240,235);
        buttonSprite->Draw();

        //back
        buttonSprite->SetPosition(240,260);
        buttonSprite->Draw();

        //selected button
        if(saveSubmenu)
        {
            sbuttonSprite->SetPosition(240,(saveSubMenuSelect * 25) + 210);
        }
        else
        {
            sbuttonSprite->SetPosition(240,(loadSelectPos * 25) + 210);
        }
        sbuttonSprite->Draw();

        sceGuDisable(GU_BLEND);
        sceGuEnable(GU_DEPTH_TEST);

        mRender->SetFontStyle(0.5f,0xFFFFFFFF,0xFF000000,0x00000200);
        //draw subtitles on buttons
        mRender->DebugPrint(240,20,"LOAD WORLD");

        if(saveSubmenu)
        {
            mRender->DebugPrint(240,215,"Are you sure?");
            mRender->DebugPrint(240,240,"Yes");
            mRender->DebugPrint(240,265,"No");
        }
        else
        {
            mRender->DebugPrint(240,215,"Play");
            mRender->DebugPrint(240,240,"Delete");
            mRender->DebugPrint(240,265,"Back");
        }
    }
    break;
    case 3://about
    {


        sceGuDisable(GU_DEPTH_TEST);
        sceGuEnable(GU_BLEND);
        sceGuColor(GU_COLOR(1,1,1,1.0f));

        for(int x = 0; x < 16; x++)
        {
            for(int y = 0; y < 9; y++)
            {
                backSprite->SetPosition(x*32,y*32);
                backSprite->Draw();
            }
        }

        menuTool->Draw();

        //check for update
        buttonSprite->SetPosition(240,235);
        buttonSprite->Draw();

        buttonSprite->SetPosition(240,260);
        buttonSprite->Draw();

        //back
        sbuttonSprite->SetPosition(240,(aboutPos * 25) + 235);
        sbuttonSprite->Draw();

        sceGuDisable(GU_BLEND);
        sceGuEnable(GU_DEPTH_TEST);

        //about text
        mRender->SetFontStyle(0.7f,0xFFFFFFFF,0xFF000000,0x00000000);
        mRender->DebugPrint(40,100,"code:        Marcin Ploska(Drakon)");
        mRender->DebugPrint(40,120,"graphics:    Mojang");
        mRender->DebugPrint(40,140,"modder:      Michal5575");
        mRender->DebugPrint(40,160,"www:         michal5575.cz");
        mRender->DebugPrint(40,180,"rev:         MCPSPE v0.3");
		mRender->DebugPrint(40,200,"Testers:  Everyone with DevRel");

        //button text
        mRender->SetFontStyle(0.5f,0xFFFFFFFF,0xFF000000,0x00000200);
        mRender->DebugPrint(240,240,"Check for update");
        mRender->DebugPrint(240,265,"Back");
    }
    break;
    case 4://choose generation type
    {


        sceGuDisable(GU_DEPTH_TEST);
        sceGuEnable(GU_BLEND);
        sceGuColor(GU_COLOR(1,1,1,1.0f));

        for(int x = 0; x < 16; x++)
        {
            for(int y = 0; y < 9; y++)
            {
                backSprite->SetPosition(x*32,y*32);
                backSprite->Draw();
            }
        }

        menuTool->Draw();

        //logo
        lamecraftSprite->Draw();

        //Randomly
        buttonSprite->SetPosition(240,120);
        buttonSprite->Draw();

        //Parametric
        buttonSprite->SetPosition(240,160);
        buttonSprite->Draw();

        //back
        buttonSprite->SetPosition(240,200);
        buttonSprite->Draw();

        //selected button
        sbuttonSprite->SetPosition(240,(generateSelectPose * 40) + 120);
        sbuttonSprite->Draw();

        sceGuDisable(GU_BLEND);
        sceGuEnable(GU_DEPTH_TEST);

        //draw subtitles on buttons

        mRender->DebugPrint(240,125,"Random Terrain");
        mRender->DebugPrint(240,165,"Parametric Terrain");
        mRender->DebugPrint(240,205,"Back");
    }
    break;
    case 5://paramateric view
    {


        sceGuDisable(GU_DEPTH_TEST);
        sceGuEnable(GU_BLEND);
        sceGuColor(GU_COLOR(1,1,1,1.0f));

        for(int x = 0; x < 16; x++)
        {
            for(int y = 0; y < 9; y++)
            {
                backSprite->SetPosition(x*32,y*32);
                backSprite->Draw();
            }
        }

        menuTool->Draw();

        //logo
        lamecraftSprite->Draw();

        //generate
        buttonSprite->SetPosition(240,95);
        buttonSprite->Draw();

        //terrain type
        buttonSprite->SetPosition(240,120);
        buttonSprite->Draw();

        //flat/hills?
        buttonSprite->SetPosition(240,145);
        buttonSprite->Draw();

        //Structures
        buttonSprite->SetPosition(240,170);
        buttonSprite->Draw();

        //water
        buttonSprite->SetPosition(240,195);
        buttonSprite->Draw();

        //caves
        buttonSprite->SetPosition(240,220);
        buttonSprite->Draw();

        //selected button
        sbuttonSprite->SetPosition(240,(generateSelectPose * 25) + 95);
        sbuttonSprite->Draw();

        sceGuDisable(GU_BLEND);
        sceGuEnable(GU_DEPTH_TEST);

        //draw subtitles on buttons
        mRender->DebugPrint(240,100,"Generate");

        if(terrainType ==0)
            mRender->DebugPrint(240,125,"Biome: Normal Forrest");
        else if(terrainType == 1)
            mRender->DebugPrint(240,125,"Biome: Winter Forrest");
        else if(terrainType == 2)
            mRender->DebugPrint(240,125,"Biome: Desert");
        else if(terrainType == 3)
            mRender->DebugPrint(240,125,"Biome: Mushroom");
        else if(terrainType == 4)
            mRender->DebugPrint(240,125,"Biome: Nether");
        else if(terrainType == 5)
            mRender->DebugPrint(240,125,"Biome: Sky lands");
        else if(terrainType == 6)
            mRender->DebugPrint(240,125,"Biome: Normal meadow");
        else if(terrainType == 7)
            mRender->DebugPrint(240,125,"Biome: Winter meadow");
        else if(terrainType == 8)
            mRender->DebugPrint(240,125,"Biome: Extreme hills");
        else if(terrainType == 9)
            mRender->DebugPrint(240,125,"Biome: WasteLand");




        makeFlat == true ?  mRender->DebugPrint(240,150,"Flat terrain"):mRender->DebugPrint(240,150,"Terrain with hills");
        makeTrees,makeTypes == true ? mRender->DebugPrint(240,175,"Trees : ON"):mRender->DebugPrint(240,175,"Trees : OFF");
        makeWater == true ? mRender->DebugPrint(240,200,"Water : ON"):mRender->DebugPrint(240,200,"Water : OFF");
        makeCaves == true ? mRender->DebugPrint(240,225,"Caves : ON"):mRender->DebugPrint(240,225,"Caves : OFF");
    }
    break;
    case 7://New or load map
    {


        sceGuDisable(GU_DEPTH_TEST);
        sceGuEnable(GU_BLEND);
        sceGuColor(GU_COLOR(1,1,1,1.0f));

        for(int x = 0; x < 16; x++)
        {
            for(int y = 0; y < 9; y++)
            {
                backSprite->SetPosition(x*32,y*32);
                backSprite->Draw();
            }
        }

        menuTool->Draw();

        //logo
        lamecraftSprite->Draw();

        //Randomly
        buttonSprite->SetPosition(240,120);
        buttonSprite->Draw();

        //Parametric
        buttonSprite->SetPosition(240,160);
        buttonSprite->Draw();

        //selected button
        sbuttonSprite->SetPosition(240,(generateSelectPose * 40) + 120);
        sbuttonSprite->Draw();

        sceGuDisable(GU_BLEND);
        sceGuEnable(GU_DEPTH_TEST);

        //draw subtitles on buttons

        mRender->DebugPrint(240,125,"New world");
        mRender->DebugPrint(240,165,"Load world");
    }
    break;
    }

    //draw debug text at the end
    /*mRender->DebugPrint(40,30,"cpu: %d%%",mRender->GetCpuUsage());
    mRender->DebugPrint(40,40,"gpu: %d%%",mRender->GetGpuUsage());
    mRender->DebugPrint(40,50,"saves: %d",saveFilesList.size());*/

    //mRender->SetFontStyle(0.5f,0xFFFFFFFF,0xFF000000,0x00000400);
    //mRender->DebugPrint(475,15,"CraftSite.pl Edition");
    //mRender->SetFontStyle(0.5f,0xFFFFFFFF,0xFF000000,0x00000200);

    //end frame
    mRender->EndFrame();
}

//additional functions
void StateMenu::ScanSaveFiles(const char* dirName)
{
    //clear list with save files
    saveFilesList.clear();

    DIR *Dir;
    struct dirent *DirEntry;
    Dir = opendir(dirName);

    while((DirEntry = readdir(Dir)) != NULL)
    {
        if ( DirEntry->d_stat.st_attr & FIO_SO_IFREG)
        {
            SaveFile newSaveFile;
            std::string plik = dirName;
            plik += DirEntry->d_name;
            //dont load lmsc files
            size_t found = plik.find(".lmsc");
            size_t found2 = plik.find(".LMSc");
            if(found==std::string::npos && found2==std::string::npos)//nie znaleziono
            {
                newSaveFile.fileName = plik;
                saveFilesList.push_back(newSaveFile);
            }
        }
    }

    closedir(Dir);

    /*//// this was causeing some problems
    int dfd;
    dfd = sceIoDopen(dirName);
    if(dfd > 0)
    {
    	SceIoDirent dir;

    	while(sceIoDread(dfd, &dir) > 0)
    	{
    		if(dir.d_stat.st_attr & FIO_SO_IFREG)//regular file
    		{
    			SaveFile newSaveFile;
    			std::string plik = dirName;
    			plik += dir.d_name;
    			//dont load lmsc files
    			size_t found = plik.find(".lmsc");
    			if(found==string::npos)//nie znaleziono
    			{
    				newSaveFile.fileName = plik;
    				saveFilesList.push_back(newSaveFile);
    			}
    		}
    	}

    	//close folder
    	sceIoClose(dfd);
    }*/

    //now update all info in save files
    for(unsigned int i = 0; i < saveFilesList.size(); i++)
    {
        FILE * pFile;
        pFile = fopen(saveFilesList[i].fileName.c_str(),"rb");

        if(pFile != NULL)
        {
            //version
            fread(&saveFilesList[i].saveVersion,sizeof(int),1,pFile);

            //name
            fread(saveFilesList[i].worldName,sizeof(char),50,pFile);

            if(saveFilesList[i].saveVersion >= 2)
                saveFilesList[i].compression = true;
            else
                saveFilesList[i].compression = false;

            fclose(pFile);
        }
    }

    //set next save name and numer
    nextSaveFileNumber = saveFilesList.size() + 1;
    {
        //ride thru all saves and check if i can use new name
        char liczba[3];
        sprintf(liczba,"%d",nextSaveFileNumber);
        nextSaveFileName = "Save/world";
        nextSaveFileName += liczba;
        nextSaveFileName += ".lms";

        for(unsigned int i = 0; i < saveFilesList.size(); i++)
        {
            if(nextSaveFileName.compare(saveFilesList[i].fileName) == 0)
            {
                nextSaveFileNumber+=1;
                char liczba[3];
                sprintf(liczba,"%d",nextSaveFileNumber);
                nextSaveFileName = "Save/world";
                nextSaveFileName += liczba;
                nextSaveFileName += ".lms";
            }
        }
    }
}
