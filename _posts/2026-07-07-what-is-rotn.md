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

The specification declares a simple and intuitive method to easily overcome old problems, especially editorial ones, that chess has always carried with it: an image is not accessible to a blind person on the Internet or in an ebook, and FEN is not very intuitive for humans—it is more suited to computers and dates back to the last century. Therefore, ROTN vs. FEN is a cultural issue to address: it takes time to realize that we need to question the obvious and the methods used so far.

The goal of ROTN is to have a speaking position with voice synthesis and containing descriptions and advice, including technical ones

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
- **P:** Describes the starting move number.

In particular, **P:** should be decreased by 1 if White is the first to move (M:B), or it remains the same if Black is the first to move (M:N).

The reason is that a chess application (e.g., _Scacchi-it_) increments the move when playing as White and does not do so when playing as Black, precisely because a move consists of two half-moves: White's and then Black's.

FEN has additional fields for castling, en passant, and the 50-move rule, which are not useful for humans. A human does not need to know the castling status—they can see it for themselves—and the computer is also able to analyze and set it. There is no need to signal the 50-move rule or en passant.

Specifically, for Scacchi-it, take advantage of the ROTN specification. In ambiguous cases of invalid castling, this allows you to add the value NS (No Short Castle), NL (No Long Castle), or both separated by a ';' to the White (W:) or Black (B:)piece list.

_Scacchi-it_, designed for both sighted and blind users, in game suspensions, marks en passant to communicate its possibility upon resumption, but only if such a possibility exists, unlike the FEN standard.

In an ebook for the blind, if there are images, they are not accessible to the blind; therefore, generally, the position is described using algebraic notation, which has the advantage of quickly conveying the position of the pieces.

ROTN takes a further step by enabling listening and immediate use on a chessboard, not just that. If an ebook displays the ROTN, it can be quickly copied and pasted into a file and loaded into _Scacchi-it_. This way, one can listen to the text with voice synthesis, navigate the chessboard, explore the position, and better appreciate what is described in the ebook.

Additionally, ROTN makes the _Scacchi-it_ application open data in a bidirectional way: it allows suspending a game and resuming it later, as well as writing or copying problems and loading them for solving.
Therefore, the correct definition of ROTN notation is that it extends algebraic notation and makes a chess application open data, allowing interaction in two directions and adding the benefits of voice synthesis and images.

# **Formalized Specification for the Blind**

As always happens, those with specific needs create a specification and a chess application (_Scacchi-it_) that practically demonstrates its advantages. An innovative application to play offline and online, with Stockfish, study openings with an Openings Trainer, give lessons with move undo, and easily reset the chessboard.

The complete official ROTN specification, ISO 14977, is available at:
https://redyouman.github.io/blog/2026/07/02/Spec-ROTN.html
