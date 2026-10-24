#include "Ship.h"

void CShip::Update(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;

	vx += ax * dt;
	vy += ay * dt;

	if (abs(vx) > abs(maxVx)) vx = maxVx;
	if (abs(vy) > abs(maxVy)) vx = maxVy;

	DebugOutTitle(L"vx = %0.5f", this->vx);
	DebugOutTitle(L"vy = %0.5f", this->vy);

	// simple screen edge collision!!!
	if (vx > 0 && x > 290) x = 290;
	if (vx < 0 && x < 0) x = 0;


	// simple screen edge collision!!!
	if (vy > 0 && y > 210) y = 195;
	if (vy < 0 && y < 0) y = 0;
}

void CShip::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;

	// Ship is still on air check, this will not work when Ship is just stand up
	if (vx == 0 && vy == 0)
	{
		aniId = ID_ANI_SHIP_IDLE;
	}
	else {
		if (vx > 0) aniId = ID_ANI_SHIP_RIGHT;
		else aniId = ID_ANI_SHIP_LEFT;

		if (vy < 0) aniId = ID_ANI_SHIP_UP;
		else if(vy > 0) aniId = ID_ANI_SHIP_DOWN;

	}

	if (aniId == -1) aniId = ID_ANI_SHIP_IDLE;

	animations->Get(aniId)->Render(x, y);
}

void CShip::SetState(int state)
{
	switch (state)
	{
	case SHIP_STATE_RIGHT:
		maxVx = SHIP_SPEED_MAX_X;
		ax = SHIP_ACCEL_X;
		nx = 1;
		break;
	case SHIP_STATE_LEFT:
		maxVx = - SHIP_SPEED_MAX_X;
		ax = - SHIP_ACCEL_X;
		nx = - 1;
		break;
	case SHIP_STATE_UP:
		maxVx = - SHIP_SPEED_MAX_Y;
		ay = - SHIP_ACCEL_Y;
		ny = - 1;
		break;
	case SHIP_STATE_DOWN:
		maxVx = SHIP_SPEED_MAX_Y;
		ay = SHIP_ACCEL_Y;
		ny = 1;
		break;

	case SHIP_STATE_IDLE:
		ax = 0.0f;
		vx = 0.0f;
		ay = 0.0f;
		vy = 0.0f;
		break;
	}

	CGameObject::SetState(state);
}

float CShip::GetX()
{
	return x;
}

float CShip::GetY()
{
	return y;
}