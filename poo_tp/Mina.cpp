#include "Mina.h"

Mina::Mina(int lin, int col, int quant){
	this->lin = lin;
	this->col = col;
	this->quantidade = quant;
	this->nome = "O";
}

string Mina::getName() const{ return nome; }
int Mina::getQuantidade(){ return quantidade; }
int Mina::getLin()const{ return lin; }
int Mina::getCol()const{ return col; }
void Mina::setQuantidade(int quant){
	quantidade -= quant;
	if (quantidade <= 0){
		quantidade = 0;
	}
}