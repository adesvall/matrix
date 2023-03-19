#include "../Vector.hpp"
#include "../Matrix.hpp"

int main()
{
    Vector<float> u = Vector<float>({1., 0.});
    Vector<float> v = Vector<float>({1., 0.});
    cout << angle_cos(u, v) << endl;
    // 1.0

    u = Vector<float>({1., 0.});
    v = Vector<float>({0., 1.});
    cout << angle_cos(u, v) << endl;
    // 0.0
    
    u = Vector<float>({-1., 1.});
    v = Vector<float>({1., -1.});
    cout << angle_cos(u, v) << endl;
    // -1.0

    u = Vector<float>({2., 1.});
    v = Vector<float>({4., 2.});
    cout << angle_cos(u, v) << endl;
    // 1.0

    u = Vector<float>({1., 2., 3.});
    v = Vector<float>({4., 5., 6.});
    cout << angle_cos(u, v) << endl;
    // 0.974631846
}