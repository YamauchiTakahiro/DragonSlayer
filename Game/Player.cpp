#include "stdafx.h"
#include "Player.h"
#include "collision/CollisionObject.h"

Player::Player()
{
	m_animationClips[enAnimationClip_Idle].Load("Assets/animData/Player/idle.tka");
	m_animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	m_animationClips[enAnimationClip_Walk].Load("Assets/animData/Player/walk.tka");
	m_animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	m_animationClips[enAnimationClip_Jump].Load("Assets/animData/Player/jump.tka");
	m_animationClips[enAnimationClip_Jump].SetLoopFlag(false);
	m_animationClips[enAnimationClip_Run].Load("Assets/animData/Player/run.tka");
	m_animationClips[enAnimationClip_Run].SetLoopFlag(true);
	//モデルを初期化する。
	m_modelRender.Init("Assets/modelData/unityChan.tkm", m_animationClips, enAnimationClip_Num, enModelUpAxisY);
	m_characterController.Init(25.0f, 75.0f, m_position);
}

Player::~Player()
{

}

void Player::Update()
{
	Move();

	Rotation();

	PlayerState();

	PlayAnimation();

	//モデルを更新する。
	m_modelRender.Update();
}

void Player::Move()
{
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;

	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();

	forward.y = 0.0f;
	right.y = 0.0f;

	if (g_pad[0]->IsPress(enButtonY) == false)
	{
		right *= stickL.x * 120.0f;
		forward *= stickL.y * 120.0f;
	}

	if (g_pad[0]->IsPress(enButtonY))
	{
		right *= stickL.x * 240.0f;
		forward *= stickL.y * 240.0f;
	}

	m_moveSpeed += right + forward;

	//二段ジャンプ
	if (m_characterController.IsOnGround())
	{
		m_moveSpeed.y = 0.0f;
		m_doubleJump = false;
		if (g_pad[0]->IsTrigger(enButtonB))
		{
			m_moveSpeed.y = 240.0f;
		}
		else if (g_pad[0]->IsTrigger(enButtonA))
		{
			if (m_GrassLandMoveFlag == false && m_CastleMoveFlag == false)
			{
				m_moveSpeed.y = 240.0f;
			}
		}
	}
	if (m_characterController.IsOnGround() == false && m_doubleJump == false)
	{
		if (g_pad[0]->IsTrigger(enButtonB))
		{
			m_moveSpeed.y = 240.0f;
			m_doubleJump = true;
		}
		else if (g_pad[0]->IsTrigger(enButtonA))
		{
			if (m_GrassLandMoveFlag == false && m_CastleMoveFlag == false)
			{
				m_moveSpeed.y = 240.0f;
				m_doubleJump = true;
			}
		}

	}
	if (m_characterController.IsOnGround() == false)
	{
		m_moveSpeed.y -= 7.0f;
	}

	if(m_characterController.IsOnGround() == false)
	{
		OnCollision();
	}

	m_position = m_characterController.Execute(m_moveSpeed, 2.0f / 60.0f);

	m_modelRender.SetPosition(m_position);
}

void Player::Rotation()
{
	if (fabsf(m_moveSpeed.x) >= 0.001f || fabsf(m_moveSpeed.z) >= 0.001f)
	{
		m_rotation.SetRotationYFromDirectionXZ(m_moveSpeed);

		m_modelRender.SetRotation(m_rotation);
	}
}

void Player::PlayerState()
{
	if (m_characterController.IsOnGround() == false)
	{
		m_playerState = 1;

		return;
	}

	if (fabsf(m_moveSpeed.x) >= 0.001f || fabsf(m_moveSpeed.z) >= 0.001f)
	{
		m_playerState = 2;
		if (g_pad[0]->IsPress(enButtonY))
		{
			m_playerState = 3;
		}
	}

	else
	{
		m_playerState = 0;
	}
}

void Player::PlayAnimation()
{
	switch (m_playerState)
	{
	case 0:
		m_modelRender.PlayAnimation(enAnimationClip_Idle);
		break;
	case 1:
		m_modelRender.PlayAnimation(enAnimationClip_Jump);
		break;
	case 2:
		m_modelRender.PlayAnimation(enAnimationClip_Walk);
		break;
	case 3:
		m_modelRender.PlayAnimation(enAnimationClip_Run);
		break;
	}
}

void Player::Render(RenderContext& rc)
{
	//モデルを表示する。
	m_modelRender.Draw(rc);
}

void Player::OnCollision()
{
	nsK2Engine::CollisionObject* collisionObject = NewGO<nsK2Engine::CollisionObject>(0);
	Vector3 collisionPosition = m_position;

	collisionObject->CreateSphere(collisionPosition, Quaternion::Identity, 20.0f);
	collisionObject->SetName("Player");
}

void Player::Hit()
{

}