#ifndef WorldGenerator_H
#define WorldGenerator_H

class CraftWorld;

class WorldGenerator
{
	public:
		void initRandompMap(int worldSize,int chunkSize, CraftWorld *world);
		void initRandompMap(int worldSize,int chunkSize, CraftWorld *world, int terrainType,bool makeFlat,bool makeTrees,bool makePumpkins,bool makeClouds,bool makeWater,bool makeCaves,bool makeTypes,bool makeSnow,bool makeCoal,bool makeGold,bool makeRedStone,bool makeDiamond,bool makeDirt,bool makeLapis,bool makeEmerald,bool makeLifeBlocks);
		void initTrees(int WORLD_SIZE, int treeChoose, CraftWorld *world);
		void initPumpkins(int WORLD_SIZE, int PumpkinChoose, CraftWorld *world);
		void initClouds(int WORLD_SIZE, int CloudChoose, CraftWorld *world);
		void initTypes(int WORLD_SIZE, int TypeChoose, CraftWorld *world);
		void initIron(int WORLD_SIZE, CraftWorld *world);
		void initCoal(int WORLD_SIZE, CraftWorld *world);
		void initGold(int WORLD_SIZE, CraftWorld *world);
		void initRedStone(int WORLD_SIZE, CraftWorld *world);
		void initDiamond(int WORLD_SIZE, CraftWorld *world);
		void initDirt(int WORLD_SIZE, CraftWorld *world);
		void initLapis(int WORLD_SIZE, CraftWorld *world);
		void initEmerald(int WORLD_SIZE, CraftWorld *world);
		void initLifeBlocks(int WORLD_SIZE, CraftWorld *world);
};

#endif
