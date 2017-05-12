
//Seguridad en Sistemas Informáticos

//Práctica 1: Algoritmo de Cifrado de Vernam
//AUTOR: Darwin González Suárez
//Seguridad en Sistemas Informáticos
//Archivo donde se implementan los métodos de la clase necesaria para la práctica


#include "vernamalgorithm.hpp"
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sstream>
#include <bitset>


using namespace std;


	void vernamalgorithm::vernamalgorithm_encrypt (string messag, string binrandomkey){
		int randomkey;
		string aux1;

/*
--- El mensaje pasado se separa en caracteres.
--- Para cada caracter se muestra su transformación en int y en bitset.
*/
		    for (int i = 0; i < messag.length(); i++) {
        		char messagascii = messag.at(i);
        		cout << "_______________" << endl << char(messagascii) << endl << "----------------" << endl;
        		cout << "ASCII: " << int(messagascii) << endl;
        		cout << "BINARY: ";
      			cout << bitset<8> (messag.c_str()[i]) << endl;
    			cout << aux1;
    		}


/*
--- El mensaje por descifrar es pasado por el usuario y convertido en bitset para su impresión.
*/
    	cout << "___________________________________________________________";
    	cout << endl << "MENSAJE DESCIFRADO: ";
    		for (int i = 0; i < messag.length(); i++) {
    		cout << bitset<8> (messag.c_str()[i]);
			}
		cout << endl;


/*
--- De igual modo, se ha pedido en prácticas que la clave aleatoria es pasada por el usuario. Es convertida en bitset también.
*/
		cout << "CLAVE ALEATORIA:    ";
		    for (int i = 0; i < binrandomkey.length(); i++) {
    			cout << bitset<8> (binrandomkey.c_str()[i]);
			}
		cout << endl;


/*
--- Se descifra el mensaje realizando la operacion XOR.
*/
	    cout << "XOR:                ";
	    	for (int i = 0; i < binrandomkey.length(); i++) {
  				cout << (bitset<8> (binrandomkey.c_str()[i]) ^ bitset<8> (messag.c_str()[i]));
	    	}
	   	cout << endl;


/*
--- Se descifra el mensaje realizando la operacion XOR.
--- Se convvierte el bitset en int y de ahi a char para obtener el mensaje cifrado.
*/
	    bitset<8> aux2;
			bitset<8> aux4;
			int x;
			cout<< "¿Cuantas veces desea cifrar?(1 o 2 veces): ";
			cin>> x;

			if(x==2){
		cout <<"MENSAJE CIFRADO 2 veces:    ";
	    	for (int i = 0; i < binrandomkey.length(); i++) {
	    		aux2=((bitset<8> (binrandomkey.c_str()[i]) ^ bitset<8> (messag.c_str()[i])) ^ bitset<8> (binrandomkey.c_str()[i]));
				int aux3 = aux2.to_ulong();
				if ((aux3<=33) | (aux3>=126)) {
					cout << "@";
				}
				cout << char(aux3);

	    	}
			}

			else{
				cout <<"MENSAJE CIFRADO 1 vez:    ";
						for (int i = 0; i < binrandomkey.length(); i++) {
							aux2=(bitset<8> (binrandomkey.c_str()[i]) ^ bitset<8> (messag.c_str()[i]));
						int aux3 = aux2.to_ulong();
						if ((aux3<=33) | (aux3>=126)) {
							cout << "@";
						}
						cout << char(aux3);

						}
			}
	   	cout << endl;
		cout << endl << "___________________________________________________________"<< endl<< endl;
	   	cout << endl << endl;
	}



	void vernamalgorithm::vernamalgorithm_decrypt (string messagencrypt, string binrandomkey){

		int randomkey, i;
		string aux1;


		    for (int i = 0; i < messagencrypt.length(); i++) {
        		char messagascii = messagencrypt.at(i);
        		cout << "_______________" << endl << char(messagascii) << endl << "----------------" << endl;
        		cout << "ASCII: " << int(messagascii) << endl;
        		cout << "BINARY: ";
      			cout << bitset<8> (messagencrypt.c_str()[i]) << endl;
    			cout << aux1;
    		}

    	cout << "___________________________________________________________";
    	cout << endl << "MENSAJE CIFRADO:    ";
    		for (int i = 0; i < messagencrypt.length(); i++) {
    		cout << bitset<8> (messagencrypt.c_str()[i]);
			}
		cout << endl;


		cout << "CLAVE ALEATORIA:    ";
		    for (int i = 0; i < binrandomkey.length(); i++) {
    			cout << bitset<8> (binrandomkey.c_str()[i]);
			}
		cout << endl;


		cout << "XOR:                ";
	    	for (int i = 0; i < binrandomkey.length(); i++) {
  				cout << (bitset<8> (binrandomkey.c_str()[i]) ^ bitset<8> (messagencrypt.c_str()[i]));
	    	}
	   	cout << endl;


	    bitset<8> aux2;
		cout <<"MENSAJE DESCIFRADO: ";
	    	for (int i = 0; i < binrandomkey.length(); i++) {
	    		aux2=(bitset<8> (binrandomkey.c_str()[i]) ^ bitset<8> (messagencrypt.c_str()[i]));
				int aux3 = aux2.to_ulong();
				if ((aux3<=33) | (aux3>=126)) {
					cout << "@";
				}
				cout << char(aux3);

	    	}
	   	cout << endl;
		cout << endl << "___________________________________________________________"<< endl<< endl;
	   	cout << endl << endl;
	}
