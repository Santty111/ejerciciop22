#include "funciones.h"
#include <math.h>
#include <stdio.h>

// Función para calcular el área de un triángulo en 3D
float calcularAreaTriangulo3D(float x1, float y1, float z1,
                             float x2, float y2, float z2,
                             float x3, float y3, float z3) {
    float a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
    float b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2) + pow(z3 - z2, 2));
    float c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2) + pow(z1 - z3, 2));
    
    float s = (a + b + c) / 2;
    
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Función para calcular el volumen de un cono truncado en 3D
float calcularVolumenConoTruncado3D(float x1, float y1, float z1,
                                    float x2, float y2, float z2,
                                    float x3, float y3, float z3) {
    float area1 = calcularAreaTriangulo3D(x1, y1, z1, x2, y2, z2, x3, y3, z3);
    float h = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2) + pow(z1 - z3, 2));
    
    return (1.0 / 3.0) * area1 * h;
}

// Función para calcular el volumen de un cono
float calcularVolumen(float cono[3][3]) {
    float x1 = cono[0][0];
    float y1 = cono[0][1];
    float z1 = cono[0][2];
    float x2 = cono[1][0];
    float y2 = cono[1][1];
    float z2 = cono[1][2];
    float x3 = cono[2][0];
    float y3 = cono[2][1];
    float z3 = cono[2][2];
    
    return (1.0 / 3.0) * M_PI * pow(x1, 2) * sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

// Función para calcular el área de un cono
float calcularArea(float cono[3][3]) {
    float x1 = cono[0][0];
    float y1 = cono[0][1];
    float z1 = cono[0][2];
    float x2 = cono[1][0];
    float y2 = cono[1][1];
    float z2 = cono[1][2];
    float x3 = cono[2][0];
    float y3 = cono[2][1];
    float z3 = cono[2][2];
    
    return calcularAreaTriangulo3D(x1, y1, z1, x2, y2, z2, x3, y3, z3) + M_PI * pow(x1, 2);
}

// Función para imprimir los resultados de volumen y área de los conos y el cono truncado
void imprimirVolumenArea(float volumen1, float volumen2, float cono1[3][3], float cono2[3][3]) {
    printf("Volumen del primer cono: %.2f\n", volumen1);
    printf("Área del primer cono: %.2f\n", calcularArea(cono1));
    printf("Volumen del segundo cono: %.2f\n", volumen2);
    printf("Área del segundo cono: %.2f\n", calcularArea(cono2));
    
    float conoTruncado[3][3];
    conoTruncado[0][0] = cono1[0][0];
    conoTruncado[0][1] = cono1[0][1];
    conoTruncado[0][2] = cono1[0][2];
    conoTruncado[1][0] = cono1[1][0];
    conoTruncado[1][1] = cono1[1][1];
    conoTruncado[1][2] = cono1[1][2];
    conoTruncado[2][0] = cono2[2][0];
    conoTruncado[2][1] = cono2[2][1];
    conoTruncado[2][2] = cono2[2][2];
    
    float volumenTruncado = calcularVolumen(conoTruncado);
    printf("Volumen del cono truncado: %.2f\n", volumenTruncado);
    printf("Área del cono truncado: %.2f\n", calcularArea(conoTruncado));
}