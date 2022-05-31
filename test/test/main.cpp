#include <DxLib.h>
#include "PlayScene.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// DxLib�̏�����
	if (DxLib_Init() == -1)return -1;

	// ��ʃ��[�h�̐ݒ�
	SetGraphMode(1920, 1080, 16);

	// �`���𗠉�ʂɃZ�b�g
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