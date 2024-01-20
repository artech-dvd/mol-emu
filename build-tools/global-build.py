import os
print("Run from project root")
print("Beginning build...")
os.system("g++ -o ./build/main ./src/main.cpp")
print("Build complete!")