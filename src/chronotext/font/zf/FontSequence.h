/*
 * THE NEW CHRONOTEXT TOOLKIT: https://github.com/arielm/new-chronotext-toolkit
 * COPYRIGHT (C) 2014, ARIEL MALKA ALL RIGHTS RESERVED.
 *
 * THE FOLLOWING SOURCE-CODE IS DISTRIBUTED UNDER THE MODIFIED BSD LICENSE:
 * https://github.com/arielm/new-chronotext-toolkit/blob/master/LICENSE.md
 */

#pragma once

#include "chronotext/quad/QuadBatchMap.h"
#include "chronotext/font/zf/FontTexture.h"

namespace chronotext
{
    namespace zf
    {
        class FontSequence
        {
        public:
            bool useColor;
            float anisotropy;
            
            FontSequence() {}
            
        protected:
            std::vector<std::unique_ptr<QuadBatchMap<FontTexture>>> maps;
            
            void begin(bool useColor = false, float anisotropy = 0);
            void end();
            
            void addMap(std::unique_ptr<QuadBatchMap<FontTexture>> &&map);
            void replay(const GLushort *indices);
            
            friend class VirtualFont;
            
        private:
            FontSequence(const FontSequence &that); // MAKES IT EXPLICIT: FontSequence CAN'T BE COPIED (I.E. BECAUSE OF THE vector OF unique_ptr)
        };
    }
}

namespace chr = chronotext;
