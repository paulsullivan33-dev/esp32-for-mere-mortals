# Modules, Dev Boards and All-in-One Boards

Outcome: you can tell a bare chip, a
module and a development board apart
at a glance, read a board listing
without being fooled, and buy the
board a first project actually needs.

Nobody's first ESP32 is a bare chip.
The raw **SoC** is a square of silicon
a few millimetres across with pads
underneath that need a factory
soldering process. What you buy, at
every level, is that chip wrapped in
progressively more help.

## The module: the chip, dressed

A **module** is the chip soldered onto
a tiny board of its own, inside a
metal can that shields the radio and
carries its name in print. Inside the
can: the chip, its **flash memory**
(the storage your firmware lives in —
4 megabytes is the common size, 8 and
16 exist), a crystal to keep time, and
an **antenna**, either a copper shape
traced on the board or a tiny socket
for an external one. Espressif's module
names follow a pattern: WROOM for the
standard line, WROVER for variants
carrying extra **PSRAM** — a separate,
slower pool of RAM bolted on for jobs
like camera frames and big audio
buffers (chapter 6 shows where it
appears in a build report). Modules are
what factories buy by the reel, and
what the next layer is built from.

## The dev board: the module, made friendly

A **development board** — dev board,
devkit — is a module on a larger board
that adds everything a human at a desk
needs: a USB socket and the chip that
translates USB to the module's serial
lines (on chips without native USB),
a voltage regulator that turns USB's
5 V into the chip's 3.3 V (chapter 1's
safety rule, handled for you), reset
and boot buttons, a power LED, and two
rows of **header pins** that plug
straight into a solderless
**breadboard** for experiments. Names
like "ESP32 DevKit", "NodeMCU-32S" and
each maker's house brand all mean this
layer. This is what a beginner buys.
Two honest warnings: the cheapest dev
boards are wide enough to cover the
breadboard's centre gap and leave only
one row of holes free on each side,
which everyone hates exactly once; and
the USB socket tells you nothing about
the chip — read the module's can, not
the listing's headline (chapter 2).

## All-in-one boards: the module, plus a job

The third layer is a dev board that
also carries the project's hardware:
a screen, a camera, a relay, a row of
addressable LEDs, a battery charger.
**Display boards** are the popular
class: an ESP32 (often an S3, sometimes
the original) bonded to a touchscreen,
with the display's wiring already done
and a case-friendly shape. A whole
category of inexpensive touchscreen
panels from several makers follows this
pattern — a 2.8-inch class display, a
microSD slot, sometimes a small speaker
connector — and they are sold as one
unit at a gadget price. The honest
trade, in both directions: you skip
the fiddliest wiring in hobby
electronics (a parallel display bus is
nobody's friend), and in exchange you
accept the maker's choices — the pins
the screen consumed are gone (chapter
7), the documentation ranges from good
to a forum thread, and the touch
controller and display driver are
yours to match with libraries
(chapter 11). For a project whose job
*is* the screen — a status panel, a
control pad — they are the fastest
honest route. For learning the chip
itself, a plain dev board teaches more.

## What to buy first, and what to check

For a first board: a plain dev board
carrying the original ESP32 or an S3,
from a maker who publishes a pinout
diagram, with a USB socket that
matches a cable you own. Check, in the
listing or the maker's page, these
five things: the chip's exact name
(chapter 2's table); the flash size
(4 MB minimum); whether the antenna is
the board-traced kind (fine indoors)
or a socket (for a metal enclosure);
the board's width, if you will live on
a breadboard; and a published pinout —
a board without one is a puzzle sold
as a product. Everything else — a
second core, PSRAM, a battery socket —
is a chapter of this guide telling you
when you need it, and you mostly do
not, yet.

One more layer exists and is worth
naming so it never confuses you: some
boards carry *two* processors, the
ESP32 beside a second chip that runs
a screen or a keyboard. They are fine
products and poor first boards; the
guide's programs assume one chip,
programmed one way (chapter 4).

## The power socket question

Dev boards are usually powered from
their USB socket, and many also offer
a pin or a connector for battery power.
Read the maker's page for which pins
may be fed 5 V, which expect the
regulated 3.3 V, and whether USB and
battery may be connected at the same
time — the answers differ by board, and
guessing is how the smoke gets out
(chapter 10 does batteries properly).
This is the board-level face of
chapter 1's safety rule, and it is the
last general warning before the guide
starts plugging things in.
