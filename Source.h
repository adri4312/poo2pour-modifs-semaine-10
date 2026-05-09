
#pragma once
#include "ParticuleNeige.h"
#include "Particule.h"
#include <memory>
#include <vector>
#include "Aleatoire.h"
class Source : public Dessinable, public Agent{
	private :
	std :: unique_ptr<Particule> modele;
	Vecteur3D position;
	Vecteur3D v_m_i;
	double e_v;
	double e_r;
	double debit;
	Aleatoire generateur;
	bool etat = true;
	std::unique_ptr<ParticuleNeige> ma_neige = std:: make_unique<ParticuleNeige>();
	public :
	// Constructeurs
	Source(std :: unique_ptr<Particule> p, Vecteur3D pos, Vecteur3D v_moy, double sigma_v, double sigma_r, double debit) : modele(std::move(p)), position(pos), v_m_i(v_moy), e_v(sigma_v), e_r(sigma_r), debit(debit){};
	Source(): modele(std :: move(ma_neige)), position(0,0,0), v_m_i(0,0,0), e_v(0), e_r(0), debit(0){};
	//accesseurs 
	const Vecteur3D& getpos() const {return position;}
	const Particule& getPar() const {return *modele;}
	double getDeb() const {return debit;}
	bool estActive() const {return etat; }
	//methodes
	void on() {etat = true;}
	void off() {etat = false;}
	void creation(std::vector<std::unique_ptr<Particule>>& particules, double dt);
	void dessine_sur(SupportADessin& support) const;
	};

std::ostream& operator<<(std::ostream& regard, Source const& s);

