#pragma once
#include <ostream>
#include <array>
#include <cmath> 
class Vecteur3D {

private:

std::array<double,3> coord;

public:
//declaration des constructeurs
Vecteur3D ();
Vecteur3D (double x, double y, double z);

//methode d'obtention pour coordonnees 
double get_x() const {return coord[0];}
double get_y() const{return coord[1];}
double get_z() const {return coord[2];}

//surcharge pour operations algebriques elementaires
void operator -=(Vecteur3D const& autre){
	for (size_t i (0); i<3; ++i){
		coord[i]-=autre.coord[i];
	}
}

void operator +=(Vecteur3D const& autre){
	for (size_t i (0); i<3; ++i){
		coord[i]+=autre.coord[i];
	}
}

double norme ()const{
	return sqrt(coord[0]*coord[0]+coord[1]*coord[1]+coord[2]*coord[2]);
}
double norme2()const{
	return coord[0]*coord[0]+coord[1]*coord[1]+coord[2]*coord[2];
}
//surcharge pour multiplier un scalaire avec un vecteur
Vecteur3D& operator*=(double s);
Vecteur3D operator-() const;
//surcharge pour comparer deux vecteurs
bool operator==(Vecteur3D const& v) const;
bool operator!=(Vecteur3D const& v)const;
// normalisation
Vecteur3D operator~() const{
	Vecteur3D v; 
	double n= norme();
	for (size_t i (0); i<3; ++i){
		v.coord[i]=coord[i]/n;
	}
	return v;
};


};
//surcharge externe
double operator*(Vecteur3D const& a, Vecteur3D const& b);
Vecteur3D operator^(Vecteur3D const& v1, Vecteur3D const& v2);
Vecteur3D operator-(Vecteur3D v1, Vecteur3D const& v2);
Vecteur3D operator+(Vecteur3D v1, Vecteur3D const& v2);
Vecteur3D operator*(double s, Vecteur3D const& v) ;
Vecteur3D operator*(Vecteur3D const& v, double s);

//declaration pour affichage
std::ostream& operator<<(std::ostream& sortie, Vecteur3D const& v);
