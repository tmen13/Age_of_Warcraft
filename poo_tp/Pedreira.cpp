#include "Pedreira.h"

Pedreira::Pedreira(int lin, int col, int quant){
	this->lin = lin;
	this->col = col;
	this->quantidade = quant;
	this->nome = "P";
}

string Pedreira::getName() const{ return nome; }
int Pedreira::getQuantidade(){ return quantidade; }
int Pedreira::getLin()const{ return lin; }
int Pedreira::getCol()const{ return col; }
void Pedreira::setQuantidade(int quant){
	quantidade -= quant;
	if (quantidade <= 0){
		quantidade = 0;
	}
}