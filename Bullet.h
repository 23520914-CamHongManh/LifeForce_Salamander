#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_BULLET 10000
#define BULLET_SPEED	0.2f

class CBullet : public CGameObject {
	float vx;
public:
	CBullet(float x, float y) : CGameObject(x, y) {
		vx = BULLET_SPEED;
	}
	void Render();
	void Update(DWORD dt);
};