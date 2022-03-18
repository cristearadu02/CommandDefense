#pragma once

class Sort
{
    int* v;
    int count;
    
public:
    Sort(int countt, int minn, int maxx); // random - done 
    Sort(int count, ...); // variadic - done 
    Sort(char* c); // din sir de caractere - done
    Sort(int* x, int count); // din vector - done
    Sort(); //lista de initializare - somehow done
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);

};