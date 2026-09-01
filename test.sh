#!/bin/bash

# Compile the C program
gcc harness.c -o harness

# Check if compilation succeeded
if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

echo "--- Running Program Test ---"

# Feed "hello" followed by "exit" into the executable
./harness << 'EOF'
hello
exit
EOF

echo "----------------------------"
echo "Test completed."