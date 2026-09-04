#include "GameObject.h"
#include "SDL3/SDL_image.h"




GameObject::GameObject(float x,float y,float width,float height):x(x),y(y),w(width),h(height){

    desRect={x,y,w,h};
    srcRect={100,100,600,600};
}


void GameObject::FixedUpdate(float dt,InputManager * input){




}

void GameObject::Update(float dt,InputManager * input){

    if(input->IsKeyDown(SDL_SCANCODE_D)){
    desRect.x+=50*dt;
  
}


if (input->IsKeyPressed(SDL_SCANCODE_D)){
    startAnimation();
    std::cout<<"pressed"<<std::endl;
}


if(input->IsKeyReleased(SDL_SCANCODE_D)){
    stopAnimation();
    std::cout<<"released"<<std::endl;
}



    
    animationTimer+=dt;
   
    if(animationTimer>=frameDuration){
     
 NextFrame();
 animationTimer -= frameDuration;
    }
   
}


void GameObject::Render(SDL_Renderer * r){
    
    SDL_RenderTexture(r,texture,&srcRect,&desRect);
}

void GameObject::SetTexture(SDL_Renderer* r,std::string file,int sp_col,int sp_row){

   sprite_col=sp_col;
   sprite_row=sp_row;
   const  char * basePath=SDL_GetBasePath();

   std::string full_path=std::string(basePath)+ file;
   std::cout<<"fullpath:"<<full_path<<std::endl;
   SDL_Surface * surface=  SDL_LoadBMP(full_path.c_str());

    if(surface){
    texture_width=surface->w;
    texture_height=surface->h;
   }else{
    std::cout<<"error while createing surface:"<<SDL_GetError()<<std::endl;
   }

   std::cout<<SDL_GetError()<<std::endl;
   texture =SDL_CreateTextureFromSurface(r,surface);
   
   
   SDL_DestroySurface(surface);
}


void GameObject::RenderSprite(SDL_Renderer * r){

    int w=texture_width/sprite_col;
    int h=texture_height/sprite_row;

    int col=currentFrame%sprite_col;
    int row=currentFrame/sprite_col;

            srcRect = { 
    static_cast<float>(col * w), 
    static_cast<float>(row * h), 
    static_cast<float>(w), 
    static_cast<float>(h)   
    };
 SDL_RenderTexture(r,texture,&srcRect,&desRect);
    
}


void GameObject::NextFrame(){
    if(AnimationRunning){
  currentFrame++;
    int totalFrames=sprite_col * sprite_row;
    if(currentFrame>=totalFrames){
        currentFrame=0;
    }
    }
  
}


void GameObject::startAnimation(){
    animationTimer=0;
    currentFrame=0;
    AnimationRunning=true;
}

void GameObject::stopAnimation(){
    animationTimer=0;
    currentFrame=0;
    AnimationRunning=false;
}