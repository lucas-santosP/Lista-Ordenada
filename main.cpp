#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include <iostream>
#include "ListaOrdenada.h"
#include "No.h"
using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand()%(b - a + 1) ; /// retorna um numero inteiro aleatório entre a e b
}

int main()
{
    ListaOrdenada l;
    int num;

    for(int i=0;i<7;i++){
        l.insereOrd(numAleatorio(1,15));
        l.imp();
    }

    return 0;
}
