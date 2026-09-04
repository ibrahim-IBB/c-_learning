#include "Renderer.h"
#include "ObjectManager.h"


void Renderer::RendererInit(SDL_Renderer *r){

    renderer=r;
    std::cout<<"Renderer Created"<<std::endl;
}

void Renderer::ClearRender(){

    SDL_SetRenderDrawColor(renderer,50,50,50,255);
    SDL_RenderClear(renderer);
}

void Renderer::Render(ObjectManager * obj_manager){
    const auto& ObjectList =obj_manager->GetObjectList();
   for(auto it = ObjectList.begin(); it != ObjectList.end() ; ++it){
   (*it)->RenderSprite(renderer);
   }
   
}

void Renderer::RenderPresent(){
    
    SDL_RenderPresent(renderer);
}


Renderer::~Renderer(){
    SDL_DestroyRenderer(renderer);
}


