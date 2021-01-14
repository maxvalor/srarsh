#ifndef SERVICE_CLIENT_H_
#define SERVICE_CLIENT_H_

#include "service.h"
#include <memory.h>

namespace mini_ros {

class ServiceClient {
private:
  std::function<bool(std::shared_ptr<Service>, const char*)> f;

  friend class ThreadHandle;
  ServiceClient(std::function<bool(std::shared_ptr<Service>, const char*)> f) : f(f) {}
public:

  ServiceClient() : f(nullptr) {}
  virtual ~ServiceClient () {}

  template <typename T>
  bool call(std::shared_ptr<T> srv, size_t data_len = sizeof(T)) {
    if (f != nullptr ) {
      srv->header.data_len = data_len;
      return f(srv, typeid(T).name());
    }

    return false;
  }
};

} /* mini_ros */

#endif
