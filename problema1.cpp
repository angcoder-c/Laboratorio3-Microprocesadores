/*
* Programacion de microprocesadores
 * Laboratorio 3
 * Angel Gabriel Chavez Otzoy
 * 24248
 * Problema 1: Ordenar un array de forma ascendnete usando algorithm
 */

#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main() {
 array <int, 3> arr;

 // obtener numeros
 for (int i = 0; i < 3; i++) {
  cout << "Numero " << i << ": ";
  cin >> arr[i];
 }

 // ordenar el array de inicio al final
 sort(arr.begin(), arr.end());

 // imprimir
 for (int i = 0; i < 3; i++) {
  cout << arr[i] << " ";
 }
 return 0;
}