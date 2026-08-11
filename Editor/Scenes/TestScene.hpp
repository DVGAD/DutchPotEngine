#pragma once
#include <World/Scene.hpp>
#include <Renderer/Renderer.hpp>
#include <Input/Input.hpp>
#include <Log/Log.hpp>

#include <ECS/Systems/MovementSystem.hpp>
#include <ECS/Systems/RenderSystem.hpp>
#include <ECS/Systems/InputSystem.hpp>

#include <ECS/Components/Core/PlayerController.hpp>
#include <ECS/Components/Physics/Physics.hpp> // include for all physics components
#include <ECS/Components/Rendering/Rendering.hpp> // include for all rendering components


namespace DPE
{
    class TestScene : public Scene
    {
    public:
        void Init(GameWorld& world, Renderer& renderer, Input& input) override
        {
			LOG_INFO("Initializing TestScene...");
            auto& registry = world.GetRegistry();
            auto& scheduler = world.GetScheduler();

            entt::entity player = registry.create(); // Player entity
            registry.emplace<Transform>(player, 100.0f, 200.0f);
            registry.emplace<Velocity>(player, 0.0f, 0.0f); 
            registry.emplace<Sprite>(player, 50.0f, 50.0f, uint8_t{ 255 }, uint8_t{ 0 }, uint8_t{ 0 }, uint8_t{ 255 });
            registry.emplace<PlayerController>(player, 200.0f); 

			entt::entity obstacle = registry.create(); // Obstacle entity
            registry.emplace<Transform>(obstacle, 300.0f, 200.0f);
            registry.emplace<Sprite>(obstacle, 50.0f, 50.0f, uint8_t{ 0 }, uint8_t{ 255 }, uint8_t{ 0 }, uint8_t{ 255 });

            // Register systems in correct order
            // 1. Input (variable, runs first to set velocities)
            scheduler.RegisterVariableSystem([&input, &world](float dt) {
                InputSystem::Update(world, input);
                });

            // 2. Clear screen
            scheduler.RegisterVariableSystem([&renderer](float dt) {
                renderer.Clear();
                });


            // 3. Draw
            scheduler.RegisterVariableSystem([&world, &renderer](float dt) {
                RenderSystem::Update(world, renderer);
                });

            // 4. Present
            scheduler.RegisterVariableSystem([&renderer](float dt) {
                renderer.Present();
                });

            // 5. Movement (fixed update)
            scheduler.RegisterFixedSystem([&world](float dt) {
                MovementSystem::Update(world, dt);
                });

            LOG_INFO("TestScene initialized with player control.");
        }

        void Shutdown() override
        {
            LOG_INFO("Unloading TestScene");
        }
    };
}
