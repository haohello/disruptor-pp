//
// Created by ubuntu on 17-11-17.
//

#ifndef DISRUPTOR_PP_IBATCHSTARTAWARE_H
#define DISRUPTOR_PP_IBATCHSTARTAWARE_H

#include<cstdint>

namespace Disruptor::Interfaces {
    class IBatchStartAware {
    public:
        virtual void OnBatchStart(const int64_t& batchSize) = 0;
    };
}

#endif //DISRUPTOR_PP_IBATCHSTARTAWARE_H
