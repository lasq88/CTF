Working code in both python scripts (chess_py2.py is python 2 for purposes of the challenge validator).

Initial idea was to check if every figure "sees" king because that's how I found it done in some open-source chess code. But in the end I managed to optimize it for sake of only validating if king is in check:
1. I start with finding king's position
2. Verify all 4 diagonals and look for enemy bishops, queens, kings (only in proximity) and pawns (only in proximity and correct direction
3. Verify all 4 cardinals and look for enemy rooks, queens and kings (only in proximity).
4. In the end I check if any enemy knight is in position to check
