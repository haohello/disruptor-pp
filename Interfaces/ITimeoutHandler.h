//
// Created by ubuntu on 17-11-17.
//

#ifndef DISRUPTOR_PP_ITIMEOUTHANDLER_H
#define DISRUPTOR_PP_ITIMEOUTHANDLER_H

#include <cstdint>

namespace Disruptor::Interfaces {

    class ITimeoutHandler {
        virtual void OnTimeOut(const int64_t& sequence) = 0;
    };
}

#endif //DISRUPTOR_PP_ITIMEOUTHANDLER_H
