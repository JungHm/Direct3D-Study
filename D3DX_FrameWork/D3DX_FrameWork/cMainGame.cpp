#include "stdafx.h"
#include "cMainGame.h"
#include "cDeviceManager.h"


cMainGame::cMainGame() 
{
}


cMainGame::~cMainGame()
{
	g_pDeviceManager->Destroy();
}

void cMainGame::Init()
{
	

}

void cMainGame::Update()
{
}

void cMainGame::Render()
{
	g_pD3DDevice->Clear(NULL, NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(0, 0, 255),
		1.0F, 0);

	g_pD3DDevice->BeginScene();

	//Draw

	g_pD3DDevice->EndScene();
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

void cMainGame::Relase()
{
}
