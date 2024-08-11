#include "Engine.h"
namespace nula
{
    nulaEngine::nulaEngine()
    {
        InitSDL();
        CreateWindow("nulaEngine", 640, 480);
    }
    void nulaEngine::Run()
    {
        bool game_is_running{true};
        while (game_is_running)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                case SDL_QUIT:
                    game_is_running = false;
                    break;
                }
            }

            SDL_RenderPresent(m_renderer.get());
        }
    }
    nulaEngine::~nulaEngine()
    {
        QuitSDL();
    }
    void nulaEngine::InitSDL()
    {
        // Initialize the SDL library with subsystems
        SDL_Init(SDL_INIT_VIDEO);
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
        m_window = std::unique_ptr<SDL_Window, SDLWindowDestroyer>(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0));
        m_renderer = std::unique_ptr<SDL_Renderer, SDLRendererDestroyer>(SDL_CreateRenderer(m_window.get(), -1, 0));
    }
    void nulaEngine::QuitSDL()
    {
        SDL_Quit();
    }
}
