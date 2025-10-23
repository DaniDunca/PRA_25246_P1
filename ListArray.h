#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        T* arr;
	int max;
	int n;
	void resize(int newCapacity) {
		T* newData = new T[newCapacity];
		for(int i= 0; i< n; i++)
			newData[i] = data[i];
		delete data;
		data = newData
			capacity= newCapacity;
	}

    public:
    ListArray(int initCapacity = 10)
        : capacity(initCapacity), n(0) {
        data = new T[capacity];
    }

    ~ListArray() { delete[] data; }

    bool isEmpty() const override { return n == 0; }
    int size() const override { return n; }

    void insert(int index, const T& element) override {
        if (index < 0 || index > n) throw std::out_of_range("Índice inválido");
        if (n == capacity) resize(capacity * 2);
        for (int i = n; i > index; --i)
            data[i] = data[i - 1];
        data[index] = element;
        n++;
 }
	 void remove(int index) override {
        if (index < 0 || index >= n) throw std::out_of_range("Índice inválido");
        for (int i = index; i < n - 1; ++i)
            data[i] = data[i + 1];
        n--;
    }

    T& get(int index) override {
        if (index < 0 || index >= n) throw std::out_of_range("Índice inválido");
        return data[index];
    }

    void clear() override { n = 0; }
};

#endif
