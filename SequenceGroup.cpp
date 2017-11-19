//
// Created by ubuntu on 17-11-19.
//

#include "SequenceGroup.h"

int64_t Disruptor::SequenceGroup::GetValue() {
    auto seqArrWrpr = _seqArrWrpr.load(std::memory_order_acquire);
    auto length = seqArrWrpr.GetLength();
    auto sequences = seqArrWrpr.GetValue();
    return Utils::GetMinimumSequence(sequences, length);
}

void Disruptor::SequenceGroup::SetValue(const int64_t &value) {
    auto seqArrWrpr = _seqArrWrpr.load(std::memory_order_acquire);
    auto length = seqArrWrpr.GetLength();
    auto sequences = seqArrWrpr.GetValue();

    for(auto i = 0; i < length; i++) {
        sequences[i]->SetValue(value);
    }
    _seqArrWrpr.store(seqArrWrpr, std::memory_order_release);
}

bool Disruptor::SequenceGroup::CompareAndSet(int64_t &expectedSequence, int64_t &nextSequence) {
    throw "Not supported exception.";
}

int64_t Disruptor::SequenceGroup::IncrementAndGet() {
    throw "Not supported exception.";
}

int64_t Disruptor::SequenceGroup::AddAndGet(const int64_t &val) {
    throw "Not supported exception.";
}

void Disruptor::SequenceGroup::Add(Disruptor::Interfaces::ISequence *sequence) {

    bool NotCAS = true;
    for(; NotCAS;) {

        auto oldSeqArrWrpr = _seqArrWrpr.load(std::memory_order_acquire);
        auto oldLength = oldSeqArrWrpr.GetLength();
        auto oldSequences = oldSeqArrWrpr.GetValue();

        SequenceArrayWrapper newSeqArrWrpr = oldSeqArrWrpr;
        auto newLength = newSeqArrWrpr.GetLength() + 1;
        auto newSequences = newSeqArrWrpr.GetValue();

        newSequences[oldLength] = sequence;

        newSeqArrWrpr.SetLength(newLength);

        NotCAS = !_seqArrWrpr.compare_exchange_weak(oldSeqArrWrpr, newSeqArrWrpr);
    }
}

bool Disruptor::SequenceGroup::Remove(Disruptor::Interfaces::ISequence *sequence) {
    return SequenceGroups::RemoveSequence(std::ref(_seqArrWrpr), sequence);
}
