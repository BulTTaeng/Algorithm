## What is the problem?

<https://www.acmicpc.net/problem/2230>

## What Algorithm should I use?

Two Pointer.

## What was the key point and the hard part?

Because the input numbers are not sorted , we have to sort it to solve it in time.

Searh from the (0,0) which means (start , end) if diff between them is less than M, increase end.

If diff is bigger than M , compare it with saved value and save the min value and increase the start.

If diff is same with M , this is optimal case so break and print M.

## Where can I get more help, if I need it?

You can contact me through email, which is wogur7496@gmail.com.
Thank you for visiting this github!
