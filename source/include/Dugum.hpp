/**
* @file Dugum.hpp
* @description Huffman algoritmasi kullanarak bir metin dosyasýnýn boyutunu daraltmak
* @course 2.öðretin B grubu
* @assignment 04
* @date 27.12.2017
* @author Aytekin Erlale - Ahmet Özdilli / aytekin.erlale@ogr.sakarya.edu.tr - ahmet.ozdilli@ogr.sakarya.edu.tr 
*/
#ifndef DUGUM_HPP
#define DUGUM_HPP

#include <iostream>
using namespace std;

class Dugum{
	public:
		char karakter;
		int frekans;	// Dosyada kaç kez tekrarlandýðý
		string kod; 	// 01 kod karþýlýðý
		Dugum* sol;
		Dugum* sag;
		Dugum(char kr,int frek, Dugum* sl=NULL,Dugum *sg=NULL);
		bool Yaprakmi() const;
		bool operator==(Dugum&);
		bool operator!=(Dugum&);
		bool operator>(Dugum&);
};


#endif