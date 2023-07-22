# **Where Is**
## **Table of contents**
* [General info](#general-info)
* [Instruction](#instruction)
* [How to use](#how-to-use)
* [Examples](#examples)
## **General info**
**Where Is** - is a program which help you with find needed file or folder. Is a small terminal program. It is fast, helpful, smart and useful.
## **Instruction**
1. Install `where_is`.
2. Click `Win(Super) + T` or `open terminal`.
3. Enter `alias where-is='/enter/your/path/where_is'`.

**Congratulations you successful instaled and bind program**
## **How to use**
If you never used it enter `where-is -h`

        Useful information about program:

         -h  | --help                   -       Useful information about program
         -fl | --file                   -       Find file (use this with file extension for example file.pdf)
         -fd | --folder                 -       Find folder (enter name folder)
         -p  | --path                   -       Changing path which will be use for find file/folder (default use "/")
If you need find file and you don't know path where is this file enter it
```bash
where-is -fl name-your-file.extension
```
If you need find folder and you don't know path where is this file enter it
```bash
where-is -fd name-your-folder
```
If you need find file or folder and you know path where is this file or folder enter it
```bash
where-is -fl name-your-file.extension | -fd  name-your-folder -p /your/path/
```
## **Examples**
**If you didn't enter path** because you don't know where is this folder. **Time will be extended**.
```bash
Input: where-is -fd WhereIs

Output: /path/of/your/folder/
```
**If you entered path** where is approximately the folder. **Time will be shorter**.
```bash
Input: where-is -fd WhereIs -p /approximately/path

Output: /path/of/your/folder/
```