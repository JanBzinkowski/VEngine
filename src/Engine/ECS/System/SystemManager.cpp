#include <Engine/ECS/System/SystemManager.hpp>

namespace Engine::ECS
{
    SystemManager::SystemManager(Event::EventManager* eventManager): m_eventManager(eventManager){}

    template <typename T>
    Event::SubscriptionID SystemManager::subscribeToEvent(std::function<void(const T&)> callback) const
    {
        return m_eventManager->subscribeToEvent<T>(std::move(callback));
    }

    template <typename T>
    System* SystemManager::getOrCreateSystem()
    {
        auto& type_index = typeid(T);

        auto it = m_systems.find(type_index);

        if (it != m_systems.end())
        {
            return it -> second.get();
        }

        auto [newIt, inserted] = m_systems.emplace(type_index, std::make_unique<System>());
        return newIt -> second.get();
    }

    template <typename T>
    void SystemManager::removeSystem()
    {
        auto& type_index = typeid(T);

        auto it = m_systems.find(type_index);

        if (it != m_systems.end())
        {
            m_systems.erase(it);
        }
    }

    void SystemManager::triggerOnTickUpdate(double deltaTime) const
    {
        for (auto system : m_systems)
        {
            system.second->onTickUpdate(deltaTime);
        }
    }

    void SystemManager::triggerOnBeginPlayUpdate() const
    {
        for (auto system: m_systems)
        {
            system.second->onBeginPlayUpdate();
        }
    }
}
