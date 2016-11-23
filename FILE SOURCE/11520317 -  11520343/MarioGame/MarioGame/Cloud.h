#ifndef _CLOUD_H_
#define _CLOUD_H_

#include "DynamicObject.h"

class Cloud : public DynamicObject
{
public:
	Cloud(DXTexture *, D3DXVECTOR2);
	virtual void Update(GameTime *);
	virtual void Draw(DXGame *, Camera *);
	virtual void UpdateObjectState(GameTime *);
	virtual void UpdateAnimation();
};

#endif