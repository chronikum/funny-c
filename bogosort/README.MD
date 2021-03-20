## Bogosort

## How does bogosort work?

It just generates all possible permutations and will then check if the generated permutations
is sorted or not. It is actually pretty stupid but was a lot of fun to implement.

## Limits

This implementation cannot handle more than 4 numbers. Also the time needed for every additional digit will increase exponentially.
If you want more combinations you can just edit ``[24][4]`` everywhere.
Also, there is probably some dirty hardcoded stuff you should take care off, i did not look into it.
Also, negative numbers are not properly displayed. Don't use them.