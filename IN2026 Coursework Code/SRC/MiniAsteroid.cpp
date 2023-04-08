#include "MiniAsteroid.h"
#include "MiniAsteroid.h"
#include <stdlib.h>
#include "GameUtil.h"
#include "BoundingShape.h"
#include "MiniAsteroid.h"

MiniAsteroid::MiniAsteroid() : GameObject("MiniAsteroid")
{
	mAngle = rand() % 360;
	mRotation = 0; // rand() % 90;
	mPosition.x = rand() / 2;
	mPosition.y = rand() / 2;
	mPosition.z = 0.0;
	mVelocity.x = 10.0 * cos(DEG2RAD * mAngle);
	mVelocity.y = 10.0 * sin(DEG2RAD * mAngle);
	mVelocity.z = 0.0;
}

MiniAsteroid::MiniAsteroid(GLfloat Angle, GLVector3f Position) : GameObject("MiniAsteroid")
{
	mAngle = Angle;
	mRotation = 0;
	mPosition = Position;
	mPosition.z = 0.0;
	mVelocity.x = 10.0 * cos(DEG2RAD * mAngle);
	mVelocity.y = 10.0 * sin(DEG2RAD * mAngle);
	mVelocity.z = 0.0;
}

MiniAsteroid::~MiniAsteroid(void)
{
}

bool MiniAsteroid::CollisionTest(shared_ptr<GameObject> o)
{
	if (GetType() == o->GetType()) return false;
	if (mBoundingShape.get() == NULL) return false;
	if (o->GetBoundingShape().get() == NULL) return false;
	return mBoundingShape->CollisionTest(o->GetBoundingShape());
}

void MiniAsteroid::OnCollision(const GameObjectList& objects)
{
	mWorld->FlagForRemoval(GetThisPtr());
}