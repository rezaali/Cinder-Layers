#pragma once

#include <map>

namespace reza { namespace layer {
    
class AppData;
typedef std::shared_ptr<class AppData> AppDataRef;

class Layer;
typedef std::shared_ptr<class Layer> LayerRef;

typedef std::shared_ptr<class LayerManager> LayerManagerRef;
class LayerManager : public std::enable_shared_from_this<class LayerManager>
{
public:
    static LayerManagerRef create( const AppDataRef& appdata )
    {
        return LayerManagerRef( new LayerManager( appdata ) );
    }
    
    LayerManager( const AppDataRef& appdata );
    ~LayerManager();
    
    void addLayer( const LayerRef& layer );
    void switchLayer( std::string name );
    
    const LayerRef& getActiveLayer();
    const AppDataRef& getAppData();
    
    const std::map<std::string, LayerRef>& getLayers();
    std::vector<std::string> getLayerNames();
    
    void update();
    void draw();
    void resize(); 
    void cleanup();
    
private:
    std::map< std::string, LayerRef > mLayersMap;
    LayerRef mActiveLayerRef;
    AppDataRef mAppDataRef;
};

} } //namespace reza::layer