# **Codingspass mit Thomas :))** 

## Clonen des Repositorys
- Am besten mit SSH clonen.
- Für Windows: Git Bash downloaden, um dem How-To 1:1 folgen zu können: https://git-scm.com/downloads <br> Git Bash emuliert eine Linux-Shell, die es in Windows möglich macht, Linux-Kommandozeilenbefehle auszuführen. 
- How to clone a repo using ssh: https://phoenixnap.com/kb/git-clone-ssh <br>

## Einbinden vom Projekt in Visual Studio Code
- Files - Open File...  <br>
<p align="left">
    <img src="images/doc/readme3.png" width="300"/>
</p>

- In das Verzeichnis, in das das Repository gecloned wurde, gehen, Hauptordner markieren & öffnen klicken <br>
<p align="left">
    <img src="images/doc/readme4.png" width="600"/>
</p>

- In Visual Studio Code sollte nun im Reiter `Explorer (Strg+Shift+E)` folgende Struktur sichtbar sein: <br>
<p align="left">
    <img src="images/doc/readme5.png" width="300"/>
</p>

- In den jeweiligen Task-Ordner befinden sich die Aufgaben mit dem zugehörigen Code.
## Ausführen vom Code in Visual Studio Code

- Rechtsklick auf jeweiligen Task-Ordner & auf `Open in Integrated Terminal` klicken. <br>
<p align="left">
    <img src="images/doc/readme1.png" width="300"/>
</p> 

- Dabei öffnet sich eine Konsole, die sich direkt im richtigen Verzeichnis befindet.
- `make clean`: löscht alte Binary- und Object-Files.
- `make`: Kompilieren des Codes mittels `gcc`. Dabei die Erros und Warnings in der Konsole ordentlich gönnen :))
- `./[Programmname]` führt Code aus. Output in Konsole. Programmname: Name der Binary-File (also meistens `main`).
