#ifndef _AboutState_H_
#define _AboutState_H_

#include "State.h"
#include "BaseInfo.h"
#include "BeginState.h"


class AboutState : public State
{
private:
	static AboutState _instance;

	BaseInfo *_backGround;
	bool _lastESCKey;
protected:
	AboutState() { };
public:
	static AboutState* GetInstance()
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