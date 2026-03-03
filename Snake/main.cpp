#include<graphics.h>
#include<conio.h>
#include<iostream>
#include<windows.h>
#include<random>
#include<ctime>
#include<cstdlib>
#include<string>
#include <tchar.h>
using namespace std;


int le = 8;//长度初始化
int score = 0;//分数初始化
int sn[1000][2] = { {10,8},{11,8} ,{12,8},{12,9},{13,9},{13,10} ,{13,11} ,{13,12} };//蛇身体数据初始化

#define w 20  //方块宽度


void drawunit(int x, int y) {
	setfillcolor(RGB(60, 60, 60));
	fillcircle(x * w + 10, y * w + 10, 11);
}//蛇单元构建



void drawsnake(int a[][2]) {
	for (int i = 0; i < le - 1; i++) {
		drawunit(a[i][0], a[i][1]);
	}
	//fillpie(a[0][0] * 20 - 20, a[0][1] * 20, a[0][0] * 20 + 20, a[0][1] * 20 + 20, -0.5, 0.5);
	setfillcolor(RGB(200, 200, 200));
	//fillpie(a[7][0] * 20, a[7][1] * 20 - 10, a[7][0] * 20 + 20, a[7][1] * 20 + 20, -1, 4);
	fillcircle(a[le - 1][0] * w + 10, a[le - 1][1] * w + 10, 11);
}//蛇整体的构建

void bkuni(int i, int j) {
	IMAGE img3;	// 定义 IMAGE 对象
	loadimage(&img3, _T("..\\resources\\围墙.jpg"));	// 读取图片到 img3 对象中
	putimage(i * w, j * w, &img3);	// 在坐标 (0, 0) 位置显示 IMAGE 对象
}//围墙单元


void drawbk() {
	setbkcolor(RGB(70, 100, 70));
	IMAGE img;	// 定义 IMAGE 对象
	loadimage(&img, _T("..\\resources\\300.jpg"));	// 读取图片到 img 对象中
	putimage(0, 0, &img);	// 在坐标 (0, 0) 位置显示 IMAGE 对象
	IMAGE img2;	// 定义 IMAGE 对象
	loadimage(&img2, _T("..\\resources\\snake.jpg"));	// 读取图片到 img2 对象中
	putimage(780, 200, &img2);	// 在坐标 (0, 0) 位置显示 IMAGE 对象
	setlinecolor(RGB(100, 100, 100));
	int n = 0;
	while (n < 600) {                        //
		int pts[] = { 0,n , 780, n };        //网格线构建————
		polyline((POINT*)pts, 2);            // 横线构造
		n += w;                             //
	}                                        //
	n = 0;                                   // 
	while (n < 780) {                          //网格线构建———
		int pts[] = { n ,0 , n , 600 };       //竖线构造
		polyline((POINT*)pts, 2);             // 
		n += w;                              // 
	}
	for (int i = 0; i < 54; i++) {
		bkuni(0, i);
		bkuni(38, i);
	}//左右边界
	for (int i = 0; i < 54; i++) {
		bkuni(i, 0);
		bkuni(i, 29);
	}//上下边界      ------ 围墙构建
    TCHAR s[16];
    _stprintf_s(s, 16, _T("%d"), score);
    outtextxy(940, 85, s);
	RECT r = { 780, 0, 1000, 200 };
	settextstyle(30, 0, _T("Consolas"));
	drawtext(_T("score:"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);// 分数显示
}//背景设置


void snakemove(char a) {
	for (int i = 0; i < le - 1; i++) {
		sn[i][0] = sn[i + 1][0];
		sn[i][1] = sn[i + 1][1];
	}//移动后身体数据记录
	if (a == 'w') {
		sn[le - 1][1] = sn[le - 2][1] - 1;

	}//上移
	else if (a == 's') {
		sn[le - 1][1] = sn[le - 2][1] + 1;

	}//下移
	else if (a == 'd') {
		sn[le - 1][0] = sn[le - 2][0] + 1;

	}//右移
	else if (a == 'a') {
		sn[le - 1][0] = sn[le - 2][0] - 1;

	}//左移
	for (int i = 0; i < 8; i++) {
		//cout << "(" << sn[i][0] << "," << sn[i][1] << ")" << " ";
	}
	cout << endl;
}//改变蛇移动方向


void automove() {
	int x = sn[le - 1][0] - sn[le - 2][0];
	int y = sn[le - 1][1] - sn[le - 2][1];//判断朝向依据
	for (int i = 0; i < le - 1; i++) {
		sn[i][0] = sn[i + 1][0];
		sn[i][1] = sn[i + 1][1];
	}//移动后身体数据记录
	if (x == 1) {
		sn[le - 1][0]++;

	}//头向右自动向右移动
	else if (x == -1) {
		sn[le - 1][0]--;

	}//头向左自动向左移动
	else if (y == 1) {
		sn[le - 1][1]++;
	}//头向上自动向上移动
	else if (y == -1) {
		sn[le - 1][1]--;

	}//头向下自动向下移动
}//自动移动


int fx = 0;
int fy = 0;// 食物坐标初始化
void foodcreat() {
	int j = 1;
	int j2 = 0;
	srand((unsigned)time(NULL));
	while (j2 == 0) {
		fx = (rand() % 37 + 1);
		fy = (rand() % 28 + 1);
		for (int i = 0; i < le; i++) {
			if (sn[i][0] == fx && sn[i][1] == fy) {
				j = 0;
			}
		}//是否在蛇身体里面
		if (j != 0) {
			j2 = 1;
		}
	}
	//cout <<"《" << fx << "," << fy <<"》";
}//食物坐标生成


void foodshow() {
	IMAGE img3;	// 定义 IMAGE 对象
	loadimage(&img3, _T("..\\resources\\红苹果.jpg"));	// 读取图片到 img3 对象中
	putimage(fx * w, fy * w, &img3);	// 在坐标 (0, 0) 位置显示 IMAGE 对象
}


void increase() {
	int eat = 0;
	int t[1000][2] = { 0 };//中转数组
	if (sn[le - 1][0] == fx && sn[le - 1][1] == fy) {
		le++;
		eat = 1;
		score++;
	}//食物坐标与头坐标重合判定食物被吃,分数增加
	if (eat == 1) {
		for (int i = 1; i < le; i++) {
			t[i][0] = sn[i - 1][0];
			t[i][1] = sn[i - 1][1];
		}
		for (int i = 1; i < le; i++) {
			sn[i][0] = t[i][0];
			sn[i][1] = t[i][1];
		}
		sn[0][0] = 2 * sn[1][0] - sn[2][0];
		sn[0][1] = 2 * sn[1][1] - sn[2][1];
		//cout << "<" << sn[le - 1][0] << "," << sn[le - 1][1] << ">";
		cleardevice();
		drawbk();
		drawsnake(sn);
		foodcreat();
		foodshow();
	}
}//伸长


void fail() {
	RECT r = { 0, 0, 769, 509 };
	settextstyle(100, 0, _T("Consolas"));
	drawtext(_T("You died"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}//失败处理


bool failjudge() {
	int x = sn[le - 1][0] - sn[le - 2][0];
	int y = sn[le - 1][1] - sn[le - 2][1];//朝向
	if (x > 0) {
		if (sn[le - 1][0] >= 38) {
			return 1;
		}
	}
	if (x < 0) {
		if (sn[le - 1][0] == 0) {
			return 1;
		}
	}
	if (y > 0) {
		if (sn[le - 1][1] == 29) {
			return 1;
		}
	}
	if (y < 0) {
		if (sn[le - 1][1] == 0) {
			return 1;
		}
	}//是否超出边界
	for (int i = 0; i < 7; i++) {
		if (sn[le - 1][0] == sn[i][0] && sn[le - 1][1] == sn[i][1]) {
			return 1;
		}//是否与身体碰撞（坐标是否重合）
	}
}//失败判定


int main() {
	initgraph(1024, 600, EX_SHOWCONSOLE);
	BeginBatchDraw();
	drawbk();
	drawsnake(sn);
	foodcreat();
	while (failjudge() != 1) {
		drawsnake(sn);
		if (_kbhit()) {
			char a = _getch();
			snakemove(a);
			cleardevice();
			drawbk();
			drawsnake(sn);
		}
		else {
			automove();
			cleardevice();
			drawbk();
			drawsnake(sn);

		}
		foodshow();
		increase();
		FlushBatchDraw();
		Sleep(150);
	}
	EndBatchDraw();
	fail();
	_getch();
	closegraph();
	return 0;
}