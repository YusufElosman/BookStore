#include "yazarlar.h"
#ifndef kitaplar_H
#define kitaplar_H
class  kitaplar : public yazarlar
{
public:
	void print() const;
	void setKitap(string yazar,string kitap, int sayi, double ucret);
	bool kitapSat();
	string getKitap();
	double getFiyat();
	int getAdet();
	kitaplar();
	~kitaplar();
private:
	string kIsim;
	int adet;
	double fiyat;
};
#endif
