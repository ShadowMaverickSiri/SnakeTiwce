#include "Food.h"
Food::Food() {
	flag = 1;
}

Food::~Food() {

}

void Food::FoodDraw(POINT coor1, int num1,POINT coor2, int num2) {
	setfillcolor(color);
	fillellipse(coor.x, coor.y, coor.x + size, coor.y + size);
	bool flag_break = true;
	if(flag==0)
	{
		color = GREEN;

		while (flag_break)
		{
			coor.x = rand() % (Window_W / size) * size;
			coor.y = rand() % (Window_H / size) * size;
			flag_break = false;
			for (int i = 0; i < num1; i++)
			{
				if (coor.x == coor1.x && coor.y == coor1.y)
				{
					flag_break = true;
					break;
				}
			}
			for (int i = 0; i < num2; i++)
			{
				if (coor.x == coor2.x && coor.y == coor2.y)
				{
					flag_break = true;
					break;
				}
			}
		}
		flag = 1;
	}

}

void Food::FoodDraw2(POINT coor1, int num1, POINT coor2, int num2) {
	setfillcolor(color);
	fillellipse(coor.x, coor.y, coor.x + size, coor.y + size);
	bool flag_break = true; 
	if (flag == 0)
	{
		color = color = RGB(249, 34, 17);
		while (flag_break)
		{
			coor.x = rand() % (Window_W / size) * size;
			coor.y = rand() % (Window_H / size) * size;
			flag_break = false;
			for (int i = 0; i < num1; i++)
			{
				if (coor.x == coor1.x && coor.y == coor1.y)
				{
					flag_break = true;
					break;
				}
			}
			for (int i = 0; i < num2; i++)
			{
				if (coor.x == coor2.x && coor.y == coor2.y)
				{
					flag_break = true;
					break;
				}
			}
		}
		flag = 1;
	}

}