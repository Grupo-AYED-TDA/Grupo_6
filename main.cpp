#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Figuras.h"
#include "Lectura.h"

using namespace std;

/* PRE: Pecibe una lista (cargada) de lecturas y una lista (vacia) fuguras
   POST: Por cada nodo de la lista lectura llam� a cargarConstructorDeFiguras
   pasandole un nodo de lista lectura y la lista figura completa*/
void recorrerFigurasYCargarConstructorDeFiguras(t_lectura *&ptrLectura, t_figura *&o_figura);

/* PRE: Recibe un nodo (cargado) de lista lectura y la lista figura completa
   POST: Se llam� al constructor y se asingnaro cada atributo del nodo a cada
   parametro que requiere el constructor*/
void cargarConstructorDeFiguras(int id, t_lectura *&ptrLectura, t_figura *&o_figura);

void ordenarLista(t_figura *&ptrfigura);

void ordenarListaPorColor(t_figura *&ptrfigura);

void mostraListaPruebaTotal(t_figura *&ptrfigura);

int main(int argc, char** argv) {

	t_figura *o_figura=NULL;//Se genera una lista figura en null
	t_lectura *o_lectura = NULL; //Se genera una lista lectura en null
    Lectura(o_lectura); //Lectura lee un archivo y carga una lista de lectura
//    mostrarLista(o_lectura); //muestra la lista de datos obtenidos del archivo con un id agregado al principio de cada rengl�n
    recorrerFigurasYCargarConstructorDeFiguras(o_lectura,o_figura);
    mostrarLista(o_figura);

    cout<<endl<<"--------------------------------------------------------------------------------------"<<endl<<endl;

    cout<<"Rectangulo, azul: "<<getTotalFiguraXColor(o_figura,"rectangulo","azul")<<endl<<endl;
    cout<<"Cilindro, rojo: "<<getTotalFiguraXColor(o_figura,"cilindro","rojo")<<endl<<endl;
    cout<<"Cubo, amarillo: "<<getTotalFiguraXColor(o_figura,"cubo","amarillo")<<endl<<endl;
    cout<<"Triangulo, azul: "<<getTotalFiguraXColor(o_figura,"triangulo","azul")<<endl<<endl;
    cout<<"Circulo, rojo: "<<getTotalFiguraXColor(o_figura,"circulo","rojo")<<endl<<endl;

    mostrarTotalesTotalFiguraXColor(o_figura);

     //Test para probar que funciona TotalFigura , sumas las tres areas


    cout<<"TotalFigura-> "<<totalfigura(o_figura);
    cout<<"\n\n----------------------------------------------------------"<<endl;

    ordenarListaPorTipo(o_figura);

    //mostrarLista(o_figura);

    cout<<"\n\n----------------------------------------------------------"<<endl;


    ordenarListaPorTipoYColor(o_figura);

    //mostrarLista(o_figura);

    cout<<"\n\n----------------------------------------------------------"<<endl;

    cout<<"Test totales por figura y color\n"<<endl;

    mostrarTotalesTotalFiguraXColor2(o_figura);

    cout<<"\n\n";

    system("pause");

    return 0;
}

void recorrerFigurasYCargarConstructorDeFiguras(t_lectura *&ptrLectura,t_figura *&o_figura){
  t_lectura *actual=new t_lectura();
  actual=ptrLectura;
    int id = 0;
	while(actual != NULL)
	{
	    id++;
        cargarConstructorDeFiguras(id, actual,o_figura);
		actual=actual->siguiente;
	}
}

void cargarConstructorDeFiguras(int id, t_lectura *&ptrLectura, t_figura *&o_figura){
       string descripcion;
       float valor1f = convertirStringA_float(replaceNum(ptrLectura->p[2]));
       float valor2f = convertirStringA_float(replaceNum(ptrLectura->p[3]));
       if(ptrLectura->p[0] == "circulo"){
        descripcion = "Radio: "+ptrLectura->p[2];
        constructor(id, ptrLectura->p[0], ptrLectura->p[1], areaCirculo(valor1f), descripcion, o_figura);
       }
       if(ptrLectura->p[0] == "cubo"){
        descripcion = "Lado: "+ptrLectura->p[2];
        constructor(id, ptrLectura->p[0], ptrLectura->p[1], areaCubo(valor1f), descripcion, o_figura);
       }
       if(ptrLectura->p[0] == "cilindro"){
        descripcion = "Radio: "+ptrLectura->p[2]+" Altura: "+ptrLectura->p[3];
        constructor(id, ptrLectura->p[0], ptrLectura->p[1], areaCilindro(valor1f,valor2f), descripcion, o_figura);
       }
       if(ptrLectura->p[0] == "rectangulo"){
        descripcion = "Base: "+ptrLectura->p[2]+" Altura: "+ptrLectura->p[3];
        constructor(id, ptrLectura->p[0], ptrLectura->p[1], areaRectangulo(valor1f,valor2f), descripcion, o_figura);
       }
       if(ptrLectura->p[0] == "triangulo"){
        descripcion = "Base: "+ptrLectura->p[2]+" Altura: "+ptrLectura->p[3];
        constructor(id, ptrLectura->p[0], ptrLectura->p[1], areaTriangulo(valor1f,valor2f), descripcion, o_figura);
       }
}
/*
void ordenarListaPorTipo(t_figura *&ptrfigura)
{
     t_figura * actual;
     t_figura * siguiente;
     int t;
     string tipo;
     string color;
     float area;
     string descripcion;


     actual = ptrfigura;

     while(actual->siguiente != NULL)
     {
          siguiente = actual->siguiente;

          while(siguiente!=NULL)
          {
               if( actual->tipo <= siguiente->tipo) // actual->tipo).compare(siguiente->tipo) != 0
               {
                    t = siguiente->id;
                    siguiente->id = actual->id;
                    actual->id = t;

                    tipo = siguiente->tipo;
                    siguiente->tipo = actual->tipo;
                    actual->tipo = tipo;

                    color = siguiente->color;
                    siguiente->color = actual->color;
                    actual->color = color;

                    area = siguiente->area;
                    siguiente->area = actual->area;
                    actual->area = area;

                    descripcion = siguiente->descripcion;
                    siguiente->descripcion = actual->descripcion;
                    actual->descripcion = descripcion;

               }

               siguiente = siguiente->siguiente;
          }
          actual = actual->siguiente;
          siguiente = actual->siguiente;

     }



     cout<<"\nLista ordenada por tipo"<<endl;
}


void ordenarListaPorTipoYColor(t_figura *&ptrfigura)
{
     t_figura * actual;
     t_figura * siguiente;
     int t;
     string tipo;
     string color;
     float area;
     string descripcion;


     actual = ptrfigura;

     while(actual->siguiente != NULL)
     {
          siguiente = actual->siguiente;

          while(siguiente!=NULL)
          {
               if( actual->tipo == siguiente->tipo && actual->color <= siguiente->color ) // actual->tipo).compare(siguiente->tipo) != 0
               {
                    t = siguiente->id;
                    siguiente->id = actual->id;
                    actual->id = t;

                    tipo = siguiente->tipo;
                    siguiente->tipo = actual->tipo;
                    actual->tipo = tipo;

                    color = siguiente->color;
                    siguiente->color = actual->color;
                    actual->color = color;

                    area = siguiente->area;
                    siguiente->area = actual->area;
                    actual->area = area;

                    descripcion = siguiente->descripcion;
                    siguiente->descripcion = actual->descripcion;
                    actual->descripcion = descripcion;

               }

               siguiente = siguiente->siguiente;
          }
          actual = actual->siguiente;
          siguiente = actual->siguiente;

     }



     cout<<"\nLista ordenada por nombre y color"<<endl<<endl;
}


void mostraListaPruebaTotal(t_figura *&ptrfigura){
    t_figura * aux = ptrfigura;
    t_figura * aux1 = ptrfigura;
    string tipoAux = "vacio";
    string colorAux = "vacio";

    while(aux!=NULL){
        if(tipoAux!=aux->tipo || colorAux!=aux->color){
        cout<<aux->tipo <<" ----> "<< aux->color <<" ----> "<< getTotalFiguraXColor(aux1,aux->tipo,aux->color) <<"\n";
         tipoAux = aux->tipo;
         colorAux = aux->color;
        }
        aux = aux->siguiente;
    }

}

*/

//float convertirStringA_float(string variableString){
//
//  char *str=const_cast< char *>(variableString.c_str());//castea string a char arrays
//  float num;
//    num = atof(str);//es como un atoi pero f de float
//  return num;
//}
//
//
//int main ()
//{
//    printf("Hola ");
//  string v = "6.6";
//    float numero = convertirStringA_float(string v);
//  cout<<"   "<<numero;
//
//  return 0;
//}
//; //chino

