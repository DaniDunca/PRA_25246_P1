#ifndef LISTLINKED_H
#define LISTLINKED_H

#include "List.h"
#include "Node.h"
#include <ostream>
#include <stdexcept>

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    
    ListLinked() : first(nullptr), n(0) {}

    
    ~ListLinked() {
        while (first != nullptr) {
            Node<T>* aux = first->next;
            delete first;
            first = aux;
        }
    }

   
    bool isEmpty() const override {
        return n == 0;
    }

   
    int size() const override {
        return n;
    }

   
    void insert(int index, const T& element) override {
        if (index < 0 || index > n) throw std::out_of_range("Índice fuera de rango");

        if (index == 0) {
            first = new Node<T>(element, first);
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < index - 1; ++i) {
                prev = prev->next;
            }
            prev->next = new Node<T>(element, prev->next);
        }
        ++n;
    }

    
    void remove(int index) override {
        if (index < 0 || index >= n) throw std::out_of_range("Índice fuera de rango");

        Node<T>* toDelete;
        if (index == 0) {
            toDelete = first;
            first = first->next;
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < index - 1; ++i) {
                prev = prev->next;
            }
            toDelete = prev->next;
            prev->next = toDelete->next;
        }
        delete toDelete;
        --n;
    }

   
    T& get(int index) override {
        if (index < 0 || index >= n) throw std::out_of_range("Índice fuera de rango");

        Node<T>* current = first;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

   
    void clear() override {
        while (first != nullptr) {
            Node<T>* aux = first->next;
            delete first;
            first = aux;
        }
        n = 0;
    }

   
    T operator[](int pos) {
    return get(pos); 
    }

    
    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        Node<T>* current = list.first;
        while (current != nullptr) {
            out << current->data << " ";
            current = current->next;
        }
        return out;
    }
};

#endif
