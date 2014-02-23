/*
 * THE NEW CHRONOTEXT TOOLKIT: https://github.com/arielm/new-chronotext-toolkit
 * COPYRIGHT (C) 2014, ARIEL MALKA ALL RIGHTS RESERVED.
 *
 * THE FOLLOWING SOURCE-CODE IS DISTRIBUTED UNDER THE MODIFIED BSD LICENSE:
 * https://github.com/arielm/new-chronotext-toolkit/blob/master/LICENSE.md
 */

#include "chronotext/font/zf/ReloadableTexture.h"
#include "chronotext/utils/MathUtils.h"

using namespace std;
using namespace ci;

namespace chronotext
{
    namespace zf
    {
        ReloadableTexture::ReloadableTexture(const GlyphData &glyphData)
        :
        id(0)
        {
            upload(glyphData);
        }
        
        ReloadableTexture::~ReloadableTexture()
        {
            discard();
        }
        
        void ReloadableTexture::upload(const GlyphData &glyphData)
        {
            if (!id)
            {
                useMipmap = glyphData.useMipmap;
                auto buffer = glyphData.getBuffer();
                
                width = nextPowerOfTwo(glyphData.width + glyphData.padding * 2);
                height = nextPowerOfTwo(glyphData.height + glyphData.padding * 2);
                auto textureData = new unsigned char[width * height](); // ZERO-FILLED
                
                for (int y = 0; y < glyphData.height; y++)
                {
                    for (int x = 0; x < glyphData.width; x++)
                    {
                        textureData[(y + glyphData.padding) * width + (x + glyphData.padding)] = buffer[y * glyphData.width + x];
                    }
                }
                
                // ---
                
                glGenTextures(1, &id);
                glBindTexture(GL_TEXTURE_2D, id);
                
                if (useMipmap)
                {
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
                }
                else
                {
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                }
                
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
                
                if (useMipmap)
                {
                    glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
                    glHint(GL_GENERATE_MIPMAP_HINT, GL_NICEST);
                }
                
                glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, width, height, 0, GL_ALPHA, GL_UNSIGNED_BYTE, textureData);
                
                if (useMipmap)
                {
                    glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_FALSE);
                }
                
                glBindTexture(GL_TEXTURE_2D, 0);
                delete[] textureData;
            }
        }
        
        void ReloadableTexture::discard()
        {
            if (id)
            {
                glDeleteTextures(1, &id);
                id = 0;
            }
        }
        
        bool ReloadableTexture::isLoaded() const
        {
            return (id != 0);
        }
        
        size_t ReloadableTexture::getMemoryUsage() const
        {
            if (id)
            {
                if (useMipmap)
                {
                    return size_t(width * height * 1.333f);
                }
                else
                {
                    return width * height;
                }
            }
            else
            {
                return 0;
            }
        }
        
        Vec2i ReloadableTexture::getSize() const
        {
            return Vec2i(width, height);
        }
    }
}
