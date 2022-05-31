#pragma once
#include <DxLib.h>
#include <vector>

class PlayScene
{
	struct Object
	{
		int Img;
		float x;
		float y;
	};

	std::vector<Object> backImg;
	Object player;
	std::vector< Object> bullet;
	bool m_jampFlag;
	float m_velocity;
	float m_mileage;
public:
	PlayScene();
	~PlayScene();

	void Update();
	void Draw();
};