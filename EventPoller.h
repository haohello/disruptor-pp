//
// Created by ubuntu on 17-11-17.
//

#ifndef DISRUPTOR_PP_EVENTPOLLER_H
#define DISRUPTOR_PP_EVENTPOLLER_H

#include <functional>
#include <cstdint>
#include "Interfaces/IDataProvider.h"
#include "Interfaces/ISequencer.h"
#include "Interfaces/ISequence.h"
#include "FixedSequenceGroup.h"

namespace  Disruptor {

    enum PollState {
        Processing,
        Gating,
        Idle
    };

    template <typename T>
    class EventPoller {
        Interfaces::IDataProvider<T> *_dataProvider;
        Interfaces::ISequencer *_sequencer;
        Interfaces::ISequence *_sequence;
        Interfaces::ISequence *_gatingSequence;

    public:
        EventPoller(Interfaces::IDataProvider<T> *dataProvider,
                    Interfaces::ISequencer *sequencer,
                    Interfaces::ISequence *sequence,
                    Interfaces::ISequence *gatingSequence){
            _dataProvider = dataProvider;
            _sequencer = sequencer;
            _sequence = sequence;
            _gatingSequence = gatingSequence;
        };

        PollState Poll(std::function<bool(T, long, bool)> eventHandler) {
            int64_t currentSequence = _sequence->GetValue();
            int64_t nextSequence = currentSequence + 1;
            int64_t availableSequence = _sequencer->GetHighestPublishedSequence(nextSequence, _gatingSequence->GetValue());

            if(nextSequence <= availableSequence) {
                bool  processNextEvent;
                int64_t processedSequence = currentSequence;

                do {
                    T evt = _dataProvider[nextSequence];
                    processNextEvent = eventHandler(evt, nextSequence, nextSequence == availableSequence);
                    processedSequence = nextSequence;
                    nextSequence++;
                } while (nextSequence <= availableSequence && processNextEvent);

                _sequence->SetValue(processedSequence);
                return PollState::Processing;
            }
            else if(_sequencer->GetCursor() >= nextSequence) {
                return PollState::Gating;
            }
            else {
                return PollState::Idle;
            }
        };

        static EventPoller NewInstance(Interfaces::IDataProvider<T> *dataProvider,
                                       Interfaces::ISequencer *sequencer,
                                       Interfaces::ISequence *sequence,
                                       Interfaces::ISequence *cursorSequence,
                                       Interfaces::ISequence *gatingSequences, const int& gtLength) {
            Interfaces::ISequence *gatingSequence;
            //int gtLen = gatingSequences.size();
            if(gtLength == 0) {
                gatingSequence = cursorSequence;
            }
            else if(gtLength == 1) {
                gatingSequence = gatingSequences;
            }
            else {
                gatingSequence = FixedSequenceGroup(gatingSequences);
            }
            return EventPoller(dataProvider, sequencer, sequence, gatingSequence);
        };

        Interfaces::ISequence* GetSequence() {
            return _sequence;
        };
    };


}


#endif //DISRUPTOR_PP_EVENTPOLLER_H
