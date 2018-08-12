//
//  TickManager.hpp
//  Craft2
//
//  Created by Ryan Riffle on 7/26/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#ifndef TickManager_hpp
#define TickManager_hpp

#define TICKS_PER_DAY 24000
#define TICK_RATE 0.05f

#include <thread>
#include <functional>
#include <vector>

class TickManager {
public:
    TickManager();
    ~TickManager();
    
    void start();
    void pause();
    void addTicks(unsigned tickCount);
    unsigned getTicks();
    bool loadFromDatabase();
    void save();
    
    bool isPaused();
    unsigned getDay();
    
    void addTickHandler(std::function<void(unsigned)> handler);
    
protected:
    void onTick(unsigned tickCount);
    void tickLoop();
    void setupThread();
    
private:
    unsigned mTicks;
    unsigned mDays;
    bool mRunning;
    bool mThreadCreated;
    bool mStopping;
    std::thread mTickThread;
    std::vector< std::function<void(unsigned)> > mTickHandlers;
};

#endif /* TickManager_hpp */
