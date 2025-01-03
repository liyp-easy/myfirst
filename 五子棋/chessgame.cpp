#include "chessgame.h"

Chessgame::Chessgame(Man* man, AI* ai, Chess* chess)
{
	this->man = man;
	this->ai = ai;
	this->chess = chess;
	man->init(chess);
	ai->init(chess);
}

void Chessgame::play()
{
	chess->init();
	while (1) {
		man->go();
		if (chess->checkover()) {
				chess->init();
				continue;
			
		}
		ai->go();
		if (chess->checkover()) {
				chess->init();
				continue;
		}
	}
}
