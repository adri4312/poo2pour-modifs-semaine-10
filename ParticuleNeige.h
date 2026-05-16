#pragma once
#include <memory>
#include "Particule.h"
class Obstacle;
class ParticuleRoche;
class Agent;
class SupportADessin;


class ParticuleNeige : public Particule {
	public : 
	using Particule::ajouteForce; 
	//Constructeurs
	ParticuleNeige(Vecteur3D pst,Vecteur3D vts, double m_vo, double ry);
	ParticuleNeige():Particule(){}
	// redéfinition ajouteForce
	virtual void ajouteForce(Agent& autre) override ;
	//dessin
	virtual void dessine_sur(SupportADessin& support) const override;
	// redéfinition opere_sur une PArticuleNeige
	virtual void opere_sur(ParticuleNeige& p) override;
	virtual void opere_sur(Obstacle& O) override;
	virtual void opere_sur(ParticuleRoche& p) override;
	//redéfinition fonction type
	virtual std :: unique_ptr<Particule> type() const override;
};
