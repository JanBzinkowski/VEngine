#include <Engine/ECS/Component/ComponentContainer.hpp>

#include <stdexcept>
#include <string>
#include <utility>

namespace Engine::ECS
{
    template<typename T>
    void ComponentContainer<T>::removeComponent(EntityID entityId)
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
    T& ComponentContainer<T>::addComponent(EntityID entityId, Args&& ... args)
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
    bool ComponentContainer<T>::hasComponent(EntityID entityId) const
    {
        return components.contains(entityId);
    }

    template<typename T>
    T& ComponentContainer<T>::getComponent(EntityID entityId)
    {
        return components.at(entityId);
    }
}
