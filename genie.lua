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

    project "PlatformDevelopment_FileSystem"
        kind "ConsoleApp"

        configuration "Debug"
            targetdir "bin/debug"
            defines {"_DEBUG"}

        configuration "Release"
            targetdir "bin/release"

        configuration "vs*"
            flags { "Unicode", "Winmain"}
            defines {"WIN32"}

        files{
            "main.cpp"
        }

        language "C++"
