#pragma once
#include <Engine/ECS/Component/IComponentContainer.hpp>
#include <Engine/ECS/Entity/Entity.hpp>
#include <unordered_map>
#include <typeindex>
#include <memory>

#include "Engine/ECS/Component/ComponentContainer.hpp"

namespace Engine::ECS
{
    class EntityManager
    {
    private:
        EntityManager* m_instance;

        std::unordered_map<std::type_index, std::unique_ptr<IComponentContainer>> m_componentContainers;

        std::uint32_t m_nextEntityId = 0;
        std::vector<std::uint32_t> m_freeId;
        std::vector<std::uint32_t> m_generationId;
    public:
        EntityManager();

        template<typename T, typename... Args>
        T& addComponent(EntityID entityId, Args&&... args);

        template<typename T>
        void removeComponent(EntityID entityId);

        template<typename T>
        bool hasComponent(EntityID entityId);

        template<typename T>
        T& getComponent(EntityID entityId);

        template<typename T>
        ComponentContainer<T>* getOrCreateComponentContainer();

        template <typename T>
        void removeComponentContainer();

        void deleteEntity(EntityID entityId);

        Entity createEntity();

        bool isEntityValid(EntityID entityId);
    };
}
