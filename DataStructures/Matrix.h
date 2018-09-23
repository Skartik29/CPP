#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <vector>
#include <iostream>

template <typename T>
class Matrix
{
private:
    unsigned int _dimX, _dimY;
    std::vector<T> _inner;
public:
    Matrix(unsigned int dimX, unsigned int dimY) : _dimX(dimX), _dimY(dimY)
    {
        _inner.resize(_dimX*_dimY);
        std::fill(_inner.begin(), _inner.end(), 0);
    }
    T& operator()(unsigned int x, unsigned int y)
    {
        if (x >= _dimX || y >= _dimY) throw std::out_of_range("matrix indices out of range");
        return _inner[_dimX*y+x];
    }
    void SetValue(int r, int c, int v)
    {
        _inner[_dimX*c+r] = v;
    }
    Matrix(const Matrix &cpy)
    {
        _dimX = cpy.GetX();
        _dimY = cpy.GetY();
        _inner = cpy.GetInner();
    }
    int GetX() const {return _dimX;}
    int GetY() const {return _dimY;}
    std::vector<T> GetInner() const {return _inner;}
    void ResizeInner(int x, int y) {_dimX = x; _dimY = y; _inner.resize(_dimX*_dimY);}
    void AddToVectorEnd(int v, int ind) {_inner[ind] = v;}
};

#endif // MATRIX_H_INCLUDED
