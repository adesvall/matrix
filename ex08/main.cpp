#include "../Vector.hpp"
#include "../Matrix.hpp"

int main()
{
    Matrix<float> u({
        {1., 0.},
        {0., 1.},
    });
    cout << u.trace() << endl;
    // 2.0
    u = Matrix<float>({
        {2., -5., 0.},
        {4., 3., 7.},
        {-2., 3., 4.},
    });
    cout << u.trace() << endl;
    // 9.0
    u = Matrix<float>({
        {-2., -8., 4.},
        {1., -23., 4.},
        {0., 6., 4.},
    });
    cout << u.trace() << endl;
    // -21.0
}