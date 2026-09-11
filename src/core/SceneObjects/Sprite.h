#include "GameObject.h"


class Sprite : public GameObject{

     private:
     SDL_Texture * texture;
    bool AnimationRunning=false;

    int currentFrame=0;

    AnimationData animation_data;

    SDL_FRect desRect;
    SDL_FRect srcRect;

    float animationTimer=0.0f;
    float frame_duration=0.1f;
    
    float speed_multiplayer=0.4f;

    public:

   using GameObject::GameObject;

    void Render(SDL_Renderer * r) override;
    void Update(float dt,InputManager * input) override;
     void SetTexture(SDL_Renderer* r,std::string file);
     void StartAnimation();
     void EndAnimation();
     void StopAnimation();
     void ContiuneAnimation();
     void NextFrame();
     
};