/**
* @file Dugum.cpp
* @description Huffman algoritmasi kullanarak bir metin dosyasının boyutunu daraltmak
* @course 2.öğretin B grubu
* @assignment 04
* @date 27.12.2017
* @author Aytekin Erlale - Ahmet Özdilli / aytekin.erlale@ogr.sakarya.edu.tr - ahmet.ozdilli@ogr.sakarya.edu.tr 
*/
#include "Dugum.hpp"

		Dugum::Dugum(char kr,int frek, Dugum* sl,Dugum *sg){
			karakter=kr;
			frekans=frek;
			sol=sl;
			sag=sg;
			kod="";
		}
		bool Dugum::Yaprakmi() const{
			if(sol == NULL && sag == NULL) return true;
			return false;
		}
		bool Dugum::operator==(Dugum& sag){
			if(this->karakter == sag.karakter) return true;
			else return false;
		}
		bool Dugum::operator!=(Dugum& sag){
			if(this->karakter != sag.karakter) return true;
			else return false;
		}
		bool Dugum::operator>(Dugum& sag){
			if(this->frekans > sag.frekans) return true;
			else return false;
		}