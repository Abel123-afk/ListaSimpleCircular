#include<iostream>
#include<conio.h>
#include<functional>
using namespace std;
template<class T>
class ListSimple;
template<class T>
class Nodo {
private:
    friend class ListSimple<T>;
    T elemento;
    Nodo<T>* siguiente;
public:
    Nodo(T elemento = NULL, Nodo<T>* siguiente = nullptr) :
        elemento(elemento), siguiente(siguiente) {}
    ~Nodo() {}
};
template<class T>
class ListSimple {
private:
    Nodo<T>* inicio;
    Nodo<T>* fin;
    long size;
public:
    ListSimple()
    {
        inicio = nullptr;
        fin = nullptr;
        size = 0;
    }
    void insertarInicio(T dato)
    {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        if (size == 0)
        {
            inicio = fin = nuevo;
            fin->siguiente = inicio;
        }
        else {
            nuevo->siguiente = inicio;
            inicio = nuevo;
            fin->siguiente = inicio;

        }
        size++;
    }
    void eliminarEnPos(int pos)
    {
        Nodo<T>* aux = inicio;
        if (pos >= 0 && pos < size)
        {
            if (pos == 0)
            {
                //eliminar al inicio
                inicio = aux->siguiente;
                aux->siguiente = nullptr;
                delete aux;
            }
            else {
                for (int i = 0; i < pos - 1; i++)
                {
                    aux = aux->siguiente;
                }
                Nodo<T>* eliminar = aux->siguiente;
                aux->siguiente = eliminar->siguiente;
                eliminar->siguiente = nullptr;
                delete eliminar;
                if (pos == size - 1)
                {
                    fin = aux;
                    fin->siguiente = inicio;
                }
            }
            size--;
        }

    }
    long _size()
    {
        return size;
    }
    void show(function<void(T)>criterio)
    {
        Nodo<T>* aux = inicio;
        for (size_t i = 0; i < size; i++)
        {
            criterio(aux->elemento);
            aux = aux->siguiente;
        }
    }
    //template<typename T>
    ListSimple<T> buscarRetornar(function<bool(T)>criterio)
    {
        ListSimple<T>listAux = ListSimple<T>();
        Nodo<T>* aux = inicio;
        for (int i = 0; i<size; i++)
        {
            if (criterio(aux->elemento))
            {
                listAux.insertarInicio(aux->elemento);
            }
            aux = aux->siguiente;
        }
        return listAux;
    }
};
class CPerson {
    short edad;
    string nombre;
    char sexo;
public:
    CPerson(short edad = rand() % 80 + 10, string nombre = "Abel", char sexo = 'M') :
        edad(edad), nombre(nombre), sexo(sexo)
    {}
    void mostrar() {
        cout <<"Nombre: "<<nombre<<" , Edad: "<<edad<<", Sexo: "<<sexo<< endl;
    }
};
int main()
{
    ListSimple<CPerson*> personas = ListSimple<CPerson*>();
    for (int i = 0; i < 10; i++)
    {
        CPerson* nuevo = new CPerson();
        personas.insertarInicio(nuevo);
    }
    cout << "Mostrar Personas" << endl;
    personas.show([](CPerson* p) {p->mostrar(); });
    system("pause>=NULL");
    return 0;
}