#include "common.hpp"

using DebugClass = Common::Debug;
DebugClass Debug{ true };


int main()  {
    
    Debug.LogData(DebugClass::LogType::Error,   "Some example text");
    Debug.LogData(DebugClass::LogType::Warning, "Some example text");
    Debug.LogData(DebugClass::LogType::Info,    "Some example text");
    Common::PrintSystemInformation();
    return 0;
}