//Algoritmos y estructuras de Datos Avanzados

//Práctica 10: Practicas de seguridad formato menú
//AUTOR: Darwin González Suárez
//Archivo principal o mainma

#include <iostream>
#include "CifradoVernam/vernamalgorithm.hpp"
#include "CifradoVigenere/vigenerealgorithm.hpp"
#include <string>
#include <bitset>
#include <cstdio>


using namespace std;

int main (void)
{
    system("clear");
    int opcion = 0;

    do
  	{
      cout << "\t\t ▶▶▶▶ SSI ◀◀◀◀" << endl;
    	cout <<"PRACTICA 10: SEGURIDAD EN SISTEMAS INFORMÁTICOS"<<endl;
      cout <<"--------------------------------------------------------------------"<<endl;
  		cout << "<< PRÁCTICAS >>" << endl;
      cout <<"--------------------------------------------------------------------"<<endl;
	    cout << "[1]. Práctica 1: Entrega Vernam" << endl;
	    cout << "[2]. Práctica 2: Entrega Vigenere" << endl;
	    cout << "[3]. Práctica 3: Entrega RC4"<< endl;
      cout << "[4]. Práctica 4: Entrega A5/1"<< endl;
      cout << "[5]. Práctica 5: Algoritmo Rijndael"<< endl;
      cout << "[6]. Práctica 6: Algoritmo de Diffie-Hellman"<< endl;
      cout << "[7]. Práctica 7: Algoritmo de Fiat-Shamir"<< endl;
      cout << "[8]. Práctica 8: Cifrado RSA"<< endl;
      cout <<"--------------------------------------------------------------------"<<endl;
	    cout << "Introduzca una opción >> ";
	    cin >> opcion;

        switch(opcion)
        {
          case 0:
	    	    exit(0);
	        break;

          case 1:{

            string message, randomkey1;
            int selection = 5;
            vernamalgorithm A;
            system ("clear");

            cout << "Práctica 1: SEGURIDAD EN SISTEMAS INFORMÁTICOS" <<endl;
            cout<<"--------------------------------------------"<<endl;
            cout<<"*___________-ALGORITMO DE VERNAM-__________*"<<endl;
            cout<<"--------------------------------------------"<<endl;
            cout<<"[1]. CIFRADO DE VERNAM."<<endl;
            cout<<"[2]. DESCIFRADO DE VERNAM."<<endl;
            cout<<"[0]. Finalizar el programa."<<endl;

            cout << endl;
            cout << "INTRODUZCA LA OPCIÓN DESEADA:";
            cin >> selection;

                switch(selection) {

                    case 1:
                        system ("clear");
                        cout<<"Introduce el mensaje que desea encriptar: "<<endl;
                        getline (cin,message);
                        cout<<"Introduce la clave aleatoria: "<<endl;
                        getline (cin,randomkey1);
                		    A.vernamalgorithm_encrypt (message, randomkey1);
                    break;

                    case 2:
                        system ("clear");
                        cout<<"Introduce el mensaje que desea desencriptar: "<<endl;
                        getline (cin,message);
                        cout<<"Introduce la clave aleatoria: "<<endl;
                        getline (cin,randomkey1);
                        A.vernamalgorithm_decrypt (message,randomkey1);
                    break;

                }
            }

          break;

          case 2:{

            string message, key;
          	int selection;
            vigenerealgorithm A;
          	system ("clear");
              do{

          	cout << "Práctica 2: SEGURIDAD EN SISTEMAS INFORMÁTICOS" <<endl;
            cout<<"--------------------------------------------"<<endl;
            cout<<"____________ALGORITMO DE VIGENERE___________"<<endl;
            cout<<"--------------------------------------------"<<endl;
            cout<<"[1]. CIFRADO DE VIGENERE."<<endl;
            cout<<"[2]. DESCIFRADO DE VIGENERE."<<endl;
          	cout<<"[3]. CIFRADO DE VIGENERE(¿?_*)."<<endl;
          	cout<<"[4]. CIFRADO DE VIGENERE(reverse)."<<endl;
          	cout<<"[5]. DESCIFRADO DE VIGENERE(reverse)."<<endl;
            cout<<"[0]. Finalizar el programa."<<endl;

            cout << endl;
            cout << "INTRODUZCA LA OPCIÓN DESEADA:";
            cin >> selection;
            getchar();

                  switch(selection) {

                      case 1:
                          system ("clear");
                          cout<<"Introduce el mensaje: ";
                          getline (cin,message);
                  				A.vigenerealgorithm_encrypt (message);
                      break;

                      case 2:
                          system ("clear");
                          cout<<"Introduce el mensaje que desea desencriptar: ";
                          getline (cin,message);
                          A.vigenerealgorithm_decrypt (message);
          						break;

          						case 3:
                          system ("clear");
                          cout<<"Introduce el mensaje: ";
                          getline (cin,message);
                  				A.vigenerealgorithm_encrypt_MOD1 (message);
                      break;

          						case 4:
          								system ("clear");
          								cout<<"Introduce el mensaje: ";
          								getline (cin,message);
          								A.vigenerealgorithm_encrypt_MOD2 (message);
          						break;

          						case 5:
          								system ("clear");
          								cout<<"Introduce el mensaje: ";
          								getline (cin,message);
          								A.vigenerealgorithm_decrypt_MOD21 (message);
          						break;

                  }
              }while(selection);

          }

	        break;

          case 3:

          break;

          case 4:

          break;

          case 5:

          break;

          case 6:

          break;

          case 7:

          break;

          case 8:

          break;

          default:
	      	    system("clear");
	            cout << "Opción incorrecta." << endl;
	        break;
	    }
	  }while(opcion!=-1);
}
