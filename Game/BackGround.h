#pragma once
class BackGround : public IGameObject
{
public:
	BackGround();
	~BackGround();
	void Update();

	//ï`âÊä÷êîÅB
	void Render(RenderContext& rc);

	void SetPosition(const Vector3& position)
	{
		m_position = position;
	}

	ModelRender m_modelRender;
	PhysicsStaticObject m_physicsStaticObject;
	Vector3 m_position;
};

