#include "Snake.h"

Snake::Snake() {


}

//通过构造函数初始化蛇
//Snake::Snake(int length, int x, int y) {
//	 num= length;
//	 coor[0].x = x;
//	 coor[0].y = x;
//
//}

Snake::~Snake() {

}



void Snake::SnakeDraw() {
	for (int i = 0; i < num; i++)
	{
		setlinecolor(BLACK);
		setfillcolor(GREEN);
		fillrectangle(coor[i].x, coor[i].y, coor[i].x + size, coor[i].y + size);
	   // std::cout << coor[i].x << " " << coor[i].y << std::endl;
	}
}

void Snake::SnakeDraw2()
{
	for (int i = 0; i < num; i++)
	{
		setlinecolor(BLACK);
		setfillcolor(RGB(249, 34, 17));
		fillrectangle(coor[i].x, coor[i].y, coor[i].x + size, coor[i].y + size);
		// std::cout << coor[i].x << " " << coor[i].y << std::endl;
	}

}

void Snake::SnakeMove() {
	for (int i = num - 1; i > 0; i--)
	{
		coor[i].x = coor[i-1].x;
		coor[i].y = coor[i-1].y; 
	}
	switch (dir)
	{
	case UP:
		coor[0].y -= size;
		if(coor[0].y<0)
		{
			coor[0].y = Window_H-size;
		}
		break;
	case DOWN:
		coor[0].y += size;
		if (coor[0].y >= Window_H)
		{
			coor[0].y = 0;
		}
		break;
	case LEFT:
		coor[0].x -= size;
		if (coor[0].x < 0)
		{
			coor[0].x = Window_W-size;
		}
		break;
	case RIGHT:
		coor[0].x += size;
		if (coor[0].x  >= Window_W)
		{
			coor[0].x = 0;
		}
		break;


	default:
		break;
	}
}

void Snake::SnakeMove2(){
	for (int i = num - 1; i > 0; i--)
	{
		coor[i].x = coor[i - 1].x;
		coor[i].y = coor[i - 1].y;
	}
	switch (dir)
	{
	case UP:
		coor[0].y -= size;
		break;
	case DOWN:
		coor[0].y += size;
		break;
	case LEFT:
		coor[0].x -= size;
		break;
	case RIGHT:
		coor[0].x += size;
		break;
	default:
		break;
	}
}

void Snake::KeyControl()
{
	//if (GetAsyncKeyState(VK_UP)&&dir!=DOWN)
	//{
	//	dir = UP;
	//}
	//if (GetAsyncKeyState(VK_DOWN) && dir != UP)
	//{
	//	dir = DOWN;
	//}
	//if (GetAsyncKeyState(VK_LEFT) && dir != RIGHT)
	//{
	//	dir = LEFT;
	//}
	//if (GetAsyncKeyState(VK_RIGHT) && dir != LEFT)
	//{
	//	dir = RIGHT;
	//}

	char userkey = _getch();
	
		switch (userkey)
		{
		case'W':
		case'w':
		//case 72:
			if (dir != DOWN)
			{
				dir = UP;
			}
			break;
		case'S':
		case's':
		//case 80:
			if (dir != UP)
			{
				dir = DOWN;
			}
			break;
		case'A':
		case'a':
		//case 75:
			if (dir != RIGHT)
			{
				dir = LEFT;
			}
			break;
		case'D':
		case'd':
		//case 77:
			if (dir != LEFT)
			{
				dir = RIGHT;
			}
			break;
		}

	
	
}

void Snake::KeyControl_2p() {
	char userkey = _getch();

	switch (userkey)
	{
		case 72:
		if (dir != DOWN)
		{
			dir = UP;
		}
		break;
		case 80:
		if (dir != UP)
		{
			dir = DOWN;
		}
		break;
		case 75:
		if (dir != RIGHT)
		{
			dir = LEFT;
		}
		break;
		case 77:
		if (dir != LEFT)
		{
			dir = RIGHT;
		}
		break;
	}

}

void Snake::EatFood(int x,  int y, int &flag) {
	if (coor[0].x == x && coor[0].y == y&&flag==1)
	{
		num++;
		score += 10;
		flag = 0;
	}
}