#include "../Vector.hpp"
#include "../Matrix.hpp"

int main()
{
    Vector<float> u = Vector<float>({0., 0., 0.});
    cout << u.norm_1() << ",  " << u.norm() << ",  " << u.norm_inf() << endl;
    // 0.0, 0.0, 0.0

    u = Vector<float>({1., 2., 3.});
    cout << u.norm_1() << ",  " << u.norm() << ",  " << u.norm_inf() << endl;
    // 6.0, 3.74165738, 3.0

    u = Vector<float>({1., 2.});
    cout << u.norm_1() << ",  " << u.norm() << ",  " << u.norm_inf() << endl;
    // 3.0, 2.236067977, 2.0
}