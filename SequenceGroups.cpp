//
// Created by ubuntu on 17-11-16.
//

#include "SequenceGroups.h"
/*
bool Disruptor::SequenceGroups::RemoveSequence(std::atomic<Disruptor::SequenceArrayWrapper> &seqArrWrper,
                                               Disruptor::Interfaces::ISequence *sequence) {

    bool NotCAS = true;
    for(; NotCAS;) {

        auto oldSeqArrWrpr = seqArrWrper.load(std::memory_order_acquire);
        auto oldLength = oldSeqArrWrpr.GetLength();
        auto oldSequences = oldSeqArrWrpr.GetValue();

        SequenceArrayWrapper newSeqArrWrpr = oldSeqArrWrpr;
        auto newLength = newSeqArrWrpr.GetLength() + 1;
        auto newSequences = newSeqArrWrpr.GetValue();

        newSequences[oldLength] = sequence;

        newSeqArrWrpr.SetLength(newLength);

        NotCAS = !seqArrWrper.compare_exchange_weak(oldSeqArrWrpr, newSeqArrWrpr);
    }*/

    //return false;
//}

//void Disruptor::SequenceGroups::AddSequences(std::atomic<Disruptor::SequenceArrayWrapper> &seqArrWrper,
  //                                           Disruptor::Interfaces::ICursored *cursor, ...) {

//}
/*
int Disruptor::SequenceGroups::CountMatching(Disruptor::Interfaces::ISequence **sequences, int length,
                                             Disruptor::Interfaces::ISequence *sequence) {
    int numToRemove = 0;

    for(int i = 0; i < length; i++) {
        if( *(sequences + i) == sequence) {
            numToRemove++;
        }
    }

    return numToRemove;
}
*/