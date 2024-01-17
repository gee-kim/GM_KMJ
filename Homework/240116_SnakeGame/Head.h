#pragma once
#include "Part.h"

class Head : public Part
{

protected:
	int2 Dir = { 0, 0 };
	//커바디를 파츠로 만들어주
	void Update() override;
};

