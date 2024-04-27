#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Definición de la estructura Estudiante
struct Estudiante {
    string id;
    string nombre;
    string apellido;
    double notas[4];
    double promedio;
    string resultado;
};

// Función para calcular el promedio y determinar el resultado
void calcularPromedioYResultado(Estudiante* estudiante) {
    double suma = 0.0;
    for (int i = 0; i < 4; ++i) {
        suma += estudiante->notas[i];
    }
    estudiante->promedio = suma / 4;
    estudiante->resultado = (estudiante->promedio >= 60) ? "Aprobado" : "Reprobado";
}

// Función para crear un nuevo estudiante
void crearEstudiante() {
    Estudiante estudiante;
    cout << "Ingrese ID del estudiante: ";
    cin >> estudiante.id;
    cout << "Ingrese nombre del estudiante: ";
    cin >> estudiante.nombre;
    cout << "Ingrese apellido del estudiante: ";
    cin >> estudiante.apellido;
    cout << "Ingrese las 4 notas del estudiante: ";
    for (int i = 0; i < 4; ++i) {
        cin >> estudiante.notas[i];
    }
    calcularPromedioYResultado(&estudiante);

    ofstream archivo("notas.dat", ios::binary | ios::app);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }
    archivo.write(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante));
    archivo.close();
    cout << "Estudiante creado exitosamente." << endl;
}

// Función para leer todos los estudiantes del archivo
void leerEstudiantes() {
    ifstream archivo("notas.dat", ios::binary);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    Estudiante estudiante;
    while (archivo.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante))) {
        cout << "ID: " << estudiante.id << endl;
        cout << "Nombre: " << estudiante.nombre << " " << estudiante.apellido << endl;
        cout << "Notas: ";
        for (int i = 0; i < 4; ++i) {
            cout << estudiante.notas[i] << " ";
        }
        cout << endl;
        cout << "Promedio: " << estudiante.promedio << endl;
        cout << "Resultado: " << estudiante.resultado << endl;
        cout << endl;
    }
    archivo.close();
}

int main() {
    char opcion;
    do {
        cout << "\nSeleccione una opcion:" << endl;
        cout << "1. Crear nuevo estudiante" << endl;
        cout << "2. Mostrar todos los estudiantes" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                crearEstudiante();
                break;
            case '2':
                leerEstudiantes();
                break;
            case '3':
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no valida. Por favor, seleccione de nuevo." << endl;
                break;
        }
    } while (opcion != '3');

    return 0;
}

