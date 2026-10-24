#include "Bullet.h"

void CBullet::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_BULLET)->Render(x, y);
}

void CBullet::Update(DWORD dt)
{
	x += vx * dt;
}