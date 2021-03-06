solution "PlatDev_FileSystem"
    configurations{
      "Debug",
      "Release",
    }

    platforms{
        "x32",
        "x64",
        "Native",
    }

    location ""

    language "C++"

PROJ_DIR = path.getabsolute("..")

    project "PlatDev_FileSystem"
        kind "ConsoleApp"

        configuration "Debug"
            targetdir "bin/debug"
            objdir "obj/debug"
            defines {"_DEBUG"}
            flags {"Symbols"} -- This is required for Kernal32.lib dependency to allow for passing arguments. YAY.

        configuration "Release"
            targetdir "bin/release"

        configuration "vs*"
            flags { "Unicode", "Winmain"}
            defines {"PLATFORM_WIN", "WIN32"}

        configuration "gmake"
            targetdir "bin/debug"
            objdir "obj/debug"
            flags {"Unicode"}
            defines{"PLATFORM_LINUX", "CXX=g++ -std=c++11", "_DEBUG"}

            --This is needed as "configuration {}" allows defining of settings for all configurations. Like files!
        configuration {}

            files{
                "*.cpp",
                "*.hpp",
                "*.h"
            }

        language "C++"
