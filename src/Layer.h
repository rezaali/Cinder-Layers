#pragma once

namespace reza { namespace layer {

class AppData;
typedef std::shared_ptr<class AppData> AppDataRef;
    
class LayerManager;
typedef std::shared_ptr<class LayerManager> LayerManagerRef;
    
typedef std::shared_ptr<class Layer> LayerRef;
class Layer {
public:    
    Layer();
    virtual ~Layer();
    
    virtual const std::string getName() { return "Layer"; }
    
    virtual void _setup();
    virtual void _update();
    virtual void _draw();
    virtual void _cleanup();
    virtual void _activate();
    virtual void _deactivate();
    
    virtual void setup();
    virtual void update();
    virtual void draw();
    virtual void cleanup();
    virtual void activate();
    virtual void deactivate();
        
    bool isSetup();
    void setSetup( bool setup );
    
    bool isActive();
    void setActive( bool active );     
    
    void setManager( LayerManagerRef manager );
    void setData( AppDataRef appData );
    
protected:
    LayerManagerRef mManagerRef;
    AppDataRef mAppDataRef;
    bool mActive;
    bool mSetup;
};

} } //namespace reza::layer