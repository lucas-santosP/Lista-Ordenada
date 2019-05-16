#include <iostream>
#include "ListaOrdenada.h"
#include "No.h"
using namespace std;

ListaOrdenada::ListaOrdenada()
{
    cout << "Criando objeto ListaOrdenada" << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}
ListaOrdenada::~ListaOrdenada(){
    cout <<endl<< "Destruindo objeto ListaOrdenada" << endl;
    No *p = primeiro;
    while(p != NULL)
    {
        No *t = p->getProx();
        delete p;
        p = t;
    }
}


int ListaOrdenada::get(int k){

    if(k<0 || k>=n){
        cout<<endl<<"Erro: Indice invalido!"<<endl;
        exit(1);
    }
    else{
    No *aux;
    aux=primeiro;
    int i=0;

    while(i<k){
        aux=aux->getProx();
        i++;
    }
    return aux->getInfo();
    }
}

void ListaOrdenada::insereOrd(int val)
{
    No *p=new No();
    p->setInfo(val);    p->setProx(NULL);

    if(n==0){       //Se Lista estiver vazia
        primeiro=p;
        ultimo=p;
        n++;
        return;
    }

    No *aux;
    aux=primeiro;
    bool cond; int k;

    for(int i=0; i<n; i++){  //For para saber se existe algum valor maior que val na lista
        if( val < aux->getInfo() ) {
            cond=true;
            k=i;
            break;}
        else{
            k=i;
            cond=false;}

        aux=aux->getProx();
    }

    cout<<endl<<boolalpha<<"-Valor maior que "<<val<<" encontrado ? "<<cond<<endl<<endl;

    if(cond)    //Se algum houver algum valor maior que val na lista,
    {           //Aqui será adiciona um Nó anterior a ele.
        aux=primeiro;
        int j=0;
        while(j<k-1){
            aux=aux->getProx();
            j++;
        }

        if(get(0)>val)      // se o valor maior que val estiver na primeira posiçao,
        {                   //  aqui será criado um novo Nó no inicio da lista
            aux=primeiro;
            primeiro=p;
            p->setProx(aux);
            n++;
            return;
        }
        p->setProx(aux->getProx());
        aux->setProx(p);
    }
    else    //Se não existir valor maior que val, aqui será adicionado um no no final da lista.
    {
        aux=primeiro;
        int j=0;
        while(j!=k){
            aux=aux->getProx();
            j++;
        }
        p->setProx(aux);
        aux->setProx(p);
        ultimo=p;
    }
    ultimo->setProx(NULL);
    n++;
}

void ListaOrdenada::imp(){
    if(n!=0){
        cout<<endl;
        No *aux=primeiro;
        for(int i=0; i<n; i++){
            cout<<"["<<aux->getInfo()<<"] ";
            aux=aux->getProx();
        }
    }
    else{
        cout<<endl<<"Lista vazia!";
    }
    cout<<endl;
}
