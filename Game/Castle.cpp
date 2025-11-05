#include "stdafx.h"
#include "Castle.h"
#include "Player.h"

Castle::Castle()
{
	m_modelRender.Init("Assets/modelData/Stage/castle.tkm");

	m_player = FindGO<Player>("player");

	//m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
}

Castle::~Castle()
{

}

void Castle::Update()
{
	Vector3 diff = m_position - m_player->m_position;

	if (diff.Length() <= 70.0f)
	{
		/*m_player->m_CastleMoveFlag = true;
		m_player->m_clearFlag = true;*/
	}
	else
	{
		//m_player->m_CastleMoveFlag = false;
	}
}

void Castle::Rotation()
{
	m_rotation.AddRotationDegY(2.0f);

	m_modelRender.SetRotation(m_rotation);
}

void Castle::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}