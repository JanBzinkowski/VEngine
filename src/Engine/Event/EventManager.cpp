#include <Engine/Event/EventManager.hpp>

namespace Engine::Event
{
    template <typename T>
    EventContainer<T>* EventManager::getOrCreateEventContainer()
    {
        const auto& type = typeid(T);

        const auto it = m_eventContainers.find(type);

        if (it != m_eventContainers.end())
        {
            return it -> second.get();
        }

        auto [newIt, inserted] = m_eventContainers.emplace(type, std::make_unique<EventContainer<T>>());
        return newIt->second.get();
    }

    template <typename T>
    SubscriptionID EventManager::subscribeToEvent(std::function<void(const T&)> callback)
    {
        auto container = getOrCreateEventContainer<T>();

        const auto id = m_nextID++;

        container->subscribe(id, std::move(callback));

        m_subscribersEvents.emplace(id, typeid(T));

        return id;
    }

    void EventManager::unsubscribeToEvent(SubscriptionID id)
    {
        const auto it = m_subscribersEvents.find(id);

        if (it == m_subscribersEvents.end())
        {
            return;
        }

        const auto& type = it->second;

        const auto newIt = m_eventContainers.find(type);

        if (newIt == m_eventContainers.end())
        {
            return;
        }

        newIt -> second.get() -> unsubscribe();

        m_subscribersEvents.erase(id);
    }

    template <typename T>
    void EventManager::postEvent(const T& event)
    {
        const auto& type = typeid(T);

        const auto it = m_eventContainers.find(type);

        if (it == m_eventContainers.end())
        {
            return;
        }

        auto container = static_cast<EventContainer<T>>(it -> second.get());
        container.publish(event);
    }
}
