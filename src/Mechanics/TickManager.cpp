//
//  TickManager.cpp
//  Craft2
//
//  Created by Ryan Riffle on 7/26/18.
//  Copyright © 2018 Ryan Riffle. All rights reserved.
//

#include "TickManager.hpp"
#include "db.h"
#include <iostream>


TickManager::TickManager() :
    mRunning(false),
    mTicks(8000), //Start at 8 am
    mThreadCreated(false),
    mDays(0),
    mStopping(false)
{
    
}


TickManager::~TickManager()
{
    mRunning = false;
    mStopping = true;
    
    mTickThread.join();
}

void TickManager::onTick(unsigned int tickCount)
{
    for (auto it = mTickHandlers.begin(); it != mTickHandlers.end(); ++it) {
        std::function<void(int)> func = *it;
        func(tickCount);
    }
}


void TickManager::tickLoop()
{
    while(true) {
        while (mRunning) {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            onTick(++mTicks);
            
            if (mTicks > TICKS_PER_DAY) {
                mDays++;
                mTicks = 0;
            }
        }
        
        if (mStopping)
            break;
        
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void TickManager::start()
{
    mRunning = true;
    
    if (mThreadCreated == false) {
        this->setupThread();
    }
}


void TickManager::pause()
{
    mRunning = false;
}


void TickManager::addTicks(unsigned int tickCount)
{
    mTicks += tickCount;
}

void TickManager::setupThread()
{
    mThreadCreated = true;
    mTickThread = std::thread(&TickManager::tickLoop, this);
}

unsigned int TickManager::getTicks()
{
    return mTicks;
}

bool TickManager::isPaused()
{
    return !mRunning;
}

unsigned int TickManager::getDay()
{
    return mDays;
}

void TickManager::addTickHandler(std::function<void (unsigned int)> handler)
{
    mTickHandlers.push_back(handler);
}

bool TickManager::loadFromDatabase()
{
    int notImplemented = 0;
    
    return db_load_enironment_state(&mTicks, &mDays, &notImplemented);
}

void TickManager::save()
{
    db_save_environment_state(mTicks, mDays, 0);
}








