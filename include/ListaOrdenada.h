#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H
#include "No.h"

class ListaOrdenada
{
    public:
        ListaOrdenada();
        ~ListaOrdenada();

        int get(int k);
        //int set(int k, int val);
        void insereOrd(int val);
        void removeOrd();
        void imp();
        void insereFinal(int val);


    private:
        No *primeiro;
        No *ultimo;
        int n;

};

#endif // LISTAORDENADA_H
