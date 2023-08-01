#include "../Vector.hpp"
#include "../Matrix.hpp"

int main()
{
    Matrix<float> u({
        { 1., -1.},
        {-1., 1.},
    });
    cout << u.determinant() << endl;
    // 0.0

    u = Matrix<float>({
        {2., 0., 0.},
        {0., 2., 0.},
        {0., 0., 2.},
    });
    cout << u.determinant() << endl;
    // 8.0

    u = Matrix<float>({
        {8., 5., -2.},
        {4., 7., 20.},
        {7., 6., 1.},
    });
    cout << u.determinant() << endl;
    // -174.0

    u = Matrix<float>({
        { 8., 5., -2., 4.},
        { 4., 2.5, 20., 4.},
        { 8., 5., 1., 4.},
        {28., -4., 17., 1.},
    });
    cout << u.determinant() << endl;
    // 1032
}