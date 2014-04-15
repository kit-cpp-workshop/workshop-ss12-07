# Workshop 15. Juni 2012

## Inhalt

Kurze Einführung in die Thematik

### static libraries

C++ selbst kann nur sehr eingeschränkt mit der Hardware kommunizieren. Außerdem möchte man zur Reduktion der 
build-Dauer unabhängige Programmteile auslagern und gebräuchliche Funktionalitäten in mehreren Projekten verwenden.
Für all dies kann man static program libraries einsetzen. Wir werden kurz erklären, was diese sind und wie man sie 
verwendet.

### Folien zum Vortrag

Die Vortragsfolien stehen als [PDF](kit-cpp-workshop.github.com/raw/downloads/workshops/ss12-07/slides.pdf) zum Download bereit. Außerdem liegt der LaTeX-Quellcode zu den Folien im 
Ordner `slides`.

### Screencast

Eine Aufzeichnung des Vortrages steht zum [Download](https://drive.google.com/file/d/0B18AwdjM48imQXpXYjFFNzVJcU0/edit?usp=sharing) bereit.

 * ab 00:00 Intro/Begrüßung
 * ab 00:31 Something about C++/Beobachtbares Verhalten
 * ab 07:38 static libraries
 * ab 20:23 Live-Demo: static libraries mit Eclipse CDT einbinden
 * ab 22:05 SDL: Simple Directmedia Layer
 * ab 28:37 Vorstellung der Praxisaufgaben

## Aufgaben

Sendet, nachdem ihr alle Aufgaben abgearbeitet habt, einen Pull-Request an das Workshop-Repository. Stellt sicher, dass 
ihr vorher alle eure Änderungen in euren Fork übertragen habt. Nennt euren Workshop-Betreuer im Text des Pull-Requests, 
einer der Betreuer (bevorzugt der genannte) wird dann eure Lösungen durchsehen, kommentieren und nach Abschluss des 
Reviews den Pull-Request als abgelehnt markieren.

### Aufgabe 1: SDL Einstieg

[SDL Website](http://www.libsdl.org/)

Windows-Nutzer müssen die SDL Development Libraries von der Website herunterladen, Nutzer Debian-basiert 
Linux-Distributionen können auf das Paket libsdl-dev zurückgreifen. Unter MacOS Homebrew nennt sich das Paket sdl.

Für den Einstieg soll eine Anwendung geschrieben werden, die ein großes rotes Fenster erzeugt, welches mit Escape oder 
dem Schließen-Button des Fensters geschlossen werden kann.

### Aufgabe 2: Schach GUI (Graphical User Interface)

Baut mit SDL eine GUI für euer Schachspiel. Der Funktionsumfang der GUI ist euch freigestellt. Denkbar sind sowohl 
einfache GUIs, die nur den aktuellen Zustand des Spielbretts anzeigen, als auch komplexere Varianten die 
Interaktionsmöglichkeiten wie Drag & Drop implementieren.

Als Grafiken für die Schachfiguren könnt ihr zum Beispiel http://en.wikipedia.org/wiki/File:Chess_symbols.PNG verwenden.

### Bonusaufgabe: Project Euler

Falls du früher fertig bist oder einfach nur Lust auf mehr hast, schau dich mal bei 
[Project Euler](http://projecteuler.net/) um und such dir eine Aufgabe aus. Lade sie genau wie die anderen Aufgaben 
hoch.
