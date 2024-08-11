#pragma once
#include <string>

#include <memory>
#include <SDL.h>

namespace nula
{
    // Custom deleter for the SDL_Window
    struct SDLWindowDestroyer
    {
        void operator()(SDL_Window *w) const
        {
            SDL_DestroyWindow(w);
        }
    };
    struct SDLRendererDestroyer
    {
        void operator()(SDL_Renderer *r) const
        {
            SDL_DestroyRenderer(r);
        }
    };

    class nulaEngine final
    {
    public:
        nulaEngine();
        void Run();
        ~nulaEngine();

        SDL_Window *GetSDLWindow() const { return m_window.get(); }
        SDL_Renderer *GetSDLRenderer() const { return m_renderer.get(); }

    private:
        void InitSDL();
        void CreateWindow(const std::string &title, int width, int height);
        void QuitSDL();

        std::unique_ptr<SDL_Window, SDLWindowDestroyer> m_window{nullptr};
        std::unique_ptr<SDL_Renderer, SDLRendererDestroyer> m_renderer{nullptr};
    };

}
