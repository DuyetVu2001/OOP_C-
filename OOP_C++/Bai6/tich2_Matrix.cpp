#include <iostream>

using namespace std;

void swap(double &a, double &b)
{
    double c = a;
    a = b;
    b = c;
}

class matrix
{
private:
    double **a;
    int rows, cols;

public:
    matrix()
    {
        rows = cols = 0;
        a = NULL;
    }

    matrix(int row, int col)
    {
        rows = row;
        cols = col;
        a = new double *[rows];
        for (int i = 0; i < rows; i++)
        {
            a[i] = new double[cols];
            for (int j = 0; j < cols; j++)
            {
                a[i][j] = 0;
            }
        }
    }

    friend istream &operator>>(istream &x, matrix &y);
    friend ostream &operator<<(ostream &x, matrix &y);
    matrix operator*(matrix y);
    int getRow();
    int getCol();

    /* Sắp xếp trên từng dòng
        * đây là sắp xếp giảm dần, nếu muốn tăng dần, đổi dấu < thành > 
     */
    void sortInRows()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols - 1; j++)
            {
                for (int k = 0; k < cols; k++)
                {
                    if (a[i][j] < a[i][k])
                    {
                        swap(a[i][j], a[i][k]);
                    }
                }
            }
        }
    }

    /* Sắp xếp toàn bộ ma trận
        * đây là sắp xếp giảm dần, nếu muốn tăng dần, đổi dấu < thành > 
     */
    void sortMatrix()
    {
        for (int row1 = 0; row1 < rows; row1++)
        {
            for (int col1 = 0; col1 < cols; col1++)
            {
                for (int row2 = row1; row2 < rows; row2++)
                {
                    for (int col2 = (row2 == row1 ? col1 + 1 : 0); col2 < cols; col2++)
                    {
                        if (a[row1][col1] < a[row2][col2])
                        {
                            swap(a[row1][col1], a[row2][col2]);
                        }
                    }
                }
            }
        }
    }

    ~matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] a[i];
        }
        delete[] a;
        a = NULL;
        rows = cols = 0;
    }
};

istream &operator>>(istream &x, matrix &y)
{
    cout << "nhap so dong: ";
    x >> y.rows;
    cout << "nhap so cot: ";
    x >> y.cols;
    y.a = new double *[y.rows];
    for (int i = 0; i < y.rows; i++)
    {
        y.a[i] = new double[y.cols];
    }
    for (int i = 0; i < y.rows; i++)
    {
        for (int j = 0; j < y.cols; j++)
        {
            cout << "a[" << i << "][" << j << "]:";
            x >> y.a[i][j];
        }
    }
    return x;
}

ostream &operator<<(ostream &x, matrix &y)
{
    for (int i = 0; i < y.rows; i++)
    {
        for (int j = 0; j < y.cols; j++)
        {
            x << y.a[i][j] << " ";
        }
        x << endl;
    }
    return x;
}
matrix matrix::operator*(matrix y)
{
    matrix z;
    z.rows = rows;
    z.cols = y.cols;
    z.a = new double *[z.rows];
    for (int i = 0; i < z.rows; i++)
    {
        z.a[i] = new double[z.cols];
    }
    for (int i = 0; i < this->rows; i++)
    {
        for (int k = 0; k < y.cols; k++)
        {
            z.a[i][k] = 0;
            for (int j = 0; j < this->cols; j++)
            {
                z.a[i][k] += this->a[i][j] * y.a[j][k];
            }
        }
    }
    return z;
}

int matrix::getRow()
{
    return rows;
}

int matrix::getCol()
{
    return cols;
}

int main()
{
    matrix a, b, c;
    cout << "nhap ma tran A: ";
    cin >> a;
    cout << "Truoc khi sap xep: " << endl;
    cout << a;
    a.sortMatrix();
    cout << "Sau khi sap xep: " << endl;
    cout << a;

    // do
    // {
    //     cout << "nhap ma tran B: ";
    //     cin >> b;
    //     if (a.getCol() != b.getRow())
    //     {
    //         cout << "so dong cua b phai bang so cot cua a!" << endl;
    //     }
    // } while (a.getCol() != b.getRow());
    // c = a * b;
    // cout << "tich hai ma tran A va B la: " << endl;
    // cout << c;
    return 0;
}