#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_

namespace test
{
  template<typename T>
  class StateMachine
  {
  public:
    typedef bool (T::* HandleState)();

    StateMachine()
    : handleState_(0) {}

    ~StateMachine() {}

    bool handleState(T* handler)
    {
      return (handler->*handleState_)();
    }

    HandleState state() const
    {
      return handleState_;
    }

    // If setState is inlined by the compiler the bug is triggered.
#if 0
    void setState(HandleState handleState) __attribute__((noinline))
#else
    void setState(HandleState handleState)
#endif
    {
      handleState_ = handleState;
    }

  private:
    HandleState handleState_;
  };
}

#endif
