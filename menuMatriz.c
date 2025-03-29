//Alcantara Rosete Adiel Jesus
#include <stdio.h>
#include <stdlib.h>
#define pf printf
#define sf scanf

#define MAX 10  // Tamaño máximo de las matrices
#define EPSILON 1e-10  // Tolerancia para determinar si un número es cero (para matrices inversas)

// Prototipos de funciones
void leerMatriz(double matriz[MAX][MAX], int filas, int columnas);
void imprimirMatriz(double matriz[MAX][MAX], int filas, int columnas);
int confirmarMatriz(double matriz[MAX][MAX], int filas, int columnas);
void sumarMatrices(double A[MAX][MAX], double B[MAX][MAX], int filas, int columnas, double C[MAX][MAX]);
void restarMatrices(double A[MAX][MAX], double B[MAX][MAX], int filas, int columnas, double C[MAX][MAX]);
void multiplicarMatrices(double A[MAX][MAX], double B[MAX][MAX], int filasA, int columnasA, int filasB, int columnasB, double C[MAX][MAX]);
void transponerMatriz(double A[MAX][MAX], int filas, int columnas, double T[MAX][MAX]);
double calcularDeterminante(double matriz[MAX][MAX], int n);
int invertirMatriz(double A[MAX][MAX], double inversa[MAX][MAX], int n);
void mostrarMenu();

int main() {
    int opcion;
    double A[MAX][MAX], B[MAX][MAX], C[MAX][MAX]; // Matrices
    int filasA, columnasA, filasB, columnasB;
    int confirmacion;

    do {
        mostrarMenu();
        pf("\nSeleccione una opcion: ");
        sf("%d", &opcion);

        switch (opcion) {
            case 1:
                pf("Suma de matrices (deben tener mismas dimensiones)\n");
                pf("Ingrese el numero de filas y columnas de las matrices: ");
                sf("%d %d", &filasA, &columnasA);

                // Lectura de la primera matriz
                pf("Matriz A:\n");
                leerMatriz(A, filasA, columnasA);
                confirmacion = confirmarMatriz(A, filasA, columnasA);
                if (!confirmacion) break;

                // Lectura de la segunda matriz
                pf("Matriz B:\n");
                leerMatriz(B, filasA, columnasA);
                confirmacion = confirmarMatriz(B, filasA, columnasA);
                if (!confirmacion) break;

                // Operación de suma
                sumarMatrices(A, B, filasA, columnasA, C);

                // Mostrar resultados
                pf("\nMatriz A:\n");
                imprimirMatriz(A, filasA, columnasA);
                pf("\nMatriz B:\n");
                imprimirMatriz(B, filasA, columnasA);
                pf("\nResultado de la suma:\n");
                imprimirMatriz(C, filasA, columnasA);
                break;

            case 2:
                pf("Resta de matrices (deben tener mismas dimensiones)\n");
                pf("Ingrese el numero de filas y columnas de las matrices: ");
                sf("%d %d", &filasA, &columnasA);

                // Lectura de la primera matriz
                pf("Matriz A:\n");
                leerMatriz(A, filasA, columnasA);
                confirmacion = confirmarMatriz(A, filasA, columnasA);
                if (!confirmacion) break;

                // Lectura de la segunda matriz
                pf("Matriz B:\n");
                leerMatriz(B, filasA, columnasA);
                confirmacion = confirmarMatriz(B, filasA, columnasA);
                if (!confirmacion) break;

                // Operación de resta
                restarMatrices(A, B, filasA, columnasA, C);

                // Mostrar resultados
                pf("\nMatriz A:\n");
                imprimirMatriz(A, filasA, columnasA);
                pf("\nMatriz B:\n");
                imprimirMatriz(B, filasA, columnasA);
                pf("\nResultado de la resta:\n");
                imprimirMatriz(C, filasA, columnasA);
                break;

            case 3:
                pf("Multiplicacion de matrices (A columnas debe ser igual a B filas)\n");
                pf("Ingrese las dimensiones de la matriz A (n x m): ");
                sf("%d %d", &filasA, &columnasA);
                pf("Ingrese las dimensiones de la matriz B (n x m): ");
                sf("%d %d", &filasB, &columnasB);

                if (columnasA != filasB) {
                    pf("Error: El numero de columnas de A debe ser igual al número de filas de B.\n");
                    break;
                }

                // Lectura de la primera matriz
                pf("Matriz A:\n");
                leerMatriz(A, filasA, columnasA);
                confirmacion = confirmarMatriz(A, filasA, columnasA);
                if (!confirmacion) break;

                // Lectura de la segunda matriz
                pf("Matriz B:\n");
                leerMatriz(B, filasB, columnasB);
                confirmacion = confirmarMatriz(B, filasB, columnasB);
                if (!confirmacion) break;

                // Operación de multiplicación
                multiplicarMatrices(A, B, filasA, columnasA, filasB, columnasB, C);

                // Mostrar resultados
                pf("\nMatriz A:\n");
                imprimirMatriz(A, filasA, columnasA);
                pf("\nMatriz B:\n");
                imprimirMatriz(B, filasB, columnasB);
                pf("\nResultado de la multiplicacion:\n");
                imprimirMatriz(C, filasA, columnasB);
                break;

            case 4:
                pf("Inversa de una matriz cuadrada\n");
                pf("Ingrese el tamaño de la matriz (solo ingresa n): ");
                sf("%d", &filasA);

                if (filasA > MAX) {
                    pf("El tamaño maximo permitido es %d.\n", MAX);
                    break;
                }

                double matriz[MAX][MAX], inversa[MAX][MAX];
                
                // Lectura de la matriz
                pf("Matriz A:\n");
                for (int i = 0; i < filasA; i++)
                    for (int j = 0; j < filasA; j++)
                        sf("%lf", &matriz[i][j]);

                confirmacion = confirmarMatriz(matriz, filasA, filasA);
                if (!confirmacion) break;

                // Verificar si la matriz es invertible
                if (invertirMatriz(matriz, inversa, filasA)) {
                    pf("\nLa matriz inversa es:\n");
                    imprimirMatriz(inversa, filasA, filasA);
                } else {
                    pf("La matriz no es invertible (determinante = 0).\n");
                }
                break;

            case 5:
                pf("Transposicion de una matriz\n");
                pf("Ingrese el numero de filas y columnas de la matriz (n x m): ");
                sf("%d %d", &filasA, &columnasA);

                // Lectura de la matriz
                pf("Matriz A:\n");
                leerMatriz(A, filasA, columnasA);
                confirmacion = confirmarMatriz(A, filasA, columnasA);
                if (!confirmacion) break;

                // Operación de transposición
                transponerMatriz(A, filasA, columnasA, C);

                // Mostrar resultados
                pf("\nMatriz original A:\n");
                imprimirMatriz(A, filasA, columnasA);
                pf("\nMatriz transpuesta:\n");
                imprimirMatriz(C, columnasA, filasA);
                break;

            case 6:
                pf("Determinante de una matriz cuadrada\n");
                pf("Ingrese el tamaño de la matriz (solo ingresa n): ");
                sf("%d", &filasA);

                if (filasA > MAX) {
                    pf("El tamaño maximo permitido es %d.\n", MAX);
                    break;
                }

                double matrizDet[MAX][MAX];
                
                // Lectura de la matriz
                pf("Matriz A:\n");
                for (int i = 0; i < filasA; i++)
                    for (int j = 0; j < filasA; j++)
                        sf("%lf", &matrizDet[i][j]);

                confirmacion = confirmarMatriz(matrizDet, filasA, filasA);
                if (!confirmacion) break;

                // Cálculo del determinante
                double determinante = calcularDeterminante(matrizDet, filasA);

                // Mostrar resultados
                pf("\nMatriz A:\n");
                imprimirMatriz(matrizDet, filasA, filasA);
                pf("\nDeterminante: %.5lf\n", determinante);
                break;

            case 7:
                pf("Saliste del programa\n");
                break;

            default:
                pf("Opcion no valida. Intenta de nuevo.\n");
        }

    } while (opcion != 7);

    return 0;
}

// FUNCIONES VOID
void leerMatriz(double matriz[MAX][MAX], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            pf("Elemento [%d][%d]: ", i, j);
            sf("%lf", &matriz[i][j]);
        }
    }
}

void imprimirMatriz(double matriz[MAX][MAX], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            pf("%.2lf ", matriz[i][j]);
        }
        pf("\n");
    }
}

int confirmarMatriz(double matriz[MAX][MAX], int filas, int columnas) {
    int confirmacion;
    pf("\nLa matriz ingresada es la siguiente:\n");
    imprimirMatriz(matriz, filas, columnas);
    pf("\n¿Es correcta? (1: Si, 0: No): ");
    sf("%d", &confirmacion);
    return confirmacion;
}

void sumarMatrices(double A[MAX][MAX], double B[MAX][MAX], int filas, int columnas, double C[MAX][MAX]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void restarMatrices(double A[MAX][MAX], double B[MAX][MAX], int filas, int columnas, double C[MAX][MAX]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiplicarMatrices(double A[MAX][MAX], double B[MAX][MAX], int filasA, int columnasA, int filasB, int columnasB, double C[MAX][MAX]) {
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < columnasA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transponerMatriz(double A[MAX][MAX], int filas, int columnas, double T[MAX][MAX]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            T[j][i] = A[i][j];
        }
    }
}

// FUNCION PARA CALCULAR EL DETERMINANTE USANDO ELIMINACION GAUSSIANA
double calcularDeterminante(double matriz[MAX][MAX], int n) {
    double det = 1;
    for (int i = 0; i < n; i++) {
        if (matriz[i][i] < EPSILON && matriz[i][i] > -EPSILON) {
            int swapRow = -1;
            for (int k = i + 1; k < n; k++) {
                if (matriz[k][i] > EPSILON || matriz[k][i] < -EPSILON) {
                    swapRow = k;
                    break;
                }
            }
            if (swapRow == -1) return 0;  // Matriz no tiene inversa (det = 0)
            // Intercambiar filas
            for (int j = 0; j < n; j++) {
                double temp = matriz[i][j];
                matriz[i][j] = matriz[swapRow][j];
                matriz[swapRow][j] = temp;
            }
            det = -det;  // Cambia signo del determinante
        }
        det *= matriz[i][i];
        for (int k = i + 1; k < n; k++) {
            double factor = matriz[k][i] / matriz[i][i];
            for (int j = i; j < n; j++) {
                matriz[k][j] -= factor * matriz[i][j];
            }
        }
    }
    return det;
}

// FUNCION PARA CALCULAR LA MATRIZ INVERSA USANDO EL METODO DE GAUSS-JORDAN
int invertirMatriz(double A[MAX][MAX], double inversa[MAX][MAX], int n) {
    double temp[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = A[i][j];
            inversa[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (temp[i][i] < EPSILON && temp[i][i] > -EPSILON) {
            int swapRow = -1;
            for (int k = i + 1; k < n; k++) {
                if (temp[k][i] > EPSILON || temp[k][i] < -EPSILON) {
                    swapRow = k;
                    break;
                }
            }
            if (swapRow == -1) return 0;  // No es invertible
            // Intercambiar filas
            for (int j = 0; j < n; j++) {
                double t = temp[i][j];
                temp[i][j] = temp[swapRow][j];
                temp[swapRow][j] = t;

                t = inversa[i][j];
                inversa[i][j] = inversa[swapRow][j];
                inversa[swapRow][j] = t;
            }
        }

        // Escalar la fila i
        double divisor = temp[i][i];
        for (int j = 0; j < n; j++) {
            temp[i][j] /= divisor;
            inversa[i][j] /= divisor;
        }

        // Eliminar los elementos encima y debajo de la diagonal
        for (int k = 0; k < n; k++) {
            if (k == i) continue;
            double factor = temp[k][i];
            for (int j = 0; j < n; j++) {
                temp[k][j] -= factor * temp[i][j];
                inversa[k][j] -= factor * inversa[i][j];
            }
        }
    }
    return 1;
}

void mostrarMenu() {
    pf("\nMenu de Operaciones con Matrices:\n");
    pf("\n1. Suma de matrices\n");
    pf("2. Resta de matrices\n");
    pf("3. Multiplicacion de matrices\n");
    pf("4. Matriz inversa\n");
    pf("5. Matriz traspuesta\n");
    pf("6. Determinante de una matriz\n");
    pf("7. Salir\n");
}
