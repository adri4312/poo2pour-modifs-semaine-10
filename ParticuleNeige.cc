#include "ParticuleNeige.h"
#include "ParticuleRoche.h"
#include "Particule.h"
#include <iostream>
class Obstacle;
using namespace std;



 // fonction Type particuleNeige
unique_ptr<Particule>  ParticuleNeige:: type() const{
	return std :: make_unique<ParticuleNeige>(*this);
 }
// ajouteForce pour neige
  void ParticuleNeige :: ajouteForce(Agent& autre)  { autre.opere_sur(*this); }
//Constructeur ParticuleNeige
ParticuleNeige :: ParticuleNeige(Vecteur3D pst,Vecteur3D vts, double m_vo, double ry)
: Particule(pst,vts,m_vo,ry){}
//méthode dessine_sur
void ParticuleNeige ::dessine_sur(SupportADessin& support) const 
  { support.dessine(*this); }
 
 
 // méthode opère sur Particule neige sur ParticuleNeige
 void ParticuleNeige:: opere_sur(ParticuleNeige& p){
	 Vecteur3D e = p.getPosition() - position;
    double d = e.norme();
    if (d == 0.0) return;
    force += (~e) * forceLJ(d);
    }
  //méthode opère sur Particule neige sur Obstacle
  void ParticuleNeige :: opere_sur( Obstacle& O){}
// méthode opère sur Particule neige sur ParticuleRoche
	void ParticuleNeige:: opere_sur(ParticuleRoche& p){
	 Vecteur3D e = p.getPosition() - position;
    double d = e.norme();
    if (d == 0.0) return;
    force += (~e) * forceLJ(2*d);
    }
