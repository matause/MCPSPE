#include "CraftWorld2.h"
#include <Aurora/Graphics/RenderManager.h>
#include <Aurora/Utils/Logger.h>

#include <string.h>
#include <zlib.h>

CraftWorld::CraftWorld()
{
    WORLD_SIZE = 0;
    CHUNK_SIZE = 0;
    //
    playerZoneSize = Vector3(28,28,28);
    updateChunksSwitch = false;
    worldTime = 0.0f;
    updateChunkTimer = 0.0f;
    chunksCreatedInFrameCount = 0;
    transparentchunksCreatedInFrameCount = 0;

    //air
    blockTypes.push_back(BaseBlock());

    //normal blocks
    blockTypes.push_back(GrassBlock());
    blockTypes.push_back(DirtBlock());
    blockTypes.push_back(RockBlock());
    blockTypes.push_back(WaterBlock());
    blockTypes.push_back(GoldBlock());
    blockTypes.push_back(LadderBlock());
    blockTypes.push_back(SandBlock());
    blockTypes.push_back(WoodBlock());
    blockTypes.push_back(LeavesBlock());

    blockTypes.push_back(TNTBlock());
    blockTypes.push_back(BlackWoolBlock());
    blockTypes.push_back(RedWoolBlock());
    blockTypes.push_back(DarkGreyWoolBlock());
    blockTypes.push_back(BrownWoolBlock());
    blockTypes.push_back(LightBlackWoolBlock());
    blockTypes.push_back(PinkWoolBlock());
    blockTypes.push_back(LightGreenWoolBlock());
    blockTypes.push_back(YellowWoolBlock());

    blockTypes.push_back(BlueWoolBlock());
    blockTypes.push_back(LightBlueWoolBlock());
    blockTypes.push_back(FioletWoolBlock());
    blockTypes.push_back(PastelWoolBlock());
    blockTypes.push_back(LightFioletWoolBlock());
    blockTypes.push_back(OrangeWoolBlock());
    blockTypes.push_back(CactusBlock());
    blockTypes.push_back(AllSnowBlock());
    blockTypes.push_back(BrickBlock());

    blockTypes.push_back(CageBlock());
    blockTypes.push_back(SnowBlock());
    blockTypes.push_back(DarkWoodBlock());
    blockTypes.push_back(WhiteWoodBlock());
    blockTypes.push_back(IceBlock());
    blockTypes.push_back(CaneBlock());
    blockTypes.push_back(BoxBlock());
    blockTypes.push_back(ShelfBlock());
    blockTypes.push_back(WallBlock());

    blockTypes.push_back(DrySandBlock());
    blockTypes.push_back(SnowLewesBlock());
    blockTypes.push_back(MudBlock());
    blockTypes.push_back(GlassBlock());
    blockTypes.push_back(BrownCoailBlock());
    blockTypes.push_back(BlackCoailBlock());
    blockTypes.push_back(BlueCoailBlock());
    blockTypes.push_back(RedCoailBlock());
    blockTypes.push_back(SlamRockBlock());

    blockTypes.push_back(WaterRockBlock());
    blockTypes.push_back(JackOLantern());
    blockTypes.push_back(Torch());
    blockTypes.push_back(Door1());
    blockTypes.push_back(Door2());
    blockTypes.push_back(HalfBlocks());
    blockTypes.push_back(SandStone1());
    blockTypes.push_back(SandStone2());
    blockTypes.push_back(SandStone3());

    blockTypes.push_back(StoneBrick1());
    blockTypes.push_back(StoneBrick2());
    blockTypes.push_back(StoneBrick3());
    blockTypes.push_back(StoneBrick4());
    blockTypes.push_back(JungleWood());
    blockTypes.push_back(Planks1());
    blockTypes.push_back(Planks2());
    blockTypes.push_back(Planks3());
    blockTypes.push_back(Mycelium());

    blockTypes.push_back(Diamond());
    blockTypes.push_back(Gold());
    blockTypes.push_back(Iron());
    blockTypes.push_back(NetherBrick());
    blockTypes.push_back(Netherrack());
    blockTypes.push_back(SoulSand());
    blockTypes.push_back(Grass());
    blockTypes.push_back(MelonSeeds());
    blockTypes.push_back(JukeBox());

    blockTypes.push_back(EndStone());
    blockTypes.push_back(Pumpkin());
    blockTypes.push_back(GlowStone());
    blockTypes.push_back(GlassPane());
    blockTypes.push_back(IronBars());
    blockTypes.push_back(lilyPad());
    blockTypes.push_back(AetherPlanks());
    blockTypes.push_back(MooshroomLeaves());
    blockTypes.push_back(MooshroomWood());

    blockTypes.push_back(HalfBlock8());
    blockTypes.push_back(HalfBlock0());
    blockTypes.push_back(HalfBlock1());
    blockTypes.push_back(HalfBlock2());
    blockTypes.push_back(HalfBlock3());
    blockTypes.push_back(HalfBlock4());
    blockTypes.push_back(HalfBlock5());
    blockTypes.push_back(HalfBlock6());
    blockTypes.push_back(HalfBlock7());

    blockTypes.push_back(Cake());
    blockTypes.push_back(TrapDoor());
    blockTypes.push_back(Snow2());
    blockTypes.push_back(Table());
    blockTypes.push_back(AetherStone());
    blockTypes.push_back(MushRoomLeave());
    blockTypes.push_back(MossAetherStone());
    blockTypes.push_back(WoodPlate());
    blockTypes.push_back(StonePlate());

    blockTypes.push_back(Fence());
    blockTypes.push_back(NetherFence());
    blockTypes.push_back(CobWeb());
    blockTypes.push_back(AetherBlock6());
    blockTypes.push_back(Furnace());
    blockTypes.push_back(Crafting());
    blockTypes.push_back(JungleLeaves());
    blockTypes.push_back(WaterFlow());
    blockTypes.push_back(LampOn());

    blockTypes.push_back(GreyRock());
    blockTypes.push_back(TNT());
    blockTypes.push_back(Nuclear());
    blockTypes.push_back(Lava());
    blockTypes.push_back(Gravel());
    blockTypes.push_back(EmeraldBlock());
    blockTypes.push_back(EmeraldOre());
    blockTypes.push_back(LapisOre());
    blockTypes.push_back(LapisBlock());

    blockTypes.push_back(NoteBlock());
    blockTypes.push_back(Chest());
    blockTypes.push_back(Sapling1());
    blockTypes.push_back(Sapling2());
    blockTypes.push_back(Sapling3());
    blockTypes.push_back(endPortal());
    blockTypes.push_back(dispenser());
    blockTypes.push_back(wheat());
    blockTypes.push_back(wines());

    blockTypes.push_back(netherWarp());
    blockTypes.push_back(Fire());
    blockTypes.push_back(supriseblock());
    blockTypes.push_back(quartzBlock());
    blockTypes.push_back(quartzBlockLines());
    blockTypes.push_back(quartzBlockChiseled());
    blockTypes.push_back(quartzSlap());
    blockTypes.push_back(brickWallSlap());
    blockTypes.push_back(redStoneBlock());

    blockTypes.push_back(netherQuartz());
	blockTypes.push_back(RSLampOFF());
	blockTypes.push_back(JunglePlant());
	blockTypes.push_back(Brad0());
	blockTypes.push_back(Brad1());
	blockTypes.push_back(Pist0());
	blockTypes.push_back(Pist1());
	blockTypes.push_back(Pist2());
	blockTypes.push_back(NP());
	
	blockTypes.push_back(Caul());
	blockTypes.push_back(Art1());
	blockTypes.push_back(Art2());
	blockTypes.push_back(Art3());
	blockTypes.push_back(Art4());
	blockTypes.push_back(Art5());
	blockTypes.push_back(Art6());
	blockTypes.push_back(Art7());
	blockTypes.push_back(Art8());
	
	blockTypes.push_back(Art9());
	blockTypes.push_back(Art10());
	blockTypes.push_back(Art11());
	
	
	
		
	blockTypes.push_back(YellowF());
	blockTypes.push_back(RedF());
	blockTypes.push_back(Hay());
	blockTypes.push_back(HC0());
	blockTypes.push_back(HC1());
	blockTypes.push_back(HC2());
	blockTypes.push_back(HC3());
	blockTypes.push_back(HC4());
	
	blockTypes.push_back(HC6());
	blockTypes.push_back(HC7());
	blockTypes.push_back(HC8());
	blockTypes.push_back(HC9());
	blockTypes.push_back(HC10());
	blockTypes.push_back(HC11());
	blockTypes.push_back(HC12());
	blockTypes.push_back(HC13());
	blockTypes.push_back(HC14());
	blockTypes.push_back(HC15());
	blockTypes.push_back(HC16());
	blockTypes.push_back(SKLO());
	blockTypes.push_back(JS());
    blockTypes.push_back(RS());
    blockTypes.push_back(KOL1());
	blockTypes.push_back(KOL2());
	
	blockTypes.push_back(OBR1());
	blockTypes.push_back(OBR2());
	blockTypes.push_back(OBR3());
	blockTypes.push_back(OBR4());
	blockTypes.push_back(ColoredGlass0());
	blockTypes.push_back(ColoredGlass1());
	blockTypes.push_back(ColoredGlass2());
	blockTypes.push_back(ColoredGlass3());
	blockTypes.push_back(ColoredGlass4());
	
	blockTypes.push_back(ColoredGlass5());
	blockTypes.push_back(ColoredGlass6());
	blockTypes.push_back(ColoredGlass7());
	blockTypes.push_back(ColoredGlass8());
	blockTypes.push_back(ColoredGlass9());
	blockTypes.push_back(UserBlock0());
	blockTypes.push_back(UserBlock1());
	blockTypes.push_back(UserBlock2());
	blockTypes.push_back(UserBlock3());

    blockTypes.push_back(UserBlock4());
    blockTypes.push_back(UserBlock5());	
	blockTypes.push_back(UserBlock6());
	blockTypes.push_back(UserBlock7());
	blockTypes.push_back(UserBlock8());
	blockTypes.push_back(UserBlock9());
	blockTypes.push_back(UserBlock10());
	blockTypes.push_back(UserBlock11());
	blockTypes.push_back(UserBlock12());
	
	blockTypes.push_back(UserBlock13());
	blockTypes.push_back(UserBlock14());
	blockTypes.push_back(UserBlock15());
	blockTypes.push_back(UserBlock16());

	blockTypes.push_back(UserBlock18());
	blockTypes.push_back(UserBlock19());
	blockTypes.push_back(UserBlock20());
	blockTypes.push_back(UserBlock21());
	
	blockTypes.push_back(UserBlock22());
    blockTypes.push_back(UserBlock23());
	blockTypes.push_back(EmptyBlock0());

	
    //must be last
    blockTypes.push_back(MelonBlock());
    blockTypes.push_back(LifeBlock());
    blockTypes.push_back(EnderTop());

    blockTypes.push_back(EnderLegs());
    blockTypes.push_back(ZombieTop());
    blockTypes.push_back(ZombieLegs());
    blockTypes.push_back(TrapDoor2());
    blockTypes.push_back(Door3());
    blockTypes.push_back(Door4());
    blockTypes.push_back(Furnace2());
blockTypes.push_back(Cloud());
    blockTypes.push_back(IronBlock());

    transOrderCont = 0;
    lightShadowFactor = 0.4f;
    lightFactor = Vector3(1.0f,1.0f,1.0f);
    worldTime = 0.0f;

    worldDayTime = 12.0f;
    worldHour = 0.0f;

    freezeDayTime = false;
    worldVersion = 3;
}

CraftWorld::~CraftWorld()
{
    //delete arrays
    delete [] m_Blocks;
    delete [] m_BlockLight;

    //delete chunks
    for(unsigned int i = 0; i < mChunks.size(); i++)
    {
        delete mChunks[i];
    }
    mChunks.clear();

    //water chunks
    for(unsigned int i = 0; i < mTransparentChunks.size(); i++)
    {
        delete mTransparentChunks[i];
    }
    mTransparentChunks.clear();


    //delete block vertices
    blockTypes.clear();

}

void CraftWorld::SaveCompressedWorld(std::string  filename)
{
    //first save version and name on normal file
    FILE * pFile;
    pFile = fopen(filename.c_str(),"wb");

    if(pFile == NULL)
        return;

    //version
    fwrite(&worldVersion,sizeof(int),1,pFile);

    //name
    fwrite(worldName,sizeof(char),50,pFile);

    //close file
    fclose(pFile);

    //now save compressed map info
    filename = filename + "c";

    //open file
    gzFile saveFile;
    saveFile = gzopen(filename.c_str(),"wb");
    if(saveFile == 0)
        return;

    //player pos
    gzwrite(saveFile, &playerPos.x,sizeof(float));
    gzwrite(saveFile, &playerPos.y,sizeof(float));
    gzwrite(saveFile, &playerPos.z,sizeof(float));

    //size
    gzwrite(saveFile, &WORLD_SIZE,sizeof(int));

    //chunksize
    gzwrite(saveFile, &CHUNK_SIZE,sizeof(int));

    //cubes
    gzwrite(saveFile, m_Blocks,sizeof(unsigned char)*(WORLD_SIZE * WORLD_SIZE * WORLD_SIZE));

    //light
    gzwrite(saveFile, m_BlockLight,sizeof(unsigned char)*(WORLD_SIZE * WORLD_SIZE * WORLD_SIZE));

    //settings
    gzwrite(saveFile, m_BlockSettings,sizeof(unsigned char)*(WORLD_SIZE * WORLD_SIZE * WORLD_SIZE));

    //world time
    gzwrite(saveFile, &worldDayTime,sizeof(float));

    //freeze world time
    gzwrite(saveFile, &freezeDayTime,sizeof(bool));

    //sun time
    gzwrite(saveFile, &sunTime,sizeof(float));

    //Health
    gzwrite(saveFile, &player.health,sizeof(float));

    //Maxhealth
    gzwrite(saveFile, &player.maxhealth,sizeof(float));

    //numApples
    gzwrite(saveFile, &player.Apples,sizeof(float));
	
	//numGrass
	gzwrite(saveFile, &player.GrassNumber,sizeof(float));
	
	//numDirt
	gzwrite(saveFile, &player.DirtNumber,sizeof(float));
	
	//numLog
	gzwrite(saveFile, &player.LogNumber,sizeof(float));
	
	//numPlank
	gzwrite(saveFile, &player.PlankNumber,sizeof(float));

    //num melons
    gzwrite(saveFile, &player.melons,sizeof(float));

    //hunger
    gzwrite(saveFile, &player.hunger,sizeof(float));

    //score
    gzwrite(saveFile, &player.score,sizeof(float));

    //num mobs
    gzwrite(saveFile, &player.NumMobs,sizeof(float));

    //gamemode
    gzwrite(saveFile, &player.gamemode,sizeof(float));

    //jump height
    gzwrite(saveFile, &player.jumpHeight,sizeof(float));

    //walk speed
    gzwrite(saveFile, &player.walkSpeed,sizeof(float));

    //fire resistance
    gzwrite(saveFile, &player.fireResistance,sizeof(float));

    //close file
    gzclose(saveFile);
    saveFile=0;
}

void CraftWorld::LoadWorld(const char *filename)
{
    FILE * pFile;
    pFile = fopen(filename,"rb");

    if(pFile == NULL)
        return;

    //version
    fread(&worldVersion,sizeof(int),1,pFile);

    //name
    fread(worldName,sizeof(char),50,pFile);

    //size
    fread(&WORLD_SIZE,sizeof(int),1,pFile);

    //chunksize
    fread(&CHUNK_SIZE,sizeof(int),1,pFile);

    //cubes
    m_Blocks = new block_t[WORLD_SIZE * WORLD_SIZE * WORLD_SIZE];
    fread(m_Blocks,sizeof(unsigned char),(WORLD_SIZE * WORLD_SIZE * WORLD_SIZE),pFile);

    //light
    m_BlockLight = new block_t[WORLD_SIZE * WORLD_SIZE * WORLD_SIZE];
    fread(m_BlockLight,sizeof(unsigned char),(WORLD_SIZE * WORLD_SIZE * WORLD_SIZE),pFile);

    m_BlockSettings = new block_t[WORLD_SIZE * WORLD_SIZE * WORLD_SIZE];
    memset(m_BlockSettings, 0, sizeof(block_t) * WORLD_SIZE * WORLD_SIZE * WORLD_SIZE);

    //close file
    fclose(pFile);
}

void CraftWorld::LoadCompressedWorld(std::string  filename)
{
    //load normal save info
    FILE * pFile;
    pFile = fopen(filename.c_str(),"rb");

    if(pFile == NULL)
        return;

    //version
    fread(&worldVersion,sizeof(int),1,pFile);

    //name
    fread(worldName,sizeof(char),50,pFile);
    //close file
    fclose(pFile);

    //load compressed map data
    filename = filename + "c";

    //open file
    gzFile saveFile;
    saveFile = gzopen(filename.c_str(),"rb");
    if(saveFile == 0)
        return;

    //player pos
    gzread(saveFile, &playerPos.x,sizeof(float));
    gzread(saveFile, &playerPos.y,sizeof(float));
    gzread(saveFile, &playerPos.z,sizeof(float));

    //size
    gzread(saveFile, &WORLD_SIZE,sizeof(int));

    //chunksize
    gzread(saveFile, &CHUNK_SIZE,sizeof(int));

    //cubes
    m_Blocks = new block_t[WORLD_SIZE * WORLD_SIZE * WORLD_SIZE];
    gzread(saveFile, m_Blocks,sizeof(unsigned char)*(WORLD_SIZE * WORLD_SIZE * WORLD_SIZE));

    //light
    m_BlockLight = new block_t[WORLD_SIZE * WORLD_SIZE * WORLD_SIZE];
    gzread(saveFile, m_BlockLight,sizeof(unsigned char)*(WORLD_SIZE * WORLD_SIZE * WORLD_SIZE));

    //settings
    m_BlockSettings = new block_t[WORLD_SIZE * WORLD_SIZE * WORLD_SIZE];
    if(worldVersion >= 3)
    {
        //settings
        gzread(saveFile, m_BlockSettings,sizeof(unsigned char)*(WORLD_SIZE * WORLD_SIZE * WORLD_SIZE));

        //world time
        gzread(saveFile, &worldDayTime,sizeof(float));

        //freeze world time?
        gzread(saveFile, &freezeDayTime,sizeof(bool));

        //sun time
        gzread(saveFile, &sunTime,sizeof(float));

        //Health
        gzread(saveFile, &player.health,sizeof(float));

        //MaxHealth
        gzread(saveFile, &player.maxhealth,sizeof(float));

        //numApples
        gzread(saveFile, &player.Apples,sizeof(float));

		//numGrass
		gzread(saveFile, &player.GrassNumber,sizeof(float));
		
		gzread(saveFile, &player.DirtNumber,sizeof(float));
		
		
		gzread(saveFile, &player.LogNumber,sizeof(float));
		
		gzread(saveFile, &player.PlankNumber,sizeof(float));
        //num melons
        gzread(saveFile, &player.melons,sizeof(float));

        //hunger
        gzread(saveFile, &player.hunger,sizeof(float));

        //score
        gzread(saveFile, &player.score,sizeof(float));

        //num mobs
        gzread(saveFile, &player.NumMobs,sizeof(float));

        //gamemode
        gzread(saveFile, &player.gamemode,sizeof(float));

        //jump height
        gzread(saveFile, &player.jumpHeight,sizeof(float));

         //walk speed
        gzread(saveFile, &player.walkSpeed,sizeof(float));

        //walk speed
        gzread(saveFile, &player.fireResistance,sizeof(float));
    }
    else
    {
        memset(m_BlockSettings, 0, sizeof(block_t) * WORLD_SIZE * WORLD_SIZE * WORLD_SIZE);
    }

    //close file
    gzclose(saveFile);
    saveFile=0;
}

void CraftWorld::initWorld(int worldSize,int chunkSize)
{
    //inicjuj mape
    WORLD_SIZE = worldSize;
    CHUNK_SIZE = chunkSize;

    m_Blocks = new block_t[WORLD_SIZE * WORLD_SIZE * WORLD_SIZE];
    memset(m_Blocks, 0, sizeof(block_t) * WORLD_SIZE * WORLD_SIZE * WORLD_SIZE);

    m_BlockLight = new block_t[WORLD_SIZE * WORLD_SIZE * WORLD_SIZE];
    memset(m_BlockLight, 255, sizeof(block_t) * WORLD_SIZE * WORLD_SIZE * WORLD_SIZE);

    m_BlockSettings = new block_t[WORLD_SIZE * WORLD_SIZE * WORLD_SIZE];
    memset(m_BlockSettings, 0, sizeof(block_t) * WORLD_SIZE * WORLD_SIZE * WORLD_SIZE);
}

void CraftWorld::initWorldBlocksLight()
{
    int x, y, z;
    block_t Light;
    block_t DeltaLight = 16;

    for (z = 0; z < WORLD_SIZE; ++z)
    {
        for (x = 0; x < WORLD_SIZE; ++x)
        {
            Light = 255;

            for (y = WORLD_SIZE - 1; y >= 0; --y)
            {
                GetBlockLight(x, y, z) = Light;

                if (GetBlock(x, y, z) != 0)
                {
                    if (Light >= DeltaLight)
                        Light -= DeltaLight;
                }
            }
        }
    }
}

void CraftWorld::InitLightValues()
{
    lightAngle = 10;
    lightColor = Vector3(1, 1, 1);
    fogColor = lightColor * 0.8f;
    ambientColor = lightColor / 3.0f;

    //light face factors
    if (lightAngle >= 0 &&lightAngle <= 180)
        factor1 = sinf(lightAngle * 3.1415926f / 180.0f);
    else
        factor1 = 0.0f;

    if(factor1 < 0.1f)
        factor1 = 0.1f;

    if (lightAngle >= 315 || lightAngle <= 45)
        factor2 = fabs(cosf(lightAngle * 3.1415926f / 180.0f));
    else
        factor2 = fabs(sinf(lightAngle * 3.1415926f / 180.0f));

    if (factor2 < 0.1f)
        factor2 = 0.1f;

    if (lightAngle >= 135 && lightAngle <= 225)
        factor3 = fabs(cosf(lightAngle * 3.1415926f / 180.0f));
    else
        factor3 = fabs(sinf(lightAngle * 3.1415926f / 180.0f));

    if (factor3 < 0.1f)
        factor3 = 0.1f;
}

void CraftWorld::SetWolrdTime(float time)
{
    //6am = SunRise
    //Light is symmetric about noon
    //4am-8am = dawn
    //4am color = (0.1, 0.1, 0.1)
    //6am color = (1, 0.6, 0.04)
    //8am color = (1, 1, 1)

    worldDayTime = time;//std::fmod(time, 24);

    lightAngle = worldDayTime / 24.0f * 360.0f - 90.0f;
    if (lightAngle < 0)lightAngle += 360.0f;

    if (worldDayTime <= 4 || worldDayTime >= 22)
    {
        lightColor = Vector3(0.1f, 0.1f, 0.1f);
    }
    else if (worldDayTime >= 8 && worldDayTime <= 16)
    {
        lightColor = Vector3(1, 1, 1);
    }
    else if (worldDayTime >= 4 && worldDayTime <= 6)
    {
        lightColor.x = (worldDayTime - 4.0f)/2.0f * 0.9f + 0.1f;
        lightColor.y = (worldDayTime - 4.0f)/2.0f * 0.5f + 0.1f;
        lightColor.z = (worldDayTime - 4.0f)/2.0f * -0.06f + 0.1f;
    }
    else if (worldDayTime >= 6 && worldDayTime <= 8)
    {
        lightColor.x = 1.0f;
        lightColor.y = (worldDayTime - 6.0f)/2.0f * 0.4f + 0.6f;
        lightColor.z = (worldDayTime - 6.0f)/2.0f * 0.96f + 0.04f;
    }
    else if (worldDayTime >= 16 && worldDayTime <= 18)
    {
        lightColor.x = 1.0f;
        lightColor.y = (18.0f - worldDayTime)/2.0f * 0.4f + 0.6f;
        lightColor.z = (18.0f - worldDayTime)/2.0f * 0.96f + 0.04f;
    }
    else if (worldDayTime >= 18 && worldDayTime <= 22)
    {
        lightColor.x = (20.0f - worldDayTime)/2.0f * 0.9f + 0.3f;
        lightColor.y = (20.0f - worldDayTime)/2.0f * 0.5f + 0.3f;
        lightColor.z = (20.0f - worldDayTime)/2.0f * -0.06f + 0.3f;
    }
    else	//Shouldn't get here
    {
        lightColor = Vector3(1, 1, 1);
    }

    //ambientColor = lightColor / 3.0f;
    ambientColor = Vector3(0.05f,0.05f,0.05f);

    fogColor = lightColor * 0.80f;

    //light face factors
    if (lightAngle >= 0 &&lightAngle <= 180)
        factor1 = sinf(lightAngle * 3.1415926f / 180.0f);
    else
        factor1 = 0.0f;

    if(factor1 < 0.1f)
        factor1 = 0.1f;

    if (lightAngle >= 315 || lightAngle <= 45)
        factor2 = fabs(cosf(lightAngle * 3.1415926f / 180.0f));
    else
        factor2 = fabs(sinf(lightAngle * 3.1415926f / 180.0f));

    if (factor2 < 0.1f)
        factor2 = 0.1f;

    if (lightAngle >= 135 && lightAngle <= 225)
        factor3 = fabs(cosf(lightAngle * 3.1415926f / 180.0f));
    else
        factor3 = fabs(sinf(lightAngle * 3.1415926f / 180.0f));

    if (factor3 < 0.1f)
        factor3 = 0.1f;
}

void CraftWorld::buildMap()
{
    createWorldChunkss();
}

void CraftWorld::destroyMap()
{
    for(unsigned int i = 0; i < mChunks.size(); i++)
    {
        mChunks[i]->reset();
    }

    for(unsigned int i = 0; i < mTransparentChunks.size(); i++)
    {
        mTransparentChunks[i]->reset();
    }
}

void CraftWorld::setTextureSize(int texture,int chunk)
{
    texutreSize = texture;
    textureChunk = chunk;

    percent = (float)textureChunk / (float)texutreSize;
}

block_t& CraftWorld::GetBlock (const int x, const int y, const int z)
{
    return m_Blocks[x + y * WORLD_SIZE + z * WORLD_SIZE * WORLD_SIZE];
}

block_t& CraftWorld::GetBlockLight (const int x, const int y, const int z)
{
    return m_BlockLight[x + y * WORLD_SIZE + z * WORLD_SIZE * WORLD_SIZE];
}

block_t& CraftWorld::GetBlockSettings(const int x, const int y, const int z)
{
    return m_BlockSettings[x + y * WORLD_SIZE + z * WORLD_SIZE * WORLD_SIZE];
}

void CraftWorld::CheckForTorchSupport(const int x, const int y, const int z,int blockID)
{
    for(int zz = z-1; zz < z+2; zz++)
    {
        for(int xx = x-1; xx < x+2; xx++)
        {
            for(int yy = y-1; yy < y+2; yy++)
            {
                if(GetBlock(xx,yy,zz) == Torch::getID())
                {
                    if(!CanPutBlockHere(xx,yy,zz,Torch::getID()))
                    {
                        GetBlock(xx,yy,zz) = 0;
                        RemoveLigtSourceAtPosition(xx,yy,zz,Torch::getID());
                    }
                }
            }
        }
    }
}

void CraftWorld::RemoveLigtSourceAtPosition(const int x, const int y, const int z,int blockID)
{
    if(blockID == LampOn::getID()|| blockID == JackOLantern::getID()|| blockID == Torch::getID() || blockID == Lava::getID() || blockID == GlowStone::getID() || blockID == Furnace2::getID())
    {
        int current = 0;

        for(int zz = z-14; zz < z+14; zz++)
        {
            for(int xx = x-14; xx < x+14; xx++)
            {
                for(int yy = y-14; yy < y+14; yy++)
                {
                    if (xx >= 0 || yy >= 0 || zz >= 0  || xx < WORLD_SIZE || yy < WORLD_SIZE || zz < WORLD_SIZE)
                    {
                        if((GetBlockSettings(xx,yy,zz) & OpLighSource) != 0)
                        {
                            current = GetBlockSettings(xx,yy,zz) & 0xF;
                            GetBlockSettings(xx,yy,zz) ^= current & 0xF;
                            GetBlockSettings(xx,yy,zz) ^= 0 & 0xF;
                            //turn off light here
                            GetBlockSettings(xx,yy,zz) ^= OpLighSource;
                        }
                    }
                }
            }
        }

        BoundingBox lBox = BoundingBox(Vector3(x - 14,y - 14,z - 14),Vector3(x + 14,y + 14,z + 14));
        for(unsigned int i = 0; i < mChunks.size(); i++)
        {
            if(lBox.intersect(mChunks[i]->bBox))
                UpdateWorldLightForChunk(i);
        }

    }
}
bool CraftWorld::CanPutBlockHere(const int x, const int y, const int z,int blockID)
{
    if(blockID == Torch::getID())
    {
        bool canPlaseTorch = false;

        if(GetBlock(x,y-1,z) != 0 && GetBlock(x,y-1,z) != Torch::getID())
        {
            canPlaseTorch = true;
        }
        else if(GetBlock(x-1,y,z) != 0 && GetBlock(x-1,y,z) != Torch::getID())
        {
            canPlaseTorch = true;
        }
        else if(GetBlock(x+1,y,z) != 0 && GetBlock(x+1,y,z) != Torch::getID())
        {
            canPlaseTorch = true;
        }
        else if(GetBlock(x,y,z-1) != 0 && GetBlock(x,y,z-1) != Torch::getID())
        {
            canPlaseTorch = true;
        }
        else if(GetBlock(x,y,z+1) != 0 && GetBlock(x,y,z+1) != Torch::getID())
        {
            canPlaseTorch = true;
        }

        return canPlaseTorch;
    }

    return true;
}

void CraftWorld::LightTravel(int x,int y,int z,int steps,int lightLevel)
{
    if (x >= 0 && y >= 0 && z >= 0  && x < WORLD_SIZE && y < WORLD_SIZE && z < WORLD_SIZE && steps > 0 && lightLevel >= 0)
    {
        //if((GetBlockSettings(x,y,z) & OpLightTraveled) == 0)//not traveled
        //{
        //mark traveled
        //GetBlockSettings(x,y,z) ^= OpLightTraveled;

        //if it's transparent block or light source...
        if(GetBlock(x,y,z) == brickWallSlap::getID() || GetBlock(x,y,z) == quartzSlap::getID() || BlockTransparent(x,y,z) == true || GetBlock(x,y,z) == Torch::getID() || GetBlock(x,y,z) == HalfBlock0::getID() || GetBlock(x,y,z) == HalfBlock1::getID() || GetBlock(x,y,z) == HalfBlock2::getID() || GetBlock(x,y,z) == HalfBlock3::getID() || GetBlock(x,y,z) == HalfBlock4::getID() ||
                GetBlock(x,y,z) == HalfBlock5::getID() || GetBlock(x,y,z) == HalfBlock6::getID() || GetBlock(x,y,z) == HalfBlock7::getID() || GetBlock(x,y,z) == HalfBlock8::getID() || GetBlock(x,y,z) == Snow2::getID() || GetBlock(x,y,z) == Cake::getID() || GetBlock(x,y,z) == Fence::getID() ||
                GetBlock(x,y,z) == NetherFence::getID() || GetBlock(x,y,z) == LampOn::getID() ||  GetBlock(x,y,z) == GlowStone::getID() || GetBlock(x,y,z) == JackOLantern::getID() || GetBlock(x,y,z) == StonePlate::getID() || GetBlock(x,y,z) == WoodPlate::getID() || GetBlock(x,y,z) == Table::getID() || GetBlock(x,y,z) == endPortal::getID())
        {
            bool canGofuther = false;
            //check if it's lightened
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//lightened
            {
                //get current value
                int current = GetBlockSettings(x,y,z) & 0xF;
                //set new only if it's brighter
                if(current < lightLevel)
                {
                    //clear this value
                    GetBlockSettings(x,y,z) ^= current & 0xF;
                    //set new value
                    GetBlockSettings(x,y,z) ^= lightLevel & 0xF;

                    canGofuther = true;
                }
            }
            else
            {
                int current = GetBlockSettings(x,y,z) & 0xF;
                //clear this value
                GetBlockSettings(x,y,z) ^= current & 0xF;
                //set new value
                GetBlockSettings(x,y,z) ^= lightLevel & 0xF;
                //mark as lightened
                GetBlockSettings(x,y,z) ^= OpLighSource;

                canGofuther = true;
            }


            //go futher
            if(canGofuther)
            {
                LightTravel(x+1,y,z,steps-1,lightLevel-1);
                LightTravel(x-1,y,z,steps-1,lightLevel-1);
                LightTravel(x,y+1,z,steps-1,lightLevel-1);
                LightTravel(x,y-1,z,steps-1,lightLevel-1);
                LightTravel(x,y,z+1,steps-1,lightLevel-1);
                LightTravel(x,y,z-1,steps-1,lightLevel-1);
            }
        }
        //}
    }
}

void CraftWorld::SetLigtSourcePosition(const int x, const int y, const int z,int blockID)
{
    //put correct light based on lightsource type
    if(blockID == LampOn::getID() || blockID == JackOLantern::getID() || blockID == Torch::getID() || blockID == Lava::getID() || blockID == GlowStone::getID() || blockID == Furnace2::getID())
    {
        LightTravel(x,y,z,14,15);
    }
}

bool CraftWorld::BlockTransparentOrSpecial(const int x, const int y, const int z)
{
    if (x < 0 || y < 0 || z < 0  || x >= WORLD_SIZE || y >= WORLD_SIZE || z >= WORLD_SIZE) return true;

    if(blockTypes[m_Blocks[x + y * WORLD_SIZE + z * WORLD_SIZE * WORLD_SIZE]].transparent || blockTypes[m_Blocks[x + y * WORLD_SIZE + z * WORLD_SIZE * WORLD_SIZE]].blockSpecial)
        return true;

    return false;
}

bool CraftWorld::BlockTransparentOrLightSource(const int x, const int y, const int z)
{
    if (x < 0 || y < 0 || z < 0  || x >= WORLD_SIZE || y >= WORLD_SIZE || z >= WORLD_SIZE) return true;

    return (blockTypes[m_Blocks[x + y * WORLD_SIZE + z * WORLD_SIZE * WORLD_SIZE]].transparent || blockTypes[m_Blocks[x + y * WORLD_SIZE + z * WORLD_SIZE * WORLD_SIZE]].lightSource);
}

bool CraftWorld::BlockTransparent(const int x, const int y, const int z)
{
    if (x < 0 || y < 0 || z < 0  || x >= WORLD_SIZE || y >= WORLD_SIZE || z >= WORLD_SIZE) return true;

    return blockTypes[m_Blocks[x + y * WORLD_SIZE + z * WORLD_SIZE * WORLD_SIZE]].transparent;
}

bool CraftWorld::BlockSpecial(const int x, const int y, const int z)
{
    if (x < 0 || y < 0 || z < 0  || x >= WORLD_SIZE || y >= WORLD_SIZE || z >= WORLD_SIZE) return true;

    return blockTypes[m_Blocks[x + y * WORLD_SIZE + z * WORLD_SIZE * WORLD_SIZE]].blockSpecial;
}

bool CraftWorld::BlockEditable(const int x, const int y, const int z)
{
    if (x < 0 || y < 0 || z < 0  || x >= WORLD_SIZE || y >= WORLD_SIZE || z >= WORLD_SIZE) return false;

    return blockTypes[m_Blocks[x + y * WORLD_SIZE + z * WORLD_SIZE * WORLD_SIZE]].editable;
}

bool CraftWorld::LightSourceBlock(int id)
{
    return blockTypes[id].lightSource;
}

void CraftWorld::GetSpecialBlockVerts(int i,BaseBlock* blockType)
{
    std::vector<Vector3*> mPosition;
    std::vector<Vector3*> mColour;
    std::vector<Vector2*> mtextures;
    std::vector<Vector3*> mTriangle;

    int iVertex = 0;

    float x = -0.5f;
    float y = -0.5f;
    float z = -0.5f;

    if(i == TrapDoor::getID())
    {

        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent;

        float left = percent * blockType->upPlane;
        float right = left + percent;

        iVertex = 0;

        //light
        float BlockLight  = 1.0f;  //For the two x faces
        float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
        float BlockLight2 = BlockLight * 0.8f;		//For the two y faces


        //x
        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x, y, z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y+0.2, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y+0.2, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y,   z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //x

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x+1, y,   z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+1, y+0.2, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+1, y+0.2, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+1, y,   z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //up
        left = percent * blockType->downPlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+1, y, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+1, y, z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x,   y, z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //down
        left = percent * blockType->upPlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y+0.2, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+1, y+0.2, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+1, y+0.2, z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x,   y+0.2, z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y+0.2, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+1, y+0.2, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+1, y,   z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x,   y,   z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y,   z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+1, y,   z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+1, y+0.2, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x,   y+0.2, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;


        blockTypes[i].vertices = (CraftPSPVertex*)memalign(16,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
        //build verts
        //vertices
        int vert = 0;
        unsigned int size =  mTriangle.size();
        for(unsigned int j = 0; j < size; j++)
        {
            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->x]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->x]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->x]->x,mColour[mTriangle[j]->x]->y,mColour[mTriangle[j]->x]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->x]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->x]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->x]->z;
            vert++;

            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->y]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->y]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->y]->x,mColour[mTriangle[j]->y]->y,mColour[mTriangle[j]->y]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->y]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->y]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->y]->z;
            vert++;

            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->z]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->z]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->z]->x,mColour[mTriangle[j]->z]->y,mColour[mTriangle[j]->z]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->z]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->z]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->z]->z;
            vert++;
        }

        //clear the cache or there will be some errors
        sceKernelDcacheWritebackInvalidateRange(blockTypes[i].vertices,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
        //sceKernelDcacheWritebackInvalidateAll();

        for(unsigned int aa = 0; aa < mPosition.size(); aa++)
        {
            delete mPosition[aa];
            delete mtextures[aa];
            delete mColour[aa];
        }
        mPosition.clear();
        mtextures.clear();
        mColour.clear();

        for(unsigned int aa = 0; aa < mTriangle.size(); aa++)
            delete 		mTriangle[aa];
        mTriangle.clear();
    }

    if(i == WaterBlock::getID() || i == Lava::getID())
    {

        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent;

        float left = percent * blockType->upPlane;
        float right = left + percent;

        iVertex = 0;

        //light
        float BlockLight  = 1.0f;  //For the two x faces
        float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
        float BlockLight2 = BlockLight * 0.8f;		//For the two y faces


        //x
        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x, y, z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y+1, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y+1, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y,   z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //x

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x+1, y,   z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+1, y+1, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+1, y+1, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+1, y,   z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //up
        left = percent * blockType->downPlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+1, y, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+1, y, z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x,   y, z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //down
        left = percent * blockType->upPlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y+1, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+1, y+1, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+1, y+1, z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x,   y+1, z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y+1, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+1, y+1, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+1, y,   z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x,   y,   z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y,   z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+1, y,   z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+1, y+1, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x,   y+1, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;


        blockTypes[i].vertices = (CraftPSPVertex*)memalign(16,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
        //build verts
        //vertices
        int vert = 0;
        unsigned int size =  mTriangle.size();
        for(unsigned int j = 0; j < size; j++)
        {
            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->x]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->x]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->x]->x,mColour[mTriangle[j]->x]->y,mColour[mTriangle[j]->x]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->x]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->x]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->x]->z;
            vert++;

            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->y]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->y]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->y]->x,mColour[mTriangle[j]->y]->y,mColour[mTriangle[j]->y]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->y]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->y]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->y]->z;
            vert++;

            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->z]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->z]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->z]->x,mColour[mTriangle[j]->z]->y,mColour[mTriangle[j]->z]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->z]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->z]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->z]->z;
            vert++;
        }

        //clear the cache or there will be some errors
        sceKernelDcacheWritebackInvalidateRange(blockTypes[i].vertices,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
        //sceKernelDcacheWritebackInvalidateAll();

        for(unsigned int aa = 0; aa < mPosition.size(); aa++)
        {
            delete mPosition[aa];
            delete mtextures[aa];
            delete mColour[aa];
        }
        mPosition.clear();
        mtextures.clear();
        mColour.clear();

        for(unsigned int aa = 0; aa < mTriangle.size(); aa++)
            delete 		mTriangle[aa];
        mTriangle.clear();
    }

    if(i == Door1::getID() || i == Door2::getID())
    {

        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent;

        float left = percent * blockType->upPlane;
        float right = left + percent;

        iVertex = 0;

        //light
        float BlockLight  = 1.0f;  //For the two x faces
        float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
        float BlockLight2 = BlockLight * 0.8f;		//For the two y faces


        //x
        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x, y, z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y+1, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y+1, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y,   z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //x

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x+0.2, y,   z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+0.2, y+1, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+0.2, y+1, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+0.2, y,   z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //up
        left = percent * blockType->downPlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+0.2, y, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+0.2, y, z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x,   y, z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //down
        left = percent * blockType->upPlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y+1, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+0.2, y+1, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+0.2, y+1, z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x,   y+1, z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y+1, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+0.2, y+1, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+0.2, y,   z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x,   y,   z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y,   z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+0.2, y,   z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+0.2, y+1, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x,   y+1, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;


        blockTypes[i].vertices = (CraftPSPVertex*)memalign(16,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
        //build verts
        //vertices
        int vert = 0;
        unsigned int size =  mTriangle.size();
        for(unsigned int j = 0; j < size; j++)
        {
            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->x]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->x]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->x]->x,mColour[mTriangle[j]->x]->y,mColour[mTriangle[j]->x]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->x]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->x]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->x]->z;
            vert++;

            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->y]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->y]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->y]->x,mColour[mTriangle[j]->y]->y,mColour[mTriangle[j]->y]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->y]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->y]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->y]->z;
            vert++;

            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->z]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->z]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->z]->x,mColour[mTriangle[j]->z]->y,mColour[mTriangle[j]->z]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->z]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->z]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->z]->z;
            vert++;
        }

        //clear the cache or there will be some errors
        sceKernelDcacheWritebackInvalidateRange(blockTypes[i].vertices,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
        //sceKernelDcacheWritebackInvalidateAll();

        for(unsigned int aa = 0; aa < mPosition.size(); aa++)
        {
            delete mPosition[aa];
            delete mtextures[aa];
            delete mColour[aa];
        }
        mPosition.clear();
        mtextures.clear();
        mColour.clear();

        for(unsigned int aa = 0; aa < mTriangle.size(); aa++)
            delete 		mTriangle[aa];
        mTriangle.clear();
    }

    if(i == GlassPane::getID() || i == IronBars::getID())
    {

        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent;

        float left = percent * blockType->upPlane;
        float right = left + percent;

        iVertex = 0;

        //light
        float BlockLight  = 1.0f;  //For the two x faces
        float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
        float BlockLight2 = BlockLight * 0.8f;		//For the two y faces


        //x
        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x, y, z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y+1, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y+1, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y,   z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //x

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x+0.1, y,   z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+0.1, y+1, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+0.1, y+1, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+0.1, y,   z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //up
        left = percent * blockType->downPlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+0.1, y, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+0.1, y, z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x,   y, z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //down
        left = percent * blockType->upPlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y+1, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+0.1, y+1, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+0.1, y+1, z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x,   y+1, z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y+1, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+0.1, y+1, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+0.1, y,   z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x,   y,   z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y,   z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+0.1, y,   z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+0.1, y+1, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x,   y+1, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;


        blockTypes[i].vertices = (CraftPSPVertex*)memalign(16,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
        //build verts
        //vertices
        int vert = 0;
        unsigned int size =  mTriangle.size();
        for(unsigned int j = 0; j < size; j++)
        {
            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->x]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->x]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->x]->x,mColour[mTriangle[j]->x]->y,mColour[mTriangle[j]->x]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->x]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->x]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->x]->z;
            vert++;

            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->y]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->y]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->y]->x,mColour[mTriangle[j]->y]->y,mColour[mTriangle[j]->y]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->y]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->y]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->y]->z;
            vert++;

            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->z]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->z]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->z]->x,mColour[mTriangle[j]->z]->y,mColour[mTriangle[j]->z]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->z]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->z]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->z]->z;
            vert++;
        }

        //clear the cache or there will be some errors
        sceKernelDcacheWritebackInvalidateRange(blockTypes[i].vertices,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
        //sceKernelDcacheWritebackInvalidateAll();

        for(unsigned int aa = 0; aa < mPosition.size(); aa++)
        {
            delete mPosition[aa];
            delete mtextures[aa];
            delete mColour[aa];
        }
        mPosition.clear();
        mtextures.clear();
        mColour.clear();

        for(unsigned int aa = 0; aa < mTriangle.size(); aa++)
            delete 		mTriangle[aa];
        mTriangle.clear();
    }

    if(i == LadderBlock::getID() || i == wines::getID())
    {

        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent;

        float left = percent * blockType->upPlane;
        float right = left + percent;

        iVertex = 0;

        //light
        float BlockLight  = 1.0f;  //For the two x faces
        float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
        float BlockLight2 = BlockLight * 0.8f;		//For the two y faces


        //x
        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x, y, z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y+1, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y+1, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y,   z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //x

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x+0.1, y,   z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+0.1, y+1, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+0.1, y+1, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+0.1, y,   z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //up
        left = percent * blockType->downPlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+0.1, y, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+0.1, y, z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x,   y, z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //down
        left = percent * blockType->upPlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y+1, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+0.1, y+1, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+0.1, y+1, z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x,   y+1, z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y+1, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+0.1, y+1, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+0.1, y,   z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x,   y,   z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y,   z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+0.1, y,   z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+0.1, y+1, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x,   y+1, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;


        blockTypes[i].vertices = (CraftPSPVertex*)memalign(16,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
        //build verts
        //vertices
        int vert = 0;
        unsigned int size =  mTriangle.size();
        for(unsigned int j = 0; j < size; j++)
        {
            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->x]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->x]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->x]->x,mColour[mTriangle[j]->x]->y,mColour[mTriangle[j]->x]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->x]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->x]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->x]->z;
            vert++;

            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->y]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->y]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->y]->x,mColour[mTriangle[j]->y]->y,mColour[mTriangle[j]->y]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->y]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->y]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->y]->z;
            vert++;

            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->z]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->z]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->z]->x,mColour[mTriangle[j]->z]->y,mColour[mTriangle[j]->z]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->z]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->z]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->z]->z;
            vert++;
        }

        //clear the cache or there will be some errors
        sceKernelDcacheWritebackInvalidateRange(blockTypes[i].vertices,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
        //sceKernelDcacheWritebackInvalidateAll();

        for(unsigned int aa = 0; aa < mPosition.size(); aa++)
        {
            delete mPosition[aa];
            delete mtextures[aa];
            delete mColour[aa];
        }
        mPosition.clear();
        mtextures.clear();
        mColour.clear();

        for(unsigned int aa = 0; aa < mTriangle.size(); aa++)
            delete 		mTriangle[aa];
        mTriangle.clear();
    }

    if(i == Cake::getID())
    {

        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent;

        float left = percent * blockType->upPlane;
        float right = left + percent;

        iVertex = 0;

        //light
        float BlockLight  = 1.0f;  //For the two x faces
        float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
        float BlockLight2 = BlockLight * 0.8f;		//For the two y faces


        //x
        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x, y, z+0.9));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y+0.5, z+0.9));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y+0.5, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y,   z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //x

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x+0.9, y,   z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+0.9, y+0.5, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+0.9, y+0.5, z+0.9));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+0.9, y,   z+0.9));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //up
        left = percent * blockType->downPlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+0.9, y, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+0.9, y, z+0.9));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x,   y, z+0.9));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //down
        left = percent * blockType->upPlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y+0.5, z+0.9));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+0.9, y+0.5, z+0.9));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+0.9, y+0.5, z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x,   y+0.5, z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y+0.5, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+0.9, y+0.5, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+0.9, y,   z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x,   y,   z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y,   z+0.9));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+0.9, y,   z+0.9));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+0.9, y+0.5, z+0.9));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x,   y+0.5, z+0.9));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;


        blockTypes[i].vertices = (CraftPSPVertex*)memalign(16,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
        //build verts
        //vertices
        int vert = 0;
        unsigned int size =  mTriangle.size();
        for(unsigned int j = 0; j < size; j++)
        {
            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->x]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->x]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->x]->x,mColour[mTriangle[j]->x]->y,mColour[mTriangle[j]->x]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->x]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->x]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->x]->z;
            vert++;

            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->y]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->y]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->y]->x,mColour[mTriangle[j]->y]->y,mColour[mTriangle[j]->y]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->y]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->y]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->y]->z;
            vert++;

            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->z]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->z]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->z]->x,mColour[mTriangle[j]->z]->y,mColour[mTriangle[j]->z]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->z]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->z]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->z]->z;
            vert++;
        }

        //clear the cache or there will be some errors
        sceKernelDcacheWritebackInvalidateRange(blockTypes[i].vertices,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
        //sceKernelDcacheWritebackInvalidateAll();

        for(unsigned int aa = 0; aa < mPosition.size(); aa++)
        {
            delete mPosition[aa];
            delete mtextures[aa];
            delete mColour[aa];
        }
        mPosition.clear();
        mtextures.clear();
        mColour.clear();

        for(unsigned int aa = 0; aa < mTriangle.size(); aa++)
            delete 		mTriangle[aa];
        mTriangle.clear();
    }

    if(i == Table::getID() || i == endPortal::getID())
    {

        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent;

        float left = percent * blockType->upPlane;
        float right = left + percent;

        iVertex = 0;

        //light
        float BlockLight  = 1.0f;  //For the two x faces
        float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
        float BlockLight2 = BlockLight * 0.8f;		//For the two y faces

        //x
        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x, y, z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y+0.65, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y+0.65, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y,   z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //x

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x+1, y,   z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+1, y+0.65, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+1, y+0.65, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+1, y,   z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //up
        left = percent * blockType->downPlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+1, y, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+1, y, z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x,   y, z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //down
        left = percent * blockType->upPlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y+0.65, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+1, y+0.65, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+1, y+0.65, z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x,   y+0.65, z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y+0.65, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+1, y+0.65, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+1, y,   z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x,   y,   z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y,   z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+1, y,   z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+1, y+0.65, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x,   y+0.65, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;


        blockTypes[i].vertices = (CraftPSPVertex*)memalign(16,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
        //build verts
        //vertices
        int vert = 0;
        unsigned int size =  mTriangle.size();
        for(unsigned int j = 0; j < size; j++)
        {
            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->x]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->x]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->x]->x,mColour[mTriangle[j]->x]->y,mColour[mTriangle[j]->x]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->x]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->x]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->x]->z;
            vert++;

            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->y]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->y]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->y]->x,mColour[mTriangle[j]->y]->y,mColour[mTriangle[j]->y]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->y]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->y]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->y]->z;
            vert++;

            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->z]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->z]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->z]->x,mColour[mTriangle[j]->z]->y,mColour[mTriangle[j]->z]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->z]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->z]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->z]->z;
            vert++;
        }

        //clear the cache or there will be some errors
        sceKernelDcacheWritebackInvalidateRange(blockTypes[i].vertices,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
        //sceKernelDcacheWritebackInvalidateAll();

        for(unsigned int aa = 0; aa < mPosition.size(); aa++)
        {
            delete mPosition[aa];
            delete mtextures[aa];
            delete mColour[aa];
        }
        mPosition.clear();
        mtextures.clear();
        mColour.clear();

        for(unsigned int aa = 0; aa < mTriangle.size(); aa++)
            delete 		mTriangle[aa];
        mTriangle.clear();
    }

    if(i == Snow2::getID() || i== WoodPlate::getID() || i== StonePlate::getID() || i==lilyPad::getID() || i ==WaterFlow::getID())
    {

        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent;

        float left = percent * blockType->upPlane;
        float right = left + percent;

        iVertex = 0;

        //light
        float BlockLight  = 1.0f;  //For the two x faces
        float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
        float BlockLight2 = BlockLight * 0.8f;		//For the two y faces


        //x
        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x, y, z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y+0.1, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y+0.1, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y,   z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //x

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x+1, y,   z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+1, y+0.1, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+1, y+0.1, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+1, y,   z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //up
        left = percent * blockType->downPlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+1, y, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+1, y, z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x,   y, z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //down
        left = percent * blockType->upPlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y+0.1, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+1, y+0.1, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+1, y+0.1, z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x,   y+0.1, z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y+0.1, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+1, y+0.1, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+1, y,   z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x,   y,   z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y,   z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+1, y,   z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+1, y+0.1, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x,   y+0.1, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;


        blockTypes[i].vertices = (CraftPSPVertex*)memalign(16,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
        //build verts
        //vertices
        int vert = 0;
        unsigned int size =  mTriangle.size();
        for(unsigned int j = 0; j < size; j++)
        {
            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->x]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->x]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->x]->x,mColour[mTriangle[j]->x]->y,mColour[mTriangle[j]->x]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->x]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->x]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->x]->z;
            vert++;

            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->y]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->y]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->y]->x,mColour[mTriangle[j]->y]->y,mColour[mTriangle[j]->y]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->y]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->y]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->y]->z;
            vert++;

            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->z]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->z]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->z]->x,mColour[mTriangle[j]->z]->y,mColour[mTriangle[j]->z]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->z]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->z]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->z]->z;
            vert++;
        }

        //clear the cache or there will be some errors
        sceKernelDcacheWritebackInvalidateRange(blockTypes[i].vertices,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
        //sceKernelDcacheWritebackInvalidateAll();

        for(unsigned int aa = 0; aa < mPosition.size(); aa++)
        {
            delete mPosition[aa];
            delete mtextures[aa];
            delete mColour[aa];
        }
        mPosition.clear();
        mtextures.clear();
        mColour.clear();

        for(unsigned int aa = 0; aa < mTriangle.size(); aa++)
            delete 		mTriangle[aa];
        mTriangle.clear();
    }

    if(i == brickWallSlap::getID() || i == quartzSlap::getID() || i == HalfBlock1::getID() || i == HalfBlock2::getID() || i == HalfBlock3::getID() || i == HalfBlock4::getID() || i == HalfBlock5::getID() || i == HalfBlock6::getID() || i == HalfBlock7::getID() || i == HalfBlock0::getID() || i == HalfBlock8::getID())
    {

        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent;

        float left = percent * blockType->upPlane;
        float right = left + percent;

        iVertex = 0;

        //light
        float BlockLight  = 1.0f;  //For the two x faces
        float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
        float BlockLight2 = BlockLight * 0.8f;		//For the two y faces


        //x
        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x, y, z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y+0.5, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y+0.5, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x, y,   z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //x

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x+1, y,   z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+1, y+0.5, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+1, y+0.5, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
        mPosition.push_back(new Vector3(x+1, y,   z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //up
        left = percent * blockType->downPlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+1, y, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+1, y, z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x,   y, z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //down
        left = percent * blockType->upPlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y+0.5, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+1, y+0.5, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x+1, y+0.5, z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
        mPosition.push_back(new Vector3(x,   y+0.5, z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y+0.5, z));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+1, y+0.5, z));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+1, y,   z));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x,   y,   z));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        left = percent * blockType->sidePlane;
        right = left + percent;

        mPosition.push_back(new Vector3(x,   y,   z+1));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+1, y,   z+1));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x+1, y+0.5, z+1));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
        mPosition.push_back(new Vector3(x,   y+0.5, z+1));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;


        blockTypes[i].vertices = (CraftPSPVertex*)memalign(16,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
        //build verts
        //vertices
        int vert = 0;
        unsigned int size =  mTriangle.size();
        for(unsigned int j = 0; j < size; j++)
        {
            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->x]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->x]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->x]->x,mColour[mTriangle[j]->x]->y,mColour[mTriangle[j]->x]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->x]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->x]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->x]->z;
            vert++;

            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->y]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->y]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->y]->x,mColour[mTriangle[j]->y]->y,mColour[mTriangle[j]->y]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->y]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->y]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->y]->z;
            vert++;

            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->z]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->z]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->z]->x,mColour[mTriangle[j]->z]->y,mColour[mTriangle[j]->z]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->z]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->z]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->z]->z;
            vert++;
        }

        //clear the cache or there will be some errors
        sceKernelDcacheWritebackInvalidateRange(blockTypes[i].vertices,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
        //sceKernelDcacheWritebackInvalidateAll();

        for(unsigned int aa = 0; aa < mPosition.size(); aa++)
        {
            delete mPosition[aa];
            delete mtextures[aa];
            delete mColour[aa];
        }
        mPosition.clear();
        mtextures.clear();
        mColour.clear();

        for(unsigned int aa = 0; aa < mTriangle.size(); aa++)
            delete 		mTriangle[aa];
        mTriangle.clear();
    }

    if(i == Torch::getID())
    {
        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent - ((percent / (float)textureChunk) * 6);

        float left = percent * blockType->sidePlane + ((percent / (float)textureChunk) * 7);
        float right = left + ((percent / (float)textureChunk) * 2);

        //x-1
        mPosition.push_back(new Vector3(x + 0.45f,y			,z + 0.45f + 0.1f	));
        mtextures.push_back(new Vector2(right	, down));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.45f,y + 0.6f	,z + 0.45f + 0.1f	));
        mtextures.push_back(new Vector2(right	, up));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.45f,y + 0.6f	,z + 0.45f			));
        mtextures.push_back(new Vector2(left	, up));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.45f,y			,z + 0.45f			));
        mtextures.push_back(new Vector2(left	, down));
        mColour.push_back(new Vector3(1,1,1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //x+1
        mPosition.push_back(new Vector3(x + 0.45f + 0.1f,y		,z + 0.45f));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.45f + 0.1f,y+ 0.6f,z + 0.45f));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.45f + 0.1f,y+ 0.6f,z + 0.45f + 0.1f));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.45f + 0.1f,y		,z + 0.45f + 0.1f));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(1,1,1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //z-1
        mPosition.push_back(new Vector3(x + 0.45f		, y + 0.6f	, z + 0.45f));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.45f + 0.1f, y + 0.6f	, z + 0.45f));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.45f + 0.1f, y			, z + 0.45f));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.45f		, y			, z + 0.45f));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(1,1,1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //z+1
        mPosition.push_back(new Vector3(x + 0.45f		, y			, z + 0.45f + 0.1f));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.45f + 0.1f, y			, z + 0.45f + 0.1f));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.45f + 0.1f, y + 0.6f	, z + 0.45f + 0.1f));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.45f		, y + 0.6f	, z + 0.45f + 0.1f));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(1,1,1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //y+1
        {
            down = 1.0f - percent * (blockType->textureRow + 1) + ((percent / (float)textureChunk) * 8);
            up = down + ((percent / (float)textureChunk) * 2);

            left = percent * blockType->sidePlane + ((percent / (float)textureChunk) * 7);
            right = left + ((percent / (float)textureChunk) * 2);

            mPosition.push_back(new Vector3(x + 0.45f		,y + 0.6f,z + 0.45f + 0.1f));
            mtextures.push_back(new Vector2(left, up));
            mColour.push_back(new Vector3(1,1,1));
            mPosition.push_back(new Vector3(x + 0.45f + 0.1f,y + 0.6f,z + 0.45f + 0.1f));
            mtextures.push_back(new Vector2(right, up));
            mColour.push_back(new Vector3(1,1,1));
            mPosition.push_back(new Vector3(x + 0.45f + 0.1f,y + 0.6f,z + 0.45f));
            mtextures.push_back(new Vector2(right, down));
            mColour.push_back(new Vector3(1,1,1));
            mPosition.push_back(new Vector3(x + 0.45f		,y + 0.6f,z + 0.45f));
            mtextures.push_back(new Vector2(left, down));
            mColour.push_back(new Vector3(1,1,1));

            mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
            mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

            iVertex += 4;
        }

        blockTypes[i].vertices = (CraftPSPVertex*)memalign(16,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
        //build verts
        //vertices
        int vert = 0;
        unsigned int size =  mTriangle.size();
        for(unsigned int j = 0; j < size; j++)
        {
            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->x]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->x]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->x]->x,mColour[mTriangle[j]->x]->y,mColour[mTriangle[j]->x]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->x]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->x]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->x]->z;
            vert++;

            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->y]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->y]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->y]->x,mColour[mTriangle[j]->y]->y,mColour[mTriangle[j]->y]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->y]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->y]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->y]->z;
            vert++;

            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->z]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->z]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->z]->x,mColour[mTriangle[j]->z]->y,mColour[mTriangle[j]->z]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->z]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->z]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->z]->z;
            vert++;
        }

        //clear the cache or there will be some errors
        sceKernelDcacheWritebackInvalidateRange(blockTypes[i].vertices,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
        //sceKernelDcacheWritebackInvalidateAll();

        for(unsigned int aa = 0; aa < mPosition.size(); aa++)
        {
            delete mPosition[aa];
            delete mtextures[aa];
            delete mColour[aa];
        }
        mPosition.clear();
        mtextures.clear();
        mColour.clear();

        for(unsigned int aa = 0; aa < mTriangle.size(); aa++)
            delete 		mTriangle[aa];
        mTriangle.clear();
    }

    if(i == Fence::getID() || i == NetherFence::getID())
    {
        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent - ((percent / (float)textureChunk) * 6);

        float left = percent * blockType->sidePlane + ((percent / (float)textureChunk) * 7);
        float right = left + ((percent / (float)textureChunk) * 2);

        //x-1
        mPosition.push_back(new Vector3(x + 0.35f,y			,z + 0.35f + 0.3f	));
        mtextures.push_back(new Vector2(right	, down));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.35f,y + 1.0f	,z + 0.35f + 0.3f	));
        mtextures.push_back(new Vector2(right	, up));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.35f,y + 1.0f	,z + 0.35f			));
        mtextures.push_back(new Vector2(left	, up));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.35f,y			,z + 0.35f			));
        mtextures.push_back(new Vector2(left	, down));
        mColour.push_back(new Vector3(1,1,1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //x+1
        mPosition.push_back(new Vector3(x + 0.35f + 0.3f,y		,z + 0.35f));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.35f + 0.3f,y+ 1.0f,z + 0.35f));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.35f + 0.3f,y+ 1.0f,z + 0.35f + 0.3f));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.35f + 0.3f,y		,z + 0.35f + 0.3f));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(1,1,1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //z-1
        mPosition.push_back(new Vector3(x + 0.35f		, y + 1.0f	, z + 0.35f));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.35f + 0.3f, y + 1.0f	, z + 0.35f));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.35f + 0.3f, y			, z + 0.35f));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.35f		, y			, z + 0.35f));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(1,1,1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //z+1
        mPosition.push_back(new Vector3(x + 0.35f		, y			, z + 0.35f + 0.3f));
        mtextures.push_back(new Vector2(left, down));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.35f + 0.3f, y			, z + 0.35f + 0.3f));
        mtextures.push_back(new Vector2(right, down));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.35f + 0.3f, y + 1.0f	, z + 0.35f + 0.3f));
        mtextures.push_back(new Vector2(right, up));
        mColour.push_back(new Vector3(1,1,1));
        mPosition.push_back(new Vector3(x + 0.35f		, y + 1.0f	, z + 0.35f + 0.3f));
        mtextures.push_back(new Vector2(left, up));
        mColour.push_back(new Vector3(1,1,1));

        mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
        mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

        iVertex += 4;

        //y+1
        {
            down = 1.0f - percent * (blockType->textureRow + 1) + ((percent / (float)textureChunk) * 8);
            up = down + ((percent / (float)textureChunk) * 2);

            left = percent * blockType->sidePlane + ((percent / (float)textureChunk) * 7);
            right = left + ((percent / (float)textureChunk) * 2);

            mPosition.push_back(new Vector3(x + 0.35f		,y + 1.0f,z + 0.35f + 0.3f));
            mtextures.push_back(new Vector2(left, up));
            mColour.push_back(new Vector3(1,1,1));
            mPosition.push_back(new Vector3(x + 0.35f + 0.3f,y + 1.0f,z + 0.35f + 0.3f));
            mtextures.push_back(new Vector2(right, up));
            mColour.push_back(new Vector3(1,1,1));
            mPosition.push_back(new Vector3(x + 0.35f + 0.3f,y + 1.0f,z + 0.35f));
            mtextures.push_back(new Vector2(right, down));
            mColour.push_back(new Vector3(1,1,1));
            mPosition.push_back(new Vector3(x + 0.35f		,y + 1.0f,z + 0.35f));
            mtextures.push_back(new Vector2(left, down));
            mColour.push_back(new Vector3(1,1,1));

            mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
            mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

            iVertex += 4;
        }

        blockTypes[i].vertices = (CraftPSPVertex*)memalign(16,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
        //build verts
        //vertices
        int vert = 0;
        unsigned int size =  mTriangle.size();
        for(unsigned int j = 0; j < size; j++)
        {
            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->x]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->x]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->x]->x,mColour[mTriangle[j]->x]->y,mColour[mTriangle[j]->x]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->x]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->x]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->x]->z;
            vert++;

            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->y]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->y]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->y]->x,mColour[mTriangle[j]->y]->y,mColour[mTriangle[j]->y]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->y]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->y]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->y]->z;
            vert++;

            blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->z]->x;
            blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->z]->y;
            blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->z]->x,mColour[mTriangle[j]->z]->y,mColour[mTriangle[j]->z]->z,1.0f);
            blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->z]->x;
            blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->z]->y;
            blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->z]->z;
            vert++;
        }

        //clear the cache or there will be some errors
        sceKernelDcacheWritebackInvalidateRange(blockTypes[i].vertices,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
        //sceKernelDcacheWritebackInvalidateAll();

        for(unsigned int aa = 0; aa < mPosition.size(); aa++)
        {
            delete mPosition[aa];
            delete mtextures[aa];
            delete mColour[aa];
        }
        mPosition.clear();
        mtextures.clear();
        mColour.clear();

        for(unsigned int aa = 0; aa < mTriangle.size(); aa++)
            delete 		mTriangle[aa];
        mTriangle.clear();
    }
}

void CraftWorld::GetNormalBlockVerts(int i,BaseBlock *blockType)
{
    std::vector<Vector3*> mPosition;
    std::vector<Vector3*> mColour;
    std::vector<Vector2*> mtextures;
    std::vector<Vector3*> mTriangle;

    int iVertex = 0;

    float x = -0.5f;
    float y = -0.5f;
    float z = -0.5f;


    float down = 1.0f - percent * (blockType->textureRow + 1);
    float up = down + percent;

    float left = percent * blockType->upPlane;
    float right = left + percent;

    iVertex = 0;

    //light
    float BlockLight  = 1.0f;  //For the two x faces
    float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
    float BlockLight2 = BlockLight * 0.8f;		//For the two y faces


    //x
    left = percent * blockType->sidePlane;
    right = left + percent;

    mPosition.push_back(new Vector3(x, y, z+1));
    mtextures.push_back(new Vector2(right, down));
    mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
    mPosition.push_back(new Vector3(x, y+1, z+1));
    mtextures.push_back(new Vector2(right, up));
    mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
    mPosition.push_back(new Vector3(x, y+1, z));
    mtextures.push_back(new Vector2(left, up));
    mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
    mPosition.push_back(new Vector3(x, y,   z));
    mtextures.push_back(new Vector2(left, down));
    mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));

    mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
    mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

    iVertex += 4;

    //x

    left = percent * blockType->sidePlane;
    right = left + percent;

    mPosition.push_back(new Vector3(x+1, y,   z));
    mtextures.push_back(new Vector2(right, down));
    mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
    mPosition.push_back(new Vector3(x+1, y+1, z));
    mtextures.push_back(new Vector2(right, up));
    mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
    mPosition.push_back(new Vector3(x+1, y+1, z+1));
    mtextures.push_back(new Vector2(left, up));
    mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));
    mPosition.push_back(new Vector3(x+1, y,   z+1));
    mtextures.push_back(new Vector2(left, down));
    mColour.push_back(new Vector3(BlockLight,BlockLight,BlockLight));

    mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
    mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

    iVertex += 4;

    //up
    left = percent * blockType->downPlane;
    right = left + percent;

    mPosition.push_back(new Vector3(x,   y, z));
    mtextures.push_back(new Vector2(left, up));
    mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
    mPosition.push_back(new Vector3(x+1, y, z));
    mtextures.push_back(new Vector2(right, up));
    mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
    mPosition.push_back(new Vector3(x+1, y, z+1));
    mtextures.push_back(new Vector2(right, down));
    mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
    mPosition.push_back(new Vector3(x,   y, z+1));
    mtextures.push_back(new Vector2(left, down));
    mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));

    mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
    mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

    iVertex += 4;

    //down
    left = percent * blockType->upPlane;
    right = left + percent;

    mPosition.push_back(new Vector3(x,   y+1, z+1));
    mtextures.push_back(new Vector2(left, up));
    mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
    mPosition.push_back(new Vector3(x+1, y+1, z+1));
    mtextures.push_back(new Vector2(right, up));
    mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
    mPosition.push_back(new Vector3(x+1, y+1, z));
    mtextures.push_back(new Vector2(right, down));
    mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));
    mPosition.push_back(new Vector3(x,   y+1, z));
    mtextures.push_back(new Vector2(left, down));
    mColour.push_back(new Vector3(BlockLight2,BlockLight2,BlockLight2));

    mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
    mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

    iVertex += 4;

    left = percent * blockType->sidePlane;
    right = left + percent;

    mPosition.push_back(new Vector3(x,   y+1, z));
    mtextures.push_back(new Vector2(right, up));
    mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
    mPosition.push_back(new Vector3(x+1, y+1, z));
    mtextures.push_back(new Vector2(left, up));
    mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
    mPosition.push_back(new Vector3(x+1, y,   z));
    mtextures.push_back(new Vector2(left, down));
    mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
    mPosition.push_back(new Vector3(x,   y,   z));
    mtextures.push_back(new Vector2(right, down));
    mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));

    mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
    mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

    iVertex += 4;

    left = percent * blockType->sidePlane;
    right = left + percent;

    mPosition.push_back(new Vector3(x,   y,   z+1));
    mtextures.push_back(new Vector2(left, down));
    mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
    mPosition.push_back(new Vector3(x+1, y,   z+1));
    mtextures.push_back(new Vector2(right, down));
    mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
    mPosition.push_back(new Vector3(x+1, y+1, z+1));
    mtextures.push_back(new Vector2(right, up));
    mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));
    mPosition.push_back(new Vector3(x,   y+1, z+1));
    mtextures.push_back(new Vector2(left, up));
    mColour.push_back(new Vector3(BlockLight1,BlockLight1,BlockLight1));

    mTriangle.push_back(new Vector3(iVertex, iVertex+1, iVertex+2));
    mTriangle.push_back(new Vector3(iVertex+2, iVertex+3, iVertex));

    iVertex += 4;


    blockTypes[i].vertices = (CraftPSPVertex*)memalign(16,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
    //build verts
    //vertices
    int vert = 0;
    unsigned int size =  mTriangle.size();
    for(unsigned int j = 0; j < size; j++)
    {
        blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->x]->x;
        blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->x]->y;
        blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->x]->x,mColour[mTriangle[j]->x]->y,mColour[mTriangle[j]->x]->z,1.0f);
        blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->x]->x;
        blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->x]->y;
        blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->x]->z;
        vert++;

        blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->y]->x;
        blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->y]->y;
        blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->y]->x,mColour[mTriangle[j]->y]->y,mColour[mTriangle[j]->y]->z,1.0f);
        blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->y]->x;
        blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->y]->y;
        blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->y]->z;
        vert++;

        blockTypes[i].vertices[vert].u = mtextures[mTriangle[j]->z]->x;
        blockTypes[i].vertices[vert].v = mtextures[mTriangle[j]->z]->y;
        blockTypes[i].vertices[vert].color = GU_COLOR( mColour[mTriangle[j]->z]->x,mColour[mTriangle[j]->z]->y,mColour[mTriangle[j]->z]->z,1.0f);
        blockTypes[i].vertices[vert].x = mPosition[mTriangle[j]->z]->x;
        blockTypes[i].vertices[vert].y = mPosition[mTriangle[j]->z]->y;
        blockTypes[i].vertices[vert].z = mPosition[mTriangle[j]->z]->z;
        vert++;
    }

    //clear the cache or there will be some errors
    sceKernelDcacheWritebackInvalidateRange(blockTypes[i].vertices,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
    //sceKernelDcacheWritebackInvalidateAll();

    for(unsigned int aa = 0; aa < mPosition.size(); aa++)
    {
        delete mPosition[aa];
        delete mtextures[aa];
        delete mColour[aa];
    }
    mPosition.clear();
    mtextures.clear();
    mColour.clear();

    for(unsigned int aa = 0; aa < mTriangle.size(); aa++)
        delete 		mTriangle[aa];
    mTriangle.clear();
}

void CraftWorld::buildblocksVerts()
{
    //create vertices for each block type
    for(unsigned int i = 1; i < blockTypes.size(); i++)
    {
        BaseBlock *blockType = &blockTypes[i];

        if(blockType->blockSpecial)
            GetSpecialBlockVerts(i,blockType);
        else
            GetNormalBlockVerts(i,blockType);
    }
}

void CraftWorld::createChunks(const int StartX, const int StartY, const int StartZ)
{
    SimpleMeshChunk* MeshChunk = new SimpleMeshChunk();

    int iVertex = 0;
    block_t Block;

    /* Only create visible faces of each chunk */
    MeshChunk->chunkStartZ = StartZ;
    MeshChunk->chunkStartY = StartY;
    MeshChunk->chunkStartX = StartX;

    MeshChunk->bBox = BoundingBox(Vector3(StartX,StartY,StartZ),Vector3(StartX + CHUNK_SIZE,StartY + CHUNK_SIZE,StartZ + CHUNK_SIZE));

    //if we are in player zone on the start then build map
    if(playerZoneBB.intersect(MeshChunk->bBox))
    {
        createdChunksCount++;
        //light
        for (int z = StartZ; z < CHUNK_SIZE + StartZ; ++z)
        {
            for (int y = StartY; y < CHUNK_SIZE + StartY; ++y)
            {
                for (int x = StartX; x < CHUNK_SIZE + StartX; ++x)
                {
                    Block = GetBlock(x,y,z);
                    if(BlockTransparent(x,y,z) == true)continue;//if block is transparent don't continue

                    if(!BlockSpecial(x,y,z))
                        GetNormalBlock(x,y,z,iVertex,MeshChunk,Block,false);
                    else
                        GetSpecialBlock(x,y,z,iVertex,MeshChunk,Block,false);
                }
            }
        }

        MeshChunk->end();
    }
    else
    {
        MeshChunk->end();
        MeshChunk->created = false;
    }

    MeshChunk->id = mChunks.size();
    mChunks.push_back(MeshChunk);
}


void CraftWorld::createTransparentChunks(const int StartX, const int StartY, const int StartZ)
{
    SimpleMeshChunk* MeshChunk = new SimpleMeshChunk();

    int iVertex = 0;
    block_t Block;

    MeshChunk->chunkStartZ = StartZ;
    MeshChunk->chunkStartY = StartY;
    MeshChunk->chunkStartX = StartX;

    MeshChunk->bBox = BoundingBox(Vector3(StartX,StartY,StartZ),Vector3(StartX + CHUNK_SIZE,StartY + CHUNK_SIZE,StartZ + CHUNK_SIZE));

    //if we are in player zone on the start then build map
    if(playerZoneBB.intersect(MeshChunk->bBox))
    {
        for (int z = StartZ; z < CHUNK_SIZE + StartZ; ++z)
        {
            for (int y = StartY; y < CHUNK_SIZE + StartY; ++y)
            {
                for (int x = StartX; x < CHUNK_SIZE + StartX; ++x)
                {
                    Block = GetBlock(x,y,z);
                    if (BlockTransparent(x,y,z) == false || Block == 0) continue;

                    if(!BlockSpecial(x,y,z))
                        GetNormalBlock(x,y,z,iVertex,MeshChunk,Block,true);
                    else
                        GetSpecialBlock(x,y,z,iVertex,MeshChunk,Block,true);
                }
            }
        }
        MeshChunk->end();
    }
    else
    {
        MeshChunk->end();
        MeshChunk->created = false;
    }

    //MeshChunk->end();
    MeshChunk->id = mChunks.size();
    mTransparentChunks.push_back(MeshChunk);
}

void CraftWorld::rebuildChunk(int id)
{
    SimpleMeshChunk* MeshChunk = mChunks[id];

    int iVertex = 0;
    block_t Block;

    int StartZ = MeshChunk->chunkStartZ;
    int StartY = MeshChunk->chunkStartY;
    int StartX = MeshChunk->chunkStartX;

    MeshChunk->reset();

    for (int z = StartZ; z < CHUNK_SIZE + StartZ; ++z)
    {
        for (int y = StartY; y < CHUNK_SIZE + StartY; ++y)
        {
            for (int x = StartX; x < CHUNK_SIZE + StartX; ++x)
            {
                Block = GetBlock(x,y,z);
                if(BlockTransparent(x,y,z) == true)continue;//if block is transparent don't continue

                if(!BlockSpecial(x,y,z))
                    GetNormalBlock(x,y,z,iVertex,MeshChunk,Block,false);
                else
                    GetSpecialBlock(x,y,z,iVertex,MeshChunk,Block,false);
            }
        }
    }

    MeshChunk->end();
}

void CraftWorld::rebuildTransparentChunk(int id)
{
    SimpleMeshChunk* MeshChunk = mTransparentChunks[id];

    int iVertex = 0;
    block_t Block;

    int StartZ = MeshChunk->chunkStartZ;
    int StartY = MeshChunk->chunkStartY;
    int StartX = MeshChunk->chunkStartX;

    MeshChunk->reset();

    for (int z = StartZ; z < CHUNK_SIZE + StartZ; ++z)
    {
        for (int y = StartY; y < CHUNK_SIZE + StartY; ++y)
        {
            for (int x = StartX; x < CHUNK_SIZE + StartX; ++x)
            {
                Block = GetBlock(x,y,z);
                if (BlockTransparent(x,y,z) == false || Block == 0) continue;

                if(!BlockSpecial(x,y,z))
                    GetNormalBlock(x,y,z,iVertex,MeshChunk,Block,true);
                else
                    GetSpecialBlock(x,y,z,iVertex,MeshChunk,Block,true);
            }
        }
    }

    MeshChunk->end();
}

void CraftWorld::GetSpecialBlock(int x,int y, int z,int &iVertex,SimpleMeshChunk* MeshChunk,block_t Block,bool transparent)
{

    if( Block == TrapDoor::getID())
    {
        /* Only create visible faces of each chunk */
        bool DefaultBlock = false;
        bool transparentBlock;

        block_t Block1 = 0;

        Vector3 light1,light2,light3,light4;
        float BaseLight = 1.0f;

        Vector3 BlockColory1;    //Top face
        Vector3 BlockColory2;    //Bottom face
        Vector3 BlockColorx1;    //Sunset face
        Vector3 BlockColorx2;    //Sunrise face
        Vector3 BlockColorz1;     //Front/back faces
        Vector3 BlockColorz2;     //Front/back faces

        //texture stuff
        BaseBlock *blockType = &blockTypes[Block];

        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent;

        float left = percent * blockType->upPlane;
        float right = left + percent;

        bool canCreate = false;

        //lightened
        //if time is between 21-4 use settings table for lightening
        //if time is between 5-20 use normal light table but compare it with settings table
        //	if setting is brighter then use it
        if(worldDayTime >= 21 || worldDayTime <= 4)//night
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                BaseLight  = (float)(GetBlockSettings(x, y, z) & 0xF)/16.0f; // 255.0f;  //For the two x faces

                BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                BlockColorz1  = BlockColorz2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
            }
            else //normal light
            {
                //light
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;  //For the two x faces
                //float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
                //float BlockLight2 = BlockLight * 0.8f;		//For the two y faces

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }
        else //day
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                //int normal = GetBlockLight(x, y, z);
                //int lightened = (GetBlockSettings(x, y, z) & 0xF) * 16;

                float normal = lightColor.x * (factor1 * (GetBlockLight(x, y, z) / 255.0f)) + ambientColor.x;
                float lightened = (GetBlockSettings(x, y, z) & 0xF) / 15.0f;

                if(lightened > normal)
                {
                    BaseLight = lightened; // 255.0f;
                    BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                    BlockColorz2 = BlockColorz1  = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                    BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
                }
                else
                {
                    BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                    BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                    BlockColory1.saturate();
                    BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                    BlockColory2.saturate();
                    BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                    BlockColorz1.saturate();
                    BlockColorz1 *= 0.80f;
                    BlockColorz2 = BlockColorz1;

                    BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx1.saturate();
                    BlockColorx1 *= 0.95f;

                    BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx2.saturate();
                    BlockColorx2 *= 0.95f;
                }

            }
            else
            {
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }

        //faces
        //x-1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (x > 0)
            {
                transparentBlock = BlockTransparent(x-1,y,z);
                Block1 = GetBlock(x-1,y,z);
            }

            if (transparentBlock == true || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (x > 0)transparentBlock = BlockTransparentOrSpecial(x-1,y,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x-1,y,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x-1, y, z) & 0xF) / 15.0f;
                if(lightened > BlockColorx1.x)
                    BlockColorx1.x = BlockColorx1.y = BlockColorx1.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorx1;
            lightFactor = BlockColorx1 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x-1,y+0.2,z) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y+0.2,z+1))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x-1,y+0.2,z) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y+0.2,z-1))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x-1,y-0.2,z) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y-0.2,z+1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x-1,y-0.2,z) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y-0.2,z-1))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x, y,   z+1);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x, y+0.2, z+1);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x, y+0.2, z);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x, y,   z);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }


        //x+1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (x < WORLD_SIZE - 1)
            {
                transparentBlock = BlockTransparent(x+1,y,z);
                Block1 = GetBlock(x+1,y,z);
            }

            if (transparentBlock == true || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (x < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x+1,y,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x+1, y, z) & 0xF) / 15.0f;
                if(lightened > BlockColorx2.x)
                    BlockColorx2.x = BlockColorx2.y = BlockColorx2.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorx2;
            lightFactor = BlockColorx2 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x+1,y+0.2,z) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y+0.2,z+1))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+1,y+0.2,z) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y+0.2,z-1))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x+1,y-0.2,z) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y-0.2,z+1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+1,y-0.2,z) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y-0.2,z-1))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x+1, y,   z);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x+1, y+0.2, z);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x+1, y+0.2, z+1);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+1, y,   z+1);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }

        //y-1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (y > 0)
            {
                transparentBlock = BlockTransparent(x,y-0.2,z);
                Block1 = GetBlock(x,y-0.2,z);
            }

            if (transparentBlock == true || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (y > 0)transparentBlock = BlockTransparentOrSpecial(x,y-0.2,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            //up
            left = percent * blockType->downPlane;
            right = left + percent;

            if((GetBlockSettings(x,y-0.2,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y-0.2, z) & 0xF) / 15.0f;
                if(lightened > BlockColory2.x)
                    BlockColory2.x = BlockColory2.y = BlockColory2.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColory2;
            lightFactor = BlockColory1 * lightShadowFactor;

            //simple shadows
            if(!BlockTransparentOrLightSource(x-1,y-0.2,z) || !BlockTransparentOrLightSource(x-1,y-0.2,z-1) || !BlockTransparentOrLightSource(x,y-0.2,z-1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.2,z-1) || !BlockTransparentOrLightSource(x+1,y-0.2,z-1) || !BlockTransparentOrLightSource(x+1,y-0.5,z))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+1,y-0.2,z) || !BlockTransparentOrLightSource(x+1,y-0.2,z+1) || !BlockTransparentOrLightSource(x,y-0.2,z+1))
            {
                light3-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.2,z+1) || !BlockTransparentOrLightSource(x-1,y-0.2,z+1) || !BlockTransparentOrLightSource(x-1,y-0.2,z))
            {
                light4-=lightFactor;
            }

            MeshChunk->position(x,   y, z);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x+1, y, z);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+1 , y, z+1);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x,   y, z+1);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light4.x,light4.y,light4.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }


        //top face
        //y+1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (y < WORLD_SIZE - 1)
            {
                transparentBlock = BlockTransparent(x,y+0.2,z);
                Block1 = GetBlock(x,y+0.2,z);
            }

            if (transparentBlock == true || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (y < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y+0.5,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            if((GetBlockSettings(x,y+0.2,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y+0.2, z) & 0xF) / 15.0f;
                if(lightened > BlockColory1.x)
                    BlockColory1.x = BlockColory1.y = BlockColory1.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColory1;
            lightFactor = BlockColory2 * lightShadowFactor;

            //simple shadows
            if(!BlockTransparentOrLightSource(x,y+0.2,z+1) || !BlockTransparentOrLightSource(x-1,y+0.2,z+1) || !BlockTransparentOrLightSource(x-1,y+0.2,z))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y+0.2,z+1) || !BlockTransparentOrLightSource(x+1,y+0.2,z+1) || !BlockTransparentOrLightSource(x+1,y+0.2,z))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+1,y+0.2,z) || !BlockTransparentOrLightSource(x+1,y+0.2,z-1) || !BlockTransparentOrLightSource(x,y+0.2,z-1))
            {
                light3-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y+0.2,z-1) || !BlockTransparentOrLightSource(x-1,y+0.2,z-1) || !BlockTransparentOrLightSource(x-1,y+0.2,z))
            {
                light4-=lightFactor;
            }

            //down
            left = percent * blockType->upPlane;
            right = left + percent;

            MeshChunk->position(x,   y+0.2, z+1);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x+1, y+0.2, z+1);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+1, y+0.2, z);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x,   y+0.2, z);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light4.x,light4.y,light4.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }

        //z-1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (z > 0)
            {
                transparentBlock = BlockTransparent(x,y,z-1);
                Block1 = GetBlock(x,y,z-1);
            }

            if (transparentBlock == true || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (z > 0)transparentBlock = BlockTransparentOrSpecial(x,y,z-1);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x,y,z-0.9) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y, z-1) & 0xF) / 15.0f;
                if(lightened > BlockColorz1.x)
                    BlockColorz1.x = BlockColorz1.y = BlockColorz1.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorz1;
            lightFactor = BlockColorz1 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x,y+0.2,z-1) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y+0.2,z-1))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y+0.2,z-1) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y+0.2,z-1))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x,y-0.2,z-1) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y-0.2,z-1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.2,z-1) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y-0.2,z-1))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x,   y+0.2, z);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+1, y+0.2, z);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x+1, y,   z);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x,   y,   z);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }


        //z+1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (z < WORLD_SIZE - 1)
            {
                transparentBlock = BlockTransparent(x,y,z+1);
                Block1 = GetBlock(x,y,z+1);
            }

            if (transparentBlock == true || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (z < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y,z+1);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate == true)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x,y,z+1) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y, z+1) & 0xF) / 15.0f;
                if(lightened > BlockColorz2.x)
                    BlockColorz2.x = BlockColorz2.y = BlockColorz2.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorz2;
            lightFactor = BlockColorz2 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x,y+0.2,z+1) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y+0.2,z+1))
            {
                light2-=lightFactor;
            }
            if(!BlockTransparentOrLightSource(x,y+0.2,z+1) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y+0.2,z+1))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x,y-0.2,z+1) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y-0.2,z+1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.2,z+1) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y-0.2,z+1))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x,   y,   z+1);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x+1, y,   z+1);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x+1, y+0.2, z+1);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x,   y+0.2, z+1);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }
    }

    if( Block == WaterBlock::getID())
    {
        /* Only create visible faces of each chunk */
        bool DefaultBlock = true;
        bool transparentBlock;

        block_t Block1 = 0;

        Vector3 light1,light2,light3,light4;
        float BaseLight = 1.0f;

        Vector3 BlockColory1;    //Top face
        Vector3 BlockColory2;    //Bottom face
        Vector3 BlockColorx1;    //Sunset face
        Vector3 BlockColorx2;    //Sunrise face
        Vector3 BlockColorz1;     //Front/back faces
        Vector3 BlockColorz2;     //Front/back faces

        //texture stuff
        BaseBlock *blockType = &blockTypes[Block];

        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent;

        float left = percent * blockType->upPlane;
        float right = left + percent;

        bool canCreate = false;

        //lightened
        //if time is between 21-4 use settings table for lightening
        //if time is between 5-20 use normal light table but compare it with settings table
        //	if setting is brighter then use it
        if(worldDayTime >= 21 || worldDayTime <= 4)//night
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                BaseLight  = (float)(GetBlockSettings(x, y, z) & 0xF)/16.0f; // 255.0f;  //For the two x faces

                BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                BlockColorz1  = BlockColorz2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
            }
            else //normal light
            {
                //light
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;  //For the two x faces
                //float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
                //float BlockLight2 = BlockLight * 0.8f;		//For the two y faces

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }
        else //day
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                //int normal = GetBlockLight(x, y, z);
                //int lightened = (GetBlockSettings(x, y, z) & 0xF) * 16;

                float normal = lightColor.x * (factor1 * (GetBlockLight(x, y, z) / 255.0f)) + ambientColor.x;
                float lightened = (GetBlockSettings(x, y, z) & 0xF) / 15.0f;

                if(lightened > normal)
                {
                    BaseLight = lightened; // 255.0f;
                    BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                    BlockColorz2 = BlockColorz1  = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                    BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
                }
                else
                {
                    BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                    BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                    BlockColory1.saturate();
                    BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                    BlockColory2.saturate();
                    BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                    BlockColorz1.saturate();
                    BlockColorz1 *= 0.80f;
                    BlockColorz2 = BlockColorz1;

                    BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx1.saturate();
                    BlockColorx1 *= 0.95f;

                    BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx2.saturate();
                    BlockColorx2 *= 0.95f;
                }

            }
            else
            {
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }

        //faces
        //x-1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (x > 0)
            {
                transparentBlock = BlockTransparent(x-1,y,z);
                Block1 = GetBlock(x-1,y,z);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (x > 0)transparentBlock = BlockTransparentOrSpecial(x-1,y,z);
            if (transparentBlock == false)
                canCreate = true;
        }

        if(GetBlock(x,y+1,z) != WaterBlock::getID())
        {
            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x-1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x-1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx1.x)
                        BlockColorx1.x = BlockColorx1.y = BlockColorx1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx1;
                lightFactor = BlockColorx1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x-1,y+0.9,z) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y+0.9,z+1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-1,y+0.9,z) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y+0.9,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x-1,y-0.9,z) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y-0.9,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-1,y-0.9,z) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y-0.9,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x, y,   z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x, y+0.9, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x, y+0.9, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //x+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x+1,y,z);
                    Block1 = GetBlock(x+1,y,z);
                }

                if (transparentBlock == false || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x+1,y,z);
                if (transparentBlock == false)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x+1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx2.x)
                        BlockColorx2.x = BlockColorx2.y = BlockColorx2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx2;
                lightFactor = BlockColorx2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x+1,y+0.9,z) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y+0.9,z+1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y+0.9,z) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y+0.9,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x+1,y-0.9,z) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y-0.9,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y-0.9,z) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y-0.9,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x+1, y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+1, y+0.9, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+1, y+0.9, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y,   z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //y-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y > 0)
                {
                    transparentBlock = BlockTransparent(x,y-0.9,z);
                    Block1 = GetBlock(x,y-0.9,z);
                }

                if (transparentBlock == false || Block1 == 0)
                    canCreate = true;
                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y > 0)transparentBlock = BlockTransparentOrSpecial(x,y-0.9,z);
                if (transparentBlock == false)
                    canCreate = true;
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                //up
                left = percent * blockType->downPlane;
                right = left + percent;

                if((GetBlockSettings(x,y-0.9,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y-0.9, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory2.x)
                        BlockColory2.x = BlockColory2.y = BlockColory2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory2;
                lightFactor = BlockColory1 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x-1,y-0.9,z) || !BlockTransparentOrLightSource(x-1,y-0.9,z-1) || !BlockTransparentOrLightSource(x,y-0.9,z-1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-0.9,z-1) || !BlockTransparentOrLightSource(x+1,y-0.9,z-1) || !BlockTransparentOrLightSource(x+1,y-0.5,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y-0.9,z) || !BlockTransparentOrLightSource(x+1,y-0.9,z+1) || !BlockTransparentOrLightSource(x,y-0.9,z+1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-0.9,z+1) || !BlockTransparentOrLightSource(x-1,y-0.9,z+1) || !BlockTransparentOrLightSource(x-1,y-0.9,z))
                {
                    light4-=lightFactor;
                }

                MeshChunk->position(x,   y, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1 , y, z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y, z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //top face
            //y+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y+0.9,z);
                    Block1 = GetBlock(x,y+0.9,z);
                }

                if (transparentBlock == false || Block1 == 0)
                    canCreate = true;
                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y+0.5,z);
                if (transparentBlock == false)
                    canCreate = true;
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                if((GetBlockSettings(x,y+0.9,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y+0.9, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory1.x)
                        BlockColory1.x = BlockColory1.y = BlockColory1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory1;
                lightFactor = BlockColory2 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x,y+0.9,z+1) || !BlockTransparentOrLightSource(x-1,y+0.9,z+1) || !BlockTransparentOrLightSource(x-1,y+0.9,z))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+0.9,z+1) || !BlockTransparentOrLightSource(x+1,y+0.9,z+1) || !BlockTransparentOrLightSource(x+1,y+0.9,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y+0.9,z) || !BlockTransparentOrLightSource(x+1,y+0.9,z-1) || !BlockTransparentOrLightSource(x,y+0.9,z-1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+0.9,z-1) || !BlockTransparentOrLightSource(x-1,y+0.9,z-1) || !BlockTransparentOrLightSource(x-1,y+0.9,z))
                {
                    light4-=lightFactor;
                }

                //down
                left = percent * blockType->upPlane;
                right = left + percent;

                MeshChunk->position(x,   y+0.9, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y+0.9, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y+0.9, z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y+0.9, z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //z-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z > 0)
                {
                    transparentBlock = BlockTransparent(x,y,z-1);
                    Block1 = GetBlock(x,y,z-1);
                }

                if (transparentBlock == false || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z > 0)transparentBlock = BlockTransparentOrSpecial(x,y,z-1);
                if (transparentBlock == false)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z-0.9) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z-1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz1.x)
                        BlockColorz1.x = BlockColorz1.y = BlockColorz1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz1;
                lightFactor = BlockColorz1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+0.9,z-1) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y+0.9,z-1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+0.9,z-1) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y+0.9,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-0.9,z-1) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y-0.9,z-1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-0.9,z-1) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y-0.9,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y+0.9, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y+0.9, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+1, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //z+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y,z+1);
                    Block1 = GetBlock(x,y,z+1);
                }

                if (transparentBlock == false || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y,z+1);
                if (transparentBlock == false)
                    canCreate = true;
            }

            if (canCreate == true)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z+1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z+1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz2.x)
                        BlockColorz2.x = BlockColorz2.y = BlockColorz2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz2;
                lightFactor = BlockColorz2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+0.9,z+1) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y+0.9,z+1))
                {
                    light2-=lightFactor;
                }
                if(!BlockTransparentOrLightSource(x,y+0.9,z+1) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y+0.9,z+1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-0.9,z+1) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y-0.9,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-0.9,z+1) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y-0.9,z+1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y,   z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y,   z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+1, y+0.9, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x,   y+0.9, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }
        }
        else
        {
            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x-1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x-1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx1.x)
                        BlockColorx1.x = BlockColorx1.y = BlockColorx1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx1;
                lightFactor = BlockColorx1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x-1,y+1,z) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y+1,z+1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-1,y+1,z) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x, y,   z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //x+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x+1,y,z);
                    Block1 = GetBlock(x+1,y,z);
                }

                if (transparentBlock == false || Block1 == 0)
                    canCreate = true;

            }
            else
            {
                if (x < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x+1,y,z);
                if (transparentBlock == false)
                    canCreate = true;

            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x+1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx2.x)
                        BlockColorx2.x = BlockColorx2.y = BlockColorx2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx2;
                lightFactor = BlockColorx2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y+1,z+1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x+1, y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+1, y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+1, y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y,   z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //y-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y > 0)
                {
                    transparentBlock = BlockTransparent(x,y-1,z);
                    Block1 = GetBlock(x,y-1,z);
                }

                if (transparentBlock == false || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y > 0)transparentBlock = BlockTransparentOrSpecial(x,y-1,z);
                if (transparentBlock == false)
                    canCreate = true;
            }

            if (canCreate)
            {
                //up
                left = percent * blockType->downPlane;
                right = left + percent;

                if((GetBlockSettings(x,y-1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y-1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory2.x)
                        BlockColory2.x = BlockColory2.y = BlockColory2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory2;
                lightFactor = BlockColory1 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y-1,z-1) || !BlockTransparentOrLightSource(x,y-1,z-1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x+1,y-1,z-1) || !BlockTransparentOrLightSource(x+1,y-0.5,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y-1,z+1) || !BlockTransparentOrLightSource(x,y-1,z+1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-1,y-1,z+1) || !BlockTransparentOrLightSource(x-1,y-1,z))
                {
                    light4-=lightFactor;
                }

                MeshChunk->position(x,   y, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1 , y, z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y, z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //top face
            //y+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y+1,z);
                    Block1 = GetBlock(x,y+1,z);
                }

                if (transparentBlock == false || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y+0.5,z);
                if (transparentBlock == false)
                    canCreate = true;
            }

            if (canCreate)
            {
                if((GetBlockSettings(x,y+1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y+1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory1.x)
                        BlockColory1.x = BlockColory1.y = BlockColory1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory1;
                lightFactor = BlockColory2 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x-1,y+1,z+1) || !BlockTransparentOrLightSource(x-1,y+1,z))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x+1,y+1,z+1) || !BlockTransparentOrLightSource(x+1,y+1,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y+1,z-1) || !BlockTransparentOrLightSource(x,y+1,z-1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x-1,y+1,z-1) || !BlockTransparentOrLightSource(x-1,y+1,z))
                {
                    light4-=lightFactor;
                }

                //down
                left = percent * blockType->upPlane;
                right = left + percent;

                MeshChunk->position(x,   y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y+1, z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //z-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z > 0)
                {
                    transparentBlock = BlockTransparent(x,y,z-1);
                    Block1 = GetBlock(x,y,z-1);
                }

                if (transparentBlock == false || Block1 == 0)
                    canCreate = true;

            }
            else
            {
                if (z > 0)transparentBlock = BlockTransparentOrSpecial(x,y,z-1);
                if (transparentBlock == false)
                    canCreate = true;

            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z-1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z-1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz1.x)
                        BlockColorz1.x = BlockColorz1.y = BlockColorz1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz1;
                lightFactor = BlockColorz1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y+1,z-1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y-1,z-1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+1, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //z+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y,z+1);
                    Block1 = GetBlock(x,y,z+1);
                }

                if (transparentBlock == false || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y,z+1);
                if (transparentBlock == false)
                    canCreate = true;
            }

            if (canCreate == true)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z+1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z+1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz2.x)
                        BlockColorz2.x = BlockColorz2.y = BlockColorz2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz2;
                lightFactor = BlockColorz2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y+1,z+1))
                {
                    light2-=lightFactor;
                }
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y+1,z+1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y-1,z+1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y,   z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y,   z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+1, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x,   y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }
        }
    }

    if( Block == Lava::getID())
    {
        /* Only create visible faces of each chunk */
        bool DefaultBlock = true;
        bool transparentBlock;

        block_t Block1 = 0;

        Vector3 light1,light2,light3,light4;
        float BaseLight = 1.0f;

        Vector3 BlockColory1;    //Top face
        Vector3 BlockColory2;    //Bottom face
        Vector3 BlockColorx1;    //Sunset face
        Vector3 BlockColorx2;    //Sunrise face
        Vector3 BlockColorz1;     //Front/back faces
        Vector3 BlockColorz2;     //Front/back faces

        //texture stuff
        BaseBlock *blockType = &blockTypes[Block];

        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent;

        float left = percent * blockType->upPlane;
        float right = left + percent;

        bool canCreate = false;

        //lightened
        //if time is between 21-4 use settings table for lightening
        //if time is between 5-20 use normal light table but compare it with settings table
        //	if setting is brighter then use it
        if(worldDayTime >= 21 || worldDayTime <= 4)//night
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                BaseLight  = (float)(GetBlockSettings(x, y, z) & 0xF)/16.0f; // 255.0f;  //For the two x faces

                BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                BlockColorz1  = BlockColorz2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
            }
            else //normal light
            {
                //light
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;  //For the two x faces
                //float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
                //float BlockLight2 = BlockLight * 0.8f;		//For the two y faces

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }
        else //day
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                //int normal = GetBlockLight(x, y, z);
                //int lightened = (GetBlockSettings(x, y, z) & 0xF) * 16;

                float normal = lightColor.x * (factor1 * (GetBlockLight(x, y, z) / 255.0f)) + ambientColor.x;
                float lightened = (GetBlockSettings(x, y, z) & 0xF) / 15.0f;

                if(lightened > normal)
                {
                    BaseLight = lightened; // 255.0f;
                    BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                    BlockColorz2 = BlockColorz1  = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                    BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
                }
                else
                {
                    BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                    BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                    BlockColory1.saturate();
                    BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                    BlockColory2.saturate();
                    BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                    BlockColorz1.saturate();
                    BlockColorz1 *= 0.80f;
                    BlockColorz2 = BlockColorz1;

                    BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx1.saturate();
                    BlockColorx1 *= 0.95f;

                    BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx2.saturate();
                    BlockColorx2 *= 0.95f;
                }

            }
            else
            {
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }

        //faces
        //x-1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (x > 0)
            {
                transparentBlock = BlockTransparent(x-1,y,z);
                Block1 = GetBlock(x-1,y,z);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (x > 0)transparentBlock = BlockTransparentOrSpecial(x-1,y,z);
            if (transparentBlock == false)
                canCreate = true;
        }

        if(GetBlock(x,y+1,z) != Lava::getID())
        {
            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x-1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x-1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx1.x)
                        BlockColorx1.x = BlockColorx1.y = BlockColorx1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx1;
                lightFactor = BlockColorx1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x-1,y+0.9,z) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y+0.9,z+1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-1,y+0.9,z) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y+0.9,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x-1,y-0.9,z) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y-0.9,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-1,y-0.9,z) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y-0.9,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x, y,   z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x, y+0.9, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x, y+0.9, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //x+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x+1,y,z);
                    Block1 = GetBlock(x+1,y,z);
                }

                if (transparentBlock == false || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x+1,y,z);
                if (transparentBlock == false)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x+1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx2.x)
                        BlockColorx2.x = BlockColorx2.y = BlockColorx2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx2;
                lightFactor = BlockColorx2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x+1,y+0.9,z) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y+0.9,z+1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y+0.9,z) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y+0.9,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x+1,y-0.9,z) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y-0.9,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y-0.9,z) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y-0.9,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x+1, y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+1, y+0.9, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+1, y+0.9, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y,   z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //y-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y > 0)
                {
                    transparentBlock = BlockTransparent(x,y-0.9,z);
                    Block1 = GetBlock(x,y-0.9,z);
                }

                if (transparentBlock == false || Block1 == 0)
                    canCreate = true;
                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y > 0)transparentBlock = BlockTransparentOrSpecial(x,y-0.9,z);
                if (transparentBlock == false)
                    canCreate = true;
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                //up
                left = percent * blockType->downPlane;
                right = left + percent;

                if((GetBlockSettings(x,y-0.9,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y-0.9, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory2.x)
                        BlockColory2.x = BlockColory2.y = BlockColory2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory2;
                lightFactor = BlockColory1 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x-1,y-0.9,z) || !BlockTransparentOrLightSource(x-1,y-0.9,z-1) || !BlockTransparentOrLightSource(x,y-0.9,z-1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-0.9,z-1) || !BlockTransparentOrLightSource(x+1,y-0.9,z-1) || !BlockTransparentOrLightSource(x+1,y-0.5,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y-0.9,z) || !BlockTransparentOrLightSource(x+1,y-0.9,z+1) || !BlockTransparentOrLightSource(x,y-0.9,z+1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-0.9,z+1) || !BlockTransparentOrLightSource(x-1,y-0.9,z+1) || !BlockTransparentOrLightSource(x-1,y-0.9,z))
                {
                    light4-=lightFactor;
                }

                MeshChunk->position(x,   y, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1 , y, z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y, z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //top face
            //y+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y+0.9,z);
                    Block1 = GetBlock(x,y+0.9,z);
                }

                if (transparentBlock == false || Block1 == 0)
                    canCreate = true;
                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y+0.5,z);
                if (transparentBlock == false)
                    canCreate = true;
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                if((GetBlockSettings(x,y+0.9,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y+0.9, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory1.x)
                        BlockColory1.x = BlockColory1.y = BlockColory1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory1;
                lightFactor = BlockColory2 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x,y+0.9,z+1) || !BlockTransparentOrLightSource(x-1,y+0.9,z+1) || !BlockTransparentOrLightSource(x-1,y+0.9,z))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+0.9,z+1) || !BlockTransparentOrLightSource(x+1,y+0.9,z+1) || !BlockTransparentOrLightSource(x+1,y+0.9,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y+0.9,z) || !BlockTransparentOrLightSource(x+1,y+0.9,z-1) || !BlockTransparentOrLightSource(x,y+0.9,z-1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+0.9,z-1) || !BlockTransparentOrLightSource(x-1,y+0.9,z-1) || !BlockTransparentOrLightSource(x-1,y+0.9,z))
                {
                    light4-=lightFactor;
                }

                //down
                left = percent * blockType->upPlane;
                right = left + percent;

                MeshChunk->position(x,   y+0.9, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y+0.9, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y+0.9, z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y+0.9, z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //z-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z > 0)
                {
                    transparentBlock = BlockTransparent(x,y,z-1);
                    Block1 = GetBlock(x,y,z-1);
                }

                if (transparentBlock == false || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z > 0)transparentBlock = BlockTransparentOrSpecial(x,y,z-1);
                if (transparentBlock == false)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z-0.9) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z-1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz1.x)
                        BlockColorz1.x = BlockColorz1.y = BlockColorz1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz1;
                lightFactor = BlockColorz1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+0.9,z-1) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y+0.9,z-1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+0.9,z-1) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y+0.9,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-0.9,z-1) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y-0.9,z-1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-0.9,z-1) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y-0.9,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y+0.9, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y+0.9, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+1, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //z+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y,z+1);
                    Block1 = GetBlock(x,y,z+1);
                }

                if (transparentBlock == false || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y,z+1);
                if (transparentBlock == false)
                    canCreate = true;
            }

            if (canCreate == true)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z+1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z+1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz2.x)
                        BlockColorz2.x = BlockColorz2.y = BlockColorz2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz2;
                lightFactor = BlockColorz2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+0.9,z+1) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y+0.9,z+1))
                {
                    light2-=lightFactor;
                }
                if(!BlockTransparentOrLightSource(x,y+0.9,z+1) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y+0.9,z+1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-0.9,z+1) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y-0.9,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-0.9,z+1) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y-0.9,z+1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y,   z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y,   z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+1, y+0.9, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x,   y+0.9, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }
        }
        else
        {
            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x-1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x-1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx1.x)
                        BlockColorx1.x = BlockColorx1.y = BlockColorx1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx1;
                lightFactor = BlockColorx1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x-1,y+1,z) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y+1,z+1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-1,y+1,z) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x, y,   z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //x+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x+1,y,z);
                    Block1 = GetBlock(x+1,y,z);
                }

                if (transparentBlock == false || Block1 == 0)
                    canCreate = true;

            }
            else
            {
                if (x < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x+1,y,z);
                if (transparentBlock == false)
                    canCreate = true;

            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x+1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx2.x)
                        BlockColorx2.x = BlockColorx2.y = BlockColorx2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx2;
                lightFactor = BlockColorx2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y+1,z+1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x+1, y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+1, y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+1, y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y,   z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //y-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y > 0)
                {
                    transparentBlock = BlockTransparent(x,y-1,z);
                    Block1 = GetBlock(x,y-1,z);
                }

                if (transparentBlock == false || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y > 0)transparentBlock = BlockTransparentOrSpecial(x,y-1,z);
                if (transparentBlock == false)
                    canCreate = true;
            }

            if (canCreate)
            {
                //up
                left = percent * blockType->downPlane;
                right = left + percent;

                if((GetBlockSettings(x,y-1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y-1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory2.x)
                        BlockColory2.x = BlockColory2.y = BlockColory2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory2;
                lightFactor = BlockColory1 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y-1,z-1) || !BlockTransparentOrLightSource(x,y-1,z-1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x+1,y-1,z-1) || !BlockTransparentOrLightSource(x+1,y-0.5,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y-1,z+1) || !BlockTransparentOrLightSource(x,y-1,z+1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-1,y-1,z+1) || !BlockTransparentOrLightSource(x-1,y-1,z))
                {
                    light4-=lightFactor;
                }

                MeshChunk->position(x,   y, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1 , y, z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y, z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //top face
            //y+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y+1,z);
                    Block1 = GetBlock(x,y+1,z);
                }

                if (transparentBlock == false || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y+0.5,z);
                if (transparentBlock == false)
                    canCreate = true;
            }

            if (canCreate)
            {
                if((GetBlockSettings(x,y+1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y+1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory1.x)
                        BlockColory1.x = BlockColory1.y = BlockColory1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory1;
                lightFactor = BlockColory2 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x-1,y+1,z+1) || !BlockTransparentOrLightSource(x-1,y+1,z))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x+1,y+1,z+1) || !BlockTransparentOrLightSource(x+1,y+1,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y+1,z-1) || !BlockTransparentOrLightSource(x,y+1,z-1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x-1,y+1,z-1) || !BlockTransparentOrLightSource(x-1,y+1,z))
                {
                    light4-=lightFactor;
                }

                //down
                left = percent * blockType->upPlane;
                right = left + percent;

                MeshChunk->position(x,   y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y+1, z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //z-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z > 0)
                {
                    transparentBlock = BlockTransparent(x,y,z-1);
                    Block1 = GetBlock(x,y,z-1);
                }

                if (transparentBlock == false || Block1 == 0)
                    canCreate = true;

            }
            else
            {
                if (z > 0)transparentBlock = BlockTransparentOrSpecial(x,y,z-1);
                if (transparentBlock == false)
                    canCreate = true;

            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z-1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z-1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz1.x)
                        BlockColorz1.x = BlockColorz1.y = BlockColorz1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz1;
                lightFactor = BlockColorz1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y+1,z-1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y-1,z-1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+1, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //z+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y,z+1);
                    Block1 = GetBlock(x,y,z+1);
                }

                if (transparentBlock == false || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y,z+1);
                if (transparentBlock == false)
                    canCreate = true;
            }

            if (canCreate == true)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z+1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z+1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz2.x)
                        BlockColorz2.x = BlockColorz2.y = BlockColorz2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz2;
                lightFactor = BlockColorz2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y+1,z+1))
                {
                    light2-=lightFactor;
                }
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y+1,z+1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y-1,z+1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y,   z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y,   z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+1, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x,   y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }
        }
    }
    
    
    if( Block == Door1::getID() || Block == Door2::getID() || Block == TrapDoor2::getID())
    {
        //after place make full door
        if(GetBlock(x,y,z) == Door2::getID())
        {
            GetBlock(x,y+1,z) = Door1::getID();
        }
        /* Only create visible faces of each chunk */
        bool DefaultBlock = false;
        bool transparentBlock;

        block_t Block1 = 0;

        Vector3 light1,light2,light3,light4;
        float BaseLight = 1.0f;

        Vector3 BlockColory1;    //Top face
        Vector3 BlockColory2;    //Bottom face
        Vector3 BlockColorx1;    //Sunset face
        Vector3 BlockColorx2;    //Sunrise face
        Vector3 BlockColorz1;     //Front/back faces
        Vector3 BlockColorz2;     //Front/back faces

        //texture stuff
        BaseBlock *blockType = &blockTypes[Block];

        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent;

        float left = percent * blockType->upPlane;
        float right = left + percent;

        bool canCreate = false;

        //lightened
        //if time is between 21-4 use settings table for lightening
        //if time is between 5-20 use normal light table but compare it with settings table
        //	if setting is brighter then use it
        if(worldDayTime >= 21 || worldDayTime <= 4)//night
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                BaseLight  = (float)(GetBlockSettings(x, y, z) & 0xF)/16.0f; // 255.0f;  //For the two x faces

                BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                BlockColorz1  = BlockColorz2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
            }
            else //normal light
            {
                //light
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;  //For the two x faces
                //float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
                //float BlockLight2 = BlockLight * 0.8f;		//For the two y faces

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }
        else //day
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                //int normal = GetBlockLight(x, y, z);
                //int lightened = (GetBlockSettings(x, y, z) & 0xF) * 16;

                float normal = lightColor.x * (factor1 * (GetBlockLight(x, y, z) / 255.0f)) + ambientColor.x;
                float lightened = (GetBlockSettings(x, y, z) & 0xF) / 15.0f;

                if(lightened > normal)
                {
                    BaseLight = lightened; // 255.0f;
                    BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                    BlockColorz2 = BlockColorz1  = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                    BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
                }
                else
                {
                    BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                    BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                    BlockColory1.saturate();
                    BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                    BlockColory2.saturate();
                    BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                    BlockColorz1.saturate();
                    BlockColorz1 *= 0.80f;
                    BlockColorz2 = BlockColorz1;

                    BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx1.saturate();
                    BlockColorx1 *= 0.95f;

                    BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx2.saturate();
                    BlockColorx2 *= 0.95f;
                }

            }
            else
            {
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }
        if(GetBlock(x+1,y,z) != 0 || GetBlock(x-1,y,z) != 0 || (GetBlock(x+1,y,z) != 0 && GetBlock(x-1,y,z) != 0))
        {
            //faces
            //x-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x > 0)
                {
                    transparentBlock = BlockTransparent(x-0.2,y,z);
                    Block1 = GetBlock(x-0.2,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x > 0)transparentBlock = BlockTransparentOrSpecial(x-1,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x-1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x-1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx1.x)
                        BlockColorx1.x = BlockColorx1.y = BlockColorx1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx1;
                lightFactor = BlockColorx1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x-0.2,y+1,z) || !BlockTransparentOrLightSource(x-0.2,y,z+1) || !BlockTransparentOrLightSource(x-0.2,y+1,z+1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-0.2,y+1,z) || !BlockTransparentOrLightSource(x-0.2,y,z-1) || !BlockTransparentOrLightSource(x-0.2,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x-0.2,y-1,z) || !BlockTransparentOrLightSource(x-0.2,y,z+1) || !BlockTransparentOrLightSource(x-0.2,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-0.2,y-1,z) || !BlockTransparentOrLightSource(x-0.2,y,z-1) || !BlockTransparentOrLightSource(x-0.2,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x, y,   z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //x+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x+0.2,y,z);
                    Block1 = GetBlock(x+0.2,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x+0.2,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x+1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx2.x)
                        BlockColorx2.x = BlockColorx2.y = BlockColorx2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx2;
                lightFactor = BlockColorx2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x+0.2,y+1,z) || !BlockTransparentOrLightSource(x+0.2,y,z+1) || !BlockTransparentOrLightSource(x+0.2,y+1,z+1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.2,y+1,z) || !BlockTransparentOrLightSource(x+0.2,y,z-1) || !BlockTransparentOrLightSource(x+0.2,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x+0.2,y-1,z) || !BlockTransparentOrLightSource(x+0.2,y,z+1) || !BlockTransparentOrLightSource(x+0.2,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.2,y-1,z) || !BlockTransparentOrLightSource(x+0.2,y,z-1) || !BlockTransparentOrLightSource(x+0.2,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x+0.2, y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+0.2, y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+0.2, y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.2, y,   z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //y-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y > 0)
                {
                    transparentBlock = BlockTransparent(x,y-1,z);
                    Block1 = GetBlock(x,y-1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y > 0)transparentBlock = BlockTransparentOrSpecial(x,y-1,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                //up
                left = percent * blockType->downPlane;
                right = left + percent;

                if((GetBlockSettings(x,y-1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y-1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory2.x)
                        BlockColory2.x = BlockColory2.y = BlockColory2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory2;
                lightFactor = BlockColory1 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x-0.2,y-1,z) || !BlockTransparentOrLightSource(x-0.2,y-1,z-1) || !BlockTransparentOrLightSource(x,y-1,z-1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x+0.2,y-1,z-1) || !BlockTransparentOrLightSource(x+0.2,y-0.5,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.2,y-1,z) || !BlockTransparentOrLightSource(x+0.2,y-1,z+1) || !BlockTransparentOrLightSource(x,y-1,z+1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-0.2,y-1,z+1) || !BlockTransparentOrLightSource(x-0.2,y-1,z))
                {
                    light4-=lightFactor;
                }

                MeshChunk->position(x,   y, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+0.2, y, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.2 , y, z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y, z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //top face
            //y+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y+1,z);
                    Block1 = GetBlock(x,y+1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y+0.5,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                if((GetBlockSettings(x,y+1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y+1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory1.x)
                        BlockColory1.x = BlockColory1.y = BlockColory1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory1;
                lightFactor = BlockColory2 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x-0.2,y+1,z+1) || !BlockTransparentOrLightSource(x-0.2,y+1,z))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x+0.2,y+1,z+1) || !BlockTransparentOrLightSource(x+0.2,y+1,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.2,y+1,z) || !BlockTransparentOrLightSource(x+0.2,y+1,z-1) || !BlockTransparentOrLightSource(x,y+1,z-1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x-0.2,y+1,z-1) || !BlockTransparentOrLightSource(x-0.2,y+1,z))
                {
                    light4-=lightFactor;
                }

                //down
                left = percent * blockType->upPlane;
                right = left + percent;

                MeshChunk->position(x,   y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+0.2, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.2, y+1, z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //z-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z > 0)
                {
                    transparentBlock = BlockTransparent(x,y,z-1);
                    Block1 = GetBlock(x,y,z-1);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z > 0)transparentBlock = BlockTransparentOrSpecial(x,y,z-1);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z-1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z-1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz1.x)
                        BlockColorz1.x = BlockColorz1.y = BlockColorz1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz1;
                lightFactor = BlockColorz1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x-0.2,y,z-1) || !BlockTransparentOrLightSource(x-0.2,y+1,z-1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x+0.2,y,z-1) || !BlockTransparentOrLightSource(x+0.2,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x-0.2,y,z-1) || !BlockTransparentOrLightSource(x-0.2,y-1,z-1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x+0.2,y,z-1) || !BlockTransparentOrLightSource(x+0.2,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.2, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+0.2, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //z+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y,z+1);
                    Block1 = GetBlock(x,y,z+1);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y,z+1);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate == true)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z+1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z+1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz2.x)
                        BlockColorz2.x = BlockColorz2.y = BlockColorz2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz2;
                lightFactor = BlockColorz2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x-0.2,y,z+1) || !BlockTransparentOrLightSource(x-0.2,y+1,z+1))
                {
                    light2-=lightFactor;
                }
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x+0.2,y,z+1) || !BlockTransparentOrLightSource(x+0.2,y+1,z+1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-0.2,y,z+1) || !BlockTransparentOrLightSource(x-0.2,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x+0.2,y,z+1) || !BlockTransparentOrLightSource(x+0.2,y-1,z+1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y,   z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+0.2, y,   z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+0.2, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x,   y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }
        }

        else if(GetBlock(x,y,z+1) != 0 || GetBlock(x,y,z-1) != 0 || (GetBlock(x,y,z+1) != 0 && GetBlock(x,y,z-1) != 0))
        {
            //faces
            //x-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x > 0)
                {
                    transparentBlock = BlockTransparent(x-1,y,z);
                    Block1 = GetBlock(x-1,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x > 0)transparentBlock = BlockTransparentOrSpecial(x-1,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x-1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x-1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx1.x)
                        BlockColorx1.x = BlockColorx1.y = BlockColorx1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx1;
                lightFactor = BlockColorx1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x-1,y+1,z) || !BlockTransparentOrLightSource(x-1,y,z+0.2) || !BlockTransparentOrLightSource(x-1,y+1,z+0.2))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-1,y+1,z) || !BlockTransparentOrLightSource(x-1,y,z-0.2) || !BlockTransparentOrLightSource(x-1,y+1,z-0.2))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y,z+0.2) || !BlockTransparentOrLightSource(x-1,y-1,z+0.2))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y,z-0.2) || !BlockTransparentOrLightSource(x-1,y-1,z-0.2))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x, y,   z+0.2);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x, y+1, z+0.2);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //x+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x+1,y,z);
                    Block1 = GetBlock(x+1,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x+1,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x+1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx2.x)
                        BlockColorx2.x = BlockColorx2.y = BlockColorx2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx2;
                lightFactor = BlockColorx2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y,z+0.2) || !BlockTransparentOrLightSource(x+1,y+1,z+0.2))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y,z-0.2) || !BlockTransparentOrLightSource(x+1,y+1,z-0.2))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y,z+0.2) || !BlockTransparentOrLightSource(x+1,y-1,z+0.2))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y,z-0.2) || !BlockTransparentOrLightSource(x+1,y-1,z-0.2))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x+1, y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+1, y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+1, y+1, z+0.2);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y,   z+0.2);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //y-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y > 0)
                {
                    transparentBlock = BlockTransparent(x,y-1,z);
                    Block1 = GetBlock(x,y-1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y > 0)transparentBlock = BlockTransparentOrSpecial(x,y-1,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                //up
                left = percent * blockType->downPlane;
                right = left + percent;

                if((GetBlockSettings(x,y-1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y-1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory2.x)
                        BlockColory2.x = BlockColory2.y = BlockColory2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory2;
                lightFactor = BlockColory1 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y-1,z-0.2) || !BlockTransparentOrLightSource(x,y-1,z-0.2))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-0.2) || !BlockTransparentOrLightSource(x+1,y-1,z-0.2) || !BlockTransparentOrLightSource(x+1,y-1,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y-1,z+0.2) || !BlockTransparentOrLightSource(x,y-1,z+0.2))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-1,y-1,z+0.2) || !BlockTransparentOrLightSource(x-1,y-1,z))
                {
                    light4-=lightFactor;
                }

                MeshChunk->position(x,   y, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1 , y, z+0.2);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y, z+0.2);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //top face
            //y+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y+1,z);
                    Block1 = GetBlock(x,y+1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y+1,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                if((GetBlockSettings(x,y+1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y+1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory1.x)
                        BlockColory1.x = BlockColory1.y = BlockColory1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory1;
                lightFactor = BlockColory2 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x,y+1,z+0.2) || !BlockTransparentOrLightSource(x-1,y+1,z+0.2) || !BlockTransparentOrLightSource(x-1,y+1,z))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z+0.2) || !BlockTransparentOrLightSource(x+1,y+1,z+0.2) || !BlockTransparentOrLightSource(x+1,y+1,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y+1,z-0.2) || !BlockTransparentOrLightSource(x,y+1,z-0.2))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-0.2) || !BlockTransparentOrLightSource(x-1,y+1,z-0.2) || !BlockTransparentOrLightSource(x-1,y+1,z))
                {
                    light4-=lightFactor;
                }

                //down
                left = percent * blockType->upPlane;
                right = left + percent;

                MeshChunk->position(x,   y+1, z+0.2);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y+1, z+0.2);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y+1, z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //z-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z > 0)
                {
                    transparentBlock = BlockTransparent(x,y,z-0.2);
                    Block1 = GetBlock(x,y,z-1);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z > 0)transparentBlock = BlockTransparentOrSpecial(x,y,z-0.2);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z-0.9) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z-1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz1.x)
                        BlockColorz1.x = BlockColorz1.y = BlockColorz1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz1;
                lightFactor = BlockColorz1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z-0.2) || !BlockTransparentOrLightSource(x-1,y,z-0.2) || !BlockTransparentOrLightSource(x-1,y+1,z-0.2))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-0.2) || !BlockTransparentOrLightSource(x+1,y,z-0.2) || !BlockTransparentOrLightSource(x+1,y+1,z-0.2))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z-0.2) || !BlockTransparentOrLightSource(x-1,y,z-0.2) || !BlockTransparentOrLightSource(x-1,y-1,z-0.2))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-0.2) || !BlockTransparentOrLightSource(x+1,y,z-0.2) || !BlockTransparentOrLightSource(x+1,y-1,z-0.2))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+1, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //z+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y,z+0.2);
                    Block1 = GetBlock(x,y,z+0.2);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y,z+1);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate == true)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z+1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z+1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz2.x)
                        BlockColorz2.x = BlockColorz2.y = BlockColorz2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz2;
                lightFactor = BlockColorz2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z+0.2) || !BlockTransparentOrLightSource(x-1,y,z+0.2) || !BlockTransparentOrLightSource(x-1,y+1,z+0.2))
                {
                    light2-=lightFactor;
                }
                if(!BlockTransparentOrLightSource(x,y+1,z+0.2) || !BlockTransparentOrLightSource(x+1,y,z+0.2) || !BlockTransparentOrLightSource(x+1,y+1,z+0.2))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z+0.2) || !BlockTransparentOrLightSource(x-1,y,z+0.2) || !BlockTransparentOrLightSource(x-1,y-1,z+0.2))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+0.2) || !BlockTransparentOrLightSource(x+1,y,z+0.2) || !BlockTransparentOrLightSource(x+1,y-1,z+0.2))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y,   z+0.2);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y,   z+0.2);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+1, y+1, z+0.2);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x,   y+1, z+0.2);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }
        }
        else
        {
            //faces
            //x-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x > 0)
                {
                    transparentBlock = BlockTransparent(x-1,y,z);
                    Block1 = GetBlock(x-1,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x > 0)transparentBlock = BlockTransparentOrSpecial(x-1,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x-1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x-1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx1.x)
                        BlockColorx1.x = BlockColorx1.y = BlockColorx1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx1;
                lightFactor = BlockColorx1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x-0.2,y+1,z) || !BlockTransparentOrLightSource(x-0.2,y,z+1) || !BlockTransparentOrLightSource(x-0.2,y+1,z+1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-0.2,y+1,z) || !BlockTransparentOrLightSource(x-0.2,y,z-1) || !BlockTransparentOrLightSource(x-0.2,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x-0.2,y-1,z) || !BlockTransparentOrLightSource(x-0.2,y,z+1) || !BlockTransparentOrLightSource(x-0.2,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-0.2,y-1,z) || !BlockTransparentOrLightSource(x-0.2,y,z-1) || !BlockTransparentOrLightSource(x-0.2,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x, y,   z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //x+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x+1,y,z);
                    Block1 = GetBlock(x+1,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x+1,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x+1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx2.x)
                        BlockColorx2.x = BlockColorx2.y = BlockColorx2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx2;
                lightFactor = BlockColorx2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x+0.2,y+1,z) || !BlockTransparentOrLightSource(x+0.2,y,z+1) || !BlockTransparentOrLightSource(x+0.2,y+1,z+1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.2,y+1,z) || !BlockTransparentOrLightSource(x+0.2,y,z-1) || !BlockTransparentOrLightSource(x+0.2,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x+0.2,y-1,z) || !BlockTransparentOrLightSource(x+0.2,y,z+1) || !BlockTransparentOrLightSource(x+0.2,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.2,y-1,z) || !BlockTransparentOrLightSource(x+0.2,y,z-1) || !BlockTransparentOrLightSource(x+0.2,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x+0.2, y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+0.2, y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+0.2, y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.2, y,   z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //y-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y > 0)
                {
                    transparentBlock = BlockTransparent(x,y-1,z);
                    Block1 = GetBlock(x,y-1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y > 0)transparentBlock = BlockTransparentOrSpecial(x,y-1,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                //up
                left = percent * blockType->downPlane;
                right = left + percent;

                if((GetBlockSettings(x,y-1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y-1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory2.x)
                        BlockColory2.x = BlockColory2.y = BlockColory2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory2;
                lightFactor = BlockColory1 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x-0.2,y-1,z) || !BlockTransparentOrLightSource(x-0.2,y-1,z-1) || !BlockTransparentOrLightSource(x,y-1,z-1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x+0.2,y-1,z-1) || !BlockTransparentOrLightSource(x+0.2,y-1,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.2,y-1,z) || !BlockTransparentOrLightSource(x+0.2,y-1,z+1) || !BlockTransparentOrLightSource(x,y-1,z+1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-0.2,y-1,z+1) || !BlockTransparentOrLightSource(x-0.2,y-1,z))
                {
                    light4-=lightFactor;
                }

                MeshChunk->position(x,   y, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+0.2, y, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.2 , y, z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y, z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //top face
            //y+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y+1,z);
                    Block1 = GetBlock(x,y+1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y+1,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                if((GetBlockSettings(x,y+1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y+1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory1.x)
                        BlockColory1.x = BlockColory1.y = BlockColory1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory1;
                lightFactor = BlockColory2 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x-0.2,y+1,z+1) || !BlockTransparentOrLightSource(x-0.2,y+1,z))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x+0.2,y+1,z+1) || !BlockTransparentOrLightSource(x+0.2,y+1,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.2,y+1,z) || !BlockTransparentOrLightSource(x+0.2,y+1,z-1) || !BlockTransparentOrLightSource(x,y+1,z-1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x-0.2,y+1,z-1) || !BlockTransparentOrLightSource(x-0.2,y+1,z))
                {
                    light4-=lightFactor;
                }

                //down
                left = percent * blockType->upPlane;
                right = left + percent;

                MeshChunk->position(x,   y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+0.2, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.2, y+1, z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //z-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z > 0)
                {
                    transparentBlock = BlockTransparent(x,y,z-1);
                    Block1 = GetBlock(x,y,z-1);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z > 0)transparentBlock = BlockTransparentOrSpecial(x,y,z-1);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z-1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z-1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz1.x)
                        BlockColorz1.x = BlockColorz1.y = BlockColorz1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz1;
                lightFactor = BlockColorz1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x-0.2,y,z-1) || !BlockTransparentOrLightSource(x-0.2,y+1,z-1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x+0.2,y,z-1) || !BlockTransparentOrLightSource(x+0.2,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x-0.2,y,z-1) || !BlockTransparentOrLightSource(x-0.2,y-1,z-1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x+0.2,y,z-1) || !BlockTransparentOrLightSource(x+0.2,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.2, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+0.2, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //z+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y,z+1);
                    Block1 = GetBlock(x,y,z+1);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y,z+1);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate == true)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z+1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z+1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz2.x)
                        BlockColorz2.x = BlockColorz2.y = BlockColorz2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz2;
                lightFactor = BlockColorz2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x-0.2,y,z+1) || !BlockTransparentOrLightSource(x-0.2,y+1,z+1))
                {
                    light2-=lightFactor;
                }
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x+0.2,y,z+1) || !BlockTransparentOrLightSource(x+0.2,y+1,z+1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-0.2,y,z+1) || !BlockTransparentOrLightSource(x-0.2,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x+0.2,y,z+1) || !BlockTransparentOrLightSource(x+0.2,y-1,z+1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y,   z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+0.2, y,   z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+0.2, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x,   y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }
        }
    }


    if( Block == GlassPane::getID() || Block == IronBars::getID())
    {
        /* Only create visible faces of each chunk */
        bool DefaultBlock = false;
        bool transparentBlock;

        block_t Block1 = 0;

        Vector3 light1,light2,light3,light4;
        float BaseLight = 1.0f;

        Vector3 BlockColory1;    //Top face
        Vector3 BlockColory2;    //Bottom face
        Vector3 BlockColorx1;    //Sunset face
        Vector3 BlockColorx2;    //Sunrise face
        Vector3 BlockColorz1;     //Front/back faces
        Vector3 BlockColorz2;     //Front/back faces

        //texture stuff
        BaseBlock *blockType = &blockTypes[Block];

        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent;

        float left = percent * blockType->upPlane;
        float right = left + percent;

        bool canCreate = false;

        //lightened
        //if time is between 21-4 use settings table for lightening
        //if time is between 5-20 use normal light table but compare it with settings table
        //	if setting is brighter then use it
        if(worldDayTime >= 21 || worldDayTime <= 4)//night
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                BaseLight  = (float)(GetBlockSettings(x, y, z) & 0xF)/16.0f; // 255.0f;  //For the two x faces

                BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                BlockColorz1  = BlockColorz2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
            }
            else //normal light
            {
                //light
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;  //For the two x faces
                //float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
                //float BlockLight2 = BlockLight * 0.8f;		//For the two y faces

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }
        else //day
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                //int normal = GetBlockLight(x, y, z);
                //int lightened = (GetBlockSettings(x, y, z) & 0xF) * 16;

                float normal = lightColor.x * (factor1 * (GetBlockLight(x, y, z) / 255.0f)) + ambientColor.x;
                float lightened = (GetBlockSettings(x, y, z) & 0xF) / 15.0f;

                if(lightened > normal)
                {
                    BaseLight = lightened; // 255.0f;
                    BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                    BlockColorz2 = BlockColorz1  = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                    BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
                }
                else
                {
                    BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                    BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                    BlockColory1.saturate();
                    BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                    BlockColory2.saturate();
                    BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                    BlockColorz1.saturate();
                    BlockColorz1 *= 0.80f;
                    BlockColorz2 = BlockColorz1;

                    BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx1.saturate();
                    BlockColorx1 *= 0.95f;

                    BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx2.saturate();
                    BlockColorx2 *= 0.95f;
                }

            }
            else
            {
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }
        if(GetBlock(x,y,z+1) != 0 || GetBlock(x,y,z-1) != 0 || (GetBlock(x,y,z+1) != 0 && GetBlock(x,y,z-1) != 0 ))
        {
            //faces
            //x-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x > 0)
                {
                    transparentBlock = BlockTransparent(x-0.1,y,z);
                    Block1 = GetBlock(x-0.1,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x > 0)transparentBlock = BlockTransparentOrSpecial(x-1,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x-1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x-1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx1.x)
                        BlockColorx1.x = BlockColorx1.y = BlockColorx1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx1;
                lightFactor = BlockColorx1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x-0.1,y+1,z) || !BlockTransparentOrLightSource(x-0.1,y,z+1) || !BlockTransparentOrLightSource(x-0.1,y+1,z+1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-0.1,y+1,z) || !BlockTransparentOrLightSource(x-0.1,y,z-1) || !BlockTransparentOrLightSource(x-0.1,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x-0.1,y-1,z) || !BlockTransparentOrLightSource(x-0.1,y,z+1) || !BlockTransparentOrLightSource(x-0.1,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-0.1,y-1,z) || !BlockTransparentOrLightSource(x-0.1,y,z-1) || !BlockTransparentOrLightSource(x-0.1,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x, y,   z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //x+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x+0.1,y,z);
                    Block1 = GetBlock(x+0.1,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x+0.1,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x+1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx2.x)
                        BlockColorx2.x = BlockColorx2.y = BlockColorx2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx2;
                lightFactor = BlockColorx2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x+0.1,y+1,z) || !BlockTransparentOrLightSource(x+0.1,y,z+1) || !BlockTransparentOrLightSource(x+0.1,y+1,z+1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.1,y+1,z) || !BlockTransparentOrLightSource(x+0.1,y,z-1) || !BlockTransparentOrLightSource(x+0.1,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x+0.1,y-1,z) || !BlockTransparentOrLightSource(x+0.1,y,z+1) || !BlockTransparentOrLightSource(x+0.1,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.1,y-1,z) || !BlockTransparentOrLightSource(x+0.1,y,z-1) || !BlockTransparentOrLightSource(x+0.1,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x+0.1, y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+0.1, y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+0.1, y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.1, y,   z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //y-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y > 0)
                {
                    transparentBlock = BlockTransparent(x,y-1,z);
                    Block1 = GetBlock(x,y-1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y > 0)transparentBlock = BlockTransparentOrSpecial(x,y-1,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                //up
                left = percent * blockType->downPlane;
                right = left + percent;

                if((GetBlockSettings(x,y-1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y-1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory2.x)
                        BlockColory2.x = BlockColory2.y = BlockColory2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory2;
                lightFactor = BlockColory1 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x-0.1,y-1,z) || !BlockTransparentOrLightSource(x-0.1,y-1,z-1) || !BlockTransparentOrLightSource(x,y-1,z-1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x+0.1,y-1,z-1) || !BlockTransparentOrLightSource(x+0.1,y-0.5,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.1,y-1,z) || !BlockTransparentOrLightSource(x+0.1,y-1,z+1) || !BlockTransparentOrLightSource(x,y-1,z+1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-0.1,y-1,z+1) || !BlockTransparentOrLightSource(x-0.1,y-1,z))
                {
                    light4-=lightFactor;
                }

                MeshChunk->position(x,   y, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+0.1, y, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.1 , y, z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y, z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //top face
            //y+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y+1,z);
                    Block1 = GetBlock(x,y+1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y+0.5,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                if((GetBlockSettings(x,y+1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y+1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory1.x)
                        BlockColory1.x = BlockColory1.y = BlockColory1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory1;
                lightFactor = BlockColory2 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x-0.1,y+1,z+1) || !BlockTransparentOrLightSource(x-0.1,y+1,z))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x+0.1,y+1,z+1) || !BlockTransparentOrLightSource(x+0.1,y+1,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.1,y+1,z) || !BlockTransparentOrLightSource(x+0.1,y+1,z-1) || !BlockTransparentOrLightSource(x,y+1,z-1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x-0.1,y+1,z-1) || !BlockTransparentOrLightSource(x-0.1,y+1,z))
                {
                    light4-=lightFactor;
                }

                //down
                left = percent * blockType->upPlane;
                right = left + percent;

                MeshChunk->position(x,   y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+0.1, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.1, y+1, z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //z-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z > 0)
                {
                    transparentBlock = BlockTransparent(x,y,z-1);
                    Block1 = GetBlock(x,y,z-1);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z > 0)transparentBlock = BlockTransparentOrSpecial(x,y,z-1);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z-1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z-1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz1.x)
                        BlockColorz1.x = BlockColorz1.y = BlockColorz1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz1;
                lightFactor = BlockColorz1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x-0.1,y,z-1) || !BlockTransparentOrLightSource(x-0.1,y+1,z-1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x+0.1,y,z-1) || !BlockTransparentOrLightSource(x+0.1,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x-0.1,y,z-1) || !BlockTransparentOrLightSource(x-0.1,y-1,z-1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x+0.1,y,z-1) || !BlockTransparentOrLightSource(x+0.1,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.1, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+0.1, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //z+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y,z+1);
                    Block1 = GetBlock(x,y,z+1);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y,z+1);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate == true)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z+1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z+1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz2.x)
                        BlockColorz2.x = BlockColorz2.y = BlockColorz2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz2;
                lightFactor = BlockColorz2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x-0.1,y,z+1) || !BlockTransparentOrLightSource(x-0.1,y+1,z+1))
                {
                    light2-=lightFactor;
                }
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x+0.1,y,z+1) || !BlockTransparentOrLightSource(x+0.1,y+1,z+1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-0.1,y,z+1) || !BlockTransparentOrLightSource(x-0.1,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x+0.1,y,z+1) || !BlockTransparentOrLightSource(x+0.1,y-1,z+1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y,   z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+0.1, y,   z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+0.1, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x,   y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }
        }

        else if(GetBlock(x+1,y,z) != 0 || GetBlock(x-1,y,z) != 0 || (GetBlock(x+1,y,z) != 0 && GetBlock(x-1,y,z) != 0))
        {
            //faces
            //x-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x > 0)
                {
                    transparentBlock = BlockTransparent(x-1,y,z);
                    Block1 = GetBlock(x-1,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x > 0)transparentBlock = BlockTransparentOrSpecial(x-1,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x-1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x-1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx1.x)
                        BlockColorx1.x = BlockColorx1.y = BlockColorx1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx1;
                lightFactor = BlockColorx1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x-1,y+1,z) || !BlockTransparentOrLightSource(x-1,y,z+0.1) || !BlockTransparentOrLightSource(x-1,y+1,z+0.1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-1,y+1,z) || !BlockTransparentOrLightSource(x-1,y,z-0.1) || !BlockTransparentOrLightSource(x-1,y+1,z-0.1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y,z+0.1) || !BlockTransparentOrLightSource(x-1,y-1,z+0.1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y,z-0.1) || !BlockTransparentOrLightSource(x-1,y-1,z-0.1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x, y,   z+0.1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x, y+1, z+0.1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //x+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x+1,y,z);
                    Block1 = GetBlock(x+1,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x+1,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x+1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx2.x)
                        BlockColorx2.x = BlockColorx2.y = BlockColorx2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx2;
                lightFactor = BlockColorx2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y,z+0.1) || !BlockTransparentOrLightSource(x+1,y+1,z+0.1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y,z-0.1) || !BlockTransparentOrLightSource(x+1,y+1,z-0.1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y,z+0.1) || !BlockTransparentOrLightSource(x+1,y-1,z+0.1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y,z-0.1) || !BlockTransparentOrLightSource(x+1,y-1,z-0.1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x+1, y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+1, y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+1, y+1, z+0.1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y,   z+0.1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //y-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y > 0)
                {
                    transparentBlock = BlockTransparent(x,y-1,z);
                    Block1 = GetBlock(x,y-1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y > 0)transparentBlock = BlockTransparentOrSpecial(x,y-1,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                //up
                left = percent * blockType->downPlane;
                right = left + percent;

                if((GetBlockSettings(x,y-1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y-1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory2.x)
                        BlockColory2.x = BlockColory2.y = BlockColory2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory2;
                lightFactor = BlockColory1 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y-1,z-0.1) || !BlockTransparentOrLightSource(x,y-1,z-0.1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-0.1) || !BlockTransparentOrLightSource(x+1,y-1,z-0.1) || !BlockTransparentOrLightSource(x+1,y-1,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y-1,z+0.1) || !BlockTransparentOrLightSource(x,y-1,z+0.1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-1,y-1,z+0.1) || !BlockTransparentOrLightSource(x-1,y-1,z))
                {
                    light4-=lightFactor;
                }

                MeshChunk->position(x,   y, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1 , y, z+0.1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y, z+0.1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //top face
            //y+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y+1,z);
                    Block1 = GetBlock(x,y+1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y+1,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                if((GetBlockSettings(x,y+1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y+1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory1.x)
                        BlockColory1.x = BlockColory1.y = BlockColory1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory1;
                lightFactor = BlockColory2 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x,y+1,z+0.1) || !BlockTransparentOrLightSource(x-1,y+1,z+0.1) || !BlockTransparentOrLightSource(x-1,y+1,z))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z+0.1) || !BlockTransparentOrLightSource(x+1,y+1,z+0.1) || !BlockTransparentOrLightSource(x+1,y+1,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y+1,z-0.1) || !BlockTransparentOrLightSource(x,y+1,z-0.1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-0.1) || !BlockTransparentOrLightSource(x-1,y+1,z-0.1) || !BlockTransparentOrLightSource(x-1,y+1,z))
                {
                    light4-=lightFactor;
                }

                //down
                left = percent * blockType->upPlane;
                right = left + percent;

                MeshChunk->position(x,   y+1, z+0.1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y+1, z+0.1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y+1, z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //z-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z > 0)
                {
                    transparentBlock = BlockTransparent(x,y,z-0.1);
                    Block1 = GetBlock(x,y,z-1);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z > 0)transparentBlock = BlockTransparentOrSpecial(x,y,z-0.1);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z-0.9) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z-1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz1.x)
                        BlockColorz1.x = BlockColorz1.y = BlockColorz1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz1;
                lightFactor = BlockColorz1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z-0.1) || !BlockTransparentOrLightSource(x-1,y,z-0.1) || !BlockTransparentOrLightSource(x-1,y+1,z-0.1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-0.1) || !BlockTransparentOrLightSource(x+1,y,z-0.1) || !BlockTransparentOrLightSource(x+1,y+1,z-0.1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z-0.1) || !BlockTransparentOrLightSource(x-1,y,z-0.1) || !BlockTransparentOrLightSource(x-1,y-1,z-0.1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-0.1) || !BlockTransparentOrLightSource(x+1,y,z-0.1) || !BlockTransparentOrLightSource(x+1,y-1,z-0.1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+1, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //z+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y,z+0.1);
                    Block1 = GetBlock(x,y,z+0.1);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y,z+1);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate == true)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z+1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z+1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz2.x)
                        BlockColorz2.x = BlockColorz2.y = BlockColorz2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz2;
                lightFactor = BlockColorz2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z+0.1) || !BlockTransparentOrLightSource(x-1,y,z+0.1) || !BlockTransparentOrLightSource(x-1,y+1,z+0.1))
                {
                    light2-=lightFactor;
                }
                if(!BlockTransparentOrLightSource(x,y+1,z+0.1) || !BlockTransparentOrLightSource(x+1,y,z+0.1) || !BlockTransparentOrLightSource(x+1,y+1,z+0.1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z+0.1) || !BlockTransparentOrLightSource(x-1,y,z+0.1) || !BlockTransparentOrLightSource(x-1,y-1,z+0.1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+0.1) || !BlockTransparentOrLightSource(x+1,y,z+0.1) || !BlockTransparentOrLightSource(x+1,y-1,z+0.1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y,   z+0.1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y,   z+0.1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+1, y+1, z+0.1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x,   y+1, z+0.1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }
        }
        else
        {
            //faces
            //x-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x > 0)
                {
                    transparentBlock = BlockTransparent(x-1,y,z);
                    Block1 = GetBlock(x-1,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x > 0)transparentBlock = BlockTransparentOrSpecial(x-1,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x-1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x-1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx1.x)
                        BlockColorx1.x = BlockColorx1.y = BlockColorx1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx1;
                lightFactor = BlockColorx1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x-0.1,y+1,z) || !BlockTransparentOrLightSource(x-0.1,y,z+1) || !BlockTransparentOrLightSource(x-0.1,y+1,z+1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-0.1,y+1,z) || !BlockTransparentOrLightSource(x-0.1,y,z-1) || !BlockTransparentOrLightSource(x-0.1,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x-0.1,y-1,z) || !BlockTransparentOrLightSource(x-0.1,y,z+1) || !BlockTransparentOrLightSource(x-0.1,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-0.1,y-1,z) || !BlockTransparentOrLightSource(x-0.1,y,z-1) || !BlockTransparentOrLightSource(x-0.1,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x, y,   z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //x+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x+1,y,z);
                    Block1 = GetBlock(x+1,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x+1,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x+1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx2.x)
                        BlockColorx2.x = BlockColorx2.y = BlockColorx2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx2;
                lightFactor = BlockColorx2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x+0.1,y+1,z) || !BlockTransparentOrLightSource(x+0.1,y,z+1) || !BlockTransparentOrLightSource(x+0.1,y+1,z+1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.1,y+1,z) || !BlockTransparentOrLightSource(x+0.1,y,z-1) || !BlockTransparentOrLightSource(x+0.1,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x+0.1,y-1,z) || !BlockTransparentOrLightSource(x+0.1,y,z+1) || !BlockTransparentOrLightSource(x+0.1,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.1,y-1,z) || !BlockTransparentOrLightSource(x+0.1,y,z-1) || !BlockTransparentOrLightSource(x+0.1,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x+0.1, y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+0.1, y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+0.1, y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.1, y,   z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //y-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y > 0)
                {
                    transparentBlock = BlockTransparent(x,y-1,z);
                    Block1 = GetBlock(x,y-1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y > 0)transparentBlock = BlockTransparentOrSpecial(x,y-1,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                //up
                left = percent * blockType->downPlane;
                right = left + percent;

                if((GetBlockSettings(x,y-1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y-1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory2.x)
                        BlockColory2.x = BlockColory2.y = BlockColory2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory2;
                lightFactor = BlockColory1 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x-0.1,y-1,z) || !BlockTransparentOrLightSource(x-0.1,y-1,z-1) || !BlockTransparentOrLightSource(x,y-1,z-1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x+0.1,y-1,z-1) || !BlockTransparentOrLightSource(x+0.1,y-1,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.1,y-1,z) || !BlockTransparentOrLightSource(x+0.1,y-1,z+1) || !BlockTransparentOrLightSource(x,y-1,z+1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-0.1,y-1,z+1) || !BlockTransparentOrLightSource(x-0.1,y-1,z))
                {
                    light4-=lightFactor;
                }

                MeshChunk->position(x,   y, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+0.1, y, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.1 , y, z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y, z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //top face
            //y+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y+1,z);
                    Block1 = GetBlock(x,y+1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y+1,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                if((GetBlockSettings(x,y+1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y+1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory1.x)
                        BlockColory1.x = BlockColory1.y = BlockColory1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory1;
                lightFactor = BlockColory2 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x-0.1,y+1,z+1) || !BlockTransparentOrLightSource(x-0.1,y+1,z))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x+0.1,y+1,z+1) || !BlockTransparentOrLightSource(x+0.1,y+1,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.1,y+1,z) || !BlockTransparentOrLightSource(x+0.1,y+1,z-1) || !BlockTransparentOrLightSource(x,y+1,z-1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x-0.1,y+1,z-1) || !BlockTransparentOrLightSource(x-0.1,y+1,z))
                {
                    light4-=lightFactor;
                }

                //down
                left = percent * blockType->upPlane;
                right = left + percent;

                MeshChunk->position(x,   y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+0.1, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.1, y+1, z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //z-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z > 0)
                {
                    transparentBlock = BlockTransparent(x,y,z-1);
                    Block1 = GetBlock(x,y,z-1);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z > 0)transparentBlock = BlockTransparentOrSpecial(x,y,z-1);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z-1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z-1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz1.x)
                        BlockColorz1.x = BlockColorz1.y = BlockColorz1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz1;
                lightFactor = BlockColorz1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x-0.1,y,z-1) || !BlockTransparentOrLightSource(x-0.1,y+1,z-1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x+0.1,y,z-1) || !BlockTransparentOrLightSource(x+0.1,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x-0.1,y,z-1) || !BlockTransparentOrLightSource(x-0.1,y-1,z-1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x+0.1,y,z-1) || !BlockTransparentOrLightSource(x+0.1,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.1, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+0.1, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //z+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y,z+1);
                    Block1 = GetBlock(x,y,z+1);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y,z+1);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate == true)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z+1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z+1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz2.x)
                        BlockColorz2.x = BlockColorz2.y = BlockColorz2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz2;
                lightFactor = BlockColorz2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x-0.1,y,z+1) || !BlockTransparentOrLightSource(x-0.1,y+1,z+1))
                {
                    light2-=lightFactor;
                }
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x+0.1,y,z+1) || !BlockTransparentOrLightSource(x+0.1,y+1,z+1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-0.1,y,z+1) || !BlockTransparentOrLightSource(x-0.1,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x+0.1,y,z+1) || !BlockTransparentOrLightSource(x+0.1,y-1,z+1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y,   z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+0.1, y,   z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+0.1, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x,   y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }
        }
    }

    if( Block == LadderBlock::getID() || Block == wines::getID())
    {
        /* Only create visible faces of each chunk */
        bool DefaultBlock = false;
        bool transparentBlock;

        block_t Block1 = 0;

        Vector3 light1,light2,light3,light4;
        float BaseLight = 1.0f;

        Vector3 BlockColory1;    //Top face
        Vector3 BlockColory2;    //Bottom face
        Vector3 BlockColorx1;    //Sunset face
        Vector3 BlockColorx2;    //Sunrise face
        Vector3 BlockColorz1;     //Front/back faces
        Vector3 BlockColorz2;     //Front/back faces

        //texture stuff
        BaseBlock *blockType = &blockTypes[Block];

        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent;

        float left = percent * blockType->upPlane;
        float right = left + percent;

        bool canCreate = false;

        //lightened
        //if time is between 21-4 use settings table for lightening
        //if time is between 5-20 use normal light table but compare it with settings table
        //	if setting is brighter then use it
        if(worldDayTime >= 21 || worldDayTime <= 4)//night
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                BaseLight  = (float)(GetBlockSettings(x, y, z) & 0xF)/16.0f; // 255.0f;  //For the two x faces

                BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                BlockColorz1  = BlockColorz2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
            }
            else //normal light
            {
                //light
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;  //For the two x faces
                //float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
                //float BlockLight2 = BlockLight * 0.8f;		//For the two y faces

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }
        else //day
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                //int normal = GetBlockLight(x, y, z);
                //int lightened = (GetBlockSettings(x, y, z) & 0xF) * 16;

                float normal = lightColor.x * (factor1 * (GetBlockLight(x, y, z) / 255.0f)) + ambientColor.x;
                float lightened = (GetBlockSettings(x, y, z) & 0xF) / 15.0f;

                if(lightened > normal)
                {
                    BaseLight = lightened; // 255.0f;
                    BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                    BlockColorz2 = BlockColorz1  = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                    BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
                }
                else
                {
                    BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                    BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                    BlockColory1.saturate();
                    BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                    BlockColory2.saturate();
                    BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                    BlockColorz1.saturate();
                    BlockColorz1 *= 0.80f;
                    BlockColorz2 = BlockColorz1;

                    BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx1.saturate();
                    BlockColorx1 *= 0.95f;

                    BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx2.saturate();
                    BlockColorx2 *= 0.95f;
                }

            }
            else
            {
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }
        if(GetBlock(x-1,y,z) != 0)
        {

            //faces
            //x-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x > 0)
                {
                    transparentBlock = BlockTransparent(x-0.05,y,z);
                    Block1 = GetBlock(x-0.05,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x > 0)transparentBlock = BlockTransparentOrSpecial(x-1,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x-1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x-1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx1.x)
                        BlockColorx1.x = BlockColorx1.y = BlockColorx1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx1;
                lightFactor = BlockColorx1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x-0.05,y+1,z) || !BlockTransparentOrLightSource(x-0.05,y,z+1) || !BlockTransparentOrLightSource(x-0.05,y+1,z+1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-0.05,y+1,z) || !BlockTransparentOrLightSource(x-0.05,y,z-1) || !BlockTransparentOrLightSource(x-0.05,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x-0.05,y-1,z) || !BlockTransparentOrLightSource(x-0.05,y,z+1) || !BlockTransparentOrLightSource(x-0.05,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-0.05,y-1,z) || !BlockTransparentOrLightSource(x-0.05,y,z-1) || !BlockTransparentOrLightSource(x-0.05,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x, y,   z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //x+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x+0.05,y,z);
                    Block1 = GetBlock(x+0.05,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x+0.05,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x+1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx2.x)
                        BlockColorx2.x = BlockColorx2.y = BlockColorx2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx2;
                lightFactor = BlockColorx2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x+0.05,y+1,z) || !BlockTransparentOrLightSource(x+0.05,y,z+1) || !BlockTransparentOrLightSource(x+0.05,y+1,z+1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.05,y+1,z) || !BlockTransparentOrLightSource(x+0.05,y,z-1) || !BlockTransparentOrLightSource(x+0.05,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x+0.05,y-1,z) || !BlockTransparentOrLightSource(x+0.05,y,z+1) || !BlockTransparentOrLightSource(x+0.05,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.05,y-1,z) || !BlockTransparentOrLightSource(x+0.05,y,z-1) || !BlockTransparentOrLightSource(x+0.05,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x+0.05, y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+0.05, y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+0.05, y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.05, y,   z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //y-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y > 0)
                {
                    transparentBlock = BlockTransparent(x,y-1,z);
                    Block1 = GetBlock(x,y-1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y > 0)transparentBlock = BlockTransparentOrSpecial(x,y-1,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                //up
                left = percent * blockType->downPlane;
                right = left + percent;

                if((GetBlockSettings(x,y-1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y-1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory2.x)
                        BlockColory2.x = BlockColory2.y = BlockColory2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory2;
                lightFactor = BlockColory1 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x-0.05,y-1,z) || !BlockTransparentOrLightSource(x-0.05,y-1,z-1) || !BlockTransparentOrLightSource(x,y-1,z-1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x+0.05,y-1,z-1) || !BlockTransparentOrLightSource(x+0.05,y-0.5,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.05,y-1,z) || !BlockTransparentOrLightSource(x+0.05,y-1,z+1) || !BlockTransparentOrLightSource(x,y-1,z+1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-0.05,y-1,z+1) || !BlockTransparentOrLightSource(x-0.05,y-1,z))
                {
                    light4-=lightFactor;
                }

                MeshChunk->position(x,   y, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+0.05, y, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.05 , y, z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y, z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //top face
            //y+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y+1,z);
                    Block1 = GetBlock(x,y+1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y+0.5,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                if((GetBlockSettings(x,y+1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y+1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory1.x)
                        BlockColory1.x = BlockColory1.y = BlockColory1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory1;
                lightFactor = BlockColory2 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x-0.05,y+1,z+1) || !BlockTransparentOrLightSource(x-0.05,y+1,z))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x+0.05,y+1,z+1) || !BlockTransparentOrLightSource(x+0.05,y+1,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.05,y+1,z) || !BlockTransparentOrLightSource(x+0.05,y+1,z-1) || !BlockTransparentOrLightSource(x,y+1,z-1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x-0.05,y+1,z-1) || !BlockTransparentOrLightSource(x-0.05,y+1,z))
                {
                    light4-=lightFactor;
                }

                //down
                left = percent * blockType->upPlane;
                right = left + percent;

                MeshChunk->position(x,   y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+0.05, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.05, y+1, z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //z-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z > 0)
                {
                    transparentBlock = BlockTransparent(x,y,z-1);
                    Block1 = GetBlock(x,y,z-1);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z > 0)transparentBlock = BlockTransparentOrSpecial(x,y,z-1);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z-1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z-1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz1.x)
                        BlockColorz1.x = BlockColorz1.y = BlockColorz1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz1;
                lightFactor = BlockColorz1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x-0.05,y,z-1) || !BlockTransparentOrLightSource(x-0.05,y+1,z-1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x+0.05,y,z-1) || !BlockTransparentOrLightSource(x+0.05,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x-0.05,y,z-1) || !BlockTransparentOrLightSource(x-0.05,y-1,z-1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x+0.05,y,z-1) || !BlockTransparentOrLightSource(x+0.05,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.05, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+0.05, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //z+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y,z+1);
                    Block1 = GetBlock(x,y,z+1);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y,z+1);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate == true)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z+1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z+1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz2.x)
                        BlockColorz2.x = BlockColorz2.y = BlockColorz2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz2;
                lightFactor = BlockColorz2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x-0.05,y,z+1) || !BlockTransparentOrLightSource(x-0.05,y+1,z+1))
                {
                    light2-=lightFactor;
                }
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x+0.05,y,z+1) || !BlockTransparentOrLightSource(x+0.05,y+1,z+1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-0.05,y,z+1) || !BlockTransparentOrLightSource(x-0.05,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x+0.05,y,z+1) || !BlockTransparentOrLightSource(x+0.05,y-1,z+1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y,   z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+0.05, y,   z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+0.05, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x,   y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }
        }

        if(GetBlock(x,y-1,z) != 0 && GetBlock(x+1,y,z) == 0 && GetBlock(x-1,y,z) == 0 && GetBlock(x,y,z+1) == 0 && GetBlock(x,y,z-1) == 0)
        {
            GetBlock(x,y,z) = 0;
        }
        else if(GetBlock(x,y-1,z) == 0 && GetBlock(x+1,y,z) == 0 && GetBlock(x-1,y,z) == 0 && GetBlock(x,y,z+1) == 0 && GetBlock(x,y,z-1) == 0)
        {
            GetBlock(x,y,z) = 0;
        }

        else if(GetBlock(x,y,z-1) != 0)
        {
            //faces
            //x-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x > 0)
                {
                    transparentBlock = BlockTransparent(x-1,y,z);
                    Block1 = GetBlock(x-1,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x > 0)transparentBlock = BlockTransparentOrSpecial(x-1,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x-1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x-1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx1.x)
                        BlockColorx1.x = BlockColorx1.y = BlockColorx1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx1;
                lightFactor = BlockColorx1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x-1,y+1,z) || !BlockTransparentOrLightSource(x-1,y,z+0.05) || !BlockTransparentOrLightSource(x-1,y+1,z+0.05))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-1,y+1,z) || !BlockTransparentOrLightSource(x-1,y,z-0.05) || !BlockTransparentOrLightSource(x-1,y+1,z-0.05))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y,z+0.05) || !BlockTransparentOrLightSource(x-1,y-1,z+0.05))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y,z-0.05) || !BlockTransparentOrLightSource(x-1,y-1,z-0.05))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x, y,   z+0.05);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x, y+1, z+0.05);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //x+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x+1,y,z);
                    Block1 = GetBlock(x+1,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x+1,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x+1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx2.x)
                        BlockColorx2.x = BlockColorx2.y = BlockColorx2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx2;
                lightFactor = BlockColorx2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y,z+0.05) || !BlockTransparentOrLightSource(x+1,y+1,z+0.05))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y,z-0.05) || !BlockTransparentOrLightSource(x+1,y+1,z-0.05))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y,z+0.05) || !BlockTransparentOrLightSource(x+1,y-1,z+0.05))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y,z-0.05) || !BlockTransparentOrLightSource(x+1,y-1,z-0.05))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x+1, y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+1, y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+1, y+1, z+0.05);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y,   z+0.05);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //y-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y > 0)
                {
                    transparentBlock = BlockTransparent(x,y-1,z);
                    Block1 = GetBlock(x,y-1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y > 0)transparentBlock = BlockTransparentOrSpecial(x,y-1,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                //up
                left = percent * blockType->downPlane;
                right = left + percent;

                if((GetBlockSettings(x,y-1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y-1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory2.x)
                        BlockColory2.x = BlockColory2.y = BlockColory2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory2;
                lightFactor = BlockColory1 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y-1,z-0.05) || !BlockTransparentOrLightSource(x,y-1,z-0.05))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-0.05) || !BlockTransparentOrLightSource(x+1,y-1,z-0.05) || !BlockTransparentOrLightSource(x+1,y-1,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y-1,z+0.05) || !BlockTransparentOrLightSource(x,y-1,z+0.05))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-1,y-1,z+0.05) || !BlockTransparentOrLightSource(x-1,y-1,z))
                {
                    light4-=lightFactor;
                }

                MeshChunk->position(x,   y, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1 , y, z+0.05);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y, z+0.05);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //top face
            //y+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y+1,z);
                    Block1 = GetBlock(x,y+1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y+1,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                if((GetBlockSettings(x,y+1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y+1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory1.x)
                        BlockColory1.x = BlockColory1.y = BlockColory1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory1;
                lightFactor = BlockColory2 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x,y+1,z+0.05) || !BlockTransparentOrLightSource(x-1,y+1,z+0.05) || !BlockTransparentOrLightSource(x-1,y+1,z))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z+0.05) || !BlockTransparentOrLightSource(x+1,y+1,z+0.05) || !BlockTransparentOrLightSource(x+1,y+1,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y+1,z-0.05) || !BlockTransparentOrLightSource(x,y+1,z-0.05))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-0.05) || !BlockTransparentOrLightSource(x-1,y+1,z-0.05) || !BlockTransparentOrLightSource(x-1,y+1,z))
                {
                    light4-=lightFactor;
                }

                //down
                left = percent * blockType->upPlane;
                right = left + percent;

                MeshChunk->position(x,   y+1, z+0.05);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y+1, z+0.05);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y+1, z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //z-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z > 0)
                {
                    transparentBlock = BlockTransparent(x,y,z-0.05);
                    Block1 = GetBlock(x,y,z-1);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z > 0)transparentBlock = BlockTransparentOrSpecial(x,y,z-0.05);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z-0.9) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z-1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz1.x)
                        BlockColorz1.x = BlockColorz1.y = BlockColorz1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz1;
                lightFactor = BlockColorz1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z-0.05) || !BlockTransparentOrLightSource(x-1,y,z-0.05) || !BlockTransparentOrLightSource(x-1,y+1,z-0.05))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-0.05) || !BlockTransparentOrLightSource(x+1,y,z-0.05) || !BlockTransparentOrLightSource(x+1,y+1,z-0.05))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z-0.05) || !BlockTransparentOrLightSource(x-1,y,z-0.05) || !BlockTransparentOrLightSource(x-1,y-1,z-0.05))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-0.05) || !BlockTransparentOrLightSource(x+1,y,z-0.05) || !BlockTransparentOrLightSource(x+1,y-1,z-0.05))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+1, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //z+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y,z+0.05);
                    Block1 = GetBlock(x,y,z+0.05);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y,z+1);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate == true)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z+1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z+1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz2.x)
                        BlockColorz2.x = BlockColorz2.y = BlockColorz2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz2;
                lightFactor = BlockColorz2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z+0.05) || !BlockTransparentOrLightSource(x-1,y,z+0.05) || !BlockTransparentOrLightSource(x-1,y+1,z+0.05))
                {
                    light2-=lightFactor;
                }
                if(!BlockTransparentOrLightSource(x,y+1,z+0.05) || !BlockTransparentOrLightSource(x+1,y,z+0.05) || !BlockTransparentOrLightSource(x+1,y+1,z+0.05))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z+0.05) || !BlockTransparentOrLightSource(x-1,y,z+0.05) || !BlockTransparentOrLightSource(x-1,y-1,z+0.05))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+0.05) || !BlockTransparentOrLightSource(x+1,y,z+0.05) || !BlockTransparentOrLightSource(x+1,y-1,z+0.05))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y,   z+0.05);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y,   z+0.05);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+1, y+1, z+0.05);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x,   y+1, z+0.05);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }
        }
        else if(GetBlock(x,y,z+1) != 0)
        {
            //faces
            //x-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x > 0)
                {
                    transparentBlock = BlockTransparent(x-0.05,y,z);
                    Block1 = GetBlock(x-0.05,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x > 0)transparentBlock = BlockTransparentOrSpecial(x-1,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x+1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx1.x)
                        BlockColorx1.x = BlockColorx1.y = BlockColorx1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx1;
                lightFactor = BlockColorx1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x-0.05,y+1,z) || !BlockTransparentOrLightSource(x-0.05,y,z+1) || !BlockTransparentOrLightSource(x-0.05,y+1,z+1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-0.05,y+1,z) || !BlockTransparentOrLightSource(x-0.05,y,z-1) || !BlockTransparentOrLightSource(x-0.05,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x-0.05,y-1,z) || !BlockTransparentOrLightSource(x-0.05,y,z+1) || !BlockTransparentOrLightSource(x-0.05,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-0.05,y-1,z) || !BlockTransparentOrLightSource(x-0.05,y,z-1) || !BlockTransparentOrLightSource(x-0.05,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x, y,   z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //x+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x+0.05,y,z);
                    Block1 = GetBlock(x+0.05,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x+0.05,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x+1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx2.x)
                        BlockColorx2.x = BlockColorx2.y = BlockColorx2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx2;
                lightFactor = BlockColorx2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x+0.05,y+1,z) || !BlockTransparentOrLightSource(x+0.05,y,z+1) || !BlockTransparentOrLightSource(x+0.05,y+1,z+1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.05,y+1,z) || !BlockTransparentOrLightSource(x+0.05,y,z-1) || !BlockTransparentOrLightSource(x+0.05,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x+0.05,y-1,z) || !BlockTransparentOrLightSource(x+0.05,y,z+1) || !BlockTransparentOrLightSource(x+0.05,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.05,y-1,z) || !BlockTransparentOrLightSource(x+0.05,y,z-1) || !BlockTransparentOrLightSource(x+0.05,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x+0.05, y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+0.05, y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+0.05, y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.05, y,   z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //y-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y > 0)
                {
                    transparentBlock = BlockTransparent(x,y-1,z);
                    Block1 = GetBlock(x,y-1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y > 0)transparentBlock = BlockTransparentOrSpecial(x,y-1,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                //up
                left = percent * blockType->downPlane;
                right = left + percent;

                if((GetBlockSettings(x,y-1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y-1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory2.x)
                        BlockColory2.x = BlockColory2.y = BlockColory2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory2;
                lightFactor = BlockColory1 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x-0.05,y-1,z) || !BlockTransparentOrLightSource(x-0.05,y-1,z-1) || !BlockTransparentOrLightSource(x,y-1,z-1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x+0.05,y-1,z-1) || !BlockTransparentOrLightSource(x+0.05,y-0.5,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.05,y-1,z) || !BlockTransparentOrLightSource(x+0.05,y-1,z+1) || !BlockTransparentOrLightSource(x,y-1,z+1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-0.05,y-1,z+1) || !BlockTransparentOrLightSource(x-0.05,y-1,z))
                {
                    light4-=lightFactor;
                }

                MeshChunk->position(x,   y, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+0.05, y, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.05 , y, z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y, z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //top face
            //y+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y+1,z);
                    Block1 = GetBlock(x,y+1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y+0.5,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                if((GetBlockSettings(x,y+1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y+1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory1.x)
                        BlockColory1.x = BlockColory1.y = BlockColory1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory1;
                lightFactor = BlockColory2 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x-0.05,y+1,z+1) || !BlockTransparentOrLightSource(x-0.05,y+1,z))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x+0.05,y+1,z+1) || !BlockTransparentOrLightSource(x+0.05,y+1,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.05,y+1,z) || !BlockTransparentOrLightSource(x+0.05,y+1,z-1) || !BlockTransparentOrLightSource(x,y+1,z-1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x-0.05,y+1,z-1) || !BlockTransparentOrLightSource(x-0.05,y+1,z))
                {
                    light4-=lightFactor;
                }

                //down
                left = percent * blockType->upPlane;
                right = left + percent;

                MeshChunk->position(x,   y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+0.05, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.05, y+1, z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //z-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z > 0)
                {
                    transparentBlock = BlockTransparent(x,y,z-1);
                    Block1 = GetBlock(x,y,z-1);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z > 0)transparentBlock = BlockTransparentOrSpecial(x,y,z-1);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z-1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z-1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz1.x)
                        BlockColorz1.x = BlockColorz1.y = BlockColorz1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz1;
                lightFactor = BlockColorz1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x-0.05,y,z-1) || !BlockTransparentOrLightSource(x-0.05,y+1,z-1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x+0.05,y,z-1) || !BlockTransparentOrLightSource(x+0.05,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x-0.05,y,z-1) || !BlockTransparentOrLightSource(x-0.05,y-1,z-1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x+0.05,y,z-1) || !BlockTransparentOrLightSource(x+0.05,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.05, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+0.05, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //z+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y,z+1);
                    Block1 = GetBlock(x,y,z+1);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y,z+1);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate == true)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z+1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z+1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz2.x)
                        BlockColorz2.x = BlockColorz2.y = BlockColorz2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz2;
                lightFactor = BlockColorz2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x-0.05,y,z+1) || !BlockTransparentOrLightSource(x-0.05,y+1,z+1))
                {
                    light2-=lightFactor;
                }
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x+0.05,y,z+1) || !BlockTransparentOrLightSource(x+0.05,y+1,z+1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-0.05,y,z+1) || !BlockTransparentOrLightSource(x-0.05,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x+0.05,y,z+1) || !BlockTransparentOrLightSource(x+0.05,y-1,z+1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y,   z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+0.05, y,   z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+0.05, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x,   y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }
        }
    }

    if( Block == Cake::getID())
    {
        /* Only create visible faces of each chunk */
        bool DefaultBlock = false;
        bool transparentBlock;

        block_t Block1 = 0;

        Vector3 light1,light2,light3,light4;
        float BaseLight = 1.0f;

        Vector3 BlockColory1;    //Top face
        Vector3 BlockColory2;    //Bottom face
        Vector3 BlockColorx1;    //Sunset face
        Vector3 BlockColorx2;    //Sunrise face
        Vector3 BlockColorz1;     //Front/back faces
        Vector3 BlockColorz2;     //Front/back faces

        //texture stuff
        BaseBlock *blockType = &blockTypes[Block];

        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent;

        float left = percent * blockType->upPlane;
        float right = left + percent;

        bool canCreate = false;

        //lightened
        //if time is between 21-4 use settings table for lightening
        //if time is between 5-20 use normal light table but compare it with settings table
        //	if setting is brighter then use it
        if(worldDayTime >= 21 || worldDayTime <= 4)//night
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                BaseLight  = (float)(GetBlockSettings(x, y, z) & 0xF)/16.0f; // 255.0f;  //For the two x faces

                BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                BlockColorz1  = BlockColorz2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
            }
            else //normal light
            {
                //light
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;  //For the two x faces
                //float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
                //float BlockLight2 = BlockLight * 0.8f;		//For the two y faces

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }
        else //day
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                //int normal = GetBlockLight(x, y, z);
                //int lightened = (GetBlockSettings(x, y, z) & 0xF) * 16;

                float normal = lightColor.x * (factor1 * (GetBlockLight(x, y, z) / 255.0f)) + ambientColor.x;
                float lightened = (GetBlockSettings(x, y, z) & 0xF) / 15.0f;

                if(lightened > normal)
                {
                    BaseLight = lightened; // 255.0f;
                    BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                    BlockColorz2 = BlockColorz1  = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                    BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
                }
                else
                {
                    BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                    BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                    BlockColory1.saturate();
                    BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                    BlockColory2.saturate();
                    BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                    BlockColorz1.saturate();
                    BlockColorz1 *= 0.80f;
                    BlockColorz2 = BlockColorz1;

                    BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx1.saturate();
                    BlockColorx1 *= 0.95f;

                    BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx2.saturate();
                    BlockColorx2 *= 0.95f;
                }

            }
            else
            {
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }

        //faces
        //x-1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (x > 0)
            {
                transparentBlock = BlockTransparent(x-1,y,z);
                Block1 = GetBlock(x-1,y,z);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (x > 0)transparentBlock = BlockTransparentOrSpecial(x-1,y,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x-1,y,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x-1, y, z) & 0xF) / 15.0f;
                if(lightened > BlockColorx1.x)
                    BlockColorx1.x = BlockColorx1.y = BlockColorx1.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorx1;
            lightFactor = BlockColorx1 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x-0.9,y+0.5,z) || !BlockTransparentOrLightSource(x-0.9,y,z+0.9) || !BlockTransparentOrLightSource(x-0.9,y+0.5,z+0.9))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x-0.9,y+0.5,z) || !BlockTransparentOrLightSource(x-0.9,y,z-0.9) || !BlockTransparentOrLightSource(x-0.9,y+0.5,z-0.9))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x-0.9,y-0.5,z) || !BlockTransparentOrLightSource(x-0.9,y,z+0.9) || !BlockTransparentOrLightSource(x-0.9,y-0.5,z+0.9))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x-0.9,y-0.5,z) || !BlockTransparentOrLightSource(x-0.9,y,z-0.9) || !BlockTransparentOrLightSource(x-0.9,y-0.5,z-0.9))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x, y,   z+0.9);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x, y+0.5, z+0.9);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x, y+0.5, z);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x, y,   z);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }


        //x+1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (x < WORLD_SIZE - 1)
            {
                transparentBlock = BlockTransparent(x+0.9,y,z);
                Block1 = GetBlock(x+1,y,z);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (x < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x+0.9,y,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x+0.9, y, z) & 0xF) / 15.0f;
                if(lightened > BlockColorx2.x)
                    BlockColorx2.x = BlockColorx2.y = BlockColorx2.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorx2;
            lightFactor = BlockColorx2 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x+0.9,y+0.5,z) || !BlockTransparentOrLightSource(x+0.9,y,z+0.9) || !BlockTransparentOrLightSource(x+0.9,y+0.5,z+0.9))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+0.9,y+0.5,z) || !BlockTransparentOrLightSource(x+0.9,y,z-0.9) || !BlockTransparentOrLightSource(x+0.9,y+0.5,z-0.9))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x+0.9,y-0.5,z) || !BlockTransparentOrLightSource(x+0.9,y,z+0.9) || !BlockTransparentOrLightSource(x+0.9,y-0.5,z+0.9))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+0.9,y-0.5,z) || !BlockTransparentOrLightSource(x+0.9,y,z-0.9) || !BlockTransparentOrLightSource(x+0.9,y-0.5,z-0.9))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x+0.9, y,   z);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x+0.9, y+0.5, z);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x+0.9, y+0.5, z+0.9);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+0.9, y,   z+0.9);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }

        //y-1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (y > 0)
            {
                transparentBlock = BlockTransparent(x,y-0.5,z);
                Block1 = GetBlock(x,y-0.5,z);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (y > 0)transparentBlock = BlockTransparentOrSpecial(x,y-0.5,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            //up
            left = percent * blockType->downPlane;
            right = left + percent;

            if((GetBlockSettings(x,y-0.5,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y-0.5, z) & 0xF) / 15.0f;
                if(lightened > BlockColory2.x)
                    BlockColory2.x = BlockColory2.y = BlockColory2.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColory2;
            lightFactor = BlockColory1 * lightShadowFactor;

            //simple shadows
            if(!BlockTransparentOrLightSource(x-0.9,y-0.5,z) || !BlockTransparentOrLightSource(x-0.9,y-0.5,z-0.9) || !BlockTransparentOrLightSource(x,y-0.5,z-0.9))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.5,z-0.9) || !BlockTransparentOrLightSource(x+0.9,y-0.5,z-0.9) || !BlockTransparentOrLightSource(x+0.9,y-0.5,z))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+0.9,y-0.5,z) || !BlockTransparentOrLightSource(x+0.9,y-0.5,z+0.9) || !BlockTransparentOrLightSource(x,y-0.5,z+0.9))
            {
                light3-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.5,z+0.9) || !BlockTransparentOrLightSource(x-0.9,y-0.5,z+0.9) || !BlockTransparentOrLightSource(x-0.9,y-0.5,z))
            {
                light4-=lightFactor;
            }

            MeshChunk->position(x,   y, z);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x+0.9, y, z);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+0.9, y, z+0.9);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x,   y, z+0.9);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light4.x,light4.y,light4.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }


        //top face
        //y+1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (y < WORLD_SIZE - 1)
            {
                transparentBlock = BlockTransparent(x,y+0.5,z);
                Block1 = GetBlock(x,y+0.5,z);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (y < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y+0.5,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            if((GetBlockSettings(x,y+0.5,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y+0.5, z) & 0xF) / 15.0f;
                if(lightened > BlockColory1.x)
                    BlockColory1.x = BlockColory1.y = BlockColory1.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColory1;
            lightFactor = BlockColory2 * lightShadowFactor;

            //simple shadows
            if(!BlockTransparentOrLightSource(x,y+0.5,z+0.9) || !BlockTransparentOrLightSource(x-0.9,y+0.5,z+0.9) || !BlockTransparentOrLightSource(x-0.9,y+0.5,z))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y+0.5,z+0.9) || !BlockTransparentOrLightSource(x+0.9,y+0.5,z+0.9) || !BlockTransparentOrLightSource(x+0.9,y+0.5,z))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+0.9,y+0.5,z) || !BlockTransparentOrLightSource(x+0.9,y+0.5,z-0.9) || !BlockTransparentOrLightSource(x,y+0.5,z-0.9))
            {
                light3-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y+0.5,z-0.9) || !BlockTransparentOrLightSource(x-0.9,y+0.5,z-0.9) || !BlockTransparentOrLightSource(x-0.9,y+0.5,z))
            {
                light4-=lightFactor;
            }

            //down
            left = percent * blockType->upPlane;
            right = left + percent;

            MeshChunk->position(x,   y+0.5, z+0.9);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x+0.9, y+0.5, z+0.9);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+0.9, y+0.5, z);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x,   y+0.5, z);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light4.x,light4.y,light4.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }

        //z-1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (z > 0)
            {
                transparentBlock = BlockTransparent(x,y,z-0.9);
                Block1 = GetBlock(x,y,z-0.9);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (z > 0)transparentBlock = BlockTransparentOrSpecial(x,y,z-0.9);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x,y,z-0.9) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y, z-1) & 0xF) / 15.0f;
                if(lightened > BlockColorz1.x)
                    BlockColorz1.x = BlockColorz1.y = BlockColorz1.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorz1;
            lightFactor = BlockColorz1 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x,y+0.5,z-0.9) || !BlockTransparentOrLightSource(x-0.9,y,z-0.9) || !BlockTransparentOrLightSource(x-0.9,y+0.5,z-0.9))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y+0.5,z-0.9) || !BlockTransparentOrLightSource(x+0.9,y,z-0.9) || !BlockTransparentOrLightSource(x+0.9,y+0.5,z-0.9))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x,y-0.5,z-0.9) || !BlockTransparentOrLightSource(x-0.9,y,z-0.9) || !BlockTransparentOrLightSource(x-0.9,y-0.5,z-0.9))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.5,z-0.9) || !BlockTransparentOrLightSource(x+0.9,y,z-0.9) || !BlockTransparentOrLightSource(x+0.9,y-0.5,z-0.9))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x,   y+0.5, z);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+0.9, y+0.5, z);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x+0.9, y,   z);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x,   y,   z);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }


        //z+1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (z < WORLD_SIZE - 1)
            {
                transparentBlock = BlockTransparent(x,y,z+0.9);
                Block1 = GetBlock(x,y,z+0.9);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (z < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y,z+0.9);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate == true)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x,y,z+0.9) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y, z+0.9) & 0xF) / 15.0f;
                if(lightened > BlockColorz2.x)
                    BlockColorz2.x = BlockColorz2.y = BlockColorz2.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorz2;
            lightFactor = BlockColorz2 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x,y+0.5,z+0.9) || !BlockTransparentOrLightSource(x-0.9,y,z+0.9) || !BlockTransparentOrLightSource(x-0.9,y+0.5,z+0.9))
            {
                light2-=lightFactor;
            }
            if(!BlockTransparentOrLightSource(x,y+0.5,z+0.9) || !BlockTransparentOrLightSource(x+0.9,y,z+0.9) || !BlockTransparentOrLightSource(x+0.9,y+0.5,z+0.9))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x,y-0.5,z+0.9) || !BlockTransparentOrLightSource(x-0.9,y,z+0.9) || !BlockTransparentOrLightSource(x-0.9,y-0.5,z+0.9))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.5,z+0.9) || !BlockTransparentOrLightSource(x+0.9,y,z+0.9) || !BlockTransparentOrLightSource(x+0.9,y-0.5,z+0.9))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x,   y,   z+0.9);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x+0.9, y,   z+0.9);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x+0.9, y+0.5, z+0.9);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x,   y+0.5, z+0.9);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }
    }

    if( Block == Snow2::getID() || Block == WoodPlate::getID() || Block == StonePlate::getID() || Block ==WaterFlow::getID())
    {
        /* Only create visible faces of each chunk */
        bool DefaultBlock = false;
        bool transparentBlock;

        block_t Block1 = 0;

        Vector3 light1,light2,light3,light4;
        float BaseLight = 1.0f;

        Vector3 BlockColory1;    //Top face
        Vector3 BlockColory2;    //Bottom face
        Vector3 BlockColorx1;    //Sunset face
        Vector3 BlockColorx2;    //Sunrise face
        Vector3 BlockColorz1;     //Front/back faces
        Vector3 BlockColorz2;     //Front/back faces

        //texture stuff
        BaseBlock *blockType = &blockTypes[Block];

        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent;

        float left = percent * blockType->upPlane;
        float right = left + percent;

        bool canCreate = false;

        //lightened
        //if time is between 21-4 use settings table for lightening
        //if time is between 5-20 use normal light table but compare it with settings table
        //	if setting is brighter then use it
        if(worldDayTime >= 21 || worldDayTime <= 4)//night
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                BaseLight  = (float)(GetBlockSettings(x, y, z) & 0xF)/16.0f; // 255.0f;  //For the two x faces

                BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                BlockColorz1  = BlockColorz2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
            }
            else //normal light
            {
                //light
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;  //For the two x faces
                //float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
                //float BlockLight2 = BlockLight * 0.8f;		//For the two y faces

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }
        else //day
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                //int normal = GetBlockLight(x, y, z);
                //int lightened = (GetBlockSettings(x, y, z) & 0xF) * 16;

                float normal = lightColor.x * (factor1 * (GetBlockLight(x, y, z) / 255.0f)) + ambientColor.x;
                float lightened = (GetBlockSettings(x, y, z) & 0xF) / 15.0f;

                if(lightened > normal)
                {
                    BaseLight = lightened; // 255.0f;
                    BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                    BlockColorz2 = BlockColorz1  = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                    BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
                }
                else
                {
                    BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                    BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                    BlockColory1.saturate();
                    BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                    BlockColory2.saturate();
                    BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                    BlockColorz1.saturate();
                    BlockColorz1 *= 0.80f;
                    BlockColorz2 = BlockColorz1;

                    BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx1.saturate();
                    BlockColorx1 *= 0.95f;

                    BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx2.saturate();
                    BlockColorx2 *= 0.95f;
                }

            }
            else
            {
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }

        //faces
        //x-1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (x > 0)
            {
                transparentBlock = BlockTransparent(x-1,y,z);
                Block1 = GetBlock(x-1,y,z);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (x > 0)transparentBlock = BlockTransparentOrSpecial(x-1,y,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x-1,y,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x-1, y, z) & 0xF) / 15.0f;
                if(lightened > BlockColorx1.x)
                    BlockColorx1.x = BlockColorx1.y = BlockColorx1.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorx1;
            lightFactor = BlockColorx1 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x-1,y+0.1,z) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y+0.1,z+1))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x-1,y+0.1,z) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y+0.1,z-1))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x-1,y-0.1,z) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y-0.1,z+1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x-1,y-0.1,z) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y-0.1,z-1))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x, y,   z+1);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x, y+0.1, z+1);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x, y+0.1, z);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x, y,   z);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }


        //x+1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (x < WORLD_SIZE - 1)
            {
                transparentBlock = BlockTransparent(x+1,y,z);
                Block1 = GetBlock(x+1,y,z);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (x < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x+1,y,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x+1, y, z) & 0xF) / 15.0f;
                if(lightened > BlockColorx2.x)
                    BlockColorx2.x = BlockColorx2.y = BlockColorx2.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorx2;
            lightFactor = BlockColorx2 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x+1,y+0.1,z) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y+0.1,z+1))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+1,y+0.1,z) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y+0.1,z-1))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x+1,y-0.1,z) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y-0.1,z+1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+1,y-0.1,z) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y-0.1,z-1))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x+1, y,   z);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x+1, y+0.1, z);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x+1, y+0.1, z+1);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+1, y,   z+1);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }

        //y-1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (y > 0)
            {
                transparentBlock = BlockTransparent(x,y-0.1,z);
                Block1 = GetBlock(x,y-0.1,z);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (y > 0)transparentBlock = BlockTransparentOrSpecial(x,y-0.1,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            //up
            left = percent * blockType->downPlane;
            right = left + percent;

            if((GetBlockSettings(x,y-0.1,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y-0.1, z) & 0xF) / 15.0f;
                if(lightened > BlockColory2.x)
                    BlockColory2.x = BlockColory2.y = BlockColory2.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColory2;
            lightFactor = BlockColory1 * lightShadowFactor;

            //simple shadows
            if(!BlockTransparentOrLightSource(x-1,y-0.1,z) || !BlockTransparentOrLightSource(x-1,y-0.1,z-1) || !BlockTransparentOrLightSource(x,y-0.1,z-1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.1,z-1) || !BlockTransparentOrLightSource(x+1,y-0.1,z-1) || !BlockTransparentOrLightSource(x+1,y-0.1,z))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+1,y-0.1,z) || !BlockTransparentOrLightSource(x+1,y-0.1,z+1) || !BlockTransparentOrLightSource(x,y-0.1,z+1))
            {
                light3-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.1,z+1) || !BlockTransparentOrLightSource(x-1,y-0.1,z+1) || !BlockTransparentOrLightSource(x-1,y-0.1,z))
            {
                light4-=lightFactor;
            }

            MeshChunk->position(x,   y, z);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x+1, y, z);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+1, y, z+1);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x,   y, z+1);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light4.x,light4.y,light4.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }


        //top face
        //y+1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (y < WORLD_SIZE - 1)
            {
                transparentBlock = BlockTransparent(x,y+0.1,z);
                Block1 = GetBlock(x,y+0.1,z);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (y < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y+0.1,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            if((GetBlockSettings(x,y+0.1,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y+0.1, z) & 0xF) / 15.0f;
                if(lightened > BlockColory1.x)
                    BlockColory1.x = BlockColory1.y = BlockColory1.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColory1;
            lightFactor = BlockColory2 * lightShadowFactor;

            //simple shadows
            if(!BlockTransparentOrLightSource(x,y+0.1,z+1) || !BlockTransparentOrLightSource(x-1,y+0.1,z+1) || !BlockTransparentOrLightSource(x-1,y+0.1,z))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y+0.1,z+1) || !BlockTransparentOrLightSource(x+1,y+0.1,z+1) || !BlockTransparentOrLightSource(x+1,y+0.1,z))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+1,y+0.1,z) || !BlockTransparentOrLightSource(x+1,y+0.1,z-1) || !BlockTransparentOrLightSource(x,y+0.1,z-1))
            {
                light3-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y+0.1,z-1) || !BlockTransparentOrLightSource(x-1,y+0.1,z-1) || !BlockTransparentOrLightSource(x-1,y+0.1,z))
            {
                light4-=lightFactor;
            }

            //down
            left = percent * blockType->upPlane;
            right = left + percent;

            MeshChunk->position(x,   y+0.1, z+1);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x+1, y+0.1, z+1);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+1, y+0.1, z);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x,   y+0.1, z);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light4.x,light4.y,light4.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }

        //z-1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (z > 0)
            {
                transparentBlock = BlockTransparent(x,y,z-1);
                Block1 = GetBlock(x,y,z-1);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (z > 0)transparentBlock = BlockTransparentOrSpecial(x,y,z-1);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x,y,z-1) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y, z-1) & 0xF) / 15.0f;
                if(lightened > BlockColorz1.x)
                    BlockColorz1.x = BlockColorz1.y = BlockColorz1.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorz1;
            lightFactor = BlockColorz1 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x,y+0.1,z-1) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y+0.1,z-1))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y+0.1,z-1) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y+0.1,z-1))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x,y-0.1,z-1) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y-0.1,z-1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.1,z-1) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y-0.1,z-1))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x,   y+0.1, z);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+1, y+0.1, z);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x+1, y,   z);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x,   y,   z);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }


        //z+1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (z < WORLD_SIZE - 1)
            {
                transparentBlock = BlockTransparent(x,y,z+1);
                Block1 = GetBlock(x,y,z+1);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (z < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y,z+1);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate == true)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x,y,z+1) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y, z+1) & 0xF) / 15.0f;
                if(lightened > BlockColorz2.x)
                    BlockColorz2.x = BlockColorz2.y = BlockColorz2.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorz2;
            lightFactor = BlockColorz2 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x,y+0.1,z+1) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y+0.1,z+1))
            {
                light2-=lightFactor;
            }
            if(!BlockTransparentOrLightSource(x,y+0.1,z+1) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y+0.1,z+1))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x,y-0.1,z+1) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y-0.1,z+1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.1,z+1) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y-0.1,z+1))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x,   y,   z+1);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x+1, y,   z+1);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x+1, y+0.1, z+1);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x,   y+0.1, z+1);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }
    }

    if( Block == lilyPad::getID())
    {
        /* Only create visible faces of each chunk */
        bool DefaultBlock = false;
        bool transparentBlock;

        block_t Block1 = 0;

        Vector3 light1,light2,light3,light4;
        float BaseLight = 1.0f;

        Vector3 BlockColory1;    //Top face
        Vector3 BlockColory2;    //Bottom face
        Vector3 BlockColorx1;    //Sunset face
        Vector3 BlockColorx2;    //Sunrise face
        Vector3 BlockColorz1;     //Front/back faces
        Vector3 BlockColorz2;     //Front/back faces

        //texture stuff
        BaseBlock *blockType = &blockTypes[Block];

        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent;

        float left = percent * blockType->upPlane;
        float right = left + percent;

        bool canCreate = false;

        //lightened
        //if time is between 21-4 use settings table for lightening
        //if time is between 5-20 use normal light table but compare it with settings table
        //	if setting is brighter then use it
        if(worldDayTime >= 21 || worldDayTime <= 4)//night
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                BaseLight  = (float)(GetBlockSettings(x, y, z) & 0xF)/16.0f; // 255.0f;  //For the two x faces

                BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                BlockColorz1  = BlockColorz2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
            }
            else //normal light
            {
                //light
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;  //For the two x faces
                //float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
                //float BlockLight2 = BlockLight * 0.8f;		//For the two y faces

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }
        else //day
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                //int normal = GetBlockLight(x, y, z);
                //int lightened = (GetBlockSettings(x, y, z) & 0xF) * 16;

                float normal = lightColor.x * (factor1 * (GetBlockLight(x, y, z) / 255.0f)) + ambientColor.x;
                float lightened = (GetBlockSettings(x, y, z) & 0xF) / 15.0f;

                if(lightened > normal)
                {
                    BaseLight = lightened; // 255.0f;
                    BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                    BlockColorz2 = BlockColorz1  = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                    BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
                }
                else
                {
                    BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                    BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                    BlockColory1.saturate();
                    BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                    BlockColory2.saturate();
                    BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                    BlockColorz1.saturate();
                    BlockColorz1 *= 0.80f;
                    BlockColorz2 = BlockColorz1;

                    BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx1.saturate();
                    BlockColorx1 *= 0.95f;

                    BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx2.saturate();
                    BlockColorx2 *= 0.95f;
                }

            }
            else
            {
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }

        //faces
        //x-1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (x > 0)
            {
                transparentBlock = BlockTransparent(x-1,y,z);
                Block1 = GetBlock(x-1,y,z);
            }

            if (transparentBlock == true || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (x > 0)transparentBlock = BlockTransparentOrSpecial(x-1,y,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x-1,y,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x-1, y, z) & 0xF) / 15.0f;
                if(lightened > BlockColorx1.x)
                    BlockColorx1.x = BlockColorx1.y = BlockColorx1.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorx1;
            lightFactor = BlockColorx1 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x-1,y+0.1,z) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y+0.1,z+1))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x-1,y+0.1,z) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y+0.1,z-1))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x-1,y-0.1,z) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y-0.1,z+1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x-1,y-0.1,z) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y-0.1,z-1))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x, y,   z+1);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x, y+0.1, z+1);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x, y+0.1, z);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x, y,   z);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }


        //x+1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (x < WORLD_SIZE - 1)
            {
                transparentBlock = BlockTransparent(x+1,y,z);
                Block1 = GetBlock(x+1,y,z);
            }

            if (transparentBlock == true || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (x < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x+1,y,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x+1, y, z) & 0xF) / 15.0f;
                if(lightened > BlockColorx2.x)
                    BlockColorx2.x = BlockColorx2.y = BlockColorx2.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorx2;
            lightFactor = BlockColorx2 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x+1,y+0.1,z) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y+0.1,z+1))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+1,y+0.1,z) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y+0.1,z-1))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x+1,y-0.1,z) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y-0.1,z+1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+1,y-0.1,z) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y-0.1,z-1))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x+1, y,   z);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x+1, y+0.1, z);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x+1, y+0.1, z+1);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+1, y,   z+1);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }

        //y-1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (y > 0)
            {
                transparentBlock = BlockTransparent(x,y-0.1,z);
                Block1 = GetBlock(x,y-0.1,z);
            }

            if (transparentBlock == true || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (y > 0)transparentBlock = BlockTransparentOrSpecial(x,y-0.1,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            //up
            left = percent * blockType->downPlane;
            right = left + percent;

            if((GetBlockSettings(x,y-0.1,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y-0.1, z) & 0xF) / 15.0f;
                if(lightened > BlockColory2.x)
                    BlockColory2.x = BlockColory2.y = BlockColory2.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColory2;
            lightFactor = BlockColory1 * lightShadowFactor;

            //simple shadows
            if(!BlockTransparentOrLightSource(x-1,y-0.1,z) || !BlockTransparentOrLightSource(x-1,y-0.1,z-1) || !BlockTransparentOrLightSource(x,y-0.1,z-1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.1,z-1) || !BlockTransparentOrLightSource(x+1,y-0.1,z-1) || !BlockTransparentOrLightSource(x+1,y-0.1,z))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+1,y-0.1,z) || !BlockTransparentOrLightSource(x+1,y-0.1,z+1) || !BlockTransparentOrLightSource(x,y-0.1,z+1))
            {
                light3-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.1,z+1) || !BlockTransparentOrLightSource(x-1,y-0.1,z+1) || !BlockTransparentOrLightSource(x-1,y-0.1,z))
            {
                light4-=lightFactor;
            }

            MeshChunk->position(x,   y, z);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x+1, y, z);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+1, y, z+1);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x,   y, z+1);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light4.x,light4.y,light4.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }


        //top face
        //y+1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (y < WORLD_SIZE - 1)
            {
                transparentBlock = BlockTransparent(x,y+0.1,z);
                Block1 = GetBlock(x,y+0.1,z);
            }

            if (transparentBlock == true || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (y < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y+0.1,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            if((GetBlockSettings(x,y+0.1,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y+0.1, z) & 0xF) / 15.0f;
                if(lightened > BlockColory1.x)
                    BlockColory1.x = BlockColory1.y = BlockColory1.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColory1;
            lightFactor = BlockColory2 * lightShadowFactor;

            //simple shadows
            if(!BlockTransparentOrLightSource(x,y+0.1,z+1) || !BlockTransparentOrLightSource(x-1,y+0.1,z+1) || !BlockTransparentOrLightSource(x-1,y+0.1,z))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y+0.1,z+1) || !BlockTransparentOrLightSource(x+1,y+0.1,z+1) || !BlockTransparentOrLightSource(x+1,y+0.1,z))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+1,y+0.1,z) || !BlockTransparentOrLightSource(x+1,y+0.1,z-1) || !BlockTransparentOrLightSource(x,y+0.1,z-1))
            {
                light3-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y+0.1,z-1) || !BlockTransparentOrLightSource(x-1,y+0.1,z-1) || !BlockTransparentOrLightSource(x-1,y+0.1,z))
            {
                light4-=lightFactor;
            }

            //down
            left = percent * blockType->upPlane;
            right = left + percent;

            MeshChunk->position(x,   y+0.1, z+1);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x+1, y+0.1, z+1);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+1, y+0.1, z);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x,   y+0.1, z);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light4.x,light4.y,light4.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }

        //z-1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (z > 0)
            {
                transparentBlock = BlockTransparent(x,y,z-1);
                Block1 = GetBlock(x,y,z-1);
            }

            if (transparentBlock == true || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (z > 0)transparentBlock = BlockTransparentOrSpecial(x,y,z-1);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x,y,z-1) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y, z-1) & 0xF) / 15.0f;
                if(lightened > BlockColorz1.x)
                    BlockColorz1.x = BlockColorz1.y = BlockColorz1.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorz1;
            lightFactor = BlockColorz1 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x,y+0.1,z-1) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y+0.1,z-1))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y+0.1,z-1) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y+0.1,z-1))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x,y-0.1,z-1) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y-0.1,z-1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.1,z-1) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y-0.1,z-1))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x,   y+0.1, z);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+1, y+0.1, z);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x+1, y,   z);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x,   y,   z);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }


        //z+1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (z < WORLD_SIZE - 1)
            {
                transparentBlock = BlockTransparent(x,y,z+1);
                Block1 = GetBlock(x,y,z+1);
            }

            if (transparentBlock == true || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (z < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y,z+1);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate == true)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x,y,z+1) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y, z+1) & 0xF) / 15.0f;
                if(lightened > BlockColorz2.x)
                    BlockColorz2.x = BlockColorz2.y = BlockColorz2.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorz2;
            lightFactor = BlockColorz2 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x,y+0.1,z+1) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y+0.1,z+1))
            {
                light2-=lightFactor;
            }
            if(!BlockTransparentOrLightSource(x,y+0.1,z+1) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y+0.1,z+1))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x,y-0.1,z+1) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y-0.1,z+1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.1,z+1) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y-0.1,z+1))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x,   y,   z+1);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x+1, y,   z+1);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x+1, y+0.1, z+1);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x,   y+0.1, z+1);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }
    }

    if( Block == Table::getID() || Block == endPortal::getID())
    {
        /* Only create visible faces of each chunk */
        bool DefaultBlock = false;
        bool transparentBlock;

        block_t Block1 = 0;

        Vector3 light1,light2,light3,light4;
        float BaseLight = 1.0f;

        Vector3 BlockColory1;    //Top face
        Vector3 BlockColory2;    //Bottom face
        Vector3 BlockColorx1;    //Sunset face
        Vector3 BlockColorx2;    //Sunrise face
        Vector3 BlockColorz1;     //Front/back faces
        Vector3 BlockColorz2;     //Front/back faces

        //texture stuff
        BaseBlock *blockType = &blockTypes[Block];

        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent;

        float left = percent * blockType->upPlane;
        float right = left + percent;

        bool canCreate = false;

        //lightened
        //if time is between 21-4 use settings table for lightening
        //if time is between 5-20 use normal light table but compare it with settings table
        //	if setting is brighter then use it
        if(worldDayTime >= 21 || worldDayTime <= 4)//night
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                BaseLight  = (float)(GetBlockSettings(x, y, z) & 0xF)/16.0f; // 255.0f;  //For the two x faces

                BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                BlockColorz1  = BlockColorz2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
            }
            else //normal light
            {
                //light
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;  //For the two x faces
                //float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
                //float BlockLight2 = BlockLight * 0.8f;		//For the two y faces

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }
        else //day
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                //int normal = GetBlockLight(x, y, z);
                //int lightened = (GetBlockSettings(x, y, z) & 0xF) * 16;

                float normal = lightColor.x * (factor1 * (GetBlockLight(x, y, z) / 255.0f)) + ambientColor.x;
                float lightened = (GetBlockSettings(x, y, z) & 0xF) / 15.0f;

                if(lightened > normal)
                {
                    BaseLight = lightened; // 255.0f;
                    BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                    BlockColorz2 = BlockColorz1  = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                    BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
                }
                else
                {
                    BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                    BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                    BlockColory1.saturate();
                    BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                    BlockColory2.saturate();
                    BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                    BlockColorz1.saturate();
                    BlockColorz1 *= 0.80f;
                    BlockColorz2 = BlockColorz1;

                    BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx1.saturate();
                    BlockColorx1 *= 0.95f;

                    BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx2.saturate();
                    BlockColorx2 *= 0.95f;
                }

            }
            else
            {
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }

        //faces
        //x-1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (x > 0)
            {
                transparentBlock = BlockTransparent(x-1,y,z);
                Block1 = GetBlock(x-1,y,z);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (x > 0)transparentBlock = BlockTransparentOrSpecial(x-1,y,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x-1,y,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x-1, y, z) & 0xF) / 15.0f;
                if(lightened > BlockColorx1.x)
                    BlockColorx1.x = BlockColorx1.y = BlockColorx1.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorx1;
            lightFactor = BlockColorx1 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x-1,y+0.65,z) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y+0.65,z+1))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x-1,y+0.65,z) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y+0.65,z-1))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x-1,y-0.65,z) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y-0.65,z+1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x-1,y-0.65,z) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y-0.65,z-1))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x, y,   z+1);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x, y+0.65, z+1);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x, y+0.65, z);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x, y,   z);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }


        //x+1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (x < WORLD_SIZE - 1)
            {
                transparentBlock = BlockTransparent(x+1,y,z);
                Block1 = GetBlock(x+1,y,z);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (x < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x+1,y,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x+1, y, z) & 0xF) / 15.0f;
                if(lightened > BlockColorx2.x)
                    BlockColorx2.x = BlockColorx2.y = BlockColorx2.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorx2;
            lightFactor = BlockColorx2 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x+1,y+0.65,z) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y+0.65,z+1))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+1,y+0.65,z) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y+0.65,z-1))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x+1,y-0.65,z) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y-0.65,z+1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+1,y-0.65,z) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y-0.65,z-1))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x+1, y,   z);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x+1, y+0.65, z);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x+1, y+0.65, z+1);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+1, y,   z+1);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }

        //y-1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (y > 0)
            {
                transparentBlock = BlockTransparent(x,y-0.65,z);
                Block1 = GetBlock(x,y-0.65,z);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (y > 0)transparentBlock = BlockTransparentOrSpecial(x,y-0.65,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            //up
            left = percent * blockType->downPlane;
            right = left + percent;

            if((GetBlockSettings(x,y-0.65,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y-0.65, z) & 0xF) / 15.0f;
                if(lightened > BlockColory2.x)
                    BlockColory2.x = BlockColory2.y = BlockColory2.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColory2;
            lightFactor = BlockColory1 * lightShadowFactor;

            //simple shadows
            if(!BlockTransparentOrLightSource(x-1,y-0.65,z) || !BlockTransparentOrLightSource(x-1,y-0.65,z-1) || !BlockTransparentOrLightSource(x,y-0.65,z-1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.65,z-1) || !BlockTransparentOrLightSource(x+1,y-0.65,z-1) || !BlockTransparentOrLightSource(x+1,y-0.65,z))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+1,y-0.65,z) || !BlockTransparentOrLightSource(x+1,y-0.65,z+1) || !BlockTransparentOrLightSource(x,y-0.65,z+1))
            {
                light3-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.65,z+1) || !BlockTransparentOrLightSource(x-1,y-0.65,z+1) || !BlockTransparentOrLightSource(x-1,y-0.65,z))
            {
                light4-=lightFactor;
            }

            MeshChunk->position(x,   y, z);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x+1, y, z);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+1, y, z+1);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x,   y, z+1);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light4.x,light4.y,light4.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }


        //top face
        //y+1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (y < WORLD_SIZE - 1)
            {
                transparentBlock = BlockTransparent(x,y+0.65,z);
                Block1 = GetBlock(x,y+0.65,z);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (y < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y+0.65,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            if((GetBlockSettings(x,y+0.65,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y+0.65, z) & 0xF) / 15.0f;
                if(lightened > BlockColory1.x)
                    BlockColory1.x = BlockColory1.y = BlockColory1.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColory1;
            lightFactor = BlockColory2 * lightShadowFactor;

            //simple shadows
            if(!BlockTransparentOrLightSource(x,y+0.65,z+1) || !BlockTransparentOrLightSource(x-1,y+0.65,z+1) || !BlockTransparentOrLightSource(x-1,y+0.65,z))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y+0.65,z+1) || !BlockTransparentOrLightSource(x+1,y+0.65,z+1) || !BlockTransparentOrLightSource(x+1,y+0.65,z))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+1,y+0.65,z) || !BlockTransparentOrLightSource(x+1,y+0.65,z-1) || !BlockTransparentOrLightSource(x,y+0.65,z-1))
            {
                light3-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y+0.65,z-1) || !BlockTransparentOrLightSource(x-1,y+0.65,z-1) || !BlockTransparentOrLightSource(x-1,y+0.65,z))
            {
                light4-=lightFactor;
            }

            //down
            left = percent * blockType->upPlane;
            right = left + percent;

            MeshChunk->position(x,   y+0.65, z+1);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x+1, y+0.65, z+1);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+1, y+0.65, z);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x,   y+0.65, z);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light4.x,light4.y,light4.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }

        //z-1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (z > 0)
            {
                transparentBlock = BlockTransparent(x,y,z-1);
                Block1 = GetBlock(x,y,z-1);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (z > 0)transparentBlock = BlockTransparentOrSpecial(x,y,z-1);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x,y,z-1) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y, z-1) & 0xF) / 15.0f;
                if(lightened > BlockColorz1.x)
                    BlockColorz1.x = BlockColorz1.y = BlockColorz1.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorz1;
            lightFactor = BlockColorz1 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x,y+0.65,z-1) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y+0.65,z-1))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y+0.65,z-1) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y+0.65,z-1))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x,y-0.65,z-1) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y-0.65,z-1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.65,z-1) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y-0.65,z-1))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x,   y+0.65, z);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+1, y+0.65, z);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x+1, y,   z);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x,   y,   z);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }


        //z+1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (z < WORLD_SIZE - 1)
            {
                transparentBlock = BlockTransparent(x,y,z+1);
                Block1 = GetBlock(x,y,z+1);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (z < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y,z+1);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate == true)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x,y,z+1) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y, z+1) & 0xF) / 15.0f;
                if(lightened > BlockColorz2.x)
                    BlockColorz2.x = BlockColorz2.y = BlockColorz2.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorz2;
            lightFactor = BlockColorz2 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x,y+0.65,z+1) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y+0.65,z+1))
            {
                light2-=lightFactor;
            }
            if(!BlockTransparentOrLightSource(x,y+0.65,z+1) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y+0.65,z+1))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x,y-0.65,z+1) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y-0.65,z+1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.65,z+1) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y-0.65,z+1))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x,   y,   z+1);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x+1, y,   z+1);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x+1, y+0.65, z+1);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x,   y+0.65, z+1);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }
    }


    if(Block == brickWallSlap::getID() || Block == quartzSlap::getID() || Block == HalfBlock1::getID() || Block == HalfBlock2::getID() || Block == HalfBlock3::getID() || Block == HalfBlock4::getID() || Block == HalfBlock5::getID() || Block == HalfBlock6::getID() || Block == HalfBlock7::getID() || Block == HalfBlock0::getID() || Block == HalfBlock8::getID())
    {
        /* Only create visible faces of each chunk */
        bool DefaultBlock = false;
        bool transparentBlock;

        block_t Block1 = 0;

        Vector3 light1,light2,light3,light4;
        float BaseLight = 1.0f;

        Vector3 BlockColory1;    //Top face
        Vector3 BlockColory2;    //Bottom face
        Vector3 BlockColorx1;    //Sunset face
        Vector3 BlockColorx2;    //Sunrise face
        Vector3 BlockColorz1;     //Front/back faces
        Vector3 BlockColorz2;     //Front/back faces

        //texture stuff
        BaseBlock *blockType = &blockTypes[Block];

        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent;

        float left = percent * blockType->upPlane;
        float right = left + percent;

        bool canCreate = false;

        //lightened
        //if time is between 21-4 use settings table for lightening
        //if time is between 5-20 use normal light table but compare it with settings table
        //	if setting is brighter then use it
        if(worldDayTime >= 21 || worldDayTime <= 4)//night
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                BaseLight  = (float)(GetBlockSettings(x, y, z) & 0xF)/16.0f; // 255.0f;  //For the two x faces

                BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                BlockColorz1  = BlockColorz2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
            }
            else //normal light
            {
                //light
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;  //For the two x faces
                //float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
                //float BlockLight2 = BlockLight * 0.8f;		//For the two y faces

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }
        else //day
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                //int normal = GetBlockLight(x, y, z);
                //int lightened = (GetBlockSettings(x, y, z) & 0xF) * 16;

                float normal = lightColor.x * (factor1 * (GetBlockLight(x, y, z) / 255.0f)) + ambientColor.x;
                float lightened = (GetBlockSettings(x, y, z) & 0xF) / 15.0f;

                if(lightened > normal)
                {
                    BaseLight = lightened; // 255.0f;
                    BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                    BlockColorz2 = BlockColorz1  = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                    BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
                }
                else
                {
                    BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                    BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                    BlockColory1.saturate();
                    BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                    BlockColory2.saturate();
                    BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                    BlockColorz1.saturate();
                    BlockColorz1 *= 0.80f;
                    BlockColorz2 = BlockColorz1;

                    BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx1.saturate();
                    BlockColorx1 *= 0.95f;

                    BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx2.saturate();
                    BlockColorx2 *= 0.95f;
                }

            }
            else
            {
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }

        //faces
        //x-1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (x > 0)
            {
                transparentBlock = BlockTransparent(x-1,y,z);
                Block1 = GetBlock(x-1,y,z);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (x > 0)transparentBlock = BlockTransparentOrSpecial(x-1,y,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x-1,y,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x-1, y, z) & 0xF) / 15.0f;
                if(lightened > BlockColorx1.x)
                    BlockColorx1.x = BlockColorx1.y = BlockColorx1.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorx1;
            lightFactor = BlockColorx1 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x-1,y+0.5,z) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y+0.5,z+1))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x-1,y+0.5,z) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y+0.5,z-1))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x-1,y-0.5,z) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y-0.5,z+1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x-1,y-0.5,z) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y-0.5,z-1))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x, y,   z+1);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x, y+0.5, z+1);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x, y+0.5, z);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x, y,   z);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }


        //x+1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (x < WORLD_SIZE - 1)
            {
                transparentBlock = BlockTransparent(x+1,y,z);
                Block1 = GetBlock(x+1,y,z);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (x < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x+1,y,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x+1, y, z) & 0xF) / 15.0f;
                if(lightened > BlockColorx2.x)
                    BlockColorx2.x = BlockColorx2.y = BlockColorx2.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorx2;
            lightFactor = BlockColorx2 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x+1,y+0.5,z) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y+0.5,z+1))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+1,y+0.5,z) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y+0.5,z-1))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x+1,y-0.5,z) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y-0.5,z+1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+1,y-0.5,z) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y-0.5,z-1))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x+1, y,   z);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x+1, y+0.5, z);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x+1, y+0.5, z+1);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+1, y,   z+1);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }

        //y-1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (y > 0)
            {
                transparentBlock = BlockTransparent(x,y-0.5,z);
                Block1 = GetBlock(x,y-0.5,z);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (y > 0)transparentBlock = BlockTransparentOrSpecial(x,y-0.5,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            //up
            left = percent * blockType->downPlane;
            right = left + percent;

            if((GetBlockSettings(x,y-1,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y-0.5, z) & 0xF) / 15.0f;
                if(lightened > BlockColory2.x)
                    BlockColory2.x = BlockColory2.y = BlockColory2.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColory2;
            lightFactor = BlockColory1 * lightShadowFactor;

            //simple shadows
            if(!BlockTransparentOrLightSource(x-1,y-0.5,z) || !BlockTransparentOrLightSource(x-1,y-0.5,z-1) || !BlockTransparentOrLightSource(x,y-0.5,z-1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.5,z-1) || !BlockTransparentOrLightSource(x+1,y-0.5,z-1) || !BlockTransparentOrLightSource(x+1,y-0.5,z))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+1,y-0.5,z) || !BlockTransparentOrLightSource(x+1,y-0.5,z+1) || !BlockTransparentOrLightSource(x,y-0.5,z+1))
            {
                light3-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.5,z+1) || !BlockTransparentOrLightSource(x-1,y-0.5,z+1) || !BlockTransparentOrLightSource(x-1,y-0.5,z))
            {
                light4-=lightFactor;
            }

            MeshChunk->position(x,   y, z);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x+1, y, z);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+1, y, z+1);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x,   y, z+1);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light4.x,light4.y,light4.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }


        //top face
        //y+1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (y < WORLD_SIZE - 1)
            {
                transparentBlock = BlockTransparent(x,y+0.5,z);
                Block1 = GetBlock(x,y+0.5,z);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (y < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y+0.5,z);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            if((GetBlockSettings(x,y+0.5,z) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y+0.5, z) & 0xF) / 15.0f;
                if(lightened > BlockColory1.x)
                    BlockColory1.x = BlockColory1.y = BlockColory1.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColory1;
            lightFactor = BlockColory2 * lightShadowFactor;

            //simple shadows
            if(!BlockTransparentOrLightSource(x,y+0.5,z+1) || !BlockTransparentOrLightSource(x-1,y+0.5,z+1) || !BlockTransparentOrLightSource(x-1,y+0.5,z))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y+0.5,z+1) || !BlockTransparentOrLightSource(x+1,y+0.5,z+1) || !BlockTransparentOrLightSource(x+1,y+0.5,z))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x+1,y+0.5,z) || !BlockTransparentOrLightSource(x+1,y+0.5,z-1) || !BlockTransparentOrLightSource(x,y+0.5,z-1))
            {
                light3-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y+0.5,z-1) || !BlockTransparentOrLightSource(x-1,y+0.5,z-1) || !BlockTransparentOrLightSource(x-1,y+0.5,z))
            {
                light4-=lightFactor;
            }

            //down
            left = percent * blockType->upPlane;
            right = left + percent;

            MeshChunk->position(x,   y+0.5, z+1);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x+1, y+0.5, z+1);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+1, y+0.5, z);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x,   y+0.5, z);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light4.x,light4.y,light4.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }

        //z-1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (z > 0)
            {
                transparentBlock = BlockTransparent(x,y,z-1);
                Block1 = GetBlock(x,y,z-1);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (z > 0)transparentBlock = BlockTransparentOrSpecial(x,y,z-1);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x,y,z-1) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y, z-1) & 0xF) / 15.0f;
                if(lightened > BlockColorz1.x)
                    BlockColorz1.x = BlockColorz1.y = BlockColorz1.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorz1;
            lightFactor = BlockColorz1 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x,y+0.5,z-1) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y+0.5,z-1))
            {
                light2-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y+0.5,z-1) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y+0.5,z-1))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x,y-0.5,z-1) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y-0.5,z-1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.5,z-1) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y-0.5,z-1))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x,   y+0.5, z);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);
            MeshChunk->position(x+1, y+0.5, z);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x+1, y,   z);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x,   y,   z);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }


        //z+1
        transparentBlock = DefaultBlock;
        canCreate = false;
        if(transparent)
        {
            Block1 = 1;
            if (z < WORLD_SIZE - 1)
            {
                transparentBlock = BlockTransparent(x,y,z+1);
                Block1 = GetBlock(x,y,z+1);
            }

            if (transparentBlock == false || Block1 == 0)
                canCreate = true;
        }
        else
        {
            if (z < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y,z+1);
            if (transparentBlock == true)
                canCreate = true;
        }

        if (canCreate == true)
        {
            left = percent * blockType->sidePlane;
            right = left + percent;

            if((GetBlockSettings(x,y,z+1) & OpLighSource) != 0)//block is lightened
            {
                float lightened = (GetBlockSettings(x, y, z+1) & 0xF) / 15.0f;
                if(lightened > BlockColorz2.x)
                    BlockColorz2.x = BlockColorz2.y = BlockColorz2.z = lightened;
            }

            light1 = light2 = light3 = light4 = BlockColorz2;
            lightFactor = BlockColorz2 * lightShadowFactor;

            //simple shadows
            //up
            if(!BlockTransparentOrLightSource(x,y+0.5,z+1) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y+0.5,z+1))
            {
                light2-=lightFactor;
            }
            if(!BlockTransparentOrLightSource(x,y+0.5,z+1) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y+0.5,z+1))
            {
                light4-=lightFactor;
            }

            //down
            if(!BlockTransparentOrLightSource(x,y-0.5,z+1) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y-0.5,z+1))
            {
                light1-=lightFactor;
            }

            if(!BlockTransparentOrLightSource(x,y-0.5,z+1) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y-0.5,z+1))
            {
                light3-=lightFactor;
            }

            MeshChunk->position(x,   y,   z+1);
            MeshChunk->textureCoord(left, down);
            MeshChunk->colour(light1.x,light1.y,light1.z);
            MeshChunk->position(x+1, y,   z+1);
            MeshChunk->textureCoord(right, down);
            MeshChunk->colour(light3.x,light3.y,light3.z);
            MeshChunk->position(x+1, y+0.5, z+1);
            MeshChunk->textureCoord(right, up);
            MeshChunk->colour(light4.x,light4.y,light4.z);
            MeshChunk->position(x,   y+0.5, z+1);
            MeshChunk->textureCoord(left, up);
            MeshChunk->colour(light2.x,light2.y,light2.z);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }
    }

    if(Block == Door3::getID() || Block == Door4::getID())
    {
        bool DefaultBlock = false;
        bool transparentBlock;

        block_t Block1 = 0;

        Vector3 light1,light2,light3,light4;
        float BaseLight = 1.0f;

        Vector3 BlockColory1;    //Top face
        Vector3 BlockColory2;    //Bottom face
        Vector3 BlockColorx1;    //Sunset face
        Vector3 BlockColorx2;    //Sunrise face
        Vector3 BlockColorz1;     //Front/back faces
        Vector3 BlockColorz2;     //Front/back faces

        //texture stuff
        BaseBlock *blockType = &blockTypes[Block];

        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent;

        float left = percent * blockType->upPlane;
        float right = left + percent;

        bool canCreate = false;

        //lightened
        //if time is between 21-4 use settings table for lightening
        //if time is between 5-20 use normal light table but compare it with settings table
        //	if setting is brighter then use it
        if(worldDayTime >= 21 || worldDayTime <= 4)//night
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                BaseLight  = (float)(GetBlockSettings(x, y, z) & 0xF)/16.0f; // 255.0f;  //For the two x faces

                BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                BlockColorz1  = BlockColorz2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
            }
            else //normal light
            {
                //light
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;  //For the two x faces
                //float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
                //float BlockLight2 = BlockLight * 0.8f;		//For the two y faces

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }
        else //day
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                //int normal = GetBlockLight(x, y, z);
                //int lightened = (GetBlockSettings(x, y, z) & 0xF) * 16;

                float normal = lightColor.x * (factor1 * (GetBlockLight(x, y, z) / 255.0f)) + ambientColor.x;
                float lightened = (GetBlockSettings(x, y, z) & 0xF) / 15.0f;

                if(lightened > normal)
                {
                    BaseLight = lightened; // 255.0f;
                    BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                    BlockColorz2 = BlockColorz1  = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                    BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
                }
                else
                {
                    BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                    BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                    BlockColory1.saturate();
                    BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                    BlockColory2.saturate();
                    BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                    BlockColorz1.saturate();
                    BlockColorz1 *= 0.80f;
                    BlockColorz2 = BlockColorz1;

                    BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx1.saturate();
                    BlockColorx1 *= 0.95f;

                    BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx2.saturate();
                    BlockColorx2 *= 0.95f;
                }

            }
            else
            {
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }

        if(GetBlock(x,y,z+1) != 0 || GetBlock(x-1,y,z-1) != 0 || (GetBlock(x,y,z+1) != 0 && GetBlock(x-1,y,z-1) != 0))
        {
            //faces
            //x-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x > 0)
                {
                    transparentBlock = BlockTransparent(x-1,y,z);
                    Block1 = GetBlock(x-1,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x > 0)transparentBlock = BlockTransparentOrSpecial(x-1,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x-1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x-1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx1.x)
                        BlockColorx1.x = BlockColorx1.y = BlockColorx1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx1;
                lightFactor = BlockColorx1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x-0.2,y+1,z) || !BlockTransparentOrLightSource(x-0.2,y,z+1) || !BlockTransparentOrLightSource(x-0.2,y+1,z+1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-0.2,y+1,z) || !BlockTransparentOrLightSource(x-0.2,y,z-1) || !BlockTransparentOrLightSource(x-0.2,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x-0.2,y-1,z) || !BlockTransparentOrLightSource(x-0.2,y,z+1) || !BlockTransparentOrLightSource(x-0.2,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-0.2,y-1,z) || !BlockTransparentOrLightSource(x-0.2,y,z-1) || !BlockTransparentOrLightSource(x-0.2,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x, y,   z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //x+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x+0.2,y,z);
                    Block1 = GetBlock(x+0.2,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x+0.2,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x+1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx2.x)
                        BlockColorx2.x = BlockColorx2.y = BlockColorx2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx2;
                lightFactor = BlockColorx2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x+0.2,y+1,z) || !BlockTransparentOrLightSource(x+0.2,y,z+1) || !BlockTransparentOrLightSource(x+0.2,y+1,z+1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.2,y+1,z) || !BlockTransparentOrLightSource(x+0.2,y,z-1) || !BlockTransparentOrLightSource(x+0.2,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x+0.2,y-1,z) || !BlockTransparentOrLightSource(x+0.2,y,z+1) || !BlockTransparentOrLightSource(x+0.2,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.2,y-1,z) || !BlockTransparentOrLightSource(x+0.2,y,z-1) || !BlockTransparentOrLightSource(x+0.2,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x+0.2, y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+0.2, y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+0.2, y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.2, y,   z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //y-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y > 0)
                {
                    transparentBlock = BlockTransparent(x,y-1,z);
                    Block1 = GetBlock(x,y-1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y > 0)transparentBlock = BlockTransparentOrSpecial(x,y-1,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                //up
                left = percent * blockType->downPlane;
                right = left + percent;

                if((GetBlockSettings(x,y-1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y-1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory2.x)
                        BlockColory2.x = BlockColory2.y = BlockColory2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory2;
                lightFactor = BlockColory1 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-0.2,y-1,z-1) || !BlockTransparentOrLightSource(x,y-1,z-1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x+0.2,y-1,z-1) || !BlockTransparentOrLightSource(x+0.2,y-0.5,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.2,y-1,z) || !BlockTransparentOrLightSource(x+0.2,y-1,z+1) || !BlockTransparentOrLightSource(x,y-1,z+1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-0.2,y-1,z+1) || !BlockTransparentOrLightSource(x-0.2,y-1,z))
                {
                    light4-=lightFactor;
                }

                MeshChunk->position(x,   y, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+0.2, y, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.2 , y, z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y, z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //top face
            //y+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y+1,z);
                    Block1 = GetBlock(x,y+1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y+0.5,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                if((GetBlockSettings(x,y+1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y+1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory1.x)
                        BlockColory1.x = BlockColory1.y = BlockColory1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory1;
                lightFactor = BlockColory2 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x-0.2,y+1,z+1) || !BlockTransparentOrLightSource(x-0.2,y+1,z))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x+0.2,y+1,z+1) || !BlockTransparentOrLightSource(x+0.2,y+1,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+0.2,y+1,z) || !BlockTransparentOrLightSource(x+0.2,y+1,z-1) || !BlockTransparentOrLightSource(x,y+1,z-1))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x-0.2,y+1,z-1) || !BlockTransparentOrLightSource(x-0.2,y+1,z))
                {
                    light4-=lightFactor;
                }

                //down
                left = percent * blockType->upPlane;
                right = left + percent;

                MeshChunk->position(x,   y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+0.2, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.2, y+1, z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //z-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z > 0)
                {
                    transparentBlock = BlockTransparent(x,y,z-1);
                    Block1 = GetBlock(x,y,z-1);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z > 0)transparentBlock = BlockTransparentOrSpecial(x,y,z-1);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z-0.9) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z-1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz1.x)
                        BlockColorz1.x = BlockColorz1.y = BlockColorz1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz1;
                lightFactor = BlockColorz1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x-0.2,y,z-1) || !BlockTransparentOrLightSource(x-0.2,y+1,z-1))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x+0.2,y,z-1) || !BlockTransparentOrLightSource(x+0.2,y+1,z-1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x-0.2,y,z-1) || !BlockTransparentOrLightSource(x-0.2,y-1,z-1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x+0.2,y,z-1) || !BlockTransparentOrLightSource(x+0.2,y-1,z-1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+0.2, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+0.2, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //z+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y,z+1);
                    Block1 = GetBlock(x,y,z+1);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y,z+1);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate == true)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z+1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z+1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz2.x)
                        BlockColorz2.x = BlockColorz2.y = BlockColorz2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz2;
                lightFactor = BlockColorz2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x-0.2,y,z+1) || !BlockTransparentOrLightSource(x-0.2,y+1,z+1))
                {
                    light2-=lightFactor;
                }
                if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x+0.2,y,z+1) || !BlockTransparentOrLightSource(x+0.2,y+1,z+1))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-0.2,y,z+1) || !BlockTransparentOrLightSource(x-0.2,y-1,z+1))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x+0.2,y,z+1) || !BlockTransparentOrLightSource(x+0.2,y-1,z+1))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y,   z+1);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+0.2, y,   z+1);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+0.2, y+1, z+1);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x,   y+1, z+1);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }
        }

        else if(GetBlock(x+1,y,z) != 0 || GetBlock(x-1,y,z) != 0 || (GetBlock(x+1,y,z) != 0 && GetBlock(x-1,y,z) != 0))
        {
            //faces
            //x-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x > 0)
                {
                    transparentBlock = BlockTransparent(x-1,y,z);
                    Block1 = GetBlock(x-1,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x > 0)transparentBlock = BlockTransparentOrSpecial(x-1,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x-1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x-1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx1.x)
                        BlockColorx1.x = BlockColorx1.y = BlockColorx1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx1;
                lightFactor = BlockColorx1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x-1,y+1,z) || !BlockTransparentOrLightSource(x-1,y,z+0.2) || !BlockTransparentOrLightSource(x-1,y+1,z+0.2))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-1,y+1,z) || !BlockTransparentOrLightSource(x-1,y,z-0.2) || !BlockTransparentOrLightSource(x-1,y+1,z-0.2))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y,z+0.2) || !BlockTransparentOrLightSource(x-1,y-1,z+0.2))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y,z-0.2) || !BlockTransparentOrLightSource(x-1,y-1,z-0.2))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x, y,   z+0.2);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x, y+1, z+0.2);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //x+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x+1,y,z);
                    Block1 = GetBlock(x+1,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x+1,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x+1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx2.x)
                        BlockColorx2.x = BlockColorx2.y = BlockColorx2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx2;
                lightFactor = BlockColorx2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y,z+0.2) || !BlockTransparentOrLightSource(x+1,y+1,z+0.2))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y,z-0.2) || !BlockTransparentOrLightSource(x+1,y+1,z-0.2))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y,z+0.2) || !BlockTransparentOrLightSource(x+1,y-1,z+0.2))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y,z-0.2) || !BlockTransparentOrLightSource(x+1,y-1,z-0.2))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x+1, y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+1, y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+1, y+1, z+0.2);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y,   z+0.2);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //y-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y > 0)
                {
                    transparentBlock = BlockTransparent(x,y-1,z);
                    Block1 = GetBlock(x,y-1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y > 0)transparentBlock = BlockTransparentOrSpecial(x,y-1,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                //up
                left = percent * blockType->downPlane;
                right = left + percent;

                if((GetBlockSettings(x,y-1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y-1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory2.x)
                        BlockColory2.x = BlockColory2.y = BlockColory2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory2;
                lightFactor = BlockColory1 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y-1,z-0.2) || !BlockTransparentOrLightSource(x,y-1,z-0.2))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-0.2) || !BlockTransparentOrLightSource(x+1,y-1,z-0.2) || !BlockTransparentOrLightSource(x+1,y-1,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y-1,z+0.2) || !BlockTransparentOrLightSource(x,y-1,z+0.2))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+0.2) || !BlockTransparentOrLightSource(x-1,y-1,z+0.2) || !BlockTransparentOrLightSource(x-1,y-1,z))
                {
                    light4-=lightFactor;
                }

                MeshChunk->position(x,   y, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1 , y, z+0.2);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y, z+0.2);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //top face
            //y+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y+1,z);
                    Block1 = GetBlock(x,y+1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y+1,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                if((GetBlockSettings(x,y+1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y+1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory1.x)
                        BlockColory1.x = BlockColory1.y = BlockColory1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory1;
                lightFactor = BlockColory2 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x,y+1,z+0.2) || !BlockTransparentOrLightSource(x-1,y+1,z+0.2) || !BlockTransparentOrLightSource(x-1,y+1,z))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z+0.2) || !BlockTransparentOrLightSource(x+1,y+1,z+0.2) || !BlockTransparentOrLightSource(x+1,y+1,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y+1,z-0.2) || !BlockTransparentOrLightSource(x,y+1,z-0.2))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-0.2) || !BlockTransparentOrLightSource(x-1,y+1,z-0.2) || !BlockTransparentOrLightSource(x-1,y+1,z))
                {
                    light4-=lightFactor;
                }

                //down
                left = percent * blockType->upPlane;
                right = left + percent;

                MeshChunk->position(x,   y+1, z+0.2);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y+1, z+0.2);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y+1, z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //z-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z > 0)
                {
                    transparentBlock = BlockTransparent(x,y,z-0.2);
                    Block1 = GetBlock(x,y,z-1);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z > 0)transparentBlock = BlockTransparentOrSpecial(x,y,z-0.2);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z-0.9) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z-1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz1.x)
                        BlockColorz1.x = BlockColorz1.y = BlockColorz1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz1;
                lightFactor = BlockColorz1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z-0.2) || !BlockTransparentOrLightSource(x-1,y,z-0.2) || !BlockTransparentOrLightSource(x-1,y+1,z-0.2))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-0.2) || !BlockTransparentOrLightSource(x+1,y,z-0.2) || !BlockTransparentOrLightSource(x+1,y+1,z-0.2))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z-0.2) || !BlockTransparentOrLightSource(x-1,y,z-0.2) || !BlockTransparentOrLightSource(x-1,y-1,z-0.2))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-0.2) || !BlockTransparentOrLightSource(x+1,y,z-0.2) || !BlockTransparentOrLightSource(x+1,y-1,z-0.2))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+1, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //z+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y,z+0.2);
                    Block1 = GetBlock(x,y,z+0.2);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y,z+1);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate == true)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z+1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z+1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz2.x)
                        BlockColorz2.x = BlockColorz2.y = BlockColorz2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz2;
                lightFactor = BlockColorz2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z+0.2) || !BlockTransparentOrLightSource(x-1,y,z+0.2) || !BlockTransparentOrLightSource(x-1,y+1,z+0.2))
                {
                    light2-=lightFactor;
                }
                if(!BlockTransparentOrLightSource(x,y+1,z+0.2) || !BlockTransparentOrLightSource(x+1,y,z+0.2) || !BlockTransparentOrLightSource(x+1,y+1,z+0.2))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z+0.2) || !BlockTransparentOrLightSource(x-1,y,z+0.2) || !BlockTransparentOrLightSource(x-1,y-1,z+0.2))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+0.2) || !BlockTransparentOrLightSource(x+1,y,z+0.2) || !BlockTransparentOrLightSource(x+1,y-1,z+0.2))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y,   z+0.2);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y,   z+0.2);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+1, y+1, z+0.2);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x,   y+1, z+0.2);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }
        }

        else if(GetBlock(x+1,y,z) == 0 || GetBlock(x-1,y,z) == 0 || GetBlock(x,y,z+1) == 0 || GetBlock(x,y,z-1) == 0)
        {
            //faces
            //x-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x > 0)
                {
                    transparentBlock = BlockTransparent(x-1,y,z);
                    Block1 = GetBlock(x-1,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x > 0)transparentBlock = BlockTransparentOrSpecial(x-1,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x-1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x-1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx1.x)
                        BlockColorx1.x = BlockColorx1.y = BlockColorx1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx1;
                lightFactor = BlockColorx1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x-1,y+1,z) || !BlockTransparentOrLightSource(x-1,y,z+0.2) || !BlockTransparentOrLightSource(x-1,y+1,z+0.2))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-1,y+1,z) || !BlockTransparentOrLightSource(x-1,y,z-0.2) || !BlockTransparentOrLightSource(x-1,y+1,z-0.2))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y,z+0.2) || !BlockTransparentOrLightSource(x-1,y-1,z+0.2))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y,z-0.2) || !BlockTransparentOrLightSource(x-1,y-1,z-0.2))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x, y,   z+0.2);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x, y+1, z+0.2);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //x+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (x < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x+1,y,z);
                    Block1 = GetBlock(x+1,y,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (x < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x+1,y,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x+1, y, z) & 0xF) / 15.0f;
                    if(lightened > BlockColorx2.x)
                        BlockColorx2.x = BlockColorx2.y = BlockColorx2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorx2;
                lightFactor = BlockColorx2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y,z+0.2) || !BlockTransparentOrLightSource(x+1,y+1,z+0.2))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y,z-0.2) || !BlockTransparentOrLightSource(x+1,y+1,z-0.2))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y,z+0.2) || !BlockTransparentOrLightSource(x+1,y-1,z+0.2))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y,z-0.2) || !BlockTransparentOrLightSource(x+1,y-1,z-0.2))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x+1, y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+1, y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+1, y+1, z+0.2);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y,   z+0.2);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //y-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y > 0)
                {
                    transparentBlock = BlockTransparent(x,y-1,z);
                    Block1 = GetBlock(x,y-1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y > 0)transparentBlock = BlockTransparentOrSpecial(x,y-1,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                //up
                left = percent * blockType->downPlane;
                right = left + percent;

                if((GetBlockSettings(x,y-1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y-1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory2.x)
                        BlockColory2.x = BlockColory2.y = BlockColory2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory2;
                lightFactor = BlockColory1 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y-1,z-0.2) || !BlockTransparentOrLightSource(x,y-1,z-0.2))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-0.2) || !BlockTransparentOrLightSource(x+1,y-1,z-0.2) || !BlockTransparentOrLightSource(x+1,y-1,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y-1,z+0.2) || !BlockTransparentOrLightSource(x,y-1,z+0.2))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-1,y-1,z+0.2) || !BlockTransparentOrLightSource(x-1,y-1,z))
                {
                    light4-=lightFactor;
                }

                MeshChunk->position(x,   y, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1 , y, z+0.2);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y, z+0.2);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //top face
            //y+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (y < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y+1,z);
                    Block1 = GetBlock(x,y+1,z);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (y < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y+1,z);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                if((GetBlockSettings(x,y+1,z) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y+1, z) & 0xF) / 15.0f;
                    if(lightened > BlockColory1.x)
                        BlockColory1.x = BlockColory1.y = BlockColory1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColory1;
                lightFactor = BlockColory2 * lightShadowFactor;

                //simple shadows
                if(!BlockTransparentOrLightSource(x,y+1,z+0.2) || !BlockTransparentOrLightSource(x-1,y+1,z+0.2) || !BlockTransparentOrLightSource(x-1,y+1,z))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z+0.2) || !BlockTransparentOrLightSource(x+1,y+1,z+0.2) || !BlockTransparentOrLightSource(x+1,y+1,z))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y+1,z-0.2) || !BlockTransparentOrLightSource(x,y+1,z-0.2))
                {
                    light3-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-0.2) || !BlockTransparentOrLightSource(x-1,y+1,z-0.2) || !BlockTransparentOrLightSource(x-1,y+1,z))
                {
                    light4-=lightFactor;
                }

                //down
                left = percent * blockType->upPlane;
                right = left + percent;

                MeshChunk->position(x,   y+1, z+0.2);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y+1, z+0.2);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y+1, z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light4.x,light4.y,light4.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }

            //z-1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z > 0)
                {
                    transparentBlock = BlockTransparent(x,y,z-0.2);
                    Block1 = GetBlock(x,y,z-1);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z > 0)transparentBlock = BlockTransparentOrSpecial(x,y,z-0.2);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z-0.9) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z-1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz1.x)
                        BlockColorz1.x = BlockColorz1.y = BlockColorz1.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz1;
                lightFactor = BlockColorz1 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z-0.2) || !BlockTransparentOrLightSource(x-1,y,z-0.2) || !BlockTransparentOrLightSource(x-1,y+1,z-0.2))
                {
                    light2-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y+1,z-0.2) || !BlockTransparentOrLightSource(x+1,y,z-0.2) || !BlockTransparentOrLightSource(x+1,y+1,z-0.2))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z-0.2) || !BlockTransparentOrLightSource(x-1,y,z-0.2) || !BlockTransparentOrLightSource(x-1,y-1,z-0.2))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z-0.2) || !BlockTransparentOrLightSource(x+1,y,z-0.2) || !BlockTransparentOrLightSource(x+1,y-1,z-0.2))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y+1, z);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);
                MeshChunk->position(x+1, y+1, z);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x+1, y,   z);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x,   y,   z);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }


            //z+1
            transparentBlock = DefaultBlock;
            canCreate = false;
            if(transparent)
            {
                Block1 = 1;
                if (z < WORLD_SIZE - 1)
                {
                    transparentBlock = BlockTransparent(x,y,z+0.2);
                    Block1 = GetBlock(x,y,z+0.2);
                }

                if (transparentBlock == true || Block1 == 0)
                    canCreate = true;
            }
            else
            {
                if (z < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y,z+1);
                if (transparentBlock == true)
                    canCreate = true;
            }

            if (canCreate == true)
            {
                left = percent * blockType->sidePlane;
                right = left + percent;

                if((GetBlockSettings(x,y,z+1) & OpLighSource) != 0)//block is lightened
                {
                    float lightened = (GetBlockSettings(x, y, z+1) & 0xF) / 15.0f;
                    if(lightened > BlockColorz2.x)
                        BlockColorz2.x = BlockColorz2.y = BlockColorz2.z = lightened;
                }

                light1 = light2 = light3 = light4 = BlockColorz2;
                lightFactor = BlockColorz2 * lightShadowFactor;

                //simple shadows
                //up
                if(!BlockTransparentOrLightSource(x,y+1,z+0.2) || !BlockTransparentOrLightSource(x-1,y,z+0.2) || !BlockTransparentOrLightSource(x-1,y+1,z+0.2))
                {
                    light2-=lightFactor;
                }
                if(!BlockTransparentOrLightSource(x,y+1,z+0.2) || !BlockTransparentOrLightSource(x+1,y,z+0.2) || !BlockTransparentOrLightSource(x+1,y+1,z+0.2))
                {
                    light4-=lightFactor;
                }

                //down
                if(!BlockTransparentOrLightSource(x,y-1,z+0.2) || !BlockTransparentOrLightSource(x-1,y,z+0.2) || !BlockTransparentOrLightSource(x-1,y-1,z+0.2))
                {
                    light1-=lightFactor;
                }

                if(!BlockTransparentOrLightSource(x,y-1,z+0.2) || !BlockTransparentOrLightSource(x+1,y,z+0.2) || !BlockTransparentOrLightSource(x+1,y-1,z+0.2))
                {
                    light3-=lightFactor;
                }

                MeshChunk->position(x,   y,   z+0.2);
                MeshChunk->textureCoord(left, down);
                MeshChunk->colour(light1.x,light1.y,light1.z);
                MeshChunk->position(x+1, y,   z+0.2);
                MeshChunk->textureCoord(right, down);
                MeshChunk->colour(light3.x,light3.y,light3.z);
                MeshChunk->position(x+1, y+1, z+0.2);
                MeshChunk->textureCoord(right, up);
                MeshChunk->colour(light4.x,light4.y,light4.z);
                MeshChunk->position(x,   y+1, z+0.2);
                MeshChunk->textureCoord(left, up);
                MeshChunk->colour(light2.x,light2.y,light2.z);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }
        }
    }

    if(Block == Torch::getID())
    {
        //texture stuff
        BaseBlock *blockType = &blockTypes[Block];
        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent - ((percent / (float)textureChunk) * 6);

        float left = percent * blockType->upPlane;
        float right = left + percent;

        //standing torch
        block_t Block1 = GetBlock(x,y-1,z);

        if(Block1 != 0 && Block1 != Torch::getID())
        {
            left = percent * blockType->sidePlane + ((percent / (float)textureChunk) * 7);
            right = left + ((percent / (float)textureChunk) * 2);

            //x-1
            MeshChunk->info(x + 0.45f,y			,z + 0.45f + 0.1f	,right	, down	,1,1,1);
            MeshChunk->info(x + 0.45f,y + 0.6f	,z + 0.45f + 0.1f	,right	, up	,1,1,1);
            MeshChunk->info(x + 0.45f,y + 0.6f	,z + 0.45f			,left	, up	,1,1,1);
            MeshChunk->info(x + 0.45f,y			,z + 0.45f			,left	, down	,1,1,1);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;

            //x+1
            MeshChunk->info(x + 0.45f + 0.1f,y		,z + 0.45f,right, down,1,1,1);
            MeshChunk->info(x + 0.45f + 0.1f,y+ 0.6f,z + 0.45f,right, up,1,1,1);
            MeshChunk->info(x + 0.45f + 0.1f,y+ 0.6f,z + 0.45f + 0.1f,left, up,1,1,1);
            MeshChunk->info(x + 0.45f + 0.1f,y		,z + 0.45f + 0.1f,left, down,1,1,1);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;

            //z-1
            MeshChunk->info(x + 0.45f		, y + 0.6f	, z + 0.45f,right, up,1,1,1);
            MeshChunk->info(x + 0.45f + 0.1f, y + 0.6f	, z + 0.45f,left, up,1,1,1);
            MeshChunk->info(x + 0.45f + 0.1f, y			, z + 0.45f,left, down,1,1,1);
            MeshChunk->info(x + 0.45f		, y			, z + 0.45f,right, down,1,1,1);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;

            //z+1
            MeshChunk->info(x + 0.45f		, y			, z + 0.45f + 0.1f,left, down,1,1,1);
            MeshChunk->info(x + 0.45f + 0.1f, y			, z + 0.45f + 0.1f,right, down,1,1,1);
            MeshChunk->info(x + 0.45f + 0.1f, y + 0.6f	, z + 0.45f + 0.1f,right, up,1,1,1);
            MeshChunk->info(x + 0.45f		, y + 0.6f	, z + 0.45f + 0.1f,left, up,1,1,1);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;

            //y+1
            {
                down = 1.0f - percent * (blockType->textureRow + 1) + ((percent / (float)textureChunk) * 8);
                up = down + ((percent / (float)textureChunk) * 2);

                left = percent * blockType->sidePlane + ((percent / (float)textureChunk) * 7);
                right = left + ((percent / (float)textureChunk) * 2);

                MeshChunk->info(x + 0.45f		,y + 0.6f,z + 0.45f + 0.1f,left, up,1,1,1);
                MeshChunk->info(x + 0.45f + 0.1f,y + 0.6f,z + 0.45f + 0.1f,right, up,1,1,1);
                MeshChunk->info(x + 0.45f + 0.1f,y + 0.6f,z + 0.45f,right, down,1,1,1);
                MeshChunk->info(x + 0.45f		,y + 0.6f,z + 0.45f,left, down,1,1,1);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }
        }
        else
        {
            Vector3 posLeft,posRight;
            Vector3 posUpLeft,posUpRight;
            Vector3 posUpLeft2,posUpRight2;
            bool canPlaseTorch = false;

            if(GetBlock(x-1,y,z) != 0 && GetBlock(x-1,y,z) != Torch::getID())
            {
                posLeft = Vector3(x,y,z+0.55f);
                posRight = Vector3(x,y,z+0.45f);
                posUpLeft = Vector3(x+0.45,y,z+0.55f);
                posUpRight = Vector3(x+0.45,y,z+0.45f);
                posUpLeft2 = Vector3(x+0.55,y,z+0.55f);
                posUpRight2 = Vector3(x+0.55,y,z+0.45f);

                canPlaseTorch = true;
            }
            else if(GetBlock(x+1,y,z) != 0 && GetBlock(x+1,y,z) != Torch::getID())
            {
                posRight = Vector3(x+1,y,z+0.55f);
                posLeft = Vector3(x+1,y,z+0.45f);
                posUpRight2 = Vector3(x+0.45,y,z+0.55f);
                posUpLeft2 = Vector3(x+0.45,y,z+0.45f);
                posUpRight = Vector3(x+0.55,y,z+0.55f);
                posUpLeft = Vector3(x+0.55,y,z+0.45f);

                canPlaseTorch = true;
            }
            else if(GetBlock(x,y,z-1) != 0 && GetBlock(x,y,z-1) != Torch::getID())
            {
                posLeft = Vector3(x+0.45f,y,z);
                posRight = Vector3(x+0.55f,y,z);
                posUpLeft = Vector3(x+0.45f,y,z+0.45f);
                posUpRight = Vector3(x+0.55f,y,z+0.45f);
                posUpLeft2 = Vector3(x+0.45f,y,z+0.55f);
                posUpRight2 = Vector3(x+0.55,y,z+0.55f);

                canPlaseTorch = true;
            }
            else if(GetBlock(x,y,z+1) != 0 && GetBlock(x,y,z+1) != Torch::getID())
            {
                posRight = Vector3(x+0.45f,y,z+1);
                posLeft = Vector3(x+0.55f,y,z+1);
                posUpRight2 = Vector3(x+0.45f,y,z+0.45f);
                posUpLeft2 = Vector3(x+0.55f,y,z+0.45f);
                posUpRight = Vector3(x+0.45f,y,z+0.55f);
                posUpLeft = Vector3(x+0.55,y,z+0.55f);

                canPlaseTorch = true;
            }

            if(canPlaseTorch)
            {
                left = percent * blockType->sidePlane + ((percent / (float)textureChunk) * 7);
                right = left + ((percent / (float)textureChunk) * 2);

                //x-1
                MeshChunk->info( posLeft.x, y+0.1f, posLeft.z, right, down, 1, 1, 1);
                MeshChunk->info( posUpLeft.x,y + 0.6f ,posUpLeft.z	,right	, up	,1,1,1);
                MeshChunk->info( posUpRight.x,y + 0.6f,posUpRight.z,left	, up	,1,1,1);
                MeshChunk->info( posRight.x, y+0.1f, posRight.z,left	, down	,1,1,1);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;

                //x+1
                MeshChunk->info(posRight.x,y		,posRight.z,right, down,1,1,1);
                MeshChunk->info(posUpRight2.x,y + 0.6f,posUpRight2.z,right, up,1,1,1);
                MeshChunk->info(posUpLeft2.x,y + 0.6f,posUpLeft2.z,left, up,1,1,1);
                MeshChunk->info(posLeft.x, y, posLeft.z,left, down,1,1,1);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;

                //z-1
                MeshChunk->info(posUpRight.x,y + 0.6f,posUpRight.z,right, up,1,1,1);
                MeshChunk->info(posUpRight2.x,y + 0.6f,posUpRight2.z,left, up,1,1,1);
                MeshChunk->info(posRight.x,y,posRight.z,left, down,1,1,1);
                MeshChunk->info(posRight.x,y+0.1f,posRight.z,right, down,1,1,1);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;

                //z+1
                MeshChunk->info(posLeft.x, y+0.1f, posLeft.z,left, down,1,1,1);
                MeshChunk->info(posLeft.x, y, posLeft.z,right, down,1,1,1);
                MeshChunk->info(posUpLeft2.x, y+0.6, posUpLeft2.z,right, up,1,1,1);
                MeshChunk->info(posUpLeft.x, y+0.6, posUpLeft.z,left, up,1,1,1);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;

                //y+1
                down = 1.0f - percent * (blockType->textureRow + 1) + ((percent / (float)textureChunk) * 8);
                up = down + ((percent / (float)textureChunk) * 2);

                left = percent * blockType->sidePlane + ((percent / (float)textureChunk) * 7);
                right = left + ((percent / (float)textureChunk) * 2);

                MeshChunk->info(x + 0.45f		,y + 0.6f,z + 0.45f + 0.1f,left, up,1,1,1);
                MeshChunk->info(x + 0.45f + 0.1f,y + 0.6f,z + 0.45f + 0.1f,right, up,1,1,1);
                MeshChunk->info(x + 0.45f + 0.1f,y + 0.6f,z + 0.45f,right, down,1,1,1);
                MeshChunk->info(x + 0.45f		,y + 0.6f,z + 0.45f,left, down,1,1,1);

                MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
                MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

                iVertex += 4;
            }
        }
    }

    if(Block == Fence::getID() || Block == NetherFence::getID())
    {
        Vector3 light1,light2,light3,light4;
        float BaseLight = 1.0f;

        Vector3 BlockColory1;    //Top face
        Vector3 BlockColory2;    //Bottom face
        Vector3 BlockColorx1;    //Sunset face
        Vector3 BlockColorx2;    //Sunrise face
        Vector3 BlockColorz1;     //Front/back faces
        Vector3 BlockColorz2;     //Front/back faces

        //texture stuff
        BaseBlock *blockType = &blockTypes[Block];

        float down = 1.0f - percent * (blockType->textureRow + 1);
        float up = down + percent;

        float left = percent * blockType->upPlane;
        float right = left + percent;


        if(worldDayTime >= 21 || worldDayTime <= 4)//night
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                BaseLight  = (float)(GetBlockSettings(x, y, z) & 0xF)/16.0f; // 255.0f;  //For the two x faces

                BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                BlockColorz1  = BlockColorz2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
            }
            else //normal light
            {
                //light
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;  //For the two x faces
                //float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
                //float BlockLight2 = BlockLight * 0.8f;		//For the two y faces

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }
        else //day
        {
            if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
            {
                //int normal = GetBlockLight(x, y, z);
                //int lightened = (GetBlockSettings(x, y, z) & 0xF) * 16;

                float normal = lightColor.x * (factor1 * (GetBlockLight(x, y, z) / 255.0f)) + ambientColor.x;
                float lightened = (GetBlockSettings(x, y, z) & 0xF) / 15.0f;

                if(lightened > normal)
                {
                    BaseLight = lightened; // 255.0f;
                    BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                    BlockColorz2 = BlockColorz1  = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                    BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
                }
                else
                {
                    BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                    BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                    BlockColory1.saturate();
                    BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                    BlockColory2.saturate();
                    BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                    BlockColorz1.saturate();
                    BlockColorz1 *= 0.80f;
                    BlockColorz2 = BlockColorz1;

                    BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx1.saturate();
                    BlockColorx1 *= 0.95f;

                    BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                    BlockColorx2.saturate();
                    BlockColorx2 *= 0.95f;
                }

            }
            else
            {
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }
        }

        left = percent * blockType->sidePlane + ((percent / (float)textureChunk) * 7);
        right = left + ((percent / (float)textureChunk) * 2);

        //x-1
        MeshChunk->info(x + 0.4f,y			,z + 0.4f + 0.2f	,right	, down	,1,1,1);
        MeshChunk->info(x + 0.4f,y + 1.0f	,z + 0.4f + 0.2f	,right	, up	,1,1,1);
        MeshChunk->info(x + 0.4f,y + 1.0f	,z + 0.4f			,left	, up	,1,1,1);
        MeshChunk->info(x + 0.4f,y			,z + 0.4f			,left	, down	,1,1,1);

        MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
        MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

        iVertex += 4;

        //x+1
        MeshChunk->info(x + 0.4f + 0.2f,y		,z + 0.4f,right, down,1,1,1);
        MeshChunk->info(x + 0.4f + 0.2f,y+ 1.0f,z + 0.4f,right, up,1,1,1);
        MeshChunk->info(x + 0.4f + 0.2f,y+ 1.0f,z + 0.4f + 0.2f,left, up,1,1,1);
        MeshChunk->info(x + 0.4f + 0.2f,y		,z + 0.4f + 0.2f,left, down,1,1,1);

        MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
        MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

        iVertex += 4;

        //z-1
        MeshChunk->info(x + 0.4f		, y + 1.0f	, z + 0.4f,right, up,1,1,1);
        MeshChunk->info(x + 0.4f + 0.2f, y + 1.0f	, z + 0.4f,left, up,1,1,1);
        MeshChunk->info(x + 0.4f + 0.2f, y			, z + 0.4f,left, down,1,1,1);
        MeshChunk->info(x + 0.4f		, y			, z + 0.4f,right, down,1,1,1);

        MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
        MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

        iVertex += 4;

        //z+1
        MeshChunk->info(x + 0.4f		, y			, z + 0.4f + 0.2f,left, down,1,1,1);
        MeshChunk->info(x + 0.4f + 0.2f, y			, z + 0.4f + 0.2f,right, down,1,1,1);
        MeshChunk->info(x + 0.4f + 0.2f, y + 1.0f	, z + 0.4f + 0.2f,right, up,1,1,1);
        MeshChunk->info(x + 0.4f		, y + 1.0f	, z + 0.4f + 0.2f,left, up,1,1,1);

        MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
        MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

        iVertex += 4;

        //y+1
        {
            down = 1.0f - percent * (blockType->textureRow + 1) + ((percent / (float)textureChunk) * 8);
            up = down + ((percent / (float)textureChunk) * 2);

            left = percent * blockType->sidePlane + ((percent / (float)textureChunk) * 7);
            right = left + ((percent / (float)textureChunk) * 2);

            MeshChunk->info(x + 0.4f		,y + 1.0f,z + 0.4f + 0.2f,left, up,1,1,1);
            MeshChunk->info(x + 0.4f + 0.2f,y + 1.0f,z + 0.4f + 0.2f,right, up,1,1,1);
            MeshChunk->info(x + 0.4f + 0.2f,y + 1.0f,z + 0.4f,right, down,1,1,1);
            MeshChunk->info(x + 0.4f		,y + 1.0f,z + 0.4f,left, down,1,1,1);

            MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
            MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

            iVertex += 4;
        }
    }
}

void CraftWorld::GetNormalBlock(int x,int y, int z,int &iVertex,SimpleMeshChunk* MeshChunk,block_t Block,bool transparent)
{
    /* Only create visible faces of each chunk */
    bool DefaultBlock = false;
    bool transparentBlock;

    block_t Block1 = 0;

    Vector3 light1,light2,light3,light4;
    float BaseLight = 1.0f;

    Vector3 BlockColory1;    //Top face
    Vector3 BlockColory2;    //Bottom face
    Vector3 BlockColorx1;    //Sunset face
    Vector3 BlockColorx2;    //Sunrise face
    Vector3 BlockColorz1;     //Front/back faces
    Vector3 BlockColorz2;     //Front/back faces

    //texture stuff
    BaseBlock *blockType = &blockTypes[Block];

    float down = 1.0f - percent * (blockType->textureRow + 1);
    float up = down + percent;

    float left = percent * blockType->upPlane;
    float right = left + percent;

    bool canCreate = false;

    //lightened
    //if time is between 21-4 use settings table for lightening
    //if time is between 5-20 use normal light table but compare it with settings table
    //	if setting is brighter then use it
    if(worldDayTime >= 21 || worldDayTime <= 4)//night
    {
        if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
        {
            BaseLight  = (float)(GetBlockSettings(x, y, z) & 0xF)/16.0f; // 255.0f;  //For the two x faces

            BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
            BlockColorz1  = BlockColorz2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
            BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
        }
        else //normal light
        {
            //light
            BaseLight  = GetBlockLight(x, y, z) / 255.0f;  //For the two x faces
            //float BlockLight1 = BlockLight * 0.9f;		//For the two z faces
            //float BlockLight2 = BlockLight * 0.8f;		//For the two y faces

            BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
            BlockColory1.saturate();
            BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
            BlockColory2.saturate();
            BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
            BlockColorz1.saturate();
            BlockColorz1 *= 0.80f;
            BlockColorz2 = BlockColorz1;

            BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
            BlockColorx1.saturate();
            BlockColorx1 *= 0.95f;

            BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
            BlockColorx2.saturate();
            BlockColorx2 *= 0.95f;
        }
    }
    else //day
    {
        if((GetBlockSettings(x,y,z) & OpLighSource) != 0)//block is lightened
        {
            //int normal = GetBlockLight(x, y, z);
            //int lightened = (GetBlockSettings(x, y, z) & 0xF) * 16;

            float normal = lightColor.x * (factor1 * (GetBlockLight(x, y, z) / 255.0f)) + ambientColor.x;
            float lightened = (GetBlockSettings(x, y, z) & 0xF) / 15.0f;

            if(lightened > normal)
            {
                BaseLight = lightened; // 255.0f;
                BlockColorx1 = BlockColorx2 = Vector3(BaseLight,BaseLight,BaseLight);
                BlockColorz2 = BlockColorz1  = Vector3(BaseLight,BaseLight,BaseLight) * 0.9f;
                BlockColory1 = BlockColory2 = Vector3(BaseLight,BaseLight,BaseLight) * 0.8f;
            }
            else
            {
                BaseLight  = GetBlockLight(x, y, z) / 255.0f;

                BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
                BlockColory1.saturate();
                BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
                BlockColory2.saturate();
                BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
                BlockColorz1.saturate();
                BlockColorz1 *= 0.80f;
                BlockColorz2 = BlockColorz1;

                BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
                BlockColorx1.saturate();
                BlockColorx1 *= 0.95f;

                BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
                BlockColorx2.saturate();
                BlockColorx2 *= 0.95f;
            }

        }
        else
        {
            BaseLight  = GetBlockLight(x, y, z) / 255.0f;

            BlockColory1 = lightColor * (factor1 * BaseLight) + ambientColor;
            BlockColory1.saturate();
            BlockColory2 = lightColor * (factor1 / 2.0f * BaseLight) + ambientColor;
            BlockColory2.saturate();
            BlockColorz1  = lightColor * (factor1 * 0.70f * BaseLight) + ambientColor;
            BlockColorz1.saturate();
            BlockColorz1 *= 0.80f;
            BlockColorz2 = BlockColorz1;

            BlockColorx1 = lightColor * (factor2 * 0.80f * BaseLight) + ambientColor;
            BlockColorx1.saturate();
            BlockColorx1 *= 0.95f;

            BlockColorx2 = lightColor * (factor3 * 0.80f * BaseLight) + ambientColor;
            BlockColorx2.saturate();
            BlockColorx2 *= 0.95f;
        }
    }

    //faces
    //x-1
    transparentBlock = DefaultBlock;
    canCreate = false;
    if(transparent)
    {
        Block1 = 1;
        if (x > 0)
        {
            transparentBlock = BlockTransparent(x-1,y,z);
            Block1 = GetBlock(x-1,y,z);
        }

        if (transparentBlock == false || Block1 == 0)
            canCreate = true;
    }
    else
    {
        if (x > 0)transparentBlock = BlockTransparentOrSpecial(x-1,y,z);
        if (transparentBlock == true)
            canCreate = true;
    }

    if (canCreate)
    {
        left = percent * blockType->sidePlane;
        right = left + percent;

        if((GetBlockSettings(x-1,y,z) & OpLighSource) != 0)//block is lightened
        {
            float lightened = (GetBlockSettings(x-1, y, z) & 0xF) / 15.0f;
            if(lightened > BlockColorx1.x)
                BlockColorx1.x = BlockColorx1.y = BlockColorx1.z = lightened;
        }

        light1 = light2 = light3 = light4 = BlockColorx1;
        lightFactor = BlockColorx1 * lightShadowFactor;

        //simple shadows
        //up
        if(!BlockTransparentOrLightSource(x-1,y+1,z) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y+1,z+1))
        {
            light2-=lightFactor;
        }

        if(!BlockTransparentOrLightSource(x-1,y+1,z) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y+1,z-1))
        {
            light4-=lightFactor;
        }

        //down
        if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y-1,z+1))
        {
            light1-=lightFactor;
        }

        if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y-1,z-1))
        {
            light3-=lightFactor;
        }

        MeshChunk->position(x, y,   z+1);
        MeshChunk->textureCoord(right, down);
        MeshChunk->colour(light1.x,light1.y,light1.z);
        MeshChunk->position(x, y+1, z+1);
        MeshChunk->textureCoord(right, up);
        MeshChunk->colour(light2.x,light2.y,light2.z);
        MeshChunk->position(x, y+1, z);
        MeshChunk->textureCoord(left, up);
        MeshChunk->colour(light4.x,light4.y,light4.z);
        MeshChunk->position(x, y,   z);
        MeshChunk->textureCoord(left, down);
        MeshChunk->colour(light3.x,light3.y,light3.z);

        MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
        MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

        iVertex += 4;
    }


    //x+1
    transparentBlock = DefaultBlock;
    canCreate = false;
    if(transparent)
    {
        Block1 = 1;
        if (x < WORLD_SIZE - 1)
        {
            transparentBlock = BlockTransparent(x+1,y,z);
            Block1 = GetBlock(x+1,y,z);
        }

        if (transparentBlock == false || Block1 == 0)
            canCreate = true;
    }
    else
    {
        if (x < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x+1,y,z);
        if (transparentBlock == true)
            canCreate = true;
    }

    if (canCreate)
    {
        left = percent * blockType->sidePlane;
        right = left + percent;

        if((GetBlockSettings(x+1,y,z) & OpLighSource) != 0)//block is lightened
        {
            float lightened = (GetBlockSettings(x+1, y, z) & 0xF) / 15.0f;
            if(lightened > BlockColorx2.x)
                BlockColorx2.x = BlockColorx2.y = BlockColorx2.z = lightened;
        }

        light1 = light2 = light3 = light4 = BlockColorx2;
        lightFactor = BlockColorx2 * lightShadowFactor;

        //simple shadows
        //up
        if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y+1,z+1))
        {
            light2-=lightFactor;
        }

        if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y+1,z-1))
        {
            light4-=lightFactor;
        }

        //down
        if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y-1,z+1))
        {
            light1-=lightFactor;
        }

        if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y-1,z-1))
        {
            light3-=lightFactor;
        }

        MeshChunk->position(x+1, y,   z);
        MeshChunk->textureCoord(right, down);
        MeshChunk->colour(light3.x,light3.y,light3.z);
        MeshChunk->position(x+1, y+1, z);
        MeshChunk->textureCoord(right, up);
        MeshChunk->colour(light4.x,light4.y,light4.z);
        MeshChunk->position(x+1, y+1, z+1);
        MeshChunk->textureCoord(left, up);
        MeshChunk->colour(light2.x,light2.y,light2.z);
        MeshChunk->position(x+1, y,   z+1);
        MeshChunk->textureCoord(left, down);
        MeshChunk->colour(light1.x,light1.y,light1.z);

        MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
        MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

        iVertex += 4;
    }

    //y-1
    transparentBlock = DefaultBlock;
    canCreate = false;
    if(transparent)
    {
        Block1 = 1;
        if (y > 0)
        {
            transparentBlock = BlockTransparent(x,y-1,z);
            Block1 = GetBlock(x,y-1,z);
        }

        if (transparentBlock == false || Block1 == 0)
            canCreate = true;
    }
    else
    {
        if (y > 0)transparentBlock = BlockTransparentOrSpecial(x,y-1,z);
        if (transparentBlock == true)
            canCreate = true;
    }

    if (canCreate)
    {
        //up
        left = percent * blockType->downPlane;
        right = left + percent;

        if((GetBlockSettings(x,y-1,z) & OpLighSource) != 0)//block is lightened
        {
            float lightened = (GetBlockSettings(x, y-1, z) & 0xF) / 15.0f;
            if(lightened > BlockColory2.x)
                BlockColory2.x = BlockColory2.y = BlockColory2.z = lightened;
        }

        light1 = light2 = light3 = light4 = BlockColory2;
        lightFactor = BlockColory1 * lightShadowFactor;

        //simple shadows
        if(!BlockTransparentOrLightSource(x-1,y-1,z) || !BlockTransparentOrLightSource(x-1,y-1,z-1) || !BlockTransparentOrLightSource(x,y-1,z-1))
        {
            light1-=lightFactor;
        }

        if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x+1,y-1,z-1) || !BlockTransparentOrLightSource(x+1,y-1,z))
        {
            light2-=lightFactor;
        }

        if(!BlockTransparentOrLightSource(x+1,y-1,z) || !BlockTransparentOrLightSource(x+1,y-1,z+1) || !BlockTransparentOrLightSource(x,y-1,z+1))
        {
            light3-=lightFactor;
        }

        if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-1,y-1,z+1) || !BlockTransparentOrLightSource(x-1,y-1,z))
        {
            light4-=lightFactor;
        }

        MeshChunk->position(x,   y, z);
        MeshChunk->textureCoord(left, up);
        MeshChunk->colour(light1.x,light1.y,light1.z);
        MeshChunk->position(x+1, y, z);
        MeshChunk->textureCoord(right, up);
        MeshChunk->colour(light2.x,light2.y,light2.z);
        MeshChunk->position(x+1, y, z+1);
        MeshChunk->textureCoord(right, down);
        MeshChunk->colour(light3.x,light3.y,light3.z);
        MeshChunk->position(x,   y, z+1);
        MeshChunk->textureCoord(left, down);
        MeshChunk->colour(light4.x,light4.y,light4.z);

        MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
        MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

        iVertex += 4;
    }


    //top face
    //y+1
    transparentBlock = DefaultBlock;
    canCreate = false;
    if(transparent)
    {
        Block1 = 1;
        if (y < WORLD_SIZE - 1)
        {
            transparentBlock = BlockTransparent(x,y+1,z);
            Block1 = GetBlock(x,y+1,z);
        }

        if (transparentBlock == false || Block1 == 0)
            canCreate = true;
    }
    else
    {
        if (y < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y+1,z);
        if (transparentBlock == true)
            canCreate = true;
    }

    if (canCreate)
    {
        if((GetBlockSettings(x,y+1,z) & OpLighSource) != 0)//block is lightened
        {
            float lightened = (GetBlockSettings(x, y+1, z) & 0xF) / 15.0f;
            if(lightened > BlockColory1.x)
                BlockColory1.x = BlockColory1.y = BlockColory1.z = lightened;
        }

        light1 = light2 = light3 = light4 = BlockColory1;
        lightFactor = BlockColory2 * lightShadowFactor;

        //simple shadows
        if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x-1,y+1,z+1) || !BlockTransparentOrLightSource(x-1,y+1,z))
        {
            light1-=lightFactor;
        }

        if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x+1,y+1,z+1) || !BlockTransparentOrLightSource(x+1,y+1,z))
        {
            light2-=lightFactor;
        }

        if(!BlockTransparentOrLightSource(x+1,y+1,z) || !BlockTransparentOrLightSource(x+1,y+1,z-1) || !BlockTransparentOrLightSource(x,y+1,z-1))
        {
            light3-=lightFactor;
        }

        if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x-1,y+1,z-1) || !BlockTransparentOrLightSource(x-1,y+1,z))
        {
            light4-=lightFactor;
        }

        //down
        left = percent * blockType->upPlane;
        right = left + percent;

        MeshChunk->position(x,   y+1, z+1);
        MeshChunk->textureCoord(left, up);
        MeshChunk->colour(light1.x,light1.y,light1.z);
        MeshChunk->position(x+1, y+1, z+1);
        MeshChunk->textureCoord(right, up);
        MeshChunk->colour(light2.x,light2.y,light2.z);
        MeshChunk->position(x+1, y+1, z);
        MeshChunk->textureCoord(right, down);
        MeshChunk->colour(light3.x,light3.y,light3.z);
        MeshChunk->position(x,   y+1, z);
        MeshChunk->textureCoord(left, down);
        MeshChunk->colour(light4.x,light4.y,light4.z);

        MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
        MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

        iVertex += 4;
    }

    //z-1
    transparentBlock = DefaultBlock;
    canCreate = false;
    if(transparent)
    {
        Block1 = 1;
        if (z > 0)
        {
            transparentBlock = BlockTransparent(x,y,z-1);
            Block1 = GetBlock(x,y,z-1);
        }

        if (transparentBlock == false || Block1 == 0)
            canCreate = true;
    }
    else
    {
        if (z > 0)transparentBlock = BlockTransparentOrSpecial(x,y,z-1);
        if (transparentBlock == true)
            canCreate = true;
    }

    if (canCreate)
    {
        left = percent * blockType->sidePlane;
        right = left + percent;

        if((GetBlockSettings(x,y,z-1) & OpLighSource) != 0)//block is lightened
        {
            float lightened = (GetBlockSettings(x, y, z-1) & 0xF) / 15.0f;
            if(lightened > BlockColorz1.x)
                BlockColorz1.x = BlockColorz1.y = BlockColorz1.z = lightened;
        }

        light1 = light2 = light3 = light4 = BlockColorz1;
        lightFactor = BlockColorz1 * lightShadowFactor;

        //simple shadows
        //up
        if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y+1,z-1))
        {
            light2-=lightFactor;
        }

        if(!BlockTransparentOrLightSource(x,y+1,z-1) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y+1,z-1))
        {
            light4-=lightFactor;
        }

        //down
        if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x-1,y,z-1) || !BlockTransparentOrLightSource(x-1,y-1,z-1))
        {
            light1-=lightFactor;
        }

        if(!BlockTransparentOrLightSource(x,y-1,z-1) || !BlockTransparentOrLightSource(x+1,y,z-1) || !BlockTransparentOrLightSource(x+1,y-1,z-1))
        {
            light3-=lightFactor;
        }

        MeshChunk->position(x,   y+1, z);
        MeshChunk->textureCoord(right, up);
        MeshChunk->colour(light2.x,light2.y,light2.z);
        MeshChunk->position(x+1, y+1, z);
        MeshChunk->textureCoord(left, up);
        MeshChunk->colour(light4.x,light4.y,light4.z);
        MeshChunk->position(x+1, y,   z);
        MeshChunk->textureCoord(left, down);
        MeshChunk->colour(light3.x,light3.y,light3.z);
        MeshChunk->position(x,   y,   z);
        MeshChunk->textureCoord(right, down);
        MeshChunk->colour(light1.x,light1.y,light1.z);

        MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
        MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

        iVertex += 4;
    }


    //z+1
    transparentBlock = DefaultBlock;
    canCreate = false;
    if(transparent)
    {
        Block1 = 1;
        if (z < WORLD_SIZE - 1)
        {
            transparentBlock = BlockTransparent(x,y,z+1);
            Block1 = GetBlock(x,y,z+1);
        }

        if (transparentBlock == false || Block1 == 0)
            canCreate = true;
    }
    else
    {
        if (z < WORLD_SIZE - 1)transparentBlock = BlockTransparentOrSpecial(x,y,z+1);
        if (transparentBlock == true)
            canCreate = true;
    }

    if (canCreate == true)
    {
        left = percent * blockType->sidePlane;
        right = left + percent;

        if((GetBlockSettings(x,y,z+1) & OpLighSource) != 0)//block is lightened
        {
            float lightened = (GetBlockSettings(x, y, z+1) & 0xF) / 15.0f;
            if(lightened > BlockColorz2.x)
                BlockColorz2.x = BlockColorz2.y = BlockColorz2.z = lightened;
        }

        light1 = light2 = light3 = light4 = BlockColorz2;
        lightFactor = BlockColorz2 * lightShadowFactor;

        //simple shadows
        //up
        if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y+1,z+1))
        {
            light2-=lightFactor;
        }
        if(!BlockTransparentOrLightSource(x,y+1,z+1) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y+1,z+1))
        {
            light4-=lightFactor;
        }

        //down
        if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x-1,y,z+1) || !BlockTransparentOrLightSource(x-1,y-1,z+1))
        {
            light1-=lightFactor;
        }

        if(!BlockTransparentOrLightSource(x,y-1,z+1) || !BlockTransparentOrLightSource(x+1,y,z+1) || !BlockTransparentOrLightSource(x+1,y-1,z+1))
        {
            light3-=lightFactor;
        }

        MeshChunk->position(x,   y,   z+1);
        MeshChunk->textureCoord(left, down);
        MeshChunk->colour(light1.x,light1.y,light1.z);
        MeshChunk->position(x+1, y,   z+1);
        MeshChunk->textureCoord(right, down);
        MeshChunk->colour(light3.x,light3.y,light3.z);
        MeshChunk->position(x+1, y+1, z+1);
        MeshChunk->textureCoord(right, up);
        MeshChunk->colour(light4.x,light4.y,light4.z);
        MeshChunk->position(x,   y+1, z+1);
        MeshChunk->textureCoord(left, up);
        MeshChunk->colour(light2.x,light2.y,light2.z);

        MeshChunk->triangle(iVertex, iVertex+1, iVertex+2);
        MeshChunk->triangle(iVertex+2, iVertex+3, iVertex);

        iVertex += 4;
    }
}

void CraftWorld::UpdateWorldLightForChunk(int chunkID)
{
    int StartZ = mChunks[chunkID]->chunkStartZ;
    int StartY = mChunks[chunkID]->chunkStartY;
    int StartX = mChunks[chunkID]->chunkStartX;

    for (int z = StartZ; z < CHUNK_SIZE + StartZ; ++z)
    {
        for (int y = StartY; y < CHUNK_SIZE + StartY; ++y)
        {
            for (int x = StartX; x < CHUNK_SIZE + StartX; ++x)
            {
                block_t Block = GetBlock(x,y,z);
                if(BlockTransparent(x,y,z) == true)continue;//if block is transparent don't continue

                //light source?
                if(LightSourceBlock(Block))
                    SetLigtSourcePosition(x,y,z,Block);
            }
        }
    }
}

void CraftWorld::UpdateLightAreaIn(Vector3 pos)
{
    int biggestLight = 14;

    int startx = pos.x - biggestLight > 0 ? pos.x - biggestLight : 0;
    int starty = pos.y - biggestLight > 0 ? pos.y - biggestLight : 0;
    int startz = pos.z - biggestLight > 0 ? pos.z - biggestLight : 0;

    int endx = pos.x + biggestLight < WORLD_SIZE ? pos.x + biggestLight : WORLD_SIZE;
    int endy = pos.y + biggestLight < WORLD_SIZE ? pos.y + biggestLight : WORLD_SIZE;
    int endz = pos.z + biggestLight < WORLD_SIZE ? pos.z + biggestLight : WORLD_SIZE;

    for (int z = startz; z < endz; ++z)
    {
        for (int y = starty; y < endy; ++y)
        {
            for (int x = startx; x < endx; ++x)
            {
                block_t Block = GetBlock(x,y,z);
                if(LightSourceBlock(Block))
                {
                    RemoveLigtSourceAtPosition(x,y,z,Block);
                    SetLigtSourcePosition(x,y,z,Block);
                    AddChunkToUpdate(x,y,z);
                }
            }
        }
    }
}

void CraftWorld::AddChunkToUpdate(const int x, const int y, const int z)
{
    int chunkTarget = getChunkId(Vector3(x,y,z));
    if(chunkTarget != -1)
        mChunks[chunkTarget]->needUpdate = true;
}

void CraftWorld::RebuildChunksLight(Vector3 pos,int currentChunk,int blockID)
{
    if(blockID == LampOn::getID() || blockID == Furnace2::getID() || blockID == Lava::getID()|| blockID == JackOLantern::getID() || blockID == Torch::getID() || blockID == GlowStone::getID())
    {
        BoundingBox lBox = BoundingBox(Vector3(pos.x - 14,pos.y - 14,pos.z - 14),Vector3(pos.x + 14,pos.y + 14,pos.z + 14));
        for(unsigned int i = 0; i < mChunks.size(); i++)
        {
            if(lBox.intersect(mChunks[i]->bBox))
            {
                rebuildChunk(i);
                rebuildTransparentChunk(i);
            }
        }
    }
}

void CraftWorld::rebuildNearestChunks(int id,Vector3 pos)
{
    Vector3 test = mChunks[id]->bBox.onBorder(pos);
    Vector3 temp = pos;
    int chunkNumber = -1;

    if(test.x != 0)
    {
        temp.x +=test.x;

        chunkNumber = getChunkId(temp);
        if(chunkNumber != -1)
        {
            rebuildChunk(chunkNumber);
            rebuildTransparentChunk(chunkNumber);
        }


        //now check for other with this... //needed by shadows
        if(test.y != 0)
        {
            temp.y +=test.y;
            chunkNumber = getChunkId(temp);
            if(chunkNumber != -1)
            {
                rebuildChunk(chunkNumber);
                rebuildTransparentChunk(chunkNumber);
            }
        }

        if(test.z != 0)
        {
            temp.z +=test.z;
            chunkNumber = getChunkId(temp);
            if(chunkNumber != -1)
            {
                rebuildChunk(chunkNumber);
                rebuildTransparentChunk(chunkNumber);
            }
        }
    }


    if(test.y != 0)
    {
        temp = pos;
        temp.y +=test.y;

        chunkNumber = getChunkId(temp);
        if(chunkNumber != -1)
        {
            rebuildChunk(chunkNumber);
            rebuildTransparentChunk(chunkNumber);
        }

        if(test.z != 0)
        {
            temp.z +=test.z;
            chunkNumber = getChunkId(temp);
            if(chunkNumber != -1)
            {
                rebuildChunk(chunkNumber);
                rebuildTransparentChunk(chunkNumber);
            }
        }
    }

    if(test.z != 0)
    {
        temp = pos;
        temp.z +=test.z;

        chunkNumber = getChunkId(temp);
        if(chunkNumber != -1)
        {
            rebuildChunk(chunkNumber);
            rebuildTransparentChunk(chunkNumber);
        }

        if(test.x != 0)
        {
            temp.x +=test.x;

            chunkNumber = getChunkId(temp);
            if(chunkNumber != -1)
            {
                rebuildChunk(chunkNumber);
                rebuildTransparentChunk(chunkNumber);
            }
        }
    }

}

void CraftWorld::createWorldChunkss()
{
    createdChunksCount = 0;

    for (int z = 0; z < WORLD_SIZE; z += CHUNK_SIZE)
    {
        for (int y = 0; y < WORLD_SIZE; y += CHUNK_SIZE)
        {
            for (int x = 0; x < WORLD_SIZE; x += CHUNK_SIZE)
            {
                createChunks(x,y,z);
                createTransparentChunks(x,y,z);
            }
        }
    }
}

void CraftWorld::SetAllChunksToUpdate()
{
    for(unsigned int i = 0; i < mChunks.size(); i++)
    {
        mChunks[i]->needUpdate = true;
    }

    for(unsigned int i = 0; i < mTransparentChunks.size(); i++)
    {
        mTransparentChunks[i]->needUpdate = true;
    }
}

void CraftWorld::drawCubes(int i)
{
    sceGuColor(0xFFFFFFFF);
    sceGuEnable(GU_TEXTURE_2D);
    if(blockTypes[i].transparent)
        sceGuEnable(GU_BLEND);
    sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF |GU_COLOR_8888| GU_VERTEX_32BITF | GU_TRANSFORM_3D, 36, 0, blockTypes[i].vertices);
    if(blockTypes[i].transparent)
        sceGuDisable(GU_BLEND);
    sceGuDisable(GU_TEXTURE_2D);
}

int compareTarnsSort (const void * a, const void * b)
{
    TransparentOrder *ia = (TransparentOrder *)a;
    TransparentOrder *ib = (TransparentOrder *)b;
    return (int)( ia->distance - ib->distance );
}

void CraftWorld::drawWorld(Frustum &camFrustum,bool camUpdate)
{
    drawnTriangles = 0;

    //normal not transparend chunks
    sceGuColor(0xFFFFFFFF);
    sceGuEnable(GU_TEXTURE_2D);
    for(unsigned int i = 0; i < mChunks.size(); i++)
    {
        if(mChunks[i]->trienglesCount > 0 || !mChunks[i]->created)
        {
            if(playerZoneBB.intersect(mChunks[i]->bBox))
            {
                if(camFrustum.BoxInFrustum(mChunks[i]->bBox) == Frustum::Intersects)
                {
                    //check if wee need to build vertices of this chunk
                    if((!mChunks[i]->created || mChunks[i]->needUpdate) && chunksCreatedInFrameCount == 0)
                    {
                        rebuildChunk(i);
                        chunksCreatedInFrameCount++;
                    }

                    mChunks[i]->drawChunk();
                    drawnTriangles += mChunks[i]->trienglesCount;
                }
            }
            else if(mChunks[i]->created)
            {
                mChunks[i]->reset();
            }
        }
    }


    //transparent chunks
    //transparent sorting
    if(camUpdate)
    {
        transOrderCont = 0;
        int j = 0;

        for(unsigned int i = 0; i < mTransparentChunks.size(); i++)
        {
            if(mTransparentChunks[i]->trienglesCount > 0 || !mTransparentChunks[i]->created)
            {
                if(playerZoneBB.intersect(mTransparentChunks[i]->bBox))
                {
                    transOrder[j].distance =  Vector3::distanceSq(playerPos,mTransparentChunks[i]->bBox.getCenter());
                    transOrder[j].chunk = i;
                    j++;
                    transOrderCont++;
                }
                else
                {
                    mTransparentChunks[i]->reset();
                }
            }
        }

        //sorting
        qsort(transOrder,transOrderCont,sizeof(TransparentOrder),compareTarnsSort);
    }

    //transparent rendering
    if(transOrderCont > 0)
    {
        for(int i = 0; i < transOrderCont; i++)
        {
            int chunk = transOrder[i].chunk;

            //check if wee need to build vertices of this chunk
            if((!mTransparentChunks[chunk]->created || mTransparentChunks[chunk]->needUpdate) && transparentchunksCreatedInFrameCount == 0)
            {
                rebuildTransparentChunk(chunk);
                transparentchunksCreatedInFrameCount++;
            }
        }
    }

    if(transOrderCont > 0)
    {
        //draw
        sceGuDepthMask(1);
        sceGuColor(0x55FFFFFF);
        sceGuEnable(GU_BLEND);
        //sceGuDisable(GU_CULL_FACE);

        for(int i = transOrderCont - 1; i >=0; i--)
        {
            int chunk = transOrder[i].chunk;
            mTransparentChunks[chunk]->drawChunk();
            drawnTriangles += mChunks[chunk]->trienglesCount;
        }

        //sceGuEnable(GU_CULL_FACE);
        sceGuDisable(GU_BLEND);
        sceGuDisable(GU_TEXTURE_2D);
        sceGuDepthMask(0);
    }
}

void CraftWorld::UpdatePlayerZoneBB(Vector3 playerPosition)
{
    playerPos = playerPosition;
    playerZoneBB = BoundingBox(Vector3(playerPosition.x - playerZoneSize.x,playerPosition.y - playerZoneSize.y,playerPosition.z - playerZoneSize.z),Vector3(playerPosition.x + playerZoneSize.x,playerPosition.y + playerZoneSize.y,playerPosition.z + playerZoneSize.z));
}

Vector3 CraftWorld::GetPlayerPos()
{
    return playerPos;
}
int CraftWorld::GetPlayerhealth()
{
    return player.health;
}
int CraftWorld::GetPlayermaxhealth()
{
    return player.maxhealth;
}
int CraftWorld::Apples()
{
    return player.Apples;
}

int CraftWorld::GrassNumber()
{
    return player.GrassNumber;
}

int CraftWorld::DirtNumber()
{
    return player.DirtNumber;
}

int CraftWorld::LogNumber()
{
    return player.LogNumber;
}

int CraftWorld::PlankNumber()
{
    return player.PlankNumber;
}

int CraftWorld::hunger()
{
    return player.hunger;
}
int CraftWorld::melons()
{
    return player.melons;
}
int CraftWorld::score()
{
    return player.score;
}
int CraftWorld::NumMobs()
{
    return player.NumMobs;
}
int CraftWorld::gamemode()
{
    return player.gamemode;
}
int CraftWorld::jumpHeight()
{
    return player.jumpHeight;
}
int CraftWorld::walkSpeed()
{
    return player.walkSpeed;
}
int CraftWorld::fireResistance()
{
    return player.fireResistance;
}



void CraftWorld::UpdateWorldTime(float dt)
{
    worldTime += dt;
    //stuff that goes on tick
    //1 tick = 1 second

    //rebuilding chunks
    updateChunkTimer += dt;
    if(updateChunkTimer > 0.3f)//update time 1/4 second
    {
        chunksCreatedInFrameCount = 0;
        transparentchunksCreatedInFrameCount = 0;
        updateChunkTimer = 0.0f;
    }

    if(worldTime > 1.0f)
    {
        worldTime = 0.0f;
    }

    if(!freezeDayTime)
    {
        //world day/night time
        worldHour += dt;
        if(worldHour > 50.0f)//one game hour = 50 sec
        {
            worldHour = 0.0f;
            worldDayTime += 1.0f;

            if(worldDayTime > 24.0f)
                worldDayTime = 0.0f;

            SetWolrdTime(worldDayTime);
            SetAllChunksToUpdate();
        }
    }
}

bool CraftWorld::isSolid(const int x, const int y, const int z)
{
    return !(GetBlock(x,y,z) == 0 || GetBlock(x,y,z) == 4 || GetBlock(x,y,z) == Torch::getID() || GetBlock(x,y,z) == Lava::getID() || GetBlock(x,y,z) == CaneBlock::getID() || GetBlock(x,y,z) == LadderBlock::getID() || GetBlock(x,y,z) == Sapling1::getID() || GetBlock(x,y,z) == Sapling2::getID() || GetBlock(x,y,z) == Sapling3::getID() || GetBlock(x,y,z) == wines::getID());
}

int CraftWorld::GetBlockTypesCount()
{
    return blockTypes.size();
}

int CraftWorld::groundHeight(const int x, const int z)
{
    if (x < 0 || z < 0 || x >= WORLD_SIZE || z >= WORLD_SIZE) return -1;

    for (int y = WORLD_SIZE - 1; y >= 0; --y)
    {
        block_t Block = GetBlock(x, y, z);
        if (Block != 0 && Block != 4) return (y);
    }

    return -1;
}

int CraftWorld::getChunkId(Vector3 pos)
{
    for(unsigned int i = 0; i < mChunks.size(); i++)
    {
        if(mChunks[i]->bBox.contains(pos))
            return mChunks[i]->id;
    }

    return -1;
}

bool CraftWorld::PlayerTouchCactus(Vector3 PlayerPos)
{
    Vector3 Check_Right = PlayerPos   + Vector3(0.5, -1, 0);
    Vector3 Check_Left = PlayerPos    +	Vector3(-0.5, -1, 0);
    Vector3 Check_Front = PlayerPos   +	Vector3(0, -1, 0.5);
    Vector3 Check_Back = PlayerPos    + Vector3(0, -1, -0.5);
    Vector3 Check_Up = PlayerPos 	  + Vector3(0, 0.6, 0);
    Vector3 Check_Down = PlayerPos 	  + Vector3(0, -1.5, 0);

    if (GetBlock(Check_Right.x, Check_Right.y, Check_Right.z) == CactusBlock::getID() 	||
            GetBlock(Check_Left.x, Check_Left.y, Check_Left.z) == CactusBlock::getID() 		||
            GetBlock(Check_Front.x, Check_Front.y, Check_Front.z) == CactusBlock::getID()	||
            GetBlock(Check_Back.x, Check_Back.y, Check_Back.z) == CactusBlock::getID()		||
            GetBlock(Check_Up.x, Check_Up.y, Check_Up.z) == CactusBlock::getID()			||
            GetBlock(Check_Down.x, Check_Down.y, Check_Down.z) == CactusBlock::getID())
        return true;
    else
        return false;

    return 0;
}

bool CraftWorld::PlayerTouchEndMap(Vector3 pos)
{
    int x = pos.x;
    int y = pos.y;
    int z = pos.z;

    if (x <= 0 || y <= 0 || z <= 0  || x >= WORLD_SIZE-1 || y >= WORLD_SIZE-1 || z >= WORLD_SIZE-1)
        return true;
    else
        return false;
}

bool CraftWorld::PlayerTouchEndermanBody(Vector3 PlayerPos)
{
    Vector3 Check_Right = PlayerPos   + Vector3(0.5, -1, 0);
    Vector3 Check_Left = PlayerPos    +	Vector3(-0.5, -1, 0);
    Vector3 Check_Front = PlayerPos   +	Vector3(0, -1, 0.5);
    Vector3 Check_Back = PlayerPos    + Vector3(0, -1, -0.5);
    Vector3 Check_Up = PlayerPos 	  + Vector3(0, 0.6, 0);
    Vector3 Check_Down = PlayerPos 	  + Vector3(0, -1.5, 0);

    if ((GetBlock(Check_Right.x, Check_Right.y, Check_Right.z) == EnderTop::getID() && GetBlock(Check_Right.x, Check_Right.y-1, Check_Right.z) == EnderLegs::getID()) 	||
            (GetBlock(Check_Left.x, Check_Left.y, Check_Left.z) == EnderTop::getID() && GetBlock(Check_Left.x, Check_Left.y-1, Check_Left.z) == EnderLegs::getID())		||
            (GetBlock(Check_Front.x, Check_Front.y, Check_Front.z) == EnderTop::getID() && GetBlock(Check_Front.x, Check_Front.y-1, Check_Front.z) == EnderLegs::getID())	||
            (GetBlock(Check_Back.x, Check_Back.y, Check_Back.z) == EnderTop::getID() && GetBlock(Check_Back.x, Check_Back.y-1, Check_Back.z) == EnderLegs::getID())		||
            (GetBlock(Check_Up.x, Check_Up.y, Check_Up.z) == EnderTop::getID() && GetBlock(Check_Up.x, Check_Up.y-1, Check_Up.z) == EnderLegs::getID())			||
            (GetBlock(Check_Down.x, Check_Down.y, Check_Down.z) == EnderTop::getID() && GetBlock(Check_Down.x, Check_Down.y-1, Check_Down.z) == EnderLegs::getID()))
        return true;
    else
        return false;

    return 0;
}

bool CraftWorld::PlayerTouchEndermanLegs(Vector3 PlayerPos)
{
    Vector3 Check_Right = PlayerPos   + Vector3(0.5, -1, 0);
    Vector3 Check_Left = PlayerPos    +	Vector3(-0.5, -1, 0);
    Vector3 Check_Front = PlayerPos   +	Vector3(0, -1, 0.5);
    Vector3 Check_Back = PlayerPos    + Vector3(0, -1, -0.5);
    Vector3 Check_Up = PlayerPos 	  + Vector3(0, 0.6, 0);
    Vector3 Check_Down = PlayerPos 	  + Vector3(0, -1.5, 0);

    if ((GetBlock(Check_Right.x, Check_Right.y, Check_Right.z) == EnderLegs::getID() && GetBlock(Check_Right.x, Check_Right.y+1, Check_Right.z) == EnderTop::getID()) 	||
            (GetBlock(Check_Left.x, Check_Left.y, Check_Left.z) == EnderLegs::getID() && GetBlock(Check_Left.x, Check_Left.y+1, Check_Left.z) == EnderTop::getID())		||
            (GetBlock(Check_Front.x, Check_Front.y, Check_Front.z) == EnderLegs::getID() && GetBlock(Check_Front.x, Check_Front.y+1, Check_Front.z) == EnderTop::getID())	||
            (GetBlock(Check_Back.x, Check_Back.y, Check_Back.z) == EnderLegs::getID() && GetBlock(Check_Back.x, Check_Back.y+1, Check_Back.z) == EnderTop::getID())		||
            (GetBlock(Check_Up.x, Check_Up.y, Check_Up.z) == EnderLegs::getID() && GetBlock(Check_Up.x, Check_Up.y-+1, Check_Up.z) == EnderTop::getID())			||
            (GetBlock(Check_Down.x, Check_Down.y, Check_Down.z) == EnderLegs::getID() && GetBlock(Check_Down.x, Check_Down.y+1, Check_Down.z) == EnderTop::getID()))
        return true;
    else
        return false;

    return 0;
}

bool CraftWorld::PlayerTouchZombieBody(Vector3 PlayerPos)
{
    Vector3 Check_Right = PlayerPos   + Vector3(0.5, -1, 0);
    Vector3 Check_Left = PlayerPos    +	Vector3(-0.5, -1, 0);
    Vector3 Check_Front = PlayerPos   +	Vector3(0, -1, 0.5);
    Vector3 Check_Back = PlayerPos    + Vector3(0, -1, -0.5);
    Vector3 Check_Up = PlayerPos 	  + Vector3(0, 0.6, 0);
    Vector3 Check_Down = PlayerPos 	  + Vector3(0, -1.5, 0);

    if ((GetBlock(Check_Right.x, Check_Right.y, Check_Right.z) == ZombieTop::getID() && GetBlock(Check_Right.x, Check_Right.y-1, Check_Right.z) == ZombieLegs::getID()) 	||
            (GetBlock(Check_Left.x, Check_Left.y, Check_Left.z) == ZombieTop::getID() && GetBlock(Check_Left.x, Check_Left.y-1, Check_Left.z) == ZombieLegs::getID())		||
            (GetBlock(Check_Front.x, Check_Front.y, Check_Front.z) == ZombieTop::getID() && GetBlock(Check_Front.x, Check_Front.y-1, Check_Front.z) == ZombieLegs::getID())	||
            (GetBlock(Check_Back.x, Check_Back.y, Check_Back.z) == ZombieTop::getID() && GetBlock(Check_Back.x, Check_Back.y-1, Check_Back.z) == ZombieLegs::getID())		||
            (GetBlock(Check_Up.x, Check_Up.y, Check_Up.z) == ZombieTop::getID() && GetBlock(Check_Up.x, Check_Up.y-1, Check_Up.z) == ZombieLegs::getID())			||
            (GetBlock(Check_Down.x, Check_Down.y, Check_Down.z) == ZombieTop::getID() && GetBlock(Check_Down.x, Check_Down.y-1, Check_Down.z) == ZombieLegs::getID()))
        return true;
    else
        return false;

    return 0;
}

bool CraftWorld::PlayerTouchZombieLegs(Vector3 PlayerPos)
{
    Vector3 Check_Right = PlayerPos   + Vector3(0.5, -1, 0);
    Vector3 Check_Left = PlayerPos    +	Vector3(-0.5, -1, 0);
    Vector3 Check_Front = PlayerPos   +	Vector3(0, -1, 0.5);
    Vector3 Check_Back = PlayerPos    + Vector3(0, -1, -0.5);
    Vector3 Check_Up = PlayerPos 	  + Vector3(0, 0.6, 0);
    Vector3 Check_Down = PlayerPos 	  + Vector3(0, -1.5, 0);

    if ((GetBlock(Check_Right.x, Check_Right.y, Check_Right.z) == ZombieLegs::getID() && GetBlock(Check_Right.x, Check_Right.y+1, Check_Right.z) == ZombieTop::getID()) 	||
            (GetBlock(Check_Left.x, Check_Left.y, Check_Left.z) == ZombieLegs::getID() && GetBlock(Check_Left.x, Check_Left.y+1, Check_Left.z) == ZombieTop::getID())		||
            (GetBlock(Check_Front.x, Check_Front.y, Check_Front.z) == ZombieLegs::getID() && GetBlock(Check_Front.x, Check_Front.y+1, Check_Front.z) == ZombieTop::getID())	||
            (GetBlock(Check_Back.x, Check_Back.y, Check_Back.z) == ZombieLegs::getID() && GetBlock(Check_Back.x, Check_Back.y+1, Check_Back.z) == ZombieTop::getID())		||
            (GetBlock(Check_Up.x, Check_Up.y, Check_Up.z) == ZombieLegs::getID() && GetBlock(Check_Up.x, Check_Up.y+1, Check_Up.z) == ZombieTop::getID())			||
            (GetBlock(Check_Down.x, Check_Down.y, Check_Down.z) == ZombieLegs::getID() && GetBlock(Check_Down.x, Check_Down.y+1, Check_Down.z) == ZombieTop::getID()))
        return true;
    else
        return false;

    return 0;
}

bool CraftWorld::SolidAtPoint(Vector3 pos)
{
    int x = pos.x;
    int y = pos.y;
    int z = pos.z;

    //outside the world so collision
    if (x <= 0 || y <= 0 || z <= 0  || x >= WORLD_SIZE-1 || y >= WORLD_SIZE-1 || z >= WORLD_SIZE-1) return true;

    //don't collide blocks
    if(GetBlock(x,y,z) == brickWallSlap::getID() || GetBlock(x,y,z) == quartzSlap::getID() || GetBlock(x,y,z) == Cake::getID() || GetBlock(x,y,z) == TrapDoor::getID() || GetBlock(x,y,z) == lilyPad::getID() || GetBlock(x,y,z) == CobWeb::getID() || GetBlock(x,y,z) == 82 || GetBlock(x,y,z) == 83 || GetBlock(x,y,z) == 84 || GetBlock(x,y,z) == 85 || GetBlock(x,y,z) == 86 || GetBlock(x,y,z) == 87 || GetBlock(x,y,z) == 88 || GetBlock(x,y,z) == 89 || GetBlock(x,y,z) == 90 || GetBlock(x,y,z) == Fire::getID() || GetBlock(x,y,z) == MelonSeeds::getID() || GetBlock(x,y,z) == WaterFlow::getID() || GetBlock(x,y,z) == Sapling3::getID() || GetBlock(x,y,z) == Sapling2::getID() || GetBlock(x,y,z) == Sapling1::getID() || GetBlock(x,y,z) == netherWarp::getID() || GetBlock(x,y,z) == wheat::getID() || GetBlock(x,y,z) == wines::getID() || GetBlock(x,y,z) == LadderBlock::getID() || GetBlock(x,y,z) == StonePlate::getID() || GetBlock(x,y,z) == WoodPlate::getID() || GetBlock(x,y,z) == Lava::getID() || GetBlock(x,y,z) == Grass::getID() || GetBlock(x,y,z) == Snow2::getID() || GetBlock(x,y,z) == TrapDoor2::getID() || GetBlock(x,y,z) == 0 || GetBlock(x,y,z) == 4 || GetBlock(x,y,z) == Torch::getID() || GetBlock(x,y,z) == Door1::getID() || GetBlock(x,y,z) == Door2::getID() || GetBlock(x,y,z) == 70 ||GetBlock(x,y,z) == Cloud::getID() ||GetBlock(x,y,z) == CaneBlock::getID())
    {
        //
        return false;
    }

    //collision
    return true;
}

int CraftWorld::BlockSoundAtPos(Vector3 pos)
{
    int x = pos.x;
    int y = pos.y;
    int z = pos.z;

    //outside the world so collision
    if (x <= 0 || y <= 0 || z <= 0  || x >= WORLD_SIZE-1 || y >= WORLD_SIZE-1 || z >= WORLD_SIZE-1) return -1;

    return blockTypes[GetBlock(x,y,z)].soundType;
}

bool CraftWorld::SolidAtPointForPlayer(Vector3 pos)
{
    int x = pos.x;
    int y = pos.y;
    int z = pos.z;

    //outside the world so collision
    if (x <= 0 || y <= 0 || z <= 0  || x >= WORLD_SIZE-1 || y >= WORLD_SIZE-1 || z >= WORLD_SIZE-1) return true;

    //don't collide with water and air
    if(GetBlock(x,y,z) == brickWallSlap::getID() || GetBlock(x,y,z) == quartzSlap::getID() || GetBlock(x,y,z) == Cake::getID() || GetBlock(x,y,z) == TrapDoor::getID() || GetBlock(x,y,z) == lilyPad::getID() || GetBlock(x,y,z) == CobWeb::getID() || GetBlock(x,y,z) == 82 || GetBlock(x,y,z) == 83 || GetBlock(x,y,z) == 84 || GetBlock(x,y,z) == 85 || GetBlock(x,y,z) == 86 || GetBlock(x,y,z) == 87 || GetBlock(x,y,z) == 88 || GetBlock(x,y,z) == 89 || GetBlock(x,y,z) == 90 || GetBlock(x,y,z) == Fire::getID() || GetBlock(x,y,z) == MelonSeeds::getID() || GetBlock(x,y,z) == WaterFlow::getID() || GetBlock(x,y,z) == Sapling3::getID() || GetBlock(x,y,z) == Sapling2::getID() || GetBlock(x,y,z) == Sapling1::getID() || GetBlock(x,y,z) == netherWarp::getID() || GetBlock(x,y,z) == wheat::getID() || GetBlock(x,y,z) == wines::getID() || GetBlock(x,y,z) == LadderBlock::getID() || GetBlock(x,y,z) == StonePlate::getID() || GetBlock(x,y,z) == WoodPlate::getID() || GetBlock(x,y,z) == Lava::getID() || GetBlock(x,y,z) == Grass::getID() || GetBlock(x,y,z) == Snow2::getID() || GetBlock(x,y,z) == TrapDoor2::getID() || GetBlock(x,y,z) == 0 || GetBlock(x,y,z) == 4 || GetBlock(x,y,z) == Torch::getID() || GetBlock(x,y,z) == Door1::getID() || GetBlock(x,y,z) == Door2::getID() || GetBlock(x,y,z) == 70 || GetBlock(x,y,z) == Cloud::getID() ||GetBlock(x,y,z) == CaneBlock::getID() )
    {
        //4 corners
        if(SolidAtPoint(Vector3(pos.x-0.15f,pos.y,pos.z-0.15f))) return true;
        if(SolidAtPoint(Vector3(pos.x+0.15f,pos.y,pos.z+0.15f))) return true;
        if(SolidAtPoint(Vector3(pos.x+0.15f,pos.y,pos.z-0.15f))) return true;
        if(SolidAtPoint(Vector3(pos.x-0.15f,pos.y,pos.z+0.15f))) return true;
        //
        return false;
    }

    //collision
    return true;
}

bool CraftWorld::PlayerInWater(Vector3 pos)
{
    int x = pos.x;
    int y = pos.y;
    int z = pos.z;

    if (x < 0 || y < 0 || z < 0  || x >= WORLD_SIZE-1 || y >= WORLD_SIZE-1 || z >= WORLD_SIZE-1) return false;

    if(GetBlock(x,y,z) == 4 || GetBlock(x,y,z) == WaterFlow::getID())
        return true;

    return false;
}

bool CraftWorld::PlayerOnLilyPad(Vector3 pos)
{
    int x = pos.x;
    int y = pos.y;
    int z = pos.z;

    if (x < 0 || y < 0 || z < 0  || x >= WORLD_SIZE-1 || y >= WORLD_SIZE-1 || z >= WORLD_SIZE-1) return false;

    if(GetBlock(x,y,z) == lilyPad::getID())
        return true;

    return false;
}

bool CraftWorld::PlayerInLava(Vector3 pos)
{
    int x = pos.x;
    int y = pos.y;
    int z = pos.z;

    if (x < 0 || y < 0 || z < 0  || x >= WORLD_SIZE-1 || y >= WORLD_SIZE-1 || z >= WORLD_SIZE-1) return false;

    if(GetBlock(x,y,z) == Lava::getID())
        return true;

    return false;
}

bool CraftWorld::PlayerOnLadder(Vector3 pos)
{
    int x = pos.x;
    int y = pos.y;
    int z = pos.z;

    if (x < 0 || y < 0 || z < 0  || x >= WORLD_SIZE-1 || y >= WORLD_SIZE-1 || z >= WORLD_SIZE-1) return false;

    if(GetBlock(x,y,z) == wines::getID() || GetBlock(x,y,z) == LadderBlock::getID())
        return true;

    return false;
}

bool CraftWorld::PlayerInWeb(Vector3 pos)
{
    int x = pos.x;
    int y = pos.y;
    int z = pos.z;

    if (x < 0 || y < 0 || z < 0  || x >= WORLD_SIZE-1 || y >= WORLD_SIZE-1 || z >= WORLD_SIZE-1) return false;

    if(GetBlock(x,y,z) == CobWeb::getID())
        return true;

    return false;
}

bool CraftWorld::PlayerOnSoulSand(Vector3 pos)
{
    int x = pos.x;
    int y = pos.y;
    int z = pos.z;

    if (x < 0 || y < 0 || z < 0  || x >= WORLD_SIZE-1 || y >= WORLD_SIZE-1 || z >= WORLD_SIZE-1) return false;

    if(GetBlock(x,y,z) == SoulSand::getID())
        return true;

    return false;
}

bool CraftWorld::PlayerOnHalfBlock(Vector3 pos)
{
    int x = pos.x;
    int y = pos.y;
    int z = pos.z;

    if (x < 0 || y < 0 || z < 0  || x >= WORLD_SIZE-1 || y >= WORLD_SIZE-1 || z >= WORLD_SIZE-1) return false;

    if(GetBlock(x,y,z) == brickWallSlap::getID() || GetBlock(x,y,z) == quartzSlap::getID() || GetBlock(x,y,z) == Cake::getID() || GetBlock(x,y,z) == TrapDoor::getID() || GetBlock(x,y,z) == 82 || GetBlock(x,y,z) == 83 || GetBlock(x,y,z) == 84 || GetBlock(x,y,z) == 85 || GetBlock(x,y,z) == 86 || GetBlock(x,y,z) == 87 || GetBlock(x,y,z) == 88 || GetBlock(x,y,z) == 89 || GetBlock(x,y,z) == 90)
        return true;

    return false;
}

block_t CraftWorld::BlockAtPoint(Vector3 pos)
{
    int x = pos.x;
    int y = pos.y;
    int z = pos.z;

    if (x < 0 || y < 0 || z < 0  || x >= WORLD_SIZE || y >= WORLD_SIZE || z >= WORLD_SIZE) return -1;

    return GetBlock(x,y,z);

}

void CraftWorld::UpdateChunkBlocks(int id)
{
    SimpleMeshChunk* MeshChunk = mChunks[id];

    int StartZ = MeshChunk->chunkStartZ;
    int StartY = MeshChunk->chunkStartY;
    int StartX = MeshChunk->chunkStartX;

    for (int z = StartZ; z < CHUNK_SIZE + StartZ; ++z)
    {
        for (int y = StartY; y < CHUNK_SIZE + StartY; ++y)
        {
            for (int x = StartX; x < CHUNK_SIZE + StartX; ++x)
            {
                //falling sand
                if(GetBlock(x,y,z) == SandBlock::getID())
                {
                    if(GetBlock(x,y-1,z) == 0 || GetBlock(x,y-1,z) == 4 || GetBlock(x,y-1,z) == Lava::getID())
                    {
                        GetBlock(x,y,z) = 0;
                        GetBlock(x,y-1,z) = SandBlock::getID();
                    }
                    else
                    {
                        GetBlock(x,y,z) = SandBlock::getID();
                    }
                }

                //falling gravel
                if(GetBlock(x,y,z) == Gravel::getID())
                {
                    if(GetBlock(x,y-1,z) == 0 || GetBlock(x,y-1,z) == 4 ||GetBlock(x,y-1,z) == Lava::getID())
                    {
                        GetBlock(x,y,z) = 0;
                        GetBlock(x,y-1,z) = Gravel::getID();
                    }
                    else
                    {
                        GetBlock(x,y,z) = Gravel::getID();
                    }
                }

                if(GetBlock(x,y,z) == IceBlock::getID())
                {
                    if(GetBlock(x,y+1,z) == SnowLewesBlock::getID() || GetBlock(x,y+2,z) == SnowLewesBlock::getID() || GetBlock(x,y+3,z) == SnowLewesBlock::getID() || GetBlock(x,y+4,z) == SnowLewesBlock::getID() || GetBlock(x,y+5,z) == SnowLewesBlock::getID())
                    {
                        GetBlock(x,y,z) = 4;
                    }
                }

                //fire
                if(GetBlock(x,y,z) == Fire::getID())
                {
                    if(GetBlock(x+1,y,z) == WoodBlock::getID() || GetBlock(x+1,y,z) == LeavesBlock::getID() || GetBlock(x+1,y,z) == TNTBlock::getID() || GetBlock(x+1,y,z) == BlackWoolBlock::getID() ||
                        GetBlock(x+1,y,z) == RedWoolBlock::getID() || GetBlock(x+1,y,z) == DarkGreyWoolBlock::getID() || GetBlock(x+1,y,z) == BrownWoolBlock::getID()  || GetBlock(x+1,y,z) == LightBlackWoolBlock::getID() ||
                        GetBlock(x+1,y,z) == PinkWoolBlock::getID() || GetBlock(x+1,y,z) == LightGreenWoolBlock::getID() || GetBlock(x+1,y,z) == YellowWoolBlock::getID() || GetBlock(x+1,y,z) == BlueWoolBlock::getID() ||
                        GetBlock(x+1,y,z) == LightBlueWoolBlock::getID() || GetBlock(x+1,y,z) == FioletWoolBlock::getID() || GetBlock(x+1,y,z) == PastelWoolBlock::getID() || GetBlock(x+1,y,z) == LightFioletWoolBlock::getID() ||
                        GetBlock(x+1,y,z) == OrangeWoolBlock::getID() || GetBlock(x+1,y,z) == DarkWoodBlock::getID() || GetBlock(x+1,y,z) == WhiteWoodBlock::getID() || GetBlock(x+1,y,z) == BoxBlock::getID() ||
                        GetBlock(x+1,y,z) == ShelfBlock::getID() || GetBlock(x+1,y,z) == SnowLewesBlock::getID() || GetBlock(x+1,y,z) == JungleWood::getID() || GetBlock(x+1,y,z) == Planks1::getID() || GetBlock(x+1,y,z) == Planks2::getID() || GetBlock(x+1,y,z) == Planks3::getID() ||
                        GetBlock(x+1,y,z) == AetherPlanks::getID() || GetBlock(x+1,y,z) == Crafting::getID() || GetBlock(x+1,y,z) == JungleLeaves::getID() || GetBlock(x+1,y,z) == LeavesBlock::getID())
                        {
                            GetBlock(x,y,z) = 0;
                            GetBlock(x+1,y,z) = Fire::getID();
                        }
                    else if(GetBlock(x-1,y,z) == WoodBlock::getID() || GetBlock(x-1,y,z) == LeavesBlock::getID() || GetBlock(x-1,y,z) == TNTBlock::getID() || GetBlock(x-1,y,z) == BlackWoolBlock::getID() ||
                        GetBlock(x-1,y,z) == RedWoolBlock::getID() || GetBlock(x-1,y,z) == DarkGreyWoolBlock::getID() || GetBlock(x-1,y,z) == BrownWoolBlock::getID()  || GetBlock(x-1,y,z) == LightBlackWoolBlock::getID() ||
                        GetBlock(x-1,y,z) == PinkWoolBlock::getID() || GetBlock(x-1,y,z) == LightGreenWoolBlock::getID() || GetBlock(x-1,y,z) == YellowWoolBlock::getID() || GetBlock(x-1,y,z) == BlueWoolBlock::getID() ||
                        GetBlock(x-1,y,z) == LightBlueWoolBlock::getID() || GetBlock(x-1,y,z) == FioletWoolBlock::getID() || GetBlock(x-1,y,z) == PastelWoolBlock::getID() || GetBlock(x-1,y,z) == LightFioletWoolBlock::getID() ||
                        GetBlock(x-1,y,z) == OrangeWoolBlock::getID() || GetBlock(x-1,y,z) == DarkWoodBlock::getID() || GetBlock(x-1,y,z) == WhiteWoodBlock::getID() || GetBlock(x-1,y,z) == BoxBlock::getID() ||
                        GetBlock(x-1,y,z) == ShelfBlock::getID() || GetBlock(x-1,y,z) == SnowLewesBlock::getID() || GetBlock(x-1,y,z) == JungleWood::getID() || GetBlock(x-1,y,z) == Planks1::getID() || GetBlock(x-1,y,z) == Planks2::getID() || GetBlock(x-1,y,z) == Planks3::getID() ||
                        GetBlock(x-1,y,z) == AetherPlanks::getID() || GetBlock(x-1,y,z) == Crafting::getID() || GetBlock(x-1,y,z) == JungleLeaves::getID() || GetBlock(x-1,y,z) == LeavesBlock::getID())
                        {
                            GetBlock(x,y,z) = 0;
                            GetBlock(x-1,y,z) = Fire::getID();
                        }
                    else if(GetBlock(x,y,z+1) == WoodBlock::getID() || GetBlock(x,y,z+1) == LeavesBlock::getID() || GetBlock(x,y,z+1) == TNTBlock::getID() || GetBlock(x,y,z+1) == BlackWoolBlock::getID() ||
                        GetBlock(x,y,z+1) == RedWoolBlock::getID() || GetBlock(x,y,z+1) == DarkGreyWoolBlock::getID() || GetBlock(x,y,z+1) == BrownWoolBlock::getID()  || GetBlock(x,y,z+1) == LightBlackWoolBlock::getID() ||
                        GetBlock(x,y,z+1) == PinkWoolBlock::getID() || GetBlock(x,y,z+1) == LightGreenWoolBlock::getID() || GetBlock(x,y,z+1) == YellowWoolBlock::getID() || GetBlock(x,y,z+1) == BlueWoolBlock::getID() ||
                        GetBlock(x,y,z+1) == LightBlueWoolBlock::getID() || GetBlock(x,y,z+1) == FioletWoolBlock::getID() || GetBlock(x,y,z+1) == PastelWoolBlock::getID() || GetBlock(x,y,z+1) == LightFioletWoolBlock::getID() ||
                        GetBlock(x,y,z+1) == OrangeWoolBlock::getID() || GetBlock(x,y,z+1) == DarkWoodBlock::getID() || GetBlock(x,y,z+1) == WhiteWoodBlock::getID() || GetBlock(x,y,z+1) == BoxBlock::getID() ||
                        GetBlock(x,y,z+1) == ShelfBlock::getID() || GetBlock(x,y,z+1) == SnowLewesBlock::getID() || GetBlock(x,y,z+1) == JungleWood::getID() || GetBlock(x,y,z+1) == Planks1::getID() || GetBlock(x,y,z+1) == Planks2::getID() || GetBlock(x,y,z+1) == Planks3::getID() ||
                        GetBlock(x,y,z+1) == AetherPlanks::getID() || GetBlock(x,y,z+1) == Crafting::getID() || GetBlock(x,y,z+1) == JungleLeaves::getID() || GetBlock(x,y,z+1) == LeavesBlock::getID())
                        {
                            GetBlock(x,y,z+1) = 0;
                            GetBlock(x,y,z+1) = Fire::getID();
                        }
                     else if(GetBlock(x,y,z-1) == WoodBlock::getID() || GetBlock(x,y,z-1) == LeavesBlock::getID() || GetBlock(x,y,z-1) == TNTBlock::getID() || GetBlock(x,y,z-1) == BlackWoolBlock::getID() ||
                        GetBlock(x,y,z-1) == RedWoolBlock::getID() || GetBlock(x,y,z-1) == DarkGreyWoolBlock::getID() || GetBlock(x,y,z-1) == BrownWoolBlock::getID()  || GetBlock(x,y,z-1) == LightBlackWoolBlock::getID() ||
                        GetBlock(x,y,z-1) == PinkWoolBlock::getID() || GetBlock(x,y,z-1) == LightGreenWoolBlock::getID() || GetBlock(x,y,z-1) == YellowWoolBlock::getID() || GetBlock(x,y,z-1) == BlueWoolBlock::getID() ||
                        GetBlock(x,y,z-1) == LightBlueWoolBlock::getID() || GetBlock(x,y,z-1) == FioletWoolBlock::getID() || GetBlock(x,y,z-1) == PastelWoolBlock::getID() || GetBlock(x,y,z-1) == LightFioletWoolBlock::getID() ||
                        GetBlock(x,y,z-1) == OrangeWoolBlock::getID() || GetBlock(x,y,z-1) == DarkWoodBlock::getID() || GetBlock(x,y,z-1) == WhiteWoodBlock::getID() || GetBlock(x,y,z-1) == BoxBlock::getID() ||
                        GetBlock(x,y,z-1) == ShelfBlock::getID() || GetBlock(x,y,z-1) == SnowLewesBlock::getID() || GetBlock(x,y,z-1) == JungleWood::getID() || GetBlock(x,y,z-1) == Planks1::getID() || GetBlock(x,y,z-1) == Planks2::getID() || GetBlock(x,y,z-1) == Planks3::getID() ||
                        GetBlock(x,y,z-1) == AetherPlanks::getID() || GetBlock(x,y,z-1) == Crafting::getID() || GetBlock(x,y,z-1) == JungleLeaves::getID() || GetBlock(x,y,z-1) == LeavesBlock::getID())
                        {
                            GetBlock(x,y,z-1) = 0;
                            GetBlock(x,y,z-1) = Fire::getID();
                        }
                     else if(GetBlock(x,y+1,z) == WoodBlock::getID() || GetBlock(x,y+1,z) == LeavesBlock::getID() || GetBlock(x,y+1,z) == TNTBlock::getID() || GetBlock(x,y+1,z) == BlackWoolBlock::getID() ||
                        GetBlock(x,y+1,z) == RedWoolBlock::getID() || GetBlock(x,y+1,z) == DarkGreyWoolBlock::getID() || GetBlock(x,y+1,z) == BrownWoolBlock::getID()  || GetBlock(x,y+1,z) == LightBlackWoolBlock::getID() ||
                        GetBlock(x,y+1,z) == PinkWoolBlock::getID() || GetBlock(x,y+1,z) == LightGreenWoolBlock::getID() || GetBlock(x,y+1,z) == YellowWoolBlock::getID() || GetBlock(x,y+1,z) == BlueWoolBlock::getID() ||
                        GetBlock(x,y+1,z) == LightBlueWoolBlock::getID() || GetBlock(x,y+1,z) == FioletWoolBlock::getID() || GetBlock(x,y+1,z) == PastelWoolBlock::getID() || GetBlock(x,y+1,z) == LightFioletWoolBlock::getID() ||
                        GetBlock(x,y+1,z) == OrangeWoolBlock::getID() || GetBlock(x,y+1,z) == DarkWoodBlock::getID() || GetBlock(x,y+1,z) == WhiteWoodBlock::getID() || GetBlock(x,y+1,z) == BoxBlock::getID() ||
                        GetBlock(x,y+1,z) == ShelfBlock::getID() || GetBlock(x,y+1,z) == SnowLewesBlock::getID() || GetBlock(x,y+1,z) == JungleWood::getID() || GetBlock(x,y+1,z) == Planks1::getID() || GetBlock(x,y+1,z) == Planks2::getID() || GetBlock(x,y+1,z) == Planks3::getID() ||
                        GetBlock(x,y+1,z) == AetherPlanks::getID() || GetBlock(x,y+1,z) == Crafting::getID() || GetBlock(x,y+1,z) == JungleLeaves::getID() || GetBlock(x,y+1,z) == LeavesBlock::getID())
                        {
                            GetBlock(x,y+1,z) = 0;
                            GetBlock(x,y+1,z) = Fire::getID();
                        }
                    else if(GetBlock(x,y+1,z) == WoodBlock::getID() || GetBlock(x,y+1,z) == LeavesBlock::getID() || GetBlock(x,y+1,z) == TNTBlock::getID() || GetBlock(x,y+1,z) == BlackWoolBlock::getID() ||
                        GetBlock(x,y+1,z) == RedWoolBlock::getID() || GetBlock(x,y+1,z) == DarkGreyWoolBlock::getID() || GetBlock(x,y+1,z) == BrownWoolBlock::getID()  || GetBlock(x,y+1,z) == LightBlackWoolBlock::getID() ||
                        GetBlock(x,y+1,z) == PinkWoolBlock::getID() || GetBlock(x,y+1,z) == LightGreenWoolBlock::getID() || GetBlock(x,y+1,z) == YellowWoolBlock::getID() || GetBlock(x,y+1,z) == BlueWoolBlock::getID() ||
                        GetBlock(x,y+1,z) == LightBlueWoolBlock::getID() || GetBlock(x,y+1,z) == FioletWoolBlock::getID() || GetBlock(x,y+1,z) == PastelWoolBlock::getID() || GetBlock(x,y+1,z) == LightFioletWoolBlock::getID() ||
                        GetBlock(x,y+1,z) == OrangeWoolBlock::getID() || GetBlock(x,y+1,z) == DarkWoodBlock::getID() || GetBlock(x,y+1,z) == WhiteWoodBlock::getID() || GetBlock(x,y+1,z) == BoxBlock::getID() ||
                        GetBlock(x,y+1,z) == ShelfBlock::getID() || GetBlock(x,y+1,z) == SnowLewesBlock::getID() || GetBlock(x,y+1,z) == JungleWood::getID() || GetBlock(x,y+1,z) == Planks1::getID() || GetBlock(x,y+1,z) == Planks2::getID() || GetBlock(x,y+1,z) == Planks3::getID() ||
                        GetBlock(x,y+1,z) == AetherPlanks::getID() || GetBlock(x,y+1,z) == Crafting::getID() || GetBlock(x,y+1,z) == JungleLeaves::getID() || GetBlock(x,y+1,z) == LeavesBlock::getID())
                        {
                            GetBlock(x,y+1,z) = 0;
                            GetBlock(x,y+1,z) = Fire::getID();
                        }
                    else if(GetBlock(x,y-1,z) == WoodBlock::getID() || GetBlock(x,y-1,z) == LeavesBlock::getID() || GetBlock(x,y-1,z) == TNTBlock::getID() || GetBlock(x,y-1,z) == BlackWoolBlock::getID() ||
                        GetBlock(x,y-1,z) == RedWoolBlock::getID() || GetBlock(x,y-1,z) == DarkGreyWoolBlock::getID() || GetBlock(x,y-1,z) == BrownWoolBlock::getID()  || GetBlock(x,y-1,z) == LightBlackWoolBlock::getID() ||
                        GetBlock(x,y-1,z) == PinkWoolBlock::getID() || GetBlock(x,y-1,z) == LightGreenWoolBlock::getID() || GetBlock(x,y-1,z) == YellowWoolBlock::getID() || GetBlock(x,y-1,z) == BlueWoolBlock::getID() ||
                        GetBlock(x,y-1,z) == LightBlueWoolBlock::getID() || GetBlock(x,y-1,z) == FioletWoolBlock::getID() || GetBlock(x,y-1,z) == PastelWoolBlock::getID() || GetBlock(x,y-1,z) == LightFioletWoolBlock::getID() ||
                        GetBlock(x,y-1,z) == OrangeWoolBlock::getID() || GetBlock(x,y-1,z) == DarkWoodBlock::getID() || GetBlock(x,y-1,z) == WhiteWoodBlock::getID() || GetBlock(x,y-1,z) == BoxBlock::getID() ||
                        GetBlock(x,y-1,z) == ShelfBlock::getID() || GetBlock(x,y-1,z) == SnowLewesBlock::getID() || GetBlock(x,y-1,z) == JungleWood::getID() || GetBlock(x,y-1,z) == Planks1::getID() || GetBlock(x,y-1,z) == Planks2::getID() || GetBlock(x,y-1,z) == Planks3::getID() ||
                        GetBlock(x,y-1,z) == AetherPlanks::getID() || GetBlock(x,y-1,z) == Crafting::getID() || GetBlock(x,y-1,z) == JungleLeaves::getID() || GetBlock(x,y-1,z) == LeavesBlock::getID())
                        {
                            GetBlock(x,y-1,z) = 0;
                            GetBlock(x,y-1,z) = Fire::getID();
                        }
                    else if(GetBlock(x,y-1,z) == 0 || GetBlock(x,y-1,z) == Grass::getID() || GetBlock(x,y-1,z) == Fire::getID() || GetBlock(x,y-1,z) == Sapling1::getID() || GetBlock(x,y-1,z) == Sapling2::getID() || GetBlock(x,y-1,z) == Sapling3::getID() || GetBlock(x,y-1,z) == netherWarp::getID() || GetBlock(x,y-1,z) == wheat::getID() || GetBlock(x,y-1,z) != Netherrack::getID())
                    {
                        GetBlock(x,y,z) = 0;
                    }
                    else if(GetBlock(x,y-1,z) == Netherrack::getID())
                    {
                        GetBlock(x,y,z) = Fire::getID();
                    }
                    else
                    {
                        int random = rand() % 4;

                        if(random == 1)
                        {
                            GetBlock(x,y,z) = 0;
                        }
                    }

                }

                //growing melons
                if(GetBlock(x,y,z) == MelonSeeds::getID())
                {
                    if(GetBlock(x-1,y-1,z) != 4 && GetBlock(x+1,y-1,z) != 4 && GetBlock(x,y-1,z-1) != 4 && GetBlock(x,y-1,z+1) != 4)
                    {
                        GetBlock(x,y,z) = 0;
                    }

                    if(GetBlock(x,y-1,z) == 0)
                    {
                        GetBlock(x,y,z) = 0;
                    }

                    int random = rand() % 40;

                    if(random == 5)
                    {
                        int directory = rand() % 4;

                        if(directory == 0)
                        {
                            if(GetBlock(x+1,y,z) == 0 && GetBlock(x-1,y,z) != MelonBlock::getID() && GetBlock(x,y,z+1) != MelonBlock::getID() && GetBlock(x,y,z-1) != MelonBlock::getID())
                            {
                                if(GetBlock(x+1,y-1,z) != 0 || GetBlock(x+1,y-1,z) != 4)
                                {
                                    GetBlock(x+1,y,z) = MelonBlock::getID();
                                }
                            }
                        }
                        if(directory == 1)
                        {
                            if(GetBlock(x-1,y,z) == 0 && GetBlock(x+1,y,z) != MelonBlock::getID() && GetBlock(x,y,z+1) != MelonBlock::getID() && GetBlock(x,y,z-1) != MelonBlock::getID())
                            {
                                if(GetBlock(x-1,y-1,z) != 0 || GetBlock(x-1,y-1,z) != 0)
                                {
                                    GetBlock(x-1,y,z) = MelonBlock::getID();
                                }
                            }
                        }
                        if(directory == 2)
                        {
                            if(GetBlock(x,y,z+1) == 0 && GetBlock(x,y,z-1) != MelonBlock::getID() && GetBlock(x+1,y,z) != MelonBlock::getID() && GetBlock(x-1,y,z) != MelonBlock::getID())
                            {
                                if(GetBlock(x+1,y-1,z) != 0 || GetBlock(x+1,y-1,z) != 0)
                                {
                                    GetBlock(x,y,z+1) = MelonBlock::getID();
                                }
                            }
                        }
                        if(directory == 3)
                        {
                            if(GetBlock(x,y,z-1) == 0 && GetBlock(x,y,z+1) != MelonBlock::getID() && GetBlock(x+1,y,z) != MelonBlock::getID() && GetBlock(x-1,y,z) != MelonBlock::getID())
                            {
                                if(GetBlock(x,y-1,z-1) != 0 || GetBlock(x,y-1,z-1) != 0)
                                {
                                    GetBlock(x,y,z-1) = MelonBlock::getID();
                                }
                            }
                        }
                    }
                }

                if(GetBlock(x,y,z) == CaneBlock::getID())
                {
                    if(GetBlock(x,y+1,z) == 0)
                    {
                        int random = rand() % 40;
                        if(random == 5)
                        {
                            if(GetBlock(x,y-3,z) != CaneBlock::getID())
                            {
                                GetBlock(x,y+1,z) = CaneBlock::getID();
                            }
                        }
                    }
                    if(GetBlock(x,y-1,z) == 0)
                    {
                        GetBlock(x,y,z) = 0;
                    }
                }

                if(GetBlock(x,y,z) == CactusBlock::getID())
                {
                    if(GetBlock(x,y+1,z) == 0)
                    {
                        int random = rand() % 40;
                        if(random == 5)
                        {
                            if(GetBlock(x,y-3,z) != CactusBlock::getID())
                            {
                                GetBlock(x,y+1,z) = CactusBlock::getID();
                            }
                        }
                    }
                    if(GetBlock(x,y-1,z) == 0)
                    {
                        GetBlock(x,y,z) = 0;
                    }
                }

                if(GetBlock(x,y,z) == Grass::getID())
                {
                    if(GetBlock(x,y-1,z) == 0)
                    {
                        GetBlock(x,y,z) = 0;
                    }
                }

                if(GetBlock(x,y,z) == 1 && GetBlock(x,y+1,z) == Snow2::getID())
                {
                    GetBlock(x,y,z) = 29;
                }

                if(GetBlockLight(x,y-1,z)>=128)
                {
                    int random = rand() % 40;

                    if(random == 5)
                    {
                        //growing grass
                        if(GetBlock(x,y,z) == 1)
                        {
                            if(GetBlock(x,y+1,z) == Snow2::getID())
                            {
                                GetBlock(x,y,z) = 29;
                            }

                            if(GetBlock(x,y+1,z) != Grass::getID() && GetBlock(x,y+1,z) != 0 && GetBlock(x,y+1,z) != Snow2::getID() && GetBlock(x,y+1,z) != NetherFence::getID() && GetBlock(x,y+1,z) != Fence::getID() && GetBlock(x,y+1,z) != LadderBlock::getID() && GetBlock(x,y+1,z) != Torch::getID() && GetBlock(x,y+1,z) != wines::getID() && GetBlock(x,y+1,z) != Sapling1::getID() && GetBlock(x,y+1,z) != Sapling2::getID() && GetBlock(x,y+1,z) != Sapling3::getID())
                            {
                                GetBlock(x,y,z) = 2;
                            }

                            if(GetBlock(x-1,y,z) == 2 && GetBlock(x-1,y+1,z) == 0)
                            {
                                GetBlock(x-1,y,z) = 1;
                            }
                            if(GetBlock(x+1,y,z) == 2 && GetBlock(x+1,y+1,z) == 0)
                            {
                                GetBlock(x+1,y,z) = 1;
                            }
                            if(GetBlock(x,y,z-1) == 2 && GetBlock(x,y+1,z-1) == 0)
                            {
                                GetBlock(x,y,z-1) = 1;
                            }
                            if(GetBlock(x,y,z+1) == 2 && GetBlock(x,y+1,z+1) == 0)
                            {
                                GetBlock(x,y,z+1) = 1;
                            }

                            if(GetBlock(x-1,y+1,z) == 2 && GetBlock(x-1,y+2,z) == 0)
                            {
                                GetBlock(x-1,y+1,z) = 1;
                            }
                            if(GetBlock(x+1,y+1,z) == 2 && GetBlock(x+1,y+2,z) == 0)
                            {
                                GetBlock(x+1,y+1,z) = 1;
                            }
                            if(GetBlock(x,y+1,z-1) == 2 && GetBlock(x,y+2,z-1) == 0)
                            {
                                GetBlock(x,y+1,z-1) = 1;
                            }
                            if(GetBlock(x,y+1,z+1) == 2 && GetBlock(x,y+2,z+1) == 0)
                            {
                                GetBlock(x,y+1,z+1) = 1;
                            }

                            if(GetBlock(x-1,y-1,z) == 2 && GetBlock(x-1,y,z) == 0)
                            {
                                GetBlock(x-1,y-1,z) = 1;
                            }
                            if(GetBlock(x+1,y-1,z) == 2 && GetBlock(x+1,y,z) == 0)
                            {
                                GetBlock(x+1,y-1,z) = 1;
                            }
                            if(GetBlock(x,y-1,z-1) == 2 && GetBlock(x,y,z-1) == 0)
                            {
                                GetBlock(x,y-1,z-1) = 1;
                            }
                            if(GetBlock(x,y-1,z+1) == 2 && GetBlock(x,y,z+1) == 0)
                            {
                                GetBlock(x,y-1,z+1) = 1;
                            }
                        }

                        if(GetBlock(x,y,z) == 29)
                        {
                            if(GetBlock(x,y+1,z) != Grass::getID() && GetBlock(x,y+1,z) != 0 && GetBlock(x,y+1,z) != Snow2::getID() && GetBlock(x,y+1,z) != NetherFence::getID() && GetBlock(x,y+1,z) != Fence::getID() && GetBlock(x,y+1,z) != LadderBlock::getID() && GetBlock(x,y+1,z) != Torch::getID() && GetBlock(x,y+1,z) != wines::getID() && GetBlock(x,y+1,z) != Sapling1::getID() && GetBlock(x,y+1,z) != Sapling2::getID() && GetBlock(x,y+1,z) != Sapling3::getID())
                            {
                                GetBlock(x,y,z) = 2;
                            }

                            if(GetBlock(x-1,y,z) == 2 && GetBlock(x-1,y+1,z) == 0)
                            {
                                GetBlock(x-1,y,z) = 29;
                            }
                            if(GetBlock(x+1,y,z) == 2 && GetBlock(x+1,y+1,z) == 0)
                            {
                                GetBlock(x+1,y,z) = 29;
                            }
                            if(GetBlock(x,y,z-1) == 2 && GetBlock(x,y+1,z-1) == 0)
                            {
                                GetBlock(x,y,z-1) = 29;
                            }
                            if(GetBlock(x,y,z+1) == 2 && GetBlock(x,y+1,z+1) == 0)
                            {
                                GetBlock(x,y,z+1) = 29;
                            }

                            if(GetBlock(x-1,y+1,z) == 2 && GetBlock(x-1,y+2,z) == 0)
                            {
                                GetBlock(x-1,y+1,z) = 29;
                            }
                            if(GetBlock(x+1,y+1,z) == 2 && GetBlock(x+1,y+2,z) == 0)
                            {
                                GetBlock(x+1,y+1,z) = 29;
                            }
                            if(GetBlock(x,y+1,z-1) == 2 && GetBlock(x,y+2,z-1) == 0)
                            {
                                GetBlock(x,y+1,z-1) = 29;
                            }
                            if(GetBlock(x,y+1,z+1) == 2 && GetBlock(x,y+2,z+1) == 0)
                            {
                                GetBlock(x,y+1,z+1) = 29;
                            }

                            if(GetBlock(x-1,y-1,z) == 2 && GetBlock(x-1,y,z) == 0)
                            {
                                GetBlock(x-1,y-1,z) = 29;
                            }
                            if(GetBlock(x+1,y-1,z) == 2 && GetBlock(x+1,y,z) == 0)
                            {
                                GetBlock(x+1,y-1,z) = 29;
                            }
                            if(GetBlock(x,y-1,z-1) == 2 && GetBlock(x,y,z-1) == 0)
                            {
                                GetBlock(x,y-1,z-1) = 29;
                            }
                            if(GetBlock(x,y-1,z+1) == 2 && GetBlock(x,y,z+1) == 0)
                            {
                                GetBlock(x,y-1,z+1) = 29;
                            }
                        }

                        if(GetBlock(x,y,z) == Mycelium::getID())
                        {
                            if(GetBlock(x,y+1,z) != Grass::getID() && GetBlock(x,y+1,z) != 0 && GetBlock(x,y+1,z) != Snow2::getID() && GetBlock(x,y+1,z) != NetherFence::getID() && GetBlock(x,y+1,z) != Fence::getID() && GetBlock(x,y+1,z) != LadderBlock::getID() && GetBlock(x,y+1,z) != Torch::getID() && GetBlock(x,y+1,z) != wines::getID() && GetBlock(x,y+1,z) != Sapling1::getID() && GetBlock(x,y+1,z) != Sapling2::getID() && GetBlock(x,y+1,z) != Sapling3::getID())
                            {
                                GetBlock(x,y,z) = 2;
                            }

                            if(GetBlock(x-1,y,z) == 2 && GetBlock(x-1,y+1,z) == 0)
                            {
                                GetBlock(x-1,y,z) = Mycelium::getID();
                            }
                            if(GetBlock(x+1,y,z) == 2 && GetBlock(x+1,y+1,z) == 0)
                            {
                                GetBlock(x+1,y,z) = Mycelium::getID();
                            }
                            if(GetBlock(x,y,z-1) == 2 && GetBlock(x,y+1,z-1) == 0)
                            {
                                GetBlock(x,y,z-1) = Mycelium::getID();
                            }
                            if(GetBlock(x,y,z+1) == 2 && GetBlock(x,y+1,z+1) == 0)
                            {
                                GetBlock(x,y,z+1) = Mycelium::getID();
                            }

                            if(GetBlock(x-1,y+1,z) == 2 && GetBlock(x-1,y+2,z) == 0)
                            {
                                GetBlock(x-1,y+1,z) = Mycelium::getID();
                            }
                            if(GetBlock(x+1,y+1,z) == 2 && GetBlock(x+1,y+2,z) == 0)
                            {
                                GetBlock(x+1,y+1,z) = Mycelium::getID();
                            }
                            if(GetBlock(x,y+1,z-1) == 2 && GetBlock(x,y+2,z-1) == 0)
                            {
                                GetBlock(x,y+1,z-1) = Mycelium::getID();
                            }
                            if(GetBlock(x,y+1,z+1) == 2 && GetBlock(x,y+2,z+1) == 0)
                            {
                                GetBlock(x,y+1,z+1) = Mycelium::getID();
                            }

                            if(GetBlock(x-1,y-1,z) == 2 && GetBlock(x-1,y,z) == 0)
                            {
                                GetBlock(x-1,y-1,z) = Mycelium::getID();
                            }
                            if(GetBlock(x+1,y-1,z) == 2 && GetBlock(x+1,y,z) == 0)
                            {
                                GetBlock(x+1,y-1,z) = Mycelium::getID();
                            }
                            if(GetBlock(x,y-1,z-1) == 2 && GetBlock(x,y,z-1) == 0)
                            {
                                GetBlock(x,y-1,z-1) = Mycelium::getID();
                            }
                            if(GetBlock(x,y-1,z+1) == 2 && GetBlock(x,y,z+1) == 0)
                            {
                                GetBlock(x,y-1,z+1) = Mycelium::getID();
                            }
                        }
                    }
                }


                if(worldDayTime >= 5.0f && worldDayTime < 21.0f)
                {
                    if(GetBlockLight(x,y-1,z) > 128)
                    {
                        if(GetBlock(x,y,z) == ZombieLegs::getID() && GetBlock(x,y+1,z) == ZombieTop::getID())
                        {
                            player.NumMobs -= 1;
                            GetBlock(x,y,z) = 0;
                            GetBlock(x,y+1,z) = 0;
                        }

                        if(GetBlock(x,y,z) == EnderLegs::getID() && GetBlock(x,y+1,z) == EnderTop::getID())
                        {
                            player.NumMobs -= 1;
                            GetBlock(x,y,z) = 0;
                            GetBlock(x,y+1,z) = 0;
                        }
                    }
                }
            }
        }
    }
}

void CraftWorld::RemoveMobs(int id)
{
    SimpleMeshChunk* MeshChunk = mChunks[id];

    int StartZ = MeshChunk->chunkStartZ;
    int StartY = MeshChunk->chunkStartY;
    int StartX = MeshChunk->chunkStartX;

    for (int z = StartZ; z < CHUNK_SIZE + StartZ; ++z)
    {
        for (int y = StartY; y < CHUNK_SIZE + StartY; ++y)
        {
            for (int x = StartX; x < CHUNK_SIZE + StartX; ++x)
            {
                if(GetBlock(x,y,z) == ZombieLegs::getID() && GetBlock(x,y+1,z) == ZombieTop::getID())
                {
                    player.NumMobs -= 1;
                    GetBlock(x,y,z) = 0;
                    GetBlock(x,y+1,z) = 0;
                }

                if(GetBlock(x,y,z) == EnderLegs::getID() && GetBlock(x,y+1,z) == EnderTop::getID())
                {
                    player.NumMobs -= 1;
                    GetBlock(x,y,z) = 0;
                    GetBlock(x,y+1,z) = 0;
                }
            }
        }
    }
}

void CraftWorld::SpawnMobs(int id)
{
    SimpleMeshChunk* MeshChunk = mChunks[id];

    int StartZ = MeshChunk->chunkStartZ;
    int StartY = MeshChunk->chunkStartY;
    int StartX = MeshChunk->chunkStartX;

    for (int z = StartZ; z < CHUNK_SIZE + StartZ; ++z)
    {
        for (int y = StartY; y < CHUNK_SIZE + StartY; ++y)
        {
            for (int x = StartX; x < CHUNK_SIZE + StartX; ++x)
            {
                if(GetBlock(x,y-1,z) != JungleWood::getID() && GetBlock(x,y-1,z) != WhiteWoodBlock::getID() && GetBlock(x,y-1,z) != DarkWoodBlock::getID() && GetBlock(x,y-1,z) != WoodBlock::getID() && GetBlock(x,y-1,z) != ShelfBlock::getID() && GetBlock(x,y-1,z) != GlassBlock::getID() && GetBlock(x,y-1,z) != Lava::getID() && GetBlock(x,y-1,z) != WaterBlock::getID() && GetBlock(x,y-1,z) != StoneBrick4::getID() && GetBlock(x,y-1,z) != StoneBrick3::getID() && GetBlock(x,y-1,z) != StoneBrick2::getID() && GetBlock(x,y-1,z) != StoneBrick1::getID() && GetBlock(x,y-1,z) != Planks3::getID() && GetBlock(x,y-1,z) != Planks2::getID() && GetBlock(x,y-1,z) != Planks1::getID() && GetBlock(x,y-1,z) != BoxBlock::getID() && GetBlock(x,y,z) == 0 && GetBlock(x,y-1,z) != BlackWoolBlock::getID() && GetBlock(x,y+1,z) == 0 && GetBlock(x,y-1,z) != 0 && GetBlock(x,y-1,z) != Cloud::getID() && GetBlock(x,y-1,z) != LightGreenWoolBlock::getID())
                {
                    if(player.NumMobs <= 50)
                    {
                        int random = rand() % 120;

                        if(random == 2)
                        {
                            int randomMob = rand()% 2;

                            if(randomMob == 0)
                            {
                                if(worldDayTime >= 5.0f && worldDayTime < 21.0f)
                                {
                                    if(GetBlockLight(x,y-1,z) < 128)
                                    {
                                        player.NumMobs += 1;
                                        GetBlock(x,y,z) = ZombieLegs::getID();
                                        GetBlock(x,y+1,z) = ZombieTop::getID();
                                    }
                                }
                                else
                                {
                                    player.NumMobs += 1;
                                    GetBlock(x,y,z) = ZombieLegs::getID();
                                    GetBlock(x,y+1,z) = ZombieTop::getID();
                                }
                            }
                            if(randomMob == 1)
                            {
                                if(worldDayTime >= 5.0f && worldDayTime < 21.0f)
                                {
                                    if(GetBlockLight(x,y-1,z) < 128)
                                    {
                                        player.NumMobs += 1;
                                        GetBlock(x,y,z) = EnderLegs::getID();
                                        GetBlock(x,y+1,z) = EnderTop::getID();
                                    }
                                }
                                else
                                {
                                    player.NumMobs += 1;
                                    GetBlock(x,y,z) = EnderLegs::getID();
                                    GetBlock(x,y+1,z) = EnderTop::getID();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void CraftWorld::UpdateAnimalPos(int id)
{
    SimpleMeshChunk* MeshChunk = mChunks[id];

    int StartZ = MeshChunk->chunkStartZ;
    int StartY = MeshChunk->chunkStartY;
    int StartX = MeshChunk->chunkStartX;

    for (int z = StartZ; z < CHUNK_SIZE + StartZ; ++z)
    {
        for (int y = StartY; y < CHUNK_SIZE + StartY; ++y)
        {
            for (int x = StartX; x < CHUNK_SIZE + StartX; ++x)
            {
                if(GetBlock(x,y,z) == Pumpkin::getID() && GetBlock(x,y-1,z) == AllSnowBlock::getID())
                {
                    if(GetBlock(x,y-2,z) != 0)
                    {
                        int randomMove = rand() % 4;

                        if(randomMove == 0)
                        {
                            if((GetBlock(x-1,y,z) == 0 || GetBlock(x-1,y,z) == Snow2::getID()) && GetBlock(x-1,y+1,z) == 0 && (GetBlock(x-1,y-1,z) != 0 && GetBlock(x-1,y-1,z) != Snow2::getID()))
                            {
                                if(GetBlock(x,y-2,z) == 4 || GetBlock(x,y-2,z) == WaterFlow::getID())
                                {
                                    GetBlock(x,y-2,z) = IceBlock::getID();
                                }

                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = Snow2::getID();
                                GetBlock(x-1,y,z) = AllSnowBlock::getID();
                                GetBlock(x-1,y+1,z) = Pumpkin::getID();
                            }
                            else if(GetBlock(x-1,y,z) == 0 && (GetBlock(x-1,y-1,z) == 0 || GetBlock(x-1,y-1,z) == Snow2::getID()) && (GetBlock(x-1,y-2,z) != 0 && GetBlock(x-1,y-2,z) != Snow2::getID()))
                            {
                                if(GetBlock(x,y-2,z) == 4 || GetBlock(x,y-2,z) == WaterFlow::getID())
                                {
                                    GetBlock(x,y-2,z) = IceBlock::getID();
                                }

                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = Snow2::getID();
                                GetBlock(x-1,y,z) = Pumpkin::getID();
                                GetBlock(x-1,y-1,z) = AllSnowBlock::getID();
                            }
                            else if(GetBlock(x-1,y-1,z) == 0 && (GetBlock(x-1,y-2,z) == 0 || GetBlock(x-1,y-2,z) == Snow2::getID()) && (GetBlock(x-1,y-3,z) != 0 && GetBlock(x-1,y-3,z) != Snow2::getID()))
                            {
                                if(GetBlock(x,y-2,z) == 4 || GetBlock(x,y-2,z) == WaterFlow::getID())
                                {
                                    GetBlock(x,y-2,z) = IceBlock::getID();
                                }

                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = Snow2::getID();
                                GetBlock(x-1,y-1,z) = Pumpkin::getID();
                                GetBlock(x-1,y-2,z) = AllSnowBlock::getID();
                            }
                        }

                        if(randomMove == 1)
                        {
                            if((GetBlock(x+1,y,z) == 0 || GetBlock(x+1,y,z) == Snow2::getID()) && GetBlock(x+1,y+1,z) == 0 && (GetBlock(x+1,y-1,z) != 0 && GetBlock(x+1,y-1,z) != Snow2::getID()))
                            {
                                if(GetBlock(x,y-2,z) == 4 || GetBlock(x,y-2,z) == WaterFlow::getID())
                                {
                                    GetBlock(x,y-2,z) = IceBlock::getID();
                                }

                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = Snow2::getID();
                                GetBlock(x+1,y,z) = AllSnowBlock::getID();
                                GetBlock(x+1,y+1,z) = Pumpkin::getID();
                            }
                            else if(GetBlock(x+1,y,z) == 0 && (GetBlock(x+1,y-1,z) == 0 || GetBlock(x+1,y-1,z) == Snow2::getID()) && (GetBlock(x+1,y-2,z) != 0 && GetBlock(x+1,y-2,z) != Snow2::getID()))
                            {
                                if(GetBlock(x,y-2,z) == 4 || GetBlock(x,y-2,z) == WaterFlow::getID())
                                {
                                    GetBlock(x,y-2,z) = IceBlock::getID();
                                }

                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = Snow2::getID();
                                GetBlock(x+1,y,z) = Pumpkin::getID();
                                GetBlock(x+1,y-1,z) = AllSnowBlock::getID();
                            }
                            else if(GetBlock(x+1,y-1,z) == 0 && (GetBlock(x+1,y-2,z) == 0 || GetBlock(x+1,y-2,z) == Snow2::getID()) && (GetBlock(x+1,y-3,z) != 0 && GetBlock(x+1,y-3,z) != Snow2::getID()))
                            {
                                if(GetBlock(x,y-2,z) == 4 || GetBlock(x,y-2,z) == WaterFlow::getID())
                                {
                                    GetBlock(x,y-2,z) = IceBlock::getID();
                                }

                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = Snow2::getID();
                                GetBlock(x+1,y-1,z) = Pumpkin::getID();
                                GetBlock(x+1,y-2,z) = AllSnowBlock::getID();
                            }
                        }

                        if(randomMove == 2)
                        {
                            if((GetBlock(x,y,z-1) == 0 || GetBlock(x,y,z-1) == Snow2::getID()) && GetBlock(x,y+1,z-1) == 0 && (GetBlock(x,y-1,z-1) != 0 && GetBlock(x,y-1,z-1) != Snow2::getID()))
                            {
                                if(GetBlock(x,y-2,z) == 4 || GetBlock(x,y-2,z) == WaterFlow::getID())
                                {
                                    GetBlock(x,y-2,z) = IceBlock::getID();
                                }

                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = Snow2::getID();
                                GetBlock(x,y,z-1) = AllSnowBlock::getID();
                                GetBlock(x,y+1,z-1) = Pumpkin::getID();
                            }
                            else if(GetBlock(x,y,z-1) == 0 && (GetBlock(x,y-1,z-1) == 0 || GetBlock(x,y-1,z-1) == Snow2::getID()) && (GetBlock(x,y-2,z-1) != 0 && GetBlock(x,y-2,z-1) != Snow2::getID()))
                            {
                                if(GetBlock(x,y-2,z) == 4 || GetBlock(x,y-2,z) == WaterFlow::getID())
                                {
                                    GetBlock(x,y-2,z) = IceBlock::getID();
                                }

                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = Snow2::getID();
                                GetBlock(x,y,z-1) = Pumpkin::getID();
                                GetBlock(x,y-1,z-1) = AllSnowBlock::getID();
                            }
                            else if(GetBlock(x,y-1,z-1) == 0 && (GetBlock(x,y-2,z-1) == 0 || GetBlock(x,y-2,z-1) == Snow2::getID()) && (GetBlock(x,y-3,z-1) != 0 && GetBlock(x,y-3,z-1) != Snow2::getID()))
                            {
                                if(GetBlock(x,y-2,z) == 4 || GetBlock(x,y-2,z) == WaterFlow::getID())
                                {
                                    GetBlock(x,y-2,z) = IceBlock::getID();
                                }

                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = Snow2::getID();
                                GetBlock(x,y-1,z-1) = Pumpkin::getID();
                                GetBlock(x,y-2,z-1) = AllSnowBlock::getID();
                            }
                        }

                        if(randomMove == 3)
                        {
                            if((GetBlock(x,y,z+1) == 0 || GetBlock(x,y,z+1) == Snow2::getID()) && GetBlock(x,y+1,z+1) == 0 && (GetBlock(x,y-1,z+1) != 0 && GetBlock(x,y-1,z+1) != Snow2::getID()))
                            {
                                if(GetBlock(x,y-2,z) == 4 || GetBlock(x,y-2,z) == WaterFlow::getID())
                                {
                                    GetBlock(x,y-2,z) = IceBlock::getID();
                                }

                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = Snow2::getID();
                                GetBlock(x,y,z+1) = AllSnowBlock::getID();
                                GetBlock(x,y+1,z+1) = Pumpkin::getID();
                            }
                            else if(GetBlock(x,y,z+1) == 0 && (GetBlock(x,y-1,z+1) == 0 || GetBlock(x,y-1,z+1) == Snow2::getID()) && (GetBlock(x,y-2,z+1) != 0 && GetBlock(x,y-2,z+1) != Snow2::getID()))
                            {
                                if(GetBlock(x,y-2,z) == 4 || GetBlock(x,y-2,z) == WaterFlow::getID())
                                {
                                    GetBlock(x,y-2,z) = IceBlock::getID();
                                }

                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = Snow2::getID();
                                GetBlock(x,y,z+1) = Pumpkin::getID();
                                GetBlock(x,y-1,z+1) = AllSnowBlock::getID();
                            }
                            else if(GetBlock(x,y-1,z+1) == 0 && (GetBlock(x,y-2,z+1) == 0 || GetBlock(x,y-2,z+1) == Snow2::getID()) && (GetBlock(x,y-3,z+1) != 0 && GetBlock(x,y-3,z+1) != Snow2::getID()))
                            {
                                if(GetBlock(x,y-2,z) == 4 || GetBlock(x,y-2,z) == WaterFlow::getID())
                                {
                                    GetBlock(x,y-2,z) = IceBlock::getID();
                                }

                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = Snow2::getID();
                                GetBlock(x,y-1,z+1) = Pumpkin::getID();
                                GetBlock(x,y-2,z+1) = AllSnowBlock::getID();
                            }
                        }
                    }
                    else if(GetBlock(x,y-2,z) == 0 || GetBlock(x,y-2,z) == Snow2::getID())
                    {
                        GetBlock(x,y-1,z) = Pumpkin::getID();
                        GetBlock(x,y-2,z) = AllSnowBlock::getID();
                        GetBlock(x,y,z) = 0;
                    }
                }
            }
        }
    }
}

void CraftWorld::UpdateMobPos(int id)
{
    SimpleMeshChunk* MeshChunk = mChunks[id];

    int StartZ = MeshChunk->chunkStartZ;
    int StartY = MeshChunk->chunkStartY;
    int StartX = MeshChunk->chunkStartX;

    for (int z = StartZ; z < CHUNK_SIZE + StartZ; ++z)
    {
        for (int y = StartY; y < CHUNK_SIZE + StartY; ++y)
        {
            for (int x = StartX; x < CHUNK_SIZE + StartX; ++x)
            {
                //enderman
                if(GetBlock(x,y,z) == EnderTop::getID() && GetBlock(x,y-1,z) == EnderLegs::getID())
                {
                    if(GetBlock(x,y-2,z) != 0)
                    {
                        int randomMove = rand() % 4;

                        if(randomMove == 0)
                        {
                            if((GetBlock(x-1,y,z) == 0 || GetBlock(x-1,y,z) == Snow2::getID()) && GetBlock(x-1,y+1,z) == 0 && (GetBlock(x-1,y-1,z) != 0 && GetBlock(x-1,y-1,z) != Snow2::getID()))
                            {
                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x-1,y,z) = EnderLegs::getID();
                                GetBlock(x-1,y+1,z) = EnderTop::getID();
                            }
                            else if(GetBlock(x-1,y,z) == 0 && (GetBlock(x-1,y-1,z) == 0 || GetBlock(x-1,y-1,z) == Snow2::getID()) && (GetBlock(x-1,y-2,z) != 0 && GetBlock(x-1,y-2,z) != Snow2::getID()))
                            {

                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x-1,y,z) = EnderTop::getID();
                                GetBlock(x-1,y-1,z) = EnderLegs::getID();
                            }
                            else if(GetBlock(x-1,y-1,z) == 0 && (GetBlock(x-1,y-2,z) == 0 || GetBlock(x-1,y-2,z) == Snow2::getID()) && (GetBlock(x-1,y-3,z) != 0 && GetBlock(x-1,y-3,z) != Snow2::getID()))
                            {

                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x-1,y-1,z) = EnderTop::getID();
                                GetBlock(x-1,y-2,z) = EnderLegs::getID();
                            }
                        }

                        if(randomMove == 1)
                        {
                            if((GetBlock(x+1,y,z) == 0 || GetBlock(x+1,y,z) == Snow2::getID()) && GetBlock(x+1,y+1,z) == 0 && (GetBlock(x+1,y-1,z) != 0 && GetBlock(x+1,y-1,z) != Snow2::getID()))
                            {


                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x+1,y,z) = EnderLegs::getID();
                                GetBlock(x+1,y+1,z) = EnderTop::getID();
                            }
                            else if(GetBlock(x+1,y,z) == 0 && (GetBlock(x+1,y-1,z) == 0 || GetBlock(x+1,y-1,z) == Snow2::getID()) && (GetBlock(x+1,y-2,z) != 0 && GetBlock(x+1,y-2,z) != Snow2::getID()))
                            {


                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x+1,y,z) = EnderTop::getID();
                                GetBlock(x+1,y-1,z) = EnderLegs::getID();
                            }
                            else if(GetBlock(x+1,y-1,z) == 0 && (GetBlock(x+1,y-2,z) == 0 || GetBlock(x+1,y-2,z) == Snow2::getID()) && (GetBlock(x+1,y-3,z) != 0 && GetBlock(x+1,y-3,z) != Snow2::getID()))
                            {


                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x+1,y-1,z) = EnderTop::getID();
                                GetBlock(x+1,y-2,z) = EnderLegs::getID();
                            }
                        }

                        if(randomMove == 2)
                        {
                            if((GetBlock(x,y,z-1) == 0 || GetBlock(x,y,z-1) == Snow2::getID()) && GetBlock(x,y+1,z-1) == 0 && (GetBlock(x,y-1,z-1) != 0 && GetBlock(x,y-1,z-1) != Snow2::getID()))
                            {
                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x,y,z-1) = EnderLegs::getID();
                                GetBlock(x,y+1,z-1) = EnderTop::getID();
                            }
                            else if(GetBlock(x,y,z-1) == 0 && (GetBlock(x,y-1,z-1) == 0 || GetBlock(x,y-1,z-1) == Snow2::getID()) && (GetBlock(x,y-2,z-1) != 0 && GetBlock(x,y-2,z-1) != Snow2::getID()))
                            {

                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x,y,z-1) = EnderTop::getID();
                                GetBlock(x,y-1,z-1) = EnderLegs::getID();
                            }
                            else if(GetBlock(x,y-1,z-1) == 0 && (GetBlock(x,y-2,z-1) == 0 || GetBlock(x,y-2,z-1) == Snow2::getID()) && (GetBlock(x,y-3,z-1) != 0 && GetBlock(x,y-3,z-1) != Snow2::getID()))
                            {


                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x,y-1,z-1) = EnderTop::getID();
                                GetBlock(x,y-2,z-1) = EnderLegs::getID();
                            }
                        }

                        if(randomMove == 3)
                        {
                            if((GetBlock(x,y,z+1) == 0 || GetBlock(x,y,z+1) == Snow2::getID()) && GetBlock(x,y+1,z+1) == 0 && (GetBlock(x,y-1,z+1) != 0 && GetBlock(x,y-1,z+1) != Snow2::getID()))
                            {


                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x,y,z+1) = EnderLegs::getID();
                                GetBlock(x,y+1,z+1) = EnderTop::getID();
                            }
                            else if(GetBlock(x,y,z+1) == 0 && (GetBlock(x,y-1,z+1) == 0 || GetBlock(x,y-1,z+1) == Snow2::getID()) && (GetBlock(x,y-2,z+1) != 0 && GetBlock(x,y-2,z+1) != Snow2::getID()))
                            {


                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x,y,z+1) = EnderTop::getID();
                                GetBlock(x,y-1,z+1) = EnderLegs::getID();
                            }
                            else if(GetBlock(x,y-1,z+1) == 0 && (GetBlock(x,y-2,z+1) == 0 || GetBlock(x,y-2,z+1) == Snow2::getID()) && (GetBlock(x,y-3,z+1) != 0 && GetBlock(x,y-3,z+1) != Snow2::getID()))
                            {


                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x,y-1,z+1) = EnderTop::getID();
                                GetBlock(x,y-2,z+1) = EnderLegs::getID();
                            }
                        }
                    }
                    else if(GetBlock(x,y-2,z) == 0 || GetBlock(x,y-2,z) == Snow2::getID())
                    {
                        GetBlock(x,y-1,z) = EnderTop::getID();
                        GetBlock(x,y-2,z) = EnderLegs::getID();
                        GetBlock(x,y,z) = 0;
                    }
                }

                //zombie
                if(GetBlock(x,y,z) == ZombieTop::getID() && GetBlock(x,y-1,z) == ZombieLegs::getID())
                {
                    if(GetBlock(x,y-2,z) != 0) //if on ground
                    {
                        int randomMove = rand() % 4;

                        if(randomMove == 0)
                        {
                            if((GetBlock(x-1,y,z) == 0 || GetBlock(x-1,y,z) == Snow2::getID()) && GetBlock(x-1,y+1,z) == 0 && (GetBlock(x-1,y-1,z) != 0 && GetBlock(x-1,y-1,z) != Snow2::getID()))
                            {
                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x-1,y,z) = ZombieLegs::getID();
                                GetBlock(x-1,y+1,z) = ZombieTop::getID();
                            }
                            else if(GetBlock(x-1,y,z) == 0 && (GetBlock(x-1,y-1,z) == 0 || GetBlock(x-1,y-1,z) == Snow2::getID()) && (GetBlock(x-1,y-2,z) != 0 && GetBlock(x-1,y-2,z) != Snow2::getID()))
                            {

                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x-1,y,z) = ZombieTop::getID();
                                GetBlock(x-1,y-1,z) = ZombieLegs::getID();
                            }
                            else if(GetBlock(x-1,y-1,z) == 0 && (GetBlock(x-1,y-2,z) == 0 || GetBlock(x-1,y-2,z) == Snow2::getID()) && (GetBlock(x-1,y-3,z) != 0 && GetBlock(x-1,y-3,z) != Snow2::getID()))
                            {

                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x-1,y-1,z) = ZombieTop::getID();
                                GetBlock(x-1,y-2,z) = ZombieLegs::getID();
                            }
                        }

                        if(randomMove == 1)
                        {
                            if((GetBlock(x+1,y,z) == 0 || GetBlock(x+1,y,z) == Snow2::getID()) && GetBlock(x+1,y+1,z) == 0 && (GetBlock(x+1,y-1,z) != 0 && GetBlock(x+1,y-1,z) != Snow2::getID()))
                            {


                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x+1,y,z) = ZombieLegs::getID();
                                GetBlock(x+1,y+1,z) = ZombieTop::getID();
                            }
                            else if(GetBlock(x+1,y,z) == 0 && (GetBlock(x+1,y-1,z) == 0 || GetBlock(x+1,y-1,z) == Snow2::getID()) && (GetBlock(x+1,y-2,z) != 0 && GetBlock(x+1,y-2,z) != Snow2::getID()))
                            {


                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x+1,y,z) = ZombieTop::getID();
                                GetBlock(x+1,y-1,z) = ZombieLegs::getID();
                            }
                            else if(GetBlock(x+1,y-1,z) == 0 && (GetBlock(x+1,y-2,z) == 0 || GetBlock(x+1,y-2,z) == Snow2::getID()) && (GetBlock(x+1,y-3,z) != 0 && GetBlock(x+1,y-3,z) != Snow2::getID()))
                            {


                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x+1,y-1,z) = ZombieTop::getID();
                                GetBlock(x+1,y-2,z) = ZombieLegs::getID();
                            }
                        }

                        if(randomMove == 2)
                        {
                            if((GetBlock(x,y,z-1) == 0 || GetBlock(x,y,z-1) == Snow2::getID()) && GetBlock(x,y+1,z-1) == 0 && (GetBlock(x,y-1,z-1) != 0 && GetBlock(x,y-1,z-1) != Snow2::getID()))
                            {
                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x,y,z-1) = ZombieLegs::getID();
                                GetBlock(x,y+1,z-1) = ZombieTop::getID();
                            }
                            else if(GetBlock(x,y,z-1) == 0 && (GetBlock(x,y-1,z-1) == 0 || GetBlock(x,y-1,z-1) == Snow2::getID()) && (GetBlock(x,y-2,z-1) != 0 && GetBlock(x,y-2,z-1) != Snow2::getID()))
                            {

                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x,y,z-1) = ZombieTop::getID();
                                GetBlock(x,y-1,z-1) = ZombieLegs::getID();
                            }
                            else if(GetBlock(x,y-1,z-1) == 0 && (GetBlock(x,y-2,z-1) == 0 || GetBlock(x,y-2,z-1) == Snow2::getID()) && (GetBlock(x,y-3,z-1) != 0 && GetBlock(x,y-3,z-1) != Snow2::getID()))
                            {


                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x,y-1,z-1) = ZombieTop::getID();
                                GetBlock(x,y-2,z-1) = ZombieLegs::getID();
                            }
                        }

                        if(randomMove == 3)
                        {
                            if((GetBlock(x,y,z+1) == 0 || GetBlock(x,y,z+1) == Snow2::getID()) && GetBlock(x,y+1,z+1) == 0 && (GetBlock(x,y-1,z+1) != 0 && GetBlock(x,y-1,z+1) != Snow2::getID()))
                            {


                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x,y,z+1) = ZombieLegs::getID();
                                GetBlock(x,y+1,z+1) = ZombieTop::getID();
                            }
                            else if(GetBlock(x,y,z+1) == 0 && (GetBlock(x,y-1,z+1) == 0 || GetBlock(x,y-1,z+1) == Snow2::getID()) && (GetBlock(x,y-2,z+1) != 0 && GetBlock(x,y-2,z+1) != Snow2::getID()))
                            {


                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x,y,z+1) = ZombieTop::getID();
                                GetBlock(x,y-1,z+1) = ZombieLegs::getID();
                            }
                            else if(GetBlock(x,y-1,z+1) == 0 && (GetBlock(x,y-2,z+1) == 0 || GetBlock(x,y-2,z+1) == Snow2::getID()) && (GetBlock(x,y-3,z+1) != 0 && GetBlock(x,y-3,z+1) != Snow2::getID()))
                            {


                                GetBlock(x,y,z) = 0;
                                GetBlock(x,y-1,z) = 0;
                                GetBlock(x,y-1,z+1) = ZombieTop::getID();
                                GetBlock(x,y-2,z+1) = ZombieLegs::getID();
                            }
                        }
                    }
                    else if(GetBlock(x,y-2,z) == 0 || GetBlock(x,y-2,z) == Snow2::getID())
                    {
                        GetBlock(x,y-1,z) = ZombieTop::getID();
                        GetBlock(x,y-2,z) = ZombieLegs::getID();
                        GetBlock(x,y,z) = 0;
                    }
                }
            }
        }
    }
}
