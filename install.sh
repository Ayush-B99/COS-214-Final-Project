#!/bin/bash
# Setup script for ncurses library

echo "🌿 Setting up ncurses for Plant Store Management System..."

# Check if ncurses is already installed
if pkg-config --exists ncurses 2>/dev/null || ldconfig -p | grep -q libncurses; then
    echo "✓ ncurses is already installed!"
else
    echo "Installing ncurses..."
    
    # Detect OS and install
    if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        # Linux
        if command -v apt-get &> /dev/null; then
            sudo apt-get update
            sudo apt-get install -y libncurses5-dev libncursesw5-dev
        elif command -v yum &> /dev/null; then
            sudo yum install -y ncurses-devel
        elif command -v pacman &> /dev/null; then
            sudo pacman -S ncurses
        fi
    elif [[ "$OSTYPE" == "darwin"* ]]; then
        # macOS
        brew install ncurses
    fi
fi

echo "✓ Setup complete! You can now run: make run"
