/*
 * THE NEW CHRONOTEXT TOOLKIT: https://github.com/arielm/new-chronotext-toolkit
 * COPYRIGHT (C) 2012-2014, ARIEL MALKA ALL RIGHTS RESERVED.
 *
 * THE FOLLOWING SOURCE-CODE IS DISTRIBUTED UNDER THE MODIFIED BSD LICENSE:
 * https://github.com/arielm/new-chronotext-toolkit/blob/master/LICENSE.md
 */

#include "chronotext/android/cinder/CinderSketch.h"
#include "chronotext/android/cinder/CinderDelegate.h"
#include "cinder/app/AppAndroid.h"

using namespace std;
using namespace ci;
using namespace ci::app;

namespace chronotext
{
    CinderSketch::CinderSketch()
    :
    CinderSketchBase(),
    context(nullptr),
    delegate(nullptr),
    mClock(FrameClock::create()),
    mTimeline(Timeline::create())
    {}
    
#pragma mark ---------------------------------------- GETTERS ----------------------------------------

    ostream& CinderSketch::console()
    {
        return context->console();
    }
    
    boost::asio::io_service& CinderSketch::io_service() const
    {
        return context->io_service();
    }
    
    double CinderSketch::getElapsedSeconds() const
    {
        return context->getElapsedSeconds();
    }
    
    uint32_t CinderSketch::getElapsedFrames() const
    {
        return context->getElapsedFrames();
    }

    bool CinderSketch::isEmulated() const
    {
        return context->isEmulated();
    }
    
    DisplayInfo CinderSketch::getDisplayInfo() const
    {
        return context->getDisplayInfo();
    }
    
    WindowInfo CinderSketch::getWindowInfo() const
    {
        return context->getWindowInfo();
    }
    
#pragma mark ---------------------------------------- ACCELEROMETER ----------------------------------------

    void CinderSketch::enableAccelerometer(float updateFrequency, float filterFactor)
    {
        context->enableAccelerometer(updateFrequency, filterFactor);
    }
    
    void CinderSketch::disableAccelerometer()
    {
        context->disableAccelerometer();
    }
    
#pragma mark ---------------------------------------- DELEGATION ----------------------------------------
    
    void CinderSketch::action(int actionId)
    {
        if (delegate)
        {
            delegate->action(actionId);
        }
    }

    void CinderSketch::sendMessageToDelegate(int what, const string &body)
    {
        if (delegate)
        {
            delegate->receiveMessageFromSketch(what, body);
        }
    }
    
    CinderDelegate* CinderSketch::getDelegate() const
    {
        return delegate;
    }
    
    void CinderSketch::setDelegate(CinderDelegate *delegate)
    {
        this->delegate = delegate;
    }
}