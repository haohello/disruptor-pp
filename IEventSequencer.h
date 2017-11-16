//
// Created by ubuntu on 17-11-16.
//

#ifndef DISRUPTOR_PP_IEVENTSEQUENCER_H
#define DISRUPTOR_PP_IEVENTSEQUENCER_H

#include "IDataProvider.h"
#include "ISequenced.h"

namespace Disruptor {

    template <class T>
    class IEventSequence: public IDataProvider<T>, public ISequenced {
        
    };
}

#endif //DISRUPTOR_PP_IEVENTSEQUENCER_H
