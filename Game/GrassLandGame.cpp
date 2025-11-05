#include "stdafx.h"
#include "GrassLandGame.h"
#include "Player.h"
#include "Enemy1.h"
#include "GameCamera.h"
#include "GrassLandStage.h"
#include "TurtleShell.h"

GrassLandGame::GrassLandGame()
{
	m_levelRender.Init("Assets/modelData/GrassLand/GrassLandStage.tkl", [&](LevelObjectData& objData)
		{
			if (objData.EqualObjectName(L"GrassLand") == true)
			{
				m_grassLandStage = NewGO<GrassLandStage>(0, "grassLandStage");

				m_grassLandStage->SetPosition(objData.position);
				return true;
			}
			if (objData.EqualObjectName(L"Enemy") == true)
			{
				m_enemy1 = NewGO<Enemy1>(0, "enemy1");

				m_enemy1->SetPosition(objData.position);

				return true;
			}if (objData.EqualObjectName(L"TurtleShell") == true)
			{
				m_turtleShell = NewGO<TurtleShell>(0, "TurtleShell");

				m_turtleShell->SetPosition(objData.position);
			}
		});
}

GrassLandGame::~GrassLandGame()
{

}

void GrassLandGame::Update()
{

}