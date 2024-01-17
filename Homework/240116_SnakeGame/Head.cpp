#include "Head.h"
#include <conio.h>
#include <ConsoleEngine/EngineCore.h>
#include "BodyManager.h"
#include "Body.h"

// 
// 1. ���� Ư�� �������� �����ߴٸ� ���� �Է¶��� �� �ݴ�������δ� ������ ����.
//    ���� �̵��ϴ� ������ �ݴ�������δ� ���� �ȵȴ�.
// 2. ���� �̵��� �ؼ� CurBody�� ȹ���ߴٸ� �� �������� �� �ٵ�� ���� ����;� �Ѵ�.

void Head::Update()
{
	int InputCount = _kbhit();
	if (0 == InputCount)
	{
		return;
	}

	int Select = _getch();

	// InputCount = _kbhit();

	// X Y
	// 1 0

	int2 PrevPos = this->GetPos();

	switch (Select)
	{
	case 'A':
	case 'a':
		if (Dir != Right)
		{
			Dir = Left;
			AddPos(Dir);
		}
		break;
	case 'S':
	case 's':
		if (Dir != Up)
		{
			Dir = Down;
			AddPos(Dir);
		}
		break;
	case 'W':
	case 'w':
		if (Dir != Down)
		{
			Dir = Up;
			AddPos(Dir);
		}
		break;
	case 'D':
	case 'd':
		if (Dir != Left)
		{
			Dir = Right;
			AddPos(Dir);
		}
		break;
	case '1':
		GetCore()->EngineEnd();
		break;
	default:
		break;
	}

	int2 MovePos = this->GetPos();
	PrevPos;
	if (nullptr == BodyManager::GetCurBody())
	{
		MsgBoxAssert("������ �ִ� �ٵ� �������� �ʽ��ϴ�.");
		return;
	}

	int a = 10;

	Body* CurBody = BodyManager::GetCurBody();

	if (CurBody->GetPos() == GetPos())
	{
		this;
		this->Back = CurBody;
		CurBody->SetPos(PrevPos);
		BodyManager::ResetBody();

		//head->back->back->back->

	}

	if (nullptr != Back)
	{
		Back->SetPos(PrevPos);
	}
	

}