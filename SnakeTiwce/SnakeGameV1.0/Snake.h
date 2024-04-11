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

	
	void SnakeDraw();       //����P1
	void SnakeDraw2();       //����P2
	void SnakeMove();   //�ߵ��ƶ�(��ǽģʽ)
	void SnakeMove2(); //���ƶ������ܴ�ǽ��
	void KeyControl();   //���̲���
	void KeyControl_2p();  //���̲��� 2p
	void EatFood(int x, int y, int& flag);  //��ʳ��
	void EatFood2(int x, int y, int& flag);//��ʳ��2P

private:

protected:

};

