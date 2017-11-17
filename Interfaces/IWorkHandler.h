//
// Created by ubuntu on 17-11-18.
//

#ifndef DISRUPTOR_PP_IWORKHANDLER_H
#define DISRUPTOR_PP_IWORKHANDLER_H

namespace Disruptor::Interfaces {
    /**
     * @brief Interface
     * Callback interface to be implemented for processing units of work as they become available in the {@link RingBuffer<T>}
     *
     * @param <T> event implementation storing the data for sharing during exchange or parallel coordination of an event.
     */
    template <typename T>
    class IWorkHandler {
        /**
     * @brief Interface
     * Callback to indicate a unit of work needs to be processed.
     *
     * @param <T> event published to the {@link RingBuffer<T>}
     */
        virtual void OnEvent(T *event) = 0;
    };
}

#endif //DISRUPTOR_PP_IWORKHANDLER_H
