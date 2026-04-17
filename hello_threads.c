#include <stdio.h>
#include <pthread.h>

void *hello_message(void *arg)
{
    printf("Hello from thread %d\n", (int)(long)arg);
    return NULL;
}
int main()
{
    /* pthread_t is a type that represents a thread identifier.
     * It is used to uniquely identify a thread in the system.
     * The pthread_create function takes a pointer to a pthread_t variable
     * as its first argument, which will be filled with the thread identifier of the newly created thread.
     * In this code, we declare two pthread_t variables, thread1 and thread2,
     * to hold the identifiers of the two threads we will create.
     */
    pthread_t thread1, thread2;

    /* pthread_attr_t is a type that represents thread attributes.
     * It is used to specify various properties of a thread,
     * such as its stack size, scheduling policy, and priority.
     * The pthread_create function takes a pointer to a pthread_attr_t variable as its second argument,
     * which can be used to specify the attributes of the newly created thread.
     * In this code, we declare a pthread_attr_t variable named attr
     * and initialize it using the attr_init function before passing it to pthread_create.
     */
    pthread_attr_t attr;
    attr_init(&attr);

    pthread_create(&thread1, &attr, hello_message, (void *)1);
    pthread_create(&thread2, &attr, hello_message, (void *)2);

    for (int i = 0; i < 10; i++)
    {
        printf("Hello from main thread\n");
    }
    return 0;
}