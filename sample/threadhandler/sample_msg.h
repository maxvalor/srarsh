#ifndef SAMPLE_MSG_H_
#define SAMPLE_MSG_H_

#include <fountain/message.h>
#include "sample_msg.h"

struct SampleMsg : public ftn::Message {
  std::uint32_t* data;
  size_t len;

  SampleMsg() : data(nullptr) {}

  SampleMsg(SampleMsg&& t) {
    data = t.data;
    t.data = nullptr;
    len = t.len;
  }

  virtual ~SampleMsg() {
    if (data != nullptr) {
      delete[] data;
    }
  }
};
#endif
