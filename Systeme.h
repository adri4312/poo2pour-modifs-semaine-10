# pragma once

# include <vector>
#include "Dessinable.h"
# include "Source.h"
class Particule;
class Obstacle;
enum milieu {air, eau};


typedef std :: vector<std :: unique_ptr <Particule>> ensemble_de_particules;
typedef std :: vector<std :: unique_ptr <Obstacle>> ensemble_d_obstacles;
typedef std :: vector<std :: unique_ptr <Source>> ensemble_de_sources;


class Systeme : public Dessinable{
	private:
	ensemble_d_obstacles OB;
	ensemble_de_particules PA;
	ensemble_de_sources SO;
	//milieu par défaut : air
	milieu mi = air;
	
	public:
	// Constructeur 
	Systeme (ensemble_d_obstacles a, ensemble_de_particules b, ensemble_de_sources c);
	
	//Constructeur par défaut
	Systeme();
	
	// Constructeur sans obstacle et sans sources
		Systeme (ensemble_de_particules a);

	// Constructeur sans sources
		Systeme (ensemble_d_obstacles a, ensemble_de_particules b);

	// Constructeur sans obstacle
	Systeme (ensemble_de_particules b, ensemble_de_sources c);
	
	//ajout particule
	void ajout_particule(std::unique_ptr <Particule> p);
	
	//ajout obstacle
	void ajout_obstacle(std::unique_ptr<Obstacle> o);
	
	//ajout source
	void ajout_source(std::unique_ptr<Source> s);
	//choix du milieu et milieu actuel
	void setMilieu(milieu m) {this->mi = m;};
	milieu getMilieu() {return mi;} ;
	//accesseurs
	const std::vector<std::unique_ptr<Particule>>& getParticules() const {
    return PA;};
    const std::vector<std::unique_ptr<Obstacle>>& getObstacles() const  {
    return OB;};
    const std::vector<std::unique_ptr<Source>>& getSources() const  {
    return SO;};
	//evolution systeme 
	void evolue(double dt);
	//redéfinition dessine_sur
	void dessine_sur(SupportADessin& support) const override ;
	
	
};

//opérateur d'affichage
std::ostream& operator<<(std::ostream& os, Systeme const& s);
std::ostream& operator<<(std::ostream& os, milieu m);

