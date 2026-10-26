# Deep Sleep and Power Budgets

Outcome: you can estimate, on paper,
how long a battery project will live —
and you know why the estimate, not the
battery, is usually what needs fixing.

An awake ESP32 is a hungry chip. The
radios see to that: while Wi-Fi is
connected and listening, the board
draws on the order of a hundred
milliamps, with brief transmit peaks
several times that (chapter 1's weak-
USB resets live here). No pocketable
battery feeds that for long. The
family's answer is to be awake as
rarely as possible — and the headline
feature is **deep sleep**, a state in
which nearly everything on the chip is
off, the draw falls to microamps, and
a timer or a pin wakes it to run the
program from the top again.

## What sleep actually means here

Deep sleep is not a pause. The main
processors stop, their memory loses
power and forgets, and when the wake
comes the chip **resets**: your sketch
starts at `setup()` as if the power
had just arrived, every time. What
survives is small and deliberate — a
slow **RTC** clock domain with a few
kilobytes of special memory
(`RTC_DATA_ATTR` in the Arduino core
marks a variable to live there), the
wake timer, and whatever you saved to
flash. The wake causes are a short,
useful list: the **timer** (wake in an
hour), a **pin** changing (a door
opened, a button pressed — wake on
touch works too, on the touch pins of
chapter 7), and combinations.

Two lighter sleeps exist and are
mostly waystations: modem sleep dozes
the radio between network beacons, and
light sleep pauses the processors
while keeping memory and the
connection's threads. Real battery
projects live in deep sleep and treat
the lighter two as seasoning.

## The arithmetic that decides everything

A battery's capacity is printed on it
in **milliamp-hours**, mAh: the
product of current and time it can
deliver. Lifetime is one division,
done honestly:

> hours of life = capacity in mAh ÷
> average current in mA

and the average is where projects lie
to themselves. Work it for a fictional
workshop sensor that wakes every 10
minutes, takes 3 seconds awake at
120 mA to measure and send, and
sleeps at 0.15 mA on a good board:

- Awake share per hour: 6 wakes ×
  3 s = 18 s at 120 mA.
- Asleep share: 3582 s at 0.15 mA.
- Average = (18 × 120 + 3582 × 0.15)
  ÷ 3600 = (2160 + 537) ÷ 3600 ≈
  **0.75 mA**.
- A 2000 mAh cell: 2000 ÷ 0.75 ≈
  2670 hours ≈ **111 days**.

Now the two lessons hidden in those
numbers. First, the awake seconds are
nearly all of the cost even at six
wakes an hour — shorten the awake time
(connect faster, send once, no cheerful
LED) before buying a bigger battery.
Second, the sleep figure dominates the
moment wakes get rarer — and the
sleeping current of a whole *dev board*
is often far worse than the chip's:
the USB-to-serial chip, the power LED
and a thirsty voltage regulator can
hold a board at 5–10 mA while the
ESP32 itself sleeps at microamps, and
no sketch can fix soldering. Battery
designs therefore end up on bare
modules or boards built for the job,
with the LED considered a feature to
justify, not a default.

## The battery itself, and the safety rule again

Chapter 1's warning returns with its
working clothes on. A **LiPo** cell is
the usual choice for a rechargeable
node: flat, light, and 3.7 V nominal —
which still needs the right regulator
and a proper charge circuit between it
and any USB power, ideally one the
board maker already fitted and
documented (chapter 3's battery socket
question). It is not a coin cell: a
coin cell is a low-energy, forgiving
chemistry that can barely source this
chip's transmit peaks at all, while a
LiPo can deliver enough current to
heat, swell and burn if it is shorted,
crushed or charged by the wrong
circuit. Handle it as stored energy,
inspect it before trusting it, and
retire a puffy one. And run the
arithmetic the other way once: a
project that never sleeps, at 120 mA
average, empties that same 2000 mAh
cell in about 16 hours. Sleep is not
an optimisation on this chip. It is
the difference between a gadget and a
chore.
