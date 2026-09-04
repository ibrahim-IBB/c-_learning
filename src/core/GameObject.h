#pragma once
#include "InputManager.h"
#include <iostream>


class GameObject{


    private:

    bool AnimationRunning=false;


    public:
    float x;
    float y;
    float w;
    float h;
    int texture_width;
    int texture_height;
    int sprite_speed=12;
    int sprite_col=0;
    int sprite_row=0;
    int currentFrame=0;
    
    SDL_Texture * texture;
    SDL_FRect srcRect;
    SDL_FRect desRect;
  float animationTimer = 0.0f;// Tracks time passed since last frame change
    float frameDuration = 0.1f; // How long EACH frame stays on screen (in seconds)

    
    GameObject(float x,float y,float width,float height);
    void SetTexture(SDL_Renderer* r,std::string file,int sp_col=0,int sp_row=0);
    void Update(float dt,InputManager * input);
    void FixedUpdate(float dt,InputManager * input);
    void Render(SDL_Renderer * r);
    void RenderSprite(SDL_Renderer *r);
    void NextFrame();
    void resetAnimation();
    void stopAnimation();
    void startAnimation();
};