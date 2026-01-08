
#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include <windows.h>
#include <gl/GL.h>
#include <string>

class Texture {
public:
    unsigned int id;
    int width, height, nrChannels;

    Texture();
    bool load(const char* path);
    void use();                  // œ«·…  ›⁄Ì· «·≈ﬂ”«¡ ﬁ»· «·—”„
};

#endif