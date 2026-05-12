#pragma once
#include "constantes.h"
#include "Agent.h"   
#include <memory>
#include "Dessinable.h"

class Obstacle;




class Particule : public Dessinable, public Agent {
protected : 
	Vecteur3D position;
	Vecteur3D vitesse;
	double m_v;
	double rayon;
	Vecteur3D force; 
public :
	// methode dacces 
	const Vecteur3D& getPosition() const { return position; }
    const Vecteur3D& getVitesse() const { return vitesse; }
    const Vecteur3D& getForce() const { return force;} 
    double getRayon() const { return rayon; }
    void setRayon(double r) {rayon = r;}
    void setVitesse(Vecteur3D v) {vitesse = v;}
    void setPosition(Vecteur3D p) {position = p;}
    
    //constantes
	static double epsilon;
	static double sigma; 
	double forceLJ(double x); 

	//constructeurs 
	Particule();
	Particule(Vecteur3D pst,Vecteur3D vts, double m_vo, double ry);
	//destructeur
	virtual ~Particule() = default;
	
	//methodes caracteristiques de la classe Particule, n.b: on a fixe le milieu "air" pour lambda 
	Vecteur3D lambda(double r, double e) const;
	double masse() const;
	void bouger(double pas_de_temps);

	
	//dessin
	virtual void dessine_sur(SupportADessin& support) const override;
	//particule par défaut pour constructeur par défaut de source
	
	// méthode ajouteForce
	virtual void ajouteForce(Agent& autre) =0;
	// méthode permettant d'ajouter un vecteur à la force:
	void ajouteForceVecteur(const Vecteur3D& f) { force += f; };
	//méthode ajouteForce qui dépend du milieu
	void ajouteForceMilieu (double r, double e);
	
	//méthode permettant de créer un unique_ptr sur une particule du type choisi
	virtual std :: unique_ptr<Particule> type() const =0;
	
	
	

};
//affichage
std::ostream& operator<<(std::ostream& os, const Particule& p);

 


