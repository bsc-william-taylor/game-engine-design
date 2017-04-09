
#include "Collision.h"

Collision::Collision(Object* object, Object * node) : Observer(object, node)
{
    triggered = false;
    active = true;
}

Collision::~Collision()
{
}

void Collision::update()
{
    if (active)
    {
        Vector<int> pos = object->getPosition();
        Vector<int> size = object->getSize();
        Vector<int> nodeSize = node->getSize();
        Vector<int> nodePos = node->getPosition();

        if (pos.getX() <= nodePos.getX() + nodeSize.getX() && pos.getX() + size.getX() > nodePos.getX())
        {
            if (pos.getY() <= nodePos.getY() + nodeSize.getY() && pos.getY() + size.getY() >= nodePos.getY())
            {
                triggered = true;
            }
        }
    }
}
