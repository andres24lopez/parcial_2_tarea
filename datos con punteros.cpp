#include <iostream>
#include <string>

using namespace std;


struct Estudiante {
    string id;
    string nombre;
    string apellido;
    double notas[4];
    double promedio;
    string estado;
};


void calcularPromedio(Estudiante* estudiante) {
    double suma = 0.0;
    for (int i = 0; i < 4; ++i) {
        suma += estudiante->notas[i];
    }
    estudiante->promedio = suma / 4;
}


void determinarEstado(Estudiante* estudiante) {
    estudiante->estado = (estudiante->promedio >= 60) ? "Aprobado" : "Reprobado";
}

int main() {
    int n;
    cout << "Ingrese el numero de estudiantes: ";
    cin >> n;

 
    Estudiante* estudiantes = new Estudiante[n];

 
    for (int i = 0; i < n; ++i) {
        cout << "Ingrese los datos del estudiante " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> estudiantes[i].id;
        cout << "Nombre: ";
        cin >> estudiantes[i].nombre;
        cout << "Apellido: ";
        cin >> estudiantes[i].apellido;
        cout << "Notas: ";
        for (int j = 0; j < 4; ++j) {
            cin >> estudiantes[i].notas[j];
        }
        calcularPromedio(&estudiantes[i]);
        determinarEstado(&estudiantes[i]);
    }

  
    cout << "\nDatos de los estudiantes:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "ID: " << estudiantes[i].id << endl;
        cout << "Nombre: " << estudiantes[i].nombre << " " << estudiantes[i].apellido << endl;
        cout << "Notas: ";
        for (int j = 0; j < 4; ++j) {
            cout << estudiantes[i].notas[j] << " ";
        }
        cout << endl;
        cout << "Promedio: " << estudiantes[i].promedio << endl;
        cout << "Estado: " << estudiantes[i].estado << endl << endl;
    }

    delete[] estudiantes;

    return 0;
}

