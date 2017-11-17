//
// Created by ubuntu on 17-11-17.
//

#ifndef DISRUPTOR_PP_IGNOREEXCEPTIONHANDLER_H
#define DISRUPTOR_PP_IGNOREEXCEPTIONHANDLER_H

#include <iostream>
#include <cstdint>
#include "Interfaces/IExceptionHandler.h"

namespace Disruptor {
    /// <summary>
    /// Convenience implementation of an exception handler that using Console.WriteLine to log the exception
    /// </summary>
    template <typename T>
    class IgnoreExceptionHandler : public Interfaces::IExceptionHandler<T> {
    public:
        /// <summary>
        /// Strategy for handling uncaught exceptions when processing an event.
        /// </summary>
        /// <param name="ex">exception that propagated from the <see cref="IEventHandler{T}"/>.</param>
        /// <param name="sequence">sequence of the event which cause the exception.</param>
        /// <param name="evt">event being processed when the exception occurred.</param>
        void HandleEventException(const std::exception& ex, const int64_t& sequence, T *event) {
            std::cout << "Exception processing sequence "
                      << sequence
                      << " for event "
                      << *event
                      << " : "
                      << ex.what();
        }

        /// <summary>
        /// Callback to notify of an exception during <see cref="ILifecycleAware.OnStart"/>
        /// </summary>
        /// <param name="ex">ex throw during the starting process.</param>
        void HandleOnStartException(const std::exception& ex) {
            std::cout << "Exception during OnStart() "
                      << ex.what();
        }

        /// <summary>
        /// Callback to notify of an exception during <see cref="ILifecycleAware.OnShutdown"/>
        /// </summary>
        /// <param name="ex">ex throw during the shutdown process.</param>
        void HandleOnShutdownException(const std::exception& ex) {
            std::cout << "Exception during OnShutdown() "
                      << ex.what();
        }
    };
}

#endif //DISRUPTOR_PP_IGNOREEXCEPTIONHANDLER_H
