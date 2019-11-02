#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *run(void *ptr)
{
    int i = 0;
    for(i = 0; i < 3; i++) {
        sleep(1);
        printf("hello world!%d\n", i);
    }
    return 0;
}

int main()
{
    pthread_t id;
    int ret = 0;
    ret = pthread_create(&id, NULL, run, NULL);
    if(ret) {
        printf("create thread failed\n");
        return -1;
    } else {
        printf("create thread id:%lu\n", id);
    }

    pthread_join(id, NULL);
    return 0;
}
