#include "PlayScene.h"

PlayScene::PlayScene()
{
	backImg[0].BackGroundImg = LoadGraph("data/BackGround.png");
	backImg[0].x = 0, backImg[0].y = 0, backImg[0].num = 0;

	backImg[1].BackGroundImg = LoadGraph("data/BackGround.png");
	backImg[1].x = 1280, backImg[1].y = 0; backImg[1].num = 0;
	player.playerImg = LoadGraph("data/zoro.png");
	player.x = 0, player.y = 0;
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{

}

void PlayScene::Draw()
{
	DrawGraph(backImg[0].x, backImg[0].y, backImg[0].BackGroundImg, FALSE);
	DrawGraph(player.x, player.y, player.playerImg, FALSE);
}
