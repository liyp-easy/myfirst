#include<iostream>
#include"chessgame.h"
int main(void) {
	Man man;
	AI ai;
	Chess chess(13,44,43,67.4);
	Chessgame game(&man, &ai, &chess);

	game.play();
	return 0;
}