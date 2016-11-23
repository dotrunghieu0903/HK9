#ifndef _SaveGame_H_
#define _SaveGame_H_

#include "Markup.h"
#include "GameWorld.h"
#include <list>
#include <map>

class SaveGame
{
public:
	CMarkup *xml;
	void Save(GameWorld *);
	void CreateSaveFile(
		char *filename, 
		QuadTree *quadTree, 
		map<int, QNode *> *listNodes, 
		map<int, BaseObject *> *listObjects, 
		MarioPlayer *mario,
		GameWorld *world);
};

#endif