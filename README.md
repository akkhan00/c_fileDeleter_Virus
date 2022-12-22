# File Deleter Virus in C
this virus will delete the files in all drives except c:

## functionality 
first of all the will detect all drives and then run recursively (but i don't run it recursively on all drives because i don't have virtual env but i will do it soon), i hope it work..
i have also made a function which will copy picture to target directory which you want and then set the desktop wallpaper to that picture when the deletion is finished.

## exceptions
first of all i implement the threading functionality to remove recursively but it's remove half drives item and some of them remain. so i removed the threading functionality but i will try again!.

# Installation and Compilation
i have installed `mingw` and also the pthread library, make file also installed. so you just type

```bash
make
```
this will compile the hole file and make the compile version named `ak07.exe`. now you read to run and destroy(format) the drives except c:/.

# Youtube Channel
[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/YOUTUBE_VIDEO_ID_HERE/0.jpg)](https://www.youtube.com/watch?v=YOUTUBE_VIDEO_ID_HERE)