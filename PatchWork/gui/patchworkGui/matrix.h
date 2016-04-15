#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__
#include "point.h"
#include<vector>

//Classe Matrix : représente une matrice 3x3
////Attention : matrice en colomn major dans son implémentation
class Matrix
{
    private:
        vector< vector<double> > mat;
        int m; //number of line
        int n; //number of col

    public:
        //Liste des constructeurs :
        ///
        /// \brief Default constructor
        ///
        Matrix();
        ///
        /// \brief Matrix (m,n)
        ///
        Matrix(double m , double n);

        ///
        /// \brief Return a Matrix representation of all Point
        /// \param points - vector of Point
        ///
        Matrix(vector<Point> points);

        ///
        /// \brief Matrix Copy function
        /// \param mat
        ///
        //Matrix(const Matrix& mat);

        ///
        /// \brief idMatrix the Identity Matrix
        /// \param n (number of col and line)
        /// \return the Identity Matrix
        ///
        static Matrix* idMatrix(double n);

        //Liste des Fonctions statiques, ici factory method
        ///
        /// \brief Return the translation matrix
        /// \param x
        /// \param y
        /// \return Return the translation matrix
        ///
        static Matrix* translation(double x, double y);

        ///
        /// \brief Return the direct rotation matrix
        /// \param alpha
        /// \return return the rotation matrix
        ///
        static Matrix* rotationDirect(double alpha);

        static Matrix rotationCentral(double alpha,double x,double y);

        ///
        /// \brief Return the indirect rotation matrix
        /// \param alpha
        /// \return return the rotation matrix
        ///
        static Matrix* rotationIndirect(double alpha);

        ///
        /// \brief Return the homothety matrix
        /// \param x
        /// \param y
        /// \return Return the homothety matrix
        ///
        static Matrix* homothety(double x, double y);

        ///
        /// \brief Return the axial symmetry matrix for y = ax+b
        /// \param a
        /// \param b
        /// \return
        ///
        static Matrix axialSymmetry(double a,double b);

        ///
        /// \brief Return the axial central matrix for y = ax+b
        /// \param a
        /// \param b
        /// \return
        ///
        static Matrix centralSymmetry(double a,double b);

        void print();

        /// Product of two matrix
        /// \brief operator *
        /// \param matrix
        /// \return
        ///
        Matrix operator*(const Matrix &matrix);

        ///
        /// \brief affectation function of matrix
        /// \param mat
        /// \return
        ///
        Matrix& operator= (const Matrix & mat);

        vector<Point> getPoints();
        /*

        //Liste des fonctions de manipulation de la matrice courante
        ///Retourne la transposée de la matrice
        //Matrix transpose();


        //Liste des fonctions de surcharge d'opérateur
        ///opérateur d'affectation
        Matrix& operator= (const Matrix & mat);
        ///Produit matriciel
        Matrix operator*(const Matrix &mat);
        //Vector operator*(Vector& v);
        Matrix& operator*= (const Matrix &mat);

        ///Opérateur de cast
        //operator double*();
        //operator float*();

        */
};

#endif
