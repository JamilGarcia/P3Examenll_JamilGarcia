#include <iostream>
#include <string>
using namespace std;

class Equipo
{
private:
    string nombreEquipo;
    int PGan;
    int PEmp;
    int PPer;
    int GFav;
    int GCon;
    int Puntos;
    int Dif_G;

public:
    Equipo();
    Equipo(string _nombreEquipo, int _PGan, int _PEmp, int _PPer, int _GFav, int _GCon);
    int getPuntos(); 
    int getDif_G(); 
    void Calcular_Puntos();
    void to_string(); 
    ~Equipo();
};

Equipo::Equipo(string _nombreEquipo, int _PGan, int _PEmp, int _PPer, int _GFav, int _GCon)
    {
        nombreEquipo = _nombreEquipo;
        PGan = _PGan;
        PEmp = _PEmp;
        PPer = _PPer;
        GFav = _GFav;
        GCon = _GCon;
        Calcular_Puntos();
    }

    int Equipo::getPuntos(){
        return Puntos; 
    }

    int Equipo::getDif_G(){
        return Dif_G; 
    }

    void Equipo::Calcular_Puntos()
    {
        int puntos = 0;
        puntos += PGan * 3;
        puntos += PEmp;
        Puntos = puntos;

        //Diferencia de goles
        Dif_G = GFav - GCon;
    }

    void Equipo::to_string(){ 
        cout << nombreEquipo << " " << PGan << " " << PEmp << "   " << PPer << "   " << GFav << "   " << GCon << "   " << Puntos << "     " << Dif_G << "      " <<endl; 
    }

Equipo::~Equipo()
{
}

