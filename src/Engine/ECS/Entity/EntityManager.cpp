#include <Engine/ECS/Entity/EntityManager.hpp>

namespace Engine::ECS::Entity
{
    template<typename T>
    Component::ComponentContainer<T>* EntityManager::getOrCreateComponentContainer()
    {
        const auto& index = typeid(T);

        auto it = m_componentContainers.find(index);

        if (it != m_componentContainers.end())
        {
            return it -> second.get();
        }

        auto [newIt, inserted] = m_componentContainers.emplace(index, std::make_unique<Component::ComponentContainer<T>>());
        return newIt -> second.get();
    }

    template <typename T>
    void EntityManager::removeComponentContainer()
    {
        const auto& index = typeid(T);

        auto it = m_componentContainers.find(index);

        if (it != m_componentContainers.end())
        {
            m_componentContainers.erase(it);
        }
    }

    EntityManager::EntityManager() {}

    template <typename T, typename... Args>
    T& EntityManager::addComponent(EntityID entityId, Args&&... args)
    {
        return getOrCreateComponentContainer<T>()
                -> addComponent(entityId, std::forward<Args>(args)...);
    }

    template <typename T>
    void EntityManager::removeComponent(EntityID entityId)
    {
        getOrCreateComponentContainer<T>()->removeComponent(entityId);
    }

    template<typename T>
    bool EntityManager::hasComponent(EntityID entityId)
    {
        return getOrCreateComponentContainer<T>()->hasComponent(entityId);
    }

    template <typename T>
    T& EntityManager::getComponent(EntityID entityId)
    {
        return getOrCreateComponentContainer<T>()->getComponent(entityId);
    }

    void EntityManager::deleteEntity(EntityID entityId)
    {
        m_freeId.push_back(entityId.id);
        for (auto& comp : m_componentContainers)
        {
            comp.second->removeComponent(entityId);
        }
    }

    Entity EntityManager::createEntity()
    {
        if (m_freeId.empty())
        {
            EntityID newEntity= {.id = m_nextEntityId++, .generation = 0};
            m_generationId.push_back(newEntity.generation);
            return {newEntity, this};
        }
        else
        {
            auto id = m_freeId.back();
            EntityID newEntity = {.id = id, .generation = ++m_generationId[id]};
            m_freeId.pop_back();
            return {newEntity, this};
        }
    }

    bool EntityManager::isEntityValid(EntityID entityId)
    {
        return std::find(m_freeId.begin(), m_freeId.end(), entityId.id) == m_freeId.end()
                && entityId.generation == m_generationId[entityId.id];
    }
}
