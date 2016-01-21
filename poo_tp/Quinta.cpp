#include "Quinta.h"

int Quinta::contaQ = 0;


Quinta::Quinta(int lin, int col)
{
	contaQ++;
	name = setName();
	this->lin = lin;
	this->col = col;
}

string Quinta::getName() const{ return name; }
int Quinta::getEstado()const{ return estado; }
int Quinta::getMadeira() const{ return madeira; }
int Quinta::getPedra() const{ return pedra; }
int Quinta::getOuro()const { return ouro; }
int Quinta::getLin()const{ return lin; }
int Quinta::getCol()const{ return col; }
int Quinta::getLimite()const { return limite; }

string Quinta::getDetail()const{
	ostringstream oss;
	oss << getName() << "(" << getLin() << "/" << getCol() << ")" << endl;
	return oss.str();
}

//sets
string Quinta::setName(){
	ostringstream oss;
	oss << "F" << setw(2) << setfill('0') << contaQ;
	return oss.str();
}

void Quinta::setEstado(int dano){
	estado -= dano;
	if (estado <= 0){
		estado = 0;
	}
}
