//Seguridad en Sistemas Informaticos (SSI)

//Práctica 7: Diffie-Hellman
//AUTOR: Darwin González Suárez
//Archivo donde se declaran los metodos y atributos necesarios para el funcionamiento de la clase DiffieHellman

#ifndef diffiehellman_hpp
#define diffiehellman_hpp

#include <cstdio>
#include <stdio.h>
#include <string>
#include <iostream>

#endif /* diffiehellman_hpp */


using namespace std;


class DiffieHellman {

private:
    long aux;


public:
    DiffieHellman();
    void DiffieHellman_algorithm(long p, long alpha, long usuarios);
    void DiffieHellman_algorithm_mod(long p, long alpha, long usuarios);
    void DiffieHellman_algorithm_mod2(long p, long alpha, long usuarios);
    long exponenciacion(long alpha, long x, long p);

};
