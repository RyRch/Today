# Screenshot

![soon](http://url/to/img.png)

# Requirement

Before running this programm you need to have GCC, make and a [NerdFont ttf](https://github.com/ryanoasis/nerd-fonts/blob/master/readme.md).

For Ubuntu : 

```
sudo apt install gcc make
```
For Arch Linux :

```
sudo pacman -S gcc make
```

And run the `install.sh` script with sudo

```
sudo install.sh
```

# How to

```
$> today
```

Display the list of tasks

```
$> today -a "new task" 
```

Add a new task

```
$> today -b 0
```

To start a new task you need to specify a [ID]

```
$> today -c 0
```

To finish a task you need to specify a [ID]

```
$> today -d 0
```

To delete a task you need to specify a [ID]

```
$> today -e 0 "test"
```

To edit a new task you need to specify a [ID] and the new task
