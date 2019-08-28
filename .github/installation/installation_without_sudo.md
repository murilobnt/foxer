# Installation without sudo

> This guide is related to the case the machine has GCC installed.
If GCC is not installed and you don't have sudo permission, this
guide won't be able to help you about it.

> This guide is only granted for the Linux Ubuntu distro.

## Step 1: Download the repository

To install the gs2d library (the engine) you first need to clone or download the
ZIP of this repository.

## Step 2: Download the newest version of SFML

In this no-sudo case, you must download the Linux version of SFML. It can be
obtained [here](https://www.sfml-dev.org/download.php).

When complete, extract the directory inside the .tar.gz to somewhere. **It's advised to
extract it to the root of the project (the gs2d_engine directory)**.

## Step 3: Adjust the makefile of the engine

In order to use the engine, you will first need to alter some variables inside the makefile.
It's no big deal.

You might run into something like this in the first three lines of the file.

```
## Use these variables if SFML is not installed in a standard path
# SFML-DIR = SFML-2.5.1
# SFML-INCLUDE = -I $(SFML-DIR)/include
```

So, you need uncomment those two last lines. If SFML directory is not located at the root
of the project, or if the downloaded version is not 2.5.1, you will need to alter it's
value to the path of the extracted directory at the moment of [Step 2: Download the newest version of SFML](https://github.com/murilobnt/gs2d_engine/blob/master/.github/installation_without_sudo.md#step-3-download-the-newest-version-of-sfml).

## Step 4: Compile the library

You can simply compile the library by going, through terminal, to the root of
this project and entering the following command.

```
make
```

### Step 4.1: Exporting the libraries locations

In order for the linker to acknowledge the location of the .so files of SFML and GS2D,
it's a good idea to export the library locations beforehand.

To easily solve this, you can
**add these lines to the end of your ~/.bashrc (if you use bash) or ~/.zshrc
(if you use zsh) file, altering the <SFML-DIRECTORY-PATH> and <GS2D-DIRECTORY-PATH>
to their paths in the machine**.

```
export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:<SFML-DIRECTORY-PATH>/lib"
export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:<GS2D-DIRECTORY-PATH>/gs2d/lib"
```

# Check if the sample is working

## But first...

... you will have to adjust the makefile of the sample. Just like the makefile of the
engine, you will only need to alter some variables of it.

```
## Use these variables if SFML is not installed in a standard path.
## Also use these variables if GS2D library couldn't be installed with sudo.

# SFML-DIR = ../SFML-2.5.1

# SFML-INCLUDE = -I $(SFML-DIR)/include
# GS2D-INCLUDE = -I ../gs2d/include

# GS2D-LIB-LOCATION = -L ../gs2d/lib
# SFML-LIB-LOCATION = -L $(SFML-DIR)/lib
```

Same as before, you will need to uncomment these variables definitions and
alter SFML-DIR's value if SFML directory is not located at the root
of the project, or if the downloaded version is not 2.5.1.

## All set

Go to the *sample* directory of this project. And run:

```
make
```

Now, if you followed the [Step 4.1: Exporting the libraries locations](https://github.com/murilobnt/gs2d_engine/blob/master/.github/installation.md#step-41-exporting-the-libraries-locations),
the following command should be successfully executed.

```
./bin/sample
```

Otherwise, you need to export the path to the GS2D and SFML libraries **on the first execution**.

```
export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:<SFML-DIRECTORY-PATH>/lib" && export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:<GS2D-DIRECTORY-PATH>/gs2d/lib" && ./bin/sample
```

[Return to readme](https://github.com/murilobnt/gs2d_engine#installation)
