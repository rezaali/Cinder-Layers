#pragma once 

namespace reza { namespace layer {
    
typedef std::shared_ptr<class AppData> AppDataRef;
class AppData {
public:
    AppData();
    virtual ~AppData();
};
    
} } //namespace reza::layer