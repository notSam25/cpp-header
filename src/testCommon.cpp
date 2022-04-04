#include "common.hpp"
#include "spdlog/common.h"

int main()  {
    #ifdef NDEBUG
    
    #else
    Common::log::setLevel(spdlog::level::debug);
    #endif
    Common::PrintSystemInformation();
    Common::log::info("FYI, this is info");
    Common::log::error("This is an error");
    Common::log::debug("Here (this is a debug message)");
    Common::log::critical("PANIC!");
    Common::log::trace("trace...");
    Common::log::warn("This is a warning: the program is about to end!");
    return 0;
}