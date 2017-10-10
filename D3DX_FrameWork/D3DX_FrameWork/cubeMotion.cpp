#include "stdafx.h"
#include "cCubeMake.h"

//////////////////////////////////////////////
//	CUBE HUMAN MOTION
//////////////////////////////////////////////
void cCubeMake::IdleMotion()
{
	//D3DXMatrixIdentity(&matR);
}

void cCubeMake::MoveMotion()
{
	//D3DXMatrixIdentity(&matR);
	//D3DXMatrixIdentity(&matMoveT);
	//D3DXMatrixIdentity(&matOriginT);
}

void cCubeMake::PushMotion()
{
	MoveMotion();
}

void cCubeMake::WinMotion()
{
	//D3DXMatrixIdentity(&matR);
	//D3DXMatrixIdentity(&matMoveT);
	//D3DXMatrixIdentity(&matOriginT);
}


//////////////////////////////////////////////
//	CUBE HAND MOTION
//////////////////////////////////////////////
void cCubeMake::GrabMotion()
{
	ThumbGMotion(); IndexGMotion(); MidGMotion();
			RingGMotion(); LilGMotion();
}

void cCubeMake::HelloMotion()
{
}

void cCubeMake::ScissorG()
{
	MidGMotion();
	RingGMotion(); LilGMotion();
}


void cCubeMake::FanMotion()
{
}



void cCubeMake::ThumbGMotion()
{
}

void cCubeMake::IndexGMotion()
{
}

void cCubeMake::MidGMotion()
{
}

void cCubeMake::RingGMotion()
{
}

void cCubeMake::LilGMotion()
{
}






//////////////////////////////////////////////
//	CUBE COMMONS
//////////////////////////////////////////////
bool cCubeMake::Recover()
{
	/*D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matMoveT);
	D3DXMatrixIdentity(&matOriginT);*/
	return true;
}

