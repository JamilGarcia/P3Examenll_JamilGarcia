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

    int getPuntosEq(){
        return Equipo_->getPuntos(); 
    }

    void to_Nstring()
    {
        Equipo_->to_string();
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