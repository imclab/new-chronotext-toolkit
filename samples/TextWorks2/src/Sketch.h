/*
 * THE NEW CHRONOTEXT TOOLKIT: https://github.com/arielm/new-chronotext-toolkit
 * COPYRIGHT (C) 2012-2014, ARIEL MALKA ALL RIGHTS RESERVED.
 *
 * THE FOLLOWING SOURCE-CODE IS DISTRIBUTED UNDER THE MODIFIED BSD LICENSE:
 * https://github.com/arielm/new-chronotext-toolkit/blob/master/LICENSE.md
 */

/*
 * ...
 */

#pragma once

#include "chronotext/cinder/CinderSketch.h"
#include "chronotext/font/zf/FontManager.h"

#include "StyledLineLayout.h"

class Sketch : public chr::CinderSketch
{
    chr::zf::FontManager fontManager;
    
    std::shared_ptr<chr::ZFont> font1;
    std::shared_ptr<chr::ZFont> font2;
    
    float fontSize;
    std::map<int, StyledLineLayout::Style> styleSheet;
    StyledLineLayout layout;

public:
    Sketch(void *context, void *delegate = NULL);
    
    void setup(bool renewContext);
    void event(int id);
    void draw();
    
    void drawAlignedText(const StyledLineLayout &layout, const ci::Vec2f &position, chr::ZFont::Alignment alignX, chr::ZFont::Alignment alignY);
};
