
```
Rewrite the code of this guide for beginners
```


# Table of Contents
## 2 ROOT Basics
### 2.3 ROOT as function lotter (2.3_slits.C) Aug.16.2018
### 2.6 Histogram in Root (Histogram_00.C) Aug.16.2018
## 3 ROOT Macros
### 3.1 General remarks on ROOT macros
```
void MacroName(){
    <...
    your lines of C++ code
    ...>
}
```
The macro is executed by typing
`>root MacroName.C` at the system prompt, 
or executed using .x at the ROOT prompt.
`root[0] .x MacroName.C`
or it can be loaded into a ROOT sesson and then be executed by typing
`root[0] .L MacroName.C`
`root[1] MacroName();`
Note that the `.h` file should be include at the last situation

### 3.2 A more complicated example
`macro1.C`

**NEED Further understanding**
```
    graph.Fit(&f);
    f.DrawClone("Same");
```

### 3.4 Interpretation and Compilation
### 3.4.1 Compile a Macro with ACLiC
ACLiC will create for you a compiled dynamic library for your macro, without any effort from your side, except the insertion of the appropriate header files.
To generate an object library from the macro code, from inside the interpreter type (please note the "+"):
`root[1] .L macro1.C+`

Once this operation in accomplished, the macro symbols will be available in memory and you will be able to exeute it simply by calling from inside the interpreter:
`root[2] macro1()`

### 3.4.2 Compile a Macro with the compiler
A plethora of excellent compilers are available, both free and commercial. We will refer to the GCC in the following.
In this case, you have to (1) include the appreciate headers in the code and then (2)exploit the `root-config` tool for the automatic settings of all the compiler flags.
`root-config` is a script that comes with ROOT; it prints all flags and libraries needed to compile code and link it with the ROOT libraries.
**Note**: You should execute the <root install dir>/bin/thisroot.sh at the terminal session for before the `root-config` take effect.
In order to make the code executable stand-alone, an entry point for the operating system is needed. in C++ this is the procedure **int main();**. The easiest way to turn a ROOT macro code into a stand-alone applciation is to add the follong "dressing code" at the end of the macro file.
```
int main(){
    ExampleMacro();
    return 0;
    }
```

To create a stand-alone program from a macro file, type
```
>g++ -o ExampleMacro.exe ExampleMacro.C `root-config --cflags --libs`
```
and execute it by typing
```
>./ExampleMacro.exe
```

This procedure will, however, not give access to the ROOT graphics, as neither control of mouse or keyboard events nor access to the graphics windows of ROOT is available.
If you want your stand-alone application have display graphics output and respond to mouse and keyboard, a lightly more complex piece of code can be used.

```
void StandaloneApplication(int argc, char** argv){
    // eventually, evaluate the application parameters argc, argv
    // here the ROOT macro is called
    ExampleMacro_GUI();
}
    // This is the stand "main" of C++ starting
    // a ROOT application
int main(int argc, char** argv){
    TApplication app("ROOT Application", &argc,argv);
    StandaloneApplication(app.Argc(),app.Argv());
    app.run();
    return 0;
}

Compile the code with
```
> g++ -o ExampleMacro_GUI.exe ExampleMacro_GUI `root-config --cflags --libs`
```
and execute the program with
```
> ./ExampleMacro_GUI
```

## Chapter 4 Graphs

### 4.1 Read Graph Points from File
The fastest way in which you can fill a graph with experimental data is to use the constructor which reads data points and their errors from an ASCII file format:
```
TGraphErrors(const char *filename, const char*format="%lg %lg %lg %lg", Option_t *option="");
```
The format string can be:
- "%lg %lg" read only 2 first columns into X,Y
- "%lg %lg %lg" read only 3 first columns into X,Y and EY
- "%lg %lg %lg %lg" read only 4 first columns into X,Y,EX and EY 
e.g. `macro2.C`,`macro2_input.txt` and `macro2_input_expected.txt`
```

### 4.2 Polar Graphs
With ROOT you can profit from rather advanced plotting routines, like the ones implemented in the TPolarGraph class to draw graphs in polar coordinates.

e.g. `macro3.C`

### 4.3 2D Graph
Under specific circumstances, it might be usefule to plot some quntities versus two variables, therefore creating bi-dimensional graph. Of course ROOT can help you in this task, with the TGraph2DErrors class.
e.g. `macro4.C`

### 4.4 Multigraph
e.g. `multigraph.C`
