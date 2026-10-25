#pragma once
#include <cstdint>

namespace Engine::Types
{
    enum class EndPlayReason: std::uint8_t
    {
        Destroyed,
        LevelTransition,
        Shutdown
    };
}
