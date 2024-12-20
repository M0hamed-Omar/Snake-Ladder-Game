#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}

bool GameObject::IsOverLapping(GameObject* Obj)
{
	return false;
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

GameObject::~GameObject()
{
}
 
void GameObject::ResetFlag()
{
	return;
}

void GameObject::resetStationOwner()
{
	return;
}
