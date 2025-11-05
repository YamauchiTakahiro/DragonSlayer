#pragma once

#include "Level3DRender/LevelRender.h"

class Player;
class Enemy1;
class GameCamera;
class GrassLandStage;
class TurtleShell;

class GrassLandGame : public IGameObject
{
public:
	//ƒƒ“ƒoŠÖ”
	GrassLandGame();
	~GrassLandGame();
	void Update();

	//ƒƒ“ƒo•Ï”
	Player* m_player;
	Enemy1* m_enemy1;
	GameCamera* m_gameCamera;
	GrassLandStage* m_grassLandStage;
	TurtleShell* m_turtleShell;
	LevelRender m_levelRender;
};


