#include <thread>
#include <iostream>
#include <vector>

using namespace std;

void f(const vector<double>* v, double* res) {
    if (NULL != v) {
        for (auto p = v->begin(); p != v->end(); ++p) {
            cout << *p << endl;
        }
    }
    *res = 1.1;
}

class F {
public:
    F(const vector<double>& vv, double* p)
    :v(vv),
    res(p)
    {

    }

    void operator()() {
        for (auto p = v.begin(); p != v.end(); ++p) {
            cout << *p << endl;
        } 
        *res = 2.1;
    }
private:
    const vector<double>& v;
    double* res;
};

void user() {
    vector<double> some_vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<double> vec2 {10, 11, 12, 13, 14};
    double res1 = 0.0;
    double res2 = 0.0;

    thread t1 {f, &some_vec, &res1};
    thread t2 {F(vec2, &res2)};

    t1.join();	// wait t1 process
    t2.join();  // wait t2 process

    cout << res1 << " " << res2 << endl;
}

int main(int argc, char** argv) {
    user();
    return 0;
}
