#ifndef _STAR_H_
#define _STAR_H_

#include "LivingObject.h"

class Star : public LivingObject
{
public:
	bool _isMoveUp;
private:
	D3DXVECTOR2 _a;
	D3DXVECTOR2 _maxV;
	bool _SFreeFall;
public:
	Star(DXTexture *, D3DXVECTOR2, D3DXVECTOR2 = D3DXVECTOR2(200, 800), D3DXVECTOR2 = D3DXVECTOR2(1200, -1300));
	virtual void Update(GameTime *);
	virtual void Draw(DXGame *, Camera *); 
	virtual void UpdateObjectState(GameTime *);
	virtual void UpdateAnimation(); 

	virtual void BeginToCheckCollisions();
	virtual void TopCol(BaseObject *obj);
	virtual void BottomCol(BaseObject *obj);
	virtual void LeftCol(BaseObject *obj);
	virtual void RightCol(BaseObject *obj);
	virtual CollisionDirection CheckCollisions(BaseObject *);
	virtual void ResponseCollisions();
};

#endif