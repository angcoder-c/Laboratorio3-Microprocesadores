/*
* Programacion de microprocesadores
 * Laboratorio 3
 * Angel Gabriel Chavez Otzoy
 * 24248

Calcular porcentaje de masa corporal

Para hombres:
Grasa Corporal% = 86.010⋅log_10(cintura−cuello)−70.041⋅log_10(altura)+36.76

Para mujeres:
Grasa Corporal% = 163.205⋅log_10(cintura+cadera−cuello)−97.684⋅log_10(altura)−78.387

*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// constantes para el porcentaje de grasa corporal de hombres
const double MC1 = 86.010;
const double MC2 = 70.041;
const double MC3 = 36.76;

// constes para el porcentaje de grasa corporal de mujeres
const double FC1 = 163.205;
const double FC2 = 97.684;
const double FC3 = 78.387;

bool isNumber (string str) {
    // verificar que todos los caracteres del string sean numeros
    bool valid = true;
    for (char c : str) {
        if (c >= '0' && c <= '9') {
            valid = true;
        } else {
            valid = false;
        }
    }
    return valid;
}

struct Persona {
    string nombre;
    // M F
    char sexo;

    // cm
    double cintura;
    double cuello;
    double altura;
    double cadera;
};

double calcularGrasa (Persona p) {
    double result = NULL;
    switch (p.sexo) {
        case 'M':
            result = MC1 * log10(p.cintura-p.cuello) - MC2 * log10(p.altura) + MC3;
            break;
        case 'F':
            result = FC1 * log10(p.cintura*p.cadera - p.cuello) - FC2 * log10(p.altura) - FC3;
            cout << "F" << endl;
            break;
        default:
            cout << "\nERROR: sexo no soportado." << endl;
            break;
    }
    return result;
}

double getData (string name) {
    double value;
    cout << name;
    cin >> value;
    return value;
}

char getSexo (string name) {
    char value;
    cout << name;
    cin >> value;
    if (value == 'M' || value == 'F') {
        return value;
    }
    return 'M';

}

int main() {
    Persona p;
    // petiion de datos
    cout << "Nombre: ";
    getline(cin, p.nombre);

    if (!cin.fail()) {
        p.sexo = getSexo("Sexo (M/F): ");
    }

    if (!cin.fail()) {
        p.altura = getData("Altura (cm): ");
    }

    if (!cin.fail()) {
        p.cuello = getData("Cuello (cm): ");
    }

    if (!cin.fail()) {
        p.cintura = getData("Cintura (cm): ");
    }

    if (p.sexo == 'F' && !cin.fail()) {
        p.cadera = getData("Cadera (cm): ");
    }

    if (cin.fail()) {
        cout << "ERROR: tipo de dato no soportado." << endl;
        cout.clear();
        cin.clear();
    } else {
        double grasa = calcularGrasa(p);
        // dos decimales
        cout << fixed << setprecision(2);
        cout << "Nombre\t"  << "Sexo\t" << "Grasa (%)" << endl;
        cout << p.nombre << "\t" << p.sexo << "\t" << grasa << endl;
    }
    return 0;
}