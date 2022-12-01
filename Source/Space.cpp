#include "../Header/Space.h"
#include "../Header/drawings.h"
#include "../Header/globalParameters.h"
#include "../Header/lighting.h"
#include <memory>

void Space::drawAndMove(double time)
{
    glPushMatrix();
        glRotated(-90,1,0,0); // rotaciona para frente para dar mais visibilidade na rotação
        drawCorpse(estrelas,time);
    glPopMatrix();

    glPushMatrix();
        glRotated(-90,1,0,0); // rotaciona para frente para dar mais visibilidade na rotação

        glPushMatrix();
            drawCorpse(sol,time);
        glPopMatrix();

        for(std::shared_ptr<Planet> planet : planets)
        {
            glPushMatrix();
                drawCorpse(planet,time);
            glPopMatrix();

            for(std::shared_ptr<Moon> moon: planet->getMoons())
            {
                glPushMatrix();
                    glRotatef(time * planet->getTranslationAngularSpeed(),0,0,1); // rotaciona ao redor do planeta
                    glTranslated(-planet->getRotationRadius(),0, 0); // determina o raio da rotação (e indiretamente o centro de rotação)
                    drawCorpse(moon,time);
                glPopMatrix();
            }
        }
    glPopMatrix();
}

void Space::initializePlanets() 
{
    estrelas = std::make_shared<Planet>(texturesId[8],0,0,4500,0,15000,0);
    sol = std::make_shared<Planet>(texturesId[9],0,0,600,0,0,10);
    planets.push_back(std::make_shared<Planet>(texturesId[2], 1, 1, 90, 5, 1200, 0.99));
}