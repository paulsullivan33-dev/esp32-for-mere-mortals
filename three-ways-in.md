# Three Ways In

Outcome: you can name the three
supported ways to program an ESP32,
say what each costs and buys, and
choose one for a project without
mysticism — including the honest
answer, which is that most people
start with the first.

Every ESP32 program is written in one
of three environments. All three end
the same way: firmware in the chip's
flash, running your logic. They differ
in language, in how much of the chip
they show you, and in how much they
hide.

## The Arduino core: the front door

The **Arduino core for ESP32** is a
layer Espressif maintains that lets
ESP32 programs be written the Arduino
way: a `setup()` function that runs
once, a `loop()` function that repeats,
and a library of friendly calls —
`digitalWrite()` for pins, `WiFi.begin()`
for the network — over the chip's real
machinery. The language is C++, but the
subset most sketches use is small and
forgiving. The toolchain of chapter 5
and the builds of chapter 6 use this
core, and the huge shared library of
public Arduino code — sensor drivers,
display drivers, protocol helpers —
mostly works on it unchanged.

What it buys: the fastest path from a
bare board to a working thing, and the
largest pile of examples on earth. What
it costs: the layer hides the chip's
real operating system (a small
real-time system called **FreeRTOS**,
running underneath), so fine control
over timing, tasks and the deepest
power features eventually means
reaching past the friendly calls — the
core allows this, and chapter 10's
sleep calls are exactly such a reach.
For most projects, most of the time,
that trade is right.

## ESP-IDF: the house Espressif built

**ESP-IDF** — the IoT Development
Framework — is Espressif's own full
environment: C and C++ with no Arduino
layer, direct access to every register
of functionality the chip has, the
real FreeRTOS API, a configuration
system that tunes the firmware before
it builds, and the tools the module
factories themselves use. It is the
only way in that supports every chip
feature on the day the chip ships, and
the way commercial products are built.

What it buys: everything, eventually.
What it costs: a steeper first week.
The project layout, the build system
and the configuration menus are a
professional tool's, and a blink
program is fifty lines of ceremony
before it blinks. The standard advice
is honest: learn the chip on the
Arduino core, move to ESP-IDF when a
project's needs — precise timing,
partitions, signed firmware, the
newest chip on its launch month —
outgrow the front door. Nothing you
learn transfers badly; the hardware
chapters of this guide (pins, power,
radios) are true in both houses.

## MicroPython: the interpreter on the chip

**MicroPython** takes the opposite
deal: you flash one ready-made firmware
— the Python interpreter itself — onto
the chip once, and afterwards your
programs are Python files, sent to the
board and run by that interpreter.
There is even a live prompt: connect to
the board and type Python at it, and
the chip answers. For trying an idea,
teaching, or bending a sensor into
shape in an afternoon, nothing else is
as quick.

What it buys: Python, live, on a five
dollar chip, with Wi-Fi and pins as
importable modules. What it costs:
speed and memory — the interpreter
itself takes a large share of the
chip, interpreted code runs far slower
than compiled code, precise timing is
not its country, and the very newest
chip features arrive late or never.
Battery projects feel the memory and
power cost (chapter 10). It is a
genuine third way, not a toy: choose it
when the programmer's time is worth
more than the chip's, which is often.

## Choosing, in one paragraph

Start with the Arduino core unless you
already know why not. Choose ESP-IDF
when the project is a product, or
needs a feature the core has not
exposed, or is your deliberate next
step in learning the chip. Choose
MicroPython when the work is
exploratory, the timing is forgiving,
and Python fluency is the asset you
bring. And note the escape hatch all
three share: the chip does not care
which wrote its flash. A board can be
re-flashed from any way to any other
in minutes, forever — the choice is
per project, never a marriage.

This guide builds with the Arduino
core, because it is the front door and
because its command-line tool
(chapter 5) makes every build
repeatable and recordable — the lab's
transcripts are its receipts.
