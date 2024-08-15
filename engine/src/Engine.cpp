#include "Engine.h"
#include <SDL.h>
namespace nula
{
    nulaEngine::nulaEngine()
    {
        InitSDL();
        CreateWindow("nulaEngine", 640, 480);
    }
    void nulaEngine::Startup()
    {
        
    }
    void nulaEngine::Run()
    {

        bool game_is_running{true};
        while (game_is_running)
        {
            // basic game loop, no framerate limit, heavy cpu usage
            game_is_running = HandleInput();
            Update();
            Render();
        }
    }
    nulaEngine::~nulaEngine()
    {
        // Cleanup SDL when we're done with the engine
        QuitSDL();
    }
    void nulaEngine::InitSDL()
    {
        // Initialize the SDL library with subsystems
        SDL_Init(SDL_INIT_VIDEO);
        // Print out the SDL version we're compiling & linking against
        SDL_version version{};

        SDL_VERSION(&version)
        printf("We compiled against SDL version %u.%u.%u ...\n",
               version.major, version.minor, version.patch);

        SDL_GetVersion(&version);
        printf("We are linking against SDL version %u.%u.%u.\n",
               version.major, version.minor, version.patch);
    }
    void nulaEngine::CreateWindow(const std::string &title, int width, int height)
    {
        // Create a RAII window that will automatically be cleaned up using native SDL functions
        m_window = std::unique_ptr<SDL_Window, SDLWindowDestroyer>(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0));
        // Same goes for the renderer. Currently only using SDL2's own 2D renderer
        m_renderer = std::unique_ptr<SDL_Renderer, SDLRendererDestroyer>(SDL_CreateRenderer(m_window.get(), -1, 0));
    }
    bool nulaEngine::HandleInput()
    {
        // Handle SDL events, including input
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                return false;
                break;
            }
        }

        return true;
    }
    void nulaEngine::Update()
    {
        // Update the systems
        // All ECS registered systems should probably get updated here
    }
    void nulaEngine::Render()
    {
        // All ECS registered systems with a "Renderable" component should probably be processed here?
        SDL_RenderPresent(m_renderer.get());
    }
    void nulaEngine::QuitSDL()
    {
        SDL_Quit();
    }
}
