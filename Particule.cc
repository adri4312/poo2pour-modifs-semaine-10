#include "Particule.h"
#include "obstacle.h"
#include <iostream>


using namespace std;



double f(double x) {
	if (x <= 1) {return -1;}
	if (x >= 2) {return 0;}
	return (pow(x, 6) - 2)/pow(x,13);};
// constructeurs
Particule::Particule() : position(0,0,0), vitesse(0,0,0), m_v(1), rayon(1) {};

Particule::Particule(Vecteur3D pst,Vecteur3D vts,double m_vo, double ry ) : position(pst), vitesse(vts) {
	/*while (m_vo <= 0.0 or ry <= 0) {
		cin >> ry ;
		cin >> m_vo ;
	}*/
	m_v = m_vo; 
	rayon = ry;
}; 
// methodes specifiques
Vecteur3D Particule::lambda(double r, double e) const{
	double v = vitesse.norme();
	if (v == 0.0) return Vecteur3D(0.0, 0.0, 0.0);
	double s((80.0 *e ) / (3.0 * r * rayon));
	double lambda1;
	if (v <= s) {lambda1 = 6.0 * phy::pi * rayon * e ;}
	else {lambda1 = (9.0 * phy::pi / 40.0) * rayon * rayon * r * v;};
	return -vitesse * lambda1;
};

double Particule::masse() const {
	return (4.0/3.0) * phy::pi * m_v * pow(rayon, 3);
};

/*//forces élémentaires
void Particule::ajouteForce(Vecteur3D vecteur) { force += vecteur; }
// force entre deux particules
void Particule::ajouteForce(Particule const& p) {
	Vecteur3D e = p.position - position;
    double d = e.norme();
    if (d == 0.0) return;
    force += (~e) * forceLJ(d);
};
//forces pour la methode d'euler
void Particule::ajouteForce(double r, double e) {force += lambda(r, e) + phy::g * masse();};
*/
void Particule::bouger(double dt) {
	vitesse += force * (dt/masse());
	position += vitesse * dt;
	force = Vecteur3D(0,0,0);
	
	};
/*//force dûe aux obstacles
void Particule::ajouteForce(Obstacle const& O){
	Vecteur3D PointProche(O.PointPlusProche(position));
	Vecteur3D e = position - PointProche;
	double d = e.norme(); 
	if (d == 0.0) return ;
	force += (~e) * (2 * forceLJ(d));
	};
*/

//forces pour la methode d'euler
void Particule::ajouteForceMilieu(double r, double e) {force += lambda(r, e) + phy::g * masse();};

double Particule::forceLJ(double x) {
	return ((24*epsilon)/pow(sigma, 2))*f(x/sigma);
};


// operateur affichage
ostream& operator<<(ostream& regard, const Particule& p) {
	regard << "[ position = " << p.getPosition() << ", "
	       << "v = " << p.getVitesse() << ", "
	       << "m = "<< p.masse() << ", "
	       << "r =" << p.getRayon() << " ]"; 
	return regard;
};
// constantes
double Particule::epsilon = 25 ;
double Particule::sigma = 0.885;
// méthode pour le dessin
void Particule ::dessine_sur(SupportADessin& support) const 
  { support.dessine(*this); }
	   
	   
	   
	   
	   
