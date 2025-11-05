#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

struct Professor {
    char name_profe[20], last_name_profe[15], subject_profe[15];
    int codigo_profe;
    float salary_profe;
} profe;

void guardarProfesor();
void leerProfesor();
void buscarProfesor();
void modificarProfesor();
void eliminarProfesor();

int main() {
    int option;
    while (true) {
        cout << "---------------------------------" << endl;
        cout << "1 GUARDAR DATOS DEL PROFESOR" << endl;
        cout << "2 LEER LOS DATOS GUARDADOS" << endl;
        cout << "3 BUSCAR LOS DATOS GUARDADOS" << endl;
        cout << "4 MODIFICAR LOS DATOS GUARDADOS" << endl;
        cout << "5 ELIMINAR LOS DATOS GUARDADOS" << endl;
        cout << "6 SALIR" << endl;
        cout << "---------------------------------" << endl;
        cout << "ESCOGER UNA OPCION: ";
        cin >> option;
        cin.ignore();

        switch (option) {
        case 1: guardarProfesor(); break;
        case 2: leerProfesor(); break;
        case 3: buscarProfesor(); break;
        case 4: modificarProfesor(); break;
        case 5: eliminarProfesor(); break;
        case 6:
            cout << "Saliendo del programa..." << endl;
            return 0;
        default:
            cout << "Opcion invalida, intente nuevamente." << endl;
        }
    }
}

void guardarProfesor() {
    Professor profe;
    ofstream file("professor_data.txt", ios::app);

    for (int i = 0; i < 5; i++) {
        cout << "\n--- Profesor #" << (i + 1) << " ---" << endl;
        cout << "Ingrese el nombre del profesor: ";
        cin >> profe.name_profe;
        cout << "Ingrese el apellido del profesor: ";
        cin >> profe.last_name_profe;
        cout << "Ingrese la materia impartida: ";
        cin >> profe.subject_profe;
        cout << "Ingrese el codigo: ";
        cin >> profe.codigo_profe;
        cout << "Ingrese el salario del profesor: ";
        cin >> profe.salary_profe;

        file << profe.name_profe << " " << profe.last_name_profe << " " << profe.subject_profe
             << " " << profe.codigo_profe << " " << profe.salary_profe << endl;

        cout << "Profesor #" << (i + 1) << " guardado correctamente.\n";
    }

    file.close();
    cout << "\nTodos los datos se han guardado exitosamente.\n";
}

void leerProfesor() {
    ifstream file("professor_data.txt");
    Professor profe;

    cout << "\nProfesores registrados:\n";
    while (file >> profe.name_profe >> profe.last_name_profe >> profe.subject_profe >> profe.codigo_profe >> profe.salary_profe) {
        cout << "Nombre: " << profe.name_profe << endl;
        cout << "Apellido: " << profe.last_name_profe << endl;
        cout << "Materia: " << profe.subject_profe << endl;
        cout << "Codigo: " << profe.codigo_profe << endl;
        cout << "Salario: " << profe.salary_profe << endl;
        cout << "--------------------------" << endl;
    }
    file.close();
}

void buscarProfesor() {
    Professor profe;
    int codigoBuscado;
    bool encontrado = false;
    ifstream file("professor_data.txt");

    cout << "\nIngrese el codigo del profesor: ";
    cin >> codigoBuscado;

    while (file >> profe.name_profe >> profe.last_name_profe >> profe.subject_profe >> profe.codigo_profe >> profe.salary_profe) {
        if (profe.codigo_profe == codigoBuscado) {
            encontrado = true;
            cout << "Nombre: " << profe.name_profe << endl;
            cout << "Apellido: " << profe.last_name_profe << endl;
            cout << "Materia: " << profe.subject_profe << endl;
            cout << "Codigo: " << profe.codigo_profe << endl;
            cout << "Salario: " << profe.salary_profe << endl;
            break;
        }
    }

    if (!encontrado)
        cout << "Codigo no encontrado." << endl;

    file.close();
}

void modificarProfesor() {
    Professor profe;
    int codigoBuscado;
    bool encontrado = false;
    ifstream file("professor_data.txt");
    ofstream temp("temp.txt");

    cout << "\nIngrese el codigo del profesor a modificar: ";
    cin >> codigoBuscado;

    while (file >> profe.name_profe >> profe.last_name_profe >> profe.subject_profe >> profe.codigo_profe >> profe.salary_profe) {
        if (profe.codigo_profe == codigoBuscado) {
            encontrado = true;
            cout << "Ingrese la nueva materia: ";
            cin >> profe.subject_profe;
            cout << "Ingrese el nuevo salario: ";
            cin >> profe.salary_profe;
            cout << "Datos modificados exitosamente." << endl;
        }
        temp << profe.name_profe << " " << profe.last_name_profe << " " << profe.subject_profe
             << " " << profe.codigo_profe << " " << profe.salary_profe << endl;
    }

    file.close();
    temp.close();

    remove("professor_data.txt");
    rename("temp.txt", "professor_data.txt");

    if (!encontrado)
        cout << "Codigo no encontrado." << endl;
}

void eliminarProfesor() {
    Professor profe;
    int codigoBuscado;
    bool encontrado = false;
    ifstream file("professor_data.txt");
    ofstream temp("temp.txt");

    cout << "\nIngrese el codigo del profesor a eliminar: ";
    cin >> codigoBuscado;

    while (file >> profe.name_profe >> profe.last_name_profe >> profe.subject_profe >> profe.codigo_profe >> profe.salary_profe) {
        if (profe.codigo_profe == codigoBuscado) {
            encontrado = true;
            cout << "Registro eliminado: " << profe.name_profe << " " << profe.last_name_profe << endl;
        } else {
            temp << profe.name_profe << " " << profe.last_name_profe << " " << profe.subject_profe
                 << " " << profe.codigo_profe << " " << profe.salary_profe << endl;
        }
    }

    file.close();
    temp.close();

    remove("professor_data.txt");
    rename("temp.txt", "professor_data.txt");

    if (!encontrado)
        cout << "Codigo no encontrado." << endl;
}
