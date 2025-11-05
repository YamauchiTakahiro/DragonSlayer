#pragma once

class Player;

class Enemy1 : public IGameObject
{
public:
	Enemy1();
	~Enemy1();
	void Move();
	void Rotate();
	void EnemyState();
	void Render(RenderContext& rc);


	void SetPosition(const Vector3& position)
	{
		m_position = position;
	}

	ModelRender m_modelRender;
	CharacterController m_characterController;
	Vector3 m_position;
	Player* m_player;
};


