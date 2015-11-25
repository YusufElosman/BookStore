#include "kitaplar.h"
#include <iostream>
#include <iomanip>
using namespace std;

kitaplar::kitaplar()
{
    kIsim = "*";
    adet = 0;
    fiyat = 0;
}

kitaplar::~kitaplar()
{

}

int kitaplar::getAdet()
{
	return adet;
}

double kitaplar::getFiyat()
{
	return fiyat;
}

bool kitaplar::kitapSat()
{
	double gPara,yPara;
	int secim;
	cout << "\nKitabin Fiyati = " << fiyat << " TL" << endl;
	cout << "\nParayi Giriniz (Cikis icin -1): ";
	cin >> gPara;

    if(gPara != -1)
    {
	while(gPara < fiyat)
	{
		cout << "\n" << (fiyat - gPara) << " TL Eksik para girdiniz \n" << endl;
		cout << "1 -> Para Ekle " << endl;
		cout << "2 -> Cikis " << endl;

		cin >> secim;
		switch(secim)
		{
			case 1:
				cout << "Parayi Giriniz : ";
				cin >> yPara;
				gPara += yPara;
			break;
			case 2:
				cout << "Satis Islemi Basarisiz..." << endl;
				return 0;
			default:
				cout << "Yanlis Secim Tekar Deneyiniz:" << endl;
		}
	}

	if(gPara > fiyat)
	{
		cout << "Para Ustu :" << gPara - fiyat << " TL " << endl;
		gPara = fiyat;
	}
	adet--;

	cout << "\nSatis Islemi Basarili \n" << endl;
	return 1;
	}
	else
	{
        cout << "\nAna Menuye Dondunuz \n" << endl;
        return 0;
	}
}

string kitaplar::getKitap()
{
	return kIsim;
}

void kitaplar::setKitap(string yazar,string kitap,int sayi,double ucret)
{
	setYazar(yazar);
	kIsim = kitap;
	adet = sayi;
	fiyat = ucret;
}

void kitaplar::print() const
{
	if(adet > 0)
	{
        cout << left;
		cout << setw(22) << kIsim << setw(18) ;
		yazarlar::print();
		cout << setw(13) << adet;
		cout << setw(6) << fiyat << " TL\n";

	}
}
