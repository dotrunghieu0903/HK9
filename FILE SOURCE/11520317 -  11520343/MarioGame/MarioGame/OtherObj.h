#ifndef _OTHEROBJ_H_
#define _OTHEROBJ_H_

#include "StaticObject.h"


enum TypeOfLand
{
	LEFT_LAND,
	MIDDLE_LAND,
	RIGHT_LAND
};

class Land : public StaticObject
{
public:
	Land(DXTexture *, D3DXVECTOR2, TypeOfLand = MIDDLE_LAND);
};


class Tower : public StaticObject
{
public:
	Tower(DXTexture *, D3DXVECTOR2);
};


class Block : public StaticObject
{
public:
	Block(DXTexture *, D3DXVECTOR2);
};


enum ESceneObject
{
	FENCE,
	MOUNTAIN,
	SIGN,
	LAMP,
	TREE,
	BIG_TREE
};

class Scene : public StaticObject
{
public:
	Scene(DXTexture *, D3DXVECTOR2, ESceneObject type);
};

#endif