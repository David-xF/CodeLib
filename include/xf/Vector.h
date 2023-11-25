#pragma once

#include <inttypes.h>
#include <initializer_list>

#include <minecraft/util/MallocOperator.h>

namespace xf {
    template<typename T>
    class Vector {
    public:
        Vector() {
            data = nullptr;
            length = 0;
        }

        Vector(std::initializer_list<T> list) {
            data = _new<T>(list.size());
            length = list.size();
            
            int index = 0;
            for (T t : list) {
                data[index++] = t;
            }
        }

        Vector(T t) {
            data = _new<T>(1);
            length = 1;

            data[0] = t;
        }

        Vector(Vector<T>& t) {
            data = _new<T>(t.getSize());
            length = t.getSize();
            
            int n = 0;
            for (T _t : t) {
                data[n++] = _t;
            }
        }

        ~Vector() {
            // _delete(data);
        }

        void push_back(T t) {
            if (!data || length == 0) {
                data = _new<T>(1);
                length = 1;

                data[0] = t;
            } else {
                length++;
                T* n_data = _new<T>(length);
                for (int i = 0; i < length - 1; i++) n_data[i] = data[i];
                n_data[length - 1] = t;
                _delete(data);
                data = n_data;
            }
        }   

        void push_front(T t) {
            if (!data || length == 0) {
                data = _new<T>(1);
                length = 1;

                data[0] = t;
            } else {
                length++;
                T* n_data = _new<T>(length);
                for (int i = 0; i < length - 1; i++) n_data[i + 1] = data[i];
                n_data[0] = t;
                _delete(data);
                data = n_data;
            }
        }

        void pop_front() {
            for (int i = 1; i < length; i++) {
                data[i - 1] = data[i];
            }

            length == 0 ? length = 0 : length -= 1;
        }

        void clear() {
            length = 0;
            if (data) _delete(data);
            data = nullptr;
        }
        
        void pop_back() {
            length -= 1;
        }

        bool isEmpty() {
            return length == 0;
        }

        T& random() {
            return data[code::Random::next(0, length - 1)];
        }

        T& front() { return data[0]; }
        T& back()  { return data[length - 1]; }

        T& operator[](int index) { 
            if (0 > index) return data[length + index];
            return data[index]; 
        }

        T operator[](int index) const { 
            if (0 > index) return data[length + index];
            return data[index]; 
        }

        xf::Vector<T>& operator=(xf::Vector<T> other) {
            clear();
            for (T t : other) {
                push_back(t);
            }

            return *this;
        }

        T* getData() const { return data;   }
        const int getSize() { return length; }
        int getSize() const { return length; }
        
        void setData(T* newData, int newLength) { 
            data = newData;
            length = newLength;
        }

        // Used for 
        // for (T t : this) {}
        typedef       T*  iter;
        typedef const T* citer;

        iter  begin()       { return &data[0]; }
        citer begin() const { return &data[0]; }
        iter  end()       { return &data[length]; }
        citer end() const { return &data[length]; }

    private:
        T* data;
        int length;
    };
}