typedef struct {
    int n;
} FooBar;

// Function declarations. Do not change or remove this line
void printFoo();
void printBar();

sem_t semFoo;
sem_t semBar;

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;
    sem_init(&semFoo, 0, 1);
    sem_init(&semBar, 0, 0);
    return obj;
}

void foo(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        
        sem_wait(&semFoo);
        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();
        sem_signal(&semBar);

    }
}

void bar(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        
        sem_wait(&semBar);
        // printBar() outputs "bar". Do not change or remove this line.
        printBar();
        sem_signal(&semFoo);

    }
}

void fooBarFree(FooBar* obj) {

    sem_destroy(&semFoo);
    sem_destroy(&semBar);
    
}