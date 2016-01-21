#pragma once
#include "FonteRecurso.h"

class Floresta :public FonteRecurso{
	string nome;
	int quantidade;
	int lin, col;
public:
	Floresta(int lin, int col, int quant);

	string getName()const;
	int getQuantidade();
	int getLin()const;
	int getCol()const;
	void setQuantidade(int quant);
};