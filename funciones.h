#ifndef FUNCIONES_H
#define FUNCIONES_H

float calcularAreaTriangulo3D(float x1, float y1, float z1,
                             float x2, float y2, float z2,
                             float x3, float y3, float z3);

float calcularVolumenConoTruncado3D(float x1, float y1, float z1,
                                    float x2, float y2, float z2,
                                    float x3, float y3, float z3);

float calcularVolumen(float cono[3][3]);

float calcularArea(float cono[3][3]);

void imprimirVolumenArea(float volumen1, float volumen2, float cono1[3][3], float cono2[3][3]);

#endif