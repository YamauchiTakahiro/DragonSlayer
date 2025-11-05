#include "stdafx.h"
#include "TurtleShell.h"
#include "Player.h"

TurtleShell::TurtleShell()
{
	m_modelRender.Init("Assets/modelData/GrassLand/TurtleShell.tkm");
	m_characterController.Init(45.0f, 75.0f, m_position);
}

TurtleShell::~TurtleShell()
{

}

void TurtleShell::Update()
{

}

void TurtleShell::Move()
{

}

void TurtleShell::Rotation()
{

}

void TurtleShell::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}
