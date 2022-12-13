#include <stdio.h>

int main(){
  if(remove("resume.txt")==0){
    printf("Deleted file successfully\n");
  }else{
    printf("Unable to delete the file\n");
  }
}
