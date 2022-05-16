#include <iostream>
#include <stdlib.h>

typedef struct nodo{
   int dato;
   struct nodo *siguiente;
}Nodo;

Nodo *inicioPila = NULL;
Nodo *inicioCola = NULL;
Nodo *ultimoCola = NULL;

//funciones
void meterPila();
void llenarCola();
int introducirDatos();
void ordenarDatos();
void verLista();

int main()
{
   printf("Ingrese los numeros para la pila\n\t->Para terminar ingrese el numero 0\n");
   meterPila();
   printf("\nDatos para la cola\n\t->Para terminar ingrese el numero 0\n");
   llenarCola();
   ordenarDatos();
   printf("\nLista enlazada ordenada\n");
   verLista();

   return 0;
}

void meterPila()
{
   Nodo *nuevo;
   int numero = introducirDatos();

   while(numero!=0)
   {
      nuevo = (Nodo*)malloc(sizeof(Nodo));
      nuevo->dato=numero;
      nuevo->siguiente=inicioPila;
      inicioPila=nuevo;
      numero=introducirDatos();
   }
}

 void llenarCola()
{
    Nodo *nuevo;
    int numero=introducirDatos();

    while(numero!=0)
    {
      nuevo = (Nodo*)malloc(sizeof(Nodo));
      nuevo->dato=numero;

      if(ultimoCola==NULL)
      {
          nuevo->siguiente=NULL;
          inicioCola=nuevo;
          ultimoCola=nuevo;
      }
      else
      {
          nuevo->siguiente=NULL;
          ultimoCola->siguiente=nuevo;
          ultimoCola=nuevo;
      }
      numero=introducirDatos();
   }
}


int introducirDatos()
{
   int x;
   printf("Numero: ");
   scanf("%d",&x);
   return x;
}

void ordenarDatos()
{
   Nodo *pivote,*actual;
   int temp;

   //Ordenar Pila
   pivote=inicioPila;
   while(pivote!=NULL)
   {
       actual=pivote;
       while(actual!=NULL)
       {
           if(pivote->dato > actual->dato)
           {
              temp=pivote->dato;
              pivote->dato=actual->dato;
              actual->dato=temp;
           }
           actual=actual->siguiente;
         }
         pivote=pivote->siguiente;
     }

    //Ordenar Cola
    pivote=inicioCola;
    while(pivote!=NULL)
    {
      actual=pivote;
      while(actual!=NULL)
      {
          if(pivote->dato > actual->dato)
          {
            temp=pivote->dato;
            pivote->dato=actual->dato;
            actual->dato=temp;
          }
          actual=actual->siguiente;
       }
       pivote=pivote->siguiente;
    }
 }

 void verLista()
 {
   Nodo *lista;

    lista=inicioPila;
    while(lista!=NULL)
    {
      printf("Dato: %d\n",lista->dato);
      lista=lista->siguiente;
    }

    lista=inicioCola;
    while(lista!=NULL)
    {
      printf("Dato: %d\n",lista->dato);
      lista=lista->siguiente;
    }
  }
