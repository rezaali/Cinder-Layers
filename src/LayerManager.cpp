#include "LayerManager.h"

#include "Layer.h"

using namespace reza::layer;
using namespace cinder;
using namespace std;

LayerManager::LayerManager( const AppDataRef& appdata ) : mActiveLayerRef( nullptr ), mAppDataRef( appdata )
{
    cout << "SETUP LAYERMANAGER" << endl;
}

LayerManager::~LayerManager()
{
    cout << "DESTROYING LAYERMANAGER" << endl;     
}

void LayerManager::addLayer( const LayerRef& layer )
{
    layer->setManager( shared_from_this() );
    layer->setData( mAppDataRef );
    mLayersMap[ layer->getName() ] = layer;
}

void LayerManager::switchLayer( string name )
{
    if( mActiveLayerRef ) {
        if( mActiveLayerRef->getName() == name ) {
            return ;
        }
        else if( mActiveLayerRef->isActive() ) {
            mActiveLayerRef->_deactivate();
            mActiveLayerRef->setActive( false ); 
        }
    }
   
    auto it = mLayersMap.find( name );
    if( it != mLayersMap.end() )
    {
        auto& layer = it->second;
        
        if( !layer->isSetup() )
        {
            layer->_setup();
            layer->setSetup( true );
        }
        layer->_activate();
        layer->setActive( true );
        mActiveLayerRef = layer; 
    }
}

const LayerRef& LayerManager::getActiveLayer()
{
    return mActiveLayerRef; 
}

const AppDataRef& LayerManager::getAppData()
{
    return mAppDataRef; 
}

const map< string, LayerRef >& LayerManager::getLayers()
{
    return mLayersMap;
}

vector<string> LayerManager::getLayerNames()
{
    vector<string> names;
    for( auto &it : mLayersMap ) {
        names.push_back( it.first );
    }
    return names;
}

void LayerManager::update()
{
    if( mActiveLayerRef ) {
        mActiveLayerRef->_update();
    }
}

void LayerManager::draw()
{
    if( mActiveLayerRef ) {
        mActiveLayerRef->_draw();
    }
}

void LayerManager::cleanup()
{
    mActiveLayerRef = nullptr;
    for( auto &it : mLayersMap ) {
        auto layer = it.second;
        if( layer ->isSetup() ) {
            if( layer ->isActive() ) {
                layer->_deactivate();
            }
            layer->_cleanup();
            layer->setManager( nullptr );
            layer->setData( nullptr );
        }
    }
    mLayersMap.clear();
    mAppDataRef = nullptr; 
}