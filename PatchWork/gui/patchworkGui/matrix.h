#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__
#include "point.h"
#include<vector>

/**
 * @brief Matrix Représente une matrice.
 */
////Attention : matrice en colomn major dans son implémentation
class Matrix
{
    private:
        /**
         * @brief mat la matrice.
         */
        vector< vector<double> > mat;
        /**
         * @brief m nombre de lignes.
         */
        int m;
        /**
         * @brief n nombre de colonnes.
         */
        int n;

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
         * @brief rotationCentral Effectue l'opération de rotation centrale sur la matrice.
         * @param alpha Angle de rotation en radiant.
         * @param x abscisse du centre de rotation.
         * @param y ordonnée du centre de rotation.
         * @return Retourne la matrice de rotation Central.
         */
        static Matrix rotationCentral(double alpha,double x,double y);

        /**
         * @brief rotationIndirect Effectue l'opération de rotation indirecte sur la matrice.
         * @param alpha Angle de rotation indirecte.
         * @return Retourne la matrice de rotation indirecte.
         */
        static Matrix* rotationIndirect(double alpha);

        /**
         * @brief axialSymmetry Effectue l'opération de symétrie axiale sur la matrice.
         * @param a Valeur en abcisse de x.
         * @param b Valeur en ordonné de y.
         * @return Retourne la matrice de symétrie axiale.
         */
        static Matrix* homothety(double x, double y);

        /**
         * @brief axialSymmetry Effectue l'opération de symétrie axiale sur la matrice.
         * @param a Valeur en abcisse de x.
         * @param b Valeur en ordonné de y.
         * @return Retourne la matrice de symétrie axiale.
         */
        static Matrix axialSymmetry(double a,double b);

        /**
         * @brief centralSymmetry Effectue l'opération de symétrie centrale sur la matrice.
         * @param a Valeur en abcisse de x.
         * @param b Valeur en ordonné de y.
         * @return Retourne la matrice de symétrie centrale.
         */
        static Matrix centralSymmetry(double a,double b);

        /**
         * @brief print Affiche la matrice dans le terminal.
         */
        void print();

        /**
         * @brief operator * Produit de deux matrices.
         * @param mat Matrice avec laquelle on veut réaliser l'opération de produit.
         * @return Retourne le résultat du produit des deux matrices (matriceResultat = mat1 * mat).
         */
        Matrix operator*(const Matrix &matrix);

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

};

#endif
