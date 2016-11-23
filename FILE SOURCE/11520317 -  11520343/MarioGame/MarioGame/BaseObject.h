#ifndef _BASEOBJECT_H
#define _BASEOBJECT_H

#include "DirectXGame.h"
#include "GameTime.h"
#include "Camera.h"
#include "SweptAABB.h"

static bool Intersect(const RECT *rect1, const RECT *rect2)
{
	if (rect1 == NULL || rect2 == NULL)
		return false;

	if (rect1->right < rect2->left) // _rect bên trái so với obj->_rect
		return false;
	if (rect1->left > rect2->right) // _rect bên phải so với obj->_rect
		return false;
	if (rect1->bottom > rect2->top) // _rect bên trên so với obj->_rect
		return false;
	if (rect1->top < rect2->bottom) // _rect bên dưới so với obj->_rect
		return false;

	return true;
}

static Box ConvertRectToBox(RECT rect, float vx = 0.0f, float vy = 0.0f)
{
	Box box(
		rect.left, 
		rect.top, 
		rect.right - rect.left,
		rect.top - rect.bottom,
		vx,
		vy
		);

	return box;
}

static Box ConvertRectToBoardBox(RECT rect, float vx = 0.0f, float vy = 0.0f)
{
	return GetSweptBroadphaseBox(ConvertRectToBox(rect, vx, vy));
}


enum EObjectName
{
    NONE_OBJECT = 0,
    MARIO_OBJECT = 1,

    ENEMY_OBJECT,//
    TURTLE_OBJECT,//
    FLYING_TURTLE_OBJECT,//

    MUSHROOM_OBJECT,//
    MUSHROOM_BLOCK_OBJECT,
    FLOWER_OBJECT,
    FLOWER_BLOCK_OBJECT,
    LIFE_MUSHROOM_OBJECT,//
    LIFE_MUSHROOM_BLOCK_OBJECT,
    COIN_OBJECT,
    COIN_BRICK_OBJECT,
    COIN_BLOCK_OBJECT,
    STAR_OBJECT,//
    STAR_BLOCK_OBJECT,

    BLOCK_OBJECT,
    BRICK_OBJECT,
    CLOUD_OBJECT,
    BAR_OBJECT,//2
	GODOWN_BAR_OBJECT,//2
	GOUP_BAR_OBJECT,//2
	HORIZONTAL_BAR_OBJECT,//2
    CARNIVOROUSFLOWER_OBJECT,
    CARNIVOROUSFLOWER_PIPE_OBJECT,
    PIPE_OBJECT,
    CREEP_PIPE_OBJECT_1,
	CREEP_PIPE_OBJECT_2,
	CREEP_UP_PIPE_OBJECT_1,
	CREEP_UP_PIPE_OBJECT_2,
    HORIZONTAL_PIPE_OBJECT_1,
	HORIZONTAL_PIPE_OBJECT_2,
    LEFT_LAND_OBJECT,
    LAND_OBJECT,
    RIGHT_LAND_OBJECT,
    FENCE_OBJECT,
    GRASS_OBJECT,
    MOUNTAIN_OBJECT,
    SIGN_OBJECT,
    LAMP_OBJECT,
    TREE_OBJECT,
    BIG_TREE_OBJECT,
    TOWER_OBJECT,

	MACHINE_OBJECT,
	SPRING_OBJECT,
	TURTLE2_OBJECT,//
	FLAG_POSITION_OBJECT,
	BULLET_OBJECT,
	MACHINE_BULLET_OBJECT
};

/*
Lớp cơ sở cho tất cả các đối tượng trong game.
*/
class BaseObject
{
public:
	EObjectName _OType;
	DXTexture *_texture; // texture
	int _offset_X, _offset_Y; // xác định frame
	RECT _rectSource; // HCN thể hiện frame animation đối tượng
public:
	int _width, _height; // kích thước
	RECT _rect;
	D3DXVECTOR2 _position; // vị trí
public:
	BaseObject(DXTexture *, D3DXVECTOR2);
	virtual void Update(GameTime *); // Update Object
	virtual void Draw(DXGame *, Camera *); // Vẽ Object theo camera
	virtual void Draw(DXGame *, Camera *, D3DXCOLOR); 
	virtual void UpdateBound();
	virtual Box GetObjectBox();
	virtual EObjectName GetType();
	virtual ~BaseObject();
};

#endif