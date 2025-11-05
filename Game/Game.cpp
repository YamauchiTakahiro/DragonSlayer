#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "BackGround.h"
#include "GameCamera.h"
#include "GrassLand.h"
#include "Castle.h"
#include "GrassLandGame.h"
#include "CastleGame.h"

Game::Game()
{
	m_player = NewGO<Player>(0, "player");
	m_gameCamera = NewGO<GameCamera>(0, "gameCamera");

	m_levelRender.Init("Assets/modelData/Stage/stage.tkl", [&](LevelObjectData& objData)
		{
			if (objData.EqualObjectName(L"stage") == true)
			{
				m_backGround = NewGO<BackGround>(0, "backGround");

				m_backGround->SetPosition(objData.position);
				return true;
			}
			else if (objData.EqualObjectName(L"GrassLand") == true)
			{
				m_grassLand = NewGO<GrassLand>(0, "grassLand");

				m_grassLand->SetPosition(objData.position);

				m_grassLand->SetRotation(objData.rotation);
				return true;
			}
			else if (objData.EqualObjectName(L"castle") == true)
			{
				m_castle = NewGO<Castle>(0, "castle");

				m_castle->SetPosition(objData.position);

				//5m_castle->SetRotation(objData.rotation);
				return true;
			}
		});
}

Game::~Game()
{
	
}

void Game::Update()
{
	if (m_player->m_GrassLandMoveFlag == true)
	{
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			m_player->m_GrassLandMoveFlag = false;
			NewGO<GrassLandGame>(0, "grassLandGame");
			DeleteGO(m_backGround);

			DeleteGO(m_castle);

			DeleteGO(m_grassLand);
		}
	}

	if (m_player->m_CastleMoveFlag == true && m_player->m_clearFlag == true)
	{
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			m_player->m_CastleMoveFlag = false;
			NewGO<CastleGame>(0, "castleGame");
			DeleteGO(m_backGround);

			DeleteGO(m_castle);

			DeleteGO(m_grassLand);
		}
	}

	 g_renderingEngine->DisableRaytracing();
}