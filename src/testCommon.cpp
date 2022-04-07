#include "common.hpp"
using DebugClass = Common::Debug;
DebugClass Debug{true};

int main()
{
    Debug.LogData(DebugClass::LogType::Info, "Started sorting names");

    std::vector<std::string> Names{"Joe", "Bob", "Jesse", "", "Martha", "James"};
    std::vector<std::string> tempNames;

    int index = 0;
    while ( index < Names.size() ) {

        if (strcmp(Names.at(index).c_str(), "") == 0)   {
            Debug.LogData(DebugClass::LogType::Error, "Invalid name");
            index++;
            continue;
        }
        Debug.LogData(DebugClass::LogType::Info, "Sorted name: " + Names.at(index));
        tempNames.push_back(Names.at(index));
        index++;
    }

    Names = tempNames;
    tempNames.clear();
    Debug.LogData(DebugClass::LogType::Warning, "Finished sorting name vector");
    Common::PrintSystemInformation();
    return 0;
}