CC_X64 := x86_64-w64-mingw32-gcc

CFLAGS  := $(CFLAGS) -Os -fno-asynchronous-unwind-tables -fno-exceptions -fPIC 
LFLAGS := $(LFLAGS) -Wl,-s,--no-seh,--enable-stdcall-fixup
LDFLAGS := --no-seh --enable-stdcall-fixup -r -S

default:
	$(CC_X64) -c copyunlocker.c $(CFLAGS)  $(LFLAGS) -o copyunlocker.x64.o

test: 
	$(CC_X64) copyunlocker.c $(CFLAGS)  $(LFLAGS) -o copyunlocker.exe