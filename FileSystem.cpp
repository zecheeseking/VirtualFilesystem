#include "FileSystem.h"

#if defined(PLATFORM_WIN)
    #include "FileSystem_Windows.hpp"
#elif defined(PLATFORM_LINUX)
    #include "FileSystem_Linux.hpp"
#else
    #include "FileSystem_Stub.hpp"
#endif