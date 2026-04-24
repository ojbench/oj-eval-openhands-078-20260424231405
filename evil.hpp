#ifndef EVIL_HPP
#define EVIL_HPP

#include <iostream>
#include <cstring>
using namespace std;

class Evil{
private:
    int st, ed, val;
    int *data;

public:
    // Constructors
    Evil(): st(0), ed(0), val(0), data(nullptr) {
        data = new int[1];
        data[0] = 0;
    }
    Evil(int s, int e, int v): st(s), ed(e), val(v), data(nullptr) {
        int n = (ed - st + 1);
        if (n < 1) { // guard against invalid range; create at least one slot
            n = 1;
            st = ed; // keep size consistent
        }
        data = new int[n];
        for (int i = 0; i < n; ++i) data[i] = 0;
    }

    // Copy constructor
    Evil(const Evil &other): st(other.st), ed(other.ed), val(other.val), data(nullptr) {
        int n = ed - st + 1;
        if (n < 1) n = 1;
        data = new int[n];
        for (int i = 0; i < n; ++i) data[i] = other.data[i];
    }

    // Subscript operator
    int &operator[](int i) {
        if (i < st || i > ed) return data[0];
        return data[i - st];
    }

    // Assignment operator
    Evil &operator=(const Evil &other) {
        if (this == &other) return *this;
        // allocate new array before deleting old in case of exceptions
        int n = other.ed - other.st + 1;
        if (n < 1) n = 1;
        int *new_data = new int[n];
        for (int i = 0; i < n; ++i) new_data[i] = other.data[i];
        delete[] data;
        st = other.st;
        ed = other.ed;
        val = other.val;
        data = new_data;
        return *this;
    }

    // Prefix ++
    Evil &operator++() {
        ++val;
        return *this;
    }

    // Postfix ++
    Evil operator++(int) {
        Evil tmp(*this);
        ++val;
        return tmp;
    }

    // Output operator
    friend ostream &operator<<(ostream &os, const Evil &e) {
        os << e.val << " ";
        int n = e.ed - e.st + 1;
        if (n < 1) n = 1;
        for (int i = 0; i < n; ++i) os << e.data[i] << " ";
        os << '\n';
        return os;
    }

    // Destructor
    ~Evil() {
        delete[] data;
        data = nullptr;
    }

    void Print(){
        cout << val << " ";
        for(int i = 0;i < ed-st+1;++i)
            cout << data[i] <<" ";
        cout << endl;
    }
};

#endif // EVIL_HPP
