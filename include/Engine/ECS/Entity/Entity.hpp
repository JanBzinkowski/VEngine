#pragma once
#include <variant>
#include <Engine/ECS/Entity/EntityID.hpp>

namespace Engine::ECS
{
    class EntityManager;

    class Entity
    {
        friend class EntityManager;

    private:
        EntityID m_entityID;
        EntityManager* m_entityManager;
        Entity(const EntityID& id, EntityManager* manager);
    public:


        EntityID getID() const;

        EntityManager* getManager() const;

        template<typename T, typename... Args>
        Entity& addComponent(T& component, Args&&... args);

        template <typename T>
        void removeComponent();

        void destroy();

        template<typename T>
        bool hasComponent();

        template<typename T>
        T& getComponent();
    };
}
