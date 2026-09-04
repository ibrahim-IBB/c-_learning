#pragma once
#include <iostream>
#include <SDL3/SDL.h>
#include "ObjectManager.h"



class Renderer{

    private:
    SDL_Renderer* renderer;
    
    public:
    
    void RendererInit(SDL_Renderer *r);

    void ClearRender();
    void RenderPresent();
    
    void Render(ObjectManager * obj_manager);
     ~Renderer();
};