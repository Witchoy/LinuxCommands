# Linux Commands : Rewritten from Scratch

This repository is a personal learning journey where I re-implement classic **Linux command-line tools** in C.  
The goal is to understand how these commands work under the hood by rebuilding them step by step.

---

## 📚 Learning Ladder

I’ve organized the project into **stages**, each focusing on a new concept:

### Stage 1, Hello, stdout
Learn to send text to the terminal.
- 1. `echo`, print arguments  
- 2. `yes`, print a string repeatedly until stopped  
- 3. `true / false`, return exit code 0 or 1  

### Stage 2, Reading files
Learn to open, read, and display files.
- 4. `cat`, print file contents to stdout  
- 5. `head`, print first N lines of a file  
- 6. `tail`, print last N lines of a file  
- 7. `wc`, count lines, words, characters  

### Stage 3, Filesystem basics
Learn about paths, metadata, and file operations.
- 8. `pwd`, print current working directory  
- 9. `basename / dirname`, split a file path  
- 10. `stat`, show file info (size, permissions, etc.)  
- 11. `touch`, create a file or update timestamp  

### Stage 4, Directory handling
Learn to interact with directories and their contents.
- 12. `ls` (basic), list files in current directory  
- 13. `du` (basic), show size of files/directories  
- 14. `rm` (basic), delete a file  
- 15. `mv` (basic), rename a file  
- 16. `cp` (basic), copy a file  

### Stage 5, System interaction
Learn about process control and system info.
- 17. `date`, get current date/time  
- 18. `sleep`, wait N seconds  
- 19. `clear`, clear terminal  
- 20. `whoami`, print current user  
- 21. `hostname`, print machine name  
- 22. `uptime`, read `/proc/uptime`

---

## 🗂️ Repository Structure

```
.
├── Final_Builds/           # Compiled binaries of finished commands
├── Stage_1/                # First commands (echo, yes, true, false)
├── Stage_2/                # File reading commands (cat, head, tail, wc)
└── ...                     # Future stages (filesystem, directories, system)
```

---

## ⚙️ How to Build

Each command has its own `Makefile`. To build, navigate into the command’s folder and run:

```bash
make
```

For example, to build **echo**:
```bash
cd Stage_1/Echo
make
./bin/my_echo "Hello World!"
```

---

## 🎯 Goals

- Practice **C programming** with real-world examples  
- Learn **system calls** like `open`, `read`, `write`, and `close`  
- Understand **how Linux utilities are built** step by step  
- Document progress as I go  

---

## 🚀 Final Builds

When a command is completed, its executable is stored in:

```
Final_Builds/
├── my_cat
├── my_echo
├── my_false
├── my_true
└── my_yes
```

This way you can run all finished commands from one place.

---

## 📝 Notes

This is a **learning project**. The reimplemented commands may not cover all edge cases or options that the GNU coreutils versions support, but they work for the basics and help me understand the internals.