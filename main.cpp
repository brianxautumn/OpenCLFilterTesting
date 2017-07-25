
#include <iostream>
#ifdef __APPLE__
#include <OpenCL/opencl.h>
#include <unistd.h>
#else
#include <CL/cl.h>
#endif

int main(int argc, const char * argv[]) {
    cl_int status;
    
    // Find the number of OpenCL platforms
    cl_uint num_platforms;
    status = clGetPlatformIDs(0, NULL, &num_platforms);
    
    if (num_platforms == 0)
    {
        printf("Found 0 platforms!\n");
        return EXIT_FAILURE;
    }
    
    printf("Found %i platforms\n", num_platforms);
    
    cl_platform_id platform[num_platforms];
    status = clGetPlatformIDs(num_platforms, platform, NULL);
    
    return 0;
}
