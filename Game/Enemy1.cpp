#include "stdafx.h"
#include "Enemy1.h"
#include "Player.h"

Enemy1::Enemy1()
{
	m_modelRender.Init("Assets/modelData/GrassLand/Enemy.tkm");
	m_characterController.Init(45.0f, 75.0f, m_position);
}

Enemy1::~Enemy1()
{

}

void Enemy1::Move()
{

}

void Enemy1::Rotate()
{

}

void Enemy1::EnemyState()
{

}

void Enemy1::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}