#include <memory>
#include "interface.h"
#include "AImpl.h"
#include "BImpl.h"

int main() {
  std::unique_ptr<Interface> f(new AImpl());
  f->do_something();
  f.reset(new BImpl());
  f->do_something();
  return 0;
}
