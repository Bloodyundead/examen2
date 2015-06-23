// queue::push/pop

#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Celular.h"
#include "Evaluador.h"
#include "NodoBinario.h"

using namespace std;

//Escribe los datos del objeto celular (dado) en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varios celulares en un solo archivo
void escribir(string nombre_archivo, Celular*celular, int posicion)
{
    //nombre 20
    //modelo 4
    //precio 8

    ofstream out(nombre_archivo.c_str(),ios::in);
    out.seekp(32*posicion);
    out.write(celular->nombre.c_str(),20);
    out.write((char*)&celular->modelo,4);
    out.write((char*)&celular->precio,8);
    out.close();

}

//Devuelve un celular previamente escrito (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varios celulares de un solo archivo
Celular* leer(string nombre_archivo, int posicion)
{
    ifstream in(nombre_archivo.c_str());
    char nombre[20];
    int modelo;
    double precio;

    in.seekg(32*posicion);
    in.read(nombre,20);
    in.read((char*)&modelo,4);
    in.read((char*)&precio,8);
    in.close();


    Celular *c = new Celular(nombre,modelo,precio);
    return c;
}

//Devuelve el precio del celular en la ultima posicion del archivo con nombre dado
double getUltimoPrecio(string nombre_archivo)
{
    return -1.0;
}

//Convierte la cola (dada) en una pila los datos deben de quedar en el mismo orden
//Nota: El tope de la pila debe de ser el frente de la cola
stack<char> convertirAPila(queue<char> mi_cola)
{
    stack<char> resultado;
    stack<char> otro;
    while(!mi_cola.empty())
    {
        otro.push(mi_cola.front());
        mi_cola.pop();
    }
    while(!otro.empty())
    {
        resultado.push(otro.top());
        otro.pop();
    }

    return resultado;
}

//Devuelve true si el set esta ordenado, de lo contrario devuelve false
bool estaOrdenado(set<int> mi_set)
{
    set<int>::iterator it;
    for ( it=mi_set.begin() ; it != mi_set.end(); it++ )
    {
        return true;
    }

    return false;
}

//Devuelve las tablas de los numeros del 1 al 10
//La llave es el numero de la tabla, el valor asociado es un vector que contiene la tabla de dicho numero
map<int,vector<int> > getTablas()
{
    map<int,vector<int> > mi_mapa;

    return mi_mapa;
}

//Devuelve la suma de todos los valores almacenados en el arbol con raiz dada
int getSuma(NodoBinario* raiz)
{
   if(raiz!=NULL)
   {
       return raiz->valor + getSuma(raiz->hijo_der) + getSuma(raiz->hijo_izq);
   }

    return 0;
}

//Devuelve true si todos los valores de los nodos son primos, de lo contrario devuelve false
bool sonPrimos(NodoBinario* raiz)
{
    return false;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

