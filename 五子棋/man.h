#pragma once
#include"chess.h"
class Man
{
public:
	void init(Chess* chess);
	void go();
private:
	Chess* chess;
};

