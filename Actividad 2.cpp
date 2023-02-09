#include <iostream>
#include <stdlib.h>

using namespace std;

class Neurona{
	private:
		Neurona* sig;
		Neurona* ant;
		int id;
		float voltaje;
		int posicion_x;
		int posicion_y;
		int red;
		int green;
		int blue;
	public:
		void print();
		void insertaradelante(int Nid, float Nvoltaje, int Nposicion_x, int Nposicion_y, int Nred, int Ngreen, int Nblue);
		float eliminarsig();

    friend class admin;
};

class admin{
	private:
		Neurona inicio, fin;
	public:
		admin();
		void agregar_inicio(int Nid, float Nvoltaje, int Nposicion_x, int Nposicion_y, int Nred, int Ngreen, int Nblue);
		void agregar_final(int Nid, float Nvoltaje, int Nposicion_x, int Nposicion_y, int Nred, int Ngreen, int Nblue);
		void mostrar();
};

int main(){
    admin Admin;
    Admin.agregar_inicio(1,100,3,4,2,3,5);
    Admin.mostrar();
    return 0;
}

admin::admin(){
	inicio.sig=&fin;
	fin.ant=&inicio;
}

void Neurona::insertaradelante(int Nid, float Nvoltaje, int Nposicion_x, int Nposicion_y, int Nred, int Ngreen, int Nblue){
    Neurona* vtx = new Neurona;
    vtx -> id = Nid;
    vtx -> voltaje = Nvoltaje;
    vtx -> posicion_x = Nposicion_x;
    vtx -> posicion_y = Nposicion_y;
    vtx -> red = Nred;
    vtx -> green = Ngreen;
    vtx -> blue = Nblue;
    vtx -> ant = this;
    vtx -> sig = this -> sig;
    this -> sig -> ant = vtx;
    this -> sig = vtx;
}

void admin::agregar_inicio(int Nid, float Nvoltaje, int Nposicion_x, int Nposicion_y, int Nred, int Ngreen, int Nblue){
    inicio.insertaradelante(Nid, Nvoltaje, Nposicion_x, Nposicion_y, Nred, Ngreen, Nblue);
}

void admin::agregar_final(int Nid, float Nvoltaje, int Nposicion_x, int Nposicion_y, int Nred, int Ngreen, int Nblue){
    fin.ant -> insertaradelante(Nid, Nvoltaje, Nposicion_x, Nposicion_y, Nred, Ngreen, Nblue);
}

float Neurona::eliminarsig(){
    float x;
    Neurona* temp=this->sig;
    x=temp->id;
    x=temp->voltaje;
    x=temp->posicion_x;
    x=temp->posicion_y;
    x=temp->red;
    x=temp->green;
    x=temp->blue;
    this->sig->sig->ant=this;
	this->sig=this->sig->sig;
	delete temp;
	return x;
}

void admin::mostrar(){
     Neurona* n=inicio.sig;
     cout<<"Neuronas:"<<endl;
     while(n->sig!=&fin){
        cout<<"id: "<<n->id<<" voltaje: "<<n->voltaje<<" posicion x: "<<n->posicion_x<<" posicion y: "<<n->posicion_y<<" red: "<<n->red<<" green: "<<n->green<<" blue: "<<n->blue;
        n=n->sig;
     }
     cout<<endl;
}
