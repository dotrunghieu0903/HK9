#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "BaseObject.h"


static bool IsCollisionableObject(BaseObject *obj)
{
	switch (obj->GetType())
	{
	case EObjectName::CLOUD_OBJECT:
	case EObjectName::FENCE_OBJECT:
	case EObjectName::GRASS_OBJECT:
	case EObjectName::MOUNTAIN_OBJECT:
	case EObjectName::SIGN_OBJECT:
	case EObjectName::LAMP_OBJECT:
	case EObjectName::TREE_OBJECT:
	case EObjectName::BIG_TREE_OBJECT:
		return false;
		break;

	default:
		return true;
		break;
	}
}

static bool IsMovableObject(BaseObject *obj)
{
	switch (obj->GetType())
	{
	case EObjectName::ENEMY_OBJECT:
	case EObjectName::TURTLE_OBJECT:
	case EObjectName::FLYING_TURTLE_OBJECT:
	case EObjectName::TURTLE2_OBJECT:

	case EObjectName::MUSHROOM_OBJECT:
	case EObjectName::LIFE_MUSHROOM_OBJECT:
	case EObjectName::STAR_OBJECT:

	case EObjectName::BAR_OBJECT:
	case EObjectName::GODOWN_BAR_OBJECT:
	case EObjectName::GOUP_BAR_OBJECT:
	case EObjectName::HORIZONTAL_BAR_OBJECT:
		return true;
		break;
	default:
		return false;
		break;
	}
}

static bool IsMovableLivingObject(BaseObject *obj)
{
	switch (obj->GetType())
	{
	case EObjectName::ENEMY_OBJECT:
	case EObjectName::TURTLE_OBJECT:
	case EObjectName::FLYING_TURTLE_OBJECT:
	case EObjectName::TURTLE2_OBJECT:

	case EObjectName::MUSHROOM_OBJECT:
	case EObjectName::LIFE_MUSHROOM_OBJECT:
	case EObjectName::STAR_OBJECT:
		return true;
		break;
	default:
		return false;
		break;
	}
}

#endif
