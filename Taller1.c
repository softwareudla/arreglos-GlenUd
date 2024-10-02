#include <stdio.h>
#include <string.h>

int main() {
    char asig[3][20] = {"Ingles", "Calculo", "Fisica"};
    char nombres[5][20];
    double nots[5][3];
    int e = 1;
    double nota_minima_aprobacion = 6.0;
    for (int i = 0; i < 5; i++) {
        printf("Ingrese nombre %d: ", e++);
        fgets(nombres[i], 20, stdin);
        nombres[i][strcspn(nombres[i], "\n")] = '\0'; 
    }
    for (int g = 0; g < 3; g++) {
        printf("-----------------------------------\n");
        printf("Asignatura: %s\n", asig[g]);
        for (int j = 0; j < 5; j++) {
            printf("Ingrese la nota de %s: ", nombres[j]);
            scanf("%lf", &nots[j][g]);
        }
    }
    for (int i = 0; i < 3; i++) {
        double max = 0, min = 10, prom = 0;
        for (int j = 0; j < 5; j++) {
            if (nots[j][i] > max) {
                max = nots[j][i];
            }
            if (nots[j][i] < min) {
                min = nots[j][i];
            }
            prom += nots[j][i];
        }
        printf("\nResultados para la asignatura %s:\n", asig[i]);
        printf("Nota máxima: %.2lf\n", max);
        printf("Nota mínima: %.2lf\n", min);
        printf("Promedio: %.2lf\n", prom / 5);
    }
    for (int j = 0; j < 5; j++) {
        double suma_notas = 0, promedio;
        for (int i = 0; i < 3; i++) {
            suma_notas += nots[j][i];
        }
        promedio = suma_notas / 3;
        if (promedio >= nota_minima_aprobacion) {
            printf("\n%s aprueba con un promedio de %.2lf\n", nombres[j], promedio);
        } else {
            printf("\n%s reprueba con un promedio de %.2lf\n", nombres[j], promedio);
        }
    }
    return 0;
}