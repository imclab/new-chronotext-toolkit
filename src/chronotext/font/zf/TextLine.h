/*
 * THE NEW CHRONOTEXT TOOLKIT: https://github.com/arielm/new-chronotext-toolkit
 * COPYRIGHT (C) 2014, ARIEL MALKA ALL RIGHTS RESERVED.
 *
 * THE FOLLOWING SOURCE-CODE IS DISTRIBUTED UNDER THE MODIFIED BSD LICENSE:
 * https://github.com/arielm/new-chronotext-toolkit/blob/master/LICENSE.md
 */

#pragma once

#include "chronotext/font/zf/TextRun.h"

#include <vector>

namespace chronotext
{
    namespace zf
    {
        struct TextLine
        {
            template<typename T> struct Item
            {
                int32_t start;
                int32_t end;
                T data;
                
                Item(int32_t start, int32_t end, T data)
                :
                start(start),
                end(end),
                data(data)
                {}
            };
            
            typedef Item<std::pair<hb_script_t, std::string>> ScriptAndLanguageItem;
            typedef Item<hb_direction_t> DirectionItem;
            typedef Item<int> TagItem;
            
            UnicodeString text;
            std::string langHint;
            hb_direction_t overallDirection;
            
            std::vector<ScriptAndLanguageItem> scriptAndLanguageItems;
            std::vector<DirectionItem> directionItems;
            std::vector<TagItem> tagItems;
            
            std::vector<TextRun> runs;

            TextLine(const std::string &langHint = "", hb_direction_t overallDirection = HB_DIRECTION_INVALID)
            :
            langHint(langHint),
            overallDirection(overallDirection)
            {}
            
            TextLine(const std::string &input, const std::string &langHint = "", hb_direction_t overallDirection = HB_DIRECTION_INVALID)
            :
            langHint(langHint),
            overallDirection(overallDirection)
            {
                text = UnicodeString::fromUTF8(input);
            }
            
            void addChunk(const std::string &input, int tag)
            {
                int start = text.length();
                text += UnicodeString::fromUTF8(input);
                tagItems.emplace_back(start, text.length(), tag);
            }
            
            void addRun(int32_t start, int32_t end, hb_script_t script, const std::string &lang, hb_direction_t direction, int tag)
            {
                runs.emplace_back(start, end, script, lang, direction, tag);
            }
        };
    }
}

namespace chr = chronotext;
