#include <pthread.h>
#include "../hdr/algorithms.h"

#define NUM_THREADS 2

typedef struct mergeTArgs
{

    int *array;
    int start;
    int end;
} mergeTArgs;

typedef struct queue
{
    mergeTArgs elements[(NUM_THREADS)*2];
    pthread_mutex_t mutex;
    int start;
    int end;
} Queue;

Queue *newQueue()
{

    Queue *q = calloc(1, sizeof(Queue));
    q->mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
    return q;
}

void append(Queue *q, mergeTArgs value)
{
    pthread_mutex_lock(&q->mutex);
    q->elements[q->end++] = value;
    pthread_mutex_unlock(&q->mutex);
}

void lappend(Queue *q, mergeTArgs value)
{
    pthread_mutex_lock(&q->mutex);
    q->elements[--q->start] = value;
    pthread_mutex_unlock(&q->mutex);
}

mergeTArgs pop(Queue *q)
{
    mergeTArgs value;
    pthread_mutex_lock(&q->mutex);
    value = q->elements[q->start++];
    pthread_mutex_unlock(&q->mutex);
    return value;
}

int length(Queue *q)
{
    return q->end - q->start;
}

void *merge_t_sroutine(void *arg)
{

    mergeTArgs *args = (mergeTArgs *)arg;

    if (args->start >= args->end)
        return NULL;

    int half = (args->end + args->start) / 2;

    merge_t_sroutine((void *)&(mergeTArgs){args->array, args->start, half});
    merge_t_sroutine((void *)&(mergeTArgs){args->array, half + 1, args->end});

    merge_sub_routine(args->array, args->start, half, args->end);

    return NULL;
}

void merge_t(int *array)
{

    if (NUM_THREADS <= 0)
        return;

    pthread_t threads[NUM_THREADS];
    Queue *q = newQueue();

    for (int i = 0; i < NUM_THREADS; i++)
    {

        mergeTArgs *args = malloc(sizeof(mergeTArgs));
        args->array = array;
        args->start = (i * SIZE) / NUM_THREADS;
        args->end = ((i + 1) * SIZE) / NUM_THREADS - 1;

        append(q, *args);
        pthread_create(&threads[i], NULL, merge_t_sroutine, args);
    }

    for (int i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);

    while (length(q) > 1)
    {
        mergeTArgs args[2];
        for (int i = 0; i < 2; i++)
            args[i] = pop(q);

        if (args[0].end > args[1].end)
        {
            merge_sub_routine(array, args[1].start, args[1].end, args[0].end);
            lappend(q, (mergeTArgs){array, args[1].start, args[0].end});
        }
        else
        {
            merge_sub_routine(array, args[0].start, args[0].end, args[1].end);
            lappend(q, (mergeTArgs){array, args[0].start, args[1].end});
        }
    }

    free(q);
}

