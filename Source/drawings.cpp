#include "../Header/globalParameters.h"
#include "../Header/Planet.h"

#include <stdio.h>
#include <SOIL/SOIL.h>
#include <memory>

void drawSolidSphere(double radius, int stacks, int columns)
{
    GLUquadric* quadObj = gluNewQuadric(); // cira uma quadrica 
    gluQuadricDrawStyle(quadObj, GLU_FILL); // estilo preenchido
    gluQuadricNormals(quadObj, GLU_SMOOTH);
    gluQuadricTexture(quadObj, GL_TRUE); // chama 01 glTexCoord por vértice
    gluSphere(quadObj, radius, stacks, columns); // cria os vértices de uma esfera
    gluDeleteQuadric(quadObj);
}

void drawCorpse(std::shared_ptr<Planet> planet, double time)
{
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, planet->getTexture());

        glRotatef(time * planet->getTranslationAngularSpeed(),0,0,1); // rotaciona ao redor do sol
        glTranslated(-planet->getRotationRadius(),0, 0); // determina o raio da rotação (e indiretamente o centro de rotação)
        glRotatef(time * planet->getRotationAngularSpeed(),0,0,1); // rotaciona no proprio eixo

        if(!planet->doesDependsOnLight())
        {
            glDisable(GL_LIGHTING);
            drawSolidSphere(planet->getCoreRadius(),200,200);
            glEnable(GL_LIGHTING);
        }
        else
            drawSolidSphere(planet->getCoreRadius(),200,200);

    glDisable(GL_TEXTURE_2D);
    
}

void drawCorpse(std::shared_ptr<Moon>  moon, double time)
{
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, moon->getTexture());

        glRotated(time * moon->getTranslationAngularSpeed() + moon->getAngle(),0,0,1); // rotaciona no proprio eixo 
        glTranslated(-moon->getRotationRadius(),0, 0); // determina o raio da rotação (e indiretamente o centro de rotação)
        glRotatef(time * moon->getRotationAngularSpeed(),0,0,1); // rotaciona no proprio eixo
        
        drawSolidSphere(moon->getCoreRadius(),200,200);   

    glDisable(GL_TEXTURE_2D);
    
}

GLuint loadTexture(const char* arquivo)
{
    GLuint idTextura = SOIL_load_OGL_texture(
        arquivo,
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );

    if (idTextura == 0) 
        printf("Erro do SOIL: '%s' + %s\n", SOIL_last_result(),arquivo);

    return idTextura;
}

void createTextures()
{
    texturesId.resize(0);
    /*[ 0]*/texturesId.push_back(loadTexture("imagens/2k_mercury.jpg"));
    /*[ 1]*/texturesId.push_back(loadTexture("imagens/2k_venus_surface.jpg"));
    /*[ 2]*/texturesId.push_back(loadTexture("imagens/2k_earth_daymap.jpg"));
    /*[ 3]*/texturesId.push_back(loadTexture("imagens/2k_mars.jpg"));
    /*[ 4]*/texturesId.push_back(loadTexture("imagens/2k_jupiter.jpg"));
    /*[ 5]*/texturesId.push_back(loadTexture("imagens/2k_saturn.jpg"));
    /*[ 6]*/texturesId.push_back(loadTexture("imagens/2k_uranus.jpg"));
    /*[ 7]*/texturesId.push_back(loadTexture("imagens/2k_neptune.jpg"));
    /*[ 8]*/texturesId.push_back(loadTexture("imagens/2k_stars_milky_way.jpg"));
    /*[ 9]*/texturesId.push_back(loadTexture("imagens/2k_sun.jpg"));
    /*[10]*/texturesId.push_back(loadTexture("imagens/2k_moon.jpg"));
}


