#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <utility>
#include <iostream>

using namespace std;

template <typename K>
class Matrix
{
public:
    vector<K> _vector;
    size_t _rows;
    size_t _cols;

    Matrix() {}
    Matrix(vector<vector<K>> const &vector) {
        _rows = vector.size();
        _cols = vector[0].size();
        for (size_t i = 0; i < _rows; i++)
            for (size_t j = 0; j < _cols; j++)
                _vector.push_back(vector[i][j]);
    }
    Matrix(vector<K> const &vector, size_t rows, size_t cols) : _vector(vector), _rows(rows), _cols(cols) {}
    Matrix(Matrix const &rhs) : _vector(rhs._vector), _rows(rhs._rows), _cols(rhs._cols) {}
    Matrix &operator=(Matrix const &rhs)
    {
        _vector = rhs._vector;
        _rows = rhs._rows;
        _cols = rhs._cols;
        return *this;
    }

    pair<size_t, size_t>  shape() const { return make_pair(_rows, _cols); }

    bool isSquare() const { return _rows == _cols; }

    void    operator+=(Matrix const &rhs)
    {
        if (shape() != rhs.shape())
            throw exception();

        for (size_t i = 0; i < rhs._vector.size(); i++)
            _vector[i] += rhs._vector[i];
    }

    void    operator-=(Matrix const &rhs)
    {
        if (shape() != rhs.shape())
            throw exception();

        for (size_t i = 0; i < _vector.size(); i++)
            _vector[i] -= rhs._vector[i];
    }

    void    operator*=(K a)
    {
        for (size_t i = 0; i < _vector.size(); i++)
            _vector[i] *= a;
    }

    K& operator[](pair<size_t, size_t> p) { return _vector[p.first * _cols + p.second]; }
    K operator[](pair<size_t, size_t> p) const { return _vector[p.first * _cols + p.second]; }

};

template <typename K>
ostream& operator<<(ostream& os, const Matrix<K>& mat)
{
    os << "Matrix:" << endl;
    for (size_t i = 0; i < mat.shape().first; i++) {
        for (size_t j = 0; j < mat.shape().second; j++)
            os << "\t" << mat[make_pair(i, j)];
        os << endl;
    }
        
    return os;
}

#endif