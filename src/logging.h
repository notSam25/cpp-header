#include <spdlog/spdlog.h>

namespace Common {
namespace log {
    spdlog::logger& getLogger();

    template<typename... Args>
    void trace(spdlog::format_string_t<Args...> fmt, Args &&... args) {
        getLogger().trace(fmt, std::forward<Args>(args)...);
    }

    template<typename... Args>
    void debug(spdlog::format_string_t<Args...> fmt, Args &&... args) {
        getLogger().debug(fmt, std::forward<Args>(args)...);
    }

    template<typename... Args>
    void info(spdlog::format_string_t<Args...> fmt, Args &&... args) {
        getLogger().info(fmt, std::forward<Args>(args)...);
    }

    template<typename... Args>
    void warn(spdlog::format_string_t<Args...> fmt, Args &&... args) {
        getLogger().warn(fmt, std::forward<Args>(args)...);
    }

    template<typename... Args>
    void error(spdlog::format_string_t<Args...> fmt, Args &&... args) {
        getLogger().error(fmt, std::forward<Args>(args)...);
    }

    template<typename... Args>
    void critical(spdlog::format_string_t<Args...> fmt, Args &&... args) {
        getLogger().critical(fmt, std::forward<Args>(args)...);
    }

}
}