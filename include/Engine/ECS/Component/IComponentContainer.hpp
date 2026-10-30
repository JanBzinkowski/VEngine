#pragma once
#include <cstdint>

#include "Engine/ECS/Entity/EntityID.hpp"

namespace Engine::ECS::Component
{
    class IComponentContainer
    {
    public:
        virtual ~IComponentContainer() = default;

        virtual void removeComponent(Entity::EntityID entityId) = 0;

        virtual void clear() = 0;
    };
}
