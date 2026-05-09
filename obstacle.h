# pragma once 
# include "Vecteur3D.h"
#include "SupportADessin.h"
# include "Dessinable.h"
#include "Agent.h"
class ParticuleNeige;
class ParticuleRoche;
class Obstacle : public Dessinable, public Agent{
	protected:
		Vecteur3D O;
	public:
		// virtual pure pour point le plus proche
		virtual Vecteur3D PointPlusProche(Vecteur3D const& x_i) const = 0;
		Vecteur3D get_O() const;
		Obstacle (Vecteur3D O_);
		Obstacle();
		//dessinable
		void dessine_sur(SupportADessin& support) const;
		
};
//affichage obstacle
std::ostream& operator<<(std::ostream& os, const Obstacle& o);

class Plan : public Obstacle{
protected:
	Vecteur3D n;
public:

// déclaration des méthodes pour trouver le point le plus proche de l'instance
virtual Vecteur3D PointPlusProche(Vecteur3D const& x_i) const;
Plan(Vecteur3D O, Vecteur3D n);
Plan();
//déclaration des getters
Vecteur3D get_n() const;
//dessinable
void dessine_sur(SupportADessin& support) const;
// Fonctions héritées de Agent
    virtual void opere_sur(ParticuleNeige& p)override;
    virtual void opere_sur(ParticuleRoche& p)override;
    virtual void opere_sur(Obstacle& o)override;  
};

//affichage plan
std::ostream& operator<<(std::ostream& os, const Plan& o);

class Dalle : public Plan{
	private:
		double L;
		double l;
		Vecteur3D vl;
		Vecteur3D vL;
		
	public:
	//redéfinition de la méthode pour trouver le vecteur le plus proche
	Vecteur3D PointPlusProche(Vecteur3D const& x_i) const;
	// constructeur de Dalle
	Dalle (double L_, double l_, Vecteur3D O_, Vecteur3D n_, Vecteur3D vl_, Vecteur3D vL_);
	//getters
	double get_L()const;
	double get_l()const;
	//constructeur par défaut
	Dalle();
	//dessinable
	void dessine_sur(SupportADessin& support) const ;
	// Fonctions héritées de Agent
    void opere_sur(ParticuleNeige& p) override;
    void opere_sur(ParticuleRoche& p) override;
    void opere_sur(Obstacle& o) override;
};



/*
class Plan : public Obstacle {
public:
    Plan(Vecteur3D O, Vecteur3D n);
    Plan();
    
    virtual Vecteur3D PointPlusProche(Vecteur3D const& x_i) const override;
    Vecteur3D get_n() const;
    void dessine_sur(SupportADessin& support) const override;

    // COPIER-COLLER STRICT :
    virtual void opere_sur(ParticuleNeige& p) = 0;
    virtual void opere_sur(ParticuleRoche& p) = 0;
    virtual void opere_sur(Obstacle& o) = 0;  
};

class Dalle : public Plan {
public:
    Dalle(double L_, double l_, Vecteur3D O_, Vecteur3D n_, Vecteur3D vl_, Vecteur3D vL_);
    Dalle();
    
    Vecteur3D PointPlusProche(Vecteur3D const& x_i) const override;
    double get_L() const;
    double get_l() const;
    void dessine_sur(SupportADessin& support) const override;

    // COPIER-COLLER STRICT :
    void opere_sur(ParticuleNeige& p) override;
    void opere_sur(ParticuleRoche& p) override;
    void opere_sur(Obstacle& o) override;
   
};
*/
//affichage dalle
std::ostream& operator<<(std::ostream& os, const Dalle& o);
