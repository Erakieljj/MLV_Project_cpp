#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__
#include "point.h"
#include<vector>

////Attention : matrice en colomn major dans son implémentation
class Matrix
{
    private:
        vector< vector<double> > mat;
        int m; //number of line
        int n; //number of col

    public:
        //Liste des constructeurs :
        /**
         * @brief Matrix Constructeur par défaut.
         */
        Matrix();
        /**
         * @brief Matrix Constructeur définissant le nombre de ligne et colonne de la matrice.
         * @param m Nombre de ligne.
         * @param n Nombre de colonne.
         */
        Matrix(double m , double n);
        /**
         * @brief Matrix Constructeur retournant la matrice de representation de tous les points.
         * @param points vecteur de Point.
        */
        Matrix(vector<Point> points);

        //Matrix(const Matrix& mat);

        /**
         * @brief idMatrix Matrice identité.
         * @param n nombre de colonnes et lignes.
         * @return Retourne la construction de la matrice identité.
         */
        static Matrix* idMatrix(double n);

        //Liste des Fonctions statiques, ici factory method
        /**
         * @brief translation Effectue l'opération de translation sur la matrice.
         * @param x Valeur en abcisse de x.
         * @param y Valeur en ordonné de y.
         * @return
         */
        static Matrix* translation(double x, double y);
        /**
         * @brief rotationDirect Effectue l'opération de rotation directe sur la matrice.
         * @param alpha Angle de rotation directe.
         * @return retourne la matrice de rotation directe.
         */
        static Matrix* rotationDirect(double alpha);
        /**
         * @brief rotationIndirect Effectue l'opération de rotation indirecte sur la matrice.
         * @param alpha Angle de rotation indirecte.
         * @return Retourne la matrice de rotation indirecte.
         */
        static Matrix* rotationIndirect(double alpha);
        /**
         * @brief homothety Effectue l'opération d'homothétie sur la matrice.
         * @param x Valeur en abcisse de x.
         * @param y Valeur en ordonné de y.
         * @return Retourne la matrice d'homothétie.
         */
        static Matrix* homothety(double x, double y);

        /**
         * @brief axialSymmetry
         * @param a Valeur en abcisse de x.
         * @param b Valeur en ordonné de y.
         * @return Retourne la matrice de symétrie axiale.
         */
        static Matrix axialSymmetry(double a, double b);
        /**
         * @brief centralSymmetry
         * @param a Valeur en abcisse de x.
         * @param b Valeur en ordonné de y.
         * @return Retourne la matrice de symétrie centrale.
         */
        static Matrix* centralSymmetry(double a, double b);

        /**
         * @brief Affichage de la matrice.
         */
        void print();

        // Surcharges d'opérateur pour la classe Matrix
        /**
         * @brief operator * Produit de deux matrices.
         * @param mat Matrice avec laquelle on veut réaliser l'opération de produit.
         * @return Retourne le résultat du produit des deux matrices (matriceResultat = mat1 * mat).
         */
        Matrix operator*(const Matrix &mat);
        /**
         * @brief operator = Fonction d'affectation d'une matrice.
         * @param mat Matrice à affecter.
         * @return Retourne le résultat de l'affectation (matrice1 = matrice2).
         */
        Matrix& operator= (const Matrix & mat);
        /**
         * @brief getPoints Obtient la liste des points.
         * @return Retourne la liste des points sous le format "vector<Points>".
         */
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
