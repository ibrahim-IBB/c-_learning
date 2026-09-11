#include "game.h"
#include "SceneObjects/GameObject.h"
#include "../game/Player.h"





bool Game::init(const char *title,int width,int height){
 if(!SDL_Init(SDL_INIT_VIDEO)){
            std::cout<<"Error init video:"<<SDL_GetError()<<std::endl;
            return 1;
        }

       
        this->title=title;
        this->height=height;
        this->width=width;

            if (!init_window()) return false;
    if (!init_renderer()) return false;
         SDL_SetRenderVSync(renderer,1);
        LastTime=SDL_GetTicksNS();
        running=true;
      
        Render_Engine.RendererInit(renderer);

        
        Player *s = new Player(10,10,160,160);
   
        
        s->StartAnimation();
        GameObject * g=s;
        s->SetTexture(renderer,"assets/Walking");

        
        obj_manager.pushGameObject(g);

   
        return true;
        
}

bool Game::init_window(){
window=SDL_CreateWindow(title,width,height,SDL_WINDOW_RESIZABLE);
        if(!window){
            std::cout<<"Error init window : "<<SDL_GetError()<<std::endl;
            return false;
        }

        return true;
}

bool Game::init_renderer(){
renderer=SDL_CreateRenderer(window,nullptr);
        if(!renderer){
            std::cout<<"Error init renderer : "<<SDL_GetError()<<std::endl;
            return false;
        }
        return true;
}



void Game::run(){
   
    while(running){
       

        processEvent();
        
        Uint64 now=SDL_GetTicksNS();
        float frame_time=(now-LastTime)/1000000000.0f;// get the frame time in seconds
        LastTime=now;
        if(frame_time>0.25f) {frame_time=0.25f;};

        accumulator+=frame_time;

        Update(frame_time);
        while(accumulator> FIXED_TIME){

            FixedUpdate(FIXED_TIME);
            //here is the logic of anything that need fixed timestep (phyiscs)
            accumulator-=FIXED_TIME;
        }
        
        input.update();//InputManager update the status so the functions like IsKeyDown can work
        
        Render_Engine.ClearRender();
        Render_Engine.Render(&obj_manager);
        Render_Engine.RenderPresent();
    }
}

void Game::processEvent(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type==SDL_EVENT_QUIT){
            running=false;
        }
    }
}


void Game::FixedUpdate(float dt){

    

    
      const auto& ObjectList =obj_manager.GetObjectList();
   for(auto it = ObjectList.begin(); it != ObjectList.end() ; ++it){
   (*it)->FixedUpdate(dt,&input);
   }
    
}


void Game::Update(float dt){


      const auto& ObjectList =obj_manager.GetObjectList();
   for(auto it = ObjectList.begin(); it != ObjectList.end() ; ++it){
   (*it)->Update(dt,&input);
   }
    
}



void Game::end(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}