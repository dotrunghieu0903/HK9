#ifndef _GRASS_H_
#define _GRASS_H_

#include "DynamicObject.h"

class Grass : public DynamicObject
{
public:
	Grass(DXTexture *, D3DXVECTOR2);
	virtual void Update(GameTime *);
	virtual void Draw(DXGame *, Camera *);
	virtual void UpdateObjectState(GameTime *);
	virtual void UpdateAnimation();
};

#endif