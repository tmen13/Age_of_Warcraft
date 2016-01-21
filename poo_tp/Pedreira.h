#pragma once
#include "FonteRecurso.h"

class Pedreira :public FonteRecurso{
	string nome;
	int quantidade;
	int lin, col;
public:
	Pedreira(int lin, int col, int quant);
	
	string getName()const;
	int getQuantidade();
	int getLin()const;
	int getCol()const;
	void setQuantidade(int quant);
};