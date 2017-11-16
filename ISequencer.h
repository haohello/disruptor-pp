//
// Created by ubuntu on 17-11-16.
//

#ifndef DISRUPTOR_PP_ISEQUENCER_H
#define DISRUPTOR_PP_ISEQUENCER_H

#endif //DISRUPTOR_PP_ISEQUENCER_H

namespace Disruptor {

    class ICursored
    {
    public:
        virtual long getCursor() = 0;
    };

}