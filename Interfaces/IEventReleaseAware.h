//
// Created by ubuntu on 17-11-17.
//

#ifndef DISRUPTOR_PP_IEVENTRELEASEAWARE_H
#define DISRUPTOR_PP_IEVENTRELEASEAWARE_H

#include "IEventReleaser.h"

namespace Disruptor::Interfaces {
    class IEventReleaseAware {
    public:
        virtual void SetEventReleaser(IEventReleaser *eventReleaser) = 0;
    };
}

#endif //DISRUPTOR_PP_IEVENTRELEASEAWARE_H
