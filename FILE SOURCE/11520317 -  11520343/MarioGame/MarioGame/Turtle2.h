#ifndef _Turtle2_H_
#define _Turtle2_H_

#include "Enemy.h"
#include "Collision.h"

class Turtle2 : public Enemy
{
protected:
public:
	Turtle2(DXTexture *, D3DXVECTOR2, Direction = Direction::LEFT, D3DXVECTOR2 = D3DXVECTOR2(VELOCITY_NORMAL, VELOCITY_FAST));
	virtual void Update(GameTime *); 
	virtual void Draw(DXGame *, Camera *); 
	virtual void UpdateObjectState(GameTime *);
	virtual void UpdateAnimation(); 

	virtual void CollisionWithMario();
	virtual void CollisionWithBullet();
};

#endif