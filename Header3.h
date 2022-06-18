#pragma once

#define MATRIX_EXPORTS ANYA

#ifdef MATRIX_EXPORTS
#define MATRIX_API __declspec(dllexport)
#else
#define MATRIX_API __declspec(dllimport)
#endif

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <exception>

using std::rand;
using std::srand;
using namespace std;

int GetRandomNum()
{
    return rand() % 9;  // ���������� ��������� �����
}

class Wrong_size_exception {};
class Square_issue_exception {};
class Matching_issue_exception {};

class MATRIX_API Matrix
{
public:
    vector<vector<double>> matrix;
    vector<double> numbers;
    int row;
    int column;

    Matrix() : row(0), column(0) {}
    Matrix(int row, int column) : row(row), column(column)
    {
        matrix.resize(row, vector<double>(column));
    }

    friend Matrix operator+(const Matrix& a, const Matrix& b);
    friend ostream& operator<<(ostream& out, const Matrix& m);
    friend Matrix operator-(const Matrix& a, const Matrix& b);
    friend Matrix operator*(const Matrix& a, double ch);
    friend Matrix operator*(double ch, const Matrix& a);
    friend Matrix operator*(const Matrix& a, const Matrix& b);
    friend Matrix Adamar(const Matrix& a, const Matrix& b);
    friend int Sled(const Matrix& a);
    friend int Scal(const Matrix& a, const Matrix& b);
    friend void NormaVec(const Matrix& a);
    friend float NormaMat(const Matrix& a);
    friend int Opr(Matrix& a);
    friend double Deg(const Matrix& a, const Matrix& b);
    friend Matrix Transpose(const Matrix& a);
    friend Matrix Tr(const Matrix& a);
    friend Matrix Obratnaya(Matrix& a);
    friend int Rank(Matrix& a);
};


class MATRIX_API Ordinary : public Matrix {
public:
    Ordinary() : Matrix(0, 0) {}
    Ordinary(int row, int column) : Matrix(row, column)
    {
        matrix.resize(row, vector<double>(column));
    }

    void CreateMatrix()
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
            {
                int m;
                cin >> m;
                matrix[i][j] = m;

            }
    }
};

class MATRIX_API Unitary : public Matrix {
public:
    Unitary() : Matrix(0, 0) {}
    Unitary(int row, int column) : Matrix(row, column)
    {
        matrix.resize(row, vector<double>(column));
    }

    void CreateMatrix()
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
            {
                if (i == j)
                    matrix[i][j] = 1;
                else
                    matrix[i][j] = 0;
            }
    }
};

class MATRIX_API Diagonal : public Matrix {
public:
    Diagonal() : Matrix(0, 0) {}
    Diagonal(int row, int column) : Matrix(row, column)
    {
        matrix.resize(row, vector<double>(column));
    }

    void CreateMatrix()
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
            {
                if (i == j) {

                    matrix[i][j] = GetRandomNum();
                }
                else
                    matrix[i][j] = 0;

            }
    }
};

class MATRIX_API UpTr : public Matrix {
public:
    UpTr() : Matrix(0, 0) {}
    UpTr(int row, int column) : Matrix(row, column)
    {
        matrix.resize(row, vector<double>(column));
    }

    void CreateMatrix()
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
            {
                if (i <= j) {

                    matrix[i][j] = GetRandomNum();
                }
                else
                    matrix[i][j] = 0;

            }
    }
};

class MATRIX_API LowTr : public Matrix {
public:
    LowTr() : Matrix(0, 0) {}
    LowTr(int row, int column) : Matrix(row, column)
    {
        matrix.resize(row, vector<double>(column));
    }

    void CreateMatrix()
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
            {
                if (i >= j) {

                    matrix[i][j] = GetRandomNum();
                }
                else
                    matrix[i][j] = 0;

            }
    }
};

class MATRIX_API SimMat : public Matrix {
public:
    SimMat() : Matrix(0, 0) {}
    SimMat(int row, int column) : Matrix(row, column)
    {
        matrix.resize(row, vector<double>(column));
    }

    void CreateMatrix()
    {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++)
            {
                if (i == j)
                    matrix[i][j] = GetRandomNum();
                if (i < j)
                    matrix[i][j] = i + 1;
                if (i > j)
                    matrix[i][j] = j + 1;
            }
        }
    }
};

Matrix operator+(const Matrix& a, const Matrix& b)
{
    setlocale(LC_ALL, "rus");
    if (a.row != b.row || a.column != b.column)
    {
        cout << "�������� �� ����� ���� ���������.\n";
        throw Matching_issue_exception();
    }
    else
    {
        cout << "����� ������ �����:" << endl;
        Matrix result(a.row, a.column);
        for (int i = 0; i < a.row; i++)
        {
            for (int j = 0; j < a.column; j++)
            {
                result.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
            }
        }
        return result;
    }
}
Matrix operator-(const Matrix& a, const Matrix& b)
{
    setlocale(LC_ALL, "rus");
    if (a.row != b.row || a.column != b.column)
    {
        cout << "�������� �� ����� ���� ���������.\n";
        throw Matching_issue_exception();
    }
    else
    {
        cout << "�������� ������ �����:" << endl;
        Matrix result(a.row, a.column);
        for (int i = 0; i < a.row; i++)
        {
            for (int j = 0; j < a.column; j++)
            {
                result.matrix[i][j] = a.matrix[i][j] - b.matrix[i][j];
            }
        }
        return result;
    }
}

Matrix operator*(const Matrix& a, double ch)
{
    setlocale(LC_ALL, "rus");
    cout << "������������ ������� � ����� �����:" << endl;
    Matrix result(a.row, a.column);
    for (int i = 0; i < a.row; i++)
    {
        for (int j = 0; j < a.column; j++)
        {
            result.matrix[i][j] = a.matrix[i][j] * ch;
        }
    }
    return result;
}

Matrix operator*(double ch, const Matrix& a)
{
    setlocale(LC_ALL, "rus");
    cout << "������������ ������� � ����� �����:" << endl;
    Matrix result(a.row, a.column);
    for (int i = 0; i < a.row; i++) {
        for (int j = 0; j < a.column; j++)
        {
            result.matrix[i][j] = a.matrix[i][j] * ch;
        }

    }
    return result;
}

Matrix operator*(const Matrix& a, const Matrix& b)
{
    setlocale(LC_ALL, "rus");
    if (a.column != b.row)
    {
        cout << "�������� �� ����� ���� ���������\n";
        throw Matching_issue_exception();
    }
    else
    {
        cout << "������������ ������ �����:" << endl;
        Matrix result(a.row, a.column);
        for (int i = 0; i < a.row; i++)
        {
            for (int j = 0; j < a.column; j++)
            {
                result.matrix[i][j] = 0;
                for (int k = 0; k < a.row; k++) {
                    result.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
                }
            }
        }
        return result;
    }
}


ostream& operator<<(ostream& out, const Matrix& m) {
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.column; j++)
            out << m.matrix[i][j] << " ";
        out << endl;
    }
    return out;
}


Matrix Adamar(const Matrix& a, const Matrix& b) {
    setlocale(LC_ALL, "rus");
    if (a.row != b.row || a.column != b.column)
    {
        cout << "�������� �� ����� ���� ���������\n";
        throw Matching_issue_exception();
    }
    else
    {
        cout << "������������ ������� �����:" << endl;
        Matrix result(a.row, a.column);
        for (int i = 0; i < a.row; i++)
        {
            for (int j = 0; j < a.column; j++)
            {
                result.matrix[i][j] = a.matrix[i][j] * b.matrix[i][j];
            }
        }
        return result;
    }
}

int Sled(const Matrix& a) {
    setlocale(LC_ALL, "rus");
    if (a.row != a.column)
    {
        cout << "�������� �� ����� ���� ���������\n";
        throw Square_issue_exception();
    }
    else
    {
        cout << "���� ������� �����:" << endl;
        int sled = 0;
        for (int i = 0; i < a.row; i++)
            for (int j = 0; j < a.column; j++)
            {
                if (i == j)
                    sled = sled + a.matrix[i][j];
            }

        return sled;
    }
}

int Scal(const Matrix& a, const Matrix& b) {
    setlocale(LC_ALL, "rus");
    if (a.row != b.row || a.column != b.column || a.row != 1 || b.row != 1)
    {
        cout << "�������� �� ����� ���� ���������.\n" << endl;
        if (a.row != b.row || a.column != b.column) {
            throw Matching_issue_exception();
        }
        else
        {
            cout << "������ ������ ������ ���� ����� 1, �� ����������� �������...\n" << endl;
            throw Wrong_size_exception();
        }
    }
    else {
        cout << "��������� ������������� �������� �����:" << endl;
        int scalar = 0;
        for (int j = 0; j < a.column; j++) {
            scalar = scalar + a.matrix[0][j] * b.matrix[0][j];
        }
        return scalar;
    }
}

void NormaVec(const Matrix& a) {
    setlocale(LC_ALL, "rus");
    cout << "��������� ����� ������� �����:" << endl;
    float norm = 0;
    for (int j = 0; j < a.column; j++) {
        norm = norm + a.matrix[0][j] * a.matrix[0][j];
    }
    norm = sqrt(norm);
    cout << norm << endl;
    int norm2 = abs(a.matrix[0][0]);
    cout << "������������ ����� ������� �����:" << endl;
    for (int j = 1; j < a.column; j++) {
        if (abs(a.matrix[0][j]) > norm2) {
            norm2 = abs(a.matrix[0][j]);
        }
    }
    cout << norm2;
}

float NormaMat(const Matrix& a) {
    setlocale(LC_ALL, "rus");
    cout << "����� ������� �����:" << endl;
    float no = 0;
    for (int i = 0; i < a.row; i++)
        for (int j = 0; j < a.column; j++)
        {
            no = no + a.matrix[i][j] * a.matrix[i][j];
        }
    return sqrt(no);
}

int Opr(Matrix& a)
{
    double v;
    int s = 0;
    for (int k = 0, i, j, im; k < a.column - 1; k++) {
        im = k;
        for (i = k + 1; i < a.column; i++) {
            if (abs(a.matrix[im][k]) < abs(a.matrix[i][k])) {
                im = i;
            }
        }
        if (im != k) {
            s += 1;
            for (j = 0; j < a.column; j++) {
                v = a.matrix[im][j];
                a.matrix[im][j] = a.matrix[k][j];
                a.matrix[k][j] = v;
            }
        }
        for (i = k + 1; i < a.column; i++) {
            v = 1.0 * a.matrix[i][k] / a.matrix[k][k];
            a.matrix[i][k] = 0;
            if (v != 0) {
                for (j = k + 1; j < a.column; j++) {
                    a.matrix[i][j] -= v * a.matrix[k][j];
                }
            }
        }
    }

    /*cout << "\nTarget matrix (Gauss method):\n\n";
    cout.precision(2);
    for (int i = 0; i < a.row; i++) {
        for (int j = 0; j < a.column; j++) {
            cout.width(8);
            cout << fixed << a.matrix[i][j] << " ";
        }
        cout << "\n";
    }*/

    float d = 1;
    for (int i = 0; i < a.row; i++) {
        d *= a.matrix[i][i];
    }
    d *= pow(-1, s);
    //cout << fixed << "\nMatrix determinant: " << d << "\n";
    return d;

}

int Rank(Matrix& a) {
    double v;
    int s = 0;
    for (int k = 0, i, j, im; k < a.column - 1; k++) {
        im = k;
        for (i = k + 1; i < a.column; i++) {
            if (abs(a.matrix[im][k]) < abs(a.matrix[i][k])) {
                im = i;
            }
        }
        if (im != k) {
            s += 1;
            for (j = 0; j < a.column; j++) {
                v = a.matrix[im][j];
                a.matrix[im][j] = a.matrix[k][j];
                a.matrix[k][j] = v;
            }
        }
        for (i = k + 1; i < a.column; i++) {
            v = 1.0 * a.matrix[i][k] / a.matrix[k][k];
            a.matrix[i][k] = 0;
            if (v != 0) {
                for (j = k + 1; j < a.column; j++) {
                    a.matrix[i][j] -= v * a.matrix[k][j];
                }
            }
        }
    }

    cout << "\nTarget matrix (Gauss method):\n\n";
    cout.precision(2);
    for (int i = 0; i < a.row; i++) {
        for (int j = 0; j < a.column; j++) {
            cout.width(8);
            cout << fixed << a.matrix[i][j] << " ";
        }
        cout << "\n";
    }

    int rank = a.row;

    for (int i = 0; i < a.row; i++) {
        int s = a.column;
        for (int j = 0; j < a.column; j++) {
            if (a.matrix[i][j] == 0) {
                s--;
            }
        }
        if (s == 0) {
            rank--;
        }
    }

    cout << "���� �������:\n";

    return rank;
}

double Deg(const Matrix& a, const Matrix& b) {
    setlocale(LC_ALL, "rus");
    if (a.column != b.column || a.column <= 0 || b.column <= 0)
    {
        cout << "�������� �� ����� ���� ���������." << endl;
        exit(1);
    }
    double degr;

    float norm1 = 0;
    for (int j = 0; j < a.column; j++) {
        norm1 = norm1 + a.matrix[0][j] * a.matrix[0][j];
    }
    norm1 = sqrt(norm1);

    float norm2 = 0;
    for (int j = 0; j < b.column; j++) {
        norm2 = norm2 + b.matrix[0][j] * b.matrix[0][j];
    }
    norm2 = sqrt(norm2);

    int scalar2 = 0;
    for (int j = 0; j < a.column; j++) {
        scalar2 = scalar2 + a.matrix[0][j] * b.matrix[0][j];
    }

    cout << "������� ���� ����� ��������� �����:\n";
    return (scalar2 / (norm1 * norm2));
}

/*Matrix Transpose(Matrix& a){
    setlocale(LC_ALL, "rus");
    Matrix result(a.column, a.row);
    for (int i = 0; i < a.column; i++){
        for (int j = 0; j < a.row; j++){
            result.matrix[i][j] = a.matrix[j][i];
        }
    }
    return result;
}*/

Matrix Transpose(Matrix& a) {
    setlocale(LC_ALL, "rus");
    Matrix result(a.column, a.row);
    for (int i = 0; i < a.column; i++) {
        for (int j = 0; j < a.row; j++) {
            result.matrix[i][j] = a.matrix[j][i];
        }
    }
    a.matrix.resize(a.column, vector<double>(a.row));
    int t = a.row;
    a.row = a.column;
    a.column = t;
    a.matrix = result.matrix;
    return a;
}

Matrix Obratnaya(Matrix& a) {
    setlocale(LC_ALL, "rus");
    //Matrix result(a.column, a.row);
    return((1.0 / Opr(a)) * Transpose(a));

}

int input, input2, input3, r, c, r2, c2, n;
Matrix a(0, 0);
Matrix b(0, 0);

void menu0() {
    cout << "�������� ��� �������\n";
    cout << "1. ��������� �������\n";
    cout << "2. ������������ �������\n";
    cout << "3. ������� ����������� �������\n";
    cout << "4. ������ ����������� �������\n";
    cout << "5. ������������ �������\n";
    cout << "6. ������� ������� � ���������� ����������\n";
    cout << "7. Exit\n";
}

void menu3() {
    menu0();
    cout << "��� �����: ";
    cin >> input3;
    if (input3 == 7) {
        exit(1);
    }

    while (1) {
        cout << "������� ���������� ����� �������: ";
        cin >> r2;
        cout << "������� ���������� �������� �������: ";
        cin >> c2;
        if (r2 > 0 and c2 > 0) {
            break;
        }
        else {
            cout << "�� ����� ���� ������� �������������� ������� ��� ������� 0\n";
        }
    }

    if (input3 == 1) {
        Unitary mat2(r2, c2);
        mat2.CreateMatrix();
        b = mat2;
        cout << b;
    }

    if (input3 == 2) {
        Diagonal mat2(r2, c2);
        mat2.CreateMatrix();
        b = mat2;
        cout << b;
    }

    if (input3 == 3) {
        UpTr mat2(r2, c2);
        mat2.CreateMatrix();
        b = mat2;
        cout << b;
    }

    if (input3 == 4) {
        LowTr mat2(r2, c2);
        mat2.CreateMatrix();
        b = mat2;
        cout << b;
    }

    if (input3 == 5) {
        SimMat mat2(r2, c2);
        mat2.CreateMatrix();
        b = mat2;
        cout << b;
    }

    if (input3 == 6) {
        Ordinary mat2(r2, c2);
        mat2.CreateMatrix();
        b = mat2;
        cout << b;
    }
}

void menu1()
{
    cout << "������� �������� ��������:\n";
    cout << "1. �������� ������� �� �������\n";
    cout << "2. �������� ������� �� �����\n";
    cout << "3. ������� ������� � ������ ��������\n";
    cout << "4. ������� �� ������� ������ �������\n";
    cout << "5. ��������� ������������ ������� ���� ������\n";
    cout << "6. ��������� ���� �������\n";
    cout << "7. ��������� ��������� ������������ �������� (1 ������ � ������� �������!)\n";
    cout << "8. ��������� ����� �������\n";
    cout << "9. ��������� ������������ ������� (������� ������)\n";
    cout << "10. ��������� ����� ������� (����� ����������)\n";
    cout << "11. ��������� ���� ����� ���������\n";
    cout << "12. ��������������� �������\n";
    cout << "13. �������� �������\n";
    cout << "14. ���� ������� ������� ������\n";
    cout << "15. Exit\n";
    cout << "��� �����: ";
    cin >> input2;

    if (input2 == 15) {
        exit(1);
    }

    if (input2 == 1 || input2 == 3 || input2 == 4 || input2 == 5) {
        menu0();
        cout << "��� �����: ";
        cin >> input;
        if (input == 7) {
            exit(1);
        }

        while (1) {
            cout << "������� ���������� ����� �������: ";
            cin >> r;
            cout << "������� ���������� �������� �������: ";
            cin >> c;
            if (r > 0 and c > 0) {
                break;
            }
            else {
                cout << "�� ����� ���� ������� �������������� ������� ��� ������� 0\n";
            }
        }

        if (input == 1) {
            Unitary mat1(r, c);
            mat1.CreateMatrix();
            a = mat1;
            cout << a;
        }

        if (input == 2) {
            Diagonal mat1(r, c);
            mat1.CreateMatrix();
            a = mat1;
            cout << a;
        }

        if (input == 3) {
            UpTr mat1(r, c);
            mat1.CreateMatrix();
            a = mat1;
            cout << a;
        }

        if (input == 4) {
            LowTr mat1(r, c);
            mat1.CreateMatrix();
            a = mat1;
            cout << a;
        }

        if (input == 5) {
            SimMat mat1(r, c);
            mat1.CreateMatrix();
            a = mat1;
            cout << a;
        }

        if (input == 6) {
            Ordinary mat1(r, c);
            mat1.CreateMatrix();
            a = mat1;
            cout << a;
        }

        menu3();
    }
    try {

        if (input2 == 1) {
            cout << "�������� ���������:\n";
            cout << a * b;
        }

        if (input2 == 2) {
            menu3();
            cout << "������� �����, �� ������� �������� �������: ";
            cin >> n;
            cout << "����: ";
            cout << b * n;
        }

        if (input2 == 3) {
            cout << "�������� ���������:\n";
            cout << a + b;
        }

        if (input2 == 4) {
            cout << "�������� ���������:\n";
            cout << a - b;
        }

        if (input2 == 5) {
            cout << "�������� ���������:\n";
            cout << Adamar(a, b);
        }

        if (input2 == 6) {
            menu3();
            cout << Sled(b);
        }


        if (input2 == 7) {
            cout << "������� ���������� ��������� �������1: ";
            cin >> c;
            Ordinary mat1(1, c);
            mat1.CreateMatrix();
            a = mat1;
            cout << a;

            cout << "������� ���������� ��������� �������2: ";
            cin >> c2;
            Ordinary mat2(1, c2);
            mat2.CreateMatrix();
            b = mat2;
            cout << b;
            cout << Scal(a, b);
        }

        if (input2 == 8) {
            cout << "������� ���������� ��������� �������: ";
            cin >> c;
            Ordinary mat1(1, c);
            mat1.CreateMatrix();
            a = mat1;
            cout << a;
            NormaVec(a);
        }

        if (input2 == 9) {
            menu3();
            cout << "������������ ������� ����� ";
            cout << Opr(b);
        }

        if (input2 == 10) {
            menu3();
            cout << NormaMat(b);
        }

        if (input2 == 11) {
            cout << "������� ���������� ��������� �������1: ";
            cin >> c;
            Ordinary mat1(1, c);
            mat1.CreateMatrix();
            a = mat1;
            cout << a;

            cout << "������� ���������� ��������� �������2: ";
            cin >> c2;
            Ordinary mat2(1, c2);
            mat2.CreateMatrix();
            b = mat2;
            cout << b;
            cout << Deg(a, b);
        }

        if (input2 == 12) {
            menu3();
            cout << "--------------------------------------\n";
            cout << "����������������� �������:\n";
            cout << Transpose(b);
            cout << "---------------------------------------\n";

        }

        if (input2 == 13) {
            menu3();
            cout << "�������� �������:\n";
            cout << Obratnaya(b);
            cout << "---------------------------------------\n";

        }

        if (input2 == 14) {
            menu3();
            cout << Rank(b);

        }

        if (input2 == 15) {
            exit(1);
        }

    }
    catch (Matching_issue_exception) {
        cout << "������� ������� �������! ��������� ���������� ����...\n";
        menu1();
    }
    catch (Wrong_size_exception) {
        cout << "�� ���������� ����� �������\n";
        menu1();
    }
    catch (Square_issue_exception) {
        cout << "������� ������ ���� ����������\n";
        menu1();
    }
}

