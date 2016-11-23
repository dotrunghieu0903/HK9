#ifndef _MARIOGAME_H_
#define _MARIOGAME_H_

#include "DirectXGame.h"
#include "Map.h"
#include "Camera.h"
#include "QuadTree.h"


#include "MarioPlayer.h"
#include "Brick.h"
#include "Coin.h"
#include "Mushroom.h"
#include "Flower.h"
#include "Grass.h"
#include "Cloud.h"
#include "CarnivorousFlower.h"
#include "Bar.h"
#include "Enemy.h"
#include "Turtle.h"
#include "SecretBlock.h"
#include "Pipe.h"
#include "OtherObj.h"
#include "Star.h"

#include "PauseMenu.h"
#include "GameInfo.h"
#include "WaitScreen.h"
#include "GameOverScreen.h"
#include "StartMenu.h"

#include "TextureManagement.h"
#include "StateManagement.h"
#include "BeginState.h"


class MarioGame : public DXGame
{
	GameTime *gameTime;
	Camera *camera;

	TextureManagement *textureManagement;
	SoundManagement *soundManagement;
	StateManagement *stateManagement;

	/*
	Map *m;
	QuadTree *quadTree;
	map<int, BaseObject *> listObjects;
	*/

	PauseMenu *pauseMenu;
	//StartMenu *startMenu;
	/*
	Score *score;
	Life *life;
	World *world;
	GameInfo *gameInfo;*/
	WaitScreen *wait;
	GameOverScreen *gameOver;

	/*
	DXSurface *background;
	DXTexture *texture, *texture1, *texture2;
	//MarioPlayer *mario;
	DXTexture *bulletTexture;

	DXSoundBuffer *sound1, *sound2;

	DXTexture *pauseTexture, *startTexture, *numberTexture, *lifeTexture, *worldTexture, *waitTexture, *gameOverTexture;
	DXTexture *brickTexture, *blockTexture, *exploredBrickTexture, *coinTexture, *mushroomTexture, *flowerTexture, *grassTexture, *cloudTexture, *carnivorousFlowerTexture, *barTexture, *enemyTexture, *turtleTexture, *secretBlockTexture, *pipeTexture, *landTexture;
	DXTexture *starTexture;
	*/
	
	/*Brick *brick;
	Coin *coin;
	Flower *flower;
	Grass *grass;
	Cloud *cloud;
	CarnivorousFlower *carnivorousFlower;
	Bar *bar;
	Mushroom *mushroom;
	Enemy *enemy;
	Turtle *turtle;
	SecretBlock *secretBlock;
	Pipe *pipe;
	Land *land;*/

public:
	MarioGame();
	bool Init(HINSTANCE);
	void Run();
	void End();
	void Initialize();
	void Update();
	void Draw();
	~MarioGame();
};

#endif