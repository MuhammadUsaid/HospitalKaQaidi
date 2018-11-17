#pragma once

class Loadtexture
{
    SDL_Texture* texture;
    int width;
    int height;
public:
    Loadtexture();
    void Free();
    void Render();
    bool LoadFile(const char*);
};
