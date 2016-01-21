#pragma once
#include "core.h"

class Bloco{
	int col, lin;
	bool isEmpty = true;
	bool wasSaw = false;
public:
	Bloco(int lin, int col);
	int getCol()const;
	int getLin()const;
	bool getEmpty()const;
	bool getWasSaw() const;
	void setEmpty(bool setB);
	void setWasSaw(bool setB);
};