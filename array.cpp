#include "array.h"
#include <iostream>

Array::Array(int initialSize, int step) {
    if (initialSize <= 0) {
        throw std::runtime_error("Оберіть розмір > 0");
    }
    if (step <= 0) {
        throw std::runtime_error("Оберіть крок >=1");
    }
    this->size = initialSize; this->step = step; this->arr = new int[initialSize]; this->currentIndex = 0;
}
Array::~Array() {
    delete[] this->arr;
}

void Array::showElements() {
    for (int i = 0; i < this->currentIndex; i++) {
        std::cout << this->arr[i] << " ";
    }
    std::cout << std::endl;
}

void Array::expandArray(int size) {
    if (size <= 0) {
        throw std::runtime_error("Оберіть розмір не менший 1");
    }
    int newSize = this->currentIndex + size;
    int* newArr = new int[newSize];
    for (int i = 0; i < this->currentIndex; i++) {
        newArr[i] = this->arr[i];
    }
    delete[] this->arr;
    this->arr = newArr; this->size = newSize;
}

int Array::getSize() {
    return this->size;
}

int Array::getElemSize() {
    return this->currentIndex;
}

void Array::setValue(int val) {
    if (this->currentIndex >= this->size) {
        this->expandArray(this->step);
    }
    this->arr[this->currentIndex] = val; this->currentIndex++;
}

void Array::setArray(int* pArr, int size) {
    for (int i = 0; i < size; i++) {
        this->setValue(pArr[i]);
    }
}