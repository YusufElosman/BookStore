#include "kasa.h"

int kasa::getSatilan()
{
	return satilan;
}

double kasa::kasadakiPara()
{
	return para;
}

void kasa::paraEkle(double yPara)
{
	para += yPara;
	satilan++;
}

kasa::kasa(int miktar)
{
	satilan = 0;
	if(miktar >= 0)
		para = miktar;
	else
		para = 10;
}
