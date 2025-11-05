#pragma once

class Player : public IGameObject
{
public:
	Player();
	~Player();
	void Update();
	void Move();
	void Rotation();
	void PlayerState();
	void PlayAnimation();
	void OnCollision();
	void Hit();
	void Render(RenderContext& rc);

	//メンバ変数
	ModelRender m_modelRender;
	Vector3 m_position;
	enum EnAnimationClip {		//アニメーション。
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Run,
		enAnimationClip_Num,
	};
	AnimationClip m_animationClips[enAnimationClip_Num];
	CharacterController m_characterController;
	Vector3 m_moveSpeed;
	int m_doubleJump;
	Quaternion m_rotation;
	int m_playerState = 0;
	int m_clearFlag = false;
	int m_GrassLandMoveFlag = false;
	int m_CastleMoveFlag = false;
	nsK2Engine::CollisionObject* m_collisionObject;
};