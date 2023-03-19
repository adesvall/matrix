#include "../Vector.hpp"
#include "../Matrix.hpp"

int main()
{
    Matrix<float> u({
        {1., 0.},
        {0., 1.}
    });
    Vector v({4., 2.});
    cout << u.mul_vec(v);
    // {4.}
    // {2.}

    u = Matrix<float>({
    {2., 0.},
    {0., 2.},
    });
    v = Vector({4., 2.});
    cout << u.mul_vec(v);
    // {8.}
    // {4.}

    u = Matrix<float>({
    {2., -2.},
    {-2., 2.},
    });
    v = Vector({4., 2.});
    cout << u.mul_vec(v);
    // {4.}
    // {-4.}

    u = Matrix<float>({
    {1., 0.},
    {0., 1.},
    });
    v = Matrix<float>({
    {1., 0.},
    {0., 1.},
    });
    cout << u.mul_mat(v);
    // {1., 0.}
    // {0., 1.}

    u = Matrix<float>({
    {1., 0.},
    {0., 1.},
    });
    v = Matrix<float>({
    {2., 1.},
    {4., 2.},
    });
    cout << u.mul_mat(&v);
    // {2., 1.}
    // {4., 2.}

    u = Matrix<float>({
    {3., -5.},
    {6., 8.},
    });
    v = Matrix<float>({
    {2., 1.},
    {4., 2.},
    });
    cout << u.mul_mat(v);
    // [-14., -7.}
    // [44., 22.}
}