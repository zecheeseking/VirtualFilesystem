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
            defines {"_DEBUG"}

        configuration "Release"
            targetdir "bin/release"

        configuration "vs*"
            flags { "Unicode", "Winmain"}
            defines {"WIN32"}

        configuration "gmake"
            targetdir "bin/debug"
            objdir "obj/debug"
            flags {"Unicode"}
            defines{"PLATFORM_LINUX"}


        files{
            "main.cpp"
        }

        language "C++"
