#include <windows.h>
#include <time.h>


int main()
{
    clock_t start, end;
    start = clock();


    // Open the drive to be formatted
    HANDLE drive = CreateFile("\\\\.\\D:", GENERIC_READ | GENERIC_WRITE,
                               FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
                               OPEN_EXISTING, 0, NULL);
    if (drive == INVALID_HANDLE_VALUE)
    {
        // An error occurred
        return 1;
    }

    // Set up the format parameters
    FORMAT_PARAMETERS format_params;
    ZeroMemory(&format_params, sizeof(format_params));
    format_params.MediaType = F3_1Pt2_512;
    format_params.StartHeadNumber = 0;
    format_params.EndHeadNumber = 1;

    // Send the format command
    if (!DeviceIoControl(drive, FSCTL_FORMAT_EX, &format_params,
                         sizeof(format_params), NULL, 0, NULL, NULL))
    {
        // An error occurred
        CloseHandle(drive);
        return 1;
    }

    // Close the handle to the drive
    CloseHandle(drive);

    end = clock();
    double time_taken = ((double) end - start)/CLOCKS_PER_SEC;

    printf("Total format time is: %f\n", time_taken);
    return 0;
}