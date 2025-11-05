#include "stdafx.h"
#include "GrassLand.h"
#include "Player.h"

GrassLand::GrassLand()
{
	m_modelRender.Init("Assets/modelData/Stage/GrassLand.tkm");

	//m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());

	m_player = FindGO<Player>("player");
}

GrassLand::~GrassLand()
{

}

void GrassLand::Update()
{
	Vector3 diff = m_position - m_player->m_position;

	if (diff.Length() <= 70.0f)
	{
		m_player->m_GrassLandMoveFlag = true;
	}
	else
	{
		m_player->m_GrassLandMoveFlag = false;
	}
}

void GrassLand::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}