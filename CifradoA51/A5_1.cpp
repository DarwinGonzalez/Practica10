
//Seguridad en Sistemas Informáticos

//Práctica 4: Algoritmo A5/1
//AUTOR: Darwin González Suárez
//Seguridad en Sistemas Informáticos
//Archivo donde se implementan los métodos de la clase necesaria para la práctica

#include "A5_1.hpp"


void A5_1algoritmo::A5_1encriptar(string messag){
    int aux = messag.length() * 8;

    bitset<19> R1 (string("1001000100011010001"));
    bitset<22> R2 (string("0101100111100010011010"));
    bitset<23> R3 (string("10111100110111100001111"));
    bitset<64> S  (string("1001000100011010001010110011110001001101010111100110111100001111"));

    bitset<1> at;
    bitset<1> bt;
    bitset<1> ct;
    bitset<256> zt;

    cout << endl << "MENSAJE A CIFRAR: " << messag;


    for (int i=0; i<6; i++) {

        cout << endl << "********************************************************************";
        cout << endl << endl;
        cout << endl << "____________________________________________________";
        cout << endl << "Número de la iteracion: " << i;
        cout << endl << "____________________________________________________";
        cout << endl << "SEMILLA ";
        cout << endl << "____________________________________________________";
        cout << endl << "REGISTRO 1:       " << R1 << "     |";
        cout << endl << "REGISTRO 2:       " << R2 << "  |";
        cout << endl << "REGISTRO 3:       " << R3 << " |";
        cout << endl << "____________________________________________________";


        //LFSR1: p1(x) = x19 + x18 + x17 + x14 + 1, genera a(t)
        at = (R1[18] ^ R1[17] ^ R1[16] ^ R1[13])^S[i];

        //LFSR2: p2(x) = x22 + x21 + 1, genera b(t)
        bt = (R2[21] ^ R2[20])^S[i];

        //LFSR2: p3(x) = x23 + x22 + x21 +x8+ 1, genera c(t)
        ct = (R3[22] ^ R3[21] ^ R3[20] ^ R3[7])^S[i];

        zt[i] = R1[18] ^ R2[21] ^ R3[22];

        cout << endl << "POLINOMIOS ";
        cout << endl << "____________________________________________________";
        cout << endl << "x19 + x18 + x17 + x14 + 1 + " << S[i] <<", genera a(t): " << at << " |";
        cout << endl << "x22 + x21 + 1 + " << S[i] <<", genera ----------->b(t): " << bt << " |";
        cout << endl << "x23 + x22 + x21 +x8+ 1 + " << S[i] <<", genera -->c(t):  " << ct << "  |";
        cout << endl << "R1x19 + R2x22 + R3x23, genera --->z(t): " << zt[i] << "  |";
        cout << endl << "____________________________________________________";


        // F (a9,b11,C11) = a9 * b11 ⊕ a9 * C11 ⊕ b11C11
        cout << endl << "MAYORIA ";
        cout << endl << "____________________________________________________";
        bitset<1> majority = (R1[8] & R2[10]) ^ (R1[8] & R3[10]) ^ (R2[10] & R3[10]);
        cout << endl << "(" << R1[8] <<", " << R2[10] <<", " << R3[10] <<") - " << "El bit mayoria es: " << majority << "                        |" << endl;
        cout << endl;
        if (R1[8]==majority[0])
        {
            cout << "R1: " << R1 << "     ---> ";
            R1<<=1;
            if (at==0)
                R1.set(0,0);
            else if (at==1)
                R1.set(0,1);
            cout << R1 << "    |" << endl;
        }

        if (R2[10]==majority[0])
        {
            cout << "R2: " << R2 << "  ---> ";
            R2<<=1;
            if (bt==0)
                R2.set(0,0);
            else if (bt==1)
                R2.set(0,1);
            cout << R2 << " |" << endl;
        }

       if (R3[10]==majority[0])
       {
            cout << "R3: " << R3 << " ---> ";
            R3<<=1;
            if (ct==0)
                R3.set(0,0);
            else if (ct==1)
                R3.set(0,1);
            cout << R3 << "|" << endl;
        }

      cout << endl << "____________________________________________________";
      cout << endl << "********************************************************************";
    }

    bitset<8> key;
    int auxset=0;

    cout << endl << endl << "- MENSAJE CIFRADO: ";
    for (int i=0; i<messag.length(); i++){
        for (int j=0; j<8; j++){

            if (zt[auxset]==0){
                key.set(j,0);
            }else if (zt[auxset]==1){
                key.set(j,1);
            }
            auxset++;
        }

        bitset<8> messagencrypt=(key ^ bitset<8> (messag.c_str()[i]));
        cout << messagencrypt;

        bitset<1> majority = (R1[8] & R2[10]) ^ (R1[8] & R3[10]) ^ (R2[10] & R3[10]);
        cout << endl << "(" << R1[8] <<", " << R2[10] <<", " << R3[10] <<") - " << "El bit mayoria es: " << majority << "                        |" << endl;
        cout << endl;
        if (R1[8]==majority[0])
        {
            R1<<=1;
            if (at==0)
                R1.set(0,0);
            else if (at==1)
                R1.set(0,1);

        }

        if (R2[10]==majority[0])
        {
            R2<<=1;
            if (bt==0)
                R2.set(0,0);
            else if (bt==1)
                R2.set(0,1);
        }

       if (R3[10]==majority[0])
       {
            R3<<=1;
            if (ct==0)
                R3.set(0,0);
            else if (ct==1)
                R3.set(0,1);
        }

        bitset<8> key2;
        for (int i=0; i<messag.length(); i++){
            for (int j=0; j<8; j++){

                if (zt[auxset]==0){
                    key2.set(j,0);
                }else if (zt[auxset]==1){
                    key2.set(j,1);
                }
                auxset++;
            }
        }

        bitset<8> messagedecrypt =(key2 ^ messagencrypt);
        cout << messagedecrypt;


}

}

void A5_1algoritmo::A5_1encriptar_mod(string messag){
    int aux = messag.length() * 8;

    bitset<19> R1 (string("1000101100010001001"));
    bitset<22> R2 (string("0101100100011110011010"));
    bitset<23> R3 (string("11110000111101100111101"));
    bitset<64> S  (string("1111000011110110011110101011001000111100110101000101100010001001"));


    bitset<1> at;
    bitset<1> bt;
    bitset<1> ct;
    bitset<256> zt;
    int x = 0;

    cout << endl << "MENSAJE A CIFRAR: " << messag;


    for (int i=0; i<6; i++) {

    while(x<20){
      bitset<1> majority = (R1[8] & R2[10]) ^ (R1[8] & R3[10]) ^ (R2[10] & R3[10]);
        if (R1[8]==majority[0])
        {
            R1<<=1;
            if (at==0)
                R1.set(0,0);
            else if (at==1)
                R1.set(0,1);
        }

        if (R2[10]==majority[0])
        {
            R2<<=1;
            if (bt==0)
                R2.set(0,0);
            else if (bt==1)
                R2.set(0,1);
        }

       if (R3[10]==majority[0])
       {
            R3<<=1;
            if (ct==0)
                R3.set(0,0);
            else if (ct==1)
                R3.set(0,1);
        }
        x++;
    }
        cout << endl << "********************************************************************";
        cout << endl << endl;
        cout << endl << "____________________________________________________";
        cout << endl << "Número de la iteracion: " << i;
        cout << endl << "____________________________________________________";
        cout << endl << "SEMILLA ";
        cout << endl << "____________________________________________________";
        cout << endl << "REGISTRO 1:       " << R1 << "     |";
        cout << endl << "REGISTRO 2:       " << R2 << "  |";
        cout << endl << "REGISTRO 3:       " << R3 << " |";
        cout << endl << "____________________________________________________";


        //LFSR1: p1(x) = x19 + x18 + x17 + x14 + 1, genera a(t)
        at = (R1[18] ^ R1[17] ^ R1[16] ^ R1[13])^S[i];

        //LFSR2: p2(x) = x22 + x21 + 1, genera b(t)
        bt = (R2[21] ^ R2[20])^S[i];

        //LFSR2: p3(x) = x23 + x22 + x21 +x8+ 1, genera c(t)
        ct = (R3[22] ^ R3[21] ^ R3[20] ^ R3[7])^S[i];

        zt[i] = R1[18] ^ R2[21] ^ R3[22];

        cout << endl << "POLINOMIOS ";
        cout << endl << "____________________________________________________";
        cout << endl << "x19 + x18 + x17 + x14 + 1 + " << S[i] <<", genera a(t): " << at << " |";
        cout << endl << "x22 + x21 + 1 + " << S[i] <<", genera ----------->b(t): " << bt << " |";
        cout << endl << "x23 + x22 + x21 +x8+ 1 + " << S[i] <<", genera -->c(t):  " << ct << "  |";
        cout << endl << "R1x19 + R2x22 + R3x23, genera --->z(t): " << zt[i] << "  |";
        cout << endl << "____________________________________________________";


        // F (a9,b11,C11) = a9 * b11 ⊕ a9 * C11 ⊕ b11C11
        cout << endl << "MAYORIA ";
        cout << endl << "____________________________________________________";
        bitset<1> majority = (R1[8] & R2[10]) ^ (R1[8] & R3[10]) ^ (R2[10] & R3[10]);
        cout << endl << "(" << R1[8] <<", " << R2[10] <<", " << R3[10] <<") - " << "El bit mayoria es: " << majority << "                        |" << endl;
        cout << endl;
        if (R1[8]==majority[0])
        {
            cout << "R1: " << R1 << "     ---> ";
            R1<<=1;
            if (at==0)
                R1.set(0,0);
            else if (at==1)
                R1.set(0,1);
            cout << R1 << "    |" << endl;
        }

        if (R2[10]==majority[0])
        {
            cout << "R2: " << R2 << "  ---> ";
            R2<<=1;
            if (bt==0)
                R2.set(0,0);
            else if (bt==1)
                R2.set(0,1);
            cout << R2 << " |" << endl;
        }

       if (R3[10]==majority[0])
       {
            cout << "R3: " << R3 << " ---> ";
            R3<<=1;
            if (ct==0)
                R3.set(0,0);
            else if (ct==1)
                R3.set(0,1);
            cout << R3 << "|" << endl;
        }

      cout << endl << "____________________________________________________";
      cout << endl << "********************************************************************";
    }

    bitset<8> key;
    int auxset=0;

    cout << endl << endl << "- MENSAJE CIFRADO: ";
    for (int i=0; i<messag.length(); i++){
        for (int j=0; j<8; j++){

            if (zt[auxset]==0){
                key.set(j,0);
            }else if (zt[auxset]==1){
                key.set(j,1);
            }
            auxset++;
        }

        bitset<8> messagencrypt=(key ^ bitset<8> (messag.c_str()[i]));
        cout << messagencrypt<<endl;

        int aux3 = messagencrypt.to_ulong();
        if ((aux3<=33) | (aux3>=126)) {
            cout << "@";
        }else{
        cout << char(aux3);
        }

    }


}
