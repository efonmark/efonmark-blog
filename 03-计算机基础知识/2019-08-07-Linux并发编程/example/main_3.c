#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *run(void *ptr)
{
    int value = *(int *)ptr;
    int i = 0;
    printf("para:%d\n", value);
    for(i = 0; i < 3; i++) {
        sleep(1);
        printf("hello world!%d\n", i);
    }
    return 0;
}

int main(){
    int value=10;
    int ret = 0;

    pthread_t id;

    pthread_attr_t attr;
    //初始化
    pthread_attr_init(&attr);
    //设置相关属性
    pthread_attr_setscope (&attr,PTHREAD_SCOPE_PROCESS);

    //获取线程优先级参数
    pthread_attr_getschedparam(&attr,&param);
    //设置优先级
    param.sched_priority=10;
    pthread_attr_setschedparam(&attr,&param);
    ret=pthread_create(&id,&attr,run,&value);
    if(ret) {
            printf("create thread failed ");
            return 0;
    }
    pthread_join(id,NULL);
    return 0;
}

