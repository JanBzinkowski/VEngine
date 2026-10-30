#include <Engine/ECS/System/System.hpp>
#include <Engine/Event/EventManager.hpp>
#include <Engine/ECS/System/SystemManager.hpp>

namespace Engine::ECS::System
{
    System::System(SystemManager* manager): m_manager(manager){}

    template <typename T>
    void System::subscribeToEvent(std::function<void(const T&)> callback)
    {
        auto id = m_manager->subscribeToEvent<T>(std::move(callback));
        auto& type = typeid(T);

        m_subscriptions[type] = id;
    }
}
