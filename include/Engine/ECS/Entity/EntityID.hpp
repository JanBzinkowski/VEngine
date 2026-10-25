#pragma once
#include <cstdint>
#include <cstddef>

namespace Engine::ECS
{
    struct EntityID
    {
        std::uint32_t id;
        std::uint32_t generation;

        bool operator==(const EntityID& other) const;
        std::size_t hash() const noexcept;
    };
}
