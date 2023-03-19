#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
#include <iostream>

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

    Vector<K> result = Vector<K>(vecs[0]);
    result *= coefs[0];

    for (size_t i = 1; i < vecs.size(); i++)    {
        if (vecs[i].size() != result.size())
            throw exception();
        Vector<K> tmp = vecs[i];
        tmp *= coefs[i];
        result += tmp;
    }

    return result;
}

template <typename V>
V lerp(V u, V v, float t)
{
    V result = u;
    result *= 1 - t;
    v *= t;
    result += v;
    return result;
}


#endif