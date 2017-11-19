//
// Created by ubuntu on 17-11-20.
//

#ifndef DISRUPTOR_PP_ALERTEXCEPTION_H
#define DISRUPTOR_PP_ALERTEXCEPTION_H

#include <exception>
#include "../Util/Utils.h"

namespace Disruptor :: Exceptions {
    class AlertException : public std::exception {
    private:
        AlertException() {};
        static AlertException instantce;
    public:
        static AlertException& GetInstance() {

            return instantce;
        };

        DISALLOW_COPY_MOVE_AND_ASSIGN(AlertException);
    };
}

#endif //DISRUPTOR_PP_ALERTEXCEPTION_H
