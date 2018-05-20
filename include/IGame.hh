#pragma once

#include <irrlicht.h>

///////////////////////////////////////////////////////
/// IGame - Main game thread
///////////////////////////////////////////////////////
class IGame
{
    static IGame* mInstance;
    
    irr::IrrlichtDevice *mDevice;
    irr::video::IVideoDriver *mDriver;
    irr::scene::ISceneManager* mManager;

    IGame();

public:

    ///Returns the instance to the current running game , or create if
    ///it does not exist.
    static IGame* GetInstance()
	{
	    if(!mInstance){
		mInstance = new IGame();
		atexit(&DestroyInstance);
	    }
	    return mInstance;
	}

    ~IGame() { mDevice->drop(); };

    ///Starts the main game thread.
    void Init();

    //Functions to access the game's Device , Driver or Scene Manager.
    irr::IrrlichtDevice* GetDevice()		const { return mDevice ; }
    irr::video::IVideoDriver* GetDriver()	const { return mDriver ; }
    irr::scene::ISceneManager* GetManager()	const { return mManager; }

    static void DestroyInstance() { delete mInstance; }
};
