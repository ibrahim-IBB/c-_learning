#include "../core/SceneObjects/Sprite.h"
class Player : public Sprite {


    public:

    Player(float x,float y,float width,float height);
    void Update(float dt,InputManager * input) override;


};