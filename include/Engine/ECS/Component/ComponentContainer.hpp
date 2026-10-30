#pragma once
#include <unordered_map>

#include "IComponentContainer.hpp"

namespace Engine::ECS::Component
{
    template<typename T>
    class ComponentContainer : public IComponentContainer
    {
    private:
        std::unordered_map<Entity::EntityID, T> components;
    public:

        void removeComponent(Entity::EntityID entityId) override;

        void clear() override;

        template<typename... Args>
        T& addComponent(Entity::EntityID entityId, Args&&... args);

        bool hasComponent(Entity::EntityID entityId) const;

        T& getComponent(Entity::EntityID entityId);
    };
}
