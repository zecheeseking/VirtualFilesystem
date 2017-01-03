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
            flags {"Unicode"}
            defines {"_DEBUG"}

        configuration "Release"
            flags {"Unicode"}
            targetdir "bin/release"

        configuration "vs*"
            flags { "Unicode", "Winmain","NoIncrementalLink"}
            defines {"PLATFORM_WIN", "WIN32"}

        configuration "gmake"
            targetdir "bin/debug"
            objdir "obj/debug"
            flags {"Unicode"}
            defines{"PLATFORM_LINUX"}


        files{
            "*.cpp",
            "*.hpp",
            "*.h",
        }

        language "C++"
