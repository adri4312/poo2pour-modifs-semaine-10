CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Objets communs
COMMON_OBJS = Vecteur3D.o Particule.o ParticuleNeige.o ParticuleRoche.o Source.o Aleatoire.o obstacle.o TextViewer.o Systeme.o 

# Exécutables
TARGETS = testNeige testP11

# Tout compiler
all: $(TARGETS)

# --- Règles pour les objets ---
Vecteur3D.o: Vecteur3D.cc Vecteur3D.h
	$(CXX) $(CXXFLAGS) -c Vecteur3D.cc

Particule.o: Particule.cc Particule.h Vecteur3D.h
	$(CXX) $(CXXFLAGS) -c Particule.cc
ParticuleNeige.o: ParticuleNeige.cc ParticuleNeige.h
	$(CXX) $(CXXFLAGS) -c ParticuleNeige.cc
Source.o: Source.cc Source.h Particule.h Aleatoire.h SupportADessin.h
	$(CXX) $(CXXFLAGS) -c Source.cc

Aleatoire.o: Aleatoire.cc Aleatoire.h
	$(CXX) $(CXXFLAGS) -c Aleatoire.cc

obstacle.o: obstacle.cc obstacle.h SupportADessin.h Particule.h ParticuleNeige.h ParticuleRoche.h
	$(CXX) $(CXXFLAGS) -c obstacle.cc

TextViewer.o: TextViewer.cc TextViewer.h SupportADessin.h
	$(CXX) $(CXXFLAGS) -c TextViewer.cc

Systeme.o: Systeme.cc Systeme.h Particule.h obstacle.h SupportADessin.h
	$(CXX) $(CXXFLAGS) -c Systeme.cc

	

	
ParticuleRoche.o: ParticuleRoche.cc ParticuleRoche.h
	$(CXX) $(CXXFLAGS) -c ParticuleRoche.cc

# --- Objets spécifiques aux tests ---
testNeige.o: testNeige.cc Agent.h ParticuleNeige.h
	$(CXX) $(CXXFLAGS) -c testNeige.cc

testP11.o: testP11.cc Vecteur3D.h Particule.h Obstacle.h Source.h Systeme.h
	$(CXX) $(CXXFLAGS) -c testP11.cc

# --- Règles pour créer les exécutables ---
testNeige: $(COMMON_OBJS) testNeige.o ParticuleNeige.o 
	$(CXX) $(CXXFLAGS) $(COMMON_OBJS) testNeige.o -o testNeige

testP11: $(COMMON_OBJS) testP11.o
	$(CXX) $(CXXFLAGS) $(COMMON_OBJS) testP11.o -o testP11

# Nettoyage
clean:
	rm -f *.o $(TARGETS)
