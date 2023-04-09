#include <stdlib.h>
#include "GameUtil.h"
#include "BoundingShape.h"
#include "Pickup.h"

Pickup::Pickup(void) : GameObject("Pickup")
{
	mAngle = rand() % 360;
	mRotation = 0;
	mPosition.x = rand() / 2;
	mPosition.y = rand() / 2;
	mPosition.z = 0.0;
	mVelocity.x = 10.0 * cos(DEG2RAD * mAngle);
	mVelocity.y = 10.0 * sin(DEG2RAD * mAngle);
	mVelocity.z = 0.0;
	PickupType = rand() % 3;
}

Pickup::~Pickup(void)
{
}

bool Pickup::CollisionTest(shared_ptr<GameObject> o)
{
	if (o->GetType() == GameObjectType("SubAsteroid")) return false;
	if (o->GetType() == GameObjectType("Asteroid")) return false;
	if (mBoundingShape.get() == NULL) return false;
	if (o->GetBoundingShape().get() == NULL) return false;
	return mBoundingShape->CollisionTest(o->GetBoundingShape());
}

void Pickup::OnCollision(const GameObjectList& objects)
{
	mWorld->FlagForRemoval(GetThisPtr());
}

