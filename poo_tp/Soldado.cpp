#include "Soldado.h"

int Soldado::contaSold = 0;

Soldado::Soldado(int lin, int col){
	contaSold++;
	name = setName();
	this->lin = lin;
	this->col = col;
}

// gets
string Soldado::getName() const{ return name; }
int Soldado::getSaude() const{ return saude; }
int Soldado::getMadeira() const{ return madeira; }
int Soldado::getPedra() const{ return pedra; }
int Soldado::getOuro()const{ return ouro; }
int Soldado::getLin()const{ return lin; }
int Soldado::getCol()const{ return col; }
bool Soldado::getCarry() const{ return canCarry; }
bool Soldado::getAtack() const{ return canAtack; }
bool Soldado::getWasAtacked() const{ return wasAtacked; }

string Soldado::getDetail() const{
	ostringstream oss;
	oss << getName() << "(" << getLin() << "/" << getCol() << ")" << endl;
	return oss.str();
}

//sets
void Soldado::setSaude(int dano){
	saude -= dano;
	if (saude <= 0){
		saude = 0;
	}
}

string Soldado::setName(){
	ostringstream oss;
	oss << "S" << setw(2) << setfill('0') << contaSold;
	return oss.str();
}

void Soldado::setColuna(int col){ this->col = col; }
void Soldado::setLinha(int lin){ this->lin = lin; }

void Soldado::movimentar(int lin, int col){
	this->setLinha(lin);
	this->setColuna(col);
}