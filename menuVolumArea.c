//Alcantara Rosete Adiel Jesus
#include <stdio.h>
#include <math.h>	// Use la biblioteca math para las potencias, y para usar pi  
#define pf printf
#define sf scanf

// Inicialice las funciones

void perimetroPentagono();
void areaRombo();
void volumenEsfera();
void volumenCono();

// Aqui hice el menu que se solicita
int main() {
    int option;

    do {
        pf("\nMenu Aritmetico:\n");
        pf("1. Perimetro de un pentagono\n");
        pf("2. Area de un rombo\n");
        pf("3. Volumen de una esfera\n");
        pf("4. Volumen de un cono\n");
        pf("5. Salir\n");
        pf("Seleccione alguna de las opciones: ");
        sf("%d", &option);

        switch (option) {
            case 1:
                perimetroPentagono(); // Llamo a mi función que realiza 
                break;
            case 2:
                areaRombo();
                break;
            case 3:
                volumenEsfera();
                break;
            case 4:
                volumenCono();
                break;
            case 5:
                pf("Saliste del programa, Nos vemos.\n");
                break;
            default:
                pf("Opcion invalida. Por favor, selecciona una opcion valida.\n");
                break;
        }
    } while (option != 5);

    return 0;
}

// Aqui defini las funciones

void perimetroPentagono() {
    float l, perimetro;
    	pf("Ingresa el lado del pentagono: ");
    	sf("%f", &l);
    perimetro = 5 * l;
    pf("El perimetro del pentagono es: %.2f\n", perimetro);
}

void areaRombo() {
    float diagMayor, diagMenor, area;
    	pf("Ingresa la diagonal mayor del rombo: ");
    	sf("%f", &diagMayor);
    	pf("Ingresa la diagonal menor del rombo: ");
    	sf("%f", &diagMenor);
    area = (diagMayor * diagMenor) / 2;
    pf("El area del rombo es: %.2f\n", area);
}

void volumenEsfera() {
    float r, volum;
    	pf("Ingresa el radio de la esfera: ");
    	sf("%f", &r);
    volum = (4.0 / 3.0) * M_PI * pow(r, 3);	// pow eleva al cuadrado el radio y pi ya esta definido como M_PI
    pf("El volumen de la esfera es: %.2f\n", volum);
}

void volumenCono() {
    float r, h, volum;
    	pf("Ingresa el radio del cono: ");
    	sf("%f", &r);
    	pf("Ingrese la altura del cono: ");
    	sf("%f", &h);
    volum = (1.0 / 3.0) * M_PI * pow(r, 2) * h;
    pf("El volumen del cono es: %.2f\n", volum);
}


