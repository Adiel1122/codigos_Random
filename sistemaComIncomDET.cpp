#include <stdio.h>  
#include <stdbool.h>  
#define pf printf  
#define sf scanf  
#define MAX 10  

// Prototypes  
void printMatrix(float matrix[MAX][MAX], int rows, int cols);  
bool isInconsistent(float matrix[MAX][MAX], int rows, int cols);  
bool isDetermined(float matrix[MAX][MAX], int rows, int cols);  
bool isIndeterminate(float matrix[MAX][MAX], int rows, int cols);  

int main() {  
    int rows, cols;  
    float matrix[MAX][MAX];  
    char choice;  

    do {  
        pf("Introduce el numero de ecuaciones (filas): ");  
        sf("%d", &rows);  
        pf("Introduce el numero de variables (columnas): ");  
        sf("%d", &cols);  
        cols++; // Increase to include the independent term  

        // Input matrix  
        pf("Introduce los coeficientes de la matriz (%d x %d):\n", rows, cols);  
        for (int i = 0; i < rows; i++) {  
            for (int j = 0; j < cols; j++) {  
                if (j == cols - 1) { // Independent term  
                    pf("Introduce el termino independiente (el que sigue despues del =) para la fila %d: ", i + 1);  
                } else {  
                    pf("Introduce el coeficiente de x[%d][%d]: ", i + 1, j + 1);  
                }  
                sf("%f", &matrix[i][j]);  
            }  
        }  

        // Print the entered matrix  
        pf("La matriz introducida es:\n");  
        printMatrix(matrix, rows, cols);  

        // Ask the user if they are sure that this is the correct matrix  
        pf("¿Estas seguro que esta es la matriz correcta? (S/N): ");  
        sf(" %c", &choice);  

    } while (choice == 'N' || choice == 'n'); // Re-enter matrix if the answer is no  

    // Option menu  
    int option;  
    do {   
		pf("----------------------------------------------------------"); 
        pf("\n1. Verificar si el sistema es incompatible\n");  
        pf("2. Verificar si el sistema es compatible determinado\n");  
        pf("3. Verificar si el sistema es compatible indeterminado\n");  
        pf("4. Volver a ingresar la matriz\n");  
        pf("5. Salir\n");  
        pf("\nSelecciona una opcion: ");  
        sf("%d", &option);  

        switch (option) {  
            case 1:  
                if (isInconsistent(matrix, rows, cols)) {  
                    pf("\nEl sistema ES INCOMPATIBLE\n");  
                } else {  
                    pf("\nEl sistema NO ES INCOMPATIBLE\n");  
                }  
                break;  
            case 2:  
                if (isDetermined(matrix, rows, cols)) {  
                    pf("\nEl sistema ES compatible DETERMINADO\n");  
                } else {  
                    pf("\nEl sistema NO ES compatible DETERMINADO.\n");  
                }  
                break;  
            case 3:  
                if (isIndeterminate(matrix, rows, cols)) {  
                    pf("\nEl sistema ES compatible INDETERMINADO.\n");  
                } else {  
                    pf("\nEl sistema NO ES compatible INDETERMINADO.\n");  
                }  
                break;  
            case 4:  
                // Logic to allow re-entering the matrix goes here  
                do {  
                    pf("Introduce el número de ecuaciones (filas): ");  
                    sf("%d", &rows);  
                    pf("Introduce el número de variables (columnas): ");  
                    sf("%d", &cols);  
                    cols++; // Increase to include the independent term  

                    // Input matrix  
                    pf("Introduce los coeficientes de la matriz (%d x %d):\n", rows, cols);  
                    for (int i = 0; i < rows; i++) {  
                        for (int j = 0; j < cols; j++) {  
                            if (j == cols - 1) { // Independent term  
                                pf("Introduce el termino independiente (el que sigue despues del =) para la fila %d: ", i + 1);  
                            } else {  
                                pf("Introduce el coeficiente de x[%d][%d]: ", i + 1, j + 1);  
                            }  
                            sf("%f", &matrix[i][j]);  
                        }  
                    }  

                    // Print the newly entered matrix  
                    pf("La nueva matriz introducida es:\n");  
                    printMatrix(matrix, rows, cols);  

                    // Confirm the new matrix  
                    pf("Estas seguro que esta es la nueva matriz correcta? (S/N): ");  
                    sf(" %c", &choice);  
                } while (choice == 'N' || choice == 'n'); // Re-enter if not confirmed  
                break;  
            case 5:  
                pf("Saliste del programa\n");  
                break;  
            default:  
                printf("Opción no válida. Intente de nuevo.\n");  
        }  
    } while (option != 5);  

    return 0;  
}  

// Function to print the matrix  
void printMatrix(float matrix[MAX][MAX], int rows, int cols) {  
    for (int i = 0; i < rows; i++) {  
        for (int j = 0; j < cols; j++) {  
            pf("%7.2f ", matrix[i][j]);  
        }  
        pf("\n");  
    }  
}  

// Implementing functions to verify the type of system  
bool isInconsistent(float matrix[MAX][MAX], int rows, int cols) {  
    // Check if there is a row where all coefficients are zero but the independent term is not zero  
    for (int i = 0; i < rows; i++) {  
        bool allZero = true;  
        for (int j = 0; j < cols - 1; j++) {  
            if (matrix[i][j] != 0) {  
                allZero = false;  
                break;  
            }  
        }  
        if (allZero && matrix[i][cols - 1] != 0) {  
            return true; // Inconsistent  
        }  
    }  
    return false; // Not inconsistent  
}  

bool isDetermined(float matrix[MAX][MAX], int rows, int cols) {  
    // A system is compatible determined if the number of equations equals the number of unknowns and the determinant is not zero  
    return (rows == cols - 1); // For a system with equations equal to the number of variables  
}  

bool isIndeterminate(float matrix[MAX][MAX], int rows, int cols) {  
    // A system is compatible indeterminate if the rank of the matrix equals the rank of the system of equations minus 1, indicating there are free variables  
    return (rows < cols - 1); // Fewer equations than variables, indicating indeterminacy  
}