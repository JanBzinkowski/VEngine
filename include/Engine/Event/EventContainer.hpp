#pragma once
#include "Engine/Event/IEventContainer.hpp"
#include <functional>
#include <unordered_map>
#include <utility>

namespace Engine::Event
{
    using SubscriptionID = std::size_t;

    template <typename T>
    class EventContainer final: public IEventContainer
    {
    private:
        std::unordered_map<SubscriptionID, std::function<void(const T&)>> m_subscribers;

    public:
        void subscribe(SubscriptionID id, std::function<void(const T&)> callback);
        void unsubscribe(SubscriptionID id) override;
        void publish(const T& event);
    };
}
