#ifndef TEXTUREHELPER_H_
#define TEXTUREHELPER_H_

#include <string>

class TextureHelper
{
private:

	std::string defaulPatch;
	std::string defaultFolder;
	std::string texturePatch;
	std::string fileName;

public:

	enum Textures
	{
		Genesis,
		PspTeam,
		Logo,
		Utils,
		Dirt,
		Glass,
		Terrain,
		Blue,
		Sky,
		Sun,
		Moon,
		lameCraft,
		Red,
		RainSky,
		Panorama1,
		Panorama2,
		Panorama3,
		Panorama4,
		menuTool,
		char1,
		Inventory,
		Thinks,
		chat,
		character,
		bilo,
		invchar1,
		button0
	};

	static TextureHelper m_TextureHelper;
	static TextureHelper* Instance();


	TextureHelper();
	~TextureHelper();

	int GetTexture(Textures texture);

	void SetTextureFolderName(std::string name);
};

#endif
