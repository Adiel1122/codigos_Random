// Codigo que resuelve ecuaciones matriciales bien huevudo
#include <stdio.h>
#include <stdlib.h>

#define pf printf
#define sf scanf
#define MAX 20  // Tamaño máximo de la matriz

// Prototipos de funciones
void pedirMatrices(int n, double A[MAX][MAX], double B[MAX], double C[MAX]);
void pedirMatrizSimple(int n, double M[MAX][MAX]);
void imprimirMatriz(int n, double A[MAX][MAX]);
void imprimirVector(int n, double V[MAX]);
void confirmacion();
void gauss(int n, double A[MAX][MAX], double B[MAX], double X[MAX]);
void resolverXmasB(int n, double B[MAX], double C[MAX], double X[MAX]);
void resolverAXigualC(int n, double A[MAX][MAX], double C[MAX], double X[MAX]);
void resolverXAigualC(int n, double A[MAX][MAX], double C[MAX], double X[MAX]);
void resolverAXmasBXigualC(int n, double A[MAX][MAX], double B[MAX][MAX], double C[MAX], double X[MAX]);

int main() {
    int opcion, n;
    double A[MAX][MAX], B[MAX][MAX], C[MAX], X[MAX];

    do {
        // Mostrar el menú
        pf("\nMenu de Ecuaciones Matriciales:\n");
        pf("\n1. X + B = C\n");
        pf("2. AX = C\n");
        pf("3. XA = C\n");
        pf("4. AX + BX = C\n");
        pf("5. Salir\n");
        pf("\nSelecciona una opcion: ");
        sf("%d", &opcion);

        // Verificar la opción seleccionada
        if (opcion >= 1 && opcion <= 4) {
            // Pedir el tamaño de la matriz
            pf("Ingrese el tamaño de la matriz (n x n) (máximo %d): ", MAX);
            sf("%d", &n);

            // Verificar que el tamaño sea válido
            if (n <= 0 || n > MAX) {
                pf("El tamaño de la matriz debe estar entre 1 y %d.\n", MAX);
                continue;  // Volver al menú
            }
        }

        switch (opcion) {
            case 1:
                // X + B = C
                pf("\nResolviendo X + B = C\n");
                pf("Ingrese los valores de B (vector):\n");
                for (int i = 0; i < n; i++) {
                    pf("B[%d]: ", i);
                    sf("%lf", &B[i][0]);
                }
                pf("Ingrese los valores de C (vector):\n");
                for (int i = 0; i < n; i++) {
                    pf("C[%d]: ", i);
                    sf("%lf", &C[i]);
                }

                // Mostrar las matrices ingresadas
                pf("\nVector B:\n");
                imprimirVector(n, B[0]);
                pf("\nVector C:\n");
                imprimirVector(n, C);

                // Confirmar
                confirmacion();

                // Resolver X + B = C
                resolverXmasB(n, B[0], C, X);

                // Mostrar la solución
                pf("\nLa solución del sistema es:\n");
                for (int i = 0; i < n; i++) {
                    pf("X[%d] = %.6f\n", i, X[i]);
                }
                break;

            case 2:
                // AX = C
                pf("\nResolviendo AX = C\n");
                pedirMatrices(n, A, B[0], C);

                // Mostrar las matrices ingresadas
                pf("\nMatriz A:\n");
                imprimirMatriz(n, A);
                pf("\nVector C:\n");
                imprimirVector(n, C);

                // Confirmar
                confirmacion();

                // Resolver AX = C
                resolverAXigualC(n, A, C, X);

                // Mostrar la solución
                pf("\nLa solución del sistema es:\n");
                for (int i = 0; i < n; i++) {
                    pf("X[%d] = %.6f\n", i, X[i]);
                }
                break;

            case 3:
                // XA = C
                pf("\nResolviendo XA = C\n");
                pedirMatrizSimple(n, A);
                pf("Ingrese los valores del vector C:\n");
                for (int i = 0; i < n; i++) {
                    pf("C[%d]: ", i);
                    sf("%lf", &C[i]);
                }

                // Mostrar las matrices ingresadas
                pf("\nMatriz A:\n");
                imprimirMatriz(n, A);
                pf("\nVector C:\n");
                imprimirVector(n, C);

                // Confirmar
                confirmacion();

                // Resolver XA = C
                resolverXAigualC(n, A, C, X);

                // Mostrar la solución
                pf("\nLa solución del sistema es:\n");
                for (int i = 0; i < n; i++) {
                    pf("X[%d] = %.6f\n", i, X[i]);
                }
                break;

            case 4:
                // AX + BX = C
                pf("\nResolviendo AX + BX = C\n");
                pf("Ingrese la matriz A (%dx%d):\n", n, n);
                pedirMatrizSimple(n, A);
                pf("Ingrese la matriz B (%dx%d):\n", n, n);
                pedirMatrizSimple(n, B);
                pf("Ingrese los valores del vector C:\n");
                for (int i = 0; i < n; i++) {
                    pf("C[%d]: ", i);
                    sf("%lf", &C[i]);
                }

                // Mostrar las matrices ingresadas
                pf("\nMatriz A:\n");
                imprimirMatriz(n, A);
                pf("\nMatriz B:\n");
                imprimirMatriz(n, B);
                pf("\nVector C:\n");
                imprimirVector(n, C);

                // Confirmar
                confirmacion();

                // Resolver AX + BX = C
                resolverAXmasBXigualC(n, A, B, C, X);

                // Mostrar la solución
                pf("\nLa solución del sistema es:\n");
                for (int i = 0; i < n; i++) {
                    pf("X[%d] = %.6f\n", i, X[i]);
                }
                break;

            case 5:
                // Salir del programa
                pf("Saliste del programa\n");
                break;

            default:
                pf("Opción no válida. Intenta nuevamente.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}

// Función para pedir las matrices A y C al usuario
void pedirMatrices(int n, double A[MAX][MAX], double B[MAX], double C[MAX]) {
    pf("Ingrese los elementos de la matriz A (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pf("A[%d][%d]: ", i, j);
            sf("%lf", &A[i][j]);
        }
    }

    pf("Ingrese los elementos del vector C (%dx1):\n", n);
    for (int i = 0; i < n; i++) {
        pf("C[%d]: ", i);
        sf("%lf", &C[i]);
    }
}

// Función para pedir una matriz simple
void pedirMatrizSimple(int n, double M[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pf("M[%d][%d]: ", i, j);
            sf("%lf", &M[i][j]);
        }
    }
}

// Función para imprimir una matriz
void imprimirMatriz(int n, double A[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pf("%10.4f ", A[i][j]);
        }
        pf("\n");
    }
}

// Función para imprimir un vector
void imprimirVector(int n, double V[MAX]) {
    for (int i = 0; i < n; i++) {
        pf("%10.4f\n", V[i]);
    }
}

// Función para confirmar si las matrices son correctas
void confirmacion() {
    char confirm;
    pf("\n¿Son correctas estas matrices? (s/n): ");
    sf(" %c", &confirm);
    if (confirm != 's' && confirm != 'S') {
        pf("Operación cancelada por el usuario.\n");
        exit(0);
    }
}

// Función para resolver X + B = C -> X = C - B
void resolverXmasB(int n, double B[MAX], double C[MAX], double X[MAX]) {
    for (int i = 0; i < n; i++) {
        X[i] = C[i] - B[i];
    }
}

// Función para resolver AX = C usando eliminación de Gauss
void resolverAXigualC(int n, double A[MAX][MAX], double C[MAX], double X[MAX]) {
    gauss(n, A, C, X);
}

// Función para resolver XA = C (X es un vector fila)
void resolverXAigualC(int n, double A[MAX][MAX], double C[MAX], double X[MAX]) {
    // Esto es equivalente a resolver A^T * X^T = C^T
    double AT[MAX][MAX];

    // Transponer A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AT[i][j] = A[j][i];
        }
    }

    // Resolver el sistema transpuesto usando eliminación de Gauss
    gauss(n, AT, C, X);
}

// Función para resolver AX + BX = C
void resolverAXmasBXigualC(int n, double A[MAX][MAX], double B[MAX][MAX], double C[MAX], double X[MAX]) {
    // Crear una matriz A' = A + B
    double AplusB[MAX][MAX];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AplusB[i][j] = A[i][j] + B[i][j];
        }
    }

    // Resolver el sistema AplusB * X = C usando eliminación de Gauss
    gauss(n, AplusB, C, X);
}

// Función para realizar la eliminación de Gauss
void gauss(int n, double A[MAX][MAX], double B[MAX], double X[MAX]) {
    // Eliminación hacia adelante
    for (int i = 0; i < n; i++) {
        if (A[i][i] == 0) {
            pf("Error: el sistema no tiene solución única.\n");
            exit(1);
        }

        for (int j = i + 1; j < n; j++) {
            double factor = A[j][i] / A[i][i];
            for (int k = i; k < n; k++) {
                A[j][k] -= factor * A[i][k];
            }
            B[j] -= factor * B[i];
        }
    }

    // Sustitución hacia atrás
    for (int i = n - 1; i >= 0; i--) {
        X[i] = B[i];
        for (int j = i + 1; j < n; j++) {
            X[i] -= A[i][j] * X[j];
        }
        X[i] /= A[i][i];
    }
}