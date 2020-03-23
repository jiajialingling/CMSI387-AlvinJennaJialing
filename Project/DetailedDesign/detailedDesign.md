# Detailed Design Document
By Qiyue Aixinjueluo, Jenna Berlinberg, and Alvin Lai.

## 2.1 – Detailed list of Linux modules that will be modified/affected


## 2.2 – Detailed list of any new modules that you will produce [or 'Not Applicable' if there are none]
Not Applicable.

## 2.3 – Class diagram showing affected modules [and any new modules] and how they related to one another
use flowchart maker


## 2.4 – List or table of explanations of all command line options that will be implemented

| Command Line Options     | Explanation                  |
| ------------------------ | ---------------------------- |
| `mkdir [folder_name]`    | This (familiar) command makes a directory in the current working directory with the name `folder_name`.            |
| `cd [folder_name]`       | This (even ore familiar) command makes `folder_name` the new working directory. `folder_name` may also be a file path. |
| `mkdir [folder_name] -c` | This new addition to the mkdir, `-c` would combine the two commands stated above into one succinct command.          |
