#ifndef _BAR_H_
#define _BAR_H_

#include "DynamicObject.h"
#include <math.h>

enum ETypeOfBar
{
	NORMAL_BAR, 
	GODOWN_BAR, 
	GOUP_BAR,
	HORIZONTAL_BAR, 
};

class Bar : public DynamicObject
{
public:
	ETypeOfBar _type;
	bool _isCollision; // sử dụng cho loại NORMAL
protected:
	int _distance; // HOR
	float _origin_X; // HOR
	float _vel_Y;
public:
	Bar(DXTexture *, D3DXVECTOR2, ETypeOfBar = NORMAL_BAR, D3DXVECTOR2 = D3DXVECTOR2(VELOCITY_SLOW, VELOCITY_NORMAL));
	virtual void Update(GameTime *);
	virtual void Draw(DXGame *, Camera *);
	virtual void UpdateObjectState(GameTime *);
	virtual void UpdateAnimation();

	virtual void HasCollision();
};

#endif