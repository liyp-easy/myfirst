#include "man.h"

void Man::init(Chess* chess)
{
	this->chess = chess;
}

void Man::go()
{
	MOUSEMSG msg;
	Chesspos pos;
	while (1) {
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN && chess->clickboard(msg.x, msg.y, &pos)) {
			break;
		}
	}
	//Âä×Ó
	chess->chessdown(&pos, chess_black);
}
