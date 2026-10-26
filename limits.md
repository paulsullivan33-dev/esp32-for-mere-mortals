# Limits

Outcome: you can recite what this
chip will not do, so a project plan
never leans on a rumour.

Every tool's marketing is a list of
its strengths. This chapter is the
other list, stated plainly, in one
place — several entries have appeared
in earlier chapters and are collected
here because limits deserve a home,
not a scattering of footnotes.

**2.4 GHz, forever.** Every chip in
the family hears and speaks only the
2.4 GHz Wi-Fi band (chapter 2). A
5 GHz-only network is a wall, not a
configuration problem, and no firmware
update can grow a second radio.

**It is not a Linux computer.** No
shell, no filesystem full of programs,
no installing packages on the device,
no running the tools of chapter 5 on
the chip itself. One firmware, yours,
does the whole job. Projects that
quietly assume otherwise ("and then it
can just run a script") die here; the
Pi of chapter 13 is the honest
alternative.

**Real time is a promise with edges.**
The chip is fast and its interrupts
are quick, but the radios share the
processors: a Wi-Fi burst can delay
your timing loops, and microsecond
promises need the hardware timers and
care, not `delay()` and hope. Motor
control at the serious end and audio
sample-clock work are possible and
expert, in that order.

**The ADC is a guide, not a gauge.**
Chapter 7's verdict stands in the
limits chapter too: nonlinear at the
ends, noisy without averaging, ADC2
unusable while Wi-Fi runs. Fine for
thresholds and trends; the wrong part
for a measurement you would defend.

**Memory is real and small.** A few
hundred kilobytes of working RAM is
the whole estate (chapter 6's second
number). TLS connections, camera
frames and JSON documents all draw
from it; PSRAM modules (chapter 3)
widen the estate at a speed cost.
Programs written as if memory were a
desktop's end in the watchdog's bark.

**A pin is not a power supply.**
Tens of milliamps per pin, 3.3 V
always (chapter 7). Motors, relays,
lamps and LED strips get their own
supply and a switching transistor.
This limit is listed here as well as
in chapter 1 because ignoring it is
the one that produces smoke.

**Physically accessible means
programmable.** Anyone who can hold
the board can reflash it through its
serial lines unless the one-way eFuse
security features (chapter 12's
armour, burned deliberately through
ESP-IDF) have been set — and those
are one-way. A deployed ESP32 should never
be the sole guardian of a secret, a
door, or a payment. It is a citizen of
the network, not its police.

**Sleep is the boards' problem too.**
The chip's microamps are only as real
as the board around it lets them be
(chapter 10): USB chips, LEDs and
regulators on a desk-friendly dev
board can out-draw the sleeping chip
a hundredfold. Battery promises are
made by the whole board, not the
chip's datasheet.

**The documentation is a landscape,
not a book.** Espressif's references
are thorough and versioned per chip;
the community's tutorials are vast
and of every age, and a 2017 answer
may describe a core that no longer
exists. Even this guide's neighbour,
chapter 13, will age. Trust the
pinout, the datasheet and the build
report over the forum's confidence.

And the safety limit that outranks
the specifications: the chip's world
is **3.3 V logic and modest currents**,
and the batteries that feed it for a
year are stored energy that commands
respect (chapters 1 and 10). A LiPo
is not a coin cell; a GPIO is not a
mains switch; and nothing in this
family is a life-safety device. Build
so that a firmware bug is an anecdote,
never an incident.
