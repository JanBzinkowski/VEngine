#pragma once
#include <memory>
#include <typeindex>
#include <unordered_map>

#include "System.hpp"
#include "Engine/Event/EventManager.hpp"

namespace Engine::ECS
{
    class SystemManager
    {
    private:
        Event::EventManager* m_eventManager;

        std::unordered_map<std::type_index, std::unique_ptr<System>> m_systems;
    public:
        SystemManager(Event::EventManager* eventManager);

        template <typename T>
        void subscribeToEvent() const;

        template <typename T>
        System* getOrCreateSystem();

        template <typename T>
        void removeSystem();

        void triggerOnTickUpdate(double deltaTime) const;

        void triggerOnBeginPlayUpdate() const;
    };
}
