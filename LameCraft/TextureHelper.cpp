#include "TextureHelper.h"
#include <Aurora/Graphics/RenderManager.h>

TextureHelper::TextureHelper()
{
	defaulPatch = "Assets/";
	defaultFolder = "Lamecraft/";
	texturePatch = "Assets/Lamecraft/";
}

TextureHelper::~TextureHelper()
{

}

int TextureHelper::GetTexture(Textures texture)
{
	switch(texture)
	{
		case Genesis:
		{
			fileName = texturePatch + "genesis.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case PspTeam:
		{
			fileName = texturePatch + "pspteam.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Logo:
		{
			fileName = texturePatch + "Moon.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Utils:
		{
			fileName = texturePatch + "utils.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Dirt:
		{
			fileName = texturePatch + "dirt.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Glass:
		{
			fileName = texturePatch + "glass.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Terrain:
		{
			fileName = texturePatch + "terrain_medium.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Blue:
		{
			fileName = texturePatch + "blue.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Sky:
		{
			fileName = texturePatch + "sky.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Sun:
		{
			fileName = texturePatch + "sun.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Moon:
		{
			fileName = texturePatch + "moon.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case lameCraft:
		{
			fileName = texturePatch + "logo.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Red:
		{
			fileName = texturePatch + "red.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case RainSky:
		{
			fileName = texturePatch + "rainSky.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Panorama1:
		{
			fileName = texturePatch + "panorama1.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Panorama2:
		{
			fileName = texturePatch + "panorama2.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Panorama3:
		{
			fileName = texturePatch + "panorama3.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Panorama4:
		{
			fileName = texturePatch + "panorama4.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		case menuTool:
		{
		    fileName = texturePatch + "menuTool.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		case char1:
		{
		        fileName = texturePatch + "mod/char.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName); 
		}
                case Inventory:
		{
			fileName = texturePatch + "mod/inventory.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Thinks:
		{
			fileName = texturePatch + "mod/thinks.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case chat:
		{
			fileName = texturePatch + "mod/chat.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case bilo:
		{
			fileName = texturePatch + "mod/bilo.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case invchar1:
		{
		        fileName = texturePatch + "mod/invchar.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName); 
		}
		case button0:
		{
		        fileName = texturePatch + "mod/0.4/planned.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName); 
		}
	}

	return 0;
}

void TextureHelper::SetTextureFolderName(std::string name)
{
	defaultFolder = name;
	texturePatch = defaulPatch + defaultFolder;
}

TextureHelper TextureHelper::m_TextureHelper;

TextureHelper* TextureHelper::Instance()
{
	return &m_TextureHelper;
}

