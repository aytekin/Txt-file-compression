/**
* @file test.cpp
* @description Huffman algoritmasi kullanarak bir metin dosyasının boyutunu daraltmak
* @course 2.öğretin B grubu
* @assignment 04
* @date 27.12.2017
* @author Aytekin Erlale - Ahmet Özdilli / aytekin.erlale@ogr.sakarya.edu.tr - ahmet.ozdilli@ogr.sakarya.edu.tr 
*/
#include "Huffman.hpp"
#include "Islem.hpp"
int main(){
	
	setlocale(LC_ALL, "turkish");
	
	Huffman *huffman = new Huffman("dene.txt");
	Islem *islem = new Islem();
	huffman->Kodla();
	cout<<*huffman;
	

	
	int secim = 3;
	while(secim == 1 || secim == 2 || secim == 3)
	{
		system("cls");
		cout<<"1- DOSYAYI SIKISTIR\n";
		cout<<"2- SIKISTIRILMIS DOSYAYI AC\n";
		cout<<">>>";
		cin>>secim;
		
		if(secim == 1)
		{
			islem->BinaryKaydet();
			cout<<"islem 1 gerceklesmistir\n";
			system("pause");
		}
		if(secim == 2)
		{
			islem->Yazdir();
			cout<<"\n\nislem 2 gerceklesmistir\n";
			system("pause");
		}
	
	}
	
	
	delete huffman;
	return 0;
}