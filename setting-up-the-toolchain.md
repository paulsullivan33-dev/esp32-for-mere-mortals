# Setting Up the Toolchain

Outcome: on your computer there is a
command that turns a sketch into
firmware, the ESP32 core is installed,
and you can name every part of what
just happened.

The **toolchain** is the set of
programs that build your program: a
**compiler** for the chip's processors,
the **core** libraries of chapter 4,
and a tool to drive them. This guide
uses **arduino-cli**, the Arduino
project's command-line driver — no
graphical IDE required, every step
typed, repeatable, and recordable. The
Arduino IDE itself uses this same
engine under its windows; learning the
commands teaches both.

## Installing arduino-cli

One download from the Arduino project,
unpacked wherever you keep tools. The
lab put it in a folder of its own and
asked it to introduce itself
(transcript `t00-toolchain-setup.txt`):

```bash
arduino-cli version
```

```text
arduino-cli  Version: 1.5.2-rc.1 Commit: fef6e48df Date: 2026-07-23T11:13:39Z
```

A version line back is the whole check:
the driver runs. Out of the box it
knows Arduino's own boards. The ESP32
is a guest, invited by name.

## Inviting the ESP32 core

Espressif publishes the core's address
— a **board manager URL** that tells
arduino-cli where the ESP32 packages
live. Two commands do the whole job:

```bash
arduino-cli core update-index --additional-urls https://espressif.github.io/arduino-esp32/package_esp32_index.json
arduino-cli core install esp32:esp32
```

The first fetches the catalogue; the
second downloads and installs the
**core**: the board definitions, the
libraries (Wi-Fi, Bluetooth, and the
rest of the chip's wardrobe), and the
two compiler toolchains the family
needs — Xtensa for the original and S
chips, RISC-V for the C and H chips of
chapter 2. It is a few hundred
megabytes and the slowest step in this
guide; the lab's first attempt died
twice on a stalled download and simply
ran again, which is the correct
response — fetched packages are kept,
and the retry resumes. Ask what you
have:

```bash
arduino-cli core list
arduino-cli lib install ArduinoJson
```

The lab also installed **ArduinoJson**
with that second command — one library
by name, from the public library index,
for chapter 11 — because libraries are
installed exactly the same way as
cores, and learning the gesture now
pays rent forever.

## Naming a board: the FQBN

Every build must name its target
exactly, in a string called the
**FQBN** — fully qualified board name.
For this guide's generic target, a
standard ESP32 dev board, it is:

```text
esp32:esp32:esp32
```

Read it as *packager : architecture :
board*. The first two parts are the
core you just installed; the third is
the board inside it, and the core
carries dozens — each variant in
`arduino-cli board listall esp32` is a
different third part, for the S3, the
C3, and specific makers' boards. Using
the wrong one compiles a program for a
chip you do not own, with pins you do
not have; chapter 15 charges rent for
that mistake. The guide standardises
on the generic name above and says so
wherever another target would change
the story.

## The last piece: the board itself

Nothing so far needed hardware. The
one hardware step in setup is plugging
the board in and watching a **serial
port** appear — on Linux a name like
`/dev/ttyUSB0` or `/dev/ttyACM0`, on
Windows a COM number:

```bash
arduino-cli board list
```

That command is where the board's
USB-to-serial chip introduces itself.
Boards differ: older designs carry a
separate translator chip (the CP210x
and CH340 names own most of the
driver hunts in chapter 15); boards on
native-USB chips present themselves
directly. Either way, *port appears*
is the check, and on real hardware it
is the moment chapter 6 stops being
theory: the same machine that compiled
the sketch can now be told to send it.
The lab had no board to plug in, and
says so wherever it matters; its
transcripts end at the compile, which
is the half of the ceremony this
chapter owns.
