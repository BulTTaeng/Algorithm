# 11559_Puyo Puyo

made by Jaehyeok Choi

## Welcome to Jaehyeok's github!

## What is the problem?

<https://www.acmicpc.net/problem/11559>

## What Algorithm should I use?

Graph Algorithm , simuation , dfs

## What was the key point and the hard part?

Because I cannot catch the simple algorithm and the nubmer size is small. I think this will work in brute-force.

First, find the group bigger than 4. I use dfs to do this.

While doing dfs , I save the location of visited location in the queue.

When dfs is done and the size of graph is bigger than 4, I push them in the priority queue.

The reason why we use priority queue is that if we change the lower location first , the location we saved goes wrong because they are moved.

Whne dfs(0,0 to 11 , 5 ) is done, move the input array to remove detected location.

## Where can I get more help, if I need it?

You can contact me through email, which is wogur7496@gmail.com.
Thank you for visiting this github!
