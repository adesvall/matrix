#include "../Vector.hpp"
#include "../Matrix.hpp"

int main()
{
    Matrix<float> u({
        {1., 0., 0.},
        {0., 1., 0.},
        {0., 0., 1.},
    });
    cout << u.rank() << endl;
    // 3

    u = Matrix<float>({
        { 1., 2., 0., 0.},
        { 2., 4., 0., 0.},
        {-1., 2., 1., 1.},
    });
    cout << u.rank() << endl;
    // 2

    u = Matrix<float>({
        { 8., 5., -2.},
        { 4., 7., 20.},
        { 7., 6., 1.},
        {21., 18., 7.},
    });
    cout << u.rank() << endl;
    // 3
}