//
// Created by ubuntu on 17-11-17.
//

#ifndef DISRUPTOR_PP_INSUFFICIENTCAPACITYEXCEPTION_H
#define DISRUPTOR_PP_INSUFFICIENTCAPACITYEXCEPTION_H

#include <exception>

namespace Disruptor {
    /// <summary>
    /// Exception thrown when it is not possible to insert a value into
    /// the ring buffer without it wrapping the consuming sequences. Used
    /// specifically when claiming with the <see cref="RingBuffer{T}.TryNext()"/> call.
    /// </summary>
    class InsufficientCapacityException : public std::exception {
    public:
        /// <summary>
        /// Pre-allocated exception to avoid garbage generation
        /// </summary>
        static InsufficientCapacityException& GetInstance() {
            static InsufficientCapacityException instantce;
            return instantce;
        };

        // C++ 11
        // =======
        // We can use the better technique of deleting the methods
        // we don't want.
        InsufficientCapacityException(InsufficientCapacityException const&)   = delete;
        void operator=(InsufficientCapacityException const&)  = delete;

        // Note: Scott Meyers mentions in his Effective Modern
        //       C++ book, that deleted functions should generally
        //       be public as it results in better error messages
        //       due to the compilers behavior to check accessibility
        //       before deleted status
    };
}

#endif //DISRUPTOR_PP_INSUFFICIENTCAPACITYEXCEPTION_H
