#include "LoadState.h"


LoadState LoadState::_instance;

void LoadState::Init()
{
	Info *info;
	GameWorld *curWorld;
	MarioPlayer *mario;
	GameInfo *gameInfo;
	LoadGame *load;

	load = new LoadGame("SaveGame");
	StateManagement::GetInstance()->ChangeState(PlayState::GetInstance());
	if (load->HasData() == false)
	{
		return;
	}
	curWorld = WorldManagement::GetInstance()->GetCurrentWorld();
	// info
	info = load->GetInfo();

	// mario
	mario = load->GetMarioPlayer();
	curWorld->SetMario(*&mario);

	// gameInfo
	gameInfo = new GameInfo(
		TextureManagement::GetInstance()->Get(EOTexture::MARIOICON_TEXTURE),
		TextureManagement::GetInstance()->Get(EOTexture::WORLD_TEXTURE),
		TextureManagement::GetInstance()->Get(EOTexture::NUMBER_TEXTURE)
		);
	gameInfo->SetScore(info->Score);
	gameInfo->SetLife(info->Life);
	gameInfo->SetWorld(info->World);
	curWorld->SetGameInfo(gameInfo);

	// info
	curWorld->_IsSubWorld = info->IsSubWorld;
	curWorld->RemoveAllSubWorld();
	curWorld->_nWorld = info->nWorld;
			
	if (info->SubWorld1 != "")
	{
		curWorld->AddSubWorld(
			new GameWorld(
			info->SubWorld1.c_str(),
			TextureManagement::GetInstance()->Get(EOTexture::BACKGROUND_TEXTURE),
			mario,
			gameInfo));
	}
	if (info->SubWorld2 != "")
	{
		curWorld->AddSubWorld(
			new GameWorld(
			info->SubWorld2.c_str(),
			TextureManagement::GetInstance()->Get(EOTexture::BACKGROUND_TEXTURE),
			mario,
			gameInfo));
	}
	curWorld->_CreepUpPos[0] = &info->CreepUpPos1;
	curWorld->_CreepUpPos[1] = &info->CreepUpPos2;
	if (info->TheNextWorld != "")
	{
		curWorld->AddTheNextWorld(
			new GameWorld(
			info->TheNextWorld.c_str(),
			TextureManagement::GetInstance()->Get(EOTexture::BACKGROUND_TEXTURE),
			mario,
			gameInfo));
	}
	curWorld->_oriMarioPos = info->OriMarioPos;

	// list object
	curWorld->_listNodes = &load->GetListQNodes();
	curWorld->_listUpdateNodes = &load->GetUpdateListQNodes();
	curWorld->_listObjects = load->GetListObjects();

	// quadtree
	curWorld->_quadTree = load->GetQuadTree();
	curWorld->_updateQuadTree = load->GetUpdateQuadTree();
}

void LoadState::Cleanup()
{

}

void LoadState::Pause()
{

}

void LoadState::Resume()
{

}


void LoadState::HandleEvents(DXGame *pDXGame)
{
}


void LoadState::Update(GameTime* gameTime)
{
}

void LoadState::Draw(DXGame *pDXGame)
{
	
}