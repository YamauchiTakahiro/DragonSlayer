#include "stdafx.h"
#include "CastleStage.h"

CastleStage::CastleStage()
{
	m_modelRender.Init("Assets/modelData/Castle/castle.tkm");
	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());

}

CastleStage::~CastleStage()
{

}

void CastleStage::Update()
{

}

void CastleStage::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}

