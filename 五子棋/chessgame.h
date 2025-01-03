#pragma once
#include"AI.h"
#include"man.h"
#include"chess.h"
class Chessgame
{
public:
	Chessgame(Man* man, AI* ai, Chess* chess);
	void play();
private:
	Man* man;
	AI* ai;
	Chess* chess;
};

