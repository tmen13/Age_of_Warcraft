#pragma once
#include "core.h"

class Unidade{
protected:
	string name;
	int saude, lin, col;
	const int velocidade = 0;
	const int madeira = 0;
	const int pedra = 0;
	const int ouro = 0;
	const int ataque = 0;
	const int defesa = 0;
	bool canCarry = false;
	bool canAtack = false;
	bool wasAtacked = false;
	virtual string setName() = 0;
	virtual void setSaude(int dano) = 0;
	virtual void setColuna(int col) = 0;
	virtual void setLinha(int lin) = 0;
public:
	// gets	
	virtual string getName() const = 0;
	virtual int getSaude() const = 0;
	virtual int getMadeira() const = 0;
	virtual int getPedra() const = 0;
	virtual int getOuro()const = 0;
	virtual bool getCarry() const = 0;
	virtual bool getAtack() const = 0;
	virtual bool getWasAtacked() const = 0;
	virtual string getDetail() const = 0;
	virtual int getLin()const = 0;
	virtual int getCol()const = 0;

	virtual void movimentar(int lin, int col) = 0;
};