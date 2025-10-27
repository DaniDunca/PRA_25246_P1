#ifndef LISTARRAY_H
#define LISTARRAY_H
#include <stdexcept>
#include <iostream>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;
    int max;
    int n;
    static const int MINSIZE = 2;

    void resize(int newCapacity) {
        T* newData = new T[newCapacity];
        for (int i = 0; i < n; ++i)
            newData[i] = arr[i];
        delete[] arr;
        arr = newData;
        max = newCapacity;
    }

public:
    ListArray() : arr(new T[MINSIZE]), max(MINSIZE), n(0) {}

    ~ListArray() {
        delete[] arr;
    }

    bool isEmpty() const override {
        return n == 0;
    }

    int size() const override {
        return n;
    }

    void insert(int index, const T& element) override {
        if (index < 0 || index > n) throw std::out_of_range("Índice inválido");
        if (n == max) resize(max * 2);
        for (int i = n; i > index; --i)
            arr[i] = arr[i - 1];
        arr[index] = element;
        ++n;
    }

    T remove(int index) override {
        if (index < 0 || index >= n) throw std::out_of_range("Índice inválido");
        T removed = arr[index];
        for (int i = index; i < n - 1; ++i)
            arr[i] = arr[i + 1];
        --n;
        if (n < max / 4 && max / 2 >= MINSIZE) resize(max / 2);
        return removed;
    }

    T& get(int index) override {
        if (index < 0 || index >= n) throw std::out_of_range("Índice inválido");
        return arr[index];
    }

    void clear() override {
        n = 0;
    }

    T& operator[](int index) {
        if (index < 0 || index >= n) throw std::out_of_range("Índice inválido");
        return arr[index];
    }

    void append(const T& item) {
        insert(n, item);
    }

    void prepend(const T& item) {
        insert(0, item);
    }

    int search(const T& item)  {
        for (int i = 0; i < n; ++i)
            if (arr[i] == item) return i;
        return -1;
    }

    friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
        out << "[";
        for (int i = 0; i < list.n; ++i) {
            out << list.arr[i];
            if (i < list.n - 1) out << ", ";
        }
        out << "]";
        return out;
    }
};

#endif // LISTARRAY_H

