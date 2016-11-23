#ifndef _COIN_H_
#define _COIN_H_

#include "DynamicObject.h"

class Coin : public DynamicObject
{
public:
	Coin(DXTexture *, D3DXVECTOR2, Direction = Direction::LEFT, D3DXVECTOR2 = D3DXVECTOR2(3, 3));
	virtual void Update(GameTime *);
	virtual void Draw(DXGame *, Camera *);
	virtual void UpdateObjectState(GameTime *);
	virtual void UpdateAnimation();

	virtual void HasCollision();
};

#endif