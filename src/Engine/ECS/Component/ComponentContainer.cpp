#include <Engine/ECS/Component/ComponentContainer.hpp>

#include <stdexcept>
#include <string>
#include <utility>

namespace Engine::ECS::Component
{
    template<typename T>
    void ComponentContainer<T>::removeComponent(Entity::EntityID entityId)
    {
        components.erase(entityId);
    }

    template<typename T>
    void ComponentContainer<T>::clear()
    {
        components.clear();
    }

    template<typename T>
    template<typename... Args>
    T& ComponentContainer<T>::addComponent(Entity::EntityID entityId, Args&& ... args)
    {
        auto [it, inserted] = components.try_emplace(entityId, std::forward<Args>(args)...);

        if (!inserted)
        {
            throw std::logic_error("Component already exists for entity ID: " + std::to_string(entityId.id)
                    + ", generation: " + std::to_string(entityId.generation));
        }
        return it->second;
    }

    template<typename T>
    bool ComponentContainer<T>::hasComponent(Entity::EntityID entityId) const
    {
        return components.contains(entityId);
    }

    template<typename T>
    T& ComponentContainer<T>::getComponent(Entity::EntityID entityId)
    {
        return components.at(entityId);
    }
}
