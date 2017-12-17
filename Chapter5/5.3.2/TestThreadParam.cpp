#include <thread>
#include <iostream>
#include <vector>

using namespace std;

void f(vector<double>* v) {
    if (NULL != v) {
        for (auto p = v->begin(); p != v->end(); ++p) {
            cout << *p << endl;
        }
    }
}

struct F{
    vector<double>& v;
    F(vector<double>& vv):v(vv){}
    void operator()(){
        for (vector<double>::iterator p = v.begin(); p != v.end(); ++p) {
            cout << *p << endl;
        }
    }
};

void user() {
    vector<double> some_vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<double> vec2 {10, 11, 12, 13, 14};

    thread t1 {f, &some_vec};
    thread t2 {F(vec2)};

    t1.join();	// wait t1 process
    t2.join();  // wait t2 process
}

int main(int argc, char** argv) {
    user();
    return 0;
}
