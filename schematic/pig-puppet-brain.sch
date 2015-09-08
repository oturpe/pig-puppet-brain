<Qucs Schematic 0.0.18>
<Properties>
  <View=-47,-20,1073,987,3.20723,1969,1532>
  <Grid=10,10,1>
  <DataSet=pig-puppet-brain.dat>
  <DataDisplay=pig-puppet-brain.dpl>
  <OpenDisplay=1>
  <Script=pig-puppet-brain.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Title>
  <FrameText1=Drawn By:>
  <FrameText2=Date:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
  <.PortSym 40 20 1 0>
  <.PortSym 50 60 2 0>
  <.PortSym 50 100 3 0>
  <.PortSym 50 140 4 0>
  <.PortSym 50 180 5 0>
  <.PortSym 70 220 6 0>
  <.PortSym 70 260 7 0>
  <.PortSym 70 300 8 0>
  <.PortSym 70 340 9 0>
  <.PortSym 70 380 10 0>
  <.PortSym 70 420 11 0>
  <.PortSym 70 460 12 0>
  <.PortSym 70 500 13 0>
  <.PortSym 70 540 14 0>
  <.PortSym 70 580 15 0>
  <.PortSym 70 620 16 0>
</Symbol>
<Components>
  <R R2 1 400 60 -48 -54 0 0 "7 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <L L1 1 460 60 -4 -38 0 0 "1 nH" 0 "" 0>
  <Diode D1 1 420 100 -28 17 0 2 "1e-15 A" 0 "1" 0 "10 fF" 0 "0.5" 0 "0.7 V" 0 "0.5" 0 "0.0 fF" 0 "0.0" 0 "2.0" 0 "0.0 Ohm" 0 "0.0 ps" 0 "0" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0" 0 "1 mA" 0 "26.85" 0 "3.0" 0 "1.11" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "26.85" 0 "1.0" 0 "normal" 0>
  <_BJT TIP120C 1 350 90 -84 23 0 0 "npn" 0 "1e-16" 0 "1" 0 "1" 0 "0" 0 "0" 0 "0" 0 "0" 0 "0" 0 "1.5" 0 "0" 0 "2" 0 "100" 0 "1" 0 "0" 0 "0" 0 "0" 0 "0" 0 "0" 0 "0" 0 "0.75" 0 "0.33" 0 "0" 0 "0.75" 0 "0.33" 0 "1.0" 0 "0" 0 "0.75" 0 "0" 0 "0.5" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "26.85" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0.0" 0 "0.0" 0 "3.0" 0 "1.11" 0 "26.85" 0 "1.0" 0>
  <GND * 1 350 120 0 0 0 0>
  <R R1 1 290 90 -61 -54 0 0 "4.7 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <Port PD4 1 36 756 -23 12 0 0 "9" 0 "analog" 0>
  <R R7 1 326 726 -12 -53 0 0 "9 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <L L3 1 386 726 17 -34 0 0 "1 nH" 0 "" 0>
  <Diode D4 1 356 756 -28 17 0 2 "1e-15 A" 0 "1" 0 "10 fF" 0 "0.5" 0 "0.7 V" 0 "0.5" 0 "0.0 fF" 0 "0.0" 0 "2.0" 0 "0.0 Ohm" 0 "0.0 ps" 0 "0" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0" 0 "1 mA" 0 "26.85" 0 "3.0" 0 "1.11" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "26.85" 0 "1.0" 0 "normal" 0>
  <_BJT TIP120 1 236 756 19 -7 0 0 "npn" 0 "1e-16" 0 "1" 0 "1" 0 "0" 0 "0" 0 "0" 0 "0" 0 "0" 0 "1.5" 0 "0" 0 "2" 0 "100" 0 "1" 0 "0" 0 "0" 0 "0" 0 "0" 0 "0" 0 "0" 0 "0.75" 0 "0.33" 0 "0" 0 "0.75" 0 "0.33" 0 "1.0" 0 "0" 0 "0.75" 0 "0" 0 "0.5" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "26.85" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0.0" 0 "0.0" 0 "3.0" 0 "1.11" 0 "26.85" 0 "1.0" 0>
  <L L2 1 416 366 20 -28 0 0 "1 nH" 0 "" 0>
  <R R4 1 356 366 0 -51 0 0 "1 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <Relais RT424006_1 1 296 416 49 -26 0 0 "0.5 V" 0 "0.1 V" 0 "0" 0 "1e12" 0 "26.85" 0>
  <Diode D3 1 466 386 17 -28 0 3 "1e-15 A" 0 "1" 0 "10 fF" 0 "0.5" 0 "0.7 V" 0 "0.5" 0 "0.0 fF" 0 "0.0" 0 "2.0" 0 "0.0 Ohm" 0 "0.0 ps" 0 "0" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0" 0 "1 mA" 0 "26.85" 0 "3.0" 0 "1.11" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "26.85" 0 "1.0" 0 "normal" 0>
  <GND * 1 236 816 0 0 0 0>
  <Port PB3 1 36 476 -13 -30 0 0 "5" 0 "analog" 0>
  <R R14 1 426 466 -61 13 0 0 "10 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <_BJT T1 1 266 476 8 -26 0 0 "npn" 0 "1e-16" 0 "1" 0 "1" 0 "0" 0 "0" 0 "0" 0 "0" 0 "0" 0 "1.5" 0 "0" 0 "2" 0 "100" 0 "1" 0 "0" 0 "0" 0 "0" 0 "0" 0 "0" 0 "0" 0 "0.75" 0 "0.33" 0 "0" 0 "0.75" 0 "0.33" 0 "1.0" 0 "0" 0 "0.75" 0 "0" 0 "0.5" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "26.85" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0.0" 0 "0.0" 0 "3.0" 0 "1.11" 0 "26.85" 0 "1.0" 0>
  <GND * 1 396 626 0 0 0 0>
  <R R3 1 86 476 21 -48 0 0 "10 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <R R13 1 86 616 5 18 0 0 "1 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <Port PB0 1 36 616 -14 -25 0 0 "11" 0 "analog" 0>
  <_MOSFET IRFZ34N 1 466 556 14 10 0 0 "nfet" 0 "1.0 V" 0 "2e-5" 0 "0.0" 0 "0.6 V" 0 "0.0" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "1e-14 A" 0 "1.0" 0 "1 um" 0 "1 um" 0 "0.0" 0 "0.1 um" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 F" 0 "0.0 F" 0 "0.8 V" 0 "0.5" 0 "0.5" 0 "0.0" 0 "0.33" 0 "0.0 ps" 0 "0.0" 0 "0.0" 0 "1" 0 "600.0" 0 "0.0" 0 "1" 0 "1" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 m" 0 "0.0 m" 0 "0.0" 0 "1.0" 0 "1.0" 0 "26.85" 0 "26.85" 0>
  <_BJT T3 1 396 586 8 -26 0 0 "npn" 0 "1e-16" 0 "1" 0 "1" 0 "0" 0 "0" 0 "0" 0 "0" 0 "0" 0 "1.5" 0 "0" 0 "2" 0 "100" 0 "1" 0 "0" 0 "0" 0 "0" 0 "0" 0 "0" 0 "0" 0 "0.75" 0 "0.33" 0 "0" 0 "0.75" 0 "0.33" 0 "1.0" 0 "0" 0 "0.75" 0 "0" 0 "0.5" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "26.85" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0.0" 0 "0.0" 0 "3.0" 0 "1.11" 0 "26.85" 0 "1.0" 0>
  <R R5 1 86 586 0 -51 0 0 "4.7 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <Port PB1 1 36 586 -14 -30 0 0 "6" 0 "analog" 0>
  <GND * 1 266 536 0 0 0 0>
  <Lib D6 1 166 526 23 14 0 2 "LEDs" 0 "red" 0>
  <R R12 1 86 526 22 -42 0 0 "1 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <Port PB4 1 36 666 -16 -28 0 0 "7" 0 "analog" 0>
  <Port PB2 1 36 696 -17 -26 0 0 "8" 0 "analog" 0>
  <Port PB5 1 36 726 -17 -26 0 0 "12" 0 "analog" 0>
  <GND * 1 196 616 0 0 0 0>
  <Lib D7 1 166 616 26 -29 0 2 "LEDs" 0 "red" 0>
  <R R8 1 86 756 -23 -56 0 0 "4.7 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <Lib D5 1 146 796 10 -29 0 2 "LEDs" 0 "red" 0>
  <R R11 1 86 796 -22 18 0 0 "1 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <GND * 1 461 220 0 0 0 0>
  <Vdc V2 1 461 190 18 -26 0 1 "5 V" 1>
  <Port PC4 1 40 300 -17 -26 0 0 "13" 0 "analog" 0>
  <Port PD1 1 40 340 -17 -26 0 0 "14" 0 "analog" 0>
  <Port PC0 1 0 90 -9 -25 0 0 "1" 0 "analog" 0>
  <Port PC1 1 0 130 -10 -27 0 0 "2" 0 "analog" 0>
  <Port PC2 1 0 170 -10 -25 0 0 "3" 0 "analog" 0>
  <Port PC3 1 0 210 -10 -28 0 0 "4" 0 "analog" 0>
  <Port PD0 1 -4 246 -10 -27 0 0 "10" 0 "analog" 0>
  <GND * 1 146 246 0 0 0 0>
  <Lib D8 1 106 246 37 -38 0 2 "LEDs" 0 "red" 0>
  <R R15 1 46 246 8 -56 0 0 "1 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <Lib D9 1 130 340 -17 -34 0 2 "LEDs" 0 "red" 0>
  <R R17 1 70 340 2 22 0 0 "1 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <GND * 1 160 340 0 0 0 0>
  <Port PC5 1 40 380 -17 -26 0 0 "15" 0 "analog" 0>
  <Port PD2 1 40 420 -17 -26 0 0 "16" 0 "analog" 0>
  <GND * 1 190 360 0 0 0 0>
  <R R16 1 190 330 15 -26 0 1 "1 MOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <phototransistor PT1 1 190 190 24 -36 0 0 "100" 0 "0.1" 0 "1e-10" 0 "1" 0 "1" 0 "100" 0 "100" 0 "0.33" 0 "0.75" 0 "1e-12" 0 "0.33" 0 "0.75" 0 "2e-12" 0 "100n" 0 "0.1n" 0 "10" 0 "10" 0 "10" 0 "1" 0 "100" 0 "1e-12" 0 "1" 0 "1" 0 "1.5" 0 "2.6122e3" 0 "-1.489e1" 0 "3.0332e-2" 0 "-2.5708e-5" 0 "7.6923e-9" 0 "26.85" 0>
  <Lib D10 1 230 190 13 3 0 1 "LEDs" 0 "blue" 0>
  <Relais RTT424006_1 1 296 316 49 -26 0 0 "0.5 V" 0 "0.1 V" 0 "0" 0 "1e12" 0 "26.85" 0>
  <R R18 1 230 250 22 2 0 1 "380 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <Lib D11 1 630 490 12 -52 0 1 "LEDs" 0 "blue" 0>
  <Lib D12 1 680 490 11 -53 0 1 "LEDs" 0 "blue" 0>
  <Vdc V1 1 540 530 18 -26 0 1 "12 V" 1>
  <GND * 1 540 600 0 0 0 0>
  <R R19 1 630 550 -37 32 0 1 "1 kOhm" 0 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <R R20 1 680 550 8 20 0 1 "1 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
</Components>
<Wires>
  <370 100 390 100 "" 0 0 0 "">
  <450 100 490 100 "" 0 0 0 "">
  <490 60 490 100 "" 0 0 0 "">
  <370 60 370 100 "" 0 0 0 "">
  <350 60 370 60 "" 0 0 0 "">
  <490 60 546 60 "" 0 0 0 "">
  <546 60 546 286 "" 0 0 0 "">
  <416 726 416 756 "" 0 0 0 "">
  <386 756 416 756 "" 0 0 0 "">
  <296 756 326 756 "" 0 0 0 "">
  <296 726 296 756 "" 0 0 0 "">
  <236 726 296 726 "" 0 0 0 "">
  <446 366 446 386 "" 0 0 0 "">
  <326 386 446 386 "" 0 0 0 "">
  <326 446 466 446 "" 0 0 0 "">
  <466 416 466 446 "" 0 0 0 "">
  <466 286 546 286 "" 0 0 0 "">
  <466 286 466 356 "" 0 0 0 "">
  <546 286 546 466 "" 0 0 0 "">
  <496 466 546 466 "" 0 0 0 "">
  <416 726 496 726 "" 0 0 0 "">
  <496 466 496 726 "" 0 0 0 "">
  <456 466 496 466 "" 0 0 0 "">
  <266 446 326 446 "" 0 0 0 "">
  <116 476 236 476 "" 0 0 0 "">
  <36 476 56 476 "" 0 0 0 "">
  <36 616 56 616 "" 0 0 0 "">
  <396 616 396 626 "" 0 0 0 "">
  <396 466 396 556 "" 0 0 0 "">
  <396 626 466 626 "" 0 0 0 "">
  <466 586 466 626 "" 0 0 0 "">
  <466 446 466 526 "" 0 0 0 "">
  <396 556 436 556 "" 0 0 0 "">
  <116 586 366 586 "" 0 0 0 "">
  <36 586 56 586 "" 0 0 0 "">
  <56 476 56 526 "" 0 0 0 "">
  <116 526 136 526 "" 0 0 0 "">
  <266 506 266 526 "" 0 0 0 "">
  <266 526 266 536 "" 0 0 0 "">
  <196 526 266 526 "" 0 0 0 "">
  <116 616 136 616 "" 0 0 0 "">
  <236 786 236 796 "" 0 0 0 "">
  <236 796 236 816 "" 0 0 0 "">
  <176 796 236 796 "" 0 0 0 "">
  <36 756 56 756 "" 0 0 0 "">
  <116 756 206 756 "" 0 0 0 "">
  <56 756 56 796 "" 0 0 0 "">
  <266 160 461 160 "" 0 0 0 "">
  <0 90 260 90 "" 0 0 0 "">
  <136 246 146 246 "" 0 0 0 "">
  <-4 246 16 246 "" 0 0 0 "">
  <190 160 230 160 "" 0 0 0 "">
  <40 300 190 300 "" 0 0 0 "">
  <190 220 190 300 "" 0 0 0 "">
  <230 160 266 160 "" 0 0 0 "">
  <266 346 266 386 "" 0 0 0 "">
  <326 346 326 366 "" 0 0 0 "">
  <326 286 466 286 "" 0 0 0 "">
  <266 160 266 286 "" 0 0 0 "">
  <190 360 230 360 "" 0 0 0 "">
  <230 280 230 360 "" 0 0 0 "">
  <540 500 546 500 "" 0 0 0 "">
  <546 466 546 500 "" 0 0 0 "">
  <540 560 540 580 "" 0 0 0 "">
  <540 580 540 600 "" 0 0 0 "">
  <540 580 630 580 "" 0 0 0 "">
  <630 460 680 460 "" 0 0 0 "">
  <560 460 630 460 "" 0 0 0 "">
  <560 460 560 500 "" 0 0 0 "">
  <546 500 560 500 "" 0 0 0 "">
  <630 580 680 580 "" 0 0 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
  <Text 30 0 12 #aa0000 0 "PC0..PC3 all drive identical transistors,\nfor tail unipolar stepper drive">
  <Text 546 626 12 #aa0000 0 "PB4, PB2 and PB5 drive circuit\nidentical to the one connected\nto PB1 and PB3. This is the\ndrive for right leg.">
  <Text 576 276 12 #aa0000 0 "Polarity of motor is changed \nwith 2 form C relay RT424006. \nNot drawn propely because\ncomponent library does not \nhave that piece. What is drawn \nhere replaces reverse polarity \nconnection with open circuit">
  <Text 586 126 12 #aa0000 0 "PC5 and PD2 are inputs for \ncircuit identical to one \nconnected to PC4 and PD2. \nThis is the pen limit sensor \nfor the right leg.">
</Paintings>
