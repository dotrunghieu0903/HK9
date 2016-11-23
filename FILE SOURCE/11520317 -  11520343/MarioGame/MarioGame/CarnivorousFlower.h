#ifndef _CARNIVOROUSFLOWER_H_
#define _CARNIVOROUSFLOWER_H_

#include "DynamicObject.h"

class CarnivorousFlower : public DynamicObject
{
public:
	bool _isDelayMove;
public:
	CarnivorousFlower(DXTexture *, D3DXVECTOR2, Direction = Direction::NONE, D3DXVECTOR2 = D3DXVECTOR2(0, VELOCITY_SLOW));
	virtual void Update(GameTime *);
	virtual void Draw(DXGame *, Camera *);
	virtual void UpdateObjectState(GameTime *);
	virtual void UpdateAnimation();

	virtual void HasCollision();
};

#endif