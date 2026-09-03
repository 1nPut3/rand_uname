#!/bin/bash

set -euo pipefail

gcc rand-uname.c -o rand-uname -lm

sudo mkdir /etc/rand-uname/
sudo chmod 55 /etc/rand-uname/

sudo cp username_* /etc/rand-uname/
sudo chmod 644 /etc/rand-uname/username_*


sudo cp rand-uname /usr/bin/rand-uname