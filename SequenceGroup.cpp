//
// Created by ubuntu on 17-11-19.
//

#include "SequenceGroup.h"

int64_t Disruptor::SequenceGroup::GetValue() {
    auto sequences = _seqArrWrpr.load(std::memory_order_acquire);
    //auto length = sequences.size();
    //auto sequences = seqArrWrpr.GetValue();
    return Utils::GetMinimumSequence(sequences.GetValue());
}

void Disruptor::SequenceGroup::SetValue(const int64_t &value) {
    auto seqArrWrpr = _seqArrWrpr.load(std::memory_order_acquire);
    auto sequences = seqArrWrpr.GetValue();
    auto length = sequences.size();

    for(auto i = 0; i < length; i++) {
        sequences[i]->SetValue(value);
    }
    _seqArrWrpr.store(sequences, std::memory_order_release);
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
        auto oldSequences = oldSeqArrWrpr.GetValue();
        auto oldLength = oldSequences.size();

        SequenceArrayWrapper newSeqArrWrpr = oldSeqArrWrpr;
        //auto newLength = newSeqArrWrpr.GetLength() + 1;
        auto newSequences = &(newSeqArrWrpr.GetValue());

        newSequences->emplace_back(sequence);

        NotCAS = !_seqArrWrpr.compare_exchange_weak(oldSeqArrWrpr, newSeqArrWrpr);
    }
}

bool Disruptor::SequenceGroup::Remove(Disruptor::Interfaces::ISequence *sequence) {
    return false; // SequenceGroups::RemoveSequence(std::ref(_seqArrWrpr), sequence);
}

int Disruptor::SequenceGroup::Size() {
    return 0 ; // _seqArrWrpr.load(std::memory_order_acquire).GetLength();
}

void Disruptor::SequenceGroup::AddWhileRunning(Disruptor::Interfaces::ICursored *cursored,
                                               Disruptor::Interfaces::ISequence *sequence) {
    //SequenceGroups::AddSequences(std::ref(_seqArrWrpr), cursored, sequence);
}
