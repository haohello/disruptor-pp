//
// Created by ubuntu on 17-11-18.
//

#ifndef DISRUPTOR_PP_ICURSORED_H
#define DISRUPTOR_PP_ICURSORED_H

#include <cstdint>

namespace Disruptor::Interfaces {
    class ICursored {
    public:
        virtual int64_t GetCursor() = 0;
    };
}

#endif //DISRUPTOR_PP_ICURSORED_H
