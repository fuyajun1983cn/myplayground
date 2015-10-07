#ifndef _ARRAY2D_H
#define _ARRAY2D_H

template<typename T>
class Array2D {
 public:
  Array2D(int r = 0, int c = 0);
  Array2D(const Array2D<T>& m); //复制构造函数
  ~Array2D() { delete []row; }
  int Rows() const { return rows; }
  int Columns() const { return cols; }
  Array1D<T>& operator[](int i) const;
  Array2D<T>& operator=(const Array2D<T>& m);
  Array2D<T> operator+() const; // 一元加法操作符
  Array2D<T> operator+(const Array2D<T>& m) const;
  Array2D<T> operator-() const; // 一元减法操作符
  Array2D<T> operator-(const Array2D<T>& m) const;
  Array2D<T> operator*(const Array2D<T>& m) const;
  Array2D<T>& operator+=(const T& x);

 private:
  int rows, cols;
  Array1D<T> *row;
};

template<typename T>
Array2D<T>::Array2D(int r, int c)
{
  if (r <= 0 || c <= 0)
    throw BadInitializer();

  rows = r;
  cols = c;

  row = new Array1D<T>[rows];
  for (int i = 0; i < rows; i++) {
    row[i].Resize(cols);
  }

}

template<typename T>
Array2D<T>::Array2D(const Array2D<T>& m)
{

    delete []row;

    rows = m.rows;
    cols = m.cols;

    row = new Array1D<T>[rows];
    for (int i = 0; i < rows; i++) {
      row[i] = m.row[i];
    }
}

template<typename T>
Array2D<T>& Array2D<T>::operator=(const Array2D<T>& m)
{
  if (this != &m) {
    delete []row;

    rows = m.rows;
    cols = m.cols;

    row = new Array1D<T>[rows];
    for (int i = 0; i < rows; i++) {
      row[i] = m.row[i];
    }
  }

  return *this;
}

template<typename T>
Array1D<T>& Array2D<T>::operator[](int i) const
{
  if (i < 0 || i > rows)
    throw OutOfBounds();

  return row[i];
}

template<typename T>
Array2D<T> Array2D<T>::operator-() const
{
  Array2D<T> w(rows, cols);

  for (int i = 0; i < rows; i++) {
    w.row[i] =  -rows[i];
  }

  return w;
}

template<typename T>
Array2D<T> Array2D<T>::operator-(const Array2D<T>& m) const
{
  if (rows != m.rows || cols != m.cols)
    throw SizeMismatch();

  Array2D<T> w(rows, cols);

  for (int i = 0; i < rows; i++) {
    w.row[i] = row[i] - m.row[i];
  }

  return w;
}

template<typename T>
Array2D<T> Array2D<T>::operator+() const
{
  Array2D<T> w(rows, cols);

  for (int i = 0; i < rows; i++) {
    w.row[i] = +row[i];
  }

  return w;
}

template<typename T>
Array2D<T> Array2D<T>::operator+(const Array2D<T>& m) const
{
  if (rows != m.rows || cols != m.cols)
    throw SizeMismatch();

  for (int i = 0; i < rows; i++) {
    w.row[i] = row[i] + m.row[i];
  }

  return w;
}

template<typename T>
Array2D<T> Array2D<T>::operator*(const Array2D<T>& m) const
{
  if (cols != m.rows)
    throw SizeMismatch();

  Array2D<T> w(rows, m.cols);

  for (int i = 0; i < w.rows; i++) {
    for (int j = 0; j < w.cols; j++) {
      T sum = (*this)[i][0] * m[0][j];
      for (int k = 1; k < cols; k++) {
	sum += (*this)[i][k] * m[k][j];
      }
      w[i][j] = sum;
    }
  }

  return w;
}

#endif
