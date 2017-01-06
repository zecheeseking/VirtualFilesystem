#include "File.h"

#if defined(PLATFORM_WIN)
    #include "File_Windows.hpp"
#elif defined(PLATFORM_LINUX)
    #include "File_Linux.hpp"
#else
    #include "File_Stub.hpp"
#endif
