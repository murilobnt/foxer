#ifndef FOX_EXIT_CALLBACKABLE_HPP
#define FOX_EXIT_CALLBACKABLE_HPP

namespace fox {

class ExitCallbackable {
public:
  virtual void exit_callback(const float &delta_time,
                             const int &pos_on_vec = -1) = 0;
};

} // namespace fox

#endif
