#ifndef C_COLA
#define C_COLA

#include <iostream>
#include <assert.h>
#include "nodo.h"

using namespace std;

template <class elemento>
class Cola: public Nodo<elemento>
{
    private:
        Nodo <elemento> *frente,*final;
        int tamano;

    public:
        Cola();
        bool esVacia();
        void encolar(elemento element);
        void desencolar();
        elemento obtenerFrente();
        elemento obtenerUltimo();
        int longitud();
        ~Cola();            
};

template <class elemento>
Cola <elemento>::Cola()
{ 
    this->tamano = 0;
    this->frente = NULL;
    this->final = NULL;
   
}
template <class elemento>
bool Cola <elemento>::esVacia()
{
    return this->tamano == 0;
}

template <class elemento>
void Cola<elemento>:: encolar(elemento element)
{
    Nodo<elemento> *nuevo;

    nuevo = new Nodo<elemento>;
    nuevo->modificarElemento(element);
    if(this->frente == NULL)
    {
        this->frente = nuevo;
    }
    else
    {
        this->final->modificarElemento(element);
    }
    this->final = nuevo;
    this->tamano++;
}

template <class elemento>
void Cola<elemento>:: desencolar()
{
    Nodo<elemento> *auxiliar;
    auxiliar = this->frente;
    this->frente = this->frente->siguiente();
    delete auxiliar;
    this->tamano--;
}
template <class elemento>
elemento Cola<elemento>::obtenerFrente()
{
    return this->frente->obtenerElemento();
}
template <class elemento>
elemento Cola<elemento>::obtenerUltimo()
{
    return this->final->obtenerElemento();
}

template <class elemento>
int Cola<elemento>::longitud()
{
    return this->tamano;
}
/*
template <class elemento>
void Cola <elemento>::~Cola()
{
    Nodo<elemento> *actual;
	actual = this->frente;
	while(actual != NULL)
	{
		actual = this->frente;
		this->frente = this->frente->siguiente();
		delete actual;
	}
    this->final = NULL;
    this->tamano = 0;
}*/
#endif
