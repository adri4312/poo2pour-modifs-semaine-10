# include "Systeme.h"
#include "Particule.h"
#include "Obstacle.h"
#include "Source.h"
#include "TextViewer.h"
using namespace std;



// Constructeur 
Systeme :: Systeme (ensemble_d_obstacles a, ensemble_de_particules b, ensemble_de_sources c)
: OB(std :: move(a)), PA(std :: move(b)), SO(std :: move(c)){}

//Constructeur par défaut 
Systeme :: Systeme()
: OB(ensemble_d_obstacles ()), PA(ensemble_de_particules ()), SO(ensemble_de_sources ()){}
// Constructeur sans obstacle et sans sources

Systeme :: Systeme (ensemble_de_particules b)
: PA(std :: move(b)){}

// Constructeur sans sources
Systeme :: Systeme (ensemble_d_obstacles a, ensemble_de_particules b)
: OB( std :: move(a)), PA ( std:: move(b)){}
// Constructeur sans obstacle
Systeme :: Systeme (ensemble_de_particules b, ensemble_de_sources c)
: PA (std :: move(b)), SO ( std :: move(c)){}
// ajout particule
void Systeme :: ajout_particule (unique_ptr<Particule> p){
	PA.push_back(move(p));
}

// ajout Obstacle
void Systeme :: ajout_obstacle (unique_ptr<Obstacle> o){
	OB.push_back(move(o));
}

// ajout source
void Systeme :: ajout_source (unique_ptr<Source> s){
	SO.push_back(move(s));
}
//evolution du systeme
void Systeme::evolue(double dt) {

    double r = phy::rho_air;
    double e = phy::eta_air;

    if (mi == eau) {
        r = phy::rho_eau;
        e = phy::eta_eau;
    }

    double dt2 = 0.01;

    while (dt > 1e-10) {
	
	
	//initialisation d'un tableau d'agents
	vector<Agent*> agents;
	      
        for (auto& ob : OB) agents.push_back(ob.get());
        
        for (auto& p : PA) agents.push_back(p.get());
        
        for (auto& s : SO) agents.push_back(s.get());
        
        for (auto& p : PA){
        	for (auto& a : agents){
        		if (p.get()!=a){
        		p->ajouteForce(*a);
        		}
        	}
        }
        
        
        

        //  Mouvement
        for (auto& p : PA) {
            p->bouger(dt2);
        }

        dt -= dt2;
    }
}
// fonction affiche
void Systeme::dessine_sur(SupportADessin& support) const{
	cout << "Le systeme est composé des " << PA.size() << "particules suivantes :" <<endl;
	for (auto const& p : PA)
	{
		p->dessine_sur(support);
	};
	cout << "et des " << OB.size() << " obstacles suivants" << endl;
	for (auto const& o : OB)
	{
		o->dessine_sur(support);
	};
	cout<<"et des " << SO.size() <<" sources suivantes"<<endl;
	for (auto const& s : SO)
	{
		s->dessine_sur(support);
	};
}
// opérateur d'affichage
ostream& operator<<(ostream& os, Systeme const& s) {
	TextViewer T(os);
	s.dessine_sur(T);
	return os;
	}
// affichage eau ou air 
ostream& operator<<(ostream& os, milieu m) {
    if (m == air) {
        os << "air";
    } else if (m == eau) {
        os << "eau";
    }
    return os;
};
