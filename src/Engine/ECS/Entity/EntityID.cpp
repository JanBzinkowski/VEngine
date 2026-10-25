#include <functional>
#include <Engine/ECS/Entity/EntityID.hpp>

namespace Engine::ECS
{
    bool EntityID::operator==(const EntityID& other) const
    {
        return id == other.id && generation == other.generation;
    }

    std::size_t EntityID::hash() const noexcept
    {
        std::size_t h1 = std::hash<uint32_t>{}(id);
        std::size_t h2 = std::hash<uint32_t>{}(generation);

        return h1 ^ (h2 << 1);
    }
}
