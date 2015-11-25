#ifndef kasa_H
#define kasa_H
using namespace std;
#include <iostream>
class kasa
{
public:
	double kasadakiPara();
	kasa (int miktar = 10);
	void paraEkle(double yPara);
	int getSatilan();
private:
	double para;
	int satilan;
};

#endif
