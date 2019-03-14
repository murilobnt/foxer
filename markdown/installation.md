# Installation

> This guide is related to the case you have SFML library installed in a
g++ standard path (if you installed it with apt or moved it to /usr/local).
If negative, I suggest altering the makefile.

> This guide is only granted for the Linux Ubuntu distro.

## Step 1: Download the repository
To install the gs2d library (the engine) you first need to clone or download the
ZIP of this repository.

## Step 2: Install the engine library

Once you've downloaded/cloned this repository, and made sure you have GCC and
SFML (in a recognizable library path of g++) installed, the following command,
through terminal, and at the root of the project, should suffice.

```
sudo make install
```

### Step 2.1: Exporting the library location

Following the GNU standards, the library and the headers of this engine will be
located at */usr/local/lib* and */usr/local/include*. Those directories,
however, are commonly not searched by default.

This shows true for Ubuntu 18.04, too. To easily solve this, you can
**add this line to the end of your ~/.bashrc (if you use bash) or ~/.zshrc
(if you use zsh) file**.

```
export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:/usr/local/lib"
```

# Check if the sample is working

Go to the *sample* directory of this project. And run:

```
make
```

Now, if you followed the [Step 2.1: Exporting the library location](https://github.com/murilobnt/gs2d_engine/blob/master/markdown/installation.md#step-21-exporting-the-library-location),
the following command should be successfully executed.

```
./bin/sample
```

Otherwise, you need to export the path to the library **every execution**.

```
export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:/usr/local/lib" && ./bin/sample
```

[Return to readme](https://github.com/murilobnt/gs2d_engine#installation)
