//
// Created by ubuntu on 17-11-20.
//

#ifndef DISRUPTOR_PP_SEQUENCEARRAYWRAPPER_H
#define DISRUPTOR_PP_SEQUENCEARRAYWRAPPER_H

#include <vector>
#include "Interfaces/ISequence.h"

namespace Disruptor {
    class SequenceArrayWrapper {
    private:
        std::vector<Interfaces::ISequence*> _sequences;
        //int _length = 0;

    public:
        SequenceArrayWrapper(){};
       SequenceArrayWrapper(std::vector<Interfaces::ISequence*>& sequences) : _sequences(sequences) {};
        std::vector<Interfaces::ISequence*> GetValue() {
            return _sequences;
        }

        int GetLength() {
            return _sequences.size();
        }

        void SetValue(std::vector<Interfaces::ISequence*>& sequences) {
            _sequences = sequences;
        }

        void Add(Interfaces::ISequence* sequence) {
            _sequences.emplace_back(sequence);
        }

    };
}

#endif //DISRUPTOR_PP_SEQUENCEARRAYWRAPPER_H
