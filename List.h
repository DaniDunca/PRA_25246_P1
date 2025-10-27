#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
public:
    virtual ~List() {}

    virtual bool isEmpty() const = 0;
    virtual int size() const = 0;
    virtual void insert(int index, const T& element) = 0;
    virtual T&  remove(int index) = 0;
    virtual T& get(int index) = 0;
    virtual void clear() = 0;
};
#endif
