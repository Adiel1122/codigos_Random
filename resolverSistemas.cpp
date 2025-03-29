#include <stdio.h>  
#include <stdlib.h>  
#include <math.h> 
#define pf printf
#define sf scanf

#define MAX 5  // Número máximo de ecuaciones/variables  

void imprimirMatriz(float matriz[MAX][MAX + 1], int n) {  
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j <= n; j++) {  
            printf("%0.2f\t", matriz[i][j]);  
        }  
        printf("\n");  
    }  
}  

void resolverSistema(float matriz[MAX][MAX + 1], int n) {  
    int i, j, k, col;  
    float factor;  
    
    // Método de eliminación de Gauss  
    for (col = 0; col < n; col++) {  
        // Búsqueda del máximo para el pivote  
        float max = fabs(matriz[col][col]);  
        int maxFila = col;  
        for (k = col + 1; k < n; k++) {  
            if (fabs(matriz[k][col]) > max) {  
                max = fabs(matriz[k][col]);  
                maxFila = k;  
            }  
        }  

        // Intercambiar filas  
        for (k = col; k <= n; k++) {  
            float temp = matriz[maxFila][k];  
            matriz[maxFila][k] = matriz[col][k];  
            matriz[col][k] = temp;  
        }  

        // Hacer ceros en la columna  
        for (k = col + 1; k < n; k++) {  
            factor = matriz[k][col] / matriz[col][col];  
            for (j = col; j <= n; j++) {  
                matriz[k][j] -= factor * matriz[col][j];  
            }  
        }  
    }  

    // Verificar si hay soluciones  
    int filasConCero = 0; // Contador para filas de ceros  
    for (i = 0; i < n; i++) {  
        int esCero = 1;  
        for (j = 0; j < n; j++) {  
            if (matriz[i][j] != 0) {  
                esCero = 0; // Si encontramos un elemento distinto de cero  
                break;  
            }  
        }  
        if (esCero && matriz[i][n] != 0) {  
            printf("El sistema no tiene solución.\n");  
            return; // Si hay una fila de ceros en la parte de coeficientes y un número distinto de cero en la constante  
        }  
        if (esCero) {  
            filasConCero++; // Contamos las filas de ceros  
        }  
    }  

    // Sustitución hacia atrás  
    float soluciones[MAX];  
    for (i = n - 1; i >= 0; i--) {  
        soluciones[i] = matriz[i][n];  
        for (j = i + 1; j < n; j++) {  
            soluciones[i] -= matriz[i][j] * soluciones[j];  
        }  
        if (matriz[i][i] != 0) {  
            soluciones[i] /= matriz[i][i];  
        }  
    }  

    // Evaluar cuántas soluciones hay  
    if (filasConCero > 0) {  
        printf("El sistema tiene infinitas soluciones.\n");  
    } else {  
        printf("Las soluciones son:\n");  
        for (i = 0; i < n; i++) {  
            printf("x[%d] = %0.2f\n", i + 1, soluciones[i]);  
        }  
    }  
}  

int main() {  
    float matriz[MAX][MAX + 1];  // Matriz aumentada  
    int n;  

    printf("Introduce el número de ecuaciones (máximo %d): ", MAX);  
    scanf("%d", &n);  

    if (n < 1 || n > MAX) {  
        printf("Número de ecuaciones no válido. Debe estar entre 1 y %d.\n", MAX);  
        return 1;  
    }  

    printf("Introduce los coeficientes del sistema de ecuaciones (incluyendo la constante):\n");  
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j <= n; j++) {  // j hasta n para incluir la constante  
            scanf("%f", &matriz[i][j]);  
        }  
    }  

    printf("\nMatriz Aumentada:\n");  
    imprimirMatriz(matriz, n);  

    resolverSistema(matriz, n);  

    return 0;  
}