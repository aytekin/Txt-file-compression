/**
* @file Huffman.hpp
* @description Huffman algoritmasi kullanarak bir metin dosyasının boyutunu daraltmak
* @course 2.öğretin B grubu
* @assignment 04
* @date 27.12.2017
* @author Aytekin Erlale - Ahmet Özdilli / aytekin.erlale@ogr.sakarya.edu.tr - ahmet.ozdilli@ogr.sakarya.edu.tr 
*/

#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <fstream>
#include <cstring>

#include "Dugum.hpp"

class Huffman{
	private:
		int harfler;  			// harflerin ASCII karşılıkları
		string girdi;			// dosyadan okunan girdi
		Dugum *root;
				
		Dugum* AgacOlustur(int frek[]);
		void KodOlustur(Dugum*,string);
		int MinDugumIndeks(Dugum* dugumler[]);
		void DosyaOku(string)throw(string);
		void inorder(Dugum*);
		void SilDugum(Dugum*);
		void TabloYaz(char,string);
			
	public:
		Huffman(string)throw(string);
		void Kodla();
		friend ostream& operator<<(ostream&,Huffman&);
		~Huffman();
};


#endif