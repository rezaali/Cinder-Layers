#include "Layer.h"

using namespace reza::layer;
using namespace cinder;
using namespace std;

Layer::Layer() : mManagerRef( nullptr ), mAppDataRef( nullptr ), mActive( false ), mSetup( false ) { }

Layer::~Layer() { }

void Layer::_setup()
{
    setup();
}

void Layer::_update()
{
    update();
}

void Layer::_draw()
{
    draw();
}

void Layer::_resize()
{
    resize();
}

void Layer::_cleanup()
{
    cleanup();
}

void Layer::_activate()
{
    activate();
}

void Layer::_deactivate()
{
    deactivate();
}

void Layer::setup()
{

}

void Layer::update()
{

}

void Layer::draw()
{

}

void Layer::resize()
{
    
}

void Layer::cleanup()
{

}

void Layer::activate()
{
    
}

void Layer::deactivate()
{
    
}

bool Layer::isSetup()
{
    return mSetup;
}

void Layer::setSetup( bool setup )
{
    mSetup = setup;
}

bool Layer::isActive()
{
    return mActive;
}

void Layer::setActive( bool active )
{
    mActive = active; 
}

void Layer::setManager( LayerManagerRef manager )
{
    mManagerRef = manager;
}

void Layer::setData( AppDataRef appData )
{
    mAppDataRef = appData;
}