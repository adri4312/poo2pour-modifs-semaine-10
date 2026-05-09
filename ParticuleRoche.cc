#include "ParticuleRoche.h"
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
void ParticuleRoche::ajouteForce(Agent& autre) {
    autre.opere_sur(*this);
}

// Méthode Agent (que fait une roche sur une autre particule ? Souvent rien de spécial ici)
void ParticuleRoche::opere_sur(ParticuleNeige& p) { (void)p; }
void ParticuleRoche::opere_sur(ParticuleRoche& p) { (void)p; }
void ParticuleRoche::opere_sur(Obstacle& o)       { (void)o; }

// Méthode de dessin
void ParticuleRoche::dessine_sur(SupportADessin& support) const {
    support.dessine(*this);
}
