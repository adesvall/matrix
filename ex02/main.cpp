#include "../Matrix.hpp"
#include "../Vector.hpp"

int main()
{
    cout << lerp(0., 1., 0.) << endl;
    // 0.0
    cout << lerp(0., 1., 1.) << endl;
    // 1.0
    cout << lerp(0., 1., 0.5) << endl;
    // 0.5
    cout << lerp(21., 42., 0.3) << endl;
    // 27.3
    cout << lerp(Vector<float>({2., 1.}), Vector<float>({4., 2.}), 0.3) << endl;
    // [2.6]
    // [1.3]
    cout << lerp(Matrix<float>({{2., 1.}, {3., 4.}}), Matrix<float>({{20., 10.}, {30., 40.}}), 0.5) << endl;
    // [[11., 5.5]
    // [16.5, 22.]]
    return 0;
}
