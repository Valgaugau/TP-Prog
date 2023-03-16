#include "tp1.h"
#include <QApplication>
#include <time.h>

int isMandelbrot(Point z, int n, Point point){
    // recursiv Mandelbrot

    // check n

       double module_z = std::sqrt(z.x * z.x + z.y * z.y);

       if (module_z > 2.0)
       {
           return 0;
       }

       if (n == 0)
       {
           return 1;
       }

       double temp = z.x * z.x - z.y * z.y + point.x;
       z.y = 2.0 * z.x * z.y + point.y;
       z.x = temp;

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



