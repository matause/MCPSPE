#include "WorldGenerator.h"
#include "CraftWorld2.h"

#include <noisepp/Noise.h>
#include <noisepp/NoiseUtils.h>
#include <noisepp/NoiseBuilders.h>

void WorldGenerator::initRandompMap(int worldSize,int chunkSize, CraftWorld *world)
{
    //inicjuj mape
    int WORLD_SIZE = worldSize;
    int CHUNK_SIZE = chunkSize;

    //srand(time(NULL));
    int seed = rand() % 10000;

    //terrain settings for default terrain
    unsigned char grass = 1;
    unsigned char rock = 3;
    unsigned char dirt = 2;
    unsigned char water = 4;
    unsigned char sandUnderWater = 7;

    int terrainType = rand() % 10;

    if(terrainType == 1)//winter
    {
        grass = 29;
        rock = 3;
        dirt = 2;
        water = 4;
        sandUnderWater = SandBlock::getID();

        for (int z = 0; z < WORLD_SIZE; ++z)
        {
            for (int x = 0; x < WORLD_SIZE; ++x)
            {
                block_t& Block = world->GetBlock(x, 62, z);
                if (Block == 0) Block = 32;
            }
        }
    }

    if(terrainType == 2)//desert
    {
        grass = SandBlock::getID();
        rock = 3;
        dirt = 53;
        water = 0;//there is no water on desert ;)
        sandUnderWater = SandBlock::getID();
    }

    if(terrainType == 3)//MooshRoom
    {
        grass = Mycelium::getID();
        rock = 3;
        dirt = 2;
        water = 4;
        sandUnderWater = SandBlock::getID();
    }

    if(terrainType == 4)//Nether
    {
        grass = Netherrack::getID();
        rock = Netherrack::getID();
        dirt = Netherrack::getID();
        water = Lava::getID();
        sandUnderWater = SoulSand::getID();



        for (int z = 0; z < WORLD_SIZE; ++z)
        {
            for (int x = 0; x < WORLD_SIZE; ++x)
            {
                block_t& Block = world->GetBlock(x,90, z);
                if (Block == 0) Block = Netherrack::getID();
            }
        }



    }

    if(terrainType == 5)//Aether
    {
        grass = 0;
        rock = 0;
        dirt = 0;
        water = 3;
        sandUnderWater = 0;

        for (int z = 0; z < WORLD_SIZE; ++z)
        {
            for (int x = 0; x < WORLD_SIZE; ++x)
            {
                block_t& Block = world->GetBlock(x,62, z);
                if (Block == 0) Block = 1;
            }
        }
    }

    if(terrainType == 6)//NOrmal
    {

        grass = 1;
        rock = 3;
        dirt = 2;
        water = 0;
        sandUnderWater = 7;

    }

    if(terrainType == 7)//Winter
    {

        grass = 29;
        rock = 3;
        dirt = 2;
        water = 0;
        sandUnderWater = 7;
    }

    if(terrainType == 8)//Jungle
    {

        grass = 1;
        rock = 3;
        dirt = 3;
        water = 4;
        sandUnderWater = 1;

    }

    if(terrainType == 9)//Wasteland
    {

        grass = GreyRock::getID();
        rock = 3;
        dirt = GreyRock::getID();
        water = 0;
        sandUnderWater = GreyRock::getID();

    }

    noisepp::PerlinModule perlin;
    perlin.setSeed(seed);
    perlin.setOctaveCount(4);
    perlin.setQuality(noisepp::NOISE_QUALITY_FAST_STD);

    float *data = new float[worldSize * worldSize];

    noisepp::utils::PlaneBuilder2D builder;
    builder.setModule(perlin);
    builder.setSize(worldSize, worldSize);
    if(terrainType == 2)
        builder.setBounds(0.0, 0.0, 2.0, 3.0);
    else if(terrainType == 2)
        builder.setBounds(0.0, 0.0, 0.5, 1.0);
    else if(terrainType == 9)
        builder.setBounds(0.0, 0.0, 1.0, 0.5);
    else if(terrainType == 8)
        builder.setBounds(10.0, 10.0, 20.0, 20.5);
    else
        builder.setBounds(0.0, 0.0, 4.0, 4.0);
    builder.setDestination(data);
    builder.build ();

    //build map
    for (int z = 0; z < WORLD_SIZE; ++z)
    {
        for (int x = 0; x < WORLD_SIZE; ++x)
        {
            int Height  = data[x + z*WORLD_SIZE]* WORLD_SIZE/12 + WORLD_SIZE/2;
            //int Height = m_HeightMap.GetValue(x, z) * WORLD_SIZE/12 + WORLD_SIZE/2;

            for (int y = 0; y < Height; ++y)
            {
                if(y == Height-1)
                    world->GetBlock(x, y, z) = grass;//grass
                else if(y < Height-3)
                    world->GetBlock(x, y, z) = rock;
                else
                    world->GetBlock(x, y, z) = dirt;

            }
        }
    }


    //carve terrain
    /*
    float *data2 = new float[worldSize * worldSize];
    float *data3 = new float[worldSize * worldSize];

    perlin.setSeed(seed+1);
    noisepp::utils::PlaneBuilder2D builder2;
    builder2.setModule(perlin);
    builder2.setSize(worldSize, worldSize);
    builder2.setBounds(0.0, 0.0, 4.0, 4.0);
    builder2.setDestination(data2);
    builder2.build ();

    perlin.setSeed(seed+2);
    noisepp::utils::PlaneBuilder2D builder3;
    builder3.setModule(perlin);
    builder3.setSize(worldSize, worldSize);
    builder3.setBounds(0.0, 0.0, 4.0, 4.0);
    builder3.setDestination(data3);
    builder3.build ();

    int height1= 0;
    int height2= 0;

    for (int z = 0; z < WORLD_SIZE; ++z)
    {
        for (int x = 0; x < WORLD_SIZE; ++x)
        {
            height1 = data2[x + z*WORLD_SIZE]* 10 + WORLD_SIZE/2;
            height2 = data3[x + z*WORLD_SIZE]* 12 + WORLD_SIZE/2;

            if (height2 > height1)
            {
                //put at height1 grass
                if(world->GetBlock(x, height1, z) != 0)
                    world->GetBlock(x, height1, z) = grass;

                //delete blocks
                for (int y = height1+1; y < height2; y++)
                {
                    world->GetBlock(x, y, z) = 0;
                }
            }
        }
    }


    //delete tempdata
    delete []data2;
    delete []data3;*/

    //caves?
   	noisepp::RidgedMultiModule NoiseSource;
	NoiseSource.setSeed(seed);//da looks interesting
	NoiseSource.setQuality(noisepp::NOISE_QUALITY_FAST_STD);
	NoiseSource.setOctaveCount(4);
	NoiseSource.setFrequency(1.5f);//the smaller the more dense and bigger 1.9
	NoiseSource.setLacunarity(2.5f);//the larger the number of the rarer objects 2.2

	noisepp::Pipeline3D *pipeline = new noisepp::Pipeline3D;
	noisepp::ElementID id = NoiseSource.addToPipeline(pipeline);
	noisepp::PipelineElement3D *element = pipeline->getElement(id);
	noisepp::Cache *cache = pipeline->createCache ();

	float nx, ny, nz;
	float max = 0.0f;

	for (int z = 2; z < WORLD_SIZE - 4; ++z)
	{
		for (int x = 2; x < WORLD_SIZE - 4; ++x)
		{
			for (int y = 2; y < WORLD_SIZE/2; ++y)
			{
				nx = (float)x / WORLD_SIZE;
				ny = (float)y / WORLD_SIZE;
				nz = (float)z / WORLD_SIZE;

				float test = element->getValue(nx,ny,nz,cache);

				if(test > max)
					max = test;

				if(test > 0.8f)
					if(world->GetBlock(x, y, z) != 0)
					{
						world->GetBlock(x, y, z) = 0;

					}

			}

		}
	}



    pipeline->freeCache (cache);
    cache = 0;
    delete pipeline;
    pipeline = 0;


    //watering
    int waterLevel = 62;

    for (int z = 0; z < WORLD_SIZE; ++z)
    {
        for (int x = 0; x < WORLD_SIZE; ++x)
        {
            int Height = data[x + z*WORLD_SIZE]* WORLD_SIZE/12 + WORLD_SIZE/2;
                //int Height = m_HeightMap.GetValue(x, z) * WORLD_SIZE/12 + WORLD_SIZE/2;

            if(Height < waterLevel)
            {
                world->GetBlock(x, Height-1, z) = sandUnderWater;//sand under water

                for (int y = Height; y < waterLevel; y++)
                {
                    world->GetBlock(x, y, z) = water;//water
                }

            }
            else if(Height == waterLevel)
            {
                world->GetBlock(x, Height-1, z) = sandUnderWater;//beach sand
                world->GetBlock(x, Height-2, z) = sandUnderWater;
            }
        }
    }


    //make the most bottom layer of cube not destroyable
    for (int z = 0; z < WORLD_SIZE; ++z)
    {
        for (int x = 0; x < WORLD_SIZE; ++x)
        {
            world->GetBlock(x, 0, z) = IronBlock::getID();
        }
    }

    delete []data;

    //init trees
    initTrees(WORLD_SIZE, terrainType, world);

    initPumpkins(WORLD_SIZE, terrainType, world);

    initClouds(WORLD_SIZE, terrainType, world);

    initTypes(WORLD_SIZE, terrainType, world);

    initIron(WORLD_SIZE, world);

    initCoal(WORLD_SIZE, world);

    initGold(WORLD_SIZE, world);

    initRedStone(WORLD_SIZE, world);

    initDiamond(WORLD_SIZE, world);

    initDirt(WORLD_SIZE, world);

    initLapis(WORLD_SIZE, world);

    initEmerald(WORLD_SIZE, world);

    initLifeBlocks(WORLD_SIZE, world);
}

void WorldGenerator::initRandompMap(int worldSize,int chunkSize, CraftWorld *world, int terrainType,bool makeFlat,bool makeTrees,bool makePumpkins,bool makeClouds,bool makeTypes,bool makeIron,bool makeWater,bool makeCaves,bool makeCoal,bool makeGold,bool makeRedStone,bool makeDiamond,bool makeDirt,bool makeLapis,bool makeEmerand,bool makeLifeBlocks)
{
    //inicjuj mape
    int WORLD_SIZE = worldSize;
    int CHUNK_SIZE = chunkSize;

    //srand(time(NULL));
    int seed = rand() % 10000;

    //terrain settings for default terrain
    unsigned char grass = 1;
    unsigned char rock = 3;
    unsigned char dirt = 2;
    unsigned char water = 4;
    unsigned char sandUnderWater = 7;

    if(terrainType == 1)//winter
    {
        grass = 29;
        rock = 3;
        dirt = 2;
        water = 4;
        sandUnderWater = SandBlock::getID();
    }

    if(terrainType == 2)//desert
    {
        grass = SandBlock::getID();
        rock = 3;
        dirt = 53;
        water = 0;//there is no water on desert ;)
        sandUnderWater = SandBlock::getID();
    }

    if(terrainType == 3)//MooshRoom
    {
        grass = Mycelium::getID();
        rock = 3;
        dirt = 2;
        water = 4;
        sandUnderWater = SandBlock::getID();
    }

    if(terrainType == 4)//Nether
    {
        grass = Netherrack::getID();
        rock = Netherrack::getID();
        dirt = Netherrack::getID();
        water = Lava::getID();
        sandUnderWater = SoulSand::getID();

        for (int z = 0; z < WORLD_SIZE; ++z)
        {
            for (int x = 0; x < WORLD_SIZE; ++x)
            {
                block_t& Block = world->GetBlock(x,90, z);
                if (Block == 0) Block = Netherrack::getID();
            }
        }



    }

    if(terrainType == 5)//Aether
    {

        grass = 0;
        rock = 0;
        dirt = 0;
        water = 3;
        sandUnderWater = 0;

        for (int z = 0; z < WORLD_SIZE; ++z)
        {
            for (int x = 0; x < WORLD_SIZE; ++x)
            {
                block_t& Block = world->GetBlock(x,62, z);
                if (Block == 0) Block = 1;
            }
        }
    }

    if(terrainType == 6)
    {

        grass = 1;
        rock = 3;
        dirt = 2;
        water = 0;
        sandUnderWater = 1;
    }

    if(terrainType == 7)
    {

        grass = 29;
        rock = 3;
        dirt = 2;
        water = 0;
        sandUnderWater = 29;
    }

    if(terrainType == 8)//Jungle
    {

        grass = 1;
        rock = 3;
        dirt = 3;
        water = 4;
        sandUnderWater = 1;

    }

    if(terrainType == 9)//Wasteland
    {

        grass = GreyRock::getID();
        rock = 3;
        dirt = GreyRock::getID();
        water = 0;
        sandUnderWater = GreyRock::getID();

    }




    float *data = new float[worldSize * worldSize];

    //
    if(!makeFlat)
    {
        noisepp::PerlinModule perlin;
        perlin.setSeed(seed);
        perlin.setQuality(noisepp::NOISE_QUALITY_FAST_STD);

        //data = new float[worldSize * worldSize];



        noisepp::utils::PlaneBuilder2D builder;
        builder.setModule(perlin);
        builder.setSize(worldSize, worldSize);
        if(terrainType == 2)
            builder.setBounds(0.0, 0.0, 2.0, 3.0);
        else if(terrainType == 2)
            builder.setBounds(0.0, 0.0, 0.5, 1.0);
        else if(terrainType == 9)
            builder.setBounds(0.0, 0.0, 1.0, 0.5);
        else if(terrainType == 8)
            builder.setBounds(10.0, 10.0, 20.0, 20.5);
        else
            builder.setBounds(0.0, 0.0, 4.0, 4.0);
        builder.setDestination(data);
        builder.build ();

        int Height = 64;

        //build map
        for (int z = 0; z < WORLD_SIZE; ++z)
        {
            for (int x = 0; x < WORLD_SIZE; ++x)
            {
                Height = data[x + z*WORLD_SIZE]* WORLD_SIZE/12 + WORLD_SIZE/2;
                //int Height = m_HeightMap.GetValue(x, z) * WORLD_SIZE/12 + WORLD_SIZE/2;

                for (int y = 0; y < Height; ++y)
                {
                    if(y == Height-1)
                        world->GetBlock(x, y, z) = grass;//grass
                    else if(y < Height-3)
                        world->GetBlock(x, y, z) = rock;
                    else
                        world->GetBlock(x, y, z) = dirt;
                }
            }
        }

        //carve terrain

        /*
        float *data2 = new float[worldSize * worldSize];
        float *data3 = new float[worldSize * worldSize];

        perlin.setSeed(seed+1);
        noisepp::utils::PlaneBuilder2D builder2;
        builder2.setModule(perlin);
        builder2.setSize(worldSize, worldSize);
        builder2.setBounds(0.0, 0.0, 4.0, 4.0);
        builder2.setDestination(data2);
        builder2.build ();

        perlin.setSeed(seed+2);
        noisepp::utils::PlaneBuilder2D builder3;
        builder3.setModule(perlin);
        builder3.setSize(worldSize, worldSize);
        builder3.setBounds(0.0, 0.0, 4.0, 4.0);
        builder3.setDestination(data3);
        builder3.build ();

        int height1= 0;
        int height2= 0;

        for (int z = 0; z < WORLD_SIZE; ++z)
        {
            for (int x = 0; x < WORLD_SIZE; ++x)
            {
                height1 = data2[x + z*WORLD_SIZE]* 10 + WORLD_SIZE/2;
                height2 = data3[x + z*WORLD_SIZE]* 12 + WORLD_SIZE/2;

                if (height2 > height1)
                {
                    //put at height1 grass
                    if(world->GetBlock(x, height1, z) != 0)
                        world->GetBlock(x, height1, z) = grass;

                    //delete blocks
                    for (int y = height1+1; y < height2; y++)
                    {
                        world->GetBlock(x, y, z) = 0;
                    }
                }
            }
        }


        //delete tempdata
        delete []data2;
        delete []data3;*/

    }
    else
    {
        noisepp::PerlinModule perlin;
        perlin.setSeed(seed);
        perlin.setQuality(noisepp::NOISE_QUALITY_FAST_STD);

        //data = new float[worldSize * worldSize];



        noisepp::utils::PlaneBuilder2D builder;
        builder.setModule(perlin);
        builder.setSize(worldSize, worldSize);

            builder.setBounds(0.0, 0.0, 0.0, 0.0);
        builder.setDestination(data);
        builder.build ();

        int Height = 50;

        //build map
        for (int z = 0; z < WORLD_SIZE; ++z)
        {
            for (int x = 0; x < WORLD_SIZE; ++x)
            {
                Height = data[x + z*WORLD_SIZE]* WORLD_SIZE/12 + WORLD_SIZE/2;
                //int Height = m_HeightMap.GetValue(x, z) * WORLD_SIZE/12 + WORLD_SIZE/2;

                for (int y = 0; y < Height; ++y)
                {
                        if(y == Height-1)
                            world->GetBlock(x, y, z) = grass;//grass
                        else if(y < Height-3)
                            world->GetBlock(x, y, z) = rock;
                        else
                            world->GetBlock(x, y, z) = dirt;
                }
            }
        }
    }

    //caves?
    if(makeCaves)
	{
		noisepp::RidgedMultiModule NoiseSource;
		NoiseSource.setSeed(seed);//wygl¹da ciekawie
		NoiseSource.setQuality(noisepp::NOISE_QUALITY_FAST_STD);
		NoiseSource.setOctaveCount(4);
		NoiseSource.setFrequency(1.5f);//im mniejsza tym bardziej gêste i wiêksze 1.9
		NoiseSource.setLacunarity(2.5f);//im wiêksza liczba tym rzadsze obiekty 2.2

		noisepp::Pipeline3D *pipeline = new noisepp::Pipeline3D;
		noisepp::ElementID id = NoiseSource.addToPipeline(pipeline);
		noisepp::PipelineElement3D *element = pipeline->getElement(id);
		noisepp::Cache *cache = pipeline->createCache ();

		float nx, ny, nz;

		for (int z = 2; z < WORLD_SIZE - 4; ++z)
		{
			for (int x = 2; x < WORLD_SIZE - 4; ++x)
			{
				for (int y = 2; y < WORLD_SIZE/2; ++y)
				{
					nx = (float)x / WORLD_SIZE;
					ny = (float)y / WORLD_SIZE;
					nz = (float)z / WORLD_SIZE;

					if(element->getValue(nx,ny,nz,cache) > 0.8f)
					{
						world->GetBlock(x, y, z) = 0;
					}
				}
			}
		}

		 pipeline->freeCache (cache);
		 cache = 0;
		 delete pipeline;
		 pipeline = 0;
	}

    if(makeWater)
    {
        if(terrainType == 1)
        {
            for (int z = 0; z < WORLD_SIZE; ++z)
            {
                for (int x = 0; x < WORLD_SIZE; ++x)
                {
                    block_t& Block = world->GetBlock(x,62, z);
                    if (Block == 0) Block = 32;
                }
            }
        }
        //watering
        int waterLevel = 62;

        for (int z = 0; z < WORLD_SIZE; ++z)
        {
            for (int x = 0; x < WORLD_SIZE; ++x)
            {
                int Height = data[x + z*WORLD_SIZE]* WORLD_SIZE/12 + WORLD_SIZE/2;
            //int Height = m_HeightMap.GetValue(x, z) * WORLD_SIZE/12 + WORLD_SIZE/2;

                if(Height < waterLevel)
                {
                    world->GetBlock(x, Height-1, z) = sandUnderWater;//sand under water

                    for (int y = Height; y < waterLevel; y++)
                    {
                        world->GetBlock(x, y, z) = water;//water
                    }

                }
                else if(Height == waterLevel)
                {
                    world->GetBlock(x, Height-1, z) = sandUnderWater;//beach sand

                }
                else if(Height == waterLevel + 1)
                {
                    world->GetBlock(x, Height-1, z) = sandUnderWater;
                }

            }
        }
    }

    delete []data;

    //make the most bottom layer of cube not destroyable
    for (int z = 0; z < WORLD_SIZE; ++z)
    {
        for (int x = 0; x < WORLD_SIZE; ++x)
        {
            world->GetBlock(x, 0, z) = IronBlock::getID();//last one in set
        }
    }

    //init trees
    if(makeTrees)
        initTrees(WORLD_SIZE, terrainType, world);

    if(makePumpkins)
        initPumpkins(WORLD_SIZE, terrainType, world);

    if(makeClouds)
        initClouds(WORLD_SIZE, terrainType, world);

    if(makeTypes)
        initTypes(WORLD_SIZE, terrainType, world);

    if(makeIron)
        initIron(WORLD_SIZE, world);

    if(makeCoal)
        initCoal(WORLD_SIZE, world);

    if(makeGold)
        initGold(WORLD_SIZE, world);

    if(makeRedStone)
        initRedStone(WORLD_SIZE, world);

    if(makeDiamond)
        initDiamond(WORLD_SIZE, world);

    if(makeDirt)
        initDirt(WORLD_SIZE, world);

    if(makeLapis)
        initLapis(WORLD_SIZE, world);

    if(makeEmerand)
        initEmerald(WORLD_SIZE, world);

    if(makeLifeBlocks)
        initLifeBlocks(WORLD_SIZE, world);

}
void WorldGenerator::initTrees(int WORLD_SIZE, int treeChoose, CraftWorld *world)
{
    int NumTrees = 300;


    for (int i = 0; i < NumTrees; ++i)
    {
        //Choose the tree position
        int x = rand() % WORLD_SIZE;
        int z = rand() % WORLD_SIZE;
        int y = world->groundHeight(x, z);

        if (y <= 0) continue;

        int TrunkHeight = 5;//rand() % 5 + 4;


        //check if there is an water on there or another tree
        int flag = 1;
        for (int y1 = y; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            if(world->GetBlock(x, y1, z) == JungleLeaves::getID() || world->GetBlock(x, y1, z) == Snow2::getID() || world->GetBlock(x, y1, z) == 4 || world->GetBlock(x, y1, z) == 3 || world->GetBlock(x, y1, z) == 8 || world->GetBlock(x, y1, z) == 9 || world->GetBlock(x, y1, z) == 31 || world->GetBlock(x, y1, z) == 38 || world->GetBlock(x, y1, z) == 25 || world->GetBlock(x, y1, z) == 32 || world->GetBlock(x, y1, z) == 80 || world->GetBlock(x, y1, z) == 78 || world->GetBlock(x, y1, z) == Cloud::getID())
                flag = 0;
        }

        if(flag == 0)continue;


        if(treeChoose == 0)//normal tree
        {
            int random = rand() % 3;

            TrunkHeight = 4 + random;
            //Create the tree trunk
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 8;
            }

            //create my leaves
            for(int yy = 0; yy < 2; yy++)
            {
                for(int xx = 0; xx < 5; xx++)
                {
                    for(int zz = 0; zz < 5; zz++)
                    {
                        int x1 = xx + x - 2;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 2;
                        int z1 = zz + z - 2;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 9;
                    }
                }
            }

            //create my leaves
            for(int yy = 0; yy < 2; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 1; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight ;
                        int z1 = zz + z ;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 9;
                    }
                }
            }

            for(int yy = 0; yy < 2; yy++)
            {
                for(int xx = 0; xx < 1; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x ;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight ;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 9;
                    }
                }
            }
        }

        if(treeChoose == 1)//winter tree
        {
            NumTrees = 300;

            TrunkHeight = 8;
            //Create the tree trunk
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 31;
            }


            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 5; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x - 2;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 2;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }

            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 5; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 2;
                        int z1 = zz + z - 2;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }

            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 5; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x - 2;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 4;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }

            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 5; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 4;
                        int z1 = zz + z - 2;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }

            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 5; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x - 2;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 6;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }

            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 5; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 6;
                        int z1 = zz + z - 2;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }

            for(int yy = 0; yy < 6; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 1; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 6;
                        int z1 = zz + z ;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }

            for(int yy = 0; yy < 6; yy++)
            {
                for(int xx = 0; xx < 1; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x ;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 6;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }

            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 1; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight + 1;
                        int z1 = zz + z ;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }

            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 1; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x ;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight + 1;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }
        }

        if(treeChoose == 2)//desert cactus ;)
        {
            NumTrees = 100;

            int random = rand() % 2;

            TrunkHeight = 1 + random;
            //Create the tree trunk
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 25;
            }
        }

        if(treeChoose == 3)//Mooshroom
        {
            int random = rand() % 3;

            TrunkHeight = 4 + random;

        	NumTrees = 40;

            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 81;
            }

            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight + 1;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 80;
                    }
                }
            }

            for(int yy = 0; yy < 3; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 1; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 2;
                        int z1 = zz + z + 2;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 80;
                    }
                }
            }

            for(int yy = 0; yy < 3; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 1; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 2;
                        int z1 = zz + z - 2;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 80;
                    }
                }
            }

            for(int yy = 0; yy < 3; yy++)
            {
                for(int xx = 0; xx < 1; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x - 2;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 2;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 80;
                    }
                }
            }

            for(int yy = 0; yy < 3; yy++)
            {
                for(int xx = 0; xx < 1; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x + 2;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 2;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 80;
                    }
                }
            }
        }

        if(treeChoose == 4)//GlowStone
        {
            //Create the tree trunk
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 0;
            }
        }

        if(treeChoose == 5)//normal tree
        {
            NumTrees = 14;

            int random = rand() % 3;

            TrunkHeight = 4 + random;
            //Create the tree trunk
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 8;
            }

            //create my leaves
            for(int yy = 0; yy < 2; yy++)
            {
                for(int xx = 0; xx < 5; xx++)
                {
                    for(int zz = 0; zz < 5; zz++)
                    {
                        int x1 = xx + x - 2;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 2;
                        int z1 = zz + z - 2;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 9;
                    }
                }
            }

            //create my leaves
            for(int yy = 0; yy < 2; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 1; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight ;
                        int z1 = zz + z ;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 9;
                    }
                }
            }

            for(int yy = 0; yy < 2; yy++)
            {
                for(int xx = 0; xx < 1; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x ;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight ;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 9;
                    }
                }
            }
        }

        if(treeChoose == 6)//normal tree
        {
            NumTrees = 14;

            int random = rand() % 3;

            TrunkHeight = 4 + random;
            //Create the tree trunk
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 8;
            }

            //create my leaves
            for(int yy = 0; yy < 2; yy++)
            {
                for(int xx = 0; xx < 5; xx++)
                {
                    for(int zz = 0; zz < 5; zz++)
                    {
                        int x1 = xx + x - 2;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 2;
                        int z1 = zz + z - 2;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 9;
                    }
                }
            }

            //create my leaves
            for(int yy = 0; yy < 2; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 1; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight ;
                        int z1 = zz + z ;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 9;
                    }
                }
            }

            for(int yy = 0; yy < 2; yy++)
            {
                for(int xx = 0; xx < 1; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x ;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight ;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 9;
                    }
                }
            }
        }

        if(treeChoose == 7)//winter tree
        {
            NumTrees = 10;

            TrunkHeight = 8;
            //Create the tree trunk
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 31;
            }


            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 5; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x - 2;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 2;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }

            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 5; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 2;
                        int z1 = zz + z - 2;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }

            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 5; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x - 2;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 4;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }

            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 5; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 4;
                        int z1 = zz + z - 2;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }

            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 5; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x - 2;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 6;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }

            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 5; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 6;
                        int z1 = zz + z - 2;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }

            for(int yy = 0; yy < 6; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 1; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 6;
                        int z1 = zz + z ;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }

            for(int yy = 0; yy < 6; yy++)
            {
                for(int xx = 0; xx < 1; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x ;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 6;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }

            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 1; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight + 1;
                        int z1 = zz + z ;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }

            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 1; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x ;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight + 1;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }
        }

        if(treeChoose == 8)//normal tree
        {
            NumTrees = 14;

            TrunkHeight = 4;
            //Create the tree trunk
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 8;
            }

            //create my leaves
            for(int yy = 0; yy < 2; yy++)
            {
                for(int xx = 0; xx < 5; xx++)
                {
                    for(int zz = 0; zz < 5; zz++)
                    {
                        int x1 = xx + x - 2;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 2;
                        int z1 = zz + z - 2;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 9;
                    }
                }
            }

            //create my leaves
            for(int yy = 0; yy < 2; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 1; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight ;
                        int z1 = zz + z ;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 9;
                    }
                }
            }

            for(int yy = 0; yy < 2; yy++)
            {
                for(int xx = 0; xx < 1; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x ;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight ;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 9;
                    }
                }
            }
        }



        if(treeChoose == 9)//winter tree
        {
            NumTrees = 1;

            TrunkHeight = 6;
            //Create the tree trunk
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = WoodBlock::getID();
            }


            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 7; xx++)
                {
                    for(int zz = 0; zz < 7; zz++)
                    {
                        int x1 = xx + x - 3;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 1;
                        int z1 = zz + z - 3;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = JungleLeaves::getID();
                    }
                }
            }

            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 5; xx++)
                {
                    for(int zz = 0; zz < 5; zz++)
                    {
                        int x1 = xx + x - 2;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight ;
                        int z1 = zz + z - 2;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = JungleLeaves::getID();
                    }
                }
            }

            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 1; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight + 1;
                        int z1 = zz + z ;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = JungleLeaves::getID();
                    }
                }
            }

            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 1; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x ;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight + 1;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = JungleLeaves::getID();
                    }
                }
            }
        }
    }
}

void WorldGenerator::initPumpkins(int WORLD_SIZE, int PumpkinChoose, CraftWorld *world)
{
    int NumPumpkins = 70;

    for (int i = 0; i < NumPumpkins; ++i)
    {
        //Choose the tpumpkin position
        int x = rand() % WORLD_SIZE;
        int z = rand() % WORLD_SIZE;
        int y = world->groundHeight(x, z);

        if (y <= 0) continue;

        int TrunkHeight = 1;//rand() % 5 + 4;


        //check if there is an water on there or another tree
        int flag = 1;
        for (int y1 = y; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            if(world->GetBlock(x, y1, z) == Grass::getID() || world->GetBlock(x, y1, z) == JungleLeaves::getID() || world->GetBlock(x, y1, z) == 4 || world->GetBlock(x, y1, z) == 3 || world->GetBlock(x, y1, z) == 8 || world->GetBlock(x, y1, z) == 9 || world->GetBlock(x, y1, z) == 31 || world->GetBlock(x, y1, z) == 38 || world->GetBlock(x, y1, z) == 25 || world->GetBlock(x, y1, z) == 32 || world->GetBlock(x, y1, z) == 80 || world->GetBlock(x, y1, z) == 78 || world->GetBlock(x, y1, z) == 74)
                flag = 0;
        }

        if(flag == 0)continue;


        if(PumpkinChoose == 0)
        {
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 74;
            }
        }

        if(PumpkinChoose == 1)
        {
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 74;
            }
        }

        if(PumpkinChoose == 2)
        {
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 0;
            }
        }

        if(PumpkinChoose == 3)
        {

            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 74;
            }
        }

        if(PumpkinChoose == 4)
        {
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = GlowStone::getID();
            }
        }

        if(PumpkinChoose == 5)
        {
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 74;
            }
        }

        if(PumpkinChoose == 6)
        {
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 74;
            }
        }

        if(PumpkinChoose == 7)
        {
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 74;
            }
        }
    }

    int NumGrass = 500;

    for (int i = 0; i < NumGrass; ++i)
    {
        //Choose the tpumpkin position
        int x = rand() % WORLD_SIZE;
        int z = rand() % WORLD_SIZE;
        int y = world->groundHeight(x, z);

        if (y <= 0) continue;

        int TrunkHeight = 1;

        int flag = 1;
        for (int y1 = y; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            if(world->GetBlock(x, y1, z) == Grass::getID() || world->GetBlock(x, y1, z) == 7 || world->GetBlock(x, y1, z) == JungleLeaves::getID() || world->GetBlock(x, y1, z) == 4 || world->GetBlock(x, y1, z) == 3 || world->GetBlock(x, y1, z) == 8 || world->GetBlock(x, y1, z) == 9 || world->GetBlock(x, y1, z) == 31 || world->GetBlock(x, y1, z) == 38 || world->GetBlock(x, y1, z) == 25 || world->GetBlock(x, y1, z) == 32 || world->GetBlock(x, y1, z) == 80 || world->GetBlock(x, y1, z) == 78 || world->GetBlock(x, y1, z) == 74)
                flag = 0;
        }

        if(flag == 0)continue;


        if(PumpkinChoose == 0)
        {
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = Grass::getID();
            }
        }

        if(PumpkinChoose == 1)
        {
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = Grass::getID();
            }
        }

        if(PumpkinChoose == 2)
        {
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 0;
            }
        }

        if(PumpkinChoose == 5)
        {
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = Grass::getID();
            }
        }

        if(PumpkinChoose == 6)
        {
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = Grass::getID();
            }
        }

        if(PumpkinChoose == 7)
        {
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = Grass::getID();
            }
        }
    }
}

void WorldGenerator::initClouds(int WORLD_SIZE, int CloudChoose, CraftWorld *world)
{
    int NumClouds = 65;

    for (int i = 0; i < NumClouds; ++i)
    {
        //Choose the tpumpkin position
        int x = rand() % WORLD_SIZE;
        int z = rand() % WORLD_SIZE;
        int y = 92;

        if (y <= 0) continue;

        int TrunkHeight = 1;

        int flag = 1;
        for (int y1 = y; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            if(world->GetBlock(x, y1, z) == Grass::getID())
                flag = 0;
        }

        if(flag == 0)continue;


        for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            block_t& Block = world->GetBlock(x, y1, z);
            if (Block == 0) Block = 0;
        }

        if(CloudChoose != 4)
        {
            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 15; xx++)
                {
                    for(int zz = 0; zz < 9; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 1;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = Cloud::getID();
                    }
                }
            }
        }
    }
}

void WorldGenerator::initTypes(int WORLD_SIZE, int TypeChoose, CraftWorld *world)
{
    int NumTypes = 70;

    for (int i = 0; i < NumTypes; ++i)
    {
        //Choose the tpumpkin position
        int x = rand() % WORLD_SIZE;
        int z = rand() % WORLD_SIZE;
        int y = world->groundHeight(x, z);

        if (y <= 0) continue;

        int TrunkHeight = 7;//rand() % 5 + 4;


        //check if there is an water on there or another tree
        int flag = 1;
        for (int y1 = y; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            if(world->GetBlock(x, y1, z) == Pumpkin::getID() || world->GetBlock(x, y1, z) == 7 || world->GetBlock(x, y1, z) == SoulSand::getID() || world->GetBlock(x, y1, z) == Netherrack::getID() || world->GetBlock(x, y1, z) == JungleLeaves::getID() || world->GetBlock(x, y1, z) == Snow2::getID() || world->GetBlock(x, y1, z) == 96 || world->GetBlock(x, y1, z) == 4 || world->GetBlock(x, y1, z) == 3 || world->GetBlock(x, y1, z) == 8 || world->GetBlock(x, y1, z) == 9 || world->GetBlock(x, y1, z) == 31 || world->GetBlock(x, y1, z) == 38 || world->GetBlock(x, y1, z) == 25 || world->GetBlock(x, y1, z) == 32 || world->GetBlock(x, y1, z) == 80 || world->GetBlock(x, y1, z) == 78 || world->GetBlock(x, y1, z) == Cloud::getID())
                flag = 0;
        }

        if(flag == 0)continue;


        if(TypeChoose == 0)
        {
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 30;
            }

            for(int yy = 0; yy < 2; yy++)
            {
                for(int xx = 0; xx < 5; xx++)
                {
                    for(int zz = 0; zz < 5; zz++)
                    {
                        int x1 = xx + x - 2;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 2;
                        int z1 = zz + z - 2;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 9;
                    }
                }
            }

            //create my leaves
            for(int yy = 0; yy < 2; yy++)
            {
                for(int xx = 0; xx < 1; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x ;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight ;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 9;
                    }
                }
            }

            for(int yy = 0; yy < 2; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 1; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight ;
                        int z1 = zz + z ;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 9;
                    }
                }
            }
        }

        if(TypeChoose == 1)
        {
            TrunkHeight = 9;

            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 31;
            }

            for(int yy = 0; yy < 3; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 1; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 2;
                        int z1 = zz + z ;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }

            //create my leaves
            for(int yy = 0; yy < 3; yy++)
            {
                for(int xx = 0; xx < 1; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x ;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 2;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }

            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 1; xx++)
                {
                    for(int zz = 0; zz < 1; zz++)
                    {
                        int x1 = xx + x ;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight + 1;
                        int z1 = zz + z ;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }
        }

        if(TypeChoose == 2)
        {
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 0;
            }
        }

        if(TypeChoose == 3)
        {
        	NumTypes = 40;

            TrunkHeight = 4;

            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = MooshroomWood::getID();
            }

            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 5; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight + 1;
                        int z1 = zz + z - 2;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = MushRoomLeave::getID();
                    }
                }
            }

            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 5; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x - 2;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight + 1;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = MushRoomLeave::getID();
                    }
                }
            }
        }

        if(TypeChoose == 4)
        {
            NumTypes = 20;

            TrunkHeight = 28;

            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = Lava::getID();
            }
        }

        if(TypeChoose == 5)
        {
            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 0;
            }
        }

        if(TypeChoose == 6)
        {
            NumTypes = 10;

            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 30;
            }

            for(int yy = 0; yy < 2; yy++)
            {
                for(int xx = 0; xx < 5; xx++)
                {
                    for(int zz = 0; zz < 5; zz++)
                    {
                        int x1 = xx + x - 2;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 2;
                        int z1 = zz + z - 2;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 9;
                    }
                }
            }

            //create my leaves
            for(int yy = 0; yy < 2; yy++)
            {
                for(int xx = 0; xx < 1; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x ;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight ;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 9;
                    }
                }
            }

            for(int yy = 0; yy < 2; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 1; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight ;
                        int z1 = zz + z ;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 9;
                    }
                }
            }
        }

        if(TypeChoose == 7)
        {
            NumTypes = 10;

            TrunkHeight = 9;

            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 31;
            }

            for(int yy = 0; yy < 3; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 1; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 2;
                        int z1 = zz + z ;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }

            //create my leaves
            for(int yy = 0; yy < 3; yy++)
            {
                for(int xx = 0; xx < 1; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x ;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 2;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }

            for(int yy = 0; yy < 1; yy++)
            {
                for(int xx = 0; xx < 1; xx++)
                {
                    for(int zz = 0; zz < 1; zz++)
                    {
                        int x1 = xx + x ;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight + 1;
                        int z1 = zz + z ;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 38;
                    }
                }
            }
        }

        if(TypeChoose == 8)
        {
            NumTypes = 10;

            for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
            {
                block_t& Block = world->GetBlock(x, y1, z);
                if (Block == 0) Block = 30;
            }

            for(int yy = 0; yy < 2; yy++)
            {
                for(int xx = 0; xx < 5; xx++)
                {
                    for(int zz = 0; zz < 5; zz++)
                    {
                        int x1 = xx + x - 2;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight - 2;
                        int z1 = zz + z - 2;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 9;
                    }
                }
            }

            //create my leaves
            for(int yy = 0; yy < 2; yy++)
            {
                for(int xx = 0; xx < 1; xx++)
                {
                    for(int zz = 0; zz < 3; zz++)
                    {
                        int x1 = xx + x ;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight ;
                        int z1 = zz + z - 1;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 9;
                    }
                }
            }

            for(int yy = 0; yy < 2; yy++)
            {
                for(int xx = 0; xx < 3; xx++)
                {
                    for(int zz = 0; zz < 1; zz++)
                    {
                        int x1 = xx + x - 1;// :D - what a shitty code
                        int y1 = yy + y + TrunkHeight ;
                        int z1 = zz + z ;

                        if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                        if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                        block_t& Block = world->GetBlock(x1, y1, z1);
                        if (Block == 0) Block = 9;
                    }
                }
            }
        }
    }
}

void WorldGenerator::initIron(int WORLD_SIZE, CraftWorld *world)
{
    int NumOres = 1600;

    for (int i = 0; i < NumOres; ++i)
    {
        //Choose the tpumpkin position
        int x = rand() % WORLD_SIZE;
        int z = rand() % WORLD_SIZE;
        int y = rand() % WORLD_SIZE;

        if (y <= 0) continue;

        int TrunkHeight = 1;//rand() % 5 + 4;

        int random = rand()% 2;

        int flag = 1;
        for (int y1 = y; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            if(world->GetBlock(x, y1, z) == 0 || world->GetBlock(x, y1, z) == Snow2::getID() || world->GetBlock(x, y1, z) == 96 || world->GetBlock(x, y1, z) == 4 || world->GetBlock(x, y1, z) == 8 || world->GetBlock(x, y1, z) == 9 || world->GetBlock(x, y1, z) == 31 || world->GetBlock(x, y1, z) == 38 || world->GetBlock(x, y1, z) == 25 || world->GetBlock(x, y1, z) == 32 || world->GetBlock(x, y1, z) == 80 || world->GetBlock(x, y1, z) == 78 || world->GetBlock(x, y1, z) == Cloud::getID())
                flag = 0;
        }

        if(flag == 0)continue;


        for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            block_t& Block = world->GetBlock(x, y1, z);
            if (Block == RockBlock::getID()) Block = 41;
        }

        for(int yy = 0; yy < 1 + random; yy++)
        {
            for(int xx = 0; xx < 1 + random; xx++)
            {
                for(int zz = 0; zz < 1 + random; zz++)
                {
                    int x1 = xx + x - 2;// :D - what a shitty code
                    int y1 = yy + y + TrunkHeight + 1;
                    int z1 = zz + z - 1;

                    if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                    if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                    block_t& Block = world->GetBlock(x1, y1, z1);
                    if (Block == RockBlock::getID()) Block = 41;
                }
            }
        }
    }
}

void WorldGenerator::initCoal(int WORLD_SIZE, CraftWorld *world)
{
    int NumOres = 2000;

    for (int i = 0; i < NumOres; ++i)
    {
        //Choose the tpumpkin position
        int x = rand() % WORLD_SIZE;
        int z = rand() % WORLD_SIZE;
        int y = rand() % WORLD_SIZE;

        int TrunkHeight = 1;

        int random = rand()% 2;

        if (y <= 0) continue;

        int flag = 1;
        for (int y1 = y; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            if(world->GetBlock(x, y1, z) == 0 || world->GetBlock(x, y1, z) == Snow2::getID() || world->GetBlock(x, y1, z) == 96 || world->GetBlock(x, y1, z) == 4 || world->GetBlock(x, y1, z) == 8 || world->GetBlock(x, y1, z) == 9 || world->GetBlock(x, y1, z) == 31 || world->GetBlock(x, y1, z) == 38 || world->GetBlock(x, y1, z) == 25 || world->GetBlock(x, y1, z) == 32 || world->GetBlock(x, y1, z) == 80 || world->GetBlock(x, y1, z) == 78 || world->GetBlock(x, y1, z) == Cloud::getID())
                flag = 0;
        }

        if(flag == 0)continue;




        for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            block_t& Block = world->GetBlock(x, y1, z);
            if (Block == RockBlock::getID()) Block = 42;
        }



        for(int yy = 0; yy < 1 + random; yy++)
        {
            for(int xx = 0; xx < 1 + random; xx++)
            {
                for(int zz = 0; zz < 1 + random; zz++)
                {
                    int x1 = xx + x - 2;// :D - what a shitty code
                    int y1 = yy + y + TrunkHeight - 4;
                    int z1 = zz + z - 1;

                    if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                    if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                    block_t& Block = world->GetBlock(x1, y1, z1);
                    if (Block == RockBlock::getID()) Block = 42;
                }
            }
        }


    }
}

void WorldGenerator::initGold(int WORLD_SIZE, CraftWorld *world)
{
    int NumOres = 300;

    for (int i = 0; i < NumOres; ++i)
    {
        //Choose the tpumpkin position
        int x = rand() % WORLD_SIZE;
        int z = rand() % WORLD_SIZE;
        int y = 17 - rand() % 17;

        int TrunkHeight = 1;

        int random = rand()% 2;

        if (y <= 0) continue;

        int flag = 1;
        for (int y1 = y; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            if(world->GetBlock(x, y1, z) == 0 || world->GetBlock(x, y1, z) == Snow2::getID() || world->GetBlock(x, y1, z) == 96 || world->GetBlock(x, y1, z) == 4 || world->GetBlock(x, y1, z) == 8 || world->GetBlock(x, y1, z) == 9 || world->GetBlock(x, y1, z) == 31 || world->GetBlock(x, y1, z) == 38 || world->GetBlock(x, y1, z) == 25 || world->GetBlock(x, y1, z) == 32 || world->GetBlock(x, y1, z) == 80 || world->GetBlock(x, y1, z) == 78 || world->GetBlock(x, y1, z) == Cloud::getID())
                flag = 0;
        }

        if(flag == 0)continue;




        for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            block_t& Block = world->GetBlock(x, y1, z);
            if (Block == RockBlock::getID()) Block = 5;
        }

        for(int yy = 0; yy < random; yy++)
        {
            for(int xx = 0; xx < 1 + random; xx++)
            {
                for(int zz = 0; zz < random; zz++)
                {
                    int x1 = xx + x - 2;// :D - what a shitty code
                    int y1 = yy + y + TrunkHeight + 1;
                    int z1 = zz + z - 1;

                    if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                    if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                    block_t& Block = world->GetBlock(x1, y1, z1);
                    if (Block == RockBlock::getID()) Block = 5;
                }
            }
        }
    }
}

void WorldGenerator::initRedStone(int WORLD_SIZE, CraftWorld *world)
{
    int NumOres = 500;

    for (int i = 0; i < NumOres; ++i)
    {
        //Choose the tpumpkin position
        int x = rand() % WORLD_SIZE;
        int z = rand() % WORLD_SIZE;
        int y = 17 - rand() % 17;

        int TrunkHeight = 1;

        int random = rand()% 2;

        if (y <= 0) continue;

        int flag = 1;
        for (int y1 = y; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            if(world->GetBlock(x, y1, z) == 0 || world->GetBlock(x, y1, z) == Snow2::getID() || world->GetBlock(x, y1, z) == 96 || world->GetBlock(x, y1, z) == 4 || world->GetBlock(x, y1, z) == 8 || world->GetBlock(x, y1, z) == 9 || world->GetBlock(x, y1, z) == 31 || world->GetBlock(x, y1, z) == 38 || world->GetBlock(x, y1, z) == 25 || world->GetBlock(x, y1, z) == 32 || world->GetBlock(x, y1, z) == 80 || world->GetBlock(x, y1, z) == 78 || world->GetBlock(x, y1, z) == Cloud::getID())
                flag = 0;
        }

        if(flag == 0)continue;




        for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            block_t& Block = world->GetBlock(x, y1, z);
            if (Block == RockBlock::getID()) Block = 44;
        }

        for(int yy = 0; yy < 1 + random; yy++)
        {
            for(int xx = 0; xx < 1 + random; xx++)
            {
                for(int zz = 0; zz < 1 + random; zz++)
                {
                    int x1 = xx + x - 2;// :D - what a shitty code
                    int y1 = yy + y + TrunkHeight + 1;
                    int z1 = zz + z - 1;

                    if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                    if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                    block_t& Block = world->GetBlock(x1, y1, z1);
                    if (Block == RockBlock::getID()) Block = 44;
                }
            }
        }
    }
}

void WorldGenerator::initDiamond(int WORLD_SIZE, CraftWorld *world)
{
    int NumOres = 200;

    for (int i = 0; i < NumOres; ++i)
    {
        //Choose the tpumpkin position
        int x = rand() % WORLD_SIZE;
        int z = rand() % WORLD_SIZE;
        int y = 10 - rand() % 10;

        int TrunkHeight = 1;

        int random = rand()% 1;

        if (y <= 0) continue;

        int flag = 1;
        for (int y1 = y; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            if(world->GetBlock(x, y1, z) == 0 || world->GetBlock(x, y1, z) == Snow2::getID() || world->GetBlock(x, y1, z) == 96 || world->GetBlock(x, y1, z) == 4 || world->GetBlock(x, y1, z) == 8 || world->GetBlock(x, y1, z) == 9 || world->GetBlock(x, y1, z) == 31 || world->GetBlock(x, y1, z) == 38 || world->GetBlock(x, y1, z) == 25 || world->GetBlock(x, y1, z) == 32 || world->GetBlock(x, y1, z) == 80 || world->GetBlock(x, y1, z) == 78 || world->GetBlock(x, y1, z) == Cloud::getID())
                flag = 0;
        }

        if(flag == 0)continue;




        for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            block_t& Block = world->GetBlock(x, y1, z);
            if (Block == RockBlock::getID()) Block = 43;
        }

        for(int yy = 0; yy < 1 + random; yy++)
        {
            for(int xx = 0; xx <1 + random; xx++)
            {
                for(int zz = 0; zz <1 + random; zz++)
                {
                    int x1 = xx + x - 2;// :D - what a shitty code
                    int y1 = yy + y + TrunkHeight + 1;
                    int z1 = zz + z - 1;

                    if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                    if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                    block_t& Block = world->GetBlock(x1, y1, z1);
                    if (Block == RockBlock::getID()) Block = 43;
                }
            }
        }
    }
}

void WorldGenerator::initDirt(int WORLD_SIZE, CraftWorld *world)
{
    int NumOres = 2000;

    for (int i = 0; i < NumOres; ++i)
    {
        //Choose the tpumpkin position
        int x = rand() % WORLD_SIZE;
        int z = rand() % WORLD_SIZE;
        int y = rand() % WORLD_SIZE;

        int TrunkHeight = 1;

        int random = rand()% 2;

        if (y <= 0) continue;

        int flag = 1;
        for (int y1 = y; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            if(world->GetBlock(x, y1, z) == 0 || world->GetBlock(x, y1, z) == Snow2::getID() || world->GetBlock(x, y1, z) == 96 || world->GetBlock(x, y1, z) == 4 || world->GetBlock(x, y1, z) == 8 || world->GetBlock(x, y1, z) == 9 || world->GetBlock(x, y1, z) == 31 || world->GetBlock(x, y1, z) == 38 || world->GetBlock(x, y1, z) == 25 || world->GetBlock(x, y1, z) == 32 || world->GetBlock(x, y1, z) == 80 || world->GetBlock(x, y1, z) == 78 || world->GetBlock(x, y1, z) == Cloud::getID())
                flag = 0;
        }

        if(flag == 0)continue;




        for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            block_t& Block = world->GetBlock(x, y1, z);
            if (Block == RockBlock::getID()) Block = 2;
        }

        for(int yy = 0; yy <2 + random; yy++)
        {
            for(int xx = 0; xx <2 + random; xx++)
            {
                for(int zz = 0; zz <2 + random; zz++)
                {
                    int x1 = xx + x - 2;// :D - what a shitty code
                    int y1 = yy + y + TrunkHeight + 1;
                    int z1 = zz + z - 1;

                    if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                    if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                    block_t& Block = world->GetBlock(x1, y1, z1);
                    if (Block == RockBlock::getID()) Block = 2;
                }
            }
        }
    }
}

void WorldGenerator::initLapis(int WORLD_SIZE, CraftWorld *world)
{
    int NumCanes = 200;

    for (int i = 0; i < NumCanes; ++i)
    {
        int x = rand() % WORLD_SIZE;
        int z = rand() % WORLD_SIZE;
        int y =  17 - rand() % 17;

        if (y <= 0) continue;

        int TrunkHeight = 1;

        int random = rand()% 2;


        int flag = 1;
        for (int y1 = y; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            if(world->GetBlock(x, y1, z) == 0 || world->GetBlock(x, y1, z) == Snow2::getID() || world->GetBlock(x, y1, z) == 96 || world->GetBlock(x, y1, z) == 4 || world->GetBlock(x, y1, z) == 8 || world->GetBlock(x, y1, z) == 9 || world->GetBlock(x, y1, z) == 31 || world->GetBlock(x, y1, z) == 38 || world->GetBlock(x, y1, z) == 25 || world->GetBlock(x, y1, z) == 32 || world->GetBlock(x, y1, z) == 80 || world->GetBlock(x, y1, z) == 78 || world->GetBlock(x, y1, z) == Cloud::getID())
                flag = 0;
        }

        if(flag == 0)continue;




        for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            block_t& Block = world->GetBlock(x, y1, z);
            if (Block == RockBlock::getID()) Block = 116;
        }

        for(int yy = 0; yy <1 + random; yy++)
        {
            for(int xx = 0; xx <1 + random; xx++)
            {
                for(int zz = 0; zz <1 + random; zz++)
                {
                    int x1 = xx + x - 2;// :D - what a shitty code
                    int y1 = yy + y + TrunkHeight + 1;
                    int z1 = zz + z - 1;

                    if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                    if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                    block_t& Block = world->GetBlock(x1, y1, z1);
                    if (Block == RockBlock::getID()) Block = 116;
                }
            }
        }
    }
}

void WorldGenerator::initEmerald(int WORLD_SIZE, CraftWorld *world)
{
    int NumCanes = 200;

    for (int i = 0; i < NumCanes; ++i)
    {
        int x = rand() % WORLD_SIZE;
        int z = rand() % WORLD_SIZE;
        int y =  17 - rand() % 17;

        if (y <= 0) continue;

        int TrunkHeight = 1;

        int random = rand()% 2;


        int flag = 1;
        for (int y1 = y; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            if(world->GetBlock(x, y1, z) == 0 || world->GetBlock(x, y1, z) == Snow2::getID() || world->GetBlock(x, y1, z) == 96 || world->GetBlock(x, y1, z) == 4 || world->GetBlock(x, y1, z) == 8 || world->GetBlock(x, y1, z) == 9 || world->GetBlock(x, y1, z) == 31 || world->GetBlock(x, y1, z) == 38 || world->GetBlock(x, y1, z) == 25 || world->GetBlock(x, y1, z) == 32 || world->GetBlock(x, y1, z) == 80 || world->GetBlock(x, y1, z) == 78 || world->GetBlock(x, y1, z) == Cloud::getID())
                flag = 0;
        }

        if(flag == 0)continue;




        for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            block_t& Block = world->GetBlock(x, y1, z);
            if (Block == RockBlock::getID()) Block = EmeraldOre::getID();
        }

        for(int yy = 0; yy <1 + random; yy++)
        {
            for(int xx = 0; xx <1 + random; xx++)
            {
                for(int zz = 0; zz <1 + random; zz++)
                {
                    int x1 = xx + x - 2;// :D - what a shitty code
                    int y1 = yy + y + TrunkHeight + 1;
                    int z1 = zz + z - 1;

                    if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                    if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                    block_t& Block = world->GetBlock(x1, y1, z1);
                    if (Block == RockBlock::getID()) Block = EmeraldOre::getID();
                }
            }
        }
    }
}

void WorldGenerator::initLifeBlocks(int WORLD_SIZE, CraftWorld *world)
{
    int NumBlocks = 30;

    for (int i = 0; i < NumBlocks; ++i)
    {
        int x = rand() % WORLD_SIZE;
        int z = rand() % WORLD_SIZE;
        int y =  40 - rand() % 40;

        if (y <= 0) continue;

        int TrunkHeight = 1;

        int flag = 1;
        for (int y1 = y; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            if(world->GetBlock(x, y1, z) == 0 || world->GetBlock(x, y1, z) == Snow2::getID() || world->GetBlock(x, y1, z) == 96 || world->GetBlock(x, y1, z) == 4 || world->GetBlock(x, y1, z) == 8 || world->GetBlock(x, y1, z) == 9 || world->GetBlock(x, y1, z) == 31 || world->GetBlock(x, y1, z) == 38 || world->GetBlock(x, y1, z) == 25 || world->GetBlock(x, y1, z) == 32 || world->GetBlock(x, y1, z) == 80 || world->GetBlock(x, y1, z) == 78 || world->GetBlock(x, y1, z) == Cloud::getID())
                flag = 0;
        }

        if(flag == 0)continue;




        for (int y1 = y + 1; y1 < y + 1 + TrunkHeight && y1 < WORLD_SIZE; ++y1)
        {
            block_t& Block = world->GetBlock(x, y1, z);
            if (Block == RockBlock::getID()) Block = LifeBlock::getID();
        }

        for(int yy = 0; yy < 2; yy++)
        {
            for(int xx = 0; xx < 3; xx++)
            {
                for(int zz = 0; zz < 3; zz++)
                {
                    int x1 = xx + x - 1;// :D - what a shitty code
                    int y1 = y + TrunkHeight;
                    int z1 = zz + z - 1;

                    if (x1 < 0 || y1 < 0 || z1 < 0) continue;
                    if (x1 >= WORLD_SIZE || y1 >= WORLD_SIZE || z1 >= WORLD_SIZE) continue;

                    block_t& Block = world->GetBlock(x1, y1, z1);
                    if (Block == RockBlock::getID()) Block = 0;
                }
            }
        }
    }
}
