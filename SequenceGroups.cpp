//
// Created by ubuntu on 17-11-16.
//

#include "SequenceGroups.h"

bool Disruptor::SequenceGroups::RemoveSequence(std::atomic<Disruptor::SequenceArrayWrapper> &seqArrWrper,
                                               Disruptor::Interfaces::ISequence *sequence) {
    return false;
}

void Disruptor::SequenceGroups::AddSequences(std::atomic<Disruptor::SequenceArrayWrapper> &seqArrWrper,
                                             Disruptor::Interfaces::ICursored *cursor, ...) {

}
