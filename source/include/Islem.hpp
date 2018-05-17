#ifndef ISLEM_HPP
#define ISLEM_HPP
/**
* @file Islem.hpp
* @description Huffman algoritmasi kullanarak bir metin dosyasının boyutunu daraltmak
* @course 2.öğretin B grubu
* @assignment 04
* @date 27.12.2017
* @author Aytekin Erlale - Ahmet Özdilli / aytekin.erlale@ogr.sakarya.edu.tr - ahmet.ozdilli@ogr.sakarya.edu.tr 
*/
#include <iostream>
#include <fstream>
#include <string> 
#include<sstream>
#include <cmath>
#include <stdio.h>      
#include <stdlib.h> 

using namespace std;


class Islem{
	private:
		int Donustur(string); //string 10101 gibi degerleri integer degere donusturur
		string frekans(char);
		string DeneOku(); 
		string tersCevir(string);
		string decimalToBinary(int);
		int stringToInt(string n);
		string kontrol(string);
		void datToBinary();
		bool Oku(string);
		
	public:
		void BinaryKaydet(); //gelen 10101 gibi degerleri 8 bitlik birlestirip 1 karakter olarak yazar
		void Yazdir();
};


#endif