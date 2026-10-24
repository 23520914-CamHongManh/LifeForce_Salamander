#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"

#define TANK_WALKING_SPEED		0.1f
#define TANK_RUNNING_SPEED		0.2f

#define TANK_ACCEL_WALK_X	0.0005f
#define TANK_ACCEL_RUN_X	0.0007f

#define TANK_JUMP_SPEED_Y		0.5f
#define TANK_JUMP_RUN_SPEED_Y	0.6f

#define TANK_GRAVITY			0.002f

#define TANK_STATE_IDLE			0
#define TANK_STATE_WALKING_RIGHT	100
#define TANK_STATE_WALKING_LEFT	200
#define TANK_STATE_WALKING_UP	101
#define TANK_STATE_WALKING_DOWN	201


#define TANK_STATE_JUMP			300
#define TANK_STATE_RELEASE_JUMP    301

#define TANK_STATE_RUNNING_RIGHT	400
#define TANK_STATE_RUNNING_LEFT	500

#define TANK_STATE_SIT				600
#define TANK_STATE_SIT_RELEASE		601


#pragma region ANIMATION_ID

#define ID_ANI_TANK_IDLE_RIGHT 400
#define ID_ANI_TANK_IDLE_LEFT 401

#define ID_ANI_TANK_WALKING_RIGHT 500
#define ID_ANI_TANK_WALKING_LEFT 501
#define ID_ANI_TANK_WALKING_UP 502
#define ID_ANI_TANK_WALKING_DOWN 503

#define ID_ANI_TANK_RUNNING_RIGHT 600
#define ID_ANI_TANK_RUNNING_LEFT 601

#define ID_ANI_TANK_JUMP_WALK_RIGHT 700
#define ID_ANI_TANK_JUMP_WALK_LEFT 701

#define ID_ANI_TANK_JUMP_RUN_RIGHT 800
#define ID_ANI_TANK_JUMP_RUN_LEFT 801

#define ID_ANI_TANK_SIT_RIGHT 900
#define ID_ANI_TANK_SIT_LEFT 901

#define ID_ANI_TANK_BRACE_RIGHT 1000
#define ID_ANI_TANK_BRACE_LEFT 1001

#pragma endregion




#define GROUND_Y 160.0f

#define TANK_SIT_HEIGHT_ADJUST 4.0f

class CTank : public CGameObject
{
	BOOLEAN isSitting;
	float maxVx;
	float ax;				// acceleration on x 
	float maxVy;
	float ay;
public:
	CTank(float x, float y) : CGameObject(x, y)
	{
		isSitting = false;
		maxVx = 0.0f;
		ax = 0.0f;
		maxVy = 0.0f;
		ay = 0.0f;
	}
	void Update(DWORD dt);
	void Render();
	void SetState(int state);
};
