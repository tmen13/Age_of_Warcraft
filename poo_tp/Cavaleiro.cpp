#include "Cavaleiro.h"

int Cavaleiro::contaCav = 0;

Cavaleiro::Cavaleiro(int lin, int col){
	contaCav++;
	name = setName();
	this->lin = lin;
	this->col = col;
}

string Cavaleiro::getName() const{ return name; }
int Cavaleiro::getSaude() const{ return saude; }
int Cavaleiro::getMadeira() const{ return madeira; }
int Cavaleiro::getPedra() const{ return pedra; }
int Cavaleiro::getOuro()const{ return ouro; }
int Cavaleiro::getLin()const{ return lin; }
int Cavaleiro::getCol()const{ return col; }
bool Cavaleiro::getCarry() const{ return canCarry; }
bool Cavaleiro::getAtack() const{ return canAtack; }
bool Cavaleiro::getWasAtacked() const{ return wasAtacked; }

string Cavaleiro::getDetail() const{
	ostringstream oss;
	oss << getName() << "(" << getLin() << "/" << getCol() << ")" << endl;
	return oss.str();
}

//sets
void Cavaleiro::setSaude(int dano){
	saude -= dano;
	if (saude <= 0){
		saude = 0;
	}
}

string Cavaleiro::setName(){
	ostringstream oss;
	oss << "K" << setw(2) << setfill('0') << contaCav;
	return oss.str();
}

void Cavaleiro::setColuna(int col){ this->col = col; }
void Cavaleiro::setLinha(int lin){ this->lin = lin; }

void Cavaleiro::movimentar(int lin, int col){
	this->setLinha(lin);
	this->setColuna(col);
}
