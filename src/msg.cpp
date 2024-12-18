#include "msg.h"

#include <iostream>
#include <ostream>



namespace Msg {

  int verbosity = 1;

  void voutput(const char* format, fmt::format_args args) {
    if (output()) {
      std::cout << fmt::vformat(format, args) << std::endl;
    }
  }

  void vdetail(const char* format, fmt::format_args args) {
    if (detail()) {
      std::cout << fmt::vformat(format, args) << std::endl;
    }
  }

  void vdebug(const char* format, fmt::format_args args) {
    if (debug()) {
      std::cout << fmt::vformat(format, args) << std::endl;
    }
  }

  void verror(const char* format, fmt::format_args args) {
      std::cerr << fmt::vformat(format, args) << std::endl;
  }


  std::runtime_error vruntime_error(const char* format, fmt::format_args args) {
    return std::runtime_error(fmt::vformat(format, args));
  }

  std::system_error vsystem_error(const char* format, fmt::format_args args) {
    auto ec = std::error_code(errno, std::generic_category());
    return std::system_error(ec, fmt::vformat(format, args));
  }

}

