#include <stdio.h>
#include <pthread.h>

void *hello_thread(void *arg)
{
    printf("Hello from thread\n");
    return NULL;
}

int main()
{
    pthread_t id;
    printf("Hello from the main thread\n");
    pthread_create(&id, NULL, hello_thread, NULL);
    if (id != 0)
    {
        printf("Created thread with id: %lu\n", (unsigned long)id);
    }
    pthread_join(id, NULL);
    return 0;
}