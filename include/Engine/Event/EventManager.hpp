#pragma once
#include <any>
#include <functional>
#include <memory>
#include <typeindex>
#include <unordered_map>

#include "EventContainer.hpp"
#include "EventContainer.hpp"
#include "IEventContainer.hpp"

namespace Engine::Event
{
    using SubscriptionID = std::size_t;

    class EventManager final
    {
    private:
        std::unordered_map<std::type_index, std::unique_ptr<IEventContainer>> m_eventContainers;
        std::unordered_map<SubscriptionID, std::type_index> m_subscribersEvents;

        SubscriptionID m_nextID = 0;

    public:
        template<typename T>
        EventContainer<T>* getOrCreateEventContainer();

        template <typename T>
        SubscriptionID subscribeToEvent(std::function<void(const T&)> callback);

        void unsubscribeToEvent(SubscriptionID id);

        template<typename T>
        void postEvent(const T& event);
    };
}
