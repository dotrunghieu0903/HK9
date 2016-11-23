#ifndef __BOSS_GUN_H__
#define __BOSS_GUN_H__

#include "DynamicObject.h"
#include "BulletPoolManager.h"

class BossGun : public DynamicObject
{
	CSpriteDx9* sprite_dead;
	CSpriteDx9* sprite_alive;
	
	bool isShoot;
	void Shoot();
	D3DXVECTOR3	GetStartPositionOfBullet();
public:
	BossGun();
	BossGun(D3DXVECTOR3 _position, eDirection _direction, eObjectID _objectID);
	void Initialize();
	void UpdateAnimation();
	void UpdateCollision(Object* checkingObject);
	void UpdateMovement();
	void Update();
	void Render(SPRITEHANDLE spriteHandle);
	void Release();
	virtual ~BossGun();
};
#endif