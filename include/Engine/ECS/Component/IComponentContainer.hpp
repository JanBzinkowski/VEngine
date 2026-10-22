#pragma once

class IComponentContainer
{
public:
    virtual ~IComponentContainer() = default;
    
    virtual void removeComponent(size_t entityId) = 0;
    
    virtual void clear() = 0;
};
