/*ALCANTARA ROSETE ADIEL JESUS*/
//Programa que calcula la regresion lineal de 10 datos en X y Y y muestra el R2
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void calcularRegresionLineal(const vector<double>& x, const vector<double>& y) {
    int n = x.size();
    
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0, sumY2 = 0;

    for (int i = 0; i < n; ++i) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
        sumY2 += y[i] * y[i];
    }

    double b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double a = (sumY - b * sumX) / n;

    double rNumerator = (n * sumXY - sumX * sumY);
    double rDenominator = sqrt((n * sumX2 - sumX * sumX) * (n * sumY2 - sumY * sumY));
    double r2 = (rNumerator / rDenominator) * (rNumerator / rDenominator);

    cout << "Ecuacion de la recta: y = " << a << " + " << b << "x" << endl;
    cout << "Coeficiente de determinacion (R^2): " << r2 << endl;
}

int main() {
    vector<double> x(10);
    vector<double> y(10);

    x = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    y = {0.15, 0.25, 0.35, 0.45, 0.55, 0.65, 0.75, 0.85, 0.95, 1.05};

    calcularRegresionLineal(x, y);

    return 0;
}
