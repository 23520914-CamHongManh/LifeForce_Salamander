#include "ShipKeyHandler.h"
#include "GameObject.h"

#include "debug.h"
#include "Game.h"

#include "Ship.h"
#include "Bullet.h"

extern CShip* ship;
extern vector<LPGAMEOBJECT> objects;


void CShipKeyHandler::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_S:
		CBullet* bullet = new CBullet(ship->GetX() + 16, ship->GetY());
		objects.push_back(bullet);
		break;
	}
}

void CShipKeyHandler::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
}


void CShipKeyHandler::KeyState(BYTE* states)
{
	CGame* game = CGame::GetInstance();

	if (game->IsKeyDown(DIK_RIGHT))
	{
			ship->SetState(SHIP_STATE_RIGHT);
	}
	else if (game->IsKeyDown(DIK_LEFT))
	{
			ship->SetState(SHIP_STATE_LEFT);
	}
	else if (game->IsKeyDown(DIK_UP))
	{
		ship->SetState(SHIP_STATE_UP);
	}
	else if (game->IsKeyDown(DIK_DOWN))
	{
		ship->SetState(SHIP_STATE_DOWN);
	}
	else
		ship->SetState(SHIP_STATE_IDLE);

}