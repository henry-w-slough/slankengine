#include "utility/logging.h"
#include <spdlog/spdlog.h>


namespace slankengine::logging {


    void log(const std::string message, const Severity severity) {

        //this is probably a bad way to do this
        //but I need a global logging system so
        //I can move on with my life
        switch (severity) {

            case(Severity::INFO) : spdlog::info(message);
            case(Severity::DEBUG) : spdlog::debug(message);
            case(Severity::WARNING) : spdlog::warn(message);
            case(Severity::ERROR) : spdlog::error(message);
            case(Severity::TRACE) : spdlog::trace(message);

        }
    }


}