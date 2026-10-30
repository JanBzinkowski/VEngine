#pragma once
#include <Engine/ECS/Entity/EntityID.hpp>

namespace Engine::ECS::Entity
{
    class Entity final
    {
        friend class EntityManager;

    private:
        EntityID m_entityID;
        EntityManager* m_entityManager;
        Entity(const EntityID& id, EntityManager* manager);
    public:
        [[nodiscard]] EntityID getID() const;

        [[nodiscard]] EntityManager* getManager() const;

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
