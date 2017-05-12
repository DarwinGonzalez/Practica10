//"PRACTICA 10: SEGURIDAD EN SISTEMAS INFORMÁTICOS

//Práctica 10: Practicas de seguridad formato menú
//AUTOR: Darwin González Suárez
//Archivo principal o mainma

#include <iostream>
#include "CifradoVernam/vernamalgorithm.hpp"
#include "CifradoVigenere/vigenerealgorithm.hpp"
#include "CifradoRC4/RC4.hpp"
#include "CifradoA51/A5_1.hpp"
#include "CifradoDH/diffiehellman.hpp"
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

          case 3:{

            system("clear");
          	std::vector<unsigned char> semilla(2,0);
          	semilla[0]=2;
          	semilla[1]=5;

          	std::vector<unsigned char> msg(2, 0);
          	msg[0]=1;
          	msg[1]=34;
          	std::vector<unsigned char> msg_cifrado(2,0);
          	std::vector<unsigned char> secuencia_cifrado;

          	rc4 A(semilla);
          	msg_cifrado = A.cifrar(msg);

          	cout << "Práctica 3: Algoritmo de Cifrado RC4 - Seguridad en Sistemas Informáticos"<<endl;
          	cout << "====================" << endl;

          	cout << "El mensaje original es: ";
          	for (int i=0;i<msg.size();i++)
          	{
          		if (i==msg.size()-1)
          			cout << int(msg[i]);
          		else
          			cout << int(msg[i]) << ", ";
          	}

          	cout << endl << "La semilla es: ";
          	for (int i=0;i<semilla.size();i++)
          	{
          		if (i==semilla.size()-1)
          			cout << int(semilla[i]);
          		else
          			cout << int(semilla[i]) << ", ";
          	}
          	secuencia_cifrado=A.secuencia();

          	cout << endl << "La clave de cifrado es: ";
          	for (int i=0;i<secuencia_cifrado.size();i++)
          	{
          		if (i==secuencia_cifrado.size()-1)
          			cout << int(secuencia_cifrado[i]);
          		else
          			cout << int(secuencia_cifrado[i]) << ", ";
          	}

          	cout << endl << "El mensaje cifrado es: ";
          	for (int i=0;i<msg_cifrado.size();i++)
          	{
          		if (i==msg_cifrado.size()-1)
          			cout << int(msg_cifrado[i]);
          		else
          			cout << int(msg_cifrado[i]) << ", ";
          	}

          	cout << endl << "====================" << endl;


          	rc4 C(semilla);
          	cout << "====================" << endl;
          	cout << "MODIFICACIÓN SPRITZ" << endl;

          	std::vector<unsigned char> msg_2(2, 0);
          	msg_2[0]=1;
          	msg_2[1]=34;

          	std::vector<unsigned char> msg_cifrado_2(2,0);
          	std::vector<unsigned char> secuencia_cifrado2;
          	msg_cifrado_2 = C.cifrar_mod(msg_2);

          	cout << "El mensaje original es: ";
          	for (int i=0;i<msg_2.size();i++)
          	{
          		if (i==msg_2.size()-1)
          			cout << int(msg_2[i]);
          		else
          			cout << int(msg_2[i]) << ", ";
          	}

          	cout << endl << "La semilla es: ";
          	for (int i=0;i<semilla.size();i++)
          	{
          		if (i==semilla.size()-1)
          			cout << int(semilla[i]);
          		else
          			cout << int(semilla[i]) << ", ";
          	}

          	secuencia_cifrado2=C.secuencia();

          	cout << endl << "La clave de cifrado es: ";
          	for (int i=0;i<secuencia_cifrado2.size();i++)
          	{
          		if (i==secuencia_cifrado2.size()-1)
          			cout << int(secuencia_cifrado2[i]);
          		else
          			cout << int(secuencia_cifrado2[i]) << ", ";
          	}

          	cout << endl <<"El mensaje cifrado es: ";
          	for (int i=0;i<msg_cifrado_2.size();i++){
          		if (i==msg_cifrado_2.size()-1)
          			cout << int(msg_cifrado_2[i]);
          		else
          			cout << int(msg_cifrado_2[i]) << ", ";
          	}

          	cout << endl << "====================" << endl;
          }

          break;

          case 4:{

            A5_1algoritmo A5_1;
            int selection;
            string message;
            system("clear");

            do{
                cout<<"______________________________________________________"<<endl;
                cout<<"Práctica 4 SEGURIDAD EN SISTEMAS INFORMÁTICOSI: A5/1"<<endl;
                cout<<"______________________________________________________"<<endl;
                cout<<"[1]. Encriptación aplicando el algoritmo A5/1"<<endl;
                cout<<"[2]. Encriptación aplicando el algoritmo A5/1(con modificación)"<<endl;
                cout<<"[0]. Finalizar el programa.                "<<endl;
                cout<<"______________________________________________________"<<endl;
                cout << endl;
                cout << "OPCIÓN >> :";
                cin >> selection;
                getchar();

                switch(selection) {

                    case 1:
                        system ("clear");
                        cout<<"Introduzca el mensaje a encriptar: "<<endl;
                        getline (cin,message);
                        A5_1.A5_1encriptar(message);
                        cout << endl << endl << endl;
                        break;

                    case 2:
                        system ("clear");
                        cout<<"Introduzca el mensaje a encriptar: "<<endl;
                        getline (cin,message);
                        A5_1.A5_1encriptar_mod(message);
                        cout << endl << endl << endl;
                        break;

                }

            }while(selection);
          }

          break;

          case 5:

          break;

          case 6:{

            DiffieHellman DH;
            long selection, usuarios, alpha,p;
            string message;
            system("clear");

            do{
                cout<<" ___________________________________________ "<<endl;
                cout<<"|      Práctica 6 SSI: DIFFIE-HELLMAN      |"<<endl;
                cout<<" -------------------------------------------"<<endl;
                cout<<"[1]. INTERCAMBIO DE CLAVES.(2 personas)     |"<<endl;
                cout<<"[2]. INTERCAMBIO DE CLAVES.(3 personas)     |"<<endl;
                cout<<"[3]. INTERCAMBIO DE CLAVES.(n personas)     |"<<endl;
                cout<<"[0]. Finalizar el programa.                 |"<<endl;
                cout<<"____________________________________________"<<endl;
                cout << endl;
                cout << "INTRODUZCA LA OPCIÓN DESEADA:";
                cin >> selection;
                getchar();

                switch(selection) {

                    case 1:
                        usuarios = 2;
                        cout << "Introduce un número primo p: ";   cin >> p;
                        cout << "Introduce el valor alpha menor que p: "; cin >> alpha;

                        system ("clear");
                        DH.DiffieHellman_algorithm(p, alpha, usuarios);
                        cout << endl << endl << endl;

                        break;


                    case 2:
                        usuarios = 3;
                        cout << "Introduce un número primo p: ";   cin >> p;
                        cout << "Introduce el valor alpha menor que p: "; cin >> alpha;

                        system ("clear");
                        DH.DiffieHellman_algorithm_mod(p, alpha, usuarios);
                        cout << endl << endl << endl;

                    break;

                    case 3:
                        cout << "Introduzca el numero de usuarios: ";   cin >> usuarios;
                        cout << "Introduce un número primo p: ";   cin >> p;
                        cout << "Introduce el valor alpha menor que p: "; cin >> alpha;

                        system ("clear");
                        DH.DiffieHellman_algorithm_mod2(p, alpha, usuarios);
                        cout << endl << endl << endl;

                    break;


                }

            }while(selection);
          }

          break;

          case 7:{

            system("clear");
            int p,s,q,N,it,A,y,Ant;
            int V;
            cout <<"--------------------------------------------------------------------"<<endl;
            cout <<" SEGURIDAD SISTEMAS INFORMATICOS"<<endl;
            cout <<"--------------------------------------------------------------------"<<endl;
            cout <<" Práctica 7: Algoritmo de Fiat-Shamir "<<endl;
            cout <<"--------------------------------------------------------------------"<<endl;
            cout<<"Introducir el valor p :";
            cin >> p;
            cout<<"Introducir el valor q :";
            cin >> q;
            cout<<"Introducir el valor s :";
            cin >> s;

            N=p * q;
            V=(s * s) % N;
            cout<<"Introducir el numero de iteraciones :";
            cin >> it;

            int x[it];
            int e[it];

            for(int i=1;i <= it;i++){

              if(i==1){
                cout<<"Introducir el valor x :";
                cin >> x[i];

                cout<<"Introducir el valor e :";
                cin >> e[i];

                A=(x[i] * x[i])% N;
                Ant = (A) % N;

                if(e[i] == 0)
                {
                  y = x[i] % N;
                  cout << "A: " << Ant << endl;
                  cout << "Y: " << y << endl;
                  cout <<"Comprobamos que Y al cuadrado modulo N es: " << (A) % N <<endl;
                  cout <<"Comprobamos que " << (y * y) % N  << "=" << (A) % N <<endl;
                }

                else {
                  y = (x[i] * s) % N;
                  Ant = (y * y) % N;
                  cout << "A: " << Ant<<endl;
                  cout << "Y: " << y<<endl;
                  cout <<"Comprobamos que " << (y * y) % N << "=" << (A * V) % N <<endl;
                }

              }

              else {

                cout<<"Introducir el valor e :";
                cin >> e[i];

                A = (Ant * Ant) % N;
                cout << "a: " << A <<endl;

                if(e[i] == 0)
                {
                  y = Ant % N;
                  Ant = (y * y) % N;

                  cout << "A: " << Ant<<endl;
                  cout << "Y: " << y<<endl;

                  cout <<"Comprobamos que Y al cuadrado modilo N es: " << (A) % N <<endl;
                  cout <<"Comprobamos que " << (y * y) % N  << "=" << (A) % N <<endl;
                }

                else {
                  y = (Ant * s) % N;
                  Ant = (y * y) % N;

                  cout << "A: " << Ant<<endl;
                  cout << "Y: " << y<<endl;

                  cout <<"Comprobamos que " << (y * y) % N << "=" << (A * V) % N <<endl;
                }

              }

            }
          }

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
