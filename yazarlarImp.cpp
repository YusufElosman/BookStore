#include "yazarlar.h"
#include <iostream>
#include <iomanip>
using namespace std;
string yazarlar::getYazar()
{
	return yIsim;
}

void yazarlar::print() const
{
    cout << left;
	cout << setw(24) << yIsim;
}

void yazarlar::setYazar(string isim)
{
	yIsim = isim;
}

yazarlar::yazarlar()
{
    yIsim = "*";
}

yazarlar::~yazarlar()
{

}
