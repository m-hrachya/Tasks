#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int get_line_count(int fd) {
    int count = 0;
    char symbol = 0;
    while (read(fd, &symbol, 1)) {
        if (symbol == '\n') ++count;
    }
    lseek(fd, 0, SEEK_SET);
    return count + 1;
}

int main(int argc, char * argv[]) {
    size_t size = getpagesize();
    int fd = open("tmp.txt", O_RDWR);
    assert(fd >= 0);
    int line = argc == 1 ? 10 : atoi(argv[1]);
    int line_count = get_line_count(fd);
    char tmp = 0;
    int skip_lines = line_count - line;
    while (skip_lines > 0) {
        read(fd, &tmp, 1);
        if (tmp == '\n') --skip_lines;
    }
    while (read(fd, &tmp, 1)) {
        write(STDOUT_FILENO, &tmp, 1);
    }
    printf("\n");
    close(fd);
    return 0;
}