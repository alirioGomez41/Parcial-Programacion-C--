#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

#include "lista.h"
#include "cola.h"

using namespace std;
void mediana(int, Lista<int>*,ofstream&);
void principal();
int main()
{
	principal();
	return 0;
}

void mediana(int longitud, Lista<int>*lista,ofstream &salida){
	Cola<int> *colaMenor,*colaMayor;
	
	colaMenor = new Cola<int>;
	colaMayor = new Cola<int>;
	int media,cont;
	media = (longitud + 1) / 2;
	cont = 1;
	
	
	if(lista->longitud() % 2 == 0){
	
	
		
		while(cont <= media)
		{	
			colaMenor->encolar(lista->consultar(cont));
			cont++;
			salida<<colaMenor->obtenerFrente()<<" ";
			colaMenor->desencolar();
		}
		salida<<endl;
		while(cont <= lista->longitud())
		{	
			colaMayor->encolar(lista->consultar(cont));
			cont++;
			salida<<colaMayor->obtenerFrente()<<" ";
			colaMayor->desencolar();
		}
		
		
		
	}
	else
	{
		
		while(cont < media)
		{
			
			colaMenor->encolar(lista->consultar(cont));
			cont++;
			salida<<colaMenor->obtenerFrente()<<" ";
			colaMenor->desencolar();
		
		
		/*salida<<lista->consultar(cont)<<" ";
		cont++;*/
		}
		salida<<endl;
		while(cont <= lista->longitud())
		{
			/*salida<<lista->consultar(cont)<<" ";
			cont++;*/
			colaMayor->encolar(lista->consultar(cont));
			cont++;
			salida<<colaMayor->obtenerFrente()<<" ";
			colaMayor->desencolar();
		}
	
		
	}
	
		
	
		
		
	
	
	salida<<endl;
}

void principal()
{
	//Archivos
	ifstream entrada;
	ofstream salida;
	// ofstream salida;

	//Variables
	int cantidad_elementos_lista,casos_prueba,cont,numero;
	
	
	//Lista
	Lista<int> *listaA;
	listaA = new Lista<int>;
	

	//Abriendo Archivos
	entrada.open("entrada.in",ios::in);	
	salida.open("salida.out",ios::out);

	if(entrada.fail() || salida.fail())
	{
		cout<<"No se puedo abrir el archivo";
		exit(1);
	}

	cont = 0;
	entrada>>casos_prueba;//leyendo cantida de casos prueba

	while(cont < casos_prueba)
	{
		//leemos
		entrada>>cantidad_elementos_lista;
		
		while(cantidad_elementos_lista > 0)
		{
			// leemos los elementos de la lista
			entrada>>numero;

			listaA->insertar(numero,listaA->longitud() + 1);
			cantidad_elementos_lista--;
		}
		
		listaA->ordenar(true);
		
		
		
		
		listaA->ordenar(true);
		
		//cout<<listaA->longitud()<<endl;
		mediana(listaA->longitud(),listaA,salida);
		
		
		
		
		
		
		
		
		listaA = new Lista<int>;
		cont++;
	}
	salida.close();
	entrada.close();
}



















