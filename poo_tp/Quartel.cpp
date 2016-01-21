#include "Quartel.h"

int Quartel::contaQuart = 0;

Quartel::Quartel(int lin, int col){
	contaQuart++;
	name = setName();
	this->lin = lin;
	this->col = col;
}

string Quartel::getName() const{ return name; }
int Quartel::getEstado()const{ return estado; }
int Quartel::getMadeira() const{ return madeira; }
int Quartel::getPedra() const{ return pedra; }
int Quartel::getOuro()const { return ouro; }
int Quartel::getLin()const{ return lin; }
int Quartel::getCol()const{ return col; }
int Quartel::getLimite()const { return limite; }
string Quartel::getDetail()const{
	ostringstream oss;
	oss << getName() << "(" << getLin() << "/" << getCol() << ")" << endl;
	return oss.str();
}

//sets
string Quartel::setName(){
	ostringstream oss;
	oss << "Q" << setw(2) << setfill('0') << contaQuart;
	return oss.str();
}

void Quartel::setEstado(int dano){
	estado -= dano;
	if (estado <= 0){
		estado = 0;
	}
}