#ifndef __PICKUP_H__
#define __PICKUP_H__

#include "GameObject.h"

class Pickup : public GameObject
{

private:

	int PickupType;
	
public:

	Pickup(void);
	~Pickup(void);

	bool CollisionTest(shared_ptr<GameObject> o);
	void OnCollision(const GameObjectList& objects);

	int GetPickupType() {
		return PickupType;
	}
	
};
#endif