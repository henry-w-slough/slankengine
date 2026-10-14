#include <string>
#include <spdlog/spdlog.h>


namespace slankengine::logging {

    void add_log();
    void get_logs();
    void clear_log();

    enum class Severity {
        TRACE,
        DEBUG,
        INFO,
        WARNING,
        ERROR
    };

}