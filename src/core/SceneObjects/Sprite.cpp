#include "Sprite.h"







void Sprite::SetTexture(SDL_Renderer* r,std::string file){

  
   const  char * basePath=SDL_GetBasePath();

   animation_data.ReadFile(file+".json");
   std::string full_path=std::string(basePath)+ file + ".bmp";
   std::cout<<"fullpath:"<<full_path<<std::endl;
   SDL_Surface * surface=  SDL_LoadBMP(full_path.c_str());

    if(!surface){
    std::cout<<"error while createing surface:"<<SDL_GetError()<<std::endl;
    
   }

  
   texture =SDL_CreateTextureFromSurface(r,surface);
   
  
   
   //init srcRect values
   srcRect.x=animation_data.getFrames()[0].frame_r.x;
   srcRect.y=animation_data.getFrames()[0].frame_r.y;
   srcRect.w=animation_data.getFrames()[0].frame_r.w;
   srcRect.h=animation_data.getFrames()[0].frame_r.h;


   SDL_DestroySurface(surface);
}


void Sprite::Update(float dt,InputManager * input){


   animationTimer+=dt*speed_multiplayer;

   if(animationTimer>=frame_duration){

      animationTimer-=frame_duration;

       if(AnimationRunning){
      
      NextFrame();
      

   }

   }

  

   

   //update location and scale of the texture 
   desRect.x=x;
   desRect.y=y;
   desRect.w=w;
   desRect.h=h;

}


void Sprite::Render(SDL_Renderer * r){

   SDL_RenderTexture(r,texture,&srcRect,&desRect);
   
}

void Sprite::NextFrame(){

   
   std::cout<<"number of frames" <<animation_data.FrameCount()<<std::endl;

   if(currentFrame>=animation_data.FrameCount()-1){

      currentFrame=0;

   }else{
      currentFrame+=1;
   }

     srcRect.x=animation_data.getFrames()[currentFrame].frame_r.x;
   srcRect.y=animation_data.getFrames()[currentFrame].frame_r.y;
   srcRect.w=animation_data.getFrames()[currentFrame].frame_r.w;
   srcRect.h=animation_data.getFrames()[currentFrame].frame_r.h;

   std::cout<<"currentFrame:"<<currentFrame<<std::endl;
   std::cout<<"x:"<<srcRect.x<<"y:"<<srcRect.y<<"w:"<<srcRect.w<<"h:"<<srcRect.h<<std::endl;
}


void Sprite::StartAnimation(){
   currentFrame=0;
   AnimationRunning=true;
}

void Sprite::EndAnimation(){
   currentFrame=0;
   AnimationRunning=false;
}

void Sprite::StopAnimation(){

   AnimationRunning=false;
}

void Sprite::ContiuneAnimation(){

   AnimationRunning=true;
}
