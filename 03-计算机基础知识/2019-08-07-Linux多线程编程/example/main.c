#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* increse_num(void* aa) {
    printf("11111111:%d\n",(int)mutex.__align);

    if (pthread_mutex_lock(&mutex) != 0) {
       perror("pthread_mutex_lock");
       exit(EXIT_FAILURE);
    }
    
    printf("22222222:%d\n",(int)mutex.__align);

    usleep(500*1000);

    printf("77777777:%d\n",(int)mutex.__align);

    if (pthread_mutex_unlock(&mutex) != 0) {
        perror("pthread_mutex_unlock");
        exit(EXIT_FAILURE);
    }

    printf("55555555:%d\n",(int)mutex.__align);
}

void* increse_num1(void* bb) {

    usleep(100*1000);

    pthread_mutex_init(&mutex, NULL);

    printf("33333333:%d\n",(int)mutex.__align);

    if (pthread_mutex_lock(&mutex) != 0) {
       perror("pthread_mutex_lock");
       exit(EXIT_FAILURE);
    }

    printf("44444444:%d\n",(int)mutex.__align);

    usleep(500*1000);

    if (pthread_mutex_unlock(&mutex) != 0) {
        perror("pthread_mutex_unlock");
        exit(EXIT_FAILURE);
    }

    printf("66666666:%d\n",(int)mutex.__align);
}


int main(){
    int ret;
    pthread_t thrd1, thrd2;
    pthread_mutex_init(&mutex, NULL);
    
    ret = pthread_create(&thrd1, NULL, increse_num, NULL);
    ret = pthread_create(&thrd2, NULL, increse_num1, NULL);

    pthread_join(thrd1, NULL);
    pthread_join(thrd2, NULL);
    //while(1);

    return 0;

}
