#include "../Vector.hpp"
#include "../Matrix.hpp"

int main()
{
    Matrix<float> u({
        {1., 2.},
        {3., 4.},
        {5., 6.},
        {7., 8.},
    });
    cout << u.transpose() << endl;

    u = Matrix<float>({
        {-2., 3., 4.},
        {2., -5., 0.},
        {-2., 0., 4.},
        {4., 3., 7.},
        {-2., 3., 4.},
    });
    cout << u.transpose() << endl;

    u = Matrix<float>({
        {-2., -8., 4.},
        {0., 6., 4.},
    });
    cout << u.transpose() << endl;
}