NetBSD support in hbottom(1)
===

This implementation utilizes kvm_getprocs(3), sysctl(3), etc, eliminating the
need for mount_procfs(8) with Linux compatibility enabled.

The implementation was initially based on the OpenBSD support in hbottom(1).

Notes on NetBSD curses
---

NetBSD is one of the last operating systems to use and maintain its own
implementation of Curses.

hbottom(1) can be compiled against either ncurses or NetBSD's curses(3).
By default, hbottom(1) will use ncurses when it is found, as support for NetBSD's
curses in hbottom is limited.

To use NetBSD's libcurses, hbottom(1) must be configured with `--disable-unicode`.
Starting with hbottom 3.4.0, a new option `--with-curses=curses` may be specified
to let `configure` skip ncurses when both libraries are installed.

Technical caveats regarding NetBSD's curses support:

* hbottom with Unicode enabled directly accesses ncurses's `cchar_t` struct, which
  has different contents in NetBSD's curses.

* Versions of libcurses in NetBSD 9 and prior have no mouse support
  (this is an ncurses extension). Newer versions contain no-op mouse functions
  for compatibility with ncurses.

What needs improvement
---

* Kernel and userspace threads are not displayed or counted -
  maybe look at NetBSD top(1).
* Support for compiling using libcurses's Unicode support.
* Support for fstat(1) (view open files, like lsof(8) on Linux).
* Support for ktrace(1) (like strace(1) on Linux).
