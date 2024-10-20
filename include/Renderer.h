#ifndef RENDERER_H
#define RENDERER_H

#include "StandardIncludes.h"
#include "Texture.h"
#include "BasicStructs.h"

class Asset;

class Renderer : public Singleton<Renderer>
{
public:
    // Constructors/Destructors
    Renderer();
    virtual ~Renderer();

    // Accessors
    SDL_Window* GetWindow() { return m_window; }
    SDL_Renderer* GetRenderer() { return m_renderer; }
    SDL_Texture* GetSDLTexture(Texture* _texture);

    // Methods
    void Initialize(int _xResolution, int _yResolution);
    Point GetWindowSize();
    void SetDrawColor(Color _color);
    void ClearScreen();
    void SetViewport(Rect _viewport);
    void RenderPoint(Point _position);
    void RenderLine(Rect _points);
    void RenderRectangle(Rect _rect);
    void RenderFillRectangle(Rect _rect);
    void RenderTexture(Texture* _texture, Point _point);
    void RenderTexture(Texture* _texture, Rect _point);
    void RenderTexture(Texture* _texture, Rect _srcRect, Rect _destRect);
    void Shutdown();

private:
    // Members
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    SDL_Rect m_srcRect;
    SDL_Rect m_destRect;
    SDL_Surface* m_surface;
    SDL_Rect m_viewPort;
    map<string, SDL_Texture*> m_textures;
};

#endif // RENDERER_H
