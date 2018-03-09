/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 *  stacks and queues portion of the lab.
 */

 #include <iostream>
 #include <string>

namespace QuackFun {


template <typename T>
T sum(stack<T>& s)
{

  T temp = s.top();
	s.pop();
	if(s.empty()){
	   s.push(temp);
	   return temp;
	}
	else{
	   T sum2 = sum(s);
	    s.push(temp);
	    return temp+sum2;
}


}

bool isBalanced(queue<char> input)
{

    stack<char> temp;
    unsigned long size = input.size();
//Input with only brackets
    for(unsigned long i =0; i<size; i++){
        char tmp = input.front();
        if(tmp == '['){
          temp.push(tmp);
        }
        else if(tmp == ']'){
          if(temp.size() != 0)
            temp.pop();
	  else
	    return false;
        }
        input.pop();
      }
      if(temp.size() != 0)
	return false;
      
      return true;

        // std::cout<<input.front()<<std::endl;

//When total brackets is not even(not paired)
      //if(input.size()%2!=0){
      //  return false;
      //}

//for all elements, [ stays in input, ] pushed to Stack temp.
      //for(unsigned long i =0; i<input.size(); i++){
        //if(input.front()=='['){
          //input.push(input.front());
          //input.pop();
       // }
       // else{
        //  temp.push(input.front());
         // input.pop();
       // }
     // }

      //if(input.size() == temp.size()){
        //return true;
      //}


      //if(input.empty()){
       // return true;
      //}

    //return false;


    // while(!input.empty()){
    //   if(input.front() == '['||input.front()==']'){
    //     temp.push(input.front());
    //   }
    //   input.pop();
    // }
    //
    // while(!temp.empty()){
    //
    // }
    //
    //
    //
    // for(unsigned long i = 0; i < temp.size()/2; i++){
    //   if(temp.top()==']'){
    //     countBack++;
    //     temp.pop();
    //   }
    //   else if(temp.top()=='['){
    //     return false;
    //   }
    // }
    //
    // for(unsigned long i = temp.size()/2; i < temp.size(); i++){
    //   if (temp.top()=='['){
    //     countFront++;
    //     temp.pop();
    //   }
    //   else if ( temp.top()==']'){
    //     return false;
    //   }
    // }
    // if(countFront!=countBack){
    //   return false;
    // }
    //
    // return true;
}

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
    // stack<T> s;
    // queue<T> q2;
    //
    // for(int i =1; i<(int)q.size(); i++){
    //   while(q.empty()==false){
    //       if(i%2==0){
    //         for(int j = 0; j<i; j++){
    //           s.push(q.front());
    //           q.pop();
    //         }
    //         for(int j = 0; j<i; j++){
    //           q2.push(s.top());
    //         }
    //
    //       }
    //       else{
    //         for(int k=0; k<i; k++){
    //
    //           q2.push(q.front());
    //           q.pop();
    //         }
    //       }
    //   }
    // }
stack<T> s;
queue<T> q2;
 int size = q.size();
 int block = 1;
 int blocki = 1;
 int i = 0;
 int newi = 0;
 while(i<size){
   if((block%2)==0){
     for(blocki=block; blocki>0; blocki--){
   //		std::cout<<"no segfault yet "<<i<<std::endl;
       if(i<size){
       s.push(q.front());
//				std::cout<<"q.front() == "<<q.front()<<std::endl;
       q.pop();
       i++;
       }
   //		std::cout<<"no segfault yet "<<i<<std::endl;
     }
     for(blocki=block; blocki>0; blocki--){
   //		std::cout<<"no segfault yet "<<i<<std::endl;
       if(newi<size){
       q.push(s.top());
   //		std::cout<<"no segfault yet "<<i<<std::endl;
       s.pop();
   //		std::cout<<"no segfault yet "<<i<<std::endl;
       newi++;
       }
     }
     //s.push(q.front());
     //q.pop();
     //blocki--;
   //	std::cout<<"no segfault yet "<<block<<std::endl;
   }else if((block%2)==1){
     for(blocki=block; blocki>0; blocki--){
   //		std::cout<<"no segfault yet "<<i<<std::endl;
       if(i<size){
       q2.push(q.front());
//				std::cout<<"q.front() == "<<q.front()<<std::endl;
       q.pop();
       i++;
       }
   //		std::cout<<"no segfault yet "<<i<<std::endl;
     }
     for(blocki=block; blocki>0; blocki--){
       if(newi<size){
       q.push(q2.front());
   //		std::cout<<"no segfault yet "<<block<<std::endl;
       q2.pop();
   //		std::cout<<"no segfault yet "<<block<<std::endl;
   //		std::cout<<"no segfault yet "<<block<<std::endl;
       newi++;
       }
     }

     //q2.push(q.front());
     //q.pop();
     //blocki--;
   }
   block++;
}
    // optional: queue<T> q2;

    // Your code here
}

/**
 * @return true if the parameter stack and queue contain only elements of
 *  exactly the same values in exactly the same order; false, otherwise.
 *
 * @note You may assume the stack and queue contain the same number of items!
 * @note The back of the queue corresponds to the top of the stack!
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
    T temp1; // rename me
    T temp2; // rename :)

    if(s.size()==0){
      return true;
    }
    temp1=s.top();
    s.pop();
    retval=verifySame(s,q);
    temp2=q.front();
    q.pop();
    retval=(retval&&(temp1==temp2));
    q.push(temp2);
    s.push(temp1);
    return retval;

    // Your code here
}

}
