/*
 * THE NEW CHRONOTEXT TOOLKIT: https://github.com/arielm/new-chronotext-toolkit
 * COPYRIGHT (C) 2012, ARIEL MALKA ALL RIGHTS RESERVED.
 *
 * THE FOLLOWING SOURCE-CODE IS DISTRIBUTED UNDER THE MODIFIED BSD LICENSE:
 * https://github.com/arielm/new-chronotext-toolkit/blob/master/LICENSE.md
 */

#include "chronotext/incubator/ui/HorizontalLayout.h"

using namespace std;
using namespace ci;

namespace chronotext
{
    HorizontalLayout::HorizontalLayout()
    :
    Container()
    {}
    
    HorizontalLayout::HorizontalLayout(LayoutStyleRef style)
    :
    Container(style),
    alignX(style->alignX),
    alignY(style->alignY)
    {}
    
    void HorizontalLayout::setAlign(int x, int y)
    {
        alignX = x;
        alignY = y;
        layoutRequest = true;
    }
    
    void HorizontalLayout::layout()
    {
        if (layoutRequest)
        {
            float previousMargin = 0;
            contentWidth = 0;
            contentHeight = 0;
            
            for (vector<ShapeRef>::const_iterator it = components.begin(); it != components.end(); ++it)
            {
                ShapeRef shape = *it;
                
                if (shape->visible)
                {
                    contentWidth += mergedMargin(previousMargin, shape->marginLeft);
                    contentWidth += shape->getWidth();
                    
                    contentHeight = max<float>(contentHeight, shape->marginTop + shape->getHeight() + shape->marginBottom);
                    previousMargin = shape->marginRight;
                }
            }
            
            contentWidth += previousMargin;
            
            if (autoWidth)
            {
                width = paddingLeft + contentWidth + paddingRight;
            }
            
            if (autoHeight)
            {
                height = paddingTop + contentHeight + paddingBottom;
            }
            
            // ---

            float innerWidth = width - paddingLeft - paddingRight;
            float left = paddingLeft;
            
            switch (alignX)
            {
                case ALIGN_MIDDLE:
                    left += (innerWidth - contentWidth) * 0.5f;
                    break;
                    
                case ALIGN_RIGHT:
                    left += innerWidth - contentWidth;
                    break;
            }
            
            // ---
            
            float innerHeight = height - paddingTop - paddingBottom;
            previousMargin = 0;

            for (vector<ShapeRef>::const_iterator it = components.begin(); it != components.end(); ++it)
            {
                ShapeRef shape = *it;
                
                if (shape->visible)
                {
                    float top = paddingTop;
                    
                    switch (alignY)
                    {
                        case ALIGN_TOP:
                            top += shape->marginTop;
                            break;
                            
                        case ALIGN_MIDDLE:
                            top += (innerHeight - shape->getHeight()) * 0.5f; // XXX
                            break;
                            
                        case ALIGN_BOTTOM:
                            top += innerHeight - shape->getHeight() - shape->marginBottom;
                            break;
                    }

                    left += mergedMargin(previousMargin, shape->marginLeft);
                    shape->setLocation(x + left, y + top);
                    
                    left += shape->getWidth();
                    previousMargin = shape->marginRight;
                }
            }
        }
        
        layoutRequest = false;
    }
}
