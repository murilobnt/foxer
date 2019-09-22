#ifndef GS_EXIT_CALLBACKABLE_HPP
#define GS_EXIT_CALLBACKABLE_HPP

namespace gs {

class ExitCallbackable {
public:
  virtual void exit_callback(const float &delta_time) = 0;
};

} // namespace gs

#endif
