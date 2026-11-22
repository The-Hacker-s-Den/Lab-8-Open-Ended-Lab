# PRISM-25 Code Documentation

## 1. Getting the project:

The source code and the latest release are both hosted on GitHub.

- Source repository: [Lab-8-Open-Ended-Lab](https://github.com/The-Hacker-s-Den/Lab-8-Open-Ended-Lab)
- Latest release: [Releases](https://github.com/The-Hacker-s-Den/Lab-8-Open-Ended-Lab/releases/latest)

To get the source, clone the repository:

```bash
git clone https://github.com/The-Hacker-s-Den/Lab-8-Open-Ended-Lab.git
```

Alternatively, use the green **Code** button on the repository page and choose **Download ZIP**. To build the game from source, follow the steps under Requirements and Build. The game runs on Windows only.

## 2. Downloading the executable file:

The quickest way to play PRISM-25 is to download the ready-made executable from the latest GitHub release, with no compiler needed. The game runs on Windows only.

1. Open the [latest release](https://github.com/The-Hacker-s-Den/Lab-8-Open-Ended-Lab/releases/latest).
2. Under **Assets**, download the executable (`.exe`) file. If it is inside a `.zip`, download the archive and extract it.
3. Double-click the `.exe` to start the game. If Windows SmartScreen warns about an unknown publisher, choose **More info**, then **Run anyway**.
4. The game maximizes the console on launch. Choose **1** at the main menu to start, or **2** for the how-to-play guide and ciphers help.

Direct link: <https://github.com/The-Hacker-s-Den/Lab-8-Open-Ended-Lab/releases/latest>

## 3. Instructions for Playing:

You play a detective following a trail of deaths linked to a drug called PRISM-25. Across four cases you search scenes, collect evidence and decrypt hidden messages. Everything is played by typing at the keyboard and pressing **Enter**.

### Starting the game

1. Launch the game. The console maximizes automatically.
2. At the main menu, type a number and press Enter: **1** Start the Game, **2** How to play, **3** Credits, **4** Exit.
3. Before your first run, choose **2** and open the **Ciphers Guide**. It explains the four ciphers used in the game: Caesar, Atbash, single-character XOR and Vigenère. The **Lore** option gives the story background.
4. Enter **1** to begin. Starting a new game resets your total score.

### Controls

- Type the number of a menu option, then press Enter.
- When a screen says "Press Enter", press Enter to continue.
- Enter numbers only at menus. Typing letters at a number prompt can freeze the game.
- Answer hint prompts with `y` or `n`.

### How each level works

Every level has the same loop:

1. Read the briefing, then press Enter to start the investigation.
2. A numbered menu lists actions such as examining a body, searching a room or inspecting objects. You can repeat any option.
3. One option uncovers an item that carries an encrypted message (a phone, a notebook, a batch tag, a computer). The decrypt option stays blocked until you find that item, so search first.
4. Choose the decrypt option. The screen shows the encrypted message, the cipher type and any key or shift.
5. Decrypt the message by hand, then type the **decrypted text** and press Enter. Keep the spaces between words. Capital or lower-case letters both work.
6. A correct answer unlocks the next part of the story. A wrong answer counts as a mistake and offers a hint.

### The four cases

| Case | Title | Cipher you face | What to do |
| --- | --- | --- | --- |
| 1 | The Web | Caesar | Examine the body, search the room, then unlock the phone. |
| 2 | The Undercover Drop | Atbash | Examine the glassware, search the warehouse for a notebook, then decipher it. Choose to save the code to your notebook. |
| 3 | The Moth | Single-character XOR (hex values) | Examine the victim, inspect the lamps, search near the body for the blister pack, then decode the batch tag. |
| 4 | The Finale | 4-digit code, then Vigenère | Unlock the computer with the 4-digit code, then decipher the evidence files. |

### Hints

- After a wrong answer the game asks whether you want a hint.
- You can use up to 3 hints per level. They get more direct each time.
- Hints cost score, so try the Ciphers Guide and your own notes first.

### Scoring and ranks

- Each level starts at 100 points.
- Each wrong answer costs 10 points. Each hint costs 20 points. A level score never drops below 0.
- The maximum total is 400. Time taken is shown after each puzzle but does not change your score.
- Final rank: 350 or more is Master Detective, 250 to 349 Senior Investigator, 150 to 249 Junior Investigator, below 150 Rookie Investigator.

### Tips

- Read the cipher line on screen carefully. It states the shift or the key, and it shows where each puzzle's rules come from.
- Write the encrypted text and your working on paper. Decrypt it letter by letter, and leave numbers and spaces unchanged.
- In Case 2, save the code to your notebook. Case 4 asks for a 4-digit code and offers to check the notebook after a wrong attempt.
- In Case 4 you get only 3 attempts at the code. Check your notebook before you guess, because a locked computer cannot be reopened.
- Complete all four cases in one sitting. Progress is not saved, and each new game restarts from Case 1.

## 4. Screenshots:

1. ### Main Function:

&#91;image: image.png\]

2. ### Level 1:

&#91;image: image.png\]

3. ### Level 2:

&#91;image: image.png\]

4. ### Level 3:

### &#91;image: image.png\]5. Level 4:

&#91;image: image.png\]

6. ### Resolution:

&#91;image: image.png\]

7. ### Ending:

&#91;image: image.png\]

## 5. Overview

PRISM-25 is a Windows console detective game written in C++. The player works through four investigation levels. Each level ends with a cipher puzzle that must be solved by decrypting a message by hand. Scoring is based on incorrect attempts and hints used. Final rank is assigned from the total score after Level 4.

Story premise: a drug named PRISM-25 is linked to a series of deaths. The player follows a chat group ("THE HOLLOW"), a dealer ("THE LUMOS"), a clinic (St Jude Psychiatric Clinic) and a chemist alias ("VESPER"). The lore screen credits the TV drama *The Truth Within* as inspiration.

## 6. Requirements and Build

| Item | Detail |
| --- | --- |
| Language | C++ (uses raw string literals, `<chrono>`: C++11 or later) |
| Headers | `<iostream>`, `<string>`, `<chrono>`, `<algorithm>`, `<cctype>`, `<windows.h>` |
| Windows-specific calls | `GetConsoleWindow`, `ShowWindow`, `keybd_event`, `system("cls")`, `system("pause")` |
| Compile example | `g++ -std=c++11 Lab_8_OEL.cpp -o prism25.exe` or build in Visual Studio |

The program will not compile or behave correctly on Linux or macOS because of `windows.h`, `cls` and `pause`.

## 7. Program Flow

```
main()
  fullscreen()
  loop until choice == 4:
    welcome()            -> banner
    main_menu()          -> returns 1-4
      1: reset totalscore and clues[1], then
         Level_1() -> Level_2(clues) -> Level_3() -> Level_4(clues) -> ending()
      2: how_to_play()   -> ciphers_help() / lore()
      3: credits()
      4: exit
```

An invalid main-menu choice prints an error and terminates the program (`return 0`).

## 8. Global State

| Variable | Type | Purpose |
| --- | --- | --- |
| `totalscore` | `int` | Sum of all four level scores. Reset to 0 when a new game starts. |
| `score_level1` … `score_level4` | `int` | Score for each level, shown in the final report. |

Local state shared between levels is carried by `string clues[4]`, created in `main()`. Only `clues[1]` is used: Level 2 stores the code `"8492"` there, Level 4 reads it.

## 9. Function Reference

| Function | Signature | Description |
| --- | --- | --- |
| `main` | `int main()` | Maximizes the console, runs the menu loop, starts the game. |
| `fullscreen` | `int fullscreen()` | Maximizes the console window with `ShowWindow(SW_MAXIMIZE)` and simulates Alt+Enter with `keybd_event` to enter full-screen mode. Returns 0. |
| `welcome` | `int welcome()` | Clears the screen and prints the PRISM-25 ASCII banner. Returns 0. |
| `main_menu` | `int main_menu()` | Prints the four options, reads and returns the choice. |
| `how_to_play` | `int how_to_play()` | Shows instructions. Sub-menu: 1 Ciphers Guide, 2 Lore, 3 Return. Loops until 3. |
| `ciphers_help` | `int ciphers_help()` | Menu 1-4 explaining Caesar, Atbash, single-character XOR and Vigenère. 0 returns. |
| `lore` | `int lore()` | Prints the LORE banner and inspiration note, then pauses. |
| `credits` | `int credits()` | Prints the credits screen (Hania Nauman, Rameen Arjmand, Shaheer), then pauses. |
| `Level_1` | `void Level_1()` | Case file #001, "The Web". Caesar cipher. |
| `Level_2` | `void Level_2(string clues[])` | Case file #002, "The Undercover Drop". Atbash cipher. Writes `clues[1]`. |
| `Level_3` | `void Level_3()` | Case file #003, "The Moth". Single-character XOR on hex values. |
| `Level_4` | `void Level_4(string clues[])` | Case file #004, "The Finale". 4-digit code, then Vigenère cipher. Calls `ending()`. |
| `timer` | `void timer(string*, int&)` | Reads one line of input into the string pointer and adds the elapsed whole seconds to the `int` reference. Uses `chrono::steady_clock` and `getline(cin >> ws, ...)`. |
| `ending` | `void ending()` | Epilogue, rank calculation and final report. |

## 10. Level Structure

All four levels follow the same pattern:

1. Print the case banner and briefing.
2. Loop on a numbered investigation menu until the puzzle is solved.
3. Menu options reveal story text. One option unlocks the puzzle (for example, "search the room" sets `phoneFound = true`). The decrypt option is refused until its prerequisite flag is set.
4. A wrong answer increments `incorrect` and offers a hint (`y`/`n`). Each accepted hint increments `hintsUsed`, up to 3 hints.
5. On success, compute the score, add it to `totalscore` and print the level summary.

### Answer validation technique

The player types the **decrypted** message. The code does not decrypt the stored ciphertext. It re-encrypts the player's input and compares the result to the stored ciphertext.

| Level | Cipher | Re-encryption applied to player input | Comparison |
| --- | --- | --- | --- |
| 1 | Caesar, shift 3 | Uppercase, add 3 to every non-space character | Whole string equals `cypher1` |
| 2 | Atbash | Uppercase, map letters with `'Z' - (c - 'A')` | Lengths equal, then every character matches `cipher2` |
| 3 | XOR, key 75 (`K`) | Uppercase only; ciphertext is decrypted instead (`hex_values[i] ^ 75`) | Lengths equal, then every character equals the decrypted value |
| 4 | Vigenère, key `VESPER` | Uppercase, add key letter offset to each letter. Key index advances on every non-space character. | Lengths equal, then every character matches `cypher4` |

### Puzzle reference (spoilers)

| Level | Ciphertext | Plaintext |
| --- | --- | --- |
| 1 | `VSLGHU LQ WKH GDUN` | `SPIDER IN THE DARK` |
| 2 | `XSVNRHG ZORZH EVHKVI XLWV 8492` | `CHEMIST ALIAS VESPER CODE 8492` |
| 3 | hex `18 1F 6B 01 1E 0F 0E 6B 1B 18 12 08 03 02 0A 1F 19 02 08 6B 08 07 02 05 02 08` | `ST JUDE PSYCHIATRIC CLINIC` |
| 4a | 4-digit door code (from Level 2) | `8492` |
| 4b | `QEFRI WPRVTH KCI LGMRGW LD WVZ LWG EXVMF X QLNX XAIV` | `VANCE FUNDED THE TRIALS TO SEE HER AGAIN I MUST FLEE` |

### Level-specific notes

**Level 2.** After decrypting, the player chooses to save the code to the notebook (`clues[1] = "8492"`) or to ignore it. The score is computed inside the main loop once both `notebookFound` and `notebookDeciphered` are true.

**Level 3.** The hex table is printed using `cout << hex`, then `cout << dec` restores decimal output. `cypher3_solved[]` holds the XOR-decoded character codes.

**Level 4.** Option 2 asks for the 4-digit code (`8492`) with 3 attempts (`passwordLimit`). After a wrong attempt the player may check the notebook. The notebook reveals the code only if it was saved in Level 2. Option 3 (Vigenère file) requires the computer to be unlocked. On success `computerDeciphered` ends the loop and `ending()` runs.

## 11. Scoring

Per level:

```
score = max(0, 100 - 10 * incorrect - 20 * hintsUsed)
```

- Maximum per level: 100. Maximum total: 400.
- Each wrong answer costs 10 points. Each hint costs 20 points. Hints are capped at 3.
- The Level 4 door-code attempts do not count toward `incorrect`.
- Elapsed time is measured by `timer()` and displayed in levels 1, 3 and 4. It does not affect the score.

### Ranks (`ending()`)

| Total score | Rank |
| --- | --- |
| 350 - 400 | MASTER DETECTIVE |
| 250 - 349 | SENIOR INVESTIGATOR |
| 150 - 249 | JUNIOR INVESTIGATOR |
| 0 - 149 | ROOKIE INVESTIGATOR |

## 12. Collaborators:

1. Shaheer
2. Hania Nauman
3. Rameen Arjmand

## 13. Member's Contributions:

| **Member** | **Contribution** |
| --- | --- |
| Shaheer | Code for verification of answers and the following functions: `timer(), fullscreen(), welcome(), main_menu(), ciphers_help(), credits(), how_to_play()` |
| Hania Nauman | Project Manager, Story writer, planned the ciphers, wrote the functions for: `Level_2(), Level_4()``,`` ``l``o``r``e``(``)` |
| Rameen Arjmand | Wrote the code for score calculation, assigning the rank and the following functions: &#32;`Level_1(), Level_3(), ending()` |
