//
// Created by ubuntu on 17-11-17.
//

#include "Sequence.h"

int64_t Disruptor::Sequence::Value() {
    //fid.compare_exchange_strong()
    return value.load(std::memory_order_acquire);
}

void Disruptor::Sequence::SetValue(const int64_t& val) {
    value.store(val, std::memory_order_release);
}

bool Disruptor::Sequence::CompareAndSet(int64_t &expectedSequence, int64_t &nextSequence) {
    return value.compare_exchange_strong(expectedSequence, nextSequence);
}

int64_t Disruptor::Sequence::AddAndGet(const int64_t& val) {
    return value.fetch_add(val, std::memory_order_release) + val;
}

int64_t Disruptor::Sequence::IncrementAndGet() {
    return value.fetch_add(1, std::memory_order_release) + 1;
}
