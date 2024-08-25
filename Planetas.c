#include <stdio.h>
#include <math.h>

#define DIAS_EN_10_ANIOS 3650
#define PI 3.14159265358979323846

typedef struct {
    double x, y;
} Punto;

Punto calcular_posicion(double distancia, double angulo) {
    Punto p;
    p.x = distancia * cos(angulo * PI / 180.0);
    p.y = distancia * sin(angulo * PI / 180.0);
    return p;
}

int estan_alineados(Punto p1, Punto p2, Punto p3) {
    double pendiente1 = (p2.y - p1.y) / (p2.x - p1.x);
    double pendiente2 = (p3.y - p2.y) / (p3.x - p2.x);
    return fabs(pendiente1 - pendiente2) < 1e-9;
}

double calcular_perimetro(Punto p1, Punto p2, Punto p3) {
    double lado1 = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    double lado2 = sqrt(pow(p3.x - p2.x, 2) + pow(p3.y - p2.y, 2));
    double lado3 = sqrt(pow(p1.x - p3.x, 2) + pow(p1.y - p3.y, 2));
    return lado1 + lado2 + lado3;
}

int sol_en_triangulo(Punto sol, Punto p1, Punto p2, Punto p3) {
    double area_total = fabs((p1.x*(p2.y-p3.y) + p2.x*(p3.y-p1.y) + p3.x*(p1.y-p2.y)) / 2.0);
    double area1 = fabs((sol.x*(p2.y-p3.y) + p2.x*(p3.y-sol.y) + p3.x*(sol.y-p2.y)) / 2.0);
    double area2 = fabs((p1.x*(sol.y-p3.y) + sol.x*(p3.y-p1.y) + p3.x*(sol.y-p2.y)) / 2.0);
    double area3 = fabs((p1.x*(p2.y-sol.y) + p2.x*(sol.y-p1.y) + sol.x*(p1.y-p2.y)) / 2.0);
    return fabs(area_total - (area1 + area2 + area3)) < 1e-9;
}

int main() {
    int dias_sequia = 0, dias_lluvia = 0, dias_optimos = 0;
    int dia_pico_lluvia = 0;
    double max_perimetro = 0;

    Punto sol = {0, 0};

    for (int dia = 0; dia <= DIAS_EN_10_ANIOS; dia++) {
        double angulo_ferengi = fmod(dia * 1, 360.0);
        double angulo_betasoide = fmod(dia * 3, 360.0);
        double angulo_vulcano = fmod(360.0 - dia * 5, 360.0);

        Punto ferengi = calcular_posicion(500, angulo_ferengi);
        Punto betasoide = calcular_posicion(2000, angulo_betasoide);
        Punto vulcano = calcular_posicion(1000, angulo_vulcano);

        if (estan_alineados(ferengi, betasoide, vulcano)) {
            if (estan_alineados(ferengi, betasoide, sol)) {
                dias_sequia++;
            } else {
                dias_optimos++;
            }
        } else {
            double perimetro = calcular_perimetro(ferengi, betasoide, vulcano);
            if (sol_en_triangulo(sol, ferengi, betasoide, vulcano)) {
                dias_lluvia++;
                if (perimetro > max_perimetro) {
                    max_perimetro = perimetro;
                    dia_pico_lluvia = dia;
                }
            }
        }
    }

    printf("Periodos de sequia: %d\n", dias_sequia);
    printf("Periodos de lluvia: %d\n", dias_lluvia);
    printf("Dia pico de lluvia: %d\n", dia_pico_lluvia);
    printf("Periodos de condiciones optimas: %d\n", dias_optimos);

    return 0;
}
