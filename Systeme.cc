# include "Systeme.h"
#include "Particule.h"
#include "obstacle.h"
#include "Source.h"

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
     for (auto& s : SO) {
        s->creation(PA, dt);
    }

    double dt2 = 0.01;


		 while (dt > 1e-10) {
	
	        for (auto& p : PA) {
            p->ajouteForce(r, e);
        };};
		// tableau d'agents
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
        };
        
        //optimisation des interactions entre obstacles et particules 
		for (auto& p : PA) {
           for (auto const& ob : OB) {
                Vecteur3D pointProche = ob->PointPlusProche(p->getPosition());
                Vecteur3D dist = p->getPosition() - pointProche;
               if (dist.norme() < p->getRayon()) {
                    // Collision : repositionne et amortit la vitesse jusqu'à ce que la vitesse s'annule
                    Vecteur3D vitess_ = p->getVitesse();
                    while (vitess_.norme() > 1e-30) {
						p->setPosition(pointProche + (~dist) * p->getRayon());
						p->setVitesse(vitess_ * 0.7); 
						vitess_ = p->getVitesse();
					p->setVitesse(Vecteur3D(0,0,0));
                    }
                }
            }
		};
        //  Mouvement
        for (auto& p : PA) {
            p->bouger(dt2);
        }

        dt -= dt2;
    };

// fonction affiche
void Systeme::dessine_sur(SupportADessin& support) const{
	support.dessine(*this);
}
// opérateur d'affichage
ostream& operator<<(ostream& os, Systeme const& s) {
	const  auto& s_ = s.getParticules();  
	const auto& o_ = s.getObstacles();  
	const auto& so_ = s.getSources();  
	os << "Le systeme est composé des " << s_.size() << "particules suivantes :" <<endl;
	for (auto const& p : s_)
	{
		os << *p;
	};
	os << "et des " << o_.size() << " obstacles suivants" << endl;
	for (auto const& o : o_)
	{
		os << *o;
	};
	os <<"et des " << so_.size() <<" sources suivantes"<<endl;
	for (auto const& s : so_)
	{
		os << *s;
	};
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
