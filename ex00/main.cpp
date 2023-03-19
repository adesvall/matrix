#include "../Vector.hpp"
#include "../Matrix.hpp"

int main()
{
    Vector<float> u = Vector<float>({2., 3.});
    Vector<float> v = Vector<float>({5., 7.});
    u += v;
    cout << u << endl;
    // [7.0]
    // [10.0]

    u = Vector<float>({2., 3.});
    v = Vector<float>({5., 7.});
    u -= v;
    cout << u << endl;
    // [-3.0]
    // [-4.0]

    u = Vector<float>({2., 3.});
    u *= 2.;
    cout << u << endl;
    // [4.0]
    // [6.0]

    Matrix<float> A = Matrix<float>({{1., 2.}, {3., 4.}});
    Matrix<float> B = Matrix<float>({{7., 4.}, {-2., 2.}});
    A += B;
    cout << A << endl;
    // [8.0, 6.0]
    // [1.0, 6.0]

    A = Matrix<float>({{1., 2.}, {3., 4.}});
    B = Matrix<float>({{7., 4.}, {-2., 2.}});
    A -= B;
    cout << A << endl;
    // [-6.0, -2.0]
    // [5.0, 2.0]

    A = Matrix<float>({{1., 2.}, {3., 4.}});
    A*= 2.;
    cout << A << endl;
    // [2.0, 4.0]
    // [6.0, 8.0]
}