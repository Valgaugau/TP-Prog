#include <QApplication>
#include <time.h>

#include "tp2.h"


MainWindow* w=nullptr;

void recursivQuickSort(Array& toSort, int size)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
    if(size <= 1){
            return;
        }

	Array& lowerArray = w->newArray(size);
	Array& greaterArray= w->newArray(size);
	int lowerSize = 0, greaterSize = 0; // effectives sizes
    const int pivotIndex = size / 2;
    const int pivotValue = toSort[pivotIndex];

	// split

    for(int i = 0; i < size; i++){
            const int current = toSort[i];
            if(i == pivotIndex){
                continue;
            }
            Array& currentArray = current < pivotValue ? lowerArray : greaterArray;
            int& currentSize = current < pivotValue ? lowerSize : greaterSize;
            currentArray[currentSize++] = current;
        }
	
	// recursiv sort of lowerArray and greaterArray

    recursivQuickSort(lowerArray, lowerSize);
    recursivQuickSort(greaterArray, greaterSize);

	// merge
    int index = 0;
    for(int i = 0; i < lowerSize; i++){
        toSort[index++] = lowerArray[i];
    }
    toSort[index++] = pivotValue;
    for(int i = 0; i < greaterSize; i++){
        toSort[index++] = greaterArray[i];
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
