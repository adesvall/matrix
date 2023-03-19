#include "../Vector.hpp"

int main()
{
    Vector<float> e1 = Vector<float>({1., 0., 0.});
    Vector<float> e2 = Vector<float>({0., 1., 0.});
    Vector<float> e3 = Vector<float>({0., 0., 1.});
    Vector<float> v1 = Vector<float>({1., 2., 3.});
    Vector<float> v2 = Vector<float>({0., 10., -100.});

    cout << linear_combination<float>({e1, e2, e3}, {10., -2., 0.5}) << endl;
    // [10.]
    // [-2.]
    // [0.5]
    cout << linear_combination<float>({v1, v2}, {10., -2.}) << endl;
    // [10.]
    // [0.]
    // [230.]
}
