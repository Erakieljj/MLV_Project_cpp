#include <cstring>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <matrix.h>

using namespace std;

Matrix::Matrix():m(0),n(0)
{

}

Matrix::Matrix(double m,double n) :m(m),n(n)
{
    this->mat.resize(m);
    for(int i = 0 ; i < m ; ++i)
    {
        mat[i].resize(n);
    }
}

Matrix::Matrix(vector<Point> points) :m(3),n(points.size()){
    this->mat.resize(this->m);
    for(int i = 0 ; i < this->m ; ++i)
    {
        mat[i].resize(this->n);
    }

    for(int j=0;j<this->n;j++){
        Point p = points.at(j);
        mat[0][j]=p.get_x();
        mat[1][j]=p.get_y();
        mat[2][j]= 1;
    }
}

Matrix* Matrix::idMatrix(double n){
    Matrix *m = new Matrix(n,n);
    for(int i=0; i< m->m; i++) {
        m->mat[i][i] = 1;
    }
    return m;
}

Matrix* Matrix::translation(double x, double y)
{
    Matrix *m = idMatrix(3);
    m->mat[0][2]=x;
    m->mat[1][2]=y;

    return m;
}


Matrix* Matrix::rotationDirect(double alpha)
{
    Matrix *m = idMatrix(3);
    m->mat[0][0]=cos(alpha);
    m->mat[0][1]=sin(alpha);
    m->mat[1][0]=-sin(alpha);
    m->mat[1][1]=cos(alpha);

    return m;
}

Matrix Matrix::rotationCentral(double alpha,double a,double b)
{
    //Matrix *m1 = translation(-a,-b);
    a=0;
    b=0;
    Matrix *m2 = idMatrix(3);
    m2->mat[0][0]=cos(alpha);
    m2->mat[0][1]=sin(alpha);
    m2->mat[1][0]=-sin(alpha);
    m2->mat[1][1]=cos(alpha);

    return (*m2);
}

Matrix* Matrix::rotationIndirect(double alpha)
{

    Matrix *m = idMatrix(3);
    m->mat[0][0]=cos(alpha);
    m->mat[0][1]=-sin(alpha);
    m->mat[1][0]=sin(alpha);
    m->mat[1][1]=cos(alpha);

    return m;
}

Matrix* Matrix::homothety(double x, double y)
{
    Matrix *m = idMatrix(3);
    m->mat[0][0]=x;
    m->mat[1][1]=y;

    return m;
}

Matrix Matrix::axialSymmetry(double a, double b)
{
    Matrix *m1 = translation(0,-b);
    Matrix *m2 = rotationDirect(atan(a));
    Matrix *m3 = idMatrix(3);
    m3->mat[1][1]=-1;
    Matrix *m4 = rotationIndirect(atan(a));
    Matrix *m5 = translation(0,b);

    Matrix m = (*m1)*(*m2)*(*m3)*(*m4)*(*m5);

    return m;
}

Matrix Matrix::centralSymmetry(double a, double b)
{

    Matrix *m1 = translation(-a,-b);
    //Matrix *m2 = rotationDirect(atan(a));
    //Matrix *m3 = translation(a,b);
    //Matrix m = (*m1)*(*m2)*(*m3);

    return *m1;
}

void Matrix::print()
{
    cout << endl;
    for(int i=0; i<this->m;i++){
        cout <<" | ";
        for(int j=0 ; j <this->n;j++) {
            cout << this->mat[i][j] << " | ";
        }
        cout <<endl;
    }
}

vector<Point> Matrix::getPoints(){
    vector<Point> points;
    for(int j=0; j<n;j++){
        points.push_back(Point(mat[0][j],mat[1][j]));
    }
    return points;
}

Matrix Matrix::operator* (const Matrix& matrix)
{
    if(this->n!= matrix.m){
        throw new domain_error("Error with operator '*' : Nb col first Matrix != Nb line second Matrix ("+to_string(this->m)+","+to_string(this->n)+") *" +"("+to_string(matrix.m)+","+to_string(matrix.n)+")");
    }
    Matrix *mul = new Matrix(this->m,matrix.n);

    for(int i=0; i<this->m; ++i) {
        for(int j=0; j<matrix.n; ++j) {
            for(int k=0; k<this->n; ++k)
            {
                mul->mat[i][j]+=this->mat[i][k]*matrix.mat[k][j];
            }
        }
    }
    return *mul;
}


Matrix& Matrix::operator= (const Matrix& matrix)
{
    this->m=matrix.m;
    this->n = matrix.n;
    this->mat.resize(m);
    for(int i = 0 ; i < m ; ++i)
    {
        mat[i].resize(n);
        for(int j=0;j<n;j++){
            this->mat[i][j] = matrix.mat[i][j];
        }
    }

    return (*this);
}
/*
Matrix& Matrix::operator= (const Matrix& mat)
{
    memcpy(this->m, mat.m, sizeof(double)*9);
    return (*this);
}

Matrix Matrix::operator* (const Matrix& mat)
{
    Matrix mul = Matrix();
    
    //First row
    mul.m[0] = this->m[0] * mat.m[0] + this->m[3] * mat.m[1] + this->m[6] * mat.m[2];
    mul.m[3] = this->m[0] * mat.m[3] + this->m[3] * mat.m[4] + this->m[6] * mat.m[5];
    mul.m[6] = this->m[0] * mat.m[6] + this->m[3] * mat.m[7] + this->m[6] * mat.m[8];

    //Second row
    mul.m[1] = this->m[1] * mat.m[0] + this->m[4] * mat.m[1] + this->m[7] * mat.m[2];
    mul.m[4] = this->m[1] * mat.m[3] + this->m[4] * mat.m[4] + this->m[7] * mat.m[5];
    mul.m[7] = this->m[1] * mat.m[6] + this->m[4] * mat.m[7] + this->m[7] * mat.m[8];

    //Third row
    mul.m[2] = this->m[2] * mat.m[0] + this->m[5] * mat.m[1] + this->m[8] * mat.m[2];
    mul.m[5] = this->m[2] * mat.m[3] + this->m[5] * mat.m[4] + this->m[8] * mat.m[5];
    mul.m[8] = this->m[2] * mat.m[6] + this->m[5] * mat.m[7] + this->m[8] * mat.m[8];

    return mul;
}

Matrix& Matrix::operator*= (const Matrix& mat)
{
    Matrix tmp(*this);
    
    //First row
    this->m[0] = tmp.m[0] * mat.m[0] + tmp.m[3] * mat.m[1] + tmp.m[6] * mat.m[2];
    this->m[3] = tmp.m[0] * mat.m[3] + tmp.m[3] * mat.m[4] + tmp.m[6] * mat.m[5];
    this->m[6] = tmp.m[0] * mat.m[6] + tmp.m[3] * mat.m[7] + tmp.m[6] * mat.m[8];

    //Second row
    this->m[1] = tmp.m[1] * mat.m[0] + tmp.m[4] * mat.m[1] + tmp.m[7] * mat.m[2];
    this->m[4] = tmp.m[1] * mat.m[3] + tmp.m[4] * mat.m[4] + tmp.m[7] * mat.m[5];
    this->m[7] = tmp.m[1] * mat.m[6] + tmp.m[4] * mat.m[7] + tmp.m[7] * mat.m[8];

    //Third row
    this->m[2] = tmp.m[2] * mat.m[0] + tmp.m[5] * mat.m[1] + tmp.m[8] * mat.m[2];
    this->m[5] = tmp.m[2] * mat.m[3] + tmp.m[5] * mat.m[4] + tmp.m[8] * mat.m[5];
    this->m[8] = tmp.m[2] * mat.m[6] + tmp.m[5] * mat.m[7] + tmp.m[8] * mat.m[8];

    return (*this);
}



Matrix::operator double*()
{
    double* tmp = new double[9];
    memcpy(tmp, this->m, sizeof(double) * 8);
    return tmp;
}

Matrix::operator float*()
{
    float* tmp = new float[9];
    for(int i = 0; i < 9; i++)
    {

        tmp[i] = (float)this->m[i];
    }
    return tmp;
}

*/
