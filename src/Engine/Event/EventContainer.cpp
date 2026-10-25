#include <Engine/Event/EventContainer.hpp>

namespace Engine::Event
{
    template <typename T>
    void EventContainer<T>::subscribe(SubscriptionID id, std::function<void(const T&)> callback)
    {
        m_subscribers.emplace(id, std::move(callback));
    }

    template <typename T>
    void EventContainer<T>::unsubscribe(SubscriptionID id)
    {
        auto it = m_subscribers.find(id);

        if (it != m_subscribers.end())
        {
            m_subscribers.erase(it);
        }
    }

    template <typename T>
    void EventContainer<T>::publish(const T& event)
    {
        for (auto subscriber : m_subscribers)
        {
            subscriber.second(event);
        }
    }
}
