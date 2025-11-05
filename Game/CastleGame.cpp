#include "stdafx.h"
#include "CastleGame.h"
#include "CastleStage.h"

CastleGame::CastleGame()
{
	m_levelRender.Init("Assets/modelData/Castle/castlestage.tkl", [&](LevelObjectData& objData)
		{
			if (objData.EqualObjectName(L"castle") == true)
			{
				m_castleStage = NewGO<CastleStage>(0, "castle");

				m_castleStage->SetPosition(objData.position);
				return true;
			}
		});
}

CastleGame::~CastleGame()
{

}

void CastleGame::Update()
{

}

void CastleGame::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}