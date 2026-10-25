#include <Engine/ECS/Entity/Entity.hpp>
#include <Engine/ECS/Entity/EntityManager.hpp>

namespace Engine::ECS
{
    Entity::Entity(const EntityID& id, EntityManager* manager)
        : m_entityID(id), m_entityManager(manager) {}

    EntityID Entity::getID() const
    {
        return m_entityID;
    }

    EntityManager* Entity::getManager() const
    {
        return m_entityManager;
    }

    template<typename T, typename... Args>
    Entity& Entity::addComponent(T& component, Args&&... args)
    {
        m_entityManager->addComponent<T>(m_entityID.id, std::forward<Args>(args)...);
        return *this;
    }

    template <typename T>
    void Entity::removeComponent()
    {
        m_entityManager->removeComponent<T>(m_entityID);
    }

    void Entity::destroy()
    {
        m_entityManager->deleteEntity(m_entityID);
    }

    template <typename T>
    bool Entity::hasComponent()
    {
        return m_entityManager->hasComponent<T>(m_entityID);
    }

    template <typename T>
    T& Entity::getComponent()
    {
        return m_entityManager->getComponent<T>(m_entityID);
    }
}
