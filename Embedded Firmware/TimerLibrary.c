// Task is to develop a timer library


// function pointer
typedef (void* timer_task)(void* ptr); 

#define MAX_TIMER_IDS    (0x400) // 2048
#define TIMER_ID_INVALID (0xFFFF)

uint32_t timer_get_free_timer_id();              // already implemented
void     timer_free_timer_id(uint32_t timer_id);  // already implemented
uint64_t cpu_clock_timestamp_get();  // already implemented
uint64_t cpu_clock_time_delay_get(uint32_t delay_in_ms); // already implemented
// 0x12345678
// (0x12345678 + cpu_clock_timestamp(3 ms) (CPU clock ticks)) 


// 20 ms, 1s,  


// timer_create(task1, 0, 100, ptr) 
// timer_create(task2, 0, 62, ptr)
// timer_create(task3, 0, 61, ptr) 
// timer_create(task4, 0, 60, ptr)
// timer_create(task5, 0, 59, ptr)
// ..
// ..
// timer_create(task5, 0, 1, ptr)

// uint64_t counter = 0;


typedef struct 
{
  timer_task task_func; // assume 32-bit address, // call back
  void* task_arg;     
  int32_t timer_id;  
  //.....
  uint64_t callingTime;

  uint64_t FinalExecutionTime;


//...
  
} TIMER_INFO;


static TIMER_INFO s_timer_info[ ];


void timer_init(int32_t timer_id, timer_task task_func, void* task_arg, uint64_t callingTime, uint64_t FinalExecutionTime)
{
    // All SW timers are initialized here.

    // Table
    // RS1 callingTime FinalExecutionTime

    s_timer_info[timer_id].timer_id            = timer_id;
    s_timer_info[timer_id].task_func           = task_func;
    s_timer_info[timer_id].task_arg            = task_arg;
    s_timer_info[timer_id].callingTime         = callingTime;
    s_timer_info[timer_id].FinalExecutionTime  = FinalExecutionTime;

}
// read_sensor_1 , 5, timer_id=1 --> 0th
// read_sensor_2, 2, timer_id=2  --> 2nd
//      ...
//  65 --> 0th

// read_sensor_2() timer_id=1
// create a task for timer --> task(arg)

//timer_create(print, args ,5);

void timer_create(timer_task task_func, void* arg, uint32_t delay_in_ms)
{ 
    int32_t CurrentTimerId;

    // Corner Case:
    //First check whether we have space to get new timerId
    CurrentTimerId = timer_get_free_timer_id();
    if(CurrentTimerId ==  TIMER_ID_INVALID)
    {
        //return can not assign new Timer Id
        return;
    }

    uint64_t callingTime =  cpu_clock_timestamp_get();
    uint64_t FinalExecutionTime =  callingTime + cpu_clock_time_delay_get(delay_in_ms);

    // BruteForce Approach:
    // 1. fill the struct object of s_timer_info with  timer_init() function
    timer_init(CurrentTimerId, task_func, arg, callingTime, FinalExecutionTime);

    // Time Complexity:
    // O (N) -> N is the number of timerIds calling from caller of timer_create() to form the array of structure of s_timer_info
    
    // Space Complexity:
    // O (N*sizeof(s_timer_info)) -> N is the number of timerIds allocated and size of structure of s_timer_info



    // Optimized Approach:
    // 1. Make the priority_queue based on the FinalExecutionTime (chosen as priority) as minHeap
    // 2. Each node of heap will have timerId and FinalExecutionTime
    // 3. Add node in minheap coming from timer_create 
    
    // Time Complexity:
    // O (N*logN) -> N is the number of timerIds calling from caller of timer_create() to form priority_queue/minHeap

    // Space Complexity:
    // O (N*sizeof(s_timer_info)) -> N is the number of timerIds allocated and size of structure of s_timer_info


  //..

  

} 
  
// get 1-ms timer interrupt, ISR
// ISR address already setup in the interrupt vector table
void timer_check_and_fire(void)
{ 
  int32_t timerIter;
  
  // BruteForce Approach:
  // 1. Run a loop over all tasks till Check FinalExecutionTime of each task 
  // 2. If it has crossed FinalExecutionTime then fire the task
  // 3. free the timer once the task is fired

  
  // Time Complexity:
  // O (N) -> N is the number of timerIds allocated 
  
  
  // Space Complexity:
  // O (N*sizeof(s_timer_info)) -> N is the number of timerIds allocated and size of structure of s_timer_info
  uint64_t checkFireTime = cpu_clock_timestamp_get()

  for(timerIter = 0; timerIter < MAX_TIMER_IDS; timerIter++)
  {
    // Check if current time from cpu has exceeded the FinalExecutionTime if yes then fire the task
    if(checkFireTime >= s_timer_info[timerIter].FinalExecutionTime)
    {
        // Call the task function
        s_timer_info[timerIter].task_func(s_timer_info[timerIter].task_arg);
        //free the timer Id once finished executing the taskfunc();
        timer_free_timer_id(s_timer_info[timerIter].timer_id);
    }
    
  }
  
    // Optimized Approach:
    // 1. Make the priority_queue based on the FinalExecutionTime (chosen as priority) as minHeap
    // 2. Each node of heap will have timerId and FinalExecutionTime
    // 2. Check the cpu_clock_timestamp_get >= FinalExecutionTime of root node of minHeap
    // 3. Choose the task with the help of timerId of root and call the task function 
    // 4. Do heapify after calling the task 
    // 5. free the timer Id once finished executing the taskfunc();
 
    // Time Complexity:
    // O (1) -> to compare the root node
    // O (logN) -> Do heapify where N is the number of timerIds allocated
    // So Overall, It is O(logN)  where N is the number of timerIds allocated
    
    // Space Complexity:
    // O (N*sizeof(s_timer_info)) -> N is the number of timerIds allocated and size of structure of s_timer_info
    


}