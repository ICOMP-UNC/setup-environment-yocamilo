#include <functions.h>
#include <stdio.h>
#include <static.h>
#include <shared.h>

int main(int argc, char* argv[])
{
    printf("Hello from main\n");

    functions();

    printf("Calling shared lib. I get: '%d'\n", shared_lib_function("Hi Shared"));
    printf("Calling static lib. I get: '%d'\n", static_lib_function("bye Static.."));

    return 0;
}
