#ifndef _TURTLE_H_
#define _TURTLE_H_

#include "Enemy.h"
#include <math.h>

enum ETypeOfTurtle
{
	NORMAL_TURTLE,
	FLYING_TURTLE
};

class Turtle : public Enemy
{
private:
	float _angle; 
	float _origin_X, _origin_Y;
	float _distance;

	bool _isMidTopCol;
	bool _flagMidCol;
public:
	ETypeOfTurtle _type;
public:
	Turtle(DXTexture *, D3DXVECTOR2, ETypeOfTurtle = NORMAL_TURTLE, Direction = Direction::LEFT, D3DXVECTOR2 = D3DXVECTOR2(150, VELOCITY_FAST));
	virtual void Update(GameTime *); // Update
	virtual void Draw(DXGame *, Camera *); // Vẽ
	virtual void UpdateObjectState(GameTime *);
	virtual void UpdateAnimation();

	virtual void CollisionWithMario();
	virtual void CollisionWithBullet();

	virtual bool CheckMidTopCollisions(BaseObject *, CollisionDirection);
	virtual void ResponseCollisions();
};

#endif