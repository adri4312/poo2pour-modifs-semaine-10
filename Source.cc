#include "Source.h"
#include <iostream>
#include "SupportADessin.h"
using namespace std;
void Source::creation(vector<unique_ptr<Particule>>& particules, double dt)
{
    if (!etat) return;

    double fraction = debit * dt;
    int nombre = int(fraction);
    fraction -= nombre;

    if (generateur.uniforme(0.0, 1.0) < fraction)
        ++nombre;

    for (int i = 0; i < nombre; ++i) {
		
		//auto permet d'aller assigner le type réel donné par la fonction type à l'objet p
        auto p = modele->type();

        double vx = generateur.gaussienne(v_m_i.get_x(), e_v);
        double vy = generateur.gaussienne(v_m_i.get_y(), e_v);
        double vz = generateur.gaussienne(v_m_i.get_z(), e_v);

        p->setVitesse(Vecteur3D(vx, vy, vz));

        double r = generateur.gaussienne(modele->getRayon(), e_r);
        p->setRayon(r);

        particules.push_back(move(p));
    };
};


 
	 void Source :: dessine_sur(SupportADessin& support) const
		{support.dessine(*this); };
		
std::ostream& operator<<(std::ostream& regard, Source const& s) {
	return regard << "(Position de la source : " << s.getpos() << ") ;" << "Débit : " << s.getDeb() << "; Modèle :" << s.getPar() ;
	};
