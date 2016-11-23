#ifndef _FLOWER_H_
#define _FLOWER_H_

#include "DynamicObject.h"


class Flower : public DynamicObject
{
public:
	Flower(DXTexture *, D3DXVECTOR2);
	virtual void Update(GameTime *);
	virtual void Draw(DXGame *, Camera *);
	virtual void UpdateObjectState(GameTime *);
	virtual void UpdateAnimation();

	virtual void HasCollision();
};

#endif