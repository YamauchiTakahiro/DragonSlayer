#pragma once
class TurtleShell : public IGameObject
{
public:
	TurtleShell();
	~TurtleShell();
	void Update();
	void Move();
	void Rotation(); 
	
	void SetPosition(const Vector3& position)
	{
		m_position = position;
	}
	void Render(RenderContext& rc);

	ModelRender m_modelRender;
	CharacterController m_characterController;
	Vector3 m_position;
	Quaternion m_rotation;
};

