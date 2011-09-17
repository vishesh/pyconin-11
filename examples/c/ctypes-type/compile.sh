gcc -c -o libsample.o -fPIC libsample.c 
gcc -shared -Wl,-soname,libsample.so.1 -o libsample.so.1 libsample.o

