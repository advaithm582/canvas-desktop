# Canvas Desktop Client for UNIX/Linux
## Motivation
Tired of re-logging into Canvas every time? Tired of waiting for the pages to 
load? Annoyed by no dark mode? Vexed since there is no offline mode in this era
of PWAs? Presenting Canvas Desktop Client, written in C/GTK to solve these 
problems.

TBH I am just doing this project to get better at C. I did want to use it to get
better at DSA, but why take the risk if it is all implrmrnted in GLib already -
don't reinvent the wheel.

## Dependencies
> This is work in progress and is subject to change anytime. Commands here may
> not work and could brick your system if you don't know what you are doing!
* GLib 2.74.6
* cJSON 1.7.15

Install it with:
`sudo apt install libglib2.0-dev libcjson-dev`

## Roadmap
This project aims to first create a "library" of functions that can be used to
access Canvas data for students. This can be considered as a canvas SDK for C.

It is important to remember that one of the main features of CDC will be its
offline cache. Hence, an SQLite wrapper of the same will be created.

After all this and I figure out how to create a shared library, I will make a
"frontend" to this library using GTK.

### Schedule
Date | Task
--|--
November 2024 | finish the canvas SDK (libcanvas)
February 2025 | finish the offline acces wrapper to the library
May 2025 | finish the GUI

I am no expert in C, and these deadlines are tentative. As a side note, this is
one project I *really* don't want to abandon, as it has not been done before and
will be very useful (for me atleast). Help with designing a robust C API will be
appreciated.
