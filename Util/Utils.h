//
// Created by ubuntu on 17-11-19.
//

#ifndef DISRUPTOR_PP_UTILS_H
#define DISRUPTOR_PP_UTILS_H


// From Google C++ Standard, modified to use C++11 deleted functions.
// A macro to disallow the copy constructor and operator= functions.
#define DISALLOW_COPY_MOVE_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&) = delete;           \
  TypeName(const TypeName&&) = delete;          \
  void operator=(const TypeName&) = delete

#ifdef _MSC_VER_ // for MSVC
#define ALWAYS_INLINE __forceinline
#elif defined __GNUC__ // for gcc on Linux/Apple OS X
#define ALWAYS_INLINE __inline__ __attribute__((always_inline))
#else
#define ALWAYS_INLINE inline
#endif

#include <cstdint>
#include <climits>
#include <vector>
#include <xmmintrin.h>
#include "../Interfaces/ISequence.h"
#include "../Interfaces/IEventProcessor.h"

namespace Disruptor {
    class Utils {
    public:
        ALWAYS_INLINE static void CpuRelax()
        {
        #if (COMPILER == MVCC)
                    _mm_pause();
        #elif (COMPILER == GCC || COMPILER == LLVM)
                    asm("pause");
        #endif
        };

        static int CeilingNextPowerOfTwo(int x) {
          int r = 2;
          while(r < x) r <<= 1;
          return r;
        };

        static int Log2(int i) {
          int r = 0;
          while ((i >>= 1) != 0) ++r;
          return r;
        };

        static bool IsPowerOfTwo(int x) {
          return x > 0 && (x & (x -1)) == 0;
        };

        static int64_t GetMinimumSequence(const std::vector<Interfaces::ISequence*>& sequences) {
          int64_t minimum = LONG_MAX;

          for (Interfaces::ISequence* sequence_ : sequences) {
            const int64_t value = sequence_->GetValue();
            minimum = minimum < value ? minimum : value;
          }

          return minimum;
        };

        static std::vector<Interfaces::ISequence*> GetSequencesFor(const std::vector<Interfaces::IEventProcessor*> processors)
        {
            std::vector<Interfaces::ISequence*> sequences;
            for (int i = 0; i < processors.size(); i++)
            {
                sequences.emplace_back(processors[i]->GetSequence());
            }

            return sequences;
        }
    };
}

#endif //DISRUPTOR_PP_UTIL_H
