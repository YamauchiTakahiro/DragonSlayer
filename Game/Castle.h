#pragma once

class Player;

class Castle : public IGameObject
{
public:
	Castle();
	~Castle();
	void Update();
	void Rotation();
	void Render(RenderContext& rc);

	void SetPosition(const Vector3& position)
	{
		m_position = position;
	}

	/*void SetRotation(const Quaternion& rotation)
	{
		m_rotation = rotation;
	}*/

	ModelRender m_modelRender;
	Vector3 m_position;
	Quaternion m_rotation;
	Player* m_player;
	PhysicsStaticObject m_physicsStaticObject;
};

