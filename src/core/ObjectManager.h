#pragma once
#include "GameObject.h"
#include <vector>
class ObjectManager{

    private:
    std::vector<GameObject*> GameObjects;   

    public:

    void pushGameObject(GameObject * g);
    
   const std::vector<GameObject*>& GetObjectList() const {
    return GameObjects;
}
};