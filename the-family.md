# The Family, Honestly Compared

Outcome: you can look at a chip name
like ESP32-S3 or ESP32-C6 and say what
it is for, what it cannot do, and
whether it is the one your project
wants — before money changes hands.

"ESP32" on a shop listing is a family
name, not a chip. **Espressif**, the
company that designs the line, has
released a shelf of related chips over
a decade, all programmed the same way
and all carrying radios — but they
differ in processor, in which radios,
and in price. Sellers do not always
make the difference obvious, and the
cheapest listing is often the oldest
chip. This chapter is the map.

## The original ESP32

The chip that started it, still sold
everywhere as plain "ESP32". Two
processor cores (a **dual-core**
Xtensa design) running up to 240 MHz,
Wi-Fi (2.4 GHz only), and *both*
Bluetooth flavours: classic Bluetooth
and **Bluetooth Low Energy**, usually
shortened to **BLE**. Generous pins,
two analogue-to-digital converters,
touch sensing, the works. If a project
plan just says "an ESP32", it means
this one, and it remains a perfectly
good default: the most tutorials, the
most libraries tested against it, the
fewest surprises. Its honest weaknesses
are age: no USB of its own (boards add
a separate USB-to-serial chip), and it
is the hungriest of the family when
awake.

## The single-core successors: S2 and C3

The **ESP32-S2** is a single-core chip
with Wi-Fi only — no Bluetooth at all.
It added native USB (the chip can be
its own USB device), which made it a
favourite for little USB gadgets. Buy
it when a project specifically wants
that USB trick or the price is
irresistible; be surprised by nothing:
the missing Bluetooth is the trap
buyers fall into.

The **ESP32-C3** is also single-core,
but a different architecture — **RISC-V**,
an open processor design, instead of
Xtensa. Wi-Fi plus BLE, no classic
Bluetooth, a modest pin count, native
USB on its serial lines, and low sleep
currents. It is the family's budget
sensor chip: cheap, sips power, plenty
for a thermometer that phones home. Its
trap is the reverse of the S2's: one
core and fewer pins than the original,
which a growing project can feel.

## The S3: the current flagship for makers

The **ESP32-S3** is dual-core Xtensa
again, faster, with more memory
options, native USB that can act as a
device *or* a host, BLE (still no
classic Bluetooth), and extra machine-
learning instructions in the processor
that help with voice and vision tricks.
Display boards and camera boards are
usually built on it. If you are buying
one chip today for projects that might
grow — screens, microphones, a camera —
the S3 is the sensible default, and it
is the chip inside most current
all-in-one display boards (chapter 3).

## The new radios: C6 and H2

Two recent chips exist mostly to add
radio standards the older ones lack.

The **ESP32-C6** is a RISC-V chip with
Wi-Fi 6 (still 2.4 GHz only), BLE, and
radios for **Thread** and **Zigbee** —
the mesh protocols modern smart-home
gear uses, with support for the
**Matter** standard built on them. Buy
it when the project is a smart-home
device that must speak to a Matter or
Thread network. Otherwise its smaller
memory and single core make the C3 or
S3 the better buy.

The **ESP32-H2** is the odd one: *no
Wi-Fi at all*. BLE plus Thread/Zigbee
only, meant for battery devices that
join a mesh and never touch a router.
It confuses buyers precisely because
the family name promises Wi-Fi. Check
for it in listings, then check again.

## The table, and how to use it

| Chip | Cores | Wi-Fi | Bluetooth | Native USB | Built for |
| --- | --- | --- | --- | --- | --- |
| ESP32 | 2, Xtensa | 2.4 GHz | Classic + BLE | No | The all-rounder |
| ESP32-S2 | 1, Xtensa | 2.4 GHz | None | Yes | USB gadgets |
| ESP32-S3 | 2, Xtensa | 2.4 GHz | BLE only | Yes | Displays, cameras, voice |
| ESP32-C3 | 1, RISC-V | 2.4 GHz | BLE only | Yes | Cheap sleepy sensors |
| ESP32-C6 | 1, RISC-V | Wi-Fi 6 | BLE + Thread/Zigbee | Yes | Matter and Thread gear |
| ESP32-H2 | 1, RISC-V | None | BLE + Thread/Zigbee | Yes | Mesh-only battery nodes |

Three rules cover most purchases.
First, **no ESP32 of any kind does
5 GHz Wi-Fi** — every chip in the
family is 2.4 GHz only, and a network
that hides its 2.4 GHz band will defeat
all of them (chapter 14). Second,
**classic Bluetooth lives only on the
original**: audio streaming to old
Bluetooth speakers and serial-over-
Bluetooth tricks need that chip and no
other. Third, **development boards mix
these freely**: the same shop may sell
five boards that all say "ESP32" in
the title and carry three different
chips. The chip name is in the fine
print, the module's metal can
(chapter 3), and the board's
documentation — look there, not at
the headline.

Check: take any listing you can find
and name its chip from the module or
specification section, not the title.
If you cannot find the chip named
anywhere, that is the listing telling
you something.

## A note on names that are not chips

Listings also wave numbers like
"WROOM" and "WROVER" — those are
**modules**, the chip plus flash memory
and an antenna in a soldered-down can
(chapter 3). A WROOM module carries the
original ESP32; an S3 module is
labelled with its own S3 name. The chip
inside is what decides everything in
this chapter's table; the module name
decides the memory size and whether a
little extra RAM rides along. Both
matter, in that order.
