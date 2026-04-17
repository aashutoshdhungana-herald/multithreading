#include <stdio.h>
#include <pthread.h>

// This function will be executed by each thread created in the main function.
// It takes a void pointer as an argument, which can be used to pass any data to the thread.
// In this case, we are passing an integer value (cast to a void pointer) that represents the thread number.
// The function prints a message that includes the thread number and then returns NULL.
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
    pthread_attr_init(&attr);

    // pthread_create is a function that creates a new thread in the program.
    // It takes four arguments:
    // 1. A pointer to a pthread_t variable that will hold the thread identifier of the newly created thread.
    // 2. A pointer to a pthread_attr_t variable that specifies the attributes of the thread (or NULL for default attributes).
    // 3. A pointer to the function that the thread will execute (the thread's start routine).
    // 4. A pointer to the argument that will be passed to the thread's start routine (or NULL if no argument is needed).
    // These threads are created after the function call, but they may not start executing immediately.
    // The scheduling of threads is determined by the operating system,
    // and they may run concurrently with the main thread.
    pthread_create(&thread1, &attr, hello_message, (void *)1);
    pthread_create(&thread2, &attr, hello_message, (void *)2);

    if (thread1 != 0)
    {
        printf("Created thread 1 with id: %lu\n", (unsigned long)thread1);
    }
    if (thread2 != 0)
    {
        printf("Created thread 2 with id: %lu\n", (unsigned long)thread2);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("Hello from the main thread\n");
    }
    return 0;
}