//
// Created by ubuntu on 17-11-17.
//

#ifndef DISRUPTOR_PP_IEVENTTRANSLATORTWOARG_H
#define DISRUPTOR_PP_IEVENTTRANSLATORTWOARG_H

#include <cstdint>

namespace Disruptor::Interfaces {
    /// <summary>
    /// Implementations translate another data representations into events claimed from the <see cref="RingBuffer{T}"/>
    /// </summary>
    /// <typeparam name="T">event implementation storing the data for sharing during exchange or parallel coordination of an event.</typeparam>
    /// <typeparam name="A"></typeparam>
    /// <typeparam name="B"></typeparam>
    template <typename T, typename A, typename B>
    class IEventTranslatorTwoArg {
    public:
        /// <summary>
        /// Translate a data representation into fields set in given event
        /// </summary>
        /// <param name="event">into which the data should be translated.</param>
        /// <param name="sequence">that is assigned to event.</param>
        /// <param name="arg0"></param>
        /// <param name="arg1"></param>
        virtual void TranslateTo(T *event, const int64_t& sequence, const A& arg0, const B& arg1) = 0;
    };
}

#endif //DISRUPTOR_PP_IEVENTTRANSLATORTWOARG_H
