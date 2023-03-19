#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

template <typename K>
class Vector
{
public:
    vector<K> _vector;

    Vector() {}
    Vector(vector<K> const &vector) : _vector(vector) {}
    Vector(Vector const &rhs) : _vector(rhs._vector) {}
    Vector &operator=(Vector const &rhs)
    {
        _vector = rhs._vector;
        return *this;
    }

    size_t  size() const { return _vector.size(); }

    void    operator+=(Vector const &rhs)
    {
        if (_vector.size() != rhs._vector.size())
            throw exception();

        for (size_t i = 0; i < rhs._vector.size(); i++)
            _vector[i] += rhs._vector[i];
    }

    void    operator-=(Vector const &rhs)
    {
        if (_vector.size() != rhs._vector.size())
            throw exception();

        for (size_t i = 0; i < rhs._vector.size(); i++)
            _vector[i] -= rhs._vector[i];
    }

    void    operator*=(K a)
    {
        for (size_t i = 0; i < _vector.size(); i++)
            _vector[i] *= a;
    }

    K& operator[](size_t i) { return _vector[i]; }
    K operator[](size_t i) const { return _vector[i]; }

    K   dot(Vector const &rhs) const
    {
        if (_vector.size() != rhs._vector.size())
            throw exception();

        K result = 0;
        for (size_t i = 0; i < _vector.size(); i++)
            result += _vector[i] * rhs._vector[i];
        return result;
    }

    K   norm_1() const
    {
        K result = 0;
        for (size_t i = 0; i < _vector.size(); i++)
            result += abs(_vector[i]);
        return result;
    }
    K   norm() const
    {
        return sqrt(this->dot(*this));
    }
    K   norm_inf() const
    {
        K result = 0;
        for (size_t i = 0; i < _vector.size(); i++)
            result = max(abs(_vector[i]), result);
        return result;
    }

};

template <typename K>
ostream& operator<<(ostream& os, const Vector<K>& v)
{
    os << "Vector:" << endl;
    for (size_t i = 0; i < v.size(); i++)
        os << v[i] << endl;
    return os;
}

template <typename K>
Vector<K> linear_combination(vector<Vector<K>> const &vecs, vector<K> const &coefs)
{
    if (vecs.size() != coefs.size())
        throw exception();

    Vector<K> result(vector<K>(vecs[0].size()));
    result *= coefs[0];

    for (size_t i = 1; i < vecs.size(); i++)   {
        if (vecs[i].size() != result.size())
            throw exception();

        for (size_t j = 0; j < result.size(); j++)
            result[j] = fma(coefs[i], vecs[i][j], result[j]);
    }

    return result;
}

template <typename V>
V lerp(V u, V v, float t)
{
    if (u.size() != u.size())
        throw exception();

    V result = u;
    result *= 1 - t;
    v *= t;
    result += v;
    return result;
}

template <typename K>
K angle_cos(Vector<K> const &u, Vector<K> const &v)
{
    if (u.size() != u.size())
        throw exception();

    return u.dot(v) / (u.norm() * v.norm());
}

template <typename K>
Vector<K> cross_product(Vector<K> const &u, Vector<K> const &v)
{
    if (u.size() != u.size())
        throw exception();

    return Vector<K>({u[1] * v[2] - u[2] * v[1],
                      u[2] * v[0] - u[0] * v[2],
                      u[0] * v[1] - u[1] * v[0]});
}

#endif