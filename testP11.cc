#include <iostream>
#include <memory>
#include "Systeme.h"
#include "Particule.h"
#include "obstacle.h"
#include "Source.h"
#include "TextViewer.h"
#include "ParticuleNeige.h"
#include "ParticuleRoche.h"

using namespace std;

int main() {
    // Création de particules
    auto p1 = make_unique<ParticuleNeige>(Vecteur3D(0,0,0), Vecteur3D(1,0,0), 10.0, 1.0);
    auto p2 = make_unique<ParticuleRoche>(Vecteur3D(1,0,0), Vecteur3D(0,1,0), 15.0, 2.0);

    // Création d'obstacles
    auto plan = make_unique<Plan>(Vecteur3D(0,-1,0), Vecteur3D(0,1,0));
    auto dalle = make_unique<Dalle>(2.0, 3.0, Vecteur3D(0,0,0), Vecteur3D(0,1,0), Vecteur3D(1,0,0), Vecteur3D(0,0,1));

    // Création du système
    Systeme S;

    // Ajout des particules
    S.ajout_particule(move(p1));
    S.ajout_particule(move(p2));

    // Ajout des obstacles
    S.ajout_obstacle(move(plan));
    S.ajout_obstacle(move(dalle));

    // Affichage initial
    cout << "=== Etat initial du système ===" << endl;
    cout << S << endl;

    // Faire évoluer le système
    double dt = 0.1; // petit pas de temps
    S.evolue(dt);

    // Affichage après évolution
    cout << "=== Etat du système après évolution ===" << endl;
    cout << S << endl;

    // Dessin textuel
    TextViewer viewer(cout);
    S.dessine_sur(viewer);

    return 0;
}
