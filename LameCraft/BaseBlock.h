#ifndef BASEBLOCK_H
#define BASEBLOCK_H

#include <Aurora/Graphics/Vertex.h>

using namespace Aurora::Graphics;

typedef unsigned char block_t;

class BaseBlock
{
public:
	//texture info
	int textureRow;
	float upPlane;
	float downPlane;
	float sidePlane;

	//vertices to show in bar or in hand
	CraftPSPVertex *vertices;

	//sound type
	int soundType;//0 grass,1 gravel,2 stone,3 wood

	//other properties
	bool editable;
	bool transparent;
	bool lightSource;
	bool blockSpecial;
	bool show_in_inventory;

	BaseBlock();
	virtual ~BaseBlock();

	static block_t getBaseID();

};

#endif
