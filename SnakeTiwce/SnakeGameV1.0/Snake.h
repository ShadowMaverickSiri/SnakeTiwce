#pragma once
#include"headfile.h"


class Snake
{
public:
	Snake(void );
	//Snake(int num, int x, int y);
	~Snake(void);
	
	int flag_life;
	int head;

	int num;
	int dir;
	int score;
	int size; 
	int speed;
	POINT coor[SNAKE_MAX]; 
	enum DIR { UP, DOWN, LEFT, RIGHT };

	
	void SnakeDraw();       //画蛇P1
	void SnakeDraw2();       //画蛇P2
	void SnakeMove();   //蛇的移动(穿墙模式)
	void SnakeMove2(); //蛇移动（不能穿墙）
	void KeyControl();   //键盘操作
	void KeyControl_2p();  //键盘操作 2p
	void EatFood(int x, int y, int& flag);  //吃食物
	void EatFood2(int x, int y, int& flag);//吃食物2P

private:

protected:

};

