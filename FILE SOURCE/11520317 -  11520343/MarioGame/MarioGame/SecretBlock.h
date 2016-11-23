#ifndef _SECRETBLOCK_H_
#define _SECRETBLOCK_H_

#include "DynamicObject.h"
#include "Coin.h"
#include "Mushroom.h"
#include "Flower.h"
#include "Star.h"
#include <list>

enum ETypefOfSecretBlock
{
	COIN_SECRET_BLOCK,
	NORMAL_MUSHROOM_SECRET_BLOCK,
	LIFE_MUSHROOM_SECRET_BLOCK,
	FLOWER_SECRET_BLOCK,
	STAR_SECRET_BLOCK
};

class SecretBlock : public DynamicObject
{
	float _vel_X;
	bool _isOutOf;
public:
	ETypefOfSecretBlock _type;
	bool _isCollision; 
	DynamicObject *_object; 
	bool _justCollision;
public:
	SecretBlock(DXTexture *, D3DXVECTOR2, DXTexture *, ETypefOfSecretBlock);
	virtual void Update(GameTime *);
	virtual void Draw(DXGame *, Camera *);
	virtual void UpdateObjectState(GameTime *);
	virtual void UpdateAnimation();

	virtual void HasCollision(list<BaseObject *> &);
};

#endif