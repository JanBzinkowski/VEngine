#pragma once
#include "Engine/Event/IEventContainer.hpp"

namespace Engine::Event
{
    template <typename T>
    class EventContainer: IEventContainer
    {
    private:
        std::unordered_map<SubscriptionID, std::function<void(const T&)>> m_subscribers;

    public:
        void subscribe(SubscriptionID id, std::function<void(const T&)> callback);
        void unsubscribe(SubscriptionID id) override;
        void publish(const T& event);
    };
}
