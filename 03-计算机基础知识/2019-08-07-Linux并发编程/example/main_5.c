/*
 * 线程互斥锁
 */
#include <stdio.h>
#include <pthread.h>

char buffer;
int buffer_has_item=0;
pthread_mutex_t mutex;
void writerFunc(){
        while(1) {
                /* 锁定互斥锁*/
                pthread_mutex_lock (&mutex);
                buffer_has_item++;
                printf("write %d\n",buffer_has_item);
                /* 打开互斥锁*/
                pthread_mutex_unlock(&mutex);
                usleep(1000*200);
        }
}
void *readerFunc(void *ptr){
        while(1) {
                pthread_mutex_lock(&mutex);
                if(buffer_has_item>0) {
                        printf("read %d\n", buffer_has_item);
                        buffer_has_item--;
                }
                pthread_mutex_unlock(&mutex);
                usleep(1000*500);
        }
}
int main(){
        pthread_t id;
        pthread_mutex_init (&mutex,NULL);
        pthread_create(&id, NULL,readerFunc, NULL);
        writerFunc();
        return 0;
}