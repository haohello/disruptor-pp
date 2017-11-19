//
// Created by ubuntu on 17-11-17.
//

#ifndef DISRUPTOR_PP_INSUFFICIENTCAPACITYEXCEPTION_H
#define DISRUPTOR_PP_INSUFFICIENTCAPACITYEXCEPTION_H

#include <exception>
#include "../Util/Utils.h"

namespace Disruptor :: Exceptions {
    /// <summary>
    /// Exception thrown when it is not possible to insert a value into
    /// the ring buffer without it wrapping the consuming sequences. Used
    /// specifically when claiming with the <see cref="RingBuffer{T}.TryNext()"/> call.
    /// </summary>
    class InsufficientCapacityException : public std::exception {
    private:
        InsufficientCapacityException() {};
        static InsufficientCapacityException instantce;
    public:
        /// <summary>
        /// Pre-allocated exception to avoid garbage generation
        /// </summary>
        static InsufficientCapacityException& GetInstance() {
            return instantce;
        };

        DISALLOW_COPY_MOVE_AND_ASSIGN(InsufficientCapacityException);

    };
}

#endif //DISRUPTOR_PP_INSUFFICIENTCAPACITYEXCEPTION_H
