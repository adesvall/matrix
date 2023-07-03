#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <utility>
#include <iostream>
#include "Vector.hpp"

using namespace std;

template <typename K>
class Matrix
{
public:
    vector<K> _data;
    size_t _rows;
    size_t _cols;

    Matrix() {}
    Matrix(vector<vector<K>> const &vector) {
        _rows = vector.size();
        _cols = vector[0].size();
        for (size_t i = 0; i < _rows; i++)
            for (size_t j = 0; j < _cols; j++)
                _data.push_back(vector[i][j]);
    }
    Matrix(vector<K> const &vector, size_t rows, size_t cols) : _data(vector), _rows(rows), _cols(cols) {}
    Matrix(Matrix const &rhs) : _data(rhs._data), _rows(rhs._rows), _cols(rhs._cols) {}
    Matrix &operator=(Matrix const &rhs)
    {
        _data = rhs._data;
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

        for (size_t i = 0; i < rhs._data.size(); i++)
            _data[i] += rhs._data[i];
    }

    void    operator-=(Matrix const &rhs)
    {
        if (shape() != rhs.shape())
            throw exception();

        for (size_t i = 0; i < _data.size(); i++)
            _data[i] -= rhs._data[i];
    }

    void    operator*=(K a)
    {
        for (size_t i = 0; i < _data.size(); i++)
            _data[i] *= a;
    }

    K& operator()(size_t i, size_t j) { return _data[i * _cols + j]; }
    K operator()(size_t i, size_t j) const { return _data[i * _cols + j]; }

    Vector<K> mul_vec(Vector<K> vec) const
    {
        Vector<K> result;
    
        if (_cols != vec.size())
            throw exception();

        for (size_t i = 0; i < _rows; i++) {
            K sum = 0;
            for (size_t j = 0; j < _cols; j++)
                sum += (*this)(i, j) * vec[j];
            result._data.push_back(sum);
        }
        return result;
    }

    Matrix mul_mat(Matrix mat) const
    {
        vector<K> result;
    
        if (_cols != mat._rows)
            throw exception();

        for (size_t i = 0; i < _rows; i++) {
            for (size_t j = 0; j < mat._cols; j++) {

                K sum = 0;
                for (size_t k = 0; k < _cols; k++)
                    sum += (*this)(i, k) * mat(k, j);
                result.push_back(sum);
            }
        }
        return Matrix(result, _rows, mat._cols);
    }

    K   trace() const
    {
        if (!isSquare())
            throw exception();

        K res = 0;
        for (size_t i = 0; i < _rows; i++)
            res += (*this)(i,i);
        return res;
    }

    Matrix transpose()   const
    {
        vector<K> data;

        for (size_t i = 0; i < _cols; i++)   {
            for (size_t j = 0; j < _rows; j++)   {
                data.push_back((*this)(j, i));
            }
        }
        return Matrix(data, _cols, _rows);
    }

    void   swap_rows(size_t i1, size_t i2)
    {
        if (i1 >= _rows || i2 >= _rows)
            throw exception();
        if (i1 == i2)
            return;

        for (size_t k = 0; k < _cols; k++)
            swap((*this)(i1, k), (*this)(i2, k));
    }

    Matrix row_echelon()    const
    {
        Matrix mat(*this);
        size_t pivot_i = 0;
        size_t pivot_j = 0;

        while (pivot_i < mat._rows && pivot_j < mat._cols) {
            size_t min_i = pivot_i;
            for (size_t i = pivot_i + 1; i < mat._rows; i++) {
                if ((abs(mat(i, pivot_j)) < abs(mat(min_i, pivot_j)) \
                                            && mat(i, pivot_j) != 0) \
                                            || mat(min_i, pivot_j) == 0)
                    min_i = i;
            }
            if (mat(min_i, pivot_j) != 0)   {
                mat.swap_rows(pivot_i, min_i);
                K c = mat(pivot_i, pivot_j);
                for (size_t j = pivot_j; j < mat._cols; j++)
                    mat(pivot_i, j) /= c;
            }
            else {
                pivot_j++;
                continue;
            }
            for (size_t i = pivot_i + 1; i < mat._rows; i++) {
                K c = mat(i, pivot_j) / mat(pivot_i, pivot_j);
                for (size_t j = pivot_j; j < mat._cols; j++)
                    mat(i, j) -= mat(pivot_i, j) * c;
            }
            pivot_i++;
            pivot_j++;
        }

        // REDUCED ROW ECHELON FORM
        for (size_t i = mat._rows - 1; i > 0; i--) {
            for (size_t j = 0; j < mat._cols; j++) {
                if (mat(i, j) != 0) {
                    for (size_t k = i - 1; k < i; k--) {
                        K c = mat(k, j) / mat(i, j);
                        for (size_t l = j; l < mat._cols; l++)
                            mat(k, l) -= mat(i, l) * c;
                    }
                    break;
                }
            }
        }
        return mat;
    }

    


};

template <typename K>
ostream& operator<<(ostream& os, const Matrix<K>& mat)
{
    os << "Matrix:" << endl;
    for (size_t i = 0; i < mat.shape().first; i++) {
        for (size_t j = 0; j < mat.shape().second; j++)
            os << "  " << mat(i, j);
        os << endl;
    }
        
    return os;
}

#endif