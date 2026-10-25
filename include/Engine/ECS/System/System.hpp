#pragma once

#include <Engine/Event/Event.hpp>

namespace Engine::ECS
{
    class System
    {
    public:
        //TODO add sub ID, manage function callbacks
        virtual void onTickUpdate(const double& deltaTime) = 0;
        virtual void onEventUpdate(const Event::Event& event) = 0;
        virtual void onBeginPlayUpdate() = 0;
        virtual void onDestroyUpdate() = 0;

        template <typename T>
        void subscribeToEvent() const;

        virtual ~System() = default;
    };
}
