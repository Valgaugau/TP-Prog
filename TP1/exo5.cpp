#include "tp1.h"
#include <QApplication>
#include <time.h>

int isMandelbrot(Point z, int n, Point point){
    // recursiv Mandelbrot

    // check n

    // Calcul de la distance de z à l'origine
       double module_z = std::sqrt(z.x * z.x + z.y * z.y);

       // Si la distance est supérieure à 2, on sait que la suite diverge
       if (module_z > 2.0)
       {
           return 0;
       }

       // Si on a atteint la profondeur maximale de récursion, on considère que la suite converge
       if (n == 0)
       {
           return 1;
       }

       // Calcul de z^2 + c
       double temp = z.x * z.x - z.y * z.y + point.x;
       z.y = 2.0 * z.x * z.y + point.y;
       z.x = temp;

       // Appel récursif pour le prochain terme de la suite
       return isMandelbrot(z, n - 1, point);

    return 0;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MandelbrotWindow(isMandelbrot);
    w->show();

    a.exec();
}



