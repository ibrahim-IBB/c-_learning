#include "InputManager.h"


InputManager::InputManager():
 currentState(nullptr)
{
    currentState=SDL_GetKeyboardState(&numKeys);

    std::memset(previousState,0,sizeof(previousState));
   

    ActionMap["jump"]=SDL_SCANCODE_SPACE;

    
    
  

}


void InputManager::update(){

    if(currentState !=nullptr){
    std::memcpy(previousState,currentState, sizeof(previousState));
      
    }

    currentState=SDL_GetKeyboardState(nullptr);



}


bool InputManager::IsKeyDown(SDL_Scancode key){
    return currentState[key];
}

bool InputManager::IsKeyPressed(SDL_Scancode key){

  
                     
    return (currentState[key] && !previousState[key] );

}

bool InputManager::IsKeyReleased(SDL_Scancode key){

    

    return (!currentState[key] && previousState[key] );
 
}