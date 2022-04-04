#include "logging.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

namespace Common {
namespace log {
    spdlog::logger& getLogger() {
        static std::shared_ptr<spdlog::logger> logger = spdlog::stdout_color_mt("common::log::spdlog");
        return *logger;
    }
}
}