# pragma once
#include "SupportADessin.h"
#include "Particule.h"
#include "Source.h"
#include "obstacle.h"
#include "Systeme.h"
class Plan;
class Dalle;


class TextViewer : public SupportADessin{
	private:
    std::ostream& sortie;

	public:
    // constructeur
    TextViewer(std::ostream& out);

    // méthodes de dessin
    virtual void dessine(Particule const& p) override;
    virtual void dessine(Source const& s) override;
    virtual void dessine(Obstacle const& o) override;
    virtual void dessine(Systeme const& sys) override;
    virtual void dessine(Plan const& pla) override;
    virtual void dessine(Dalle const& dal) override;
}; 
