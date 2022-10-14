#!/bin/bash
make clean
make qemu SCHEDULER=PBS CPUS="${1:-3/}"