/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 *  stacks and queues portion of the lab.
 */

namespace QuackFun {

/**
 * Sums items in a stack.
 * @param s A stack holding values to sum.
 * @return The sum of all the elements in the stack, leaving the original
 *  stack in the same state (unchanged).
 *
 * @note You may modify the stack as long as you restore it to its original
 *  values.
 * @note You may use only two local variables of type T in your function.
 *  Note that this function is templatized on the stack's type, so stacks of
 *  objects overloading the + operator can be summed.
 * @note We are using the Standard Template Library (STL) stack in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint Think recursively!
 */
template <typename T>
T sum(stack<T>& s){

if (s.empty()){
  return 0;
}
  T temp=s.top();
  s.pop();
  T answer=temp+sum(s);
  s.push(temp);
  return answer;



}
    // Your code here
     // stub return value (0 for primitive types). Change this!
                // Note: T() is the default value for objects, and 0 for
                // primitive type


/**
 * Reverses even sized blocks of items in the queue. Blocks start at size
 * one and increase for each subsequent block.
 * @param q A queue of items to be scrambled
 *
 * @note Any "leftover" numbers should be handled as if their block was
 *  complete.
 * @note We are using the Standard Template Library (STL) queue in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint You'll want to make a local stack variable.
 */
template <typename T>
void scramble(queue<T>& q)
{
    stack<T> s;
    // optional: queue<T> q2;
    queue<T> q2;
    int size = q.size();
    if(size == 0){return;}
    int count = 1;
    int sum = 1;
    int odd_even;
    T curr;
    while(sum <= size){
      if(count % 2 == 1){
        for(int i = 0; i < count; i++){
          curr = q.front();
          q2.push(curr);
          q.pop();
        }
        odd_even = 1;
        count++;
        sum+=count;
      }
      else{
        for(int i = 0; i < count; i++){
          curr= q.front();
          q.pop();
          s.push(curr);
        }
        for(int i = 0; i < count; i++){
          curr = s.top();
          q2.push(curr);
          s.pop();
        }
        odd_even = 0;
        count++;
        sum+=count;
      }
    }
    int left = size-(sum-count);

    if(odd_even == 1){
      for(int i = 0; i < left; i++){
        curr = q.front();
        q.pop();
        s.push(curr);
      }
      for(int i = 0; i < left; i++){
        curr = s.top();
        q2.push(curr);
        s.pop();
      }
    }
    else{
      for(int i = 0; i < left; i++){
        curr = q.front();
        q2.push(curr);
        q.pop();
      }
    }

    q = q2;
}

/**
 * @return true if the parameter stack and queue contain only elements of
 *  exactly the same values in exactly the same order; false, otherwise.
 *
 * @note You may assume the stack and queue contain the same number of items!
 * @note There are restrictions for writing this function.
 * - Your function may not use any loops
 * - In your function you may only declare ONE local boolean variable to use in
 *   your return statement, and you may only declare TWO local variables of
 *   parametrized type T to use however you wish.
 * - No other local variables can be used.
 * - After execution of verifySame, the stack and queue must be unchanged. Be
 *   sure to comment your code VERY well.
 */
template <typename T>
bool verifySame(stack<T>& s, queue<T>& q)
{
    bool retval = true; // optional
    //T temp1; // rename me
    //T temp2; // rename :)
    T temp1; // rename me
    T temp2; // rename :)
    if(s.size()==0){return true;} //when the stack has no more elements left, return true -> Base Case
    temp1 = s.top(); //recursion starts from the top of the stack
    s.pop();//pop the s.top
    retval = verifySame(s,q);//Recursive Step
    temp2 = q.front();//recursion starts from the front of the queue
    retval = retval && (temp1 == temp2); //Compare the front of the queue with the top of the stack
    q.pop();//pop the q.front
    s.push(temp1);
    q.push(temp2);

    return retval;
}
}
