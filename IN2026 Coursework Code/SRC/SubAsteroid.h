#ifndef __SUBASTEROID_H__
#define __SUBASTEROID_H__

#include "Asteroid.h"

class SubAsteroid : public GameObject
{
public:
	SubAsteroid(void);
	~SubAsteroid(void);

	bool CollisionTest(shared_ptr<GameObject> o);
	void OnCollision(const GameObjectList& objects);
};

#endif
