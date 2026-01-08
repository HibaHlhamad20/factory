#include "Texture.h"
#include <iostream>


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h" 

Texture::Texture() {
    id = 0;
}

bool Texture::load(const char* path) {
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    // ≈⁄œ«œ«   ﬂ—«— «·’Ê—… Ê ‰⁄Ì„Â«
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //  Õ„Ì· »Ì«‰«  «·’Ê—…
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);

    if (data) {
        GLenum format = (nrChannels == 4) ? GL_RGBA : GL_RGB;
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        stbi_image_free(data);
        return true;
    }
    else {
        std::cout << "Failed to load texture: " << path << std::endl;
        stbi_image_free(data);
        return false;
    }
}

void Texture::use() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, id);
}