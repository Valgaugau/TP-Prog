#include "tp1.h"
#include <QApplication>
#include <time.h>

#define return_and_display(result) return _.store(result);

int fibonacci(int value)
{
    Context _("fibonacci", value); // do not care about this, it allow the display of call stack

    // your code

        if(value <= 1){
            return_and_display(value);
        }

        int a = 0;
        int b = 1;
        int c;

        for(int i = 2; i <= value; i++){
            c = a + b;
            a = b;
            b = c;
        }

        return_and_display(b);

    return_and_display(value);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // create a window manager
    MainWindow::instruction_duration = 400;  // make a pause between instruction display
    MainWindow* w = new FibonacciWindow(fibonacci); // create a window for this exercice
    w->show(); // show exercice

    return a.exec(); // main loop while window is opened
}
