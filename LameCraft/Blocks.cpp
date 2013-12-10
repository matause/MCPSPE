#include "Blocks.h"


GrassBlock::GrassBlock():BaseBlock()
{
	textureRow = 0;

	upPlane = 0;
	downPlane = 2;
	sidePlane = 3;
	editable = true;
	transparent = false;
	soundType = 0;

}

block_t GrassBlock::getID(){ return 1;}

DirtBlock::DirtBlock():BaseBlock()
{
	textureRow = 0;

	upPlane = 2;
	downPlane = 2;
	sidePlane = 2;
	editable = true;
	transparent = false;
	soundType = 1;

}

block_t DirtBlock::getID(){ return 2;}


RockBlock::RockBlock():BaseBlock()
{
	textureRow = 1;

	upPlane = 0;
	downPlane = 0;
	sidePlane = 0;
	editable = true;
	transparent = false;
	soundType = 2;

}

block_t RockBlock::getID(){ return 3;}


WaterBlock::WaterBlock():BaseBlock()
{
	textureRow = 3;

	upPlane = 2;
	downPlane = 2;
	sidePlane = 2;
	editable = false;
	transparent = true;
	blockSpecial = true;
	soundType = -1;

}

block_t WaterBlock::getID(){ return 4;}

GoldBlock::GoldBlock():BaseBlock()
{
	textureRow = 6;

	upPlane = 2;
	downPlane = 2;
	sidePlane = 2;
	editable = true;
	transparent = false;
	soundType = 2;

}

block_t GoldBlock::getID(){ return 5;}

LadderBlock::LadderBlock():BaseBlock()
{
	textureRow = 3;

	upPlane = 0;
	downPlane = 0;
	sidePlane = 0;
	editable = true;
	transparent = true;
	blockSpecial = true;
	soundType = 3;

}
block_t LadderBlock::getID(){ return 6;}


SandBlock::SandBlock():BaseBlock()
{
	textureRow = 1;

	upPlane = 2;
	downPlane = 2;
	sidePlane = 2;
	editable = true;
	transparent = false;
	soundType = 6;

}
block_t SandBlock::getID(){ return 7;}


WoodBlock::WoodBlock():BaseBlock()
{
	textureRow = 2;

	upPlane = 1;
	downPlane = 1;
	sidePlane = 2;
	editable = true;
	transparent = false;
	soundType = 3;

}
block_t WoodBlock::getID(){ return 8;}

LeavesBlock::LeavesBlock():BaseBlock()
{
	textureRow = 2;

	upPlane = 3;
	downPlane = 3;
	sidePlane = 3;
	editable = true;
	transparent = false;
	soundType = 0;

}
block_t LeavesBlock::getID(){ return 9;}


TNTBlock::TNTBlock():BaseBlock()
{
	textureRow = 4;

	upPlane = 3;
	downPlane = 3;
	sidePlane = 3;
	editable = true;
	transparent = false;
	soundType = 3;

}
block_t TNTBlock::getID(){ return 10;}


BlackWoolBlock::BlackWoolBlock():BaseBlock()
{
	textureRow = 3;

	upPlane = 6;
	downPlane = 6;
	sidePlane = 6;
	editable = true;
	transparent = false;
	soundType = 4;

}
block_t BlackWoolBlock::getID(){ return 11;}


RedWoolBlock::RedWoolBlock():BaseBlock()
{
	textureRow = 1;

	upPlane = 4;
	downPlane = 4;
	sidePlane = 4;
	editable = true;
	transparent = false;
	soundType = 4;

}
block_t RedWoolBlock::getID(){ return 12;}


DarkGreyWoolBlock::DarkGreyWoolBlock():BaseBlock()
{
	textureRow = 4;

	upPlane = 5;
	downPlane = 5;
	sidePlane = 5;
	editable = true;
	transparent = false;
	soundType = 4;

}
block_t DarkGreyWoolBlock::getID(){ return 13;}



BrownWoolBlock::BrownWoolBlock():BaseBlock()
{
	textureRow = 5;

	upPlane = 5;
	downPlane = 5;
	sidePlane = 5;
	editable = true;
	transparent = false;
	soundType = 4;

}
block_t BrownWoolBlock::getID(){ return 14;}


LightBlackWoolBlock::LightBlackWoolBlock():BaseBlock()
{
	textureRow = 3;

	upPlane = 7;
	downPlane = 7;
	sidePlane = 7;
	editable = true;
	transparent = false;
	soundType = 4;

}
block_t LightBlackWoolBlock::getID(){ return 15;}



PinkWoolBlock::PinkWoolBlock():BaseBlock()
{
	textureRow = 1;

	upPlane = 5;
	downPlane = 5;
	sidePlane = 5;
	editable = true;
	transparent = false;
	soundType = 4;

}
block_t PinkWoolBlock::getID(){ return 16;}


LightGreenWoolBlock::LightGreenWoolBlock():BaseBlock()
{
	textureRow = 4;

	upPlane = 6;
	downPlane = 6;
	sidePlane = 6;
	editable = true;
	transparent = false;
	soundType = 4;

}
block_t LightGreenWoolBlock::getID(){ return 17;}

YellowWoolBlock::YellowWoolBlock():BaseBlock()
{
	textureRow = 1;

	upPlane = 3;
	downPlane = 3;
	sidePlane = 3;
	editable = true;
	transparent = false;
	soundType = 4;

}
block_t YellowWoolBlock::getID(){ return 18;}

BlueWoolBlock::BlueWoolBlock():BaseBlock()
{
	textureRow = 0;

	upPlane = 6;
	downPlane = 6;
	sidePlane = 6;
	editable = true;
	transparent = false;
	soundType = 4;

}
block_t BlueWoolBlock::getID(){ return 19;}

LightBlueWoolBlock::LightBlueWoolBlock():BaseBlock()
{
	textureRow = 0;

	upPlane = 7;
	downPlane = 7;
	sidePlane = 7;
	editable = true;
	transparent = false;
	soundType = 4;

}
block_t LightBlueWoolBlock::getID(){ return 20;}

FioletWoolBlock::FioletWoolBlock():BaseBlock()
{
	textureRow = 1;

	upPlane = 6;
	downPlane = 6;
	sidePlane = 6;
	editable = true;
	transparent = false;
	soundType = 4;

}
block_t FioletWoolBlock::getID(){ return 21;}

PastelWoolBlock::PastelWoolBlock():BaseBlock()
{
	textureRow = 2;

	upPlane = 6;
	downPlane = 6;
	sidePlane = 6;
	editable = true;
	transparent = false;
	soundType = 4;

}
block_t PastelWoolBlock::getID(){ return 22;}

LightFioletWoolBlock::LightFioletWoolBlock():BaseBlock()
{
	textureRow = 1;

	upPlane = 7;
	downPlane = 7;
	sidePlane = 7;
	editable = true;
	transparent = false;
	soundType = 4;

}
block_t LightFioletWoolBlock::getID(){ return 23;}

OrangeWoolBlock::OrangeWoolBlock():BaseBlock()
{
	textureRow = 2;

	upPlane = 7;
	downPlane = 7;
	sidePlane = 7;
	editable = true;
	transparent = false;
	soundType = 4;

}
block_t OrangeWoolBlock::getID(){ return 24;}

CactusBlock::CactusBlock():BaseBlock()
{
	textureRow = 5;

	upPlane = 0;
	downPlane = 2;
	sidePlane = 1;
	editable = true;
	transparent = true;
	soundType = 3;

}
block_t CactusBlock::getID(){ return 25;}

AllSnowBlock::AllSnowBlock():BaseBlock()
{
	textureRow = 0;

	upPlane = 4;
	downPlane = 4;
	sidePlane = 4;
	editable = true;
	transparent = false;
	soundType = 5;

}
block_t AllSnowBlock::getID(){ return 26;}

BrickBlock::BrickBlock():BaseBlock()
{
	textureRow = 4;

	upPlane = 7;
	downPlane = 7;
	sidePlane = 7;
	editable = true;
	transparent = false;
	soundType = 2;

}
block_t BrickBlock::getID(){ return 27;}

CageBlock::CageBlock():BaseBlock()
{
	textureRow = 6;

	upPlane = 1;
	downPlane = 1;
	sidePlane = 1;
	editable = true;
	transparent = true;
	soundType = 2;

}
block_t CageBlock::getID(){ return 28;}

SnowBlock::SnowBlock():BaseBlock()
{
	textureRow = 0;

	upPlane = 4;
	downPlane = 2;
	sidePlane = 5;
	editable = true;
	transparent = false;
	soundType = 5;

}
block_t SnowBlock::getID(){ return 29;}

DarkWoodBlock::DarkWoodBlock():BaseBlock()
{
	textureRow = 2;

	upPlane = 1;
	downPlane = 1;
	sidePlane = 4;
	editable = true;
	transparent = false;
	soundType = 3;

}
block_t DarkWoodBlock::getID(){ return 30;}

WhiteWoodBlock::WhiteWoodBlock():BaseBlock()
{
	textureRow = 2;

	upPlane = 1;
	downPlane = 1;
	sidePlane = 5;
	editable = true;
	transparent = false;
	soundType = 3;

}
block_t WhiteWoodBlock::getID(){ return 31;}

IceBlock::IceBlock():BaseBlock()
{
	textureRow = 6;

	upPlane = 0;
	downPlane = 0;
	sidePlane = 0;
	editable = true;
	transparent = false;
	soundType = 2;

}
block_t IceBlock::getID(){ return 32;}

CaneBlock::CaneBlock():BaseBlock()
{
	textureRow = 5;

	upPlane = 4;
	downPlane = 4;
	sidePlane = 3;
	editable = true;
	transparent = true;
	soundType = 1;

}
block_t CaneBlock::getID(){ return 33;}

BoxBlock::BoxBlock():BaseBlock()
{
	textureRow = 4;

	upPlane = 0;
	downPlane = 0;
	sidePlane = 0;
	editable = true;
	transparent = false;
	soundType = 3;

}
block_t BoxBlock::getID(){ return 34;}

ShelfBlock::ShelfBlock():BaseBlock()
{
	textureRow = 4;

	upPlane = 0;
	downPlane = 0;
	sidePlane = 1;
	editable = true;
	transparent = false;
	soundType = 3;

}
block_t ShelfBlock::getID(){ return 35;}

WallBlock::WallBlock():BaseBlock()
{
	textureRow = 4;

	upPlane = 2;
	downPlane = 2;
	sidePlane = 2;
	editable = true;
	transparent = false;
	soundType = 2;

}
block_t WallBlock::getID(){ return 36;}

DrySandBlock::DrySandBlock():BaseBlock()
{
	textureRow = 4;

	upPlane = 8;
	downPlane = 8;
	sidePlane = 8;
	editable = true;
	transparent = false;
	soundType = 6;

}
block_t DrySandBlock::getID(){ return 37;}

SnowLewesBlock::SnowLewesBlock():BaseBlock()
{
	textureRow = 2;

	upPlane = 0;
	downPlane = 0;
	sidePlane = 0;
	editable = true;
	transparent = false;
	soundType = 0;

}
block_t SnowLewesBlock::getID(){ return 38;}

MudBlock::MudBlock():BaseBlock()
{
	textureRow = 3;

	upPlane = 10;
	downPlane = 10;
	sidePlane = 10;
	editable = true;
	transparent = false;
	soundType = 6;

}
block_t MudBlock::getID(){ return 39;}

GlassBlock::GlassBlock():BaseBlock()
{
	textureRow = 3;

	upPlane = 1;
	downPlane = 1;
	sidePlane = 1;
	editable = true;
	transparent = true;
	soundType = 2;

}
block_t GlassBlock::getID(){ return 40;}

BrownCoailBlock::BrownCoailBlock():BaseBlock()
{
	textureRow = 6;

	upPlane = 3;
	downPlane = 3;
	sidePlane = 3;
	editable = true;
	transparent = false;
	soundType = 2;

}
block_t BrownCoailBlock::getID(){ return 41;}

BlackCoailBlock::BlackCoailBlock():BaseBlock()
{
	textureRow = 6;

	upPlane = 4;
	downPlane = 4;
	sidePlane = 4;
	editable = true;
	transparent = false;
	soundType = 2;

}
block_t BlackCoailBlock::getID(){ return 42;}

BlueCoailBlock::BlueCoailBlock():BaseBlock()
{
	textureRow = 6;

	upPlane = 5;
	downPlane = 5;
	sidePlane = 5;
	editable = true;
	transparent = false;
	soundType = 2;

}
block_t BlueCoailBlock::getID(){ return 43;}

RedCoailBlock::RedCoailBlock():BaseBlock()
{
	textureRow = 6;

	upPlane = 6;
	downPlane = 6;
	sidePlane = 6;
	editable = true;
	transparent = false;
	soundType = 2;

}
block_t RedCoailBlock::getID(){ return 44;}

SlamRockBlock::SlamRockBlock():BaseBlock()
{
	textureRow = 6;

	upPlane = 7;
	downPlane = 7;
	sidePlane = 7;
	editable = true;
	transparent = false;
	soundType = 2;

}
block_t SlamRockBlock::getID(){ return 45;}

WaterRockBlock::WaterRockBlock():BaseBlock()
{
	textureRow = 5;

	upPlane = 6;
	downPlane = 6;
	sidePlane = 6;
	editable = true;
	transparent = false;
	soundType = 2;

}
block_t WaterRockBlock::getID(){ return 46;}

JackOLantern::JackOLantern():BaseBlock()
{
	textureRow = 7;

	upPlane = 0;
	downPlane = 1;
	sidePlane = 2;
	editable = true;
	transparent = false;
	soundType = 3;
	lightSource = true;

}
block_t JackOLantern::getID(){ return 47;}

Torch::Torch():BaseBlock()
{
	textureRow = 7;

	upPlane = 3;
	downPlane = 3;
	sidePlane = 3;
	editable = true;
	transparent = false;
	soundType = 2;
	lightSource = true;
	blockSpecial = true;

}
block_t Torch::getID(){ return 48;}

Door1::Door1():BaseBlock()
{
	textureRow = 3;

	upPlane = 11;
	downPlane = 11;
	sidePlane = 9;
	editable = true;
	transparent = true;
	blockSpecial = true;
	soundType = 3;

}
block_t Door1::getID(){ return 49;}

Door2::Door2():BaseBlock()
{
	textureRow = 4;

	upPlane = 9;
	downPlane = 9;
	sidePlane = 9;
	editable = true;
	transparent = true;
	blockSpecial = true;
	soundType = 3;

}
block_t Door2::getID(){ return 50;}

HalfBlocks::HalfBlocks():BaseBlock()
{
	textureRow = 1;

	upPlane = 8;
	downPlane = 8;
	sidePlane = 9;
	editable = true;
	transparent = false;
	soundType = 2;

}
block_t HalfBlocks::getID(){ return 51;}

SandStone1::SandStone1():BaseBlock()
{
	textureRow = 7;

	upPlane = 4;
	downPlane = 4;
	sidePlane = 6;
	editable = true;
	transparent = false;
	soundType = 2;

}
block_t SandStone1::getID(){ return 52;}

SandStone2::SandStone2():BaseBlock()
{
	textureRow = 7;

	upPlane = 4;
	downPlane = 5;
	sidePlane = 7;
	editable = true;
	transparent = false;
	soundType = 2;

}
block_t SandStone2::getID(){ return 53;}

SandStone3::SandStone3():BaseBlock()
{
	textureRow = 7;

	upPlane = 4;
	downPlane = 5;
	sidePlane = 8;
	editable = true;
	transparent = false;
	soundType = 2;

}
block_t SandStone3::getID(){ return 54;}

StoneBrick1::StoneBrick1():BaseBlock()
{
	textureRow = 4;

	upPlane = 4;
	downPlane = 4;
	sidePlane = 4;
	editable = true;
	transparent = false;
	soundType = 2;

}
block_t StoneBrick1::getID(){ return 55;}

StoneBrick2::StoneBrick2():BaseBlock()
{
	textureRow = 3;

	upPlane = 3;
	downPlane = 3;
	sidePlane = 3;
	editable = true;
	transparent = false;
	soundType = 2;

}
block_t StoneBrick2::getID(){ return 56;}

StoneBrick3::StoneBrick3():BaseBlock()
{
	textureRow = 3;

	upPlane = 4;
	downPlane = 4;
	sidePlane = 4;
	editable = true;
	transparent = false;
	soundType = 2;

}
block_t StoneBrick3::getID(){ return 57;}

StoneBrick4::StoneBrick4():BaseBlock()
{
	textureRow = 3;

	upPlane = 5;
	downPlane = 5;
	sidePlane = 5;
	editable = true;
	transparent = false;
	soundType = 2;

}
block_t StoneBrick4::getID(){ return 58;}

JungleWood::JungleWood():BaseBlock()
{
	textureRow = 2;

	upPlane = 1;
	downPlane = 1;
	sidePlane = 8;
	editable = true;
	transparent = false;
	soundType = 3;

}
block_t JungleWood::getID(){ return 59;}

Planks1::Planks1():BaseBlock()
{
	textureRow = 5;

	upPlane = 7;
	downPlane = 7;
	sidePlane = 7;
	editable = true;
	transparent = false;
	soundType = 3;

}
block_t Planks1::getID(){ return 60;}

Planks2::Planks2():BaseBlock()
{
	textureRow = 5;

	upPlane = 8;
	downPlane = 8;
	sidePlane = 8;
	editable = true;
	transparent = false;
	soundType = 3;

}
block_t Planks2::getID(){ return 61;}

Planks3::Planks3():BaseBlock()
{
	textureRow = 6;

	upPlane = 8;
	downPlane = 8;
	sidePlane = 8;
	editable = true;
	transparent = false;
	soundType = 3;

}
block_t Planks3::getID(){ return 62;}

Mycelium::Mycelium():BaseBlock()
{
	textureRow = 0;

	upPlane = 8;
	downPlane = 2;
	sidePlane = 9;
	editable = true;
	transparent = false;
	soundType = 0;

}
block_t Mycelium::getID(){ return 63;}

Diamond::Diamond():BaseBlock()
{
	textureRow = 8;

	upPlane = 2;
	downPlane = 2;
	sidePlane = 2;
	editable = true;
	transparent = false;
	soundType = 2;

}
block_t Diamond::getID(){ return 64;}

Gold::Gold():BaseBlock()
{
	textureRow = 8;

	upPlane = 1;
	downPlane = 1;
	sidePlane = 1;
	editable = true;
	transparent = false;
	soundType = 2;

}
block_t Gold::getID(){ return 65;}


Iron::Iron():BaseBlock()
{
	textureRow = 8;

	upPlane = 0;
	downPlane = 0;
	sidePlane = 0;
	editable = true;
	transparent = false;
	soundType = 2;

}
block_t Iron::getID(){ return 66;}

NetherBrick::NetherBrick():BaseBlock()
{
    textureRow = 0;

    upPlane = 1;
    downPlane = 1;
    sidePlane = 1;
    editable = true;
    transparent = false;
    soundType = 2;

}
block_t NetherBrick::getID(){ return 67;}

Netherrack::Netherrack():BaseBlock()
{
    textureRow = 2;

    upPlane = 9;
    downPlane = 9;
    sidePlane = 9;
    editable = true;
    transparent = false;
    soundType = 2;

}
block_t Netherrack::getID(){ return 68;}

SoulSand::SoulSand():BaseBlock()
{
    textureRow = 2;

    upPlane = 10;
    downPlane = 10;
    sidePlane = 10;
    editable = true;
    transparent = false;
    soundType = 1;

}
block_t SoulSand::getID(){ return 69;}

Grass::Grass():BaseBlock()
{
    textureRow = 5;

    upPlane = 4;
    downPlane = 4;
    sidePlane = 9;
    editable = true;
    transparent = true;
    soundType = 0;

}
block_t Grass::getID(){ return 70;}

MelonSeeds::MelonSeeds():BaseBlock()
{
    textureRow = 5;

    upPlane = 14;
    downPlane = 14;
    sidePlane = 12;
    editable = true;
    transparent = true;
    soundType = 3;

}
block_t MelonSeeds::getID(){ return 71;}

JukeBox::JukeBox():BaseBlock()
{
    textureRow = 8;

    upPlane = 6;
    downPlane = 5;
    sidePlane = 5;
    editable = true;
    transparent = false;
    soundType = 3;

}
block_t JukeBox::getID(){ return 72;}


EndStone::EndStone():BaseBlock()
{
    textureRow = 0;

    upPlane = 10;
    downPlane = 10;
    sidePlane = 10;
    editable = true;
    transparent = false;
    soundType = 2;

}
block_t EndStone::getID(){ return 73;}

Pumpkin::Pumpkin():BaseBlock()
{
    textureRow = 9;

    upPlane = 1;
    downPlane = 1;
    sidePlane = 0;
    editable = true;
    transparent = false;
    soundType = 3;

}
block_t Pumpkin::getID(){ return 74;}


GlowStone::GlowStone():BaseBlock()
{
    textureRow = 3;

    upPlane = 8;
    downPlane = 8;
    sidePlane = 8;
    editable = true;
    transparent = false;
    lightSource = true;
    soundType = 2;

}
block_t GlowStone::getID(){ return 75;}

GlassPane::GlassPane():BaseBlock()
{
	textureRow = 3;

	upPlane = 1;
	downPlane = 1;
	sidePlane = 1;
	editable = true;
	transparent = true;
	blockSpecial = true;
	soundType = 2;

}
block_t GlassPane::getID(){ return 76;}

IronBars::IronBars():BaseBlock()
{
    textureRow = 9;

    upPlane = 5;
    downPlane = 5;
    sidePlane = 5;
    editable = true;
    transparent = true;
    blockSpecial = true;
    soundType = 3;

}
block_t IronBars::getID(){ return 77;}

lilyPad::lilyPad():BaseBlock()
{
    textureRow = 9;

    upPlane = 2;
    downPlane = 2;
    sidePlane = 3;
    editable = true;
    blockSpecial = true;
    transparent = true;
    soundType = 0;

}
block_t lilyPad::getID(){ return 78;}

AetherPlanks::AetherPlanks():BaseBlock()
{
    textureRow = 6;

    upPlane = 9;
    downPlane = 9;
    sidePlane = 9;
    editable = true;
    transparent = false;
    soundType = 3;

}
block_t AetherPlanks::getID(){ return 79;}

MooshroomLeaves::MooshroomLeaves():BaseBlock()
{
    textureRow = 8;

    upPlane = 9;
    downPlane = 8;
    sidePlane = 9;
    editable = true;
    transparent = false;
    soundType = 3;

}
block_t MooshroomLeaves::getID(){ return 80;}

MooshroomWood::MooshroomWood():BaseBlock()
{
    textureRow = 8;

    upPlane = 8;
    downPlane = 8;
    sidePlane = 7;
    editable = true;
    transparent = false;
    soundType = 3;

}
block_t MooshroomWood::getID(){ return 81;}

HalfBlock8::HalfBlock8():BaseBlock()
{
    textureRow = 4;

    upPlane = 2;
    downPlane = 2;
    sidePlane = 12;
    editable = true;
    transparent = false;
    blockSpecial = true;
    soundType = 3;

}
block_t HalfBlock8::getID(){ return 82;}

HalfBlock0::HalfBlock0():BaseBlock()
{
    textureRow = 4;

    upPlane = 4;
    downPlane = 4;
    sidePlane = 11;
    editable = true;
    transparent = false;
    blockSpecial = true;
    soundType = 3;

}
block_t HalfBlock0::getID(){ return 83;}

HalfBlock1::HalfBlock1():BaseBlock()
{
    textureRow = 1;

    upPlane = 8;
    downPlane = 8;
    sidePlane = 11;
    editable = true;
    transparent = false;
    blockSpecial = true;
    lightSource = false;
    soundType = 3;

}
block_t HalfBlock1::getID(){ return 84;}

HalfBlock2::HalfBlock2():BaseBlock()
{
    textureRow = 7;

    upPlane = 4;
    downPlane = 5;
    sidePlane = 11;
    editable = true;
    transparent = false;
    blockSpecial = true;
    lightSource = false;
    soundType = 3;

}
block_t HalfBlock2::getID(){ return 85;}

HalfBlock3::HalfBlock3():BaseBlock()
{
    textureRow = 4;

    upPlane = 0;
    downPlane = 0;
    sidePlane = 10;
    editable = true;
    transparent = false;
    blockSpecial = true;
    lightSource = false;
    soundType = 3;

}
block_t HalfBlock3::getID(){ return 86;}

HalfBlock4::HalfBlock4():BaseBlock()
{
    textureRow = 5;

    upPlane = 7;
    downPlane = 7;
    sidePlane = 10;
    editable = true;
    transparent = false;
    blockSpecial = true;
    lightSource = false;
    soundType = 3;

}
block_t HalfBlock4::getID(){ return 87;}

HalfBlock5::HalfBlock5():BaseBlock()
{
    textureRow = 5;

    upPlane = 8;
    downPlane = 8;
    sidePlane = 11;
    editable = true;
    transparent = false;
    blockSpecial = true;
    lightSource = false;
    soundType = 3;

}
block_t HalfBlock5::getID(){ return 88;}

HalfBlock6::HalfBlock6():BaseBlock()
{
    textureRow = 6;

    upPlane = 8;
    downPlane = 8;
    sidePlane = 10;
    editable = true;
    transparent = false;
    blockSpecial = true;
    lightSource = false;
    soundType = 3;

}
block_t HalfBlock6::getID(){ return 89;}

HalfBlock7::HalfBlock7():BaseBlock()
{
    textureRow = 6;

    upPlane = 9;
    downPlane = 9;
    sidePlane = 11;
    editable = true;
    transparent = false;
    blockSpecial = true;
    lightSource = false;
    soundType = 3;

}
block_t HalfBlock7::getID(){ return 90;}

Cake::Cake():BaseBlock()
{
    textureRow = 0;

    upPlane = 11;
    downPlane = 13;
    sidePlane = 12;
    editable = true;
    transparent = false;
    blockSpecial = true;
    lightSource = false;

}
block_t Cake::getID(){ return 91;}

TrapDoor::TrapDoor():BaseBlock()
{
    textureRow = 8;

    upPlane = 11;
    downPlane = 11;
    sidePlane = 12;
    editable = true;
    transparent = true;
    blockSpecial = true;
    lightSource = false;
    soundType = 3;

}
block_t TrapDoor::getID(){ return 92;}

Snow2::Snow2():BaseBlock()
{
    textureRow = 0;

    upPlane = 4;
    downPlane = 4;
    sidePlane = 4;
    editable = true;
    transparent = false;
    blockSpecial = true;
    lightSource = false;
    soundType = 5;

}
block_t Snow2::getID(){ return 93;}

Table::Table():BaseBlock()
{
    textureRow = 9;

    upPlane = 10;
    downPlane = 8;
    sidePlane = 9;
    editable = true;
    transparent = false;
    blockSpecial = true;
    lightSource = false;
    soundType = 2;

}
block_t Table::getID(){ return 94;}

AetherStone::AetherStone():BaseBlock()
{
    textureRow = 9;

    upPlane = 11;
    downPlane = 11;
    sidePlane = 11;
    editable = true;
    transparent = false;
    lightSource = false;
    soundType = 2;

}
block_t AetherStone::getID(){ return 95;}

MushRoomLeave::MushRoomLeave():BaseBlock()
{
    textureRow = 8;

    upPlane = 10;
    downPlane = 8;
    sidePlane = 10;
    editable = true;
    transparent = false;
    lightSource = false;
    soundType = 3;

}
block_t MushRoomLeave::getID(){ return 96;}

MossAetherStone::MossAetherStone():BaseBlock()
{
    textureRow = 10;

    upPlane = 0;
    downPlane = 0;
    sidePlane = 0;
    editable = true;
    transparent = false;
    lightSource = false;
    soundType = 2;

}
block_t MossAetherStone::getID(){ return 97;}

WoodPlate::WoodPlate():BaseBlock()
{
    textureRow = 4;

	upPlane = 0;
	downPlane = 0;
	sidePlane = 0;
	editable = true;
	transparent = false;
	blockSpecial = true;
	soundType = 3;


}
block_t WoodPlate::getID(){ return 98;}

StonePlate::StonePlate():BaseBlock()
{
    textureRow = 1;

	upPlane = 0;
	downPlane = 0;
	sidePlane = 0;
	editable = true;
	transparent = false;
	blockSpecial = true;
	soundType = 2;

}
block_t StonePlate::getID(){ return 99;}

Fence::Fence():BaseBlock()
{
    textureRow = 4;

	upPlane = 0;
	downPlane = 0;
	sidePlane = 0;
	editable = true;
	transparent = false;
	blockSpecial = true;
	soundType = 3;

}
block_t Fence::getID(){ return 100;}

NetherFence::NetherFence():BaseBlock()
{
    textureRow = 0;

    upPlane = 1;
    downPlane = 1;
    sidePlane = 1;
    editable = true;
    transparent = false;
    blockSpecial = true;
    soundType = 2;

}
block_t NetherFence::getID(){ return 101;}

CobWeb::CobWeb():BaseBlock()
{
    textureRow = 10;

    upPlane = 5;
    downPlane = 5;
    sidePlane = 5;
    editable = true;
    transparent = true;
    lightSource = false;
    soundType = 2;

}
block_t CobWeb::getID(){ return 102;}

AetherBlock6::AetherBlock6():BaseBlock()
{
    textureRow = 10;

    upPlane = 6;
    downPlane = 6;
    sidePlane = 6;
    editable = true;
    transparent = false;
    lightSource = false;
    soundType = 2;

}
block_t AetherBlock6::getID(){ return 103;}

Furnace::Furnace():BaseBlock()
{
    textureRow = 10;

    upPlane = 7;
    downPlane = 7;
    sidePlane = 8;
    editable = true;
    transparent = false;
    lightSource = false;
    soundType = 2;

}
block_t Furnace::getID(){ return 104;}

Crafting::Crafting():BaseBlock()
{
    textureRow = 10;

    upPlane = 10;
    downPlane = 10;
    sidePlane = 11;
    editable = true;
    transparent = false;
    lightSource = false;
    soundType = 3;

}
block_t Crafting::getID(){ return 105;}

JungleLeaves::JungleLeaves():BaseBlock()
{
    textureRow = 7;

    upPlane = 10;
    downPlane = 10;
    sidePlane = 10;
    editable = true;
    transparent = false;
    lightSource = false;
    soundType = 0;

}
block_t JungleLeaves::getID(){ return 106;}

WaterFlow::WaterFlow():BaseBlock()
{
	textureRow = 3;

	upPlane = 2;
	downPlane = 2;
	sidePlane = 2;
	editable = false;
	transparent = true;
	soundType = -1;
	blockSpecial = true;
}
block_t WaterFlow::getID(){ return 107;}

LampOn::LampOn():BaseBlock()
{
	textureRow = 12;

	upPlane = 1;
	downPlane = 1;
	sidePlane = 1;
	editable = true;
	transparent = false;
	soundType = 2;
	lightSource = true;
	blockSpecial = false;
}
block_t LampOn::getID(){ return 108;}

GreyRock::GreyRock():BaseBlock()
{
    textureRow = 2;

    upPlane = 11;
    downPlane = 11;
    sidePlane = 11;
    editable = true;
    transparent = false;
    lightSource = false;
    soundType = 1;

}
block_t GreyRock::getID(){ return 109;}

TNT::TNT():BaseBlock()
{
    textureRow = 1;

    upPlane = 13;
    downPlane = 12;
    sidePlane = 14;
    editable = true;
    transparent = false;
    lightSource = false;
    soundType = 1;

}
block_t TNT::getID(){ return 110;}

Nuclear::Nuclear():BaseBlock()
{
    textureRow = 1;

    upPlane = 15;
    downPlane = 15;
    sidePlane = 15;
    editable = true;
    transparent = false;
    lightSource = false;
    soundType = 1;

}
block_t Nuclear::getID(){ return 111;}

Lava::Lava():BaseBlock()
{
    textureRow = 11;

    upPlane = 0;
    downPlane = 0;
    sidePlane = 0;
    editable = false;
    transparent = true;
    blockSpecial = true;
    lightSource = true;

}
block_t Lava::getID(){ return 112;}

Gravel::Gravel():BaseBlock()
{
    textureRow = 11;

    upPlane = 1;
    downPlane = 1;
    sidePlane = 1;
    editable = true;
    transparent = false;
    lightSource = false;
    soundType = 1;

}
block_t Gravel::getID(){ return 113;}

EmeraldBlock::EmeraldBlock():BaseBlock()
{
    textureRow = 11;

    upPlane = 2;
    downPlane = 2;
    sidePlane = 2;
    editable = true;
    transparent = false;
    lightSource = false;
    soundType = 2;

}
block_t EmeraldBlock::getID(){ return 114;}

EmeraldOre::EmeraldOre():BaseBlock()
{
    textureRow = 11;

    upPlane = 3;
    downPlane = 3;
    sidePlane = 3;
    editable = true;
    transparent = false;
    lightSource = false;
    soundType = 2;

}
block_t EmeraldOre::getID(){ return 115;}

LapisOre::LapisOre():BaseBlock()
{
    textureRow = 11;

    upPlane = 4;
    downPlane = 4;
    sidePlane = 4;
    editable = true;
    transparent = false;
    lightSource = false;
    soundType = 2;

}
block_t LapisOre::getID(){ return 116;}

LapisBlock::LapisBlock():BaseBlock()
{
    textureRow = 11;

    upPlane = 5;
    downPlane = 5;
    sidePlane = 5;
    editable = true;
    transparent = false;
    lightSource = false;
    soundType = 2;

}
block_t LapisBlock::getID(){ return 117;}

NoteBlock::NoteBlock():BaseBlock()
{
    textureRow = 8;

	upPlane = 5;
	downPlane = 5;
	sidePlane = 5;
	editable = true;
	transparent = false;
	soundType = 3;

}
block_t NoteBlock::getID(){ return 118;}

Chest::Chest():BaseBlock()
{
    textureRow = 10;

	upPlane = 4;
	downPlane = 4;
	sidePlane = 3;
	editable = true;
	transparent = false;
	soundType = 3;

}
block_t Chest::getID(){ return 119;}

Sapling1::Sapling1():BaseBlock()
{
    textureRow = 5;

	upPlane = 14;
	downPlane = 14;
	sidePlane = 13;
	editable = true;
	transparent = true;
	soundType = -1;

}
block_t Sapling1::getID(){ return 120;}

Sapling2::Sapling2():BaseBlock()
{
    textureRow = 4;

	upPlane = 15;
	downPlane = 15;
	sidePlane = 13;
	editable = true;
	transparent = true;
	soundType = -1;

}
block_t Sapling2::getID(){ return 121;}

Sapling3::Sapling3():BaseBlock()
{
    textureRow = 3;

	upPlane = 14;
	downPlane = 14;
	sidePlane = 13;
	editable = true;
	transparent = true;
	soundType = -1;

}
block_t Sapling3::getID(){ return 122;}

endPortal::endPortal():BaseBlock()
{
    textureRow = 0;

	upPlane = 14;
	downPlane = 10;
	sidePlane = 15;
	editable = true;
	blockSpecial = true;
	transparent = false;
	soundType = 2;

}
block_t endPortal::getID(){ return 123;}

dispenser::dispenser():BaseBlock()
{
    textureRow = 10;

	upPlane = 7;
	downPlane = 7;
	sidePlane = 2;
	editable = true;
	transparent = false;
	soundType = 2;

}
block_t dispenser::getID(){ return 124;}

wheat::wheat():BaseBlock()
{
    textureRow = 3;

	upPlane = 14;
	downPlane = 14;
	sidePlane = 12;
	editable = true;
	transparent = true;
	soundType = -1;

}
block_t wheat::getID(){ return 125;}

wines::wines():BaseBlock()
{
    textureRow = 10;

	upPlane = 1;
	downPlane = 1;
	sidePlane = 1;
	editable = true;
	blockSpecial = true;
	transparent = true;
	soundType = -1;

}
block_t wines::getID(){ return 126;}

netherWarp::netherWarp():BaseBlock()
{
    textureRow = 2;

	upPlane = 15;
	downPlane = 15;
	sidePlane = 14;
	editable = true;
	transparent = true;
	soundType = -1;

}
block_t netherWarp::getID(){ return 127;}

Fire::Fire():BaseBlock()
{
    textureRow = 7;

	upPlane = 13;
	downPlane = 13;
	sidePlane = 12;
	editable = false;
	transparent = true;
	soundType = -1;

}
block_t Fire::getID(){ return 128;}

supriseblock::supriseblock():BaseBlock()
{
    textureRow = 6;

	upPlane = 12;
	downPlane = 12;
	sidePlane = 12;
	editable = true;
	transparent = true;
	soundType = 2;
}
block_t supriseblock::getID(){ return 129;}

quartzBlock::quartzBlock():BaseBlock()
{
    textureRow = 11;

	upPlane = 7;
	downPlane = 6;
	sidePlane = 8;
	editable = true;
	transparent = false;
	soundType = 2;
}
block_t quartzBlock::getID(){ return 130;}

quartzBlockLines::quartzBlockLines():BaseBlock()
{
    textureRow = 11;

	upPlane = 9;
	downPlane = 9;
	sidePlane = 10;
	editable = true;
	transparent = false;
	soundType = 2;
}
block_t quartzBlockLines::getID(){ return 131;}

quartzBlockChiseled::quartzBlockChiseled():BaseBlock()
{
    textureRow = 11;

	upPlane = 12;
	downPlane = 12;
	sidePlane = 11;
	editable = true;
	transparent = false;
	soundType = 2;
}
block_t quartzBlockChiseled::getID(){ return 132;}

quartzSlap::quartzSlap():BaseBlock()
{
	textureRow = 11;

	upPlane = 7;
	downPlane = 6;
	sidePlane = 13;
	editable = true;
	transparent = false;
	blockSpecial = true;
	soundType = 2;
}
block_t quartzSlap::getID(){ return 133;}

brickWallSlap::brickWallSlap():BaseBlock()
{
	textureRow = 4;

	upPlane = 7;
	downPlane = 7;
	sidePlane = 14;
	editable = true;
	transparent = false;
	blockSpecial = true;
	soundType = 2;
}
block_t brickWallSlap::getID(){ return 134;}

redStoneBlock::redStoneBlock():BaseBlock()
{
	textureRow = 9;

	upPlane = 12;
	downPlane = 12;
	sidePlane = 12;
	editable = true;
	transparent = false;
	soundType = 2;
}
block_t redStoneBlock::getID(){ return 135;}

netherQuartz::netherQuartz():BaseBlock()
{
	textureRow = 9;

	upPlane = 13;
	downPlane = 13;
	sidePlane = 13;
	editable = true;
	transparent = false;
	soundType = 2;
}
block_t netherQuartz::getID(){ return 136;}

RSLampOFF::RSLampOFF():BaseBlock()
{
	textureRow = 12;

	upPlane = 2;
	downPlane = 2;
	sidePlane = 2;
	editable = true;
	transparent = false;
	soundType = 2;
}
block_t RSLampOFF::getID(){ return 137;}

JunglePlant::JunglePlant():BaseBlock()
{
	textureRow = 12;

	upPlane = 15;
	downPlane = 15;
	sidePlane = 3;
	editable = true;
	transparent = true;
	soundType = -1;
}
block_t JunglePlant::getID(){ return 138;}

Brad0::Brad0():BaseBlock()
{
	textureRow = 12;

	upPlane = 15;
	downPlane = 15;
	sidePlane = 4;
	editable = true;
	transparent = true;
	soundType = -1;
}
block_t Brad0::getID(){ return 139;}

Brad1::Brad1():BaseBlock()
{
	textureRow = 12;

	upPlane = 15;
	downPlane = 15;
	sidePlane = 5;
	editable = true;
	transparent = true;
	soundType = -1;
}
block_t Brad1::getID(){ return 140;}

Pist0::Pist0():BaseBlock()
{
	textureRow = 12;

	upPlane = 6;
	downPlane = 6;
	sidePlane = 6;
	editable = true;
	transparent = false;
	soundType = 2;
}
block_t Pist0::getID(){ return 141;}

Pist1::Pist1():BaseBlock()
{
	textureRow = 12;

	upPlane = 7;
	downPlane = 7;
	sidePlane = 7;
	editable = true;
	transparent = false;
	soundType = 3;
}
block_t Pist1::getID(){ return 142;}

Pist2::Pist2():BaseBlock()
{
	textureRow = 12;

	upPlane = 8;
	downPlane = 8;
	sidePlane = 8;
	editable = true;
	transparent = false;
	soundType = 3;
}
block_t Pist2::getID(){ return 143;}

NP::NP():BaseBlock()
{
	textureRow = 12;

	upPlane = 9;
	downPlane = 9;
	sidePlane = 9;
	editable = true;
	transparent = true;
	soundType = 2;
}
block_t NP::getID(){ return 144;}

Caul::Caul():BaseBlock()
{
	textureRow = 12;

	upPlane = 10;
	downPlane = 10;
	sidePlane = 10;
	editable = true;
	transparent = false;
	soundType = 2;
}
block_t Caul::getID(){ return 145;}

Art1::Art1():BaseBlock()
{
	textureRow = 13;

	upPlane = 1;
	downPlane = 1;
	sidePlane = 1;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t Art1::getID(){ return 146;}

Art2::Art2():BaseBlock()
{
	textureRow = 13;

	upPlane = 2;
	downPlane = 2;
	sidePlane = 2;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t Art2::getID(){ return 147;}

Art3::Art3():BaseBlock()
{
	textureRow = 13;

	upPlane = 3;
	downPlane = 3;
	sidePlane = 3;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t Art3::getID(){ return 148;}

Art4::Art4():BaseBlock()
{
	textureRow = 13;

	upPlane = 4;
	downPlane = 4;
	sidePlane = 4;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t Art4::getID(){ return 149;}

Art5::Art5():BaseBlock()
{
	textureRow = 13;

	upPlane = 5;
	downPlane = 5;
	sidePlane = 5;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t Art5::getID(){ return 150;}

Art6::Art6():BaseBlock()
{
	textureRow = 13;

	upPlane = 6;
	downPlane = 6;
	sidePlane = 6;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t Art6::getID(){ return 151;}

Art7::Art7():BaseBlock()
{
	textureRow = 13;

	upPlane = 7;
	downPlane = 7;
	sidePlane = 7;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t Art7::getID(){ return 152;}

//ArtBig

Art8::Art8():BaseBlock()
{
	textureRow = 13;

	upPlane = 8;
	downPlane = 8;
	sidePlane = 8;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t Art8::getID(){ return 153;}

Art9::Art9():BaseBlock()
{
	textureRow = 13;

	upPlane = 9;
	downPlane = 9;
	sidePlane = 9;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t Art9::getID(){ return 154;}

Art10::Art10():BaseBlock()
{
	textureRow = 13;

	upPlane = 10;
	downPlane = 10;
	sidePlane = 10;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t Art10::getID(){ return 155;}

Art11::Art11():BaseBlock()
{
	textureRow = 13;

	upPlane = 11;
	downPlane = 11;
	sidePlane = 11;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t Art11::getID(){ return 156;}

//ArtBig

//Flowers

YellowF::YellowF():BaseBlock()
{
	textureRow = 13;

	upPlane = 12;
	downPlane = 12;
	sidePlane = 12;
	editable = true;
	transparent = true;
	soundType = -1;
}
block_t YellowF::getID(){ return 157;}

RedF::RedF():BaseBlock()
{
	textureRow = 13;

	upPlane = 13;
	downPlane = 13;
	sidePlane = 13;
	editable = true;
	transparent = true;
	soundType = -1;
}
block_t RedF::getID(){ return 158;}

//Flowers End




//UpHlina End


//1.6.2 Start

//Hay Block Start

Hay::Hay():BaseBlock()
{
	textureRow = 14;

	upPlane = 1;
	downPlane = 1;
	sidePlane = 0;
	editable = true;
	transparent = false;
	soundType = 0;
}
block_t Hay::getID(){ return 159;}

//Hay Block End

//Hardened Clay Start

HC0::HC0():BaseBlock()
{
	textureRow = 14;

	upPlane = 2;
	downPlane = 2;
	sidePlane = 2;
	editable = true;
	transparent = false;
	soundType = 0;
}
block_t HC0::getID(){ return 160;}

HC1::HC1():BaseBlock()
{
	textureRow = 14;

	upPlane = 3;
	downPlane = 3;
	sidePlane = 3;
	editable = true;
	transparent = false;
	soundType = 0;
}
block_t HC1::getID(){ return 161;}

HC2::HC2():BaseBlock()
{
	textureRow = 14;

	upPlane = 4;
	downPlane = 4;
	sidePlane = 4;
	editable = true;
	transparent = false;
	soundType = 0;
}
block_t HC2::getID(){ return 162;}

//4 Other:

HC3::HC3():BaseBlock()
{
	textureRow = 14;

	upPlane = 5;
	downPlane = 5;
	sidePlane = 5;
	editable = true;
	transparent = false;
	soundType = 0;
}
block_t HC3::getID(){ return 163;}

HC4::HC4():BaseBlock()
{
	textureRow = 14;

	upPlane = 6;
	downPlane = 6;
	sidePlane = 6;
	editable = true;
	transparent = false;
	soundType = 0;
}
block_t HC4::getID(){ return 164;}

HC5::HC5():BaseBlock()
{
	textureRow = 14;

	upPlane = 7;
	downPlane = 7;
	sidePlane = 7;
	editable = true;
	transparent = false;
	soundType = 0;
}
block_t HC5::getID(){ return 165;}

HC6::HC6():BaseBlock()
{
	textureRow = 14;

	upPlane = 8;
	downPlane = 8;
	sidePlane = 8;
	editable = true;
	transparent = false;
	soundType = 0;
}
block_t HC6::getID(){ return 166;}

//4 Other End

//10 Other Start

HC7::HC7():BaseBlock()
{
	textureRow = 15;

	upPlane = 0;
	downPlane = 0;
	sidePlane = 0;
	editable = true;
	transparent = false;
	soundType = 0;
}
block_t HC7::getID(){ return 167;}

HC8::HC8():BaseBlock()
{
	textureRow = 15;

	upPlane = 1;
	downPlane = 1;
	sidePlane = 1;
	editable = true;
	transparent = false;
	soundType = 0;
}
block_t HC8::getID(){ return 168;}

HC9::HC9():BaseBlock()
{
	textureRow = 15;

	upPlane = 2;
	downPlane = 2;
	sidePlane = 2;
	editable = true;
	transparent = false;
	soundType = 0;
}
block_t HC9::getID(){ return 169;}

HC10::HC10():BaseBlock()
{
	textureRow = 15;

	upPlane = 3;
	downPlane = 3;
	sidePlane = 3;
	editable = true;
	transparent = false;
	soundType = 0;
}
block_t HC10::getID(){ return 170;}

HC11::HC11():BaseBlock()
{
	textureRow = 15;

	upPlane = 4;
	downPlane = 4;
	sidePlane = 4;
	editable = true;
	transparent = false;
	soundType = 0;
}
block_t HC11::getID(){ return 171;}

HC12::HC12():BaseBlock()
{
	textureRow = 15;

	upPlane = 5;
	downPlane = 5;
	sidePlane = 5;
	editable = true;
	transparent = false;
	soundType = 0;
}
block_t HC12::getID(){ return 172;}

HC13::HC13():BaseBlock()
{
	textureRow = 15;

	upPlane = 6;
	downPlane = 6;
	sidePlane = 6;
	editable = true;
	transparent = false;
	soundType = 0;
}
block_t HC13::getID(){ return 173;}

HC14::HC14():BaseBlock()
{
	textureRow = 15;

	upPlane = 7;
	downPlane = 7;
	sidePlane = 7;
	editable = true;
	transparent = false;
	soundType = 0;
}
block_t HC14::getID(){ return 174;}

HC15::HC15():BaseBlock()
{
	textureRow = 15;

	upPlane = 8;
	downPlane = 8;
	sidePlane = 8;
	editable = true;
	transparent = false;
	soundType = 0;
}
block_t HC15::getID(){ return 175;}

HC16::HC16():BaseBlock()
{
	textureRow = 15;

	upPlane = 9;
	downPlane = 9;
	sidePlane = 9;
	editable = true;
	transparent = false;
	soundType = 0;
}
block_t HC16::getID(){ return 176;}

//10 Other End
//Hardened Clay End


//1.6.2 End
SKLO::SKLO():BaseBlock()
{
	textureRow = 16;

	upPlane = 0;
	downPlane = 0;
	sidePlane = 0;
	editable = true;
	transparent = true;
	soundType = -1;
}
block_t SKLO::getID(){ return 177;}

JS::JS():BaseBlock()
{
	textureRow = 16;

	upPlane = 1;
	downPlane = 1;
	sidePlane = 1;
	editable = true;
	transparent = true;
	soundType = -1;
}
block_t JS::getID(){ return 178;}

RS::RS():BaseBlock()
{
	textureRow = 16;

	upPlane = 2;
	downPlane = 2;
	sidePlane = 2;
	editable = true;
	transparent = true;
	soundType = -1;
}
block_t RS::getID(){ return 179;}

KOL1::KOL1():BaseBlock()
{
	textureRow = 16;

	upPlane = 3;
	downPlane = 3;
	sidePlane = 3;
	editable = true;
	transparent = true;
	soundType = -1;
}
block_t KOL1::getID(){ return 180;}

KOL2::KOL2():BaseBlock()
{
	textureRow = 16;

	upPlane = 4;
	downPlane = 4;
	sidePlane = 4;
	editable = true;
	transparent = true;
	soundType = -1;
}
block_t KOL2::getID(){ return 181;}

OBR1::OBR1():BaseBlock()
{
	textureRow = 17;

	upPlane = 0;
	downPlane = 0;
	sidePlane = 0;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t OBR1::getID(){ return 182;}

OBR2::OBR2():BaseBlock()
{
	textureRow = 17;

	upPlane = 1;
	downPlane = 1;
	sidePlane = 1;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t OBR2::getID(){ return 183;}

OBR3::OBR3():BaseBlock()
{
	textureRow = 18;

	upPlane = 0;
	downPlane = 0;
	sidePlane = 0;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t OBR3::getID(){ return 184;}

OBR4::OBR4():BaseBlock()
{
	textureRow = 18;

	upPlane = 1;
	downPlane = 1;
	sidePlane = 1;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t OBR4::getID(){ return 185;}

ColoredGlass0::ColoredGlass0():BaseBlock()
{
	textureRow = 21;

	upPlane = 0;
	downPlane = 0;
	sidePlane = 0;
	editable = true;
	transparent = true;
	soundType = -1;
}
block_t ColoredGlass0::getID(){ return 186;}

ColoredGlass1::ColoredGlass1():BaseBlock()
{
	textureRow = 21;

	upPlane = 1;
	downPlane = 1;
	sidePlane = 1;
	editable = true;
	transparent = true;
	soundType = -1;
}
block_t ColoredGlass1::getID(){ return 187;}

ColoredGlass2::ColoredGlass2():BaseBlock()
{
	textureRow = 21;

	upPlane = 2;
	downPlane = 2;
	sidePlane = 2;
	editable = true;
	transparent = true;
	soundType = -1;
}
block_t ColoredGlass2::getID(){ return 188;}

ColoredGlass3::ColoredGlass3():BaseBlock()
{
	textureRow = 21;

	upPlane = 3;
	downPlane = 3;
	sidePlane = 3;
	editable = true;
	transparent = true;
	soundType = -1;
}
block_t ColoredGlass3::getID(){ return 189;}

ColoredGlass4::ColoredGlass4():BaseBlock()
{
	textureRow = 21;

	upPlane = 4;
	downPlane = 4;
	sidePlane = 4;
	editable = true;
	transparent = true;
	soundType = -1;
}
block_t ColoredGlass4::getID(){ return 190;}

ColoredGlass5::ColoredGlass5():BaseBlock()
{
	textureRow = 21;

	upPlane = 5;
	downPlane = 5;
	sidePlane = 5;
	editable = true;
	transparent = true;
	soundType = -1;
}
block_t ColoredGlass5::getID(){ return 191;}

ColoredGlass6::ColoredGlass6():BaseBlock()
{
	textureRow = 21;

	upPlane = 6;
	downPlane = 6;
	sidePlane = 6;
	editable = true;
	transparent = true;
	soundType = -1;
}
block_t ColoredGlass6::getID(){ return 192;}

ColoredGlass7::ColoredGlass7():BaseBlock()
{
	textureRow = 21;

	upPlane = 7;
	downPlane = 7;
	sidePlane = 7;
	editable = true;
	transparent = true;
	soundType = -1;
}
block_t ColoredGlass7::getID(){ return 193;}

ColoredGlass8::ColoredGlass8():BaseBlock()
{
	textureRow = 21;

	upPlane = 8;
	downPlane = 8;
	sidePlane = 8;
	editable = true;
	transparent = true;
	soundType = -1;
}
block_t ColoredGlass8::getID(){ return 194;}

ColoredGlass9::ColoredGlass9():BaseBlock()
{
	textureRow = 21;

	upPlane = 9;
	downPlane = 9;
	sidePlane = 9;
	editable = true;
	transparent = true;
	soundType = -1;
}
block_t ColoredGlass9::getID(){ return 195;}

UserBlock0::UserBlock0():BaseBlock()
{
	textureRow = 22;

	upPlane = 0;
	downPlane = 0;
	sidePlane = 0;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t UserBlock0::getID(){ return 196;}

UserBlock1::UserBlock1():BaseBlock()
{
	textureRow = 22;

	upPlane = 2;
	downPlane = 2;
	sidePlane = 1;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t UserBlock1::getID(){ return 197;}

UserBlock2::UserBlock2():BaseBlock()
{
	textureRow = 22;

	upPlane = 3;
	downPlane = 3;
	sidePlane = 3;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t UserBlock2::getID(){ return 198;}

UserBlock3::UserBlock3():BaseBlock()
{
	textureRow = 22;

	upPlane = 4;
	downPlane = 4;
	sidePlane = 4;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t UserBlock3::getID(){ return 199;}

UserBlock4::UserBlock4():BaseBlock()
{
	textureRow = 22;

	upPlane = 5;
	downPlane = 5;
	sidePlane = 5;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t UserBlock4::getID(){ return 200;}

UserBlock5::UserBlock5():BaseBlock()
{
	textureRow = 22;

	upPlane = 7;
	downPlane = 8;
	sidePlane = 6;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t UserBlock5::getID(){ return 201;}

UserBlock6::UserBlock6():BaseBlock()
{
	textureRow = 22;

	upPlane = 10;
	downPlane = 10;
	sidePlane = 10;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t UserBlock6::getID(){ return 202;}

UserBlock7::UserBlock7():BaseBlock()
{
	textureRow = 22;

	upPlane = 11;
	downPlane = 11;
	sidePlane = 11;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t UserBlock7::getID(){ return 203;}

UserBlock8::UserBlock8():BaseBlock()
{
	textureRow = 22;

	upPlane = 12;
	downPlane = 12;
	sidePlane = 12;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t UserBlock8::getID(){ return 204;}

UserBlock9::UserBlock9():BaseBlock()
{
	textureRow = 22;

	upPlane = 13;
	downPlane = 13;
	sidePlane = 13;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t UserBlock9::getID(){ return 205;}

UserBlock10::UserBlock10():BaseBlock()
{
	textureRow = 22;

	upPlane = 15;
	downPlane = 16;
	sidePlane = 14;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t UserBlock10::getID(){ return 206;}

UserBlock11::UserBlock11():BaseBlock()
{
	textureRow = 22;

	upPlane = 17;
	downPlane = 17;
	sidePlane = 18;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t UserBlock11::getID(){ return 207;}

UserBlock12::UserBlock12():BaseBlock()
{
	textureRow = 22;

	upPlane = 19;
	downPlane = 19;
	sidePlane = 19;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t UserBlock12::getID(){ return 208;}

UserBlock13::UserBlock13():BaseBlock()
{
	textureRow = 22;

	upPlane = 20;
	downPlane = 20;
	sidePlane = 20;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t UserBlock13::getID(){ return 209;}

UserBlock14::UserBlock14():BaseBlock()
{
	textureRow = 22;

	upPlane = 22;
	downPlane = 22;
	sidePlane = 21;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t UserBlock14::getID(){ return 210;}

UserBlock15::UserBlock15():BaseBlock()
{
	textureRow = 22;

	upPlane = 23;
	downPlane = 23;
	sidePlane = 23;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t UserBlock15::getID(){ return 211;}

UserBlock16::UserBlock16():BaseBlock()
{
	textureRow = 22;

	upPlane = 24;
	downPlane = 24;
	sidePlane = 24;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t UserBlock16::getID(){ return 212;}

UserBlock18::UserBlock18():BaseBlock()
{
	textureRow = 22;

	upPlane = 27;
	downPlane = 27;
	sidePlane = 26;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t UserBlock18::getID(){ return 213;}

UserBlock19::UserBlock19():BaseBlock()
{
	textureRow = 22;

	upPlane = 28;
	downPlane = 28;
	sidePlane = 28;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t UserBlock19::getID(){ return 214;}

UserBlock20::UserBlock20():BaseBlock()
{
	textureRow = 23;

	upPlane = 1;
	downPlane = 1;
	sidePlane = 0;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t UserBlock20::getID(){ return 215;}

UserBlock21::UserBlock21():BaseBlock()
{
	textureRow = 23;

	upPlane = 2;
	downPlane = 2;
	sidePlane = 2;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t UserBlock21::getID(){ return 216;}

UserBlock22::UserBlock22():BaseBlock()
{
	textureRow = 23;

	upPlane = 3;
	downPlane = 3;
	sidePlane = 3;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t UserBlock22::getID(){ return 217;}

UserBlock23::UserBlock23():BaseBlock()
{
	textureRow = 23;

	upPlane = 4;
	downPlane = 4;
	sidePlane = 4;
	editable = true;
	transparent = false;
	soundType = -1;
}
block_t UserBlock23::getID(){ return 218;}

EmptyBlock0::EmptyBlock0():BaseBlock()
{
	textureRow = 32;

	upPlane = 29;
	downPlane = 29;
	sidePlane = 29;
	editable = true;
	transparent = true;
	soundType = -1;
}
block_t EmptyBlock0::getID(){ return 219;}




//must be last
MelonBlock::MelonBlock():BaseBlock()
{
    textureRow = 8;

    upPlane = 4;
    downPlane = 4;
    sidePlane = 3;
    editable = true;
    transparent = false;
    soundType = 3;

}
block_t MelonBlock::getID(){ return 220;}

LifeBlock::LifeBlock():BaseBlock()
{
	textureRow = 12;

	upPlane = 1;
	downPlane = 1;
	sidePlane = 0;
	editable = true;
	transparent = true;
	soundType = -1;

}
block_t LifeBlock::getID(){ return 221;}

EnderTop::EnderTop():BaseBlock()
{
	textureRow = 14;

	upPlane = 11;
	downPlane = 1;
	sidePlane = 14;
	editable = true;
	transparent = true;
	soundType = 2;

}
block_t EnderTop::getID(){ return 222;}

EnderLegs::EnderLegs():BaseBlock()
{
	textureRow = 15;

	upPlane = 1;
	downPlane = 1;
	sidePlane = 14;
	editable = true;
	transparent = true;
	soundType = 2;

}
block_t EnderLegs::getID(){ return 223;}

ZombieTop::ZombieTop():BaseBlock()
{
	textureRow = 14;

	upPlane = 12;
	downPlane = 1;
	sidePlane = 15;
	editable = true;
	transparent = true;
	soundType = 2;

}
block_t ZombieTop::getID(){ return 224;}

ZombieLegs::ZombieLegs():BaseBlock()
{
	textureRow = 15;

	upPlane = 1;
	downPlane = 1;
	sidePlane = 15;
	editable = true;;
	transparent = true;
	soundType = 2;

}
block_t ZombieLegs::getID(){ return 225;}

TrapDoor2::TrapDoor2():BaseBlock()
{
    textureRow = 8;

    upPlane = 12;
    downPlane = 12;
    sidePlane = 11;
    editable = true;
    transparent = true;
    lightSource = false;
    blockSpecial = true;
    soundType = 3;
}
block_t TrapDoor2::getID(){ return 226;}


Door3::Door3():BaseBlock()
{
	textureRow = 3;

	upPlane = 11;
	downPlane = 11;
	sidePlane = 9;
	editable = true;
	transparent = true;
	blockSpecial = true;
	soundType = 3;

}
block_t Door3::getID(){ return 227;}

Door4::Door4():BaseBlock()
{
	textureRow = 4;

	upPlane = 9;
	downPlane = 9;
	sidePlane = 9;
	editable = true;
	transparent = true;
	blockSpecial = true;
	soundType = 3;
}
block_t Door4::getID(){ return 228;}

Furnace2::Furnace2():BaseBlock()
{
    textureRow = 10;

    upPlane = 7;
    downPlane = 7;
    sidePlane = 9;
    editable = true;
    transparent = false;
    lightSource = true;
    soundType = 2;

}
block_t Furnace2::getID(){ return 229;}

Cloud::Cloud():BaseBlock()
{
    textureRow = 7;

    upPlane = 9;
    downPlane = 9;
    sidePlane = 9;
    editable = false;
    transparent = true;

}
block_t Cloud::getID(){ return 230;}

IronBlock::IronBlock():BaseBlock()
{
	textureRow = 1;

	upPlane = 1;
	downPlane = 1;
	sidePlane = 1;
	editable = true;;
	transparent = false;
	soundType = 2;

}
block_t IronBlock::getID(){ return 231;}
