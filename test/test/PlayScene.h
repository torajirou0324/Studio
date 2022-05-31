#pragma once
#include <DxLib.h>
#include <vector>

class PlayScene
{
	struct BackGround
	{
		int BackGroundImg;
		int x;
		int y;
		int num;
	};

	struct Player
	{
		int playerImg;
		int x;
		int y;
	};

	std::vector<BackGround> backImg;
	Player player;
public:
	PlayScene();
	~PlayScene();

	void Update();
	void Draw();
};