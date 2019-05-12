# Adventures on the Wheels of Steel<sup>*</sup>

### Place blocks on the turntable

### Make some noise!

![Adventures on the Wheels of Steel](/Images/completed1.JPG)

## What is this?

*Adventures on the Wheels of Steel* is a tangible sequencer that allows users to create their own MIDI patterns by placing small objects, in this case lego blocks covered with colored tape, on a rotating disk found on turntables. The physical interface allows users to make beats, play chords or notes using the 4 channels. All channels are equiped with color recognition which creates room for greater variability. It utilizes Arduino Leonardo's native USB connectivity to tranfer MIDI messages to any Digital Audio Workstation imagenable. 
 
## Why is this made? 

The project has been created as part of 49-719 *Internet of Things - In Depth* class that I've attended at Carnegie Mellon University during Spring 2019 semester. *Adventures on the Wheels of Steel* pays homage to the legendary Grand Master Flash, who single handedly redefined the use of turntables in music, while investigating how tangible interfaces can ease and enchant the idea generation process during music making. 

## How did I end up here?

When I first entered electrical engineering school back in 2012, I had a dream of creating electronic music instruments, guitar pedals and amplifiers. Unfortunately, I learnt the hard way that undergraduate engineering school is not really the place where dreams come true. This is not true for graduate education though.

Long story short, when I was given the chance to work on any project idea I want for 6 weeks, I knew that I was going to create something to do with music. All the pieces came together when I stumbled upon the Beat Blox project created by Per Holmquist. I looked at his take on the turntable as a tool to create music and said "I can make that". Then for 6 weeks I focused my energy on replicating his design and trying to find ways of adding features that can make it more expressive and adaptable. I thought that to create a real music making tool, I needed to integrate MIDI to the design and add a way of creating variation.  

### Inspiration

I got most of my inspiration from this project. Its simple beautiful at the same time. Check it out before you continue to understand where I'm coming from.

[Beat Blox by Per Holmquist](https://open.spotify.com/track/7xMzNQkDzu3JZkhURGvH7p?si=wFec3MJkSc-wyBhV8cBQGQ)

### Forerunners

Tangible interfaces are not anything new for electronic music making tools. Here are some of the recent examples that I looked at while working on my design. The beauty of making things with technology is that when you figure out a way to make a particular tool, adapting your findings to create designs that are similar on the inside but different on the outside is easy. So here are some inspiration for everyone who wants to create their own MIDI controllers.   

[Spinning Disc Step Sequencer](https://learn.adafruit.com/spinning-disc-step-sequencer/overview)

[Coin Sequencer](http://www.varal.org/coinsequencer/)

[Tquencer](https://jensvetter.de/files/pdf/tquencer_acm.pdf)

[UTS-1](https://www.youtube.com/watch?v=3NAn9fSdh8M)

[XOXX Composer](http://xoxxcomposer.axelbluhme.se/)

## How can you make this? 



### Components

1. 1 x Arduino Leonardo
1. 1 x [SparkFun Multiplexer Breakout - 8 Channel](https://www.sparkfun.com/products/13906)
1. 1 x [Byron Statics Record Player](https://www.amazon.com/gp/product/B07J2NZLZS/ref=ppx_yo_dt_b_asin_title_o03_s00?ie=UTF8&psc=1)
1. 4 x [Adafruit APDS9940](https://www.adafruit.com/product/3595) 
1. 4 x [Adafruit LED Sequins - Warm White](https://www.adafruit.com/product/1758)

### Circuit 

#### Basic Circuit 

![Basic Circuit](/Schematics/tonearm_basic.png)

#### Initial Prototype

![Initial Prototype](/Schematics/tonearm_prototype.png)

#### Final Circuit

![Final Circuit](/Schematics/tonearm_final.png)

### Code

[You can reach the final code here](/Code/tonearm.ino)

### Form  

#### "With A Little Help From My Friends"<sup>**</sup>

Final tonearm form designed by [Özgüç Bertuğ Çapunaman](https://github.com/ozgucbertug) on Rhino.

#### Tonearm

![Tonearm Form](/Form/tonearm.gif)

[Tonearm Lasercutting Pattern](tonearm.dxf)

## Related Resources

[Selfmade Tutorial on MIDI & Arduino](https://github.com/cemergin/Adventures-on-the-Wheels-of-Steel/blob/master/Tutorials/MIDI101_%231.md)

[Introduction to MIDI by the MIDI Association](https://www.midi.org/images/easyblog_articles/43/intromidi.pdf)

[MIDI Message Codes Explained](http://www.songstuff.com/recording/article/midi_message_format/)

[Arduino MIDI Output Basics](https://www.midi.org/articles-old/arduino-midi-output-basics)

[MIDI Output Using an Arduino](http://itp.nyu.edu/physcomp/labs/labs-serial-communication/lab-midi-output-using-an-arduino/)

[Arduino MIDIUSB Library](https://www.arduino.cc/en/Reference/MIDIUSB)

## Notes

* [Grandmaster Flash & the Furious Five - Adventures of Grand Master Flash On the Wheels of Steel](https://open.spotify.com/track/7xMzNQkDzu3JZkhURGvH7p?si=wFec3MJkSc-wyBhV8cBQGQ)

** [The Beatles - With A Little Help From My Friends](https://open.spotify.com/track/2RnPATK99oGOZygnD2GTO6?si=fi9PeBmyTsGBMCBx69-2zQ)
