#ifndef _Machine_H_
#define _Machine_H_

#include "MachineBullet.h"
#include <list>
#include "SoundManagement.h"

class Machine : public DynamicObject
{
	DXTexture *_bulletTexture;
	bool _isOutOf;
public:
	MachineBullet *_bullet;
public:
	Machine(DXTexture *, D3DXVECTOR2, DXTexture *);
	virtual void Update(GameTime *); 
	virtual void ShootBullet(D3DXVECTOR2, list<BaseObject *> &);
	virtual void Draw(DXGame *, Camera *);
};

#endif