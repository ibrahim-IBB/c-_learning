#pragma once
#include "../InputManager.h"
#include <iostream>
#include "../../utils/AnimationData.h"

class GameObject{


    private:



    public:
    float x;
    float y;
    float w;
    float h;

   
    
    


    
    GameObject(float x,float y,float width,float height);
    
    virtual void Update(float dt,InputManager * input);
   virtual void FixedUpdate(float dt,InputManager * input);
   virtual void Render(SDL_Renderer * r);
   

};