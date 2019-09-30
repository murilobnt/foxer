# Installation with sudo

> This guide is related to the case you have SFML library installed in a
> g++ standard path (if you installed it with apt or moved it to /usr/local).
>
> This guide is only granted for the Linux Ubuntu distro.

## Step 1: Download the repository

To install Foxer you first need to clone or download the ZIP of this repository.

## Step 2: Install this project's dependencies

Check [this page of the wiki](https://github.com/murilobnt/foxer/wiki/Insight:-Starting-point#install-dependencies).

## Step 3: Install the Framework library

Once you've downloaded/cloned this repository, and made sure you have GCC and
SFML (in a recognizable library path of g++) installed, the following command,
through terminal, and at the root of the project, should suffice.

```sh
sudo make install
```

### Step 3.1: Exporting the library location

Following the GNU standards, the library and the headers of this Framework will be
located at */usr/local/lib* and */usr/local/include*. Those directories,
however, are commonly not searched by default.

This shows true for Ubuntu 18.04, too. To easily solve this, you can
**add this line to the end of your ~/.bashrc (if you use bash) or ~/.zshrc
(if you use zsh) file**.

```sh
export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:/usr/local/lib"
```

## Check if the sample is working

Go to the *sample* directory of this project. And run:

```sh
make
```

Now, if you followed the [Step 3.1: Exporting the library location](https://github.com/murilobnt/foxer/blob/master/.github/installation/installation-sudo.md#step-31-exporting-the-library-location),
the following command should be successfully executed.

```sh
./bin/sample
```

Otherwise, you need to export the path to the library **on the first execution**.

```sh
export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:/usr/local/lib" && ./bin/sample
```

[Return to readme](https://github.com/murilobnt/foxer#installation)
