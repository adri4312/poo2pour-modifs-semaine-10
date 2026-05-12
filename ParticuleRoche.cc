#include "ParticuleRoche.h"
#include "ParticuleNeige.h"
#include "obstacle.h"
#include <memory>

// Constructeurs
ParticuleRoche::ParticuleRoche() 
    : Particule() {}

ParticuleRoche::ParticuleRoche(Vecteur3D pst, Vecteur3D vts, double m_vo, double ry)
    : Particule(pst, vts, m_vo, ry) {}

// Méthode de clonage pour la Source
std::unique_ptr<Particule> ParticuleRoche::type() const {
    return std::make_unique<ParticuleRoche>(*this);
}

// Méthode pour le Visitor Pattern
void ParticuleRoche::ajouteForce (Agent& autre) {
    autre.opere_sur(*this);
}

// Méthode Agent (que fait une roche sur une autre particule ? Souvent rien de spécial ici)
void ParticuleRoche::opere_sur(ParticuleNeige& p) { 	 
	Vecteur3D e = p.getPosition() - position;
    double d = e.norme();
    if (d == 0.0) return;
    force += (~e) * forceLJ(5*d);}
void ParticuleRoche::opere_sur(ParticuleRoche& p) { 	 
Vecteur3D e = p.getPosition() - position;
    double d = e.norme();
    if (d == 0.0) return;
    force += (~e) * forceLJ(3*d); }
void ParticuleRoche::opere_sur(Obstacle& o)       { }

// Méthode de dessin
void ParticuleRoche::dessine_sur(SupportADessin& support) const {
    support.dessine(*this);
}
