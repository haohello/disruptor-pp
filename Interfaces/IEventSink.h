//
// Created by ubuntu on 17-11-17.
//

#ifndef DISRUPTOR_PP_IEVENTSINK_H
#define DISRUPTOR_PP_IEVENTSINK_H

#include <cstdarg>
#include "IEventTranslator.h"
#include "IEventTranslatorOneArg.h"
#include "IEventTranslatorTwoArg.h"
#include "IEventTranslatorThreeArg.h"
#include "IEventTranslatorVararg.h"

namespace Disruptor::Interfaces {
    /// <summary>
    ///     An entity into which events can be published
    /// </summary>
    /// <typeparam name="T"></typeparam>
    template <typename T>
    class IEventSink {
    public:
        /// <summary>
        /// Publishes an event to the ring buffer.  It handles claiming the next sequence, getting the current(uninitialised)
        /// event from the ring buffer and publishing the claimed sequence after translation.
        /// </summary>
        /// <param name="translator">The user specified translation for the event</param>
        virtual void PublishEvent(IEventTranslator<T> *translator) = 0;

        /// <summary>
        /// Attempts to publish an event to the ring buffer.  It handles claiming the next sequence, getting the current(uninitialised)
        /// event from the ring buffer and publishing the claimed sequence after translation.Will return false if specified capacity
        /// was not available.
        /// </summary>
        /// <param name="translator">The user specified translation for the event</param>
        /// <returns>true if the value was published, false if there was insufficient capacity</returns>
        virtual bool TryPublishEvent(IEventTranslator<T> *translator) = 0;

        /// <summary>
        /// Allows one user supplied argument.
        /// </summary>
        /// <typeparam name="A">Class of the user supplied argument</typeparam>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="arg0">A user supplied argument.</param>
        template <typename A>
        virtual void PublishEvent(IEventTranslatorOneArg<T, A> *translator, const A& arg0) = 0;

        /// <summary>
        /// Allows one user supplied argument.
        /// </summary>
        /// <typeparam name="A">Class of the user supplied argument</typeparam>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="arg0">A user supplied argument.</param>
        /// <returns>true if the value was published, false if there was insufficient capacity</returns>
        template <typename A>
        virtual bool TryPublishEvent(IEventTranslatorOneArg<T, A> *translator, const A& arg0) = 0;

        /// <summary>
        /// Allows two user supplied arguments.
        /// </summary>
        /// <typeparam name="A">Class of the user supplied argument</typeparam>
        /// <typeparam name="B">Class of the user supplied argument</typeparam>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="arg0">A user supplied argument.</param>
        /// <param name="arg1">A user supplied argument.</param>
        template <typename A, typename B>
        virtual void PublishEvent(IEventTranslatorTwoArg<T, A, B> *translator,
                                  const A& arg0, const B& arg1) = 0;

        /// <summary>
        /// Allows two user supplied arguments.
        /// </summary>
        /// <typeparam name="A">Class of the user supplied argument</typeparam>
        /// <typeparam name="B">Class of the user supplied argument</typeparam>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="arg0">A user supplied argument.</param>
        /// <param name="arg1">A user supplied argument.</param>
        /// <returns>true if the value was published, false if there was insufficient capacity</returns>
        template <typename A, typename B>
        virtual bool TryPublishEvent(IEventTranslatorTwoArg<T, A, B> *translator,
                                     const A& arg0, const B& arg1) = 0;

        /// <summary>
        /// Allows three user supplied arguments
        /// </summary>
        /// <typeparam name="A">Class of the user supplied argument</typeparam>
        /// <typeparam name="B">Class of the user supplied argument</typeparam>
        /// <typeparam name="C">Class of the user supplied argument</typeparam>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="arg0">A user supplied argument.</param>
        /// <param name="arg1">A user supplied argument.</param>
        /// <param name="arg2">A user supplied argument.</param>
        template <typename A, typename B, typename C>
        virtual void PublishEvent(IEventTranslatorThreeArg<T, A, B, C> *translator,
                                  const A& arg0, const B& arg1, const C& arg2) = 0;

        /// <summary>
        /// Allows three user supplied arguments
        /// </summary>
        /// <typeparam name="A">Class of the user supplied argument</typeparam>
        /// <typeparam name="B">Class of the user supplied argument</typeparam>
        /// <typeparam name="C">Class of the user supplied argument</typeparam>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="arg0">A user supplied argument.</param>
        /// <param name="arg1">A user supplied argument.</param>
        /// <param name="arg2">A user supplied argument.</param>
        /// <returns>true if the value was published, false if there was insufficient capacity</returns>
        template <typename A, typename B, typename C>
        virtual bool TryPublishEvent(IEventTranslatorThreeArg<T, A, B, C> *translator,
                                     const A& arg0, const B& arg1, const C& arg2) = 0;

        /// <summary>
        /// Allows a variable number of user supplied arguments
        /// </summary>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="args">User supplied arguments, one Object[] per event.</param>
        virtual void PublishEvent(IEventTranslatorVararg<T> *translator, ...) = 0;

        /// <summary>
        /// Allows a variable number of user supplied arguments
        /// </summary>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="args">User supplied arguments, one Object[] per event.</param>
        /// <returns>true if the value was published, false if there was insufficient capacity</returns>
        virtual bool TryPublishEvent(IEventTranslatorVararg<T> *translator, ...) = 0;

        /// <summary>
        /// Publishes multiple events to the ring buffer.  It handles claiming the next sequence, getting the current(uninitialised)
        /// event from the ring buffer and publishing the claimed sequence after translation.
        /// <para/>
        /// With this call the data that is to be inserted into the ring buffer will be a field (either explicitly or captured anonymously),
        /// therefore this call will require an instance of the translator for each value that is to be inserted into the ring buffer.
        /// </summary>
        /// <param name="translators">The user specified translation for each event</param>
        virtual void PublishEvents(IEventTranslator<T> *translators, const int& length) = 0;

        /// <summary>
        /// Publishes multiple events to the ring buffer.  It handles claiming the next sequence, getting the current(uninitialised)
        /// event from the ring buffer and publishing the claimed sequence after translation.
        /// <para/>
        /// With this call the data that is to be inserted into the ring buffer will be a field (either explicitly or captured anonymously),
        /// therefore this call will require an instance of the translator for each value that is to be inserted into the ring buffer.
        /// </summary>
        /// <param name="translators">The user specified translation for each event</param>
        /// <param name="batchStartsAt">The first element of the array which is within the batch.</param>
        /// <param name="batchSize">The actual size of the batch.</param>
        virtual void PublishEvents(IEventTranslator<T> *translators, int batchStartsAt, int batchSize) = 0;

        /// <summary>
        /// Attempts to publish multiple events to the ring buffer.  It handles claiming the next sequence, getting the current(uninitialised)
        /// event from the ring buffer and publishing the claimed sequence after translation.Will return false if specified capacity was not available.
        /// </summary>
        /// <param name="translators">The user specified translation for each event</param>
        /// <returns>true if the value was published, false if there was insufficient capacity</returns>
        virtual bool TryPublishEvents(IEventTranslator<T> *translators) = 0;

        /// <summary>
        /// Attempts to publish multiple events to the ring buffer.  It handles claiming the next sequence, getting the current(uninitialised)
        /// event from the ring buffer and publishing the claimed sequence after translation.Will return false if specified capacity was not available.
        /// </summary>
        /// <param name="translators">The user specified translation for each event</param>
        /// <param name="batchStartsAt">The first element of the array which is within the batch.</param>
        /// <param name="batchSize">The actual size of the batch.</param>
        /// <returns>true if the value was published, false if there was insufficient capacity</returns>
        virtual bool TryPublishEvents(IEventTranslator<T> *translators,
                                      const int& batchStartsAt, const int& batchSize) = 0;

        /// <summary>
        /// Allows one user supplied argument per event.
        /// </summary>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="arg0">A user supplied argument.</param>
        /// <typeparam name="A">Class of the user supplied argument</typeparam>
        template <typename A>
        virtual void PublishEvents(IEventTranslatorOneArg<T, A> *translator, A *arg0) = 0;

        /// <summary>
        /// Allows one user supplied argument per event.
        /// </summary>
        /// <typeparam name="A">Class of the user supplied argument</typeparam>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="batchStartsAt">The first element of the array which is within the batch.</param>
        /// <param name="batchSize">The actual size of the batch.</param>
        /// <param name="arg0">A user supplied argument.</param>
        template <typename A>
        virtual void PublishEvents(IEventTranslatorOneArg<T, A> *translator,
                                   const int& batchStartsAt, const int& batchSize, A *arg0) = 0;

        /// <summary>
        /// Allows one user supplied argument per event.
        /// </summary>
        /// <typeparam name="A">Class of the user supplied argument</typeparam>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="arg0">A user supplied argument.</param>
        /// <returns>true if the value was published, false if there was insufficient capacity</returns>
        template <typename A>
        virtual bool TryPublishEvents(IEventTranslatorOneArg<T, A> *translator, A *arg0) = 0;

        /// <summary>
        /// Allows one user supplied argument per event.
        /// </summary>
        /// <typeparam name="A">Class of the user supplied argument</typeparam>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="batchStartsAt">The first element of the array which is within the batch.</param>
        /// <param name="batchSize">The actual size of the batch.</param>
        /// <param name="arg0">A user supplied argument.</param>
        /// <returns>true if the value was published, false if there was insufficient capacity</returns>
        template <typename A>
        virtual bool TryPublishEvents(IEventTranslatorOneArg<T, A> *translator,
                                      const int batchStartsAt, const int& batchSize, A *arg0) = 0;

        /// <summary>
        /// Allows two user supplied arguments per event.
        /// </summary>
        /// <typeparam name="A">Class of the user supplied argument</typeparam>
        /// <typeparam name="B">Class of the user supplied argument</typeparam>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="arg0">A user supplied argument.</param>
        /// <param name="arg1">A user supplied argument.</param>
        template <typename A, typename B>
        virtual void PublishEvents(IEventTranslatorTwoArg<T, A, B> *translator,
                                   A *arg0, B *arg1) = 0;

        /// <summary>
        /// Allows two user supplied arguments per event.
        /// </summary>
        /// <typeparam name="A">Class of the user supplied argument</typeparam>
        /// <typeparam name="B">Class of the user supplied argument</typeparam>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="batchStartsAt">The first element of the array which is within the batch.</param>
        /// <param name="batchSize">The actual size of the batch.</param>
        /// <param name="arg0">A user supplied argument.</param>
        /// <param name="arg1">A user supplied argument.</param>
        template <typename A, typename B>
        virtual void PublishEvents(IEventTranslatorTwoArg<T, A, B> *translator,
                                   const int& batchStartsAt, const int& batchSize,
                                   A *arg0, B *arg1) = 0;

        /// <summary>
        /// Allows two user supplied arguments per event.
        /// </summary>
        /// <typeparam name="A">Class of the user supplied argument</typeparam>
        /// <typeparam name="B">Class of the user supplied argument</typeparam>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="arg0">A user supplied argument.</param>
        /// <param name="arg1">A user supplied argument.</param>
        /// <returns>true if the value was published, false if there was insufficient capacity</returns>
        template <typename A, typename B>
        virtual bool TryPublishEvents(IEventTranslatorTwoArg<T, A, B> *translator,
                                      A *arg0, B *arg1) = 0;

        /// <summary>
        /// Allows two user supplied arguments per event.
        /// </summary>
        /// <typeparam name="A">Class of the user supplied argument</typeparam>
        /// <typeparam name="B">Class of the user supplied argument</typeparam>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="batchStartsAt">The first element of the array which is within the batch.</param>
        /// <param name="batchSize">The actual size of the batch.</param>
        /// <param name="arg0">A user supplied argument.</param>
        /// <param name="arg1">A user supplied argument.</param>
        /// <returns>true if the value was published, false if there was insufficient capacity</returns>
        template <typename A, typename B>
        virtual bool TryPublishEvents(IEventTranslatorTwoArg<T, A, B> *translator,
                                      const int& batchStartsAt, const int& batchSize,
                                      A *arg0, B *arg1) = 0;

        /// <summary>
        /// Allows three user supplied arguments per event.
        /// </summary>
        /// <typeparam name="A">Class of the user supplied argument</typeparam>
        /// <typeparam name="B">Class of the user supplied argument</typeparam>
        /// <typeparam name="C">Class of the user supplied argument</typeparam>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="arg0">A user supplied argument.</param>
        /// <param name="arg1">A user supplied argument.</param>
        /// <param name="arg2">A user supplied argument.</param>
        template <typename A, typename B, typename C>
        virtual void PublishEvents(IEventTranslatorThreeArg<T, A, B, C> *translator,
                                   A *arg0, B *arg1, C *arg2) = 0;

        /// <summary>
        /// Allows three user supplied arguments per event.
        /// </summary>
        /// <typeparam name="A">Class of the user supplied argument</typeparam>
        /// <typeparam name="B">Class of the user supplied argument</typeparam>
        /// <typeparam name="C">Class of the user supplied argument</typeparam>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="batchStartsAt">The first element of the array which is within the batch.</param>
        /// <param name="batchSize">The actual size of the batch.</param>
        /// <param name="arg0">A user supplied argument.</param>
        /// <param name="arg1">A user supplied argument.</param>
        /// <param name="arg2">A user supplied argument.</param>
        template <typename A, typename B, typename C>
        virtual void PublishEvents(IEventTranslatorThreeArg<T, A, B, C> *translator,
                                   const int& batchStartsAt, const int& batchSize,
                                   A *arg0, B *arg1, C *arg2) = 0;

        /// <summary>
        /// Allows three user supplied arguments per event.
        /// </summary>
        /// <typeparam name="A">Class of the user supplied argument</typeparam>
        /// <typeparam name="B">Class of the user supplied argument</typeparam>
        /// <typeparam name="C">Class of the user supplied argument</typeparam>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="arg0">A user supplied argument.</param>
        /// <param name="arg1">A user supplied argument.</param>
        /// <param name="arg2">A user supplied argument.</param>
        /// <returns>true if the value was published, false if there was insufficient capacity</returns>
        template <typename A, typename B, typename C>
        virtual bool TryPublishEvents(IEventTranslatorThreeArg<T, A, B, C> *translator,
                                      A *arg0, B *arg1, C *arg2) = 0;

        /// <summary>
        /// Allows three user supplied arguments per event.
        /// </summary>
        /// <typeparam name="A">Class of the user supplied argument</typeparam>
        /// <typeparam name="B">Class of the user supplied argument</typeparam>
        /// <typeparam name="C">Class of the user supplied argument</typeparam>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="batchStartsAt">The first element of the array which is within the batch.</param>
        /// <param name="batchSize">The actual size of the batch.</param>
        /// <param name="arg0">A user supplied argument.</param>
        /// <param name="arg1">A user supplied argument.</param>
        /// <param name="arg2">A user supplied argument.</param>
        /// <returns>true if the value was published, false if there was insufficient capacity</returns>
        template <typename A, typename B, typename C>
        virtual bool TryPublishEvents(IEventTranslatorThreeArg<T, A, B, C> *translator,
                                      const int& batchStartsAt, const int& batchSize,
                                      A *arg0, B *arg1, C *arg2) = 0;

        /// <summary>
        /// Allows a variable number of user supplied arguments per event.
        /// </summary>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="args">User supplied arguments, one Object[] per event.</param>
        virtual void PublishEvents(IEventTranslatorVararg<T> *translator, ...) = 0;

        /// <summary>
        /// Allows a variable number of user supplied arguments per event.
        /// </summary>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="batchStartsAt">The first element of the array which is within the batch.</param>
        /// <param name="batchSize">The actual size of the batch.</param>
        /// <param name="args">User supplied arguments, one Object[] per event.</param>
        virtual void PublishEvents(IEventTranslatorVararg<T> *translator,
                                   const int& batchStartsAt, const int& batchSize, ...) = 0;

        /// <summary>
        /// Allows a variable number of user supplied arguments per event.
        /// </summary>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="args">User supplied arguments, one Object[] per event.</param>
        /// <returns>true if the value was published, false if there was insufficient capacity</returns>
        virtual bool TryPublishEvents(IEventTranslatorVararg<T> *translator, ...) = 0;

        /// <summary>
        /// Allows a variable number of user supplied arguments per event.
        /// </summary>
        /// <param name="translator">The user specified translation for the event</param>
        /// <param name="batchStartsAt">The first element of the array which is within the batch.</param>
        /// <param name="batchSize">The actual size of the batch.</param>
        /// <param name="args">User supplied arguments, one Object[] per event.</param>
        /// <returns>true if the value was published, false if there was insufficient capacity</returns>
        virtual bool TryPublishEvents(IEventTranslatorVararg<T> *translator,
                                      const int& batchStartsAt, const int& batchSize, ...) = 0;
    };
}

#endif //DISRUPTOR_PP_IEVENTSINK_H
