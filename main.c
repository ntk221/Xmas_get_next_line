#include <stdio.h>
#include <unistd.h>

int main(void)
{
    write(1, "-->", 4);
    while(1)
    {
    }
    return (0);
}