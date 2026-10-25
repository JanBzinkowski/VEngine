#pragma once
#include <cstdint>

#include "Engine/ECS/Entity/EntityID.hpp"

namespace Engine::ECS
{
    class IComponentContainer
    {
    public:
        virtual ~IComponentContainer() = default;

        virtual void removeComponent(EntityID entityId) = 0;

        virtual void clear() = 0;
    };
}
