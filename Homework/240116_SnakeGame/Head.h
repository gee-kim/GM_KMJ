#pragma once
#include "Part.h"

class Head : public Part
{

protected:
	int2 Dir = { 0, 0 };
	//Ŀ�ٵ� ������ �������
	void Update() override;
};

