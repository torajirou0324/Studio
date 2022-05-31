#include <DxLib.h>
#include "PlayScene.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// DxLibの初期化
	if (DxLib_Init() == -1)return -1;

	// 画面モードの設定
	SetGraphMode(1920, 1080, 16);

	// 描画先を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);

	bool GameState = true;
	PlayScene* playScene = new PlayScene();

	while (GameState)
	{
		ClearDrawScreen();

		playScene->Update();

		playScene->Draw();

		ScreenFlip();

		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}

	delete playScene;

	return 0;
}