/*
 * THE NEW CHRONOTEXT TOOLKIT: https://github.com/arielm/new-chronotext-toolkit
 * COPYRIGHT (C) 2012-2014, ARIEL MALKA ALL RIGHTS RESERVED.
 *
 * THE FOLLOWING SOURCE-CODE IS DISTRIBUTED UNDER THE MODIFIED BSD LICENSE:
 * https://github.com/arielm/new-chronotext-toolkit/blob/master/LICENSE.md
 */

#pragma once

#include "chronotext/font/zf/VirtualFont.h"

class StyledLineLayout
{
public:
    struct Chunk
    {
        int tag;
        chr::ZFont *font;
        
        std::vector<chr::zf::Cluster*> clusters;
        
        Chunk(int tag, chr::ZFont *font)
        :
        tag(tag),
        font(font)
        {}
        
        float getAdvance() const
        {
            float advance = 0;
            
            for (auto &cluster : clusters)
            {
                advance += font->getAdvance(*cluster);
            }
            
            return advance;
        }
    };
    
    struct Style
    {
        chr::ZFont *font;
        ci::ColorA color;
        
        Style()
        {}
        
        Style(std::shared_ptr<chr::ZFont> font, const ci::ColorA &color)
        :
        font(font.get()),
        color(color)
        {}
    };
    
    std::vector<std::unique_ptr<chr::zf::LineLayout>> lineLayouts;
    std::vector<Chunk> chunks;
    
    StyledLineLayout();
    StyledLineLayout(const chr::zf::TextLine &line, std::map<int, Style> &styleSheet);
    
    float getAdvance() const;
    float getOffsetX(chr::ZFont::Alignment align) const;
    float getOffsetY(chr::ZFont::Alignment align) const;
    inline ci::Vec2f getOffset(chr::ZFont::Alignment alignX, chr::ZFont::Alignment alignY) const { return ci::Vec2f(getOffsetX(alignX), getOffsetY(alignY)); }
    
    void setSize(float size) const;
    
    void beginSequence() const;
    void endSequence() const;
};
