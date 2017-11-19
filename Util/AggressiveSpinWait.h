//
// Created by ubuntu on 17-11-19.
//

#ifndef DISRUPTOR_PP_AGGRESSIVESPINWAIT_H
#define DISRUPTOR_PP_AGGRESSIVESPINWAIT_H

#include <climits>
#include <iostream>
#include <thread>
#include <chrono>
#include "Utils.h"

namespace Disruptor {
    class AggressiveSpinWait {
    private:
        static const bool _isSingleProcessor = false; //
        const int _yieldThreshold = 10;
        const int _sleep0EveryHowManyTimes = 5;
        int _count;
        bool NextSpinWillYield() {
            return _count > _yieldThreshold || _isSingleProcessor;
        };

    public:
        void SpinOnce() {
            if (NextSpinWillYield())
            {
                int yieldsSoFar = (_count >= _yieldThreshold ? _count - _yieldThreshold : _count);

                if ((yieldsSoFar % _sleep0EveryHowManyTimes) == (_sleep0EveryHowManyTimes - 1))
                {
                    //std::chrono::microseconds m(0);
                    std::this_thread::sleep_for(std::chrono::milliseconds(0));
                }
                else
                {
                    std::this_thread::yield();
                }
            }
            else
            {
                size_t spinIters = 4 << _count;
                for (size_t i = 0; i < spinIters; i++)
                    Utils::CpuRelax();
                // Thread.SpinWait(4 << _count);
            }

            _count = (_count == INT_MAX ? _yieldThreshold : _count + 1);
        }
    };
}

#endif //DISRUPTOR_PP_AGGRESSIVESPINWAIT_H
