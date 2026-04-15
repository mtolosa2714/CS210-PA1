# Developer Log (DEVLOG.md)
## Monopoly Board Simulator (Spring 2026)

Minimum **6 entries** required.

Each entry must document learning and reasoning. Fabricated bugs are not expected.

---

## Allowed Entry Types
Each entry may be one of the following:

1) **Bug Fix Entry**
- The issue encountered.
- Error messages or symptoms.
- Attempts made.
- Final resolution.

2) **Edge Case / Testing Entry**
- A failure discovered through testing.
- The specific input/state that caused it.
- The change you made to handle it correctly.

3) **Engineering Decision Entry (up to 2 allowed)**
- A design decision you made.
- An alternative approach you considered.
- Why you chose one approach over another (tradeoffs).

---

### Entry 1
**Date:** 2020-04-13
**Entry Type:** Bug Fix
**Task worked on:** Connecting CLion to GitHub Repository
**Issue or decision:** I could not push my project to GitHub. It kept rejecting with "non-fast-forward" errors.
**Error message / symptom (if applicable):**  “Pulling is not possible because you have unmerged files.”
**What I tried:**  I kept trying to push, but it kept rejecting. So I tried pulling from the repository but it made more errors about branches and merges.
**Fix / resolution (or final decision):**  The problem was in the README file where I cad to manually edit the marker and keep the correct version of README
**Commit(s):**  Add project files and gitignore

---

### Entry 2
**Date:** 2026-04-14
**Entry Type:** Edge Case  
**Task worked on:**  Creating and testing the addSpace linking
**Issue or decision:**  After writing the code for addSpace(), I used basic tests to check if the list was working properly/circularly
**Error message / symptom (if applicable):**  The code didn't crash, but I wrote a small test to make sure the tail node pointed back to the head node.
**What I tried:**  I added debugging print statements to check if the list was circular, which showed that I did not have the tail point to the head
**Fix / resolution (or final decision):**  Since the tests proved that the circular list was not working properly, I went back and added the line tailNode -> nextNode == headNode, which I accidentally forgot.
**Commit(s):**  From commits 3 to 4

---

### Entry 3
**Date:** YYYY-MM-DD  
**Entry Type:** Bug Fix / Edge Case / Engineering Decision  
**Task worked on:**  
**Issue or decision:**  
**Error message / symptom (if applicable):**  
**What I tried:**  
**Fix / resolution (or final decision):**  
**Commit(s):**  

---

### Entry 4
**Date:** YYYY-MM-DD  
**Entry Type:** Bug Fix / Edge Case / Engineering Decision  
**Task worked on:**  
**Issue or decision:**  
**Error message / symptom (if applicable):**  
**What I tried:**  
**Fix / resolution (or final decision):**  
**Commit(s):**  

---

### Entry 5
**Date:** YYYY-MM-DD  
**Entry Type:** Bug Fix / Edge Case / Engineering Decision  
**Task worked on:**  
**Issue or decision:**  
**Error message / symptom (if applicable):**  
**What I tried:**  
**Fix / resolution (or final decision):**  
**Commit(s):**  

---

### Entry 6
**Date:** YYYY-MM-DD  
**Entry Type:** Bug Fix / Edge Case / Engineering Decision  
**Task worked on:**  
**Issue or decision:**  
**Error message / symptom (if applicable):**  
**What I tried:**  
**Fix / resolution (or final decision):**  
**Commit(s):**  
