#include "Textviewer.h"
class Plan;
class Dalle;


using namespace std;

// constructeur
TextViewer::TextViewer(ostream& out)
: sortie(out)
{}

// dessin = affichage avec <<
void TextViewer::dessine(Particule const& p)
{
    sortie << p<<endl;
}

void TextViewer::dessine(Source const& s)
{
    sortie << s<<endl;
}

void TextViewer::dessine(Obstacle const& o)
{
    sortie << o<<endl;
}

void TextViewer::dessine(Systeme const& sys)
{
    sortie << sys<<endl;
}

void TextViewer::dessine(Plan const& plan)
{
    sortie << plan<<endl;
}

void TextViewer::dessine(Dalle const& dal)
{
    sortie << dal<<endl;
}
