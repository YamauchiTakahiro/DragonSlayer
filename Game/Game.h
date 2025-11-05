#pragma once

#include "Level3DRender/LevelRender.h"

class Player;
class BackGround;
class GameCamera;
class GrassLand;
class Castle;

class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();

	Player* m_player;
	BackGround* m_backGround;
	GameCamera* m_gameCamera;
	GrassLand* m_grassLand;
	Castle* m_castle;
	LevelRender m_levelRender;
};

