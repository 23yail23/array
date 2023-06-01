#pragma once

class Array {
    
private:

    int size;
    int step;
    int* arr;
    int currentIndex;
    
public:

    Array(int initialSize = 10, int step = 10);
    ~Array();
    void showElements();
    void expandArray(int size);
    int getSize();
    int getElemSize();
    void setValue(int val);
    void setArray(int* pArr, int size);
    
};