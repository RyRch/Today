# Introduction

ctodo is a fork of a CLI program writen in Golang.

# Requirement

Before running this programm you need to have GCC, make and a [NerdFont ttf](https://github.com/ryanoasis/nerd-fonts/blob/master/readme.md).

For ubuntu : 

'''
sudo apt install gcc make

'''

# How to

'''
$> todo
'''

Display the list of tasks

'''
$> todo -a "new task" 
'''

Add a new task

'''
$> todo -b 0
'''

To start a new task you need to specify a [ID]

'''
$> todo -c 0
'''

To finish a task you need to specify a [ID]

'''
$> todo -d 0
'''

To delete a task you need to specify a [ID]

'''
$> todo -e 0 "test"
'''

To edit a new task you need to specify a [ID] and the new task
