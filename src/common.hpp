#pragma once
#pragma warning(disable : 4996) // CRT_SECURE_NO_WARNINGS

#define ll long long
#if defined(_WIN32)
#define PLATFORM_NAME "windows"
#elif defined(_WIN64)
#define PLATFORM_NAME "windows"
#elif defined(__linux__)
#define PLATFORM_NAME "linux"
#else
#define PLATFORM_NAME NULL
#endif

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <array>
#include <cmath>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <array>

#include "logging.hpp"

/*
 * Made for: Linux, Windows
 * Compiled with: clang++ version 10.0.0
 */

namespace Common
{
    inline const char *GetOperatingSystemName()     {
        return (PLATFORM_NAME == NULL) ? "" : PLATFORM_NAME;
    }

    inline std::string GetSystemOutput(const char *cmd)     {
        std::array<char, 128> buffer;
        std::string result;
        #if defined(_WIN32)
        std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
        #elif defined(_WIN64)
        std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
        #elif defined(__linux__)
        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
        #endif

        while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
            result += buffer.data();
        if(result[result.length()-1] == '\n') 
            result.pop_back();
        return result;
    }

    inline void PrintSystemInformation()    {
        Common::log::info("OS Name     -> {}", GetOperatingSystemName());

        if(strcmp(PLATFORM_NAME, "linux") == 0) {
            Common::log::info("OS Version  -> {}", GetSystemOutput("cat /etc/os-release | grep VERSION="));
            Common::log::info("Username    -> {}", GetSystemOutput("whoami"));
        } else {
            Common::log::info("OS Version  -> {}", GetSystemOutput("Get-WmiObject -Class win32_OperatingSystem | Select Version, BuildNumber"));
        }
    }
}
