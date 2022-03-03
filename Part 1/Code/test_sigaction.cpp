//test_sigaction.cpp
// Any additional lines of code are the work of Thomas Cross. Assistance was also provided by Ruben Puentes.
#include <signal.h>
#include <unistd.h>
#include <iostream>

using namespace std;

void func (int sig, siginfo_t *, void *)
{
  switch(sig){
    case 2:
      cout << "SIGINT detected!" << endl;
      break;
    case 3:
      cout << "SIGSTOP Detected!" << endl;
      break;
    default:
      cout << "Signal not detected. ERROR!" << endl;
      break;
    
  }
}

int main()
{
  struct sigaction S_1, S_2; //S_1 = Oldact S_2 = Newact
  sigemptyset(&S_2.sa_mask); //Clearing the sigset of S_2
  S_2.sa_sigaction = func; //Defines the function to call when  signal is caught.

  sigaction(SIGINT,&S_2, &S_1);	//CTRL-C Input intercept
  sigaction(SIGQUIT,&S_2, &S_1);	//CTRL-\ Input intercept

  while (1) {
    cout << "CSUSB CSE 4600 Operating Systems. Homework on signals" << endl;
    sleep (1); 
  }
  
  return 0;
} 