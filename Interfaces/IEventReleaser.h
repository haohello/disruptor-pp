//
// Created by ubuntu on 17-11-17.
//

#ifndef DISRUPTOR_PP_IEVENTRELEASER_H
#define DISRUPTOR_PP_IEVENTRELEASER_H

namespace Disruptor::Interfaces {
    class IEventReleaser {
    public:
        virtual void Release() = 0;
    };
}

#endif //DISRUPTOR_PP_IEVENTRELEASER_H
