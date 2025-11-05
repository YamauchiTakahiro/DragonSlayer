#include "stdafx.h"
#include "GrassLandStage.h"

GrassLandStage::GrassLandStage()
{
	m_modelRender.Init("Assets/modelData/GrassLand/GrassLandStage.tkm");
	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());

}

GrassLandStage::~GrassLandStage()
{

}

void GrassLandStage::Update()
{

}

void GrassLandStage::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}

