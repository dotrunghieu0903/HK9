#ifndef _MUSHROOM_H_
#define _MUSHROOM_H_

#include "LivingObject.h"

enum ETypeOfMushroom
{
	NORMAL_MUSHROOM,
	LIFE_MUSHROOM
};

class Mushroom : public LivingObject
{
public:
	bool _isMoveUp;
	ETypeOfMushroom _type;
	D3DXVECTOR2 _maxV;
private:
	bool _SFreeFall;
public:
	Mushroom(DXTexture *, D3DXVECTOR2, ETypeOfMushroom, Direction = Direction::LEFT, D3DXVECTOR2 = D3DXVECTOR2(VELOCITY_NORMAL, VELOCITY_FAST));
	virtual void Update(GameTime *);
	virtual void Draw(DXGame *, Camera *);
	virtual void UpdateObjectState(GameTime *);
	virtual void UpdateAnimation();

	virtual void SetMovingDirection(Direction);

	virtual void BeginToCheckCollisions();
	virtual void TopCol(BaseObject *obj);
	virtual void BottomCol(BaseObject *obj);
	virtual void LeftCol(BaseObject *obj);
	virtual void RightCol(BaseObject *obj);
	virtual CollisionDirection CheckCollisions(BaseObject *);
	virtual void ResponseCollisions();
};

#endif