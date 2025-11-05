#pragma once
class GrassLandStage : public IGameObject
{
public:
	GrassLandStage();
	~GrassLandStage();
	void Update();

	//ï`âÊä÷êîÅB
	void Render(RenderContext& rc);

	void SetPosition(const Vector3& position)
	{
		m_position = position;
	}

	ModelRender m_modelRender;
	Vector3 m_position;
	PhysicsStaticObject m_physicsStaticObject;
};
