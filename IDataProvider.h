//
// Created by ubuntu on 17-11-16.
//

#ifndef DISRUPTOR_PP_IDATAPROVIDER_H
#define DISRUPTOR_PP_IDATAPROVIDER_H

namespace Disruptor {

    template <typename T>
    class IDataProvider {
    public:
        virtual T operator[](long sequence) = 0;
    };
}

#endif //DISRUPTOR_PP_IDATAPROVIDER_H
