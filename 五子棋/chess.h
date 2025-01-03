#pragma once
#include<graphics.h>
#include<vector>
using namespace std;
struct Chesspos{
	int row;
	int col;
	Chesspos(int r=0, int c=0) :row(r), col(c) {}
};
typedef enum {
	chess_white = -1,
	chess_black = 1
}chess_kind_t;
class Chess
{
public:
	Chess(int gradesize, int marginx, int marginy, float chessssize);//棋盘格式，边界，棋盘方格大小
	void init();
	bool clickboard(int x, int y, Chesspos* pos);
	void chessdown(Chesspos *pos, chess_kind_t kind);
	int getgradesize();
	int getchessdata(Chesspos* pos);
	int getchessdata(int row, int col);
	bool checkover();
private:
	IMAGE chessblackimg;
	IMAGE chesswhiteimg;
	int gradesize;
	int margin_x;
	int margin_y;
	float chesssize;
	vector<vector<int>> chessmap;
	bool playerflag;//true:黑
	void updateGameMap(Chesspos* pos);
	bool checkwin();
	Chesspos lastPos;
};

