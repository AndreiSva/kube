```
 ____  __.    ___.           
|    |/ _|__ _\_ |__   ____  
|      < |  |  \ __ \_/ __ \ 
|    |  \|  |  / \_\ \  ___/ 
|____|__ \____/|___  /\___  >
        \/         \/     \/ 
```

NOTE: This was mostly made as a side project for me to get more accustomed to programming in C. That being said, I might update this in the future to include more complex features. Feel free to take a look at [planned features](https://github.com/AndreiSva/kube/#planned-features).

kube is an esoteric programming language very similar to [BrainF](https://gist.github.com/roachhd/dce54bec8ba55fb17d3a). It has most of it's features with a few tweaks and quality of life imrpovements and tools to make more powerful programs.

## features

here is a list of all kube's features

### 1. increment register
Kube works on a simple register system. By default, the register pointer starts at 0 and the size starts at 1 with the register value at 0. This means the registers look a bit like this:
```
[0]
```
To increment the value at the current register pointer we use the `+` symbol. So feel free to put that in a file and run `./kube file.kubic`.
Now our registers look like this:
```
[1]
```

### 2. decrement register
the `-` symbol does the same thing as the `+` symbol but of course decrements the register instead of incrementing it.

### 3. integer literals
kube allows for integer literals. When the interpreter detects an integer literal, the value of that integer is writen to the current register. For example this small kube scipt:
```
10
```
would result in the following register values:
```
[10]
```

### 4. printing registers
you can print the value in the current register as a ascii character by using the `^` symbol. This is especially useful in combination with integer literals. For example:
```
72^101^108^108^111^32^87^111^114^108^100^
```
gives the output:
```
Hello World
```
### 5. moving the register pointer
you can move the register pointer (or the "selected" pointer) by using the `>` character. If there are no more registers to move to, kube will automatically create new registers on the fly. Lets see an example of this:
```
>
```
register values:
```
[0][0]
```
you can repeat this indefinetly:
```
>>>>>
```
register values:
```
[0][0][0][0][0]
```

Similarly, you can move the pointer position backwards with the `<` character. Lets visualize this by setting different registers to different values:

```
0>><1>3
```
register values:

```
[0][0][1][3]
```

### 6. loops
Loops in kube work exactly the same as in Brainf with only a few minor changes. To declair the start and end of a loop we can use the `(` and `)` characters respectively. The interpreter will recursively interpret the contents of the loop until the current register is 0.

### 7. user input
User input in kube is much more powerful than in BrainF. Instead of only being able to take a single character as input, kube can take strings of infinite lengths. To use input simply use the `v` symbol. The interpreter will then copy each char from the string to the registers and moves the register pointer to the end of the copied registers. Here is an example:
```
v
```
input = `Andrei`
register values:
```
[65][110][100][114][101][105]
```
