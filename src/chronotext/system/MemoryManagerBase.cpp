/*
 * THE NEW CHRONOTEXT TOOLKIT: https://github.com/arielm/new-chronotext-toolkit
 * COPYRIGHT (C) 2012-2014, ARIEL MALKA ALL RIGHTS RESERVED.
 *
 * THE FOLLOWING SOURCE-CODE IS DISTRIBUTED UNDER THE SIMPLIFIED BSD LICENSE:
 * https://github.com/arielm/new-chronotext-toolkit/blob/master/LICENSE.md
 */

#include "MemoryManagerBase.h"

#include "chronotext/system/Context.h"
#include "chronotext/Log.h"

using namespace std;

namespace chronotext
{
    namespace memory
    {
        Info getInfo()
        {
            return context::memoryManager()->updateInfo();
        }
        
        // ---
        
        bool ManagerBase::init()
        {
            LOGI << "MEMORY INFO: " << updateInfo() << endl;
            return true;
        }
        
        void ManagerBase::uninit()
        {
            LOGI << "MEMORY INFO: " << updateInfo() << endl;
        }
    }
}
