


# Linux Socket Programming

Most inter-process communication uses the client server model. These terms refer to the two processes which will be communicating with each other.
One of the two processes, the client, connects to the other process, the server, typically to make a request for information.
A good analogy is a person who makes a phone call to another person.


A socket is a mechanism for allowing communication between processes, be it programs running on the same machine or different computers connected
on a network. More specifically, Internet sockets provide a programming interface to the network protocol stack that is managed by the operating system. Using this API, a programmer can quickly initialize a socket and send messages without having to worry about issues such as packet framing or transmission control. 

There are a number of different types of sockets available, but we are only really interested in two
specific Internet sockets. These are:
• Stream sockets
• Datagram sockets

What differentiates these two socket types is the transport protocol used for data transmission.
A stream socket uses the Transmission Control Protocol (TCP) for sending messages. TCP provides an ordered and reliable connection between two hosts. This means that for every message sent, TCP guarantees that the message will arrive at the host in the correct order. This is achieved at the
transport layer so the programmer does not have to worry about this, it is all done for you.

A datagram socket uses the User Datagram Protocol (UDP) for sending messages. UDP is a much simpler protocol as it does not provide any of the delivery guarantees that TCP does. Messages, called datagrams, can be sent to another host without requiring any prior communication or a connection
having been established. As such, using UDP can lead to lost messages or messages being received out of order.

It is assumed that the application can tolerate an occasional lost message or that the application will handle the issue of re-transmission. There are advantages and disadvantages to using either protocol and it will be highly dependent of the application context.
For example, when transferring a file you want to ensure that, upon receipt, the file has not become corrupted. TCP will handle all the error checking and guarantee that it will arrive as you sent it. On the other hand, imagine you are sending 1000 messages detailing player position data every second in a computer game The application will be able to tolerate missing messages here so UDP would be more suitable.


# NETWORK PROGRAMMING ASSIGNMENT


    1. Write a simple TCP-Server and TCP-Client socket applications, establish connection and observe client and server communication.

    2. Write a simple UDP-Server and UDP-Client socket application and establish connection and observe client and server communication.

    3. Write a simple UNIX-Server and UNIX-Client socket (TCP) application and establish connection and observe client and server communication.
       
    4. Write a simple UNIX-Server and UNIX-Client socket (UDP) application and establish connection and observe client and server communication.
       
    5. Write a simple Server socket application that will publish a message into its group(with Client). Design an simple Multi-cast  Socket application.
       
    6. Write a simple Server socket application that will publish a message to all. Design an simple Broadcast Socket application.
