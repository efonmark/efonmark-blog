/*
 * 线程的数据处理
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sched.h>

//用户访问和获取线程变量。所有的线程都可以访问
pthread_key_t key;

void *run(void *ptr){
        int value=*(int *)ptr;
        int temp=1;
		printf("para:%d\n", value);
		
        //将temp的地址赋给key。
        pthread_setspecific (key, &temp);
        for(int i=0; i<3; i++) {
                //根据key获取对应的值
                int v=*(int *)pthread_getspecific(key);
                usleep(1000 * 100);
				printf("run key value:%d\n", v);
        }
        return 0;
}

void *run2(void *ptr){
        int temp=2;
        pthread_setspecific (key, &temp);
        for(int i=0; i<3; i++) {
                int v=*(int *)pthread_getspecific(key);
                usleep(1000*100);
                printf("run2 key value:%d\n", v);
        }
        return 0;
}

int main(){
        //创建key
        pthread_key_create(&key,NULL);
        int ret=0;
        int value=10;
		
        pthread_t id;
        pthread_attr_t attr;
        struct sched_param param;
        //初始化
        pthread_attr_init(&attr);
        //设置相关属性
        pthread_attr_setscope (&attr,PTHREAD_SCOPE_PROCESS);
        //获取线程优先级参数
        pthread_attr_getschedparam(&attr,&param);
		printf("param.sched_priority:%d\n", param.sched_priority);
        //设置优先级
        param.sched_priority=10;
        pthread_attr_setschedparam(&attr,&param);
        ret=pthread_create(&id,&attr,run,&value);
        if(ret) {
				printf("create thread failed\n");
                return 0;
        }
		
        pthread_t id2;
        ret=pthread_create(&id2,NULL,run2,NULL);
        if(ret) {
				printf("create thread 2 failed\n");
                return 0;
        }
        pthread_join(id,NULL);
        pthread_join(id2,NULL);
        pthread_key_delete(key);
        return 0;
}