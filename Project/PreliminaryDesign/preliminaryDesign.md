# Preliminary Design

## 1.1 – Description of modification/addition to Linux
Our group has decided to make modifications to Linux’s `mkdir` utility function. Rather than just being able to create a new directory, users can simultaneously “cd” into their newly created directory with the command `mkdir [directoryName] -c`.

## 1.2 – Rationale as to why this is a good idea, or what the good points of it are:
Normally, people would use `mkdir` to create a new directory name. Then, you will need to use `cd` to go into the newly made directory or folder. This is a two-step process. It is sometimes inconvenient to do this second step, because we tend to type the new name of the directory as we desire. We are less likely to pay attention to little details, such as spaces, capitalizization, and spelling. When it is the time to go into our new folder, “cd newName” would not work. It might be typed as NewName, newname, or newame. Our group figured it would increase people’s efficiency by making the `mkdir` and `cd` into a one-step process. It can be used like this:

```
mkdir [directoryName] -c
```

This way, we are automatically in the new folder once we make the new directory. We can focus our minds on the program we are working on and not to worry about remembering what name we gave to the directory. We will always be able to modify or look at what that name was later- even quicker when it is indicated on the command line as the current directory. This convenient modification will protect our train of thoughts from being interrupted, thus keeping workflow as efficient as possible.

## 1.3 – Preliminary list of [possible] Linux modules that will be modified/affected

* `mkdir`: This modification would be added to the mkdir module. Using -c after typing the name of the new directory will now perform `cd [new_directory]` in the same step.
* `cd`: While cd itself might not be affected, it will be useful in the creation of this new utility. Inspiration for our modifications will likely come from the existing code in the built-in `cd`.

## 1.4 – Preliminary list of any new modules that you will produce [or 'Not Applicable' if there are none]
Not applicable.
