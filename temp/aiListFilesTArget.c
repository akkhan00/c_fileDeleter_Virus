// #include <Windows.h>
// #include <stdio.h>

// int main()
// {
//     // Set the directory to search
//     char directory[] = "..  \\";

//     // Find the first file in the directory
//     WIN32_FIND_DATA find_data;
//     HANDLE find_handle = FindFirstFile(directory, &find_data);
//     if (find_handle == INVALID_HANDLE_VALUE)
//     {
//         // An error occurred
//         return 1;
//     }

//     // Print the name of the first file
//     printf("%s\n", find_data.cFileName);

//     // Find the rest of the files in the directory
//     while (FindNextFile(find_handle, &find_data))
//     {
//         printf("%s\n", find_data.cFileName);
//     }

//     // Close the handle to the search
//     FindClose(find_handle);

//     return 0;
// }


#include <windows.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    // Check that a directory was specified
    if (argc < 2)
    {
        printf("Error: No directory specified.\n");
        return 1;
    }

    // Build the search pattern
    char search_pattern[MAX_PATH];
    sprintf(search_pattern, "%s\\*", argv[1]);

    // Find the first file in the directory
    WIN32_FIND_DATA find_data;
    HANDLE find_handle = FindFirstFile(search_pattern, &find_data);
    if (find_handle == INVALID_HANDLE_VALUE)
    {
        printf("Error: No files found in directory.\n");
        return 1;
    }

    // Print the name of the first file
    printf("%s\n", find_data.cFileName);

    // Find the rest of the files
    while (FindNextFile(find_handle, &find_data))
    {
        printf("%s\n", find_data.cFileName);
    }

    // Close the search handle
    FindClose(find_handle);

    return 0;
}