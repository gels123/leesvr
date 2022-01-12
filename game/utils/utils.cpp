#include "utils.h"
#include <time.h>
	
int Utils::Test(int n, int m)
{
    return n/m;
}

int Utils::GetCurTime() 
{
    return (int)time(NULL);
}

int Utils::GetHour0Time(int ti)
{
    if (ti < 0) {
        ti = (int) time(NULL);
    }
    return (ti - ti%86400);
}