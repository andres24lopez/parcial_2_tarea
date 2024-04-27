#include <iostream>
#include <vector>
#include <string>

using namespace std;

double calcularPromedio(const vector<double>& notas) {
    double suma = 0.0;
    for (double nota : notas) {
        suma += nota;
    }
    return suma / notas.size();
}

string estadoAprobacion(double promedio) {
    return (promedio >= 60) ? "Aprobado" : "Reprobado";
}

struct Estudiante {
    string id;
    string nombre;
    string apellido;
    vector<double> notas;
    double promedio;
    string estado;
};

vector<Estudiante> ingresarEstudiantes(int cantidad) {
    vector<Estudiante> estudiantes;
    for (int i = 0; i < cantidad; ++i) {
        cout << "Ingrese los datos del estudiante " << i + 1 << ":" << endl;
        Estudiante estudiante;
        cout << "ID: ";
        cin >> estudiante.id;
        cout << "Nombre: ";
        cin >> estudiante.nombre;
        cout << "Apellido: ";
        cin >> estudiante.apellido;
        cout << "Notas: " << endl;
        for (int j = 0; j < 4; ++j) {
            double nota;
            cout << "Nota " << j + 1 << ": ";
            cin >> nota;
            estudiante.notas.push_back(nota);
        }
        estudiante.promedio = calcularPromedio(estudiante.notas);
        estudiante.estado = estadoAprobacion(estudiante.promedio);
        estudiantes.push_back(estudiante);
    }
    return estudiantes;
}

void mostrarEstudiantes(const vector<Estudiante>& estudiantes) {
    cout << "\nDatos de los estudiantes:" << endl;
    for (const Estudiante& estudiante : estudiantes) {
        cout << "ID: " << estudiante.id << endl;
        cout << "Nombre: " << estudiante.nombre << " " << estudiante.apellido << endl;
        cout << "Notas: ";
        for (double nota : estudiante.notas) {
            cout << nota << " ";
        }
        cout << endl;
        cout << "Promedio: " << estudiante.promedio << endl;
        cout << "Estado: " << estudiante.estado << endl << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese el número de estudiantes: ";
    cin >> n;
    vector<Estudiante> listaEstudiantes = ingresarEstudiantes(n);
    mostrarEstudiantes(listaEstudiantes);
    return 0;
}

