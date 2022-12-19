// #include <stdio.h>
// #include <stdlib.h>

// int main(void){
// 	printf("%s\n", getenv("USERPROFILE")); // there is some bug to retreive the value
// 	return 0;
// }


#include <windows.h>
#include <stdio.h>

int main()
{
    // char username[256];
    // DWORD username_size = sizeof(username);

    // if (GetUserName(username, &username_size))
    // {
    //     // The user name was retrieved successfully
    //     printf("User name: %s\n", username);
    // }
    // else
    // {
    //     // An error occurred while retrieving the user name
    //     // Handle the error here...
    // }

	printf("[home]: %s\n", getenv("PATH"));

    return 0;
}
