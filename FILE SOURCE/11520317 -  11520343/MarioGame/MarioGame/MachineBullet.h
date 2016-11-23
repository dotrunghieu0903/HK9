#ifndef _MACHINEBULLET_H_
#define _MACHINEBULLET_H_

#include "DynamicObject.h"
#include "Collision.h"

class MachineBullet : public DynamicObject, public Collision
{
	float _distance;
public:
	bool _isCollision;
	bool _isTopCol;
public:
	MachineBullet(DXTexture *, D3DXVECTOR2, Direction, D3DXVECTOR2 = D3DXVECTOR2(VELOCITY_FAST, VELOCITY_FAST));
	virtual void Update(GameTime *);
	virtual void Draw(DXGame *, Camera *);
	virtual void UpdateObjectState(GameTime *);
	virtual void UpdateAnimation();

	virtual void HasCollision();
	virtual void HasTopCollision();

	virtual void BeginToCheckCollisions();
	virtual void TopCol(BaseObject *obj);
	virtual void BottomCol(BaseObject *obj);
	virtual void LeftCol(BaseObject *obj);
	virtual void RightCol(BaseObject *obj);
	virtual CollisionDirection CheckCollisions(BaseObject *);
	virtual void ResponseCollisions();
};

#endif