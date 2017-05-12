
//Seguridad en Sistemas Informáticos

//Práctica 1: Algoritmo de Cifrado de Vernam
//AUTOR: Darwin González Suárez
//Seguridad en Sistemas Informáticos
//Archivo donde se declaran los métodos de la clase necesaria para la práctica

#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <bitset>


using namespace std;


	class vigenerealgorithm {


//=======================================================================================
//  DEFINICIÓN DE MÉTODOS
//=======================================================================================

	private:

    public:

/**
    \Función encripta según el cifrado de Vernam
    \Se le pasa el mensaje a encriptar.
*/
		void vigenerealgorithm_encrypt (string messag);


/**
    \Función que desencripta según el cifrado de Vernam
    \Se le pasa el mensaje a encriptar.
*/
		void vigenerealgorithm_decrypt (string messag);


/**
		 \Función encripta según el cifrado de Vernam
		 \Se le pasa el mensaje a encriptar.
		 \Al alfabeto se le ha añadido los simbolos ?¿_*
*/
		void vigenerealgorithm_encrypt_MOD1 (string messag);


/**
		 \Función encripta según el cifrado de Vernam
		 \Se le pasa el mensaje a encriptar.
		 \El alfabeto se le ha cambiado el orden a la inversa
*/
		void vigenerealgorithm_encrypt_MOD2 (string messag);


/**
			\Función encripta según el cifrado de Vernam
			\Se le pasa el mensaje a encriptar.
			\El alfabeto se le ha cambiado el orden a la inversa
*/
		void vigenerealgorithm_decrypt_MOD21 (string messag);


	};
