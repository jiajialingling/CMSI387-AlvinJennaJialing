# Detailed Design Document
By Qiyue Aixinjueluo, Jenna Berlinberg, and Alvin Lai.

## 2.1 – Detailed list of Linux modules that will be modified/affected
* `mkdir`: This modification would be added to the mkdir module. Using `-c` after typing the name of the new directory will now perform the `cd [new_directory]` function in the same step.
* `cd`: This will not be affected, but it will be useful in the creation of this new utility. The inspiration for our modifications will likely come from the existing code in the built-in `cd` method.

## 2.2 – Detailed list of any new modules that you will produce [or 'Not Applicable' if there are none]
Not Applicable.

## 2.3 – Class diagram showing affected modules [and any new modules] and how they related to one another
Alvin: use flowchart maker


## 2.4 – List or table of explanations of all command line options that will be implemented

| Command Line Options     | Explanation |
|--------------------------|------------------------------------------------------------------------------------|
| `mkdir [folder_name]`    | Make a new directory in the current working directory with the name `folder_name`. |
| `cd [folder_name]`       | Make `folder_name` the new working directory.|
| `mkdir [folder_name] -c` | Make a new directory `folder_name` and immediately `cd` into it. |
