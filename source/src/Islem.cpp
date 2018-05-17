/**
* @file Islem.cpp
* @description Huffman algoritmasi kullanarak bir metin dosyasının boyutunu daraltmak
* @course 2.öğretin B grubu
* @assignment 04
* @date 27.12.2017
* @author Aytekin Erlale - Ahmet Özdilli / aytekin.erlale@ogr.sakarya.edu.tr - ahmet.ozdilli@ogr.sakarya.edu.tr 
*/

#include "Islem.hpp"
#include<bits/stdc++.h>

//binary stringi int e çevirip decimal karsıligini geri dondurur
int Islem::Donustur(string n)
{
	int deger = atoi(n.c_str());
	int decimalNumber = 0, i = 0, remainder;

	while (deger != 0)
	{

		remainder = deger % 10;
		deger /= 10;
		decimalNumber += remainder*pow(2, i);
		++i;
	}
	return decimalNumber;
} 

//karakteri tablo.txt'den sayisal karsiligini dondurur
string Islem::frekans(char karakter)
{
	ifstream oku("tablo.txt");

	char k;
	string s;

	while (!oku.eof())
	{
		oku >> k >> s;
		if (k == karakter)
			return s;
	}
	oku.close();
	return "";
} 

string Islem::DeneOku()
{
	ifstream oku("dene.txt");
	ofstream Okuuu;
	Okuuu.open("lib\\string.txt",ios::app);
	
	char a[200];
	string islem_string = "";
	while (!oku.eof())
	{
		oku.getline(a, 200);
		for (int i = 0; a[i] != '\0'; i++)
		{
			if (a[i] == ' ')
			{
				islem_string += frekans('@');
				Okuuu<<frekans('@');
			}
			else if (a[i] == '\n')
			{
				islem_string += frekans('>');
				Okuuu<<frekans('>');
			}
			else
			{
				islem_string += frekans(a[i]); //frekans fonksiyonu karakterin frekansını dondurecek
				Okuuu<<frekans(a[i]);
			}
		}
		islem_string += frekans('\n');

	}
	islem_string += "2"; //stringin bittigini bu sekilde anlayacagiz
	/*fstream a;
	a.open("lib/string.txt");
	a<<islem_string;
	Dosya.open("lib/string.txt");
	remove("lib/gecici.txt");*/
	Okuuu.close();
	return islem_string;
}

void Islem::BinaryKaydet()
{
	ofstream Dat;
	Dat.open("Bit.dat");

	string islenecek = DeneOku();

	int aradeger = 0;

	for (int i = 0; islenecek[i] != '2'; i++)
	{
		string gecici = "";

		for (int j = 0; j < 7; j++)
		{
			if (islenecek.length() < 7 && islenecek.length()  ==  j - 1) //gelen boyut 7 bitten kucukse konrole gerek kalmadan
				break;
			
			gecici += islenecek[j];
		}
		
		Dat << (char)Donustur(gecici);

		
		if (islenecek.length() >= 7)
		{
			int deger = islenecek.length() - 7;
			islenecek = islenecek.substr(7, deger);
		}
		else
			Dat << islenecek;

	}

	Dat.close();
}




bool Islem::Oku(string ara)
{
	ifstream frekans;
	frekans.open("tablo.txt");

	char fokunacak;
	string fbinary = "";

	while (!frekans.eof())
	{
		frekans >> fokunacak >> fbinary;
		if (ara == fbinary)
		{
			ara = "";
			if (fokunacak == '@')
				cout << " ";
			else if (fokunacak == '>')
				cout << endl;
			else 
			cout << fokunacak;
			return true;
		}
	}

	frekans.close();
	return false;
}

string Islem::tersCevir(string n)
{
	//gelen stringi tersten yazdirmak icin yazilan fonksiyon
	//ihtiyac nedeni binarye cevirme algoritmamızın degeri ters yazıyor olmasi
	
	reverse(n.begin(),n.end());


	//olusan yeni stringi geri dondurduk	
	return n;
}

string Islem::decimalToBinary(int num)
{
	//decimal olarak gelem sayinin binary karsiligini buluyoruz
	//orn 42 olarak gelen sayi 101010 olarak geri donmesi gerekir
	string s = "";
	string g = "";
	while (num > 0)
	{
		int total = 0;
		total = num % 2;
		num /= 2;
		//string ile int degerlerini birlestirme islemi
		stringstream convert;
		convert << total;
		g = convert.str();
		s += g;
	}

	return tersCevir(s);
}

int Islem::stringToInt(string n)
{
	//strini integere cevirme fonksiyonu deger olarak geri donen degerin basinda 0 eksik olabilir
	//kontrol fonksiyonunda kontrol edilecektir.

	//c dili kutuphanelirnden atoi methodu ile stringi int degere donusturduk
	//stringin basindaki 0 degerlerinden dolayi veri kaybimiz olabilir
	//Orn: 00110101 8 bitlik bu string deger integere cevrilirken bastaki 2 adet 0 integere 
	//dahil edilmez bu da veri kaybina neden olur bunu kontrol fonksiyonunda kontrol edecegiz
	int sayi = atoi(n.c_str());
	return sayi;
	
}

string Islem::kontrol(string deger)
{
	//dosyaya sıkıstırma yaparken verileri 8 bit 8 bit okudugumuz icin int donusumunde 
	//basdaki 0 larda veri kaybini kontol edip ona gore basa sıfır ekliyoruz
	if (deger.length() < 7)
	{
		string ara_deger = "";
		for (int i = 0; i < 7 - deger.length(); i++)
			ara_deger += "0";

		ara_deger += deger;
		
		return ara_deger;

	}return deger;
}

void Islem::datToBinary()
{
	//dat dosyasi aciliyor
	ifstream Oku;
	ofstream Yaz;
	Oku.open("Bit.dat");
	Yaz.open("gecici.txt", ios::app);

	char okunan;
	
	while (!Oku.eof())
	{
		Oku >> okunan;
		
		//karakterin binary karsiligielde edildi dosyaya yazilmaya hazir veri kaybi olmadan
		Yaz << kontrol(decimalToBinary((int)okunan));
	}

	Oku.close();
	Yaz.close();

}

void Islem::Yazdir()
{
	datToBinary();


	
	ifstream Dosya;
	Dosya.open("lib\\string.txt");

	char Okunan;
	string ara = "";

	while (!Dosya.eof())
	{
		Dosya >> Okunan;
		ara += Okunan;
		
		if (Oku(ara))
			ara = "";
		
	}
	Dosya.close();	
			
	remove("lib\\string.txt");
	remove("gecici.txt");

}

