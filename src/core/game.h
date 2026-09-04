#pragma once
#define SDL_MAIN_HANDLED
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "InputManager.h"
#include "Renderer.h"
#include "ObjectManager.h"
#include <iostream>
#include <functional>


class Game{
    
    private:
    SDL_Window *window;
    ObjectManager obj_manager;
    SDL_Renderer * renderer;
    InputManager input;
    Renderer Render_Engine;
    bool init_window();
    bool init_renderer();
    void processEvent();
    const char *title ;
    int width;
    int height;
    bool running;

    //timing
    Uint64 LastTime=0;
    float accumulator=0;
    static constexpr float FIXED_TIME=1.0f/60.0f;

    public:
    
    bool init(const char *title,int wdith,int height);

    void end();
    void run();
    void FixedUpdate(float dt);
    void Update(float dt);
   
};