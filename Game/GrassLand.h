#pragma once

class Player;

class GrassLand : public IGameObject
{
public:
	GrassLand();
	~GrassLand();
	void Update();
	void Rotation();

	//ï`âÊä÷êîÅB
	void Render(RenderContext& rc);

	void SetPosition(const Vector3& position)
	{
		m_position = position;
	}

	void SetRotation(const Quaternion& rotation)
	{
		m_rotation = rotation;
	}

	ModelRender m_modelRender;
	Vector3 m_position;
	Quaternion m_rotation;
	Player* m_player;
	PhysicsStaticObject m_physicsStaticObject;
};

