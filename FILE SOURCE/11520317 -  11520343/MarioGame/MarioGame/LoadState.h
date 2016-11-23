#ifndef _LoadState_H_
#define _LoadState_H_

#include "State.h"
#include "PlayState.h"
#include "LoadGame.h"


class LoadState : public State
{
private:
	static LoadState _instance;
protected:
	LoadState() { };
public:
	static LoadState* GetInstance()
	{
		return &_instance;
	};

	virtual void Init();
	virtual void Cleanup();

	virtual void Pause();
	virtual void Resume();

	virtual void HandleEvents(DXGame *);
	virtual void Update(GameTime*);
	virtual void Draw(DXGame *);
};

#endif