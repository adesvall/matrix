#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>

using namespace std;

template <typename K>
class Vector
{
    vector<K> _vector;

public:
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

        for (int i = 0; i < rhs._vector.size(); i++)
            _vector[i] += rhs._vector[i];
    }

    void    operator-=(Vector const &rhs)
    {
        if (_vector.size() != rhs._vector.size())
            throw exception();

        for (int i = 0; i < rhs._vector.size(); i++)
            _vector[i] -= rhs._vector[i];
    }

    void    operator*=(K a)
    {
        for (int i = 0; i < rhs._vector.size(); i++)
            _vector[i] *= a;
    }

}

#endif