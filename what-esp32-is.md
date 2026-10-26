# What the ESP32 Is

Most computers you meet are general
purpose: they run an operating system,
many programs at once, and whatever you
ask next. An **ESP32** is the opposite
kind of computer. It is a
**microcontroller** — a small, cheap,
self-contained chip that runs one
program, yours, directly on the metal,
from the moment power arrives until the
moment it leaves. No desktop, no login,
no updates installing themselves in the
night. If you have ever wished a sensor
could notice something and tell your
phone, or a workshop gauge could draw
its own dial, this is the class of chip
that does it.

What makes the ESP32 the famous one of
its class is what is built in. The chip's
full title is **system on a chip**, or
**SoC**: besides the processor cores and
memory, the silicon itself carries a
**Wi-Fi** radio and a **Bluetooth**
radio. On older microcontrollers,
wireless meant a second board, a second
chip, and a conversation between them
that you had to arrange. Here it is one
chip, one program, and a library call.
That single fact — radios included, for
a few pounds or dollars — is why ESP32
boards turn up in smart plugs, weather
stations, robot kits, badge projects and
a thousand workshop one-offs.

Your program for an ESP32 is usually
called a **sketch** (a name inherited
from Arduino, chapter 4) or, once built,
**firmware** — software that lives in
the chip's flash memory and runs the
device it is part of. You write it on a
real computer, **compile** it there
(chapter 6 takes that apart), and send
the result down a USB cable to the
board. The board then runs it alone.

## The safety rules, before anything else

Electronics adds something software
guides can skip: mistakes here can
damage hardware, and one common battery
chemistry can catch fire if mistreated.
This guide's rules are short, and they
are stated here, in chapter 1, before
any procedure depends on them:

> **The ESP32 is a 3.3 volt chip.**
> Its pins speak 3.3 V logic and are
> *not* tolerant of 5 V. Power it from
> the rail the board maker specifies,
> never feed a pin more than 3.3 V, and
> treat a lithium polymer battery with
> the respect a stored fire deserves.

Three consequences run through the
whole guide. First, **logic levels**:
many older sensors and nearly all
classic Arduino boards work at 5 V, and
connecting a 5 V output straight into an
ESP32 pin can kill that pin or the chip
(chapter 7 names the level shifter that
solves it). Second, **power**: the chip
can draw brief peaks of several hundred
milliamps when its radio transmits, so a
weak USB port or a tired cable can cause
mysterious resets that look exactly like
software bugs (chapter 15). Third,
**batteries**: a **LiPo** — a lithium
polymer pouch cell — holds a great deal
of energy in a soft package. It is not
a coin cell. It needs a proper charger
circuit, it must never be punctured,
short-circuited or charged unattended
in a pile of paper, and a swollen one
is retired, not squeezed back into a
case. Chapter 10 does the battery
arithmetic; the handling rule is here.

## Who it is for

The maker with a job shaped like *sense
something, then report it*: a greenhouse
that texts when it is dry, a freezer
alarm, a door that logs its own opening.
The programmer who knows software and
wants one honest step into hardware,
with a chip whose mistakes cost a few
dollars. The student who wants Wi-Fi and
Bluetooth without a radio-engineering
degree. The common thread is a small,
well-defined job, done by a chip that
costs less than the cable that programs
it.

## What it is not

An ESP32 is not a small Linux computer.
It has no operating system in the usual
sense, no shell, no files full of other
people's programs; if you want to run
Python scripts, edit files on the
device and install packages, a Raspberry
Pi-class board (chapter 13) is the right
tool and the ESP32 is not a cheap
substitute. It is not a precision
instrument: its analogue inputs are
useful and a little rough (chapter 7 is
honest about them). It is not a security
appliance: it can do proper encrypted
connections, but a chip anyone can pick
up and reflash should never be the only
lock on anything that matters (chapter
14). And it is not magic about power:
the radios that make it famous are the
radios that empty batteries, and chapter
10 shows the arithmetic that decides
whether a project runs for a weekend or
a year.

## A first taste

After the toolchain is installed
(chapter 5), this is the whole ceremony
for building a program and checking its
size — run on the lab's machine, against
a workshop sensor sketch this guide
writes in chapter 6:

```bash
arduino-cli compile --fqbn esp32:esp32:esp32 esp32-lab/sketches/blink
```

The compiler answers with two numbers
that become old friends: how much of the
chip's program memory the sketch uses,
and how much of its working memory.
The lab's record of that build,
transcript `esp32-lab/transcripts/t01-blink-compile.txt`,
ends:

```text
Sketch uses 271704 bytes (20%) of program storage space. Maximum is 1310720 bytes.
Global variables use 22116 bytes (6%) of dynamic memory, leaving 305564 bytes for local variables. Maximum is 327680 bytes.
```

If your program fits, the same file can
be sent to a board. Whether it then
*works* is a question only the board can
answer — which is why this guide is
careful, everywhere, about the difference
between *compiled* (proven here) and
*running on hardware* (proven only when
someone holds the board). Chapter 5
starts the honest path: setting up the
tools.
