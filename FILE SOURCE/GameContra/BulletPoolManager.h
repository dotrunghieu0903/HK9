#ifndef __BULLETPOOLMANAGER_H__
#define __BULLETPOOLMANAGER_H__

#include "Bullet.h"
#include "BulletPool.h"
#include <list>

class BulletPoolManager
{
private:
	//std::list<Bullet* > m_ListBulletInGame;
	//LazerBullet* m_lazerShoot;
	BulletPoolManager();
	~BulletPoolManager();
public:
	std::list<Bullet*> m_ListBulletInGame;
	static BulletPoolManager* m_Instance;
	static BulletPoolManager* getInstance();

	void Initialize();
	void addBulletIntoList(eIDTypeBullet, D3DXVECTOR3, D3DXVECTOR2, float _factor = 0.0f, float _rotationAngle = 0.0f);
	void popBulletFromList();
	void Update();
	void UpdateAnimation();
	void UpdateMovement();
	void UpdateCollision(Object* checkingObject);
	void Render(SPRITEHANDLE spriteHandler);
	void Release();

	// Danh code
	list<Bullet*> getListBullet() { return m_ListBulletInGame; }
	int GetAmountBulletOfType(eIDTypeBullet _type)
	{
		int result = 0;
		for (auto i = m_ListBulletInGame.begin(); i != m_ListBulletInGame.end(); ++i)
		{
			if ((*i)->getTypeBullet() == _type)
			{
				++result;
			}
		}
		return result;
	}
	void KillBullet(eIDTypeBullet _type)
	{
		for (auto i = m_ListBulletInGame.begin(); i != m_ListBulletInGame.end(); ++i)
		{
			if ((*i)->getTypeBullet() == _type)
			{
				(*i)->setObjectState(eObjectState::STATE_DEATH);
			}
		}
		//m_lazerShoot->setObjectState(eObjectState::STATE_DEATH);
	}
};

#endif