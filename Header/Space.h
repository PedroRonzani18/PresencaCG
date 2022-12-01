#ifndef _SPACE_H
#define _SPACE_H

#include "Planet.h"
#include <vector>
#include <memory>

class Space{
    private:
        //Planet sol;
        std::shared_ptr<Planet> sol;
        std::shared_ptr<Planet> estrelas;
        std::vector<Planet> planetas;
        std::vector<std::shared_ptr<Planet>> planets;

        //Planet estrelas;

    public:
        void addPlaneta(Planet p){planetas.push_back(p);}
        Planet getPlaneta(int i){return planetas[i];}

        void drawAndMove(double time);
        void initializePlanets();

};

#endif