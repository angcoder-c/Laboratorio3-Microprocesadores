/*
 * Programacion de microprocesadores
 * Laboratorio 3
 * Angel Gabriel Chavez Otzoy
 * 24248

================================================================================
Entrada             | Proceso                                    | Salida
====================+============================================+==============
Cantidad vendida    | Validar > 0                                |
-------------------------------------------------------------------------------
Costo por unidad    | Calcular diferencia entre precio y costo   | Utilidad total
-------------------------------------------------------------------------------
Precio de venta por | Multiplicar diferencia por cantidad vendida|
unidad              |                                            |
-------------------------------------------------------------------------------
 */
#include <iostream>

double calcularUtilidad(int cantidad, double costo, double precio) {
  if (cantidad > 0) {
   double utilidad = precio - costo;
   return cantidad * utilidad;
  }
 return 0;
}

int main() {
 std::cout << "Ejemplo: " << std::endl;
 std::cout << "Utilidad total: Q " << calcularUtilidad(10, 5.0, 7.5)<< std::endl;

 int cantidadVendida;
 double costoUnidad;
 double predioUnidad;

 std::cout << "Cantidad vendida: ";
 std::cin >> cantidadVendida;
 std::cout << "Costo por unidad: ";
 std::cin >> costoUnidad;
 std::cout << "Precio de venta: ";
 std::cin >> predioUnidad;
 std::cout << "Utilidad total: Q " << calcularUtilidad(cantidadVendida, costoUnidad, predioUnidad);
 return 0;
}
