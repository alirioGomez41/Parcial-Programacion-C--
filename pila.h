#ifndef P_PILA
#define P_PILA

#include <iostream>
#include <assert.h>
#include "nodo.h"

using namespace std;

template <class elemento>
class Pila : public Nodo<elemento>
{
    private:
    Nodo <elemento> *tope;
    int tamano;

    public:
    Pila(); // constructor
    bool esVacia();
    void apilar(elemento element);
    void desapilar();
    elemento obtenerTope();
    int obtenerTamano();
    ~Pila();

};

template <class elemento>
Pila <elemento>:: Pila()
{
    this->tope = NULL;
    this->tamano = 0;
}

template <class elemento>
bool Pila<elemento>::esVacia()
{
    return this->tamano == 0;
}

template <class elemento>
void Pila <elemento>:: apilar(elemento element)
{
    Nodo <elemento> *nuevo;
    nuevo = new Nodo<elemento>;
    nuevo->modificarElemento(element);
    nuevo->modificarSiguiente(this->tope);
    this->tope = nuevo;
    this->tamano = this->tamano + 1;
}

template <class elemento>
void Pila <elemento>:: desapilar()
{
    Nodo <elemento> *auxiliar;
    auxiliar = this->tope;
    this->tope = this->tope->siguiente();
    delete auxiliar;
    this->tamano = this->tamano - 1;
}

template <class elemento>
elemento Pila<elemento>::obtenerTope()
{
    return this->tope->obtenerElemento();
}

template <class elemento>
int Pila<elemento>::obtenerTamano()
{
    return this->tamano;
}

//No me funciona este metodo UwU
template <class Elemento>
void Pila<Elemento>::invertir()
{
	Pila<Elemento> pila;
	while(this->tamano > 0 )
    {
		pila->apilar(this->obtenerTope());
		this->desapilar();
	}
	this->tope = pila;
}



template <class elemento>
void Pila <elemento>::~Pila()
{
    Nodo<elemento> *actual;
	actual = this->tope;
	while(actual != NULL)
	{
		actual = this->tope;
		this->tope = this->tope->siguiente();
		delete actual;
	}
    this->tamano = 0;
}


#endif