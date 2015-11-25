#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "kasa.h"
#include "kitaplar.h"
#include "yazarlar.h"
using namespace std;


void yonet();
void baslikYaz();

void yonet(kitaplar *kitap,kasa *celikKasa, int i,int *sifre)
{
	int j,k;
	int secim = 0;
	int tKitap = 0;
	int cesit;
	double para ;
	cout << "\nSayin Yonetici HosGeldiniz \n" << endl;

	while(secim != 9)
	{
		cout << "1 -> Kasadaki Toplam Para " << endl;
		cout << "2 -> Satilan Toplam Kitap Sayisi " << endl;
		cout << "3 -> Mevcut Kitap Cesidi" <<  endl;
		cout << "4 -> Toplam Kitap Sayisi" << endl;
		cout << "5 -> Fiyat Guncelle" << endl;
		cout << "6 -> Stok Guncelle" << endl;
		cout << "7 -> Sifre Degistir" << endl;
		cout << "9 -> Cikis" << endl;

		cin >> secim;

		switch(secim)
		{
			case 1 :
				cout << "\nKasadaki Toplam Para = "<< celikKasa->kasadakiPara() << " TL \n" <<endl;
			break;

			case 2 :
				cout << "Satilan Toplam Kitap Sayisi = " << celikKasa->getSatilan() << " Tane\n" <<endl;
			break;

			case 3 :
				cesit = 0;
				for(j = 0; j < i; j++)
				{
					if(kitap[j].getAdet())
						cesit++;
				}
				cout << "\nMagazada Bulunan Mevcut Kitap Cesidi = " << cesit << " Cesit \n" << endl;
			break;

			case 4 :
				tKitap = 0;
				for(j = 0; j < i; j++)
				{
					tKitap += kitap[j].getAdet();
				}
				cout << "\nMagazada Bulunan Toplam Kitap Sayisi = " << tKitap << " Tanedir\n" << endl;
			break;

			case 5 :
				baslikYaz();
				for(j = 0; j < i ; j++)
				{
					if(kitap[j].getAdet())
					{
						cout << setw(6) << j+1 ;
						kitap[j].print();
					}
				}
				cout << endl << endl;
				cout << "Fiyatini Guncellemek Istediginiz Kitap Kodunu Giriniz (Cikis Icin -1 ) : " ;
				cin >> j;
				if(j != -1)
				{
				cout << "Kitabin Suanki Fiyati = " << kitap[j-1].getFiyat() << " TL " << endl;
				cout << "Yeni Fiyati Giriniz : " ;
				cin >> para;
				kitap[j-1].setKitap(kitap[j-1].getYazar(),kitap[j-1].getKitap(),kitap[j-1].getAdet(),para);
				cout << "\n Fiyat Guncellendi...\n" << endl;
				cout << "Kitabin Yeni Fiyati = " << kitap[j-1].getFiyat() << " TL  Oldu\n" << endl;
				}
				else
                    cout << "\nYonetici Anasayfasina Dondunuz...\n" << endl;
			break;

			case 6:
				baslikYaz();
				for(j = 0; j < i ; j++)
				{
					if(!kitap[j].getAdet())
					{
						cout << setw(6) << j+1 ;
						cout << setw(30) << kitap[j].getKitap() << setw(20) ;
						cout << kitap[j].getYazar();
						cout << setw(18) << kitap[j].getAdet();
						cout << setw(24) << kitap[j].getFiyat() << " TL\n";
					}
					else
					{
						cout << setw(4) << j+1 ;
						kitap[j].print();
					}

				}
				cout << endl << endl;
				cout << "Adedini Guncellemek Istediginiz Kitap Kodunu Giriniz (Cikis Icin -1): " ;
				cin >> j;
				if(j != -1)
				{
                cout << "Kitabin Mevcut Adedi = " << kitap[j-1].getAdet() << " Tane " << endl;
				cout << "Yeni Adedi Giriniz : " ;
				cin >> tKitap;
				kitap[j-1].setKitap(kitap[j-1].getYazar(),kitap[j-1].getKitap(),tKitap,kitap[j-1].getFiyat());
				cout << "\n Stok Guncellendi...\n" << endl;
				cout << "Kitabin Yeni Adedi = " << kitap[j-1].getAdet() << " Tane Oldu\n" << endl;
                }
                else
                    cout << "\nYonetici Anasayfasina Dondunuz \n" << endl;
			break;

			case 7:
				cout << "Mevcut Sifrenizi Giriniz (Cikis Icin -1): ";
				cin >> j;
				if(j != -1)
				{
				if(*sifre == j)
				{
					cout << "Yeni Sifreyi Girniz : ";
					cin >> j;
					cout << "Yeni Sifreyi Tekrar Girninz : ";
					cin >> k;
					if(j == k)
					{
						*sifre = k;
						cout << "\nSifreniz Basariyle Degistirildi...\n" << endl;
					}
					else
						cout << "\nGirdiginiz Sifreler Uyusmuyor...!!!\n" << endl;

				}
				else
					cout << "Yanlis Sifre Girdiniz...!\n" << endl;
                }
                else
                    cout << "\nYonetici Anasfasina Dondunuz \n" << endl;
				break;
			case 9 :
				cout << "Cikis Yaptiniz...\n" << "Musteri Anasayfasına Dondunuz...\n" << endl;
			break;

			default:
                cout << "\nYanlis Secim Yaptiniz Tekrar Deneyiniz...!!!\n" << endl;

		}


	}

	return;
}


void baslikYaz()
{
	cout<<endl<<endl;
	cout << left;
	cout << setw(6) << "No " << setw(22) << "Kitabin Ismi" << setw(22) << "Kitap Yazari";
	cout << setw(14) << "Stok" << setw(16) << "Fiyati" << endl;
	cout << setw(6) << "___ " << setw(22) << "_____________" << setw(22) << "_____________";
	cout << setw(14) << "_____" << "________\n";
}

int main()
{
	string satir;
	string yAd;
	string kAd;
	int adet;
	double fiyat;
	int secim;
	bool bulundu = false;
	string aranan;


	char a;
	int j=0;
	int i=0;
	int k;
	int m;
	int p;
	int kNo;
	int satis;
	int sifre = 1234;

	ifstream oku;
	oku.open("kitapci.txt");

	while(!oku.eof())
	{
		oku >> satir;
		if(satir == "#")
            j++;
        satir = "";
	}
	oku.close();

	k = j;
	kitaplar *kitapci;
	kitapci = new kitaplar[j];

	oku.open("kitapci.txt");
	while(k > 0)
	{


		oku >> satir;
        while(satir != "-")
        {
            yAd = yAd + satir + " ";
            oku >> satir;
        }
        oku >> satir;
        while(satir != "-")
        {
            kAd = kAd + satir + " ";
            oku >> satir;
        }

        oku >> adet;
        oku >> fiyat;
        oku >> satir;


        transform(yAd.begin(),yAd.end(),yAd.begin(),(int(*)(int))toupper);
        transform(kAd.begin(),kAd.end(),kAd.begin(),(int(*)(int))toupper);
		kitapci[i].setKitap(yAd,kAd,adet,fiyat);

		i++;
		k--;
		yAd = kAd = "";

	}
	oku.close();

	kasa celikKasa(0);
	cout << "**** Kitapciya Hosgeldiniz ***** " << endl;

	do
	{
		cout << "\n1 -> Mevcut Kitaplar" << endl;
		cout << "2 -> Arama Yapma " << endl;
		cout << "3 -> Kitap Satin Alma" << endl;
		cout << "4 -> Yonetici Girisi " << endl;
		cout << "9 -> Cikis " << endl;
		cout << "\nSeciminizi Yapiniz : ";
		cin >> secim;

		switch(secim)
		{
			case 1:
			baslikYaz();
				for(i = 0; i < j ; i++)
				{
					if(kitapci[i].getAdet())
					{
						cout << left << setw(6) << i+1 ;
						kitapci[i].print();
					}

				}
					cout<<endl<<endl;
			break;

			case 2:

				cout << "Aradiginiz Kitap  veya Yazar ismi : ";
				cin >> aranan;
				transform(aranan.begin(),aranan.end(),aranan.begin(),(int(*)(int))toupper);
				for(p = 0; p < j; p++)
				{
					m = k = -1;
					if(kitapci[p].getAdet())
					{
						string ara = kitapci[p].getYazar();
						transform(ara.begin(),ara.end(),ara.begin(),(int(*)(int))toupper);
						k = ara.find(aranan);
						ara = kitapci[p].getKitap();
						transform(ara.begin(),ara.end(),ara.begin(),(int(*)(int))toupper);
						m = ara.find(aranan);
					}
					if(k >= 0 || m >= 0)
					{
						if(!bulundu)
						{
							cout << "\nKitap Bulundu" ;
							baslikYaz();
						}
						cout << setw(6) << p+1 ;
						kitapci[p].print();
						bulundu = true;
					}


				}
				if(bulundu)
				{
				cout << "\nSatin Almak Istediginiz Kitap Kodu (Cikis icin -1): " ;
				cin >> p;
                if(p != -1)
				if(p <= j)
				{
					satis=kitapci[p-1].kitapSat();
					if(satis)
					{
						fiyat =kitapci[p-1].getFiyat();
						celikKasa.paraEkle(fiyat);
					}
				}
				else
					cout << "Kitap Kodu Bulunamadi...\n" << endl;
                else
                    cout << "\nAna Menuye Dondunuz \n";
                }
				else
                    cout << "\nAradiginiz Kitap Bulunamadi... !!! \n";
				bulundu = false;


			break;

			case 3:

				baslikYaz();
				for(i = 0; i < j ; i++)
				{
					if(kitapci[i].getAdet())
					{
						cout << left << setw(6) << i+1 ;
						kitapci[i].print();

					}
				}
				cout << "\nMevcut Kitap Sayisi : " << j << " Adet\n"<< endl;

				cout << "Satin Almak Istediginiz Kitap Kodu (Cikis icin -1): " ;
				cin >> p;
                if(p != -1)
				if(p <= j)
				{
					satis=kitapci[p-1].kitapSat();
					if(satis)
					{
						fiyat =kitapci[p-1].getFiyat();
						celikKasa.paraEkle(fiyat);
					}
				}
				else
					cout << "Kitap Kodu Bulunamadi...\n" << endl;
                else
                    cout << "\nAna Menuye Dondunuz \n";
			break;

			case 4:
				cout << "\n\nYonetici Girisi Icin Sifreyi Giriniz (Sifre =  " << sifre << " ) = ";
				cin >> p;
				if(p == sifre)
					yonet(kitapci,&celikKasa,j,&sifre);
				else
					cout << "\nYanlis Sifre Girdiniz...\n\n";
			break;


			case 9:
				cout << "Cikis Yaptiniz..." << endl;
			break;

			default:
				cout << "\nYanlis Secim Tekrar Deneyiniz..\n" << endl;


		}
	}while(secim != 9);

    delete [] kitapci;

	return 0;
}
