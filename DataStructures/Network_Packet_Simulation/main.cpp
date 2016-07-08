//
//  main.cpp
//  Network_Packet_Simulation
//
//  Created by Nitesh Thali on 7/6/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
 
 Ref : https://www.coursera.org/learn/data-structures
 Problem Description
 Task. You are given a series of incoming network packets, and your task is to simulate their processing.
 Packets arrive in some order. For each packet number i, you know the time when it arrived Ai and the
 time it takes the processor to process it Pi (both in milliseconds). There is only one processor, and it
 processes the incoming packets in the order of their arrival. If the processor started to process some
 packet, it doesn't interrupt or stop until it finishes the processing of this packet, and the processing of packet i takes exactly Pi milliseconds.
The computer processing the packets has a network buffer of fixed size S. When packets ar-
 rive, they are stored in the buffer before being processed. However, if the buffer is full when a packet
 arrives (there are S packets which have arrived before this packet, and the computer hasn't finished
 processing any of them), it is dropped and won't be processed at all. If several packets arrive at the
 same time, they are first all stored in the buffer (some of them may be dropped because of that |
 those which are described later in the input). The computer processes the packets in the order of
 their arrival, and it starts processing the next available packet from the buffer as soon as it finishes processing the previous one. If at some point the computer is not busy, and there are no packets in the buffer the computer just waits for the next packet to arrive. Note that a packet leaves the buffer and frees the space in the buffer as soon as the computerfinishes processing it.
 
 Input Format. The first line of the input contains the size S of the buffer and the number n of incoming
 network packets. Each of the next n lines contains two numbers. i-th line contains the time of arrival
 Ai and the processing time Pi (both in milliseconds) of the i-th packet. It is guaranteed that the
 sequence of arrival times is non-decreasing (however, it can contain the exact same times of arrival
 in milliseconds | in this case the packet which is earlier in the input is considered to have arrived
 earlier).
 Constraints. All the numbers in the input are integers. 1  S  105; 1  n  105; 0  Ai  106;
 0  Pi  103; Ai  Ai+1 for 1  i  n 􀀀 1.
 Output Format. For each packet output either the moment of time (in milliseconds) when the processor
 began processing it or 􀀀1 if the packet was dropped (output the answers for the packets in the same
 order as the packets are given in the input).
 Time Limits. C: 2 sec, C++: 2 sec, Java: 6 sec, Python:
 
 ***********************************************************
 Input:
 1 2
 0 1
 0 1
 Output:
 0
 -1
 Explanation:
 The first packet arrived at time 0, the second packet also arrived at time 0, but was dropped, because
 the network buffer has size 1 and it was full with the first packet already. The first packet started
 processing at time 0, and the second packet was not processed at all.
 Sample 4.
 Input:
 1 2
 0 1
 1 1
 Output:
 0
 1
 Explanation: The first packet arrived at time 0, the computer started processing it immediately and finished at time 1. The second packet arrived at time 1, and the computer started processing it immediately.
 
 
 */

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
