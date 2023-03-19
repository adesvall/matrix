#include "../Matrix.hpp"
#include "../Vector.hpp"

int main()
{
    Vector<float> u = Vector<float>({0., 0.});
    Vector<float> v = Vector<float>({1., 1.});
    cout << u.dot(v) << endl;
    // 0.0
    
    u = Vector<float>({1., 1.});
    v = Vector<float>({1., 1.});
    cout << u.dot(v) << endl;
    // 2.0

    u = Vector<float>({-1., 6.});
    v = Vector<float>({3., 2.});
    cout << u.dot(v) << endl;
    // 9.0
}
