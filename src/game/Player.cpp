#include "Player.h"


void Player::Update(float dt,InputManager * input){
Sprite::Update(dt,input);


if(input->IsKeyDown(SDL_SCANCODE_D)){

    x+=30*dt;
}

}


Player::Player(float x,float y,float width,float height):Sprite(x,y,width,height){

}