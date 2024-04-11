#pragma once
#include"headfile.h"
class Food
{
public:
	Food(void);
	~Food(void);

	POINT coor;
	DWORD color;
	int flag;
	int size;//食物大小

	void FoodDraw(POINT coor1, int num1, POINT coor2, int num2);
	void FoodDraw2(POINT coor1, int num1, POINT coor2, int num2);
private:

protected:

};

