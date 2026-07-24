---
title: "Chess: What is ROTN"
description: "Rosario Turco's blog with free game downloads for the blind"
keywords:
  [
    "Chess articles",
    "games",
    "free",
    "no cost",
    "blind",
    "visually impaired",
    "low vision",
  ]
categories: Blog
---

# **What is ROTN**

by Rosario Turco

First and foremost, it is a digital accessibility specification for those who develop chess software compatible with screen readers (such as NVDA and similar), but it also allows sighted people to use the software, in line with a concept dear to me of integrating the two worlds: blind and sighted (NV&V).
The game becomes a moment of social integration and equal opportunity between sighted and blind individuals.

The specification declares a simple and intuitive method to easily overcome old problems, especially editorial ones, that chess has always carried with it: an image is not accessible to a blind person on the Internet or in an ebook, and FEN is not very intuitive for humans—it is more suited to computers and dates back to the last century.

The goal of ROTN is to have a speaking position with voice synthesis and containing descriptions and advice, including technical ones

"Today, when a screen reader reads a fen text, it fires a stream of characters at you so fast that it doesn't give you time to 'see' it through your auditory channel."

Anyway, the ROTN is an extra opportunity to take advantage of new technological ways.

ROTN is a text file consisting of descriptors followed by values. All descriptor fields are mandatory and have a fixed position and order.

**Example of ROTN:**
T:Checkmate in one move
V:B;
W:Kh8;
B:Kf7;Qg1;
M:B
P:34;

- **T:** Describes the position,, with possible technical advise , that will be read, even with voice synthesis.
- **V:** Describes from which point of view the program should load the position (White or Black, using W; or B;).
- **W:** Describes the list of white pieces, separated by semicolons, using english algebraic notation (e.g., Bg5;Ke2;).
- **B:** Describes the list of black pieces, as above.
- **M:** Describes whose turn it is (White or Black, using W or B).
- **P:** Describes the move number of the position.

Optional descriptor U: if present, it indicates the list of squares (not separated by ';') of the pawns that can perform an en passant capture and the square of the pawn under attack, e.g., U:c4b4; another example U:d4f4e4; The descriptor is used for the automated suspension and resumption of a match. In handwritten positions, it is the responsibility of the writer to observe the exact order and syntax of the command."

Optional Z descriptor: indicates the number of half-moves present in the FEN (field 5).

• Software developer-reserved descriptors: F, K, L, C, E.
• The text-to-speech feature in the application must read: T, M, P, U, Z.
• Furthermore, the application rotates the chessboard according to V.

From the ROTN, the Scacchi-it application learns the valid castling moves (invalid ones are marked with NS=No Short Castle and NL=No Long Castle), the half-move number for the 50-move rule, as well as the en passant.

_Scacchi-it_, designed for both sighted and blind users, in game suspensions, marks en passant to communicate its possibility upon resumption, but only if such a possibility exists, unlike the FEN standard.

In an ebook for the blind, if there are images, they are not accessible to the blind; therefore, generally, the position is described using algebraic notation, which has the advantage of quickly conveying the position of the pieces.

ROTN takes a further step by enabling listening and immediate use on a chessboard, not just that. If an ebook displays the ROTN, it can be quickly copied and pasted into a file and loaded into _Scacchi-it_. This way, one can listen to the text with voice synthesis, navigate the chessboard, explore the position, and better appreciate what is described in the ebook.

Additionally, ROTN makes the _Scacchi-it_ application open data in a bidirectional way: it allows suspending a game and resuming it later, as well as writing or copying problems and loading them for solving.
Therefore, the correct definition of ROTN notation is that it extends algebraic notation and makes a chess application open data, allowing interaction in two directions and adding the benefits of voice synthesis and images.

However ROTN provides voice to the FEN".

Finally, in the Scacchi-it case, the ROTN is the internal language for exchange with all external formats such as FEN or other future formats."

One last observation: the true strength of Scacchi-it and ROTN is not obvious. It allows me to set up any position in 3 seconds and test checkmate, stalemate, castling, en passant and any other complicated position, without having to play 40 moves every time.

# **Formalized Specification for the Blind**

As always happens, those with specific needs create a specification and a chess application (_Scacchi-it_) that practically demonstrates its advantages. An innovative application to play offline and online, with Stockfish, study openings with an Openings Trainer, give lessons with move undo, and easily reset the chessboard.

[Download Scacchi-it](https://github.com/RedYouMan/redyouman.github.io/raw/main/_posts/repo/scacchiGr.7z)

[italian tutorial Scacchi-it](https://github.com/RedYouMan/redyouman.github.io/raw/main/_posts/tutorials/scacchiGr.txt)

[The complete official ROTN specification, ISO 14977](https://redyouman.github.io/blog/2026/07/02/Spec-ROTN.html)

[Dare voce alla fen con rotn](https://redyouman.github.io/blog/2026/07/18/estensioni-browser.html)
