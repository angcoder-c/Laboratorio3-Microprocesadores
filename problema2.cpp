/*
* Programacion de microprocesadores
 * Laboratorio 3
 * Angel Gabriel Chavez Otzoy
 * 24248
 * Problema 2
• Conversión usando static_cast<char>
 */
#include <iostream>
#include <string>

using namespace std;

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

int main() {
 string option = "";

 while (option != "0") {
  cout << "BIENVENIDO\no [1] Ver tabla ASCII completa\no [2] Convertir número al carácter ASCII correspondiente\no [0] Salir\n>>> ";
  cin >> option;

  if (option == "1") {
   // tabla de caracteres ascii imprimibles
   cout << "======================\nCaracteres ASCII imprimibles\n======================" << endl;
   for (int i=32; i<80;i++) {
    cout << "ASCII-" << i << " "<< static_cast<char>(i);
    cout << "\t ASCII-" << i+48 << " "<< static_cast<char>(i+48) << endl;
   }
  }

  if (option == "2") {
   string input;
   cout << "Entrada: ";
   cin >> input;

   if (isNumber(input)) {
    int input_int = stoi(input);
    if (input_int >= 0 && input_int <= 127) {
     // casteo de numeros a char
     cout << "ASCII-" << input << " "<< static_cast<char>(input_int) << endl;
    } else {
     cout << "ERROR: entrada " << input << " invalida." << endl;
    }
   }  else {
    cout << "ERROR: entrada '" << input << "' invalida." << endl;
   }
  }
 }
}