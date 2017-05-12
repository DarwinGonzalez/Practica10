
//Seguridad en Sistemas Informáticos

//Práctica 1: Algoritmo de Cifrado de Vernam
//AUTOR: Darwin González Suárez
//Seguridad en Sistemas Informáticos
//Archivo donde se implementan los métodos de la clase necesaria para la práctica

#include "vigenerealgorithm.hpp"
#include <string>
#include <stdlib.h>
#include <stdio.h>


using namespace std;


	void vigenerealgorithm::vigenerealgorithm_encrypt (string messag) {

	string abecedario = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string messagencrypt, messagencrypt2, aux, aux2, key;
	int i=0, j=0, z=0,y=0, move=0, rotation=0, total=0, cnt=0;
	size_t pos, pos2, pos3;


  cout<<"Introduce la clave:   ";
  getline(cin,key);
  cout << endl;

  cout << "___________________________________________________________"<<endl;
  cout << "MENSAJE A CIFRAR: "<< messag << endl;
	cout << "CLAVE:            "<< key << endl;
	int x=key.length()-1;


	 	//Bucle while que borra los espacios del mensaje.
		while((pos3 = messag.find(' ')) != string::npos){
			messag.erase(pos3, 1);
		}


		//Bucle while que repite la clave tantas veces como longitud tiene el mensaje sin espacios.
		while (messag.length() != key.length()){
			key=key + key.at(j);
			j++;
		}


	/*
	--- Bucle for que realiza la sustitucion de caracteres.
	--- Se busca en nuestro abecesadario la posicón de las letras del mensaje y la clave.
	--- Dichas posiciones se suman para obtener el dezplazamiento.
	--- Se añada la letra del abecedario que corresponde a dicha posicion en el string final.
	*/
		for(i=0,rotation=0; i<messag.length(); i++,rotation++) {
			pos = abecedario.find(messag.at(i));
			pos2 = abecedario.find(key.at(rotation));
			total = ((int)(pos+pos2));

			if(total > abecedario.length()) {
				move = total-abecedario.length();
				move= move%abecedario.length();
			}else{
				move = total%abecedario.length();
			}

			messagencrypt.append(abecedario,move,1);

				if(rotation==key.length())
					rotation=0;
		}

		cout << "MENSAJE CIFRADO:  "<< messagencrypt << endl;
		cout << "___________________________________________________________"<< endl<< endl;
	   	cout << endl << endl;
	}



	void vigenerealgorithm::vigenerealgorithm_decrypt (string messag){

	string abecedario = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string messagdecrypt, aux, key;
	int i=0, j=0, move=0, rotation=0, total=0;
	size_t pos, pos2, pos3;

    cout<<"Introduce la clave:   ";
    getline(cin,key);
    cout << endl;

    cout << "___________________________________________________________"<<endl;
    cout << "MENSAJE A DESCIFRAR: "<< messag << endl;
		cout << "CLAVE:               "<< key << endl;

		//Elimina los posibles espacios en blanco que pueda haber en el mensaje a encriptar
		while((pos3 = messag.find(' ')) != string::npos){
			messag.erase(pos3, 1);
		}

		//Repite la clave tantas veces como sea necesaria para el cifrado dependiendo de la longitud del mensaje
		while (messag.length() != key.length()){
			key=key + key.at(j);
			j++;
		}

		for(i=0,rotation=0; i<messag.length(); i++,rotation++) {
			pos = abecedario.find(messag.at(i));
			pos2 = abecedario.find(key.at(rotation));
			total = ((int)(pos-pos2));

			if(total < 0) {
				move = total+abecedario.length();
				move= move%abecedario.length();
			}else{
				move = total%abecedario.length();
			}

			messagdecrypt.append(abecedario,move,1);

				if(rotation==key.length())
					rotation=0;
		}



		cout << "MENSAJE DESCIFRADO:  "<< messagdecrypt << endl;
		cout << "___________________________________________________________"<< endl<< endl;
	   	cout << endl << endl;

	}

	void vigenerealgorithm::vigenerealgorithm_encrypt_MOD1 (string messag) {

	string abecedario = "ABCDEFGHIJKLMNOPQRSTUVWXYZ¿?_*";
	string messagencrypt, messagencrypt2, aux, aux2, key;
	int i=0, j=0, z=0,y=0, move=0, rotation=0, total=0, cnt=0;
	size_t pos, pos2, pos3;


	cout<<"Introduce la clave:   ";
	getline(cin,key);
	cout << endl;

	cout << "___________________________________________________________"<<endl;
	cout << "MENSAJE A CIFRAR: "<< messag << endl;
	cout << "CLAVE:            "<< key << endl;
	int x=key.length()-1;


		//Bucle while que borra los espacios del mensaje.
		while((pos3 = messag.find(' ')) != string::npos){
			messag.erase(pos3, 1);
		}


		//Bucle while que repite la clave tantas veces como longitud tiene el mensaje sin espacios.
		while (messag.length() != key.length()){
			key=key + key.at(j);
			j++;
		}


	/*
	--- Bucle for que realiza la sustitucion de caracteres.
	--- Se busca en nuestro abecesadario la posicón de las letras del mensaje y la clave.
	--- Dichas posiciones se suman para obtener el dezplazamiento.
	--- Se añada la letra del abecedario que corresponde a dicha posicion en el string final.
	*/
		for(i=0,rotation=0; i<messag.length(); i++,rotation++) {
			pos = abecedario.find(messag.at(i));
			pos2 = abecedario.find(key.at(rotation));
			total = ((int)(pos+pos2));

			if(total > abecedario.length()) {
				move = total-abecedario.length();
				move= move%abecedario.length();
			}else{
				move = total%abecedario.length();
			}

			messagencrypt.append(abecedario,move,1);

				if(rotation==key.length())
					rotation=0;
		}

		cout << "MENSAJE CIFRADO:  "<< messagencrypt << endl;
		cout << "___________________________________________________________"<< endl<< endl;
			cout << endl << endl;
	}

	void vigenerealgorithm::vigenerealgorithm_encrypt_MOD2 (string messag) {

	string abecedario = "*_?¿ZYXWVUTSRQPONMLKJIHGFEDCBA";
	string messagencrypt, messagencrypt2, aux, aux2, key;
	int i=0, j=0, z=0,y=0, move=0, rotation=0, total=0, cnt=0;
	size_t pos, pos2, pos3;


	cout<<"Introduce la clave:   ";
	getline(cin,key);
	cout << endl;

	cout << "___________________________________________________________"<<endl;
	cout << "MENSAJE A CIFRAR: "<< messag << endl;
	cout << "CLAVE:            "<< key << endl;
	int x=key.length()-1;


		//Bucle while que borra los espacios del mensaje.
		while((pos3 = messag.find(' ')) != string::npos){
			messag.erase(pos3, 1);
		}


		//Bucle while que repite la clave tantas veces como longitud tiene el mensaje sin espacios.
		while (messag.length() != key.length()){
			key=key + key.at(j);
			j++;
		}


	/*
	--- Bucle for que realiza la sustitucion de caracteres.
	--- Se busca en nuestro abecesadario la posicón de las letras del mensaje y la clave.
	--- Dichas posiciones se suman para obtener el dezplazamiento.
	--- Se añada la letra del abecedario que corresponde a dicha posicion en el string final.
	*/
		for(i=0,rotation=0; i<messag.length(); i++,rotation++) {
			pos = abecedario.find(messag.at(i));
			pos2 = abecedario.find(key.at(rotation));
			total = ((int)(pos+pos2));

			if(total > abecedario.length()) {
				move = total-abecedario.length();
				move= move%abecedario.length();
			}else{
				move = total%abecedario.length();
			}

			messagencrypt.append(abecedario,move,1);

				if(rotation==key.length())
					rotation=0;
		}

		cout << "MENSAJE CIFRADO:  "<< messagencrypt << endl;
		cout << "___________________________________________________________"<< endl<< endl;
			cout << endl << endl;
	}

	void vigenerealgorithm::vigenerealgorithm_decrypt_MOD21 (string messag){

	string abecedario = "*_?¿ZYXWVUTSRQPONMLKJIHGFEDCBA";
	string messagdecrypt, aux, key;
	int i=0, j=0, move=0, rotation=0, total=0;
	size_t pos, pos2, pos3;

		cout<<"Introduce la clave:   ";
		getline(cin,key);
		cout << endl;

		cout << "___________________________________________________________"<<endl;
		cout << "MENSAJE A DESCIFRAR: "<< messag << endl;
		cout << "CLAVE:               "<< key << endl;

		//Elimina los posibles espacios en blanco que pueda haber en el mensaje a encriptar
		while((pos3 = messag.find(' ')) != string::npos){
			messag.erase(pos3, 1);
		}

		//Repite la clave tantas veces como sea necesaria para el cifrado dependiendo de la longitud del mensaje
		while (messag.length() != key.length()){
			key=key + key.at(j);
			j++;
		}

		for(i=0,rotation=0; i<messag.length(); i++,rotation++) {
			pos = abecedario.find(messag.at(i));
			pos2 = abecedario.find(key.at(rotation));
			total = ((int)(pos-pos2));

			if(total < 0) {
				move = total+abecedario.length();
				move= move%abecedario.length();
			}else{
				move = total%abecedario.length();
			}

			messagdecrypt.append(abecedario,move,1);

				if(rotation==key.length())
					rotation=0;
		}



		cout << "MENSAJE DESCIFRADO:  "<< messagdecrypt << endl;
		cout << "___________________________________________________________"<< endl<< endl;
			cout << endl << endl;

	}
