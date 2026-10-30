#pragma once
#include <cstddef>
#include <cstdint>

namespace Engine::ECS::Entity
{
    struct EntityID final
    {
        std::uint32_t id;
        std::uint32_t generation;

        bool operator==(const EntityID& other) const;
        [[nodiscard]] std::size_t hash() const noexcept;
    };
}
