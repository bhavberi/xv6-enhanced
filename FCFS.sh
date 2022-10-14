#!/bin/bash
make clean
make qemu SCHEDULER=FCFS CPUS="${1:-3/}"