#include <stdio.h>
#include <string.h>
#include "virusFunc.h"
#include <dirent.h>
#include <stdlib.h>



int main(int argc, char * argv[]){

    // array of drives connected to computer
    char existDrivesArray[10][10] = {};
    int drivesArryLength = 0;
    // detect every drives and the array length
    detectDrives(existDrivesArray, &drivesArryLength); // will detect drives and the conut of drives
    printf("Detected Drives Length Is: %d\n", drivesArryLength);

    return 0;
}
