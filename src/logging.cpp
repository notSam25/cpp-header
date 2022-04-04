#include "logging.hpp"
#include "spdlog/common.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

namespace Common {
namespace log {
    spdlog::logger& getLogger() {
        static bool initialized = false;
        static std::shared_ptr<spdlog::logger> logger = spdlog::stdout_color_mt("common::log::spdlog");
        if(!initialized)
            logger->set_pattern("[%=8l] %^%v%$");
        return *logger;
    }

    void setLevel(spdlog::level::level_enum level) {
        getLogger().set_level(level);
    }
}
}