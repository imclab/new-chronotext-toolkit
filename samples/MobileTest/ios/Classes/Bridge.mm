/*
 * THE NEW CHRONOTEXT TOOLKIT: https://github.com/arielm/new-chronotext-toolkit
 * COPYRIGHT (C) 2012-2014, ARIEL MALKA ALL RIGHTS RESERVED.
 *
 * THE FOLLOWING SOURCE-CODE IS DISTRIBUTED UNDER THE SIMPLIFIED BSD LICENSE:
 * https://github.com/arielm/new-chronotext-toolkit/blob/master/LICENSE.md
 */

#import "Bridge.h"

@implementation Bridge

- (id) initWithOptions:(NSDictionary*)options
{
    if (self = [super initWithOptions:options])
    {
        NSDictionary *properties = [NSDictionary dictionaryWithObjectsAndKeys:
            [NSNumber numberWithInt:kEAGLRenderingAPIOpenGLES1], kGLViewControllerPropertyRenderingAPI,
            [NSNumber numberWithInt:UIInterfaceOrientationMaskAll], kGLViewControllerPropertyInterfaceOrientationMask,
            [NSNumber numberWithInt:GLKViewDrawableDepthFormatNone], kGLViewControllerPropertyDepthFormat,
            nil];

        window = [[UIWindow alloc] initWithFrame:UIScreen.mainScreen.bounds];
        window.backgroundColor = [UIColor blackColor];

        [window setRootViewController:[self createViewControllerWithProperties:properties]];
        [window makeKeyAndVisible];
    }
    
    return self;
}

- (void) dealloc
{
    [window release];
    [super dealloc];
}

@end
