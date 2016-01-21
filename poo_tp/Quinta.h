#pragma once
#include "Edificio.h"

class Quinta :public Edificio{
	static int contaQ;
	int lin, col;
	int estado = 80;
	int limite = 99;
	const int madeira = 100;
	const int pedra = 300;
	const int ouro = 50;
	string setName();
public:
	Quinta(int lin, int col);
	string getName()const;
	bool getIsBuild()const;
	int getEstado()const;
	int getMadeira()const;
	int getPedra()const;
	int getOuro()const;
	string getDetail()const;
	int getLin()const;
	int getCol()const;
	int getLimite()const;

	//sets
	void setEstado(int dano);

};
