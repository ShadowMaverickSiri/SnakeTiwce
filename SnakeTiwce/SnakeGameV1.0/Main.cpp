#include"headfile.h"
#include"Snake.h"
#include"Food.h"

using namespace std;

void GameInit();
void GameDraw();
void Restrict();  //��ϷԼ��
void GamePause();//��Ϸ��ͣ
void KeyControl(); //���̿���
void Char2TCHAR(const char* _char, TCHAR* tchar);
void cardioid(int _x, int _y, int a);

Snake snake,snake2;
Food apple,apple2;
DWORD t1, t2;
DWORD T;
int flag_gameover = 0;
enum DIR {UP,DOWN,LEFT,RIGHT};



void GameInit() {
	//��ʼ����1������
	snake.num = 2;
	snake.dir = RIGHT;
	snake.score = 0;
	snake.size = 20;
	snake.coor[snake.num -1].x =( (Window_W / snake.size) /4 )* snake.size;
	snake.coor[snake.num-1].y = ((Window_H/ snake.size)/2)* snake.size;
	for (int i = snake.num-2; i >=0; i--)
	{
		snake.coor[i].x = snake.coor[snake.num - 1].x + snake.size*(snake.num-1-i);
		snake.coor[i].y = snake.coor[snake.num - 1].y;
	}
	for (int i = snake.num;i<SNAKE_MAX;i++)
	{
		snake.coor[i].x = -100;
		snake.coor[i].y = -100;
	}


	//��ʼ����2������
	snake2.num = 2;
	snake2.dir = LEFT;
	snake2.score = 0;
	snake2.size = 20;
	snake2.coor[snake2.num - 1].x = ((Window_W / snake.size) / 4*3) * snake.size;;
	snake2.coor[snake2.num - 1].y = ((Window_H / snake.size) / 2) * snake.size;
	for (int i = snake2.num - 2; i >= 0; i--)
	{
		snake2.coor[i].x = snake2.coor[snake2.num - 1].x - snake2.size * (snake2.num - 1 - i);
		snake2.coor[i].y = snake2.coor[snake2.num - 1].y;
	}
	for (int i = snake2.num; i < SNAKE_MAX; i++)
	{
		snake2.coor[i].x = -100;
		snake2.coor[i].y = -100;
	}

	srand(GetTickCount());

	//��ʼ��ƻ��1����
	apple.coor.x = rand() % (Window_W/snake.size)* snake.size;
	apple.coor.y = rand() % (Window_H / snake.size) * snake.size;
	apple.flag = 1;
	apple.size = 20;
	apple.color =GREEN;

	//��ʼ��ƻ��2����
	apple2.coor.x = rand() % (Window_W / snake2.size) * snake2.size;
	apple2.coor.y = rand() % (Window_H / snake2.size) * snake2.size;
	apple2.flag = 1;
	apple2.size = 20;
	apple2.color = RGB(249, 34, 17);


	T = 200;//���ó�ʼ�ٶ�
}

void GameDraw() {
	setbkcolor(RGB(172, 205, 211));
	cleardevice();
	//T = 200 - (snake.num> snake2.num? snake.num: snake2.num) * 2;//�ߵ��ٶȿ���
	T = 200 - (snake.num + snake2.num) * 2;
	T = T < 50 ? 50 : T;

	if (t2 - t1 > T)
	{
		snake.SnakeMove();
		snake2.SnakeMove();
		t1 = t2;
	}

	t2 = GetTickCount();
	snake.SnakeDraw();
	snake2.SnakeDraw2();
	//����ʳ�ﲻ��������������
	apple.FoodDraw(*snake.coor, snake.num, *snake2.coor,snake2.num);
	apple2.FoodDraw2(*snake.coor, snake.num, *snake2.coor, snake2.num);
	snake.EatFood(apple.coor.x, apple.coor.y,apple.flag);
	snake2.EatFood(apple2.coor.x, apple2.coor.y, apple2.flag);
	if (_kbhit())
	{
		KeyControl();
	}
	
	//��ʾ����
	 char  temp[20]= "";
	 TCHAR temp_out[20];
	sprintf(temp, "P1������%d", snake.score);
	setbkmode(TRANSPARENT);
	Char2TCHAR(temp, temp_out);
	settextcolor(RED);
	settextstyle(30, 0,_T("΢���ź�"));//�������ִ�С ��ʽ 
	outtextxy(20, 0, temp_out);

	sprintf(temp, "P2������%d", snake2.score);
	setbkmode(TRANSPARENT);
	Char2TCHAR(temp, temp_out);
	settextcolor(RED);
	settextstyle(30, 0, _T("΢���ź�"));//�������ִ�С ��ʽ 
	outtextxy(200, 0, temp_out);

	sprintf(temp, "�ܷ�����%d", snake.score+snake2.score);
	setbkmode(TRANSPARENT);
	Char2TCHAR(temp, temp_out);
	settextcolor(RED);
	settextstyle(30, 0, _T("΢���ź�"));//�������ִ�С ��ʽ 
	outtextxy(400, 0, temp_out);

	setbkmode(TRANSPARENT);
	settextcolor(YELLOW);
	settextstyle(30, 0, _T("΢���ź�"));//�������ִ�С ��ʽ 
	outtextxy(Window_W - 140, Window_H - 40, _T("By Caesarlsy"));

	FlushBatchDraw();
	
}

void Restrict() {
	//�˳���Ϸ��������
	//1Pҧ���Լ�
	for (int i = 4; i < snake.num; i++)
	{
		if (snake.coor[0].x == snake.coor[i].x && snake.coor[0].y == snake.coor[i].y)
		{
			flag_gameover = 1;
		}
	}
	//2Pҧ���Լ�
	for (int i = 4; i < snake2.num; i++)
	{
		if (snake2.coor[0].x == snake2.coor[i].x && snake2.coor[0].y == snake2.coor[i].y)
		{
			flag_gameover = 2;
		}
	}
	//1Pҧ��2P
	for (int i = 0; i < snake2.num; i++)
	{
		if (snake.coor[0].x == snake2.coor[i].x && snake.coor[0].y == snake2.coor[i].y)
		{
			flag_gameover = 3;
		}
	}
	//2Pҧ��1P
	for (int i = 0; i < snake.num; i++)
	{
		if (snake2.coor[0].x == snake.coor[i].x && snake2.coor[0].y == snake.coor[i].y)
		{
			flag_gameover = 4;
		}
	}

	//1P�Դ�ʳ��
	if (snake.coor[0].x == apple2.coor.x && snake.coor[0].y == apple2.coor.y)
	{
		flag_gameover = 5;
	}
	//2P�Դ�ʳ��
	if (snake2.coor[0].x == apple.coor.x && snake2.coor[0].y == apple.coor.y)
	{
		flag_gameover = 6;
	}
	////��1����ǽ��
	//if (snake.coor[0].x < 0 ||snake.coor[0].x >= Window_W || snake.coor[0].y < 0  || snake.coor[0].y>=Window_H)
	//{
	//	flag_gameover = 7;
	//}
	////��2����ǽ��
	//if (snake2.coor[0].x < 0 || snake2.coor[0].x >= Window_W || snake2.coor[0].y < 0 || snake2.coor[0].y>=Window_H)
	//{
	//	flag_gameover = 8;
	//}


	
	if (flag_gameover!=0)
	{
		
		cardioid(Window_W / 2, Window_H / 2, 100);
		outtextxy(Window_W/2-snake.size, Window_H/2, _T("Game Over!"));
		_getch();
		exit(88);

	}

}

void KeyControl() {
	char userkey = _getch();

	switch (userkey)
	{
	case'W':
	case'w':
		
		if (snake.dir != DOWN)
		{
			snake.dir = UP;
		}
		break;
	case'S':
	case's':
		//case 80:
		if (snake.dir != UP)
		{
			snake.dir = DOWN;
		}
		break;
	case'A':
	case'a':
		//case 75:
		if (snake.dir != RIGHT)
		{
			snake.dir = LEFT;
		}
		break;
	case'D':
	case'd':
		//case 77:
		if (snake.dir != LEFT)
		{
			snake.dir = RIGHT;
		}
		break;

	case 72:
		if (snake2.dir != DOWN)
		{
			snake2.dir = UP;
		}
		break;
	case 80:
		if (snake2.dir != UP)
		{
			snake2.dir = DOWN;
		}
		break;
	case 75:
		if (snake2.dir != RIGHT)
		{
			snake2.dir = LEFT;
		}
		break;
	case 77:
		if (snake2.dir != LEFT)
		{
			snake2.dir = RIGHT;
		}
		break;
	}

	



}

void GamePause() {
	if (_getch() == 32)
	{
		char ch = _getch();
		while (ch == 32)
		{
			while (1)
			{
				ch = _getch();
			}
		}

	}
}

void cardioid(int _x, int _y, int a)
{
	cleardevice();
	setlinecolor(RGB(255, 0, 0));
	setlinestyle(0, 10, 0, 0);
	int x1, y1, x2, y2;
	double angle = PI;
	while (angle <= 3 * PI)
	{
		x1 = a * (2 * sin(angle) + sin(2 * angle)) + _x;
		y1 = a * (2 * cos(angle) + cos(2 * angle)) + _y;
		angle += ONE_ANGLE;
		x2 = a * (2 * sin(angle) + sin(2 * angle)) + _x;
		y2 = a * (2 * cos(angle) + cos(2 * angle)) + _y;
		line(x1, y1, x2, y2);
		Sleep(5);
	}


}

void Char2TCHAR(const char* _char, TCHAR* tchar)
{
	int iLength;
	iLength = MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, NULL, 0);
	MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, tchar, iLength);
}

int main(){
	t1 = t2 = GetTickCount();//ȡ��ʼʱ��
	initgraph(Window_W,Window_H,0);
	GameInit();

	while (1)
	{
		GameDraw();
		Restrict(); 
		
		//Sleep(50);
	}

	/*cout << "welcome" << endl;*/
	//system("pause");
	closegraph();
	return 0;
}