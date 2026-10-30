#ifndef VENGINE_RENDERER_H
#define VENGINE_RENDERER_H
#include <cstdint>

#include <Engine/Renderer/Commands/CommandMannager.hpp>
#include <Engine/Renderer/Synchronization/Synchronization.hpp>
#include <Engine/Renderer/VulkanResources/Device.hpp>
#include <Engine/Renderer/VulkanResources/Swapchain.hpp>
#include <Engine/Renderer/VulkanResources/Instance.hpp>
#include <Engine/Types/RendererInitializationConfig.hpp>
#include <Engine/Types/RendererOptions.hpp>

namespace Engine::Renderer
{
    class Renderer final
    {
    private:
        Instance m_instance;
        Device m_device;
        Swapchain m_swapchain;

        CommandMannager m_commandManager;
        Synchronization m_synchronization;

        std::uint32_t m_currentFrame = 0;

        Types::RendererInitializationConfig m_config;
        Types::RendererOptions m_options;

    public:
        Renderer(Types::RendererInitializationConfig config);


    };
}

#endif //VENGINE_RENDERER_H
