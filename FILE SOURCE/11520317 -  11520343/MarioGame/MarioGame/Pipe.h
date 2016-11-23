#ifndef _PIPE_H_
#define _PIPE_H_

#include "DynamicObject.h"
#include "CarnivorousFlower.h"

// cổng chui thứ x
enum EntryNumber
{
	NONE_ENTRY,
	FIRST_ENTRY,
	SUB_FIRST_ENTRY,
	SECOND_ENTRY,
	SUB_SECOND_ENTRY,
	FIRST_EXIT,
	SECOND_EXIT
};

class Pipe : public DynamicObject
{
public:
	EntryNumber _entryNumber;
	CarnivorousFlower *_flower;
public:
	Pipe(DXTexture *, D3DXVECTOR2, EntryNumber = NONE_ENTRY, DXTexture * = NULL);
	virtual void Update(GameTime *); // Update
	virtual void Draw(DXGame *, Camera *); // Vẽ
	virtual void UpdateObjectState(GameTime *); // Cập nhật logic trạng thái đối tượng

	virtual CarnivorousFlower* GetFlowerObj();

	~Pipe();
};

#endif