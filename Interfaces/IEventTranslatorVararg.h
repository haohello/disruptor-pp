//
// Created by ubuntu on 17-11-17.
//

#ifndef DISRUPTOR_PP_IEVENTTRANSLATORVARARG_H
#define DISRUPTOR_PP_IEVENTTRANSLATORVARARG_H

#include <cstdarg>
#include <cstdint>

namespace Disruptor::Interfaces {
    /// <summary>
    /// Implementations translate another data representations into events claimed from the <see cref="RingBuffer{T}"/>
    /// </summary>
    /// <typeparam name="T">event implementation storing the data for sharing during exchange or parallel coordination of an event.</typeparam>
    template <typename T>
    class IEventTranslatorVararg {
    public:
        /// <summary>
        /// Translate a data representation into fields set in given event
        /// </summary>
        /// <param name="event">into which the data should be translated.</param>
        /// <param name="sequence">that is assigned to event.</param>
        /// <param name="args">The array of user arguments.</param>
        virtual void TranslateTo(T *event, const int64_t& sequence, ...) = 0;
    };
}

#endif //DISRUPTOR_PP_IEVENTTRANSLATORVARARG_H
