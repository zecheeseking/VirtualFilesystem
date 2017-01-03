solution "PlatformDevelopment_FileSystem"
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
            flags {"Unicode"}
            defines {"_DEBUG"}

        configuration "Release"
            flags {"Unicode"}
            targetdir "bin/release"

        configuration "vs*"
            flags { "Unicode", "Winmain"}
            defines {"PLATFORM_WIN"}

        configuration "gmake"
            targetdir "bin/debug"
            flags {"Unicode"}
            defines{"PLATFORM_LINUX"}


        files{
            "main.cpp"
        }

        language "C++"
