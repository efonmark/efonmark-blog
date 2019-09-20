/*
 * Linux 线程调度与优先级
 */
#include <stdio.h>
#include <pthread.h>
#include <sched.h>
#include <assert.h>

//打印当前的线程调度策略
static int get_thread_policy(pthread_attr_t *attr)
{
  int policy;
  int rs = pthread_attr_getschedpolicy(attr,&policy);
  assert(rs==0);
  switch(policy)
  {
  case SCHED_FIFO:
    printf("policy= SCHED_FIFO\n");
    break;
  case SCHED_RR:
    printf("policy= SCHED_RR\n");
    break;
  case SCHED_OTHER:
    printf("policy=SCHED_OTHER\n");
    break;
  default:
    printf("policy=UNKNOWN\n");
    break;
  }
  return policy;
}

//打印当前调度策略线程的最高和最低优先级
static void show_thread_priority(pthread_attr_t *attr,int policy)
{
  int priority = sched_get_priority_max(policy);
  assert(priority!=-1);
  printf("max_priority=%d\n",priority);
  priority= sched_get_priority_min(policy);
  assert(priority!=-1);
  printf("min_priority=%d\n",priority);
}

//打印当前线程的优先级
static int get_thread_priority(pthread_attr_t *attr)
{
  struct sched_param param;
  int rs = pthread_attr_getschedparam(attr,&param);
  assert(rs==0);
  printf("priority=%d\n",param.__sched_priority);
  return param.__sched_priority;
}

//设置线程线程的调度策略
static void set_thread_policy(pthread_attr_t *attr,int policy)
{
  int rs = pthread_attr_setschedpolicy(attr,policy);
  assert(rs==0);
  get_thread_policy(attr);
}

int main(void)
{
  pthread_attr_t attr;
  struct sched_param sched;
  int rs;
  rs = pthread_attr_init(&attr);
  assert(rs==0);

  //获取默认的线程调度策略
  printf("==    Show current configuration of priority    ==\n");
  int policy = get_thread_policy(&attr);
  show_thread_priority(&attr,policy);
  //打印当前线程的优先级
  printf("show priority of current thread\n");
  int priority = get_thread_priority(&attr);


   printf("==   Show different Scheduling method priority   ==\n");
  //获取SCHED_FIFO调度策略的最高和最低优先级
  printf("show SCHED_FIFO of priority:\n");
  show_thread_priority(&attr,SCHED_FIFO);

 //获取SCHED_RR调度策略的最高和最低优先级
  printf("show SCHED_RR of priority:\n");
  show_thread_priority(&attr,SCHED_RR);

  printf("==        Set thread policy        == \n");
  //设置线程的调度属性为SCHED_FIFO
  printf("set SCHED_FIFO policy:\n");  
  set_thread_policy(&attr,SCHED_FIFO);
  priority = get_thread_priority(&attr);
  sched.__sched_priority = 99;
  pthread_attr_setschedparam(&attr,&sched);
  priority = get_thread_priority(&attr);

  //设置线程的调度属性为SCHED_FIFO
  printf("set SCHED_RR policy:\n");
  set_thread_policy(&attr,SCHED_RR);
  priority = get_thread_priority(&attr);
  sched.__sched_priority = 55;
  pthread_attr_setschedparam(&attr,&sched);
  priority = get_thread_priority(&attr);

  //恢复线程的调度策略
  printf("Restore current policy:\n");
  set_thread_policy(&attr,policy);

  rs = pthread_attr_destroy(&attr);
  assert(rs==0);
  return 0;
}