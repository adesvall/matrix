#include "../Vector.hpp"
#include "../Matrix.hpp"

int main()
{
    Vector<float> u({0., 0., 1.});
    Vector<float> v({1., 0., 0.});
    cout << cross_product(u, v) << endl;
    // [0.]
    // [1.]
    // [0.]
    u = Vector<float>({1., 2., 3.});
    v = Vector<float>({4., 5., 6.});
    cout << cross_product(u, v) << endl;
    // [-3.]
    // [6.]
    // [-3.]
    u = Vector<float>({4., 2., -3.});
    v = Vector<float>({-2., -5., 16.});
    cout << cross_product(u, v) << endl;
    // [17.]
    // [-58.]
    // [-16.]
}