include config.mk

all: libgoatio.so libgoatstring.so

libgoatio.so: ./include/io.h ./src/io.c
	$(CC) $(CFLAGS) -shared -o $@ -fPIC ./src/io.c

libgoatstring.so: ./include/strings.h ./src/strings.c
	$(CC) $(CFLAGS) -shared -o $@ -fPIC ./src/strings.c

install: all
	install -Dm 755 libgoatio.so $(DESTDIR)$(PREFIX)
	install -Dm 755 libgoatstring.so $(DESTDIR)$(PREFIX)

clean:
	rm -f libgoatio.so libgoatstring.so

.PHONY: all clean install
