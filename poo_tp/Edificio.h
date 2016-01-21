#pragma once
#include "core.h"

class Edificio{
protected:
	string name;
	int lin, col;
	int estado = 0, limite = 0;
	const int madeira = 0;
	const int pedra = 0;
	const int ouro = 0;
	virtual string setName() = 0;
public:
	//gets
	virtual string getName()const = 0;
	virtual int getEstado()const = 0;
	virtual int getLimite()const = 0;
	virtual int getMadeira()const = 0;
	virtual int getPedra()const = 0;
	virtual int getOuro()const = 0;
	virtual string getDetail()const = 0;
	virtual int getLin()const = 0;
	virtual int getCol()const = 0;

	//sets
	virtual void setEstado(int dano) = 0;

};