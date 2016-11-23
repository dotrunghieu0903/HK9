#ifndef _SPRING_H_
#define _SPRING_H_

#include "DynamicObject.h"


class Spring : public DynamicObject
{
private:
	float _force;
	bool _isCollision;
	bool _isSwingDown;
public:
	Spring(DXTexture *pTexture, D3DXVECTOR2 position, float force = 1600);
	virtual void Update(GameTime *); 
	virtual void Draw(DXGame *, Camera *);
	virtual void UpdateBound();
	virtual void UpdateObjectState(GameTime *); 
	virtual void UpdateAnimation(); 
	virtual float HasCollision();
	virtual float GetSwingForce();
};

#endif