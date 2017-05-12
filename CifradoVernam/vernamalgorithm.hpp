
//Seguridad en Sistemas Informáticos

//Práctica 1: Algoritmo de Cifrado de Vernam
//AUTOR: Darwin González Suárez
//Seguridad en Sistemas Informáticos
//Archivo donde se declaran los métodos y la clase necesaria para la práctica


#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <bitset>


using namespace std;


	class vernamalgorithm {

	public:

/**
    \Función encripta según el cifrado de Vernam
    \Se le pasa el mensaje a encriptar.
*/
		void vernamalgorithm_encrypt (string messag, string binrandomkey);


/**
    \Función que desencripta según el cifrado de Vernam
    \Se le pasa el mensaje a encriptar.
*/
		void vernamalgorithm_decrypt (string messag, string binrandomkey);

	};
