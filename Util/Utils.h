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

#endif //DISRUPTOR_PP_UTIL_H
