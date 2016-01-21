#pragma once
#include "core.h"

class FonteRecurso{
	string nome;
	int lin, col;
	int quantidade;
public:	
	virtual string getName()const = 0;
	virtual int getQuantidade() = 0;
	virtual int getLin()const = 0;
	virtual int getCol()const = 0;
	virtual void setQuantidade(int quant) = 0;
};