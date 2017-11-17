//
// Created by ubuntu on 17-11-18.
//

#ifndef DISRUPTOR_PP_IDATAPROVIDER_H
#define DISRUPTOR_PP_IDATAPROVIDER_H

#include <cstdint>

namespace Disruptor::Interfaces {
    template <typename T>
    class IDataProvider {
    public:
        virtual T operator[](const int64_t& sequence) = 0;
    };
}

#endif //DISRUPTOR_PP_IDATAPROVIDER_H
