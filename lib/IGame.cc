#include <IGame.hh>
#include <stdexcept>

IGame* IGame::mInstance = nullptr;

///////////////////////////////////////////////////////
IGame::IGame()
{
    this->mDevice = nullptr;
    this->mDriver = nullptr;
    this->mManager = nullptr;
}

///////////////////////////////////////////////////////
void IGame::Init()
{
    //TODO: Implement these in i23.set file
    const irr::video::E_DRIVER_TYPE driverType = irr::video::EDT_OPENGL;
    const irr::u32 bpp = 32;
    const bool fullscreen = false;
    const bool stencil = false;
    const bool vsync = true;
    
    mDevice = irr::createDevice(driverType,
				irr::core::dimension2d<irr::u32>(640,480),
				bpp,fullscreen,stencil,vsync);

    if(!mDevice)
	throw std::runtime_error("Failed to create an OpenGL device");

    mDriver = mDevice->getVideoDriver();
    mManager = mDevice->getSceneManager();

    while(mDevice->run())
    {
	if(mDevice->isWindowActive())
	{    
	    mDriver->beginScene();
	    mManager->drawAll();
            mDriver->endScene();   
	}
	else
	    mDevice->yield();
    }
}
