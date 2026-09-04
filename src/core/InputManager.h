#pragma once
#include <SDL3/SDL.h>
#include <unordered_map>
#include <string>
#include <cstring>
#include <iostream>
class InputManager{
    
    private:

    int numKeys;
    bool  previousState[SDL_SCANCODE_COUNT]={};
    const bool * currentState;
    
    
    public:
    std::unordered_map<std::string,SDL_Scancode> ActionMap;

    
    InputManager();

    void update();

    bool IsKeyDown(SDL_Scancode key);
    bool IsKeyPressed(SDL_Scancode key);
    bool IsKeyReleased(SDL_Scancode key);
};

