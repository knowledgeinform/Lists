# Lists

Install Catch2 with Homebrew:
```bash
$ brew install catch2
```

To run tests manually:
``` bash
$ g++ tests-main.cpp -I/usr/local/include/ -c
$ g++ file.cpp -c
$ g++ -I/usr/local/include/ tests-main.o file.o file-test.cpp -o tests.out
$ ./tests.out
```
