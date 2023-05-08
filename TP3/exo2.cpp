#include "tp3.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;
using std::size_t;

void binarySearchAll(Array& array, int toSearch, int& indexMin, int& indexMax) {
    int start = 0;
    int end = array.size() - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (array[mid] == toSearch) {
            indexMin = mid;
            end = mid - 1;
        }
        else if (array[mid] < toSearch) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    start = 0;
    end = array.size() - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (array[mid] == toSearch) {
            indexMax = mid;
            start = mid + 1;
        }
        else if (array[mid] < toSearch) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    if (indexMin == -1 && indexMax == -1) {
        indexMin = indexMax = -1;
    }
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow::instruction_duration = 500;
    w = new BinarySearchAllWindow(binarySearchAll);
    w->show();
    return a.exec();
}
