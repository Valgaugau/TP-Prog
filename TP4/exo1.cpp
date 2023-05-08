#include "tp4.h"
#include "mainwindow.h"

#include <QApplication>
#include <time.h>
#include <stdio.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;

int Heap::leftChild(int nodeIndex)
{
    return 2 * nodeIndex + 1;
}

int Heap::rightChild(int nodeIndex)
{
    return 2 * nodeIndex + 2;
}

void Heap::insertHeapNode(int heapSize, int value)
{
    int i = heapSize;
    (*this)[i] = value;
    int parent = (i - 1) / 2;
    while (i > 0 && (*this)[i] > (*this)[parent]) {
        std::swap((*this)[i], (*this)[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }
}

void Heap::heapify(int heapSize, int nodeIndex)
{
    int i_max = nodeIndex;
    int left = leftChild(nodeIndex);
    int right = rightChild(nodeIndex);
    if (left < heapSize && (*this)[left] > (*this)[i_max]) {
        i_max = left;
    }
    if (right < heapSize && (*this)[right] > (*this)[i_max]) {
        i_max = right;
    }
    if (i_max != nodeIndex) {
        std::swap((*this)[nodeIndex], (*this)[i_max]);
        heapify(heapSize, i_max);
    }
}

void Heap::buildHeap(Array& numbers)
{
    for (int i = 0; i < numbers.size(); i++) {
        insertHeapNode(i, numbers[i]);
    }
}

void Heap::heapSort()
{
    int heapSize = size();
    for (int i = heapSize - 1; i > 0; i--) {
        std::swap((*this)[0], (*this)[i]);
        heapSize--;
        heapify(heapSize, 0);
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow::instruction_duration = 50;
    w = new HeapWindow();
    w->show();

    return a.exec();
}
