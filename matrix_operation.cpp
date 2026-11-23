#include <iostream> 
#include <cassert> 
using namespace std; 
class Matrix 
{ 
private: 
    int data[2][2]; 
public: 
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0) 
 
 
    { 
        data[0][0] = a; 
        data[0][1] = b; 
        data[1][0] = c; 
        data[1][1] = d; 
    } 
    // Operator + 
    Matrix operator+(const Matrix &m) 
    { 
        Matrix result; 
        for (int i = 0; i < 2; i++) 
            for (int j = 0; j < 2; j++) 
                result.data[i][j] = data[i][j] + m.data[i][j]; 
        return result; 
    } 
    // Operator * 
    Matrix operator*(const Matrix &m) 
    { 
        Matrix result; 
        for (int i = 0; i < 2; i++) 
        { 
            for (int j = 0; j < 2; j++) 
            { 
                result.data[i][j] = 0; 
 
                for (int k = 0; k < 2; k++) 
                    result.data[i][j] += data[i][k] * m.data[k][j]; 
 
 
            } 
        } 
        return result; 
    } 
    // Operator [] 
    int* operator[](int index) 
    { 
        return data[index]; 
    } 
 
    // Operator << 
    friend ostream& operator<<(ostream &out, const Matrix &m) 
    { 
        for (int i = 0; i < 2; i++) 
        { 
            for (int j = 0; j < 2; j++) 
                out << m.data[i][j] << " "; 
 
            out << endl; 
        } 
        return out; 
    } 
}; 
int main()
{
    int a1, a2, a3, a4;
    int b1, b2, b3, b4;

    cout << "Enter 4 elements of Matrix A: ";
    cin >> a1 >> a2 >> a3 >> a4;

    cout << "Enter 4 elements of Matrix B: ";
    cin >> b1 >> b2 >> b3 >> b4;

    Matrix A(a1, a2, a3, a4);
    Matrix B(b1, b2, b3, b4);

    Matrix sum = A + B;
    Matrix product = A * B;

    cout << "Matrix A:" << endl;
    cout << A;

    cout << "Matrix B:" << endl;
    cout << B;

    cout << "Addition of Matrices:" << endl;
    cout << sum;

    cout << "Multiplication of Matrices:" << endl;
    cout << product;

    cout << "Matrix operations completed successfully." << endl;

    return 0;
}