#include "PlayScene.h"

PlayScene::PlayScene()
{
	Object BG;
	BG.Img = LoadGraph("data/BackGround.png");
	BG.x = 0, BG.y = 0;
	backImg.push_back(BG);
	BG.x = 1920, BG.y = 0;
	backImg.push_back(BG);

	BG.Img = LoadGraph("data/monokuro_bullet.png");
	BG.x = 1920, BG.y = 120;
	bullet.push_back(BG);
	BG.Img = LoadGraph("data/yellow_bullet.png");
	BG.x = 2420, BG.y = 620;
	bullet.push_back(BG);

	player.Img = LoadGraph("data/zoro.png");
	player.x = 320, player.y = 660;
	m_jampFlag = false;
	m_velocity = 0;
	m_mileage = 0;
}

PlayScene::~PlayScene()
{
	backImg.clear();
	bullet.clear();
}

void PlayScene::Update()
{
	for (int i = 0; i < backImg.size(); i++)
	{
		backImg[i].x -= 2;
		if (backImg[i].x < -1919)
		{
			backImg[i].x = 1920;
		}

		bullet[i].x -= 5;
		if (bullet[i].x < -200)
		{
			bullet[i].x = 1920;
		}
	}

	if (CheckHitKey(KEY_INPUT_SPACE) && !m_jampFlag)
	{
		m_velocity = -20.0f;
		m_jampFlag = true;
	}
	player.y += m_velocity;
	m_velocity += 0.4f;

	if (player.y > 660)
	{
		m_jampFlag = false;
		player.y = 660;
	}

	// ëñçsãóó£ëùâ¡
	m_mileage += 0.032f;
}

void PlayScene::Draw()
{
	DrawGraph(backImg[0].x, backImg[0].y, backImg[0].Img, FALSE);
	DrawGraph(backImg[1].x, backImg[1].y, backImg[1].Img, FALSE);

	
	SetFontSize(62);
	DrawFormatString(0, 0, GetColor(0, 0, 0), "ÉåÉxÉã%d");
	DrawFormatString(0, 1000, GetColor(255, 255, 255), "%.3f M", m_mileage);
	SetFontSize(48);
	DrawFormatString(20, 64, GetColor(255, 255, 255), "HP");
	DrawBox(20, 112, 255, 142, GetColor(0, 255, 0), TRUE);

	DrawGraph(player.x, player.y, player.Img, TRUE);
	DrawGraph(bullet[0].x, bullet[0].y, bullet[0].Img, TRUE);
	DrawGraph(bullet[1].x, bullet[1].y, bullet[1].Img, TRUE);
}
