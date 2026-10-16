#include "utility/logging.h"
#include <spdlog/spdlog.h>


namespace slankengine::logging {


    void log(const std::string message, const Severity severity) {

        //this is probably a bad way to do this
        //but I need a global logging system so
        //I can move on with my life
        switch (severity) {

            case(Severity::INFO) : spdlog::info(message); break;
            case(Severity::DEBUG) : spdlog::debug(message); break;
            case(Severity::WARNING) : spdlog::warn(message); break;
            case(Severity::ERROR) : spdlog::error(message); break;
            case(Severity::TRACE) : spdlog::trace(message); break;

        }
    }


}