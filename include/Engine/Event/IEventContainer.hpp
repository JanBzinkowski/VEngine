#pragma once
#include "Engine/Event/EventManager.hpp"

namespace Engine::Event
{
    class IEventContainer
    {
    public:
        virtual ~IEventContainer() = default;

        virtual void unsubscribe(SubscriptionID id) = 0;
    };

}
