#include "Castelo.h"

int Castelo::contaCast = 0;

//implementar sistema de coordenadas
Castelo::Castelo(int lin, int col){
	contaCast++;
	name = setName();
	this->lin = lin;
	this->col = col;
}

string Castelo::getName() const{ return name; }
int Castelo::getEstado()const{ return estado; }
int Castelo::getMadeira() const{ return madeira; }
int Castelo::getPedra() const{ return pedra; }
int Castelo::getOuro()const { return ouro; }
int Castelo::getLin()const{ return lin; }
int Castelo::getCol()const{ return col; }
int Castelo::getLimite()const { return limite; }
string Castelo::getDetail()const{
	ostringstream oss;
	oss << getName() << "(" << getLin() << "/" << getCol() << ")" << endl;
	return oss.str();
}

//sets
string Castelo::setName(){
	ostringstream oss;
	oss << "C" << setw(2) << setfill('0') << contaCast;
	return oss.str();
}

void Castelo::setEstado(int dano){
	estado -= dano;
	if (estado <= 0){
		estado = 0;
	}
}