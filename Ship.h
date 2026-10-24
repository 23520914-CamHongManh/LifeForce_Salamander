#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"

#define SHIP_SPEED_X		0.1f
#define SHIP_SPEED_MAX_X		0.2f

#define SHIP_ACCEL_X	0.0005f
#define SHIP_ACCEL_Y	0.0005f

#define SHIP_SPEED_Y		0.1f
#define SHIP_SPEED_MAX_Y		0.2f


#define SHIP_STATE_IDLE			0
#define SHIP_STATE_UP	100
#define SHIP_STATE_DOWN	200

#define SHIP_STATE_RIGHT		300
#define SHIP_STATE_LEFT    301


#pragma region ANIMATION_ID

#define ID_ANI_SHIP_IDLE 400

#define ID_ANI_SHIP_UP 500
#define ID_ANI_SHIP_DOWN 501

#define ID_ANI_SHIP_RIGHT 600
#define ID_ANI_SHIP_LEFT 601

#pragma endregion

class CShip : public CGameObject
{
	float maxVx;
	float ax;				// acceleration on x 
	float maxVy;
	float ay;				// acceleration on y 
public:
	CShip(float x, float y) : CGameObject(x, y)
	{
		maxVx = 0.0f;
		ax = 0.0f;
		maxVy = 0.0f;
		ay = 0.0f;
	}
	void Update(DWORD dt);
	void Render();
	void SetState(int state);
	float GetX();
	float GetY();
};