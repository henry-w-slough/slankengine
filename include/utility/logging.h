#include <string>


/* Simple logging module made for consistent global error, warning, and
 * other information logging.
 */
namespace slankengine::logging {

    enum class Severity {
        TRACE,
        DEBUG,
        INFO,
        WARNING,
        ERROR
    };

    /**
     * Logs the given message immediately to the console.
     * The severity given determines what log type is outputted.
     */
    void log(const std::string message, const Severity severity);

}