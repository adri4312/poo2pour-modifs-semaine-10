#pragma once
#include "constantes.h"

#include <memory>

#include "Particule.h"
class ParticuleNeige;
class Agent;
class Obstacle;
class SupportADessin;


class ParticuleRoche : public Particule {
	public:
	//Constructeurs
	ParticuleRoche(Vecteur3D pst,Vecteur3D vts, double m_vo, double ry);
	ParticuleRoche();
	// redéfinition ajouteForce
	virtual void ajouteForce(Agent& autre) override ;
	//dessin
	virtual void dessine_sur(SupportADessin& support) const override;
	// redéfinition opere_sur une ParticuleRoche
	virtual void opere_sur(ParticuleRoche& p) override;
	virtual void opere_sur(Obstacle& O) override;
	virtual void opere_sur(ParticuleNeige& p) override;
	//redéfinition fonction type
	virtual std :: unique_ptr<Particule> type() const override;
};



// Différence entre nouvelle et ancinnne version du code, regarder le constructeur , fonction type, autres différences
