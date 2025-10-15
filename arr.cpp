#include "arr.h"
#include <iostream>
using namespace std;

//инициализация массива
void initArray(MyArr &arr) {
    arr.data = nullptr;
    arr.size = 0;
    arr.capacity = 0;
}

//освобождение памяти
void freeArr(MyArr &arr) {
    delete[] arr.data;
    arr.data = nullptr;
    arr.size = 0;
    arr.capacity = 0;
}

//проверка и расширение памяти при необходимости
static void ensureCapacity(MyArr &arr, int newSize) {
    if (newSize <= arr.capacity) return;

    int newCapacity = arr.capacity == 0 ? 1 : arr.capacity;
    while (newCapacity < newSize)
        newCapacity *= 2;

    string* newData = new string[newCapacity];
    for (int i = 0; i < arr.size; ++i)
        newData[i] = arr.data[i];

    delete[] arr.data;
    arr.data = newData;
    arr.capacity = newCapacity;
}

// добавление в конец
void addEnd(MyArr &arr, const string& val) {
    ensureCapacity(arr, arr.size + 1);
    arr.data[arr.size++] = val;
}

// добавление по индексу (только в существующую ячейку)
void addAt(MyArr &arr, int idx, const string& val) {
    // теперь вставлять можно только в существующий диапазон [0, size-1]
    if (idx < 0 || idx >= arr.size) {
        cout << "Ошибка: нельзя добавить по индексу " << idx
             << " — допустимо от 0 до " << (arr.size - 1) << endl;
        return;
    }

    ensureCapacity(arr, arr.size + 1);

    //сдвигаем элементы вправо, начиная с конца
    for (int i = arr.size; i > idx; --i)
        arr.data[i] = arr.data[i - 1];

    arr.data[idx] = val;
    arr.size++;
}

//удаление по индексу
void delAt(MyArr &arr, int idx) {
    if (idx < 0 || idx >= arr.size) {
        cout << "Неверный индекс" << endl;
        return;
    }

    for (int i = idx; i < arr.size - 1; ++i)
        arr.data[i] = arr.data[i + 1];

    arr.size--;

    //уменьшаем capacity, если слишком много пустого места
    if (arr.size * 4 <= arr.capacity && arr.capacity > 1) {
        int newCapacity = arr.capacity / 2;
        string* newData = new string[newCapacity];
        for (int i = 0; i < arr.size; ++i)
            newData[i] = arr.data[i];
        delete[] arr.data;
        arr.data = newData;
        arr.capacity = newCapacity;
    }
}

//замена элемента
void repArr(MyArr &arr, int idx, const string& val) {
    if (idx < 0 || idx >= arr.size) {
        cout << "Неверный индекс" << endl;
        return;
    }
    arr.data[idx] = val;
}

//чтение всех элементов
void readArray(const MyArr &arr) {
    if (arr.size == 0) {
        cout << "Массив пуст." << endl;
        return;
    }
    cout << "Содержимое массива (" << arr.size << "/" << arr.capacity << "): ";
    for (int i = 0; i < arr.size; ++i)
        cout << arr.data[i] << " ";
    cout << endl;
}

//получение элемента по индексу
void getAt(const MyArr &arr, int idx) {
    if (idx >= 0 && idx < arr.size)
        cout << arr.data[idx] << endl;
    else
        cout << "Неверный индекс" << endl;
}

//логическая длина массива
int lenArr(const MyArr &arr) {
    return arr.size;
}

//реальный размер (ёмкость)
int realSize(const MyArr &arr) {
    return arr.capacity;
}

