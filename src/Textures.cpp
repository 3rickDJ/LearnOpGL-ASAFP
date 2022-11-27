#include <iostream>
#include "Textures.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


void Textures::loadTextureFromFile(char *filename, int index) {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    //glEnable(GL_DEPTH_TEST);
    int x,y,n;
    unsigned char *data = stbi_load(filename,&x,&y,&n,0);
    if(data== nullptr){
        std::cout << stbi_failure_reason();
        std::cout << "No se pudo leer\n";
    }

    //generate an OpenGL texture ID for this texture
    glGenTextures(1, &texture[index]);
    //bind to the new texture ID
    glBindTexture(GL_TEXTURE_2D, texture[index]);


    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, x, y, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, data);
    stbi_image_free(data);
}

void Textures::activate(int face) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[face]);
}

void Textures::deactivate() {
    glDisable(GL_TEXTURE_2D);
}
