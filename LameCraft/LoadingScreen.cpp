#include "LoadingScreen.h"
#include <pspthreadman.h>
#include <pspgu.h>
#include <pspgum.h>
#include <pspdisplay.h>

#include <Aurora/Graphics/RenderManager.h>
#include <Aurora/Graphics/Sprite.h>



using namespace Aurora::Graphics;

Sprite* backSprite;
LoadingScreen::LoadingScreen()
{
	// the loadingscreen is loaded as a thread
	thid_ = sceKernelCreateThread("LoadingThread", RunLoadingScreen, 0x18, 0x10000, THREAD_ATTR_VFPU|THREAD_ATTR_USER, NULL);
	// start the thread
	sceKernelStartThread(thid_, 0, 0);
}


void LoadingScreen::KillLoadingScreen()
{
	// shut down the loading screen again.
	sceKernelTerminateDeleteThread(thid_);
	// free the mem space of the images
	delete backSprite;
}


int LoadingScreen::RunLoadingScreen(SceSize args, void *argp)
{
	// load up the images
	backSprite = new Sprite("Assets/Lamecraft/dirt.png",0,0,16,16);
	backSprite->Scale(2,2);

	int random_message;
	random_message = rand()%52;
	// start the render loop
	while(1)
	{
		RenderManager::InstancePtr()->StartFrame();

		sceGuDisable(GU_DEPTH_TEST);
		sceGuEnable(GU_BLEND);
		sceGuColor(GU_COLOR(1,1,1,1.0f));

		for(int x = 0;x < 16;x++)
		{
			for(int y = 0;y < 9;y++)
			{
				backSprite->SetPosition(x*32,y*32);
				backSprite->Draw();
			}
		}

		sceGuDisable(GU_BLEND);
		sceGuEnable(GU_DEPTH_TEST);

		//draw subtitles on buttons

		switch(random_message)
		{
			case 0:
				RenderManager::InstancePtr()->DebugPrint(240,136,"GENERATING WORLD");
			break;
			case 1:
				RenderManager::InstancePtr()->DebugPrint(240,136,"FILING NAILS");
			break;
			case 2:
				RenderManager::InstancePtr()->DebugPrint(240,136,"HIDING THE EVIDENCE");
			break;
			case 3:
				RenderManager::InstancePtr()->DebugPrint(240,136,"EATING COCO PUFFS");
			break;
			case 4:
				RenderManager::InstancePtr()->DebugPrint(240,136,"SOLVING E=MC2");
			break;
			case 5:
				RenderManager::InstancePtr()->DebugPrint(240,136,"DEFYING GRAVITY");
			break;
			case 6:
				RenderManager::InstancePtr()->DebugPrint(240,136,"PUMPING UP A SOCCER BALL");
			break;
			case 7:
				RenderManager::InstancePtr()->DebugPrint(240,136,"WATCHING THE HANGOVER");
			break;
			case 8:
				RenderManager::InstancePtr()->DebugPrint(240,136,"SUCKING ON AN ICE CUBE");
			break;
			case 9:
				RenderManager::InstancePtr()->DebugPrint(240,136,"EATING DIRT");
			break;
			case 10:
				RenderManager::InstancePtr()->DebugPrint(240,136,"GOING TO WALMART");
			break;
			case 11:
				RenderManager::InstancePtr()->DebugPrint(240,136,"GETTING A LIFE");
			break;
			case 12:
				RenderManager::InstancePtr()->DebugPrint(240,136,"LAUGHING UNCONTROLLABLY");
			break;
			case 13:
				RenderManager::InstancePtr()->DebugPrint(240,136,"FACEBOOK STALKING");
			break;
			case 14:
				RenderManager::InstancePtr()->DebugPrint(240,136,"FLAMING YOUTUBERS");
			break;
			case 15:
				RenderManager::InstancePtr()->DebugPrint(240,136,"CHILLING WITH HOBOS");
			break;
			case 16:
				RenderManager::InstancePtr()->DebugPrint(240,136,"EMBRACEING THE WORST");
			break;
			case 17:
				RenderManager::InstancePtr()->DebugPrint(240,136,"uhm, hello there.");
			break;
			case 18:
				RenderManager::InstancePtr()->DebugPrint(240,136,"BASKING IN THE SUN");
			break;
			case 19:
				RenderManager::InstancePtr()->DebugPrint(240,136,"EATING FOOD");
			break;
			case 20:
				RenderManager::InstancePtr()->DebugPrint(240,136,"Please wait a moment sir.");
			break;
			case 21:
				RenderManager::InstancePtr()->DebugPrint(240,136,"FIGHTING THE BEAST");
			break;
			case 22:
				RenderManager::InstancePtr()->DebugPrint(240,136,"WAITING FOR A MIRACLE");
			break;
			case 23:
				RenderManager::InstancePtr()->DebugPrint(240,136,"BUILDING A PURTY HOUSE");
			break;
			case 24:
				RenderManager::InstancePtr()->DebugPrint(240,136,"LEARNING HOW TO RIDE A BIKE");
			break;
			case 25:
				RenderManager::InstancePtr()->DebugPrint(240,136,"STALKING SANTA");
			break;
			case 26:
				RenderManager::InstancePtr()->DebugPrint(240,136,"LOOKING AT A GOAT");
			break;
			case 27:
				RenderManager::InstancePtr()->DebugPrint(240,136,"BUILDING A WORLD FOR A PLATTY");
			break;
			case 28:
				RenderManager::InstancePtr()->DebugPrint(240,136,"HOSTING A CLASS FOR SHE-MALES");
			break;
			case 29:
				RenderManager::InstancePtr()->DebugPrint(240,136,"LEARNING HOW TO MAKE A WORLD");
			break;
			case 30:
				RenderManager::InstancePtr()->DebugPrint(240,136,"SUPERCALIFRAGILISTICEXPIALODOCIOUS");
			break;
			case 31:
				RenderManager::InstancePtr()->DebugPrint(240,136,"BUYING A PINK CARPET");
			break;
			case 32:
				RenderManager::InstancePtr()->DebugPrint(240,136,"SMELLING A FLOWER");
			break;
			case 33:
				RenderManager::InstancePtr()->DebugPrint(240,136,"FIGHTING FEROCIOUS BEARS");
			break;
			case 34:
				RenderManager::InstancePtr()->DebugPrint(240,136,"BATHING IN LAVA");
			break;
			case 35:
				RenderManager::InstancePtr()->DebugPrint(240,136,"PAYING MEXICOUGER RESPECTS");
			break;
			case 36:
				RenderManager::InstancePtr()->DebugPrint(240,136,"LIVING EVERY SINGLE DAY");
			break;
			case 37:
				RenderManager::InstancePtr()->DebugPrint(240,136,"BLASTING DUB STEP");
			break;
			case 38:
				RenderManager::InstancePtr()->DebugPrint(240,136,"BEING METICULOUS");
			break;
			case 39:
				RenderManager::InstancePtr()->DebugPrint(240,136,"WICKED WITCH OF THE WEST");
			break;
			case 40:
				RenderManager::InstancePtr()->DebugPrint(240,136,"READING A CHILDRENS BOOK");
			break;
			case 41:
				RenderManager::InstancePtr()->DebugPrint(240,136,"BUYING SOME NEW KICKS");
			break;
			case 42:
				RenderManager::InstancePtr()->DebugPrint(240,136,"SAY IRISH WRISTWATCH 3X FAST");
			break;
			case 43:
				RenderManager::InstancePtr()->DebugPrint(240,136,"BOOBY TRAPPED!");
			break;
			case 44:
				RenderManager::InstancePtr()->DebugPrint(240,136,"CHILLING AND GRILLING");
			break;
			case 45:
				RenderManager::InstancePtr()->DebugPrint(240,136,"FACE-N-BRAN CEAREAL");
			break;
			case 46:
				RenderManager::InstancePtr()->DebugPrint(240,136,"I FREEZE YOUR PSP!!!");
			break;
			case 47:
				RenderManager::InstancePtr()->DebugPrint(240,136,"BATTLING CHUCK NORRIS ON POKEMON");
			break;
			case 48:
				RenderManager::InstancePtr()->DebugPrint(240,136,"GOING OVER 9000");
			break;
			case 49:
				RenderManager::InstancePtr()->DebugPrint(240,136,"WATCHING MARIO AND SONIC IN A COCK FIGHT");
			break;
			case 50:
				RenderManager::InstancePtr()->DebugPrint(240,136,"LOCKING MY DOOR");
			break;
			case 51:
				RenderManager::InstancePtr()->DebugPrint(240,136,"WATCHING YOU WITH MY POKER EYES");
			break;
		}

		// the loading graphics :)
		/*animation_++;
		if(animation_ > 19)
			animation_ = 0;

		// switch images now and then
		if (animation_ < 10)
			gfx->Render2DImageOn3D(117, 100, load1);
		else if (animation_ < 20)
			gfx->Render2DImageOn3D(117, 100, load2);*/

		RenderManager::InstancePtr()->EndFrame();
	}
	return 0;
}

