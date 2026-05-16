# include <iostream>
#include "Particule.h"
#include "obstacle.h"
#include "SupportADessin.h"
#include "ParticuleNeige.h"
#include "ParticuleRoche.h"




using namespace std;
	
	
	
	
	// constructeur d'obstacle
		Obstacle ::Obstacle(Vecteur3D O_)
		:O(O_)
		{}
	// constructeur par défaut d'obstacle
	Obstacle :: Obstacle ()
	: O(0,0,0){}
	
	//méthodes donnant accès aux coordonnées de def d'un obstacle
	Vecteur3D Obstacle :: get_O() const{return O;}
	
	//dessinable obstacle
	void Obstacle :: dessine_sur(SupportADessin& support) const
	{ support.dessine(*this); }
	
	// affichage de l'obstacle 
	ostream& operator<<(ostream& os, const Obstacle& o) {
		os << " position de l'obstacle = " << o.get_O() << endl;
		return os;
	};
	
	
	
	
	// Pour Plan
void Plan::opere_sur(ParticuleNeige& p) { 
    Vecteur3D e = p.getPosition() - PointPlusProche(p.getPosition());
    double d = e.norme(); 
    if (d == 0.0) return;
    p.ajouteForce((~e) * (2 * p.forceLJ(d)));
}

void Plan::opere_sur(ParticuleRoche& p) {
    Vecteur3D e = p.getPosition() - PointPlusProche(p.getPosition());
    double d = e.norme(); 
    if (d == 0.0) return;
    p.ajouteForce((~e) * (1.2 * p.forceLJ(d)));
}

void Plan::opere_sur(Obstacle& o) {} 

// Pour Dalle (on peut souvent appeler la version de Plan si le code est identique)
void Dalle::opere_sur(ParticuleNeige& p) { Plan::opere_sur(p); }
void Dalle::opere_sur(ParticuleRoche& p) { Plan::opere_sur(p); }
void Dalle::opere_sur(Obstacle& o)       {}
	
	//méthode permettant de trouver le vecteur le plus proche de l'instance
	Vecteur3D Plan:: PointPlusProche(Vecteur3D const& x_i) const{
		Vecteur3D v;
		v= x_i + ( ( O-x_i ) * ~n ) * ~n;
		return v;
	};
	
	// Constructeur de plan
	 Plan :: Plan (Vecteur3D O_, Vecteur3D n_)
	 : Obstacle(O_),n(n_)
	 {}
	
	//Constructeur par défaut de plan
	Plan :: Plan ()
	:Obstacle(), n(1,0,0)
	{}
	
	//méthodes donnant accès aux coordonnées de def du plan

	Vecteur3D Plan :: get_n() const{return ~n;}
	
	//dessinable plan
	void Plan :: dessine_sur(SupportADessin& support) const
	{support.dessine(*this); }
	
		// affichage du plan 
	ostream& operator<<(ostream& os, const Plan& o) {
		os << " Plan d'origine " << o.get_O() << " et de normale" << o.get_n()<<endl;
		return os;
	};
/*	
	// fonctions héritées de Agent
	 void Plan :: opere_sur(ParticuleNeige& p) { 
	Vecteur3D e = p.getPosition() - PointPlusProche(p.getPosition());
	double d = e.norme(); 
	if (d == 0.0) return ;
	p.ajouteForceVecteur ((~e) * (2 * p.forceLJ(d)));
	}
	 
	void Plan :: opere_sur(Obstacle& O) {}
	 
	void Plan :: opere_sur(ParticuleRoche& p) {
	Vecteur3D e = p.getPosition() - PointPlusProche(p.getPosition());
	double d = e.norme(); 
	if (d == 0.0) return ;
	p.ajouteForceVecteur ((~e) * (1.2 * p.forceLJ(d)));

}
	
	
	
	
	
	
	
	// fonctions héritées de Agent pour Dalle
	 void Dalle :: opere_sur(ParticuleNeige& p) { 
	Vecteur3D e = p.getPosition() - PointPlusProche(p.getPosition());
	double d = e.norme(); 
	if (d == 0.0) return ;
	p.ajouteForceVecteur ((~e) * (2 * p.forceLJ(d)));
	}
	 
	void Dalle :: opere_sur(Obstacle& O) {}
	 
	void Dalle :: opere_sur(ParticuleRoche& p) {
	Vecteur3D e = p.getPosition() - PointPlusProche(p.getPosition());
	double d = e.norme(); 
	if (d == 0.0) return ;
	p.ajouteForceVecteur ((~e) * (1.2 * p.forceLJ(d)));
}
	
*/

//Constructeur de Dalle
	Dalle :: Dalle (double L_, double l_, Vecteur3D O_, Vecteur3D n_, Vecteur3D vl_, Vecteur3D vL_)
	: Plan(O_,n_), L(L_),l(l_), vl(vl_), vL(vL_){}

//getters
double Dalle :: get_L() const {return L;}
double Dalle :: get_l()const {return l;}

//Constructeur par défaut de Dalle
		Dalle :: Dalle()
		: Plan(), L(1), l(1), vl(0,1,0), vL(0,0,1){}
	
//redéfinition de la méthode pour trouver le vecteur le plus proche dans une dalle
	Vecteur3D Dalle :: PointPlusProche(Vecteur3D const& x_i) const{
	Vecteur3D v;
	v= x_i+((O-x_i)*n)*n;
	double XkL;
	double Xkl;
	XkL =(v-O)*~vL;
	Xkl=(v-O)*~vl;
	if (XkL > L){
		v=v-(XkL-L)*~vL;
	}else{
		v=v-XkL*~vL;
	}
	if (Xkl> l){
		v=v-(Xkl-l)*~vl;
	}else{
		v=v-Xkl*~vl;
	}
	return v;
}

	//dessinable dalle
	void Dalle :: dessine_sur(SupportADessin& support) const
	{support.dessine(*this); }
	
		// affichage de la dalle 
	ostream& operator<<(ostream& os, const Dalle& o) {
		os << " Dalle d'origine, " << o.get_O() << "de normale "<< o.get_n() <<"de longueur "<< o.get_L()<< "et de largeur"<< o.get_l()<< endl;
		return os;
	};
	
	


