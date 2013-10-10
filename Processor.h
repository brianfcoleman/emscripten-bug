#ifndef PROCESSOR_H_
#define PROCESSOR_H_

#include "StateMachine.h"

namespace test
{
  class Processor
  {
  public:

    Processor();

    ~Processor();

    bool handleFirstState();

    bool handleLastState();

    bool run();

    int result() const;

  private:

    int result_;

    StateMachine<Processor> stateMachine_;
  };

}

#endif
