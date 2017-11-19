//
// Created by ubuntu on 17-11-20.
//

#ifndef DISRUPTOR_PP_TIMEOUTEXCEPTION_H
#define DISRUPTOR_PP_TIMEOUTEXCEPTION_H

#include <exception>
#include "../Util/Utils.h"

namespace Disruptor::Exceptions {
    class TimeoutException : public std::exception {
    private:
        TimeoutException(){};
        static TimeoutException instance;

    public:
        TimeoutException& GetInstance() {
            return instance;
        };

        DISALLOW_COPY_MOVE_AND_ASSIGN(TimeoutException);
    };
}

#endif //DISRUPTOR_PP_TIMEOUTEXCEPTION_H
