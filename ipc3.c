#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int fd[2];
    pid_t pid;
    int nums[2];

    pipe(fd);
    pid = fork();
    srand(time(NULL));

    if (pid == 0) { // HIJO
        close(fd[0]);
        nums[0] = rand() % 50 + 1;
        nums[1] = rand() % 50 + 1;
        write(fd[1], nums, sizeof(nums));
        close(fd[1]);
    } else { // PADRE
        close(fd[1]);
        read(fd[0], nums, sizeof(nums));
        printf("%d + %d = %d\n", nums[0], nums[1], nums[0] + nums[1]);
        printf("%d - %d = %d\n", nums[0], nums[1], nums[0] - nums[1]);
        printf("%d * %d = %d\n", nums[0], nums[1], nums[0] * nums[1]);
        printf("%d / %d = %d\n", nums[0], nums[1], nums[0] / nums[1]);
        close(fd[0]);
    }
    return 0;
}
