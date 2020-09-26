#include <iostream>
#include "Equipo.hpp"
using namespace std;

class nodo
{
private:
    nodo *Nodo;
    Equipo *Equipo_;

public:
    nodo(Equipo *_Equipo)
    {
        Equipo_ = _Equipo;
    }

    void setNext_node(nodo *PNodo)
    {
        Nodo = PNodo;
    }

   nodo* next_node(){
       return Nodo; 
    }

    Equipo* getEquipo(){
        return Equipo_; 
    }

    void to_Nstring()
    {
        if(Nodo != nullptr){
            Equipo_->to_string();
            Nodo->to_Nstring();
        }
    }

    ~nodo()
    {
        if (Nodo)
        {
            delete Nodo;
        }

        if (Equipo_)
        {
            delete Equipo_;
        }
    };
};