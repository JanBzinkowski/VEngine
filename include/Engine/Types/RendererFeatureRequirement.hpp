#ifndef VENGINE_RENDERERFEATUREREQUIREMENT_HPP
#define VENGINE_RENDERERFEATUREREQUIREMENT_HPP

#include <cstdint>

namespace Engine::Types
{
    enum class RendererFeatureRequirement: std::uint8_t
    {
        Optional,
        Required,
        Preferred
    };
}

#endif //VENGINE_RENDERERFEATUREREQUIREMENT_HPP
