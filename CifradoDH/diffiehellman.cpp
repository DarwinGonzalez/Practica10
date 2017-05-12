//Seguridad en Sistemas Informaticos (SSI)

//Práctica 7: Diffie-Hellman
//AUTOR: Darwin González Suárez
//Archivo donde se implementan los metodos y atributos necesarios para el funcionamiento de la clase DiffieHellman


#include "diffiehellman.hpp"
#include <math.h>

DiffieHellman::DiffieHellman():
    aux(NULL)
{}

//---------------------------------------------------------------------------------------------------------------------
void DiffieHellman::DiffieHellman_algorithm(long p, long alpha, long usuarios){
    long  x[100], y[100], k;
    cout << endl;

    for (long i=0; i<usuarios; i++) {
        cout << "Introduce el valor secreto del usuario " << i+1 << ": "; cin >> x[i];
    }


    cout << endl << endl << "VALORES INTRODUCIDOS: ";
    cout << endl << "_________________________";

    for (long i=0; i<usuarios; i++) {
        cout << endl << "VALOR  SECRETO USER "<< i+1 << ": " << x[i];
        cout << endl << "NÚMERO PRIMO    p: " << p;
        cout << endl << "VALOR  ALPHA <  p: " << alpha;
        cout << endl;
    }

    cout << endl << endl << endl << "INTERCAMBIO DE CLAVES: ";
    cout << endl << "___________________________________________" << endl;

 for (long i=0; i<usuarios; i++) {
    y[i] = exponenciacion(alpha,x[i],p);
    cout << endl << "USER "<< i+1 << " y: " << y[i];
 }

    k = exponenciacion(y[1],x[0],p);
    cout << endl << "CLAVE  k: " << k;

}

//---------------------------------------------------------------------------------------------------------------------//
void DiffieHellman::DiffieHellman_algorithm_mod(long p, long alpha, long usuarios){
    long  x[100], y[100],z[100], k;
    cout << endl;

    for (long i=0; i<usuarios; i++) {
        cout << "Introduce el valor secreto del usuario " << i+1 << ": "; cin >> x[i];
    }


    cout << endl << endl << "VALORES INTRODUCIDOS: ";
    cout << endl << "_________________________";

    for (long i=0; i<usuarios; i++) {
        cout << endl << "VALOR  SECRETO USER "<< i+1 << ": " << x[i];
        cout << endl << "NÚMERO PRIMO    p: " << p;
        cout << endl << "VALOR  ALPHA <  p: " << alpha;
        cout << endl;
    }

    cout << endl << endl << endl << "INTERCAMBIO DE CLAVES: ";
    cout << endl << "___________________________________________" << endl;

 for (long i=0; i<usuarios; i++) {
    y[i] = exponenciacion(alpha,x[i],p);
    cout << endl << "USER "<< i+1 << " y: " << y[i];
 }

    z[0] = exponenciacion(y[2],x[0],p);
    cout << endl << "Z 1: " << z[0];

    z[1] = exponenciacion(y[0],x[1],p);
    cout << endl << "Z 2: " << z[1];

    z[2] = exponenciacion(y[1],x[2],p);
    cout << endl << "Z 3: " << z[2];

    k = exponenciacion(z[2],x[0],p);
    cout << endl << "k : " << k;

    k = exponenciacion(z[0],x[1],p);
    cout << endl << "k : " << k;

    k = exponenciacion(z[1],x[2],p);
    cout << endl << "k : " << k;

}

//---------------------------------------------------------------------------------------------------------------------//
void DiffieHellman::DiffieHellman_algorithm_mod2(long p, long alpha, long usuarios){
    long  x[100], y[100],z[100],k;
    int  K;
    cout << endl;

    for (long i=0; i<usuarios; i++) {
        cout << "Introduce el valor secreto del usuario " << i+1 << ": "; cin >> x[i];
    }


    cout << endl << endl << "VALORES INTRODUCIDOS: ";
    cout << endl << "_________________________";

    for (long i=0; i<usuarios; i++) {
        cout << endl << "VALOR  SECRETO USER "<< i+1 << ": " << x[i];
        cout << endl << "NÚMERO PRIMO    p: " << p;
        cout << endl << "VALOR  ALPHA <  p: " << alpha;
        cout << endl;
    }

    cout << endl << endl << endl << "INTERCAMBIO DE CLAVES: ";
    cout << endl << "___________________________________________" << endl;

 for (long i=0; i<usuarios; i++) {
    y[i] = exponenciacion(alpha,x[i],p);
    cout << endl << "y0: " << y[i];
 }

 for (long i=0; i<usuarios; i++) {
    z[i] = exponenciacion(y[(i+1)%usuarios],x[i],p);
    cout << endl << "y1 "<< i+1 << ": " << z[i];
  }

 for (long i=0; i<usuarios; i++) {
    k = exponenciacion(z[(i+1)%usuarios],x[i],p);
    cout << endl << "y2 : " << k;
  }

  for (long i=0; i<usuarios; i++) {
     K = exponenciacion(k,x[i],p);
     cout << endl << "k : " << K;
   }


}

//---------------------------------------------------------------------------------------------------------------------//


long DiffieHellman::exponenciacion(long alpha, long x, long p) {
    long ex = 1;

    while(x > 0) {

        if(x % 2 != 0) {
            ex = (ex * alpha) % p;
            x = x - 1;
        }

        else {
            alpha = (alpha * alpha) % p;
            x = x / 2;
        }
    }
    return ex;
}
