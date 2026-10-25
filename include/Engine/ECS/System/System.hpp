#pragma once

#include <typeindex>
#include <unordered_map>

#include "Engine/Event/EventManager.hpp"
#include <Engine/Types/EndPlayReason.hpp>

namespace Engine::ECS
{
    class SystemManager;

    class System
    {
    private:
        std::unordered_map<std::type_index, Event::SubscriptionID> m_subscriptions;

        SystemManager* m_manager;
    public:
        System(SystemManager* manager);
        virtual void onTickUpdate(const double& deltaTime) = 0;
        virtual void onBeginPlayUpdate() = 0;
        virtual void onEndPlayUpdate(Types::EndPlayReason reason) = 0;

        virtual ~System() = default;

        template <typename T>
        void subscribeToEvent(std::function<void(const T&)> callback);
    };
}
