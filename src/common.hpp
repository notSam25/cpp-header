/* A simple header-only c++ header for commonly used stuff
 *
 * https://github.com/notSam25/cpp-header
 *
 * Copyright (c) 2022 notSam
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

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

#include <functional>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <array>
#include <cmath>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <array>
#include <vector>
#include <chrono>
#include <ctime>

namespace Common
{
    inline const char* GetOperatingSystemName()     {
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

        return result;
    }

    inline void PrintSystemInformation()    {
        printf("[dbg] OS Name     -> %s\n", GetOperatingSystemName());

        if(strcmp(PLATFORM_NAME, "linux") == 0) {
            printf("[dbg] OS Version  -> %s", GetSystemOutput("cat /etc/os-release | grep VERSION=").c_str());
            printf("[dbg] Username    -> %s", GetSystemOutput("whoami").c_str());
        } else
            printf("[dbg] OS Version  -> %s\n", GetSystemOutput("Get-WmiObject -Class win32_OperatingSystem | Select Version, BuildNumber").c_str()); 
    }

    class Debug {
    public:
        Debug(bool _UseLogFile = true) : UseLogFile(_UseLogFile) {}
        enum class LogType {
            Error = 0,
            Warning,
            Info
        };
        void LogData(LogType type, const std::string &data)
        {
            switch (type)
            {
            case LogType::Error:
                std::cout << "\033[1;31m[!]\033[0m " << data << std::endl;
                break;
            case LogType::Warning:
                std::cout << "\033[1;33m[#]\033[0m " << data << std::endl;
                break;
            case LogType::Info:
                std::cout << "\033[1;34m[*]\033[0m " << data << std::endl;
                break;

            default:
                break;
            }
            if(UseLogFile)  {
                //Log data in file
            }
        }

    private:
        bool UseLogFile;
    };
}
