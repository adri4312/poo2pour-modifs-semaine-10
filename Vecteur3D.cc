#include <iostream>
#include "Vecteur3D.h"
using namespace std;

//constructeurs par défaut
Vecteur3D::Vecteur3D (double x, double y, double z){
		coord[0]=x;
		coord[1]=y;
		coord[2]=z;
		};
Vecteur3D::Vecteur3D (){
	for (size_t i (0); i<3; ++i){
		coord[i]=0.0;
	};
};

//operateur pour etendre l'addition et la soustraction
Vecteur3D operator+(Vecteur3D v1, Vecteur3D const& v2){
Vecteur3D v_(v1.get_x()+v2.get_x(),v1.get_y()+v2.get_y(),v1.get_z()+v2.get_z());
return v_;
};
Vecteur3D operator-(Vecteur3D v1, Vecteur3D const& v2){
Vecteur3D v_(v1.get_x()-v2.get_x(),v1.get_y()-v2.get_y(),v1.get_z()-v2.get_z());
return v_;
};
// PRODUIT vectoriel
Vecteur3D operator^(Vecteur3D const& v1, Vecteur3D const& v2){
    return Vecteur3D(v1.get_y() * v2.get_z() - v1.get_z() * v2.get_y(),v1.get_z() * v2.get_x() - v1.get_x() * v2.get_z(),v1.get_x() * v2.get_y() - v1.get_y() * v2.get_x());
};
// Produit scalaire
double operator*(Vecteur3D const& a, Vecteur3D const& b){
    return a.get_x() * b.get_x()
         + a.get_y() * b.get_y()
         + a.get_z() * b.get_z();
};

// SURCHARGE INTERNE 
Vecteur3D Vecteur3D::operator-() const {
    return Vecteur3D(-get_x(), -get_y(), -get_z());
};
Vecteur3D& Vecteur3D::operator*=(double s){
	for (size_t i(0); i<3; ++i){
		coord[i] *= s;
	};
	return *this;
};
bool Vecteur3D::operator==(Vecteur3D const& v) const{
	for (size_t i (0); i<3; ++i){
		if (coord[i]!=v.coord[i]){
			return false;}
		
		}return true;}
bool Vecteur3D::operator!=(Vecteur3D const& v)const{
	return !(*this == v);
}
//multiplication EXTERNE entre scalaire et vecteur 
Vecteur3D operator*(double s, Vecteur3D const& v) {
    Vecteur3D n(v);
    n *= s;
    return n;
};
Vecteur3D operator*(Vecteur3D const& v, double s){
	return s*v; 
	};
// affichage du vecteur 
ostream& operator<<(ostream& sortie, Vecteur3D const& v){
	sortie << "("<<v.get_x()<<","<<v.get_y()<<","<<v.get_z()<<")";
	return sortie;
};





