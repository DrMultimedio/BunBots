#include "Player.h"

void Player::addPlayerModel(ISceneManager* smgraux, IVideoDriver* driveraux){
    this->node = smgraux->addCubeSceneNode(10.0f, 0, 0, core::vector3df(0.0f, 0.0f, -85.0f), core::vector3df(0, 0, 0), core::vector3df(5.0f, 1.0f, 1.0f));
    
    if (node)
    {
        node->setDebugDataVisible( true);

        this->node->setMaterialTexture(0, driveraux->getTexture("Materials/madero.jpg"));
        this->node->setMaterialFlag(video::EMF_LIGHTING, false);
    }


}
void Player::move (char axis, int direction, float frameDeltaTime){
    //esta funcion permitira moverse al usuario. Pedimos el eje de movimiento, la direccion y el deltatime
    if(direction > 0){
        direction = 1;
    }
    else if (direction < 0) {
        direction = -1;
    }
    else{
        direction = 0;
    }
    core::vector3df nodePosition = this->node->getPosition();
    switch (axis){
        case 'X':
            if(nodePosition.X<-200){
                direction = 1;
            }
            else if(nodePosition.X>950)
                direction = -1;
            nodePosition.X += this->speed * direction * frameDeltaTime;

            break;
        case 'Y':
            nodePosition.Y += this->speed * direction * frameDeltaTime;
            break;
        case 'Z':

            nodePosition.Z += this->speed * direction * frameDeltaTime;
            break;

    }
    this->node->setPosition(nodePosition);

}


