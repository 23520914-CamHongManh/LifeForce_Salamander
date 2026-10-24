#include "Tank.h"

void CTank::Update(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;

	//// simple fall down
	//vy += Tank_GRAVITY * dt;

	vx += ax * dt;
	vy += ay * dt;

	if (abs(vx) > abs(maxVx)) vx = maxVx;
	if (abs(vy) > abs(maxVy)) vx = maxVy;

	DebugOutTitle(L"vx = %0.5f", this->vx);
	DebugOutTitle(L"vy = %0.5f", this->vy);

	//// BAD & sinful platform collision handling, see next sample for correct collision handling
	//if (y > GROUND_Y)
	//{
	//	vy = 0; y = GROUND_Y;
	//}

	// simple screen edge collision!!!
	if (vx > 0 && x > 290) x = 290;
	if (vx < 0 && x < 0) x = 0;


	// simple screen edge collision!!!
	if (vy > 0 && y > 210) x = 210;
	if (vy < 0 && y < 0) x = 0;
}

void CTank::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;

	// Tank is still on air check, this will not work when Tank is just stand up
	if (y < GROUND_Y)
	{
		if (abs(ax) == Tank_ACCEL_RUN_X) // TODO: need to optimize this
		{
			if (nx >= 0)
				aniId = ID_ANI_Tank_JUMP_RUN_RIGHT;
			else
				aniId = ID_ANI_Tank_JUMP_RUN_LEFT;
		}
		else
		{
			if (nx >= 0)
				aniId = ID_ANI_Tank_JUMP_WALK_RIGHT;
			else
				aniId = ID_ANI_Tank_JUMP_WALK_LEFT;
		}
	}
	else
		if (isSitting)
		{
			if (nx > 0)
				aniId = ID_ANI_Tank_SIT_RIGHT;
			else
				aniId = ID_ANI_Tank_SIT_LEFT;
		}
		else
			if (vx == 0)
			{
				if (nx > 0) aniId = ID_ANI_Tank_IDLE_RIGHT;
				else aniId = ID_ANI_Tank_IDLE_LEFT;
			}
			else if (vx > 0)
			{
				if (ax < 0)
					aniId = ID_ANI_Tank_BRACE_RIGHT;
				else if (ax == Tank_ACCEL_RUN_X)
					aniId = ID_ANI_Tank_RUNNING_RIGHT;
				else if (ax == Tank_ACCEL_WALK_X)
					aniId = ID_ANI_Tank_WALKING_RIGHT;
			}
			else // vx < 0
			{
				if (ax > 0)
					aniId = ID_ANI_Tank_BRACE_LEFT;
				else if (ax == -Tank_ACCEL_RUN_X)
					aniId = ID_ANI_Tank_RUNNING_LEFT;
				else if (ax == -Tank_ACCEL_WALK_X)
					aniId = ID_ANI_Tank_WALKING_LEFT;
			}

	if (aniId == -1) aniId = ID_ANI_Tank_IDLE_RIGHT;

	float d = 0;
	if (isSitting) d = Tank_SIT_HEIGHT_ADJUST;

	animations->Get(aniId)->Render(x, y + d);
}

void CTank::SetState(int state)
{
	switch (state)
	{
	case Tank_STATE_RUNNING_RIGHT:
		if (isSitting) break;
		maxVx = Tank_RUNNING_SPEED;
		ax = Tank_ACCEL_RUN_X;
		nx = 1;
		break;
	case Tank_STATE_RUNNING_LEFT:
		if (isSitting) break;
		maxVx = -Tank_RUNNING_SPEED;
		ax = -Tank_ACCEL_RUN_X;
		nx = -1;
		break;
	case Tank_STATE_WALKING_RIGHT:
		if (isSitting) break;
		maxVx = Tank_WALKING_SPEED;
		ax = Tank_ACCEL_WALK_X;
		nx = 1;
		break;
	case Tank_STATE_WALKING_LEFT:
		if (isSitting) break;
		maxVx = -Tank_WALKING_SPEED;
		ax = -Tank_ACCEL_WALK_X;
		nx = -1;
		break;
	case Tank_STATE_JUMP:
		if (isSitting) break;
		if (y == GROUND_Y)
		{
			if (abs(this->vx) == Tank_RUNNING_SPEED)
				vy = -Tank_JUMP_RUN_SPEED_Y;
			else
				vy = -Tank_JUMP_SPEED_Y;
		}
		break;

	case Tank_STATE_RELEASE_JUMP:
		if (vy < 0) vy += Tank_JUMP_SPEED_Y / 2;
		break;

	case Tank_STATE_SIT:
		if (y == GROUND_Y)
		{
			state = Tank_STATE_IDLE;
			isSitting = true;
			vx = 0; vy = 0;
			//y += Tank_SIT_HEIGHT_ADJUST;
		}
		break;

	case Tank_STATE_SIT_RELEASE:
		isSitting = false;
		state = Tank_STATE_IDLE;
		//y -= Tank_SIT_HEIGHT_ADJUST;
		break;

	case Tank_STATE_IDLE:
		ax = 0.0f;
		vx = 0.0f;
		break;
	}

	CGameObject::SetState(state);
}

