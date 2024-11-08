# mini-talk

A project focused on learning the basics of UNIX signals, and how to use them.
In this project I built a Client-Server Communication programs, that share data using Signals. But wait? Can we even send data on signals?? actually no but if we alter between 2 signals 
"SIGUSR1 and SIGUSR2" and we handled both of them with a sigaction, we can treat each signal reached as a bit either 1 (SIGUSR1) or 0 (SIGUSR2). 

