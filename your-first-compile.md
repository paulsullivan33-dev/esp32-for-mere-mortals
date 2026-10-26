# Your First Compile

Outcome: you can build a sketch into
firmware, read the report the build
gives back, and say exactly which
questions the compile has *not*
answered.

A **sketch** lives in a folder of its
own name, holding a file of the same
name ending in `.ino` — the lab's
first is `esp32-lab/sketches/blink/`,
containing `blink.ino`. That naming
rule is the Arduino way and the tools
enforce it without discussion. The
sketch itself is chapter 4's shape: a
`setup()` that sets a pin to be an
output and opens the serial line, and
a `loop()` that raises and lowers the
pin once a second, saying so each
time. Eleven lines of consequence;
everything else in this chapter is the
machinery around them.

## The command, taken apart

```bash
arduino-cli compile --fqbn esp32:esp32:esp32 esp32-lab/sketches/blink
```

`compile` is the job. The sketch folder
is the input. `--fqbn` carries chapter
5's board name — *this build is for a
generic original ESP32* — and it is
the single most important flag in the
command, because the same sketch built
under another chip's name is firmware
for a board you may not own. Run it,
and the first build takes a while: the
whole core is compiled once and cached,
so later builds of later sketches take
seconds. The lab's record is
transcript `t01-blink-compile.txt`,
and its ending is the paragraph this
whole guide keeps quoting:

```text
Sketch uses 271704 bytes (20%) of program storage space. Maximum is 1310720 bytes.
Global variables use 22116 bytes (6%) of dynamic memory, leaving 305564 bytes for local variables. Maximum is 327680 bytes.
```

What the build actually did, in order:
it stitched the sketch and the core
into one C++ program, compiled that
program and every library it used with
the Xtensa compiler from chapter 5,
**linked** the pieces into a single
executable image (the file ending in
`.bin`), and packaged alongside it the
board's **bootloader** and
**partition table** from chapter 12's
world. A second file, the *merged*
image, contains all of it laid out
exactly as it will sit in a 4 MB
flash — the whole estate, ready to be
written in one pass.

## Reading the two numbers

The first number is **program storage**:
your code's share of the app
**partition**. Note the maximum —
1,310,720 bytes is not the module's
4 MB; it is the size of the home this
partition table gives one firmware
image (chapter 12 explains where the
rest went: a second home for updates,
and storage). Twenty percent for a
blink means the ceiling is rarely the
problem beginners fear.

The second number is **dynamic
memory**: the working RAM your global
variables occupy before `setup()` even
runs, out of 327,680 bytes — the
original chip's headline RAM. What it
does not count is just as important:
memory the program claims *while
running* (strings being built, network
buffers, the JSON document of chapter
11) comes out of the same estate, and
running out is a crash the compile
cannot predict. One more pool goes
uncounted entirely: **PSRAM**, the
extra RAM on WROVER-class modules
(chapter 3), is not part of either
number; sketches must ask for it
deliberately, and the report stays
silent about it.

## The Wi-Fi lesson, in one comparison

The lab compiled its other sketches
the same way, and the comparison is
the cheapest education in this guide.
Blink: 271,704 bytes. The JSON sketch
(chapter 11): 276,812 — a good library
for the price of a paragraph. And the
Wi-Fi scan (chapter 8): **877,284
bytes, 66% of the partition, and
45,680 bytes of globals** — because
asking for `WiFi.h` links the radio's
whole world: the network stack, the
encryption, the works. Nothing is
wrong; that is simply what Wi-Fi
costs on this chip, printed before
you promise it to a smaller partition.
Transcripts `t02` and `t03` keep both
reports.

## What the compile cannot tell you

A clean compile proves the program is
*well-formed and fits*. It does not
prove the pin you chose exists on your
board, that the LED is on GPIO 2 on
yours, that the network password is
right, or that the board will not
brown out when the radio wakes
(chapter 15). Sending the firmware
down the cable — **uploading** — is
the other half of the ceremony: the
tool writes the bootloader, the
partition table and your image to
their flash addresses, with the board
held in download mode by its BOOT
button or its own circuitry. On the
lab's bench there was no board to
receive it, so this guide teaches
uploading from the documentation and
says so — while insisting on the
chapter's real lesson, which the
transcripts *do* prove: if you cannot
compile it cleanly and read the
report, the cable was never the
problem.

Check: compile the three lab sketches
and explain, in one sentence each, why
their sizes differ. That sentence is
chapter 6 learned.
