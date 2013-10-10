#include "Processor.h"
#include <cstdlib>

namespace test
{
  Processor::Processor()
  : result_(0) {}

  Processor::~Processor() {}

  bool Processor::handleFirstState()
  {
    result_ += rand();
    return (result_ % 2 == 0);
  }

  bool Processor::handleLastState()
  {
    result_ += std::rand();
    return true;
  }

  bool Processor::run()
  {
    stateMachine_.setState(&Processor::handleFirstState);
    while (stateMachine_.state() != &Processor::handleLastState)
    {
      bool result = stateMachine_.handleState(this);
      if (result) {
        stateMachine_.setState(&Processor::handleLastState);
      }
    }
    return stateMachine_.handleState(this);
  }

  int Processor::result() const
  {
    return result_;
  }
}
