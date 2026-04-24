#ifndef SRC_HPP
#define SRC_HPP

#include <iostream>
using namespace std;

class Evil{
private:
    int st, ed, val;
    int *data;

public:
    Evil(): st(0), ed(0), val(0), data(nullptr) {
        data = new int[1];
        data[0] = 0;
    }
    Evil(int s, int e, int v): st(s), ed(e), val(v), data(nullptr) {
        int n = (ed - st + 1);
        if (n < 1) { n = 1; st = ed; }
        data = new int[n];
        for (int i = 0; i < n; ++i) data[i] = 0;
    }
    Evil(const Evil &other): st(other.st), ed(other.ed), val(other.val), data(nullptr) {
        int n = ed - st + 1;
        if (n < 1) n = 1;
        data = new int[n];
        for (int i = 0; i < n; ++i) data[i] = other.data[i];
    }

    int &operator[](int i) {
        if (i < st || i > ed) return data[0];
        return data[i - st];
    }

    Evil &operator=(const Evil &other) {
        if (this == &other) return *this;
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

    Evil &operator++() { ++val; return *this; }
    Evil operator++(int) { Evil tmp(*this); ++val; return tmp; }

    friend ostream &operator<<(ostream &os, const Evil &e) {
        os << e.val << " ";
        int n = e.ed - e.st + 1;
        if (n < 1) n = 1;
        for (int i = 0; i < n; ++i) os << e.data[i] << " ";
        os << '\n';
        return os;
    }

    ~Evil() { delete[] data; data = nullptr; }

    void Print(){
        cout << val << " ";
        for(int i = 0;i < ed-st+1;++i)
            cout << data[i] <<" ";
        cout << endl;
    }
};

#endif // SRC_HPP
