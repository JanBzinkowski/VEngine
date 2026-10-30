#pragma once
#include <cstddef>

namespace Engine::Event
{
    using SubscriptionID = std::size_t;

    class IEventContainer
    {
    public:
        virtual ~IEventContainer() = default;

        virtual void unsubscribe(SubscriptionID id) = 0;
    };

}
