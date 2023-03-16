#include <QApplication>
#include <time.h>

#include "tp2.h"


MainWindow* w=nullptr;

void recursivQuickSort(Array& toSort, int size)
{
    // stop statement = condition + return (return stop the function even if it does not return anything)
    Array& lowerArray = w->newArray(size);
    Array& greaterArray= w->newArray(size);
    int lowerSize = 0, greaterSize = 0;

    // Check if the array has only one element, in which case it is already sorted
    if (size <= 1) {
        return;
    }


    int pivotIndex = rand() % size;
    int pivot = toSort[pivotIndex];

    // split
    for (int i = 0; i < size; i++) {
        if (i == pivotIndex) {
            continue;
        }
        int current = toSort[i];
        if (current < pivot) {
            lowerArray[lowerSize++] = current;
        } else {
            greaterArray[greaterSize++] = current;
        }
    }

    // recursiv sort of lowerArray and greaterArray
    recursivQuickSort(lowerArray, lowerSize);
    recursivQuickSort(greaterArray, greaterSize);

    // merge
    int i = 0;
    for (int j = 0; j < lowerSize; j++) {
        toSort[i++] = lowerArray[j];
    }
    toSort[i++] = pivot;
    for (int j = 0; j < greaterSize; j++) {
        toSort[i++] = greaterArray[j];
    }
}

void quickSort(Array& toSort){
    recursivQuickSort(toSort, toSort.size());
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    uint elementCount=20;
    MainWindow::instruction_duration = 50;
    w = new TestMainWindow(quickSort);
    w->show();

    return a.exec();
}
