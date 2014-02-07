//
//  ThreadingUI.h
//  ViolinMIR
//
//  Created by Minwei Gu on 12/1/13.
//
//

#ifndef __ViolinMIR__ThreadingUI__
#define __ViolinMIR__ThreadingUI__

#include <iostream>
#include "JuceHeader.h"

//==============================================================================
class BouncingBallComp;
class DemoThread;
class DemoThreadPoolJob;
class ThreadingDemo  : public Component, public Timer, public ButtonListener
{
public:
    //==============================================================================
    ThreadingDemo();
    ~ThreadingDemo();
    void resetAllBalls();
    void paint (Graphics& g);
    void setUsingPool (bool usePool);
    void addABall();
    void addABall(int note,int channel);
    void removeABall();
    void timerCallback();
    void buttonClicked (Button*);
    static void menuItemChosenCallback (int result, ThreadingDemo* demoComponent);
    void parentHierarchyChanged();
    
private:
    ThreadPool pool;
    //TextButton controlButton;
    bool isUsingPool;
    
    OwnedArray<Component> balls;
};



//==============================================================================
//Component* createThreadingDemo()
//{
//    return new ThreadingDemo();
//}

#endif /* defined(__ViolinMIR__ThreadingUI__) */
