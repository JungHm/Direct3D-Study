#pragma once

#define g_Cam cCamera::GetInstance()

class cCamera
{
	SINGLETONE(cCamera);
	SYNTHESIZE(D3DXVECTOR3, m_vCamRotAngle, Angle)
	SYNTHESIZE(D3DXVECTOR3, m_fCameraDistance, Distance)
private:
	D3DXVECTOR3		m_vEye;
	D3DXVECTOR3		m_vLookAt;
	D3DXVECTOR3		m_vUp;

	POINT			m_ptPrevMouse;
	bool			m_isLButtonDown;
	//float			m_fCameraDistance;
	//D3DXVECTOR3		m_vCamRotAngle;

public:
	//cCamera();
	//~cCamera();

	void Init();
	void Update();
	

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void Release();
};

