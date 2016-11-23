#ifndef _SAVESTATE_H_
#define _SAVESTATE_H_

#include "State.h"


class SaveState : public State
{
private:
	static SaveState _instance;

protected:
	SaveState() { };
public:
	static SaveState* GetInstance()
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