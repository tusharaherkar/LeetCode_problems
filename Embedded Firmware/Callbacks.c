//          |                                        event_fired()
//          |                                             |
//          |                                             |
//  ----------------------------------------------------------------------------->time
//         |                         |                  cb1()            |
//         |                         |                  cb2()            |
// register_callback(cb1)    register_callback(cb2)              register_callback(cb3)
//                                                                        cb3()
//callbacks need to wait utill the event is fired
// callbacaks which registered post event fired can execute directly
// # assume callback could be executed with callback.run()
 


typedef struct callbackClass{
    callback* func; 
    int front;
    int back;
}CB;
pthread_mutex_t EventFiredflagMutex = PTHREAD_MUTEX_INITIALIZER;

bool EventFiredflag = FALSE;

void enque(callback cb);//implemented already
callback* deque(); //implemented already retun null on empty
 
void register_callback(callback cb)
{
    // fill this in
    bool getEventFiredflag;
    
    pthread_mutex_lock(&EventFiredflagMutex);
    getEventFiredflag = EventFiredflag;
    
    
    if(getEventFiredflag)
    {
        pthread_mutex_unlock(&EventFiredflagMutex);
        cb.run();
    }
    else
    {
        enqueue(cb); 
        pthread_mutex_unlock(&EventFiredflagMutex);  
    }
    
   
}

void event_fired()
{
    
    pthread_mutex_lock(&EventFiredflagMutex);
    EventFiredflag = TRUE;
   
    pthread_mutex_unlock(&EventFiredflagMutex);
    
    // fill this in
    callback* tobefiredEvent = deque();
    
    
    //pf(tobefiredEvent)
    
    while(tobefiredEvent != NULL)
    {
        tobefiredEvent->run();
        
        tobefiredEvent = deque();
       
    }
    
   
       
}