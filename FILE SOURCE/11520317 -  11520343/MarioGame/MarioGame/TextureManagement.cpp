#include "TextureManagement.h"


TextureManagement TextureManagement::_instance = TextureManagement();

bool TextureManagement::Add(LPDIRECT3DDEVICE9 d3dDevice, EOTexture type, char *path)
{
	if (_ListTexture.find(type) != _ListTexture.end()) // đã tồn tại
		return false;

	DXTexture *texture = new DXTexture(d3dDevice);
	texture->LoadTexture(path);
	_ListTexture[type] = texture;

	return true;
}

bool TextureManagement::Add(LPDIRECT3DDEVICE9 d3dDevice, EOTexture type, char *path, int nHor, int nVer)
{
	if (_ListTexture.find(type) != _ListTexture.end()) // đã tồn tại
		return false;

	DXTexture *texture = new DXTexture(d3dDevice);
	texture->LoadTexture(path, nHor, nVer);
	_ListTexture[type] = texture;

	return true;
}

void TextureManagement::AddAll(LPDIRECT3DDEVICE9 d3dDevice)
{
	this->Add(d3dDevice, EOTexture::BACKGROUND_TEXTURE, "BackGround.png", SCREEN_WIDTH / OBJECT_WIDTH, SCREEN_HEIGHT / OBJECT_HEIGHT);
	this->Add(d3dDevice, EOTexture::BEGINBACKGROUND_TEXTURE, "BeginBackground.png", SCREEN_WIDTH / OBJECT_WIDTH, SCREEN_HEIGHT / OBJECT_HEIGHT);
	this->Add(d3dDevice, EOTexture::ABOUTBACKGROUND_TEXTURE, "AboutBackground.png", SCREEN_WIDTH / OBJECT_WIDTH, SCREEN_HEIGHT / OBJECT_HEIGHT);
	this->Add(d3dDevice, EOTexture::SETTINGBACKGROUND_TEXTURE, "SettingBackground.png", SCREEN_WIDTH / OBJECT_WIDTH, SCREEN_HEIGHT / OBJECT_HEIGHT);

	this->Add(d3dDevice, EOTexture::SOUNDLABEL_TEXTURE, "SoundLabel.png");
	this->Add(d3dDevice, EOTexture::SOUNDOPTION_TEXTURE, "SoundOption.png");
	this->Add(d3dDevice, EOTexture::VOLUME_TEXTURE, "Volume.png");

	this->Add(d3dDevice, EOTexture::BAR_TEXTURE, "Bar.png");
	this->Add(d3dDevice, EOTexture::BLOCK_TEXTURE, "Block.png");
	this->Add(d3dDevice, EOTexture::BRICK_TEXTURE, "Brick.png");
	this->Add(d3dDevice, EOTexture::BULLET_TEXTURE, "Bullet.png");
	this->Add(d3dDevice, EOTexture::CARNIVOROUSFLOWER_TEXTURE, "CarnivorousFlower.png");

	this->Add(d3dDevice, EOTexture::CLOUD_TEXTURE, "Cloud.png");
	this->Add(d3dDevice, EOTexture::COIN_TEXTURE, "Coin.png");
	this->Add(d3dDevice, EOTexture::ENEMY_TEXTURE, "Enemy.png");
	this->Add(d3dDevice, EOTexture::EXPLOREDBRICK_TEXTURE, "ExploredBrick.png");
	this->Add(d3dDevice, EOTexture::FENCE_TEXTURE, "Fence.png");

	this->Add(d3dDevice, EOTexture::FIREWORKS_TEXTURE, "Fireworks.png");
	this->Add(d3dDevice, EOTexture::FLAGPOLE_TEXTURE, "FlagPole.png");
	this->Add(d3dDevice, EOTexture::FLOWER_TEXTURE, "Flower.png");
	this->Add(d3dDevice, EOTexture::GAMEOVERSCREEN_TEXTURE, "GameOverScreen.png", SCREEN_WIDTH / OBJECT_WIDTH, SCREEN_HEIGHT / OBJECT_HEIGHT);
	this->Add(d3dDevice, EOTexture::GRASS_TEXTURE, "Grass.png");

	this->Add(d3dDevice, EOTexture::HEIGHTMARIO_TEXTURE, "HeightMario.png");
	this->Add(d3dDevice, EOTexture::HORIZONTALPIPE_TEXTURE, "HorizontalPipe.png");
	this->Add(d3dDevice, EOTexture::LAMP_TEXTURE, "Lamp.png");
	this->Add(d3dDevice, EOTexture::LAND_TEXTURE, "Land.png");
	this->Add(d3dDevice, EOTexture::MACHINEBULLET_TEXTURE, "MachineBullet.png");
	this->Add(d3dDevice, EOTexture::MACHINE_TEXTURE, "Machine.png");
	this->Add(d3dDevice, EOTexture::MARIOICON_TEXTURE, "MarioIcon.png");

	this->Add(d3dDevice, EOTexture::MOUNTAIN_TEXTURE, "Mountain.png");
	this->Add(d3dDevice, EOTexture::MUSHROOM_TEXTURE, "Mushroom.png");
	this->Add(d3dDevice, EOTexture::NUMBER_TEXTURE, "Number.png", 10, 1);
	this->Add(d3dDevice, EOTexture::PAUSEMENU_TEXTURE, "PauseMenu.png");
	this->Add(d3dDevice, EOTexture::PIPE_TEXTURE, "Pipe.png");

	this->Add(d3dDevice, EOTexture::SECRETBLOCK_TEXTURE, "SecretBlock.png");
	this->Add(d3dDevice, EOTexture::SIGN_TEXTURE, "Sign.png");
	this->Add(d3dDevice, EOTexture::SMALLMARIO_TEXTURE, "SmallMario.png");
	this->Add(d3dDevice, EOTexture::SPRING_TEXTURE, "Spring.png");
	this->Add(d3dDevice, EOTexture::STAR_TEXTURE, "Star.png");

	this->Add(d3dDevice, EOTexture::STARTMENU_TEXTURE, "StartMenu.png");
	this->Add(d3dDevice, EOTexture::SUPERMATIO_TEXTURE, "SuperMario.png");
	this->Add(d3dDevice, EOTexture::TOWER_TEXTURE, "Tower.png");
	this->Add(d3dDevice, EOTexture::TREE_TEXTURE, "Tree.png");
	this->Add(d3dDevice, EOTexture::TREE2_TEXTURE, "Tree2.png");

	this->Add(d3dDevice, EOTexture::TURTLE_TEXTURE, "Turtle.png");
	this->Add(d3dDevice, EOTexture::TURTLE2_TEXTURE, "Turtle2.png");
	this->Add(d3dDevice, EOTexture::WAITSCREEN_TEXTURE, "WaitScreen.png", SCREEN_WIDTH / OBJECT_WIDTH, SCREEN_HEIGHT / OBJECT_HEIGHT);
	this->Add(d3dDevice, EOTexture::WORLD_TEXTURE, "World.png");
}

DXTexture* TextureManagement::Get(EOTexture name)
{
	map<EOTexture, DXTexture *>::iterator i;
	i = _ListTexture.find(name);
	if (i == _ListTexture.end())
	{
		return NULL;
	}

	return i->second;
}

EOTexture TextureManagement::Get(DXTexture *texture)
{
	map<EOTexture, DXTexture *>::iterator i;
	for (i = _ListTexture.begin(); i != _ListTexture.end(); i++)
	{
		if (i->second == this->Get(i->first))
			return i->first;
	}

	return EOTexture::BACKGROUND_TEXTURE;
}

