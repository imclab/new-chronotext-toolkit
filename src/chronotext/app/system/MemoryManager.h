/*
 * THE NEW CHRONOTEXT TOOLKIT: https://github.com/arielm/new-chronotext-toolkit
 * COPYRIGHT (C) 2012-2014, ARIEL MALKA ALL RIGHTS RESERVED.
 *
 * THE FOLLOWING SOURCE-CODE IS DISTRIBUTED UNDER THE SIMPLIFIED BSD LICENSE:
 * https://github.com/arielm/new-chronotext-toolkit/blob/master/LICENSE.md
 */

#pragma once

#include "chronotext/system/MemoryManagerBase.h"

#if !defined(CINDER_MSW)

#error UNSUPPORTED PLATFORM

#endif

namespace chronotext
{
    namespace memory
    {
        class Manager : public ManagerBase
        {
        public:
            Manager();
            ~Manager() override;
            
            Info updateInfo() override;
        };
    }
}