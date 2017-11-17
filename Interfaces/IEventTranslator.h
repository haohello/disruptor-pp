//
// Created by ubuntu on 17-11-18.
//

#ifndef DISRUPTOR_PP_IEVENTTRANSLATOR_H
#define DISRUPTOR_PP_IEVENTTRANSLATOR_H

#include <cstdint>

namespace Disruptor::Interfaces {
    /**
     * @brief Interface
     * Implementations translate another data representations into events claimed from the {@link RingBuffer}
     *
     * @param <T> event implementation storing the data for sharing during exchange or parallel coordination of an event.
     */
    template <typename T>
    class IEventTranslator {
    public:
        /**
         * @brief translateTo
         * Translate a data representation into fields set in given event
         *
         * @param event into which the data should be translated.
         * @param sequence that is assigned to event.
         */
        virtual void TranslateTo(T *event, const int64_t& sequence) = 0;
    };
}

#endif //DISRUPTOR_PP_IEVENTTRANSLATOR_H
