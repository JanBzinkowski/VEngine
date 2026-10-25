#pragma once
#include <unordered_map>

#include "IComponentContainer.hpp"

namespace Engine::ECS
{
    template<typename T>
    class ComponentContainer : public IComponentContainer
    {
    private:
        std::unordered_map<EntityID, T> components;
    public:

        void removeComponent(EntityID entityId) override;

        void clear() override;

        template<typename... Args>
        T& addComponent(EntityID entityId, Args&&... args);

        bool hasComponent(EntityID entityId) const;

        T& getComponent(EntityID entityId);
    };
}
