#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;


void bubbleSort(Array& toSort){
	// bubbleSort
    int n = toSort.size();
       // boucle pour trier les éléments de toSort
       for (int i = 0; i < n - 1; i++) {
           // boucle pour remonter la valeur la plus haute
           for (int j = 0; j < n - i - 1; j++) {
               if (toSort[j] > toSort[j+1]) {
                   // échange des valeurs
                   int temp = toSort[j];
                   toSort[j] = toSort[j+1];
                   toSort[j+1] = temp;
               }
           }
       }
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 100;
	w = new TestMainWindow(bubbleSort);
	w->show();

	return a.exec();
}
