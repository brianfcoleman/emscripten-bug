#include "Process.h"
#include "Processor.h"

#if defined(__cplusplus)
extern "C"
{
#endif

int runProcess()
{
  test::Processor processor;
  processor.run();
  return processor.result();
}

#if defined(__cplusplus)
}
#endif
