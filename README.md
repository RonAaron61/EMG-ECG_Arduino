# EMG-ECG_Arduino
Making EMG (and ECG) sensor with adjutable gain that can be used wth arduino 

## Abstract

abstract

## What is EMG

Electromyography (EMG) is a technique for evaluating and recording the electrical activity produced by skeletal muscles. EMG is performed using an instrument called an electromyograph to produce a record called an electromyogram. An electromyograph detects the electric potential generated by muscle cells when these cells are electrically or neurologically activated. The signals can be analyzed to detect abnormalities, activation level, or recruitment order, or to analyze the biomechanics of human or animal movement. [(Wikipedia)](https://en.wikipedia.org/wiki/Electromyography)

But in this case I want to make EMG sensor that can measure if there's muscles activity and read it with arduino, so it can be used to maybe control some robot hand or something.

## How to make

The basic of EMG sensor is first we will capture signal data through the surface of the skin using electrodes, then the signal will be amplified. after the signal is amplified, the signal needs to be filtered, generally the filter is done in the form of a bandpass and/or notchpass filter, because EMG signals are generally in the range 0-500 Hz so a bandpass filter is needed, after going through the filter, the signal will be amplified again.


## Component

For this project I will use AD620 for the pre-amp, and LM358 to amplified it again

The filters I will be using are a bandpass filter

Component used:

IC:
- AD620 (instrument amplifier)
- LM358 (Op-Amp)

Resistor:
- 10 kΩ (2)
- 330 Ω (2)
- 33 kΩ (1)
- Trimpot or potentiometer (I used 50 kΩ)

Capacitor:
- 10 nF (1)
- 10 uF (1)
- 220 uF (1)

Other:
- Diode (1)
- LM7660 module (you can also use MC34063A positive to negative module)

## Schematic

![image](https://user-images.githubusercontent.com/105662575/234283722-94559312-6164-4e0a-9ef0-4037cd8fb142.png)

->
- R1 -> 330 Ω
- R2 -> 50 kΩ trimpot
- R3 -> 33 kΩ
- R4, R5 -> 10 kΩ
- C1 -> 220 uF
- C2 -> 10 nF
- C3 -> 10 uF

#### AD620

The AD620 is an instrument amplifier with adjustable gain, I connected the gain pin (Rg) to trimpot to adjust the gain more easily. The formula to find the gain is as follow:

G = (49.4 kΩ / Rg) + 1

I set the trimpot in 2.5 kΩ so the gain I use is around 21x 


#### Band Pass Filter

The band pass consist of HPF (High Pass Filter) and LPF (Low Pass Filter), for the HPF the Fc (cut-off frequency) is around 2.2 Hz, and for LPF the Fc is 480 Hz. The band pass filter also amplified the signal by 100 gain as shown below

![Dokumen 6_2](https://user-images.githubusercontent.com/105662575/234286106-dc7a7b0a-7a6c-499e-833d-6aa2df8b0442.jpg)


on the output after the bandpass filter I make two output, one with voltage divider and one with diode connected. 

In the Output-1 I connect it with voltage divider so the signal is on 2.5 V offset (so the signal is on the middle of the graph), use this if you want to see the full signal (negative and positive signal) especially for ECG signal. If you just want to see the positive signal use the diode, personally I use this to view the EMG signal because I find this easier to read and to program to control servo motor, because I just use the peak (positive) signal


#### Notch filter (optional)

If you want to remove 50 Hz/60 Hz noise caused by power line you can add notch filter to remove it. You can use Twin T notch filter to use it. To filter 50 Hz noise you can use as follow:

![Dokumen 7_2](https://user-images.githubusercontent.com/105662575/234292294-a64a65ab-149f-4ad1-adb7-fae0b3fe7e1a.jpg)

or if you want to use other value for the resistor and capacitor you can play with it, I find this [{website}](http://sim.okawa-denshi.jp/en/TwinTCRkeisan.htm) that you can use to calculate the value of resistor/capacitor or the frequency. 


### Prototype

![IMG_20230425_203051](https://user-images.githubusercontent.com/105662575/234293371-a444c702-f697-49a7-96c6-6d64cd500c35.jpg)


### Cdoe



## Result

result
