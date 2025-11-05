#pragma once

class Player;
class Enemy1;
class GameCamera;
class CastleStage;

class CastleGame : public IGameObject
{
public:
	CastleGame();
	~CastleGame();
	void Update();
	void Render(RenderContext& rc);

	Player* m_player;
	Enemy1* m_enemy1;
	GameCamera* m_gameCamera;
	CastleStage* m_castleStage;
	ModelRender m_modelRender;
	LevelRender m_levelRender;
};

