#include <iostream>
using namespace std;

class Persona{
  protected:
    string nombre;
    int edad;
  public:       
    Persona(string,int); //constructor
    ~Persona(); //destructor
    virtual void mostrar(); //función de polimorfismo va en la clase padre
};

Persona::Persona(string _nombre, int _edad)
{
    nombre=_nombre;
    edad=_edad;
};

Persona::~Persona(){ };

void Persona::mostrar()
{
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Edad: "<<edad<<endl;
};

class Alumno : public Persona
{
    private:
        float notaFinal;
    public:
        Alumno (string,int,float); //constructor de Alumno
        void mostrar();
};

Alumno::Alumno(string _nombre,int _edad, float _notaFinal) : Persona (_nombre,_edad)
{
    notaFinal=_notaFinal;
};

void Alumno :: mostrar()
{
    Persona::mostrar();
    cout<<"Nota Final: "<<notaFinal<<endl;
};

class Profesor : public Persona
{
    private:
        string Materia;
    public:
        Profesor (string,int,string); //constructor de Profesor
        void mostrar();
};

Profesor::Profesor(string _nombre,int _edad, string _Materia) : Persona (_nombre,_edad)
{
    Materia=_Materia;
};

void Profesor :: mostrar()
{
    Persona::mostrar();
    cout<<"Materia: "<<Materia<<endl;
};


main()
{
    Persona *lista[3];
    lista[0]= new Profesor("Juan",28,"Logica");
    lista[1]= new Alumno("Jose",19,4.9);
    lista[2]= new Alumno("Maria",17,4.5);
    
    for(int i=0;i<3;i++)
    
    {
        (*lista[i]).mostrar(); // lista[i]->mostrar();
    }
}
