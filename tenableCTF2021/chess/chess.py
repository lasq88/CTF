'''
Takes '+' and ' ' delimited data of chess matches and parses into list of seperate matches
''' 
def ParseMatches(chess_matches):
    return [c.split('+') for c in chess_matches.split(' ')]


def GetKingPos(chessboard, color):
    for figure in chessboard:
        if (figure[1] == 'k' and figure[0] == color):
            return figure[2]

def FirstFigure(chessboard,king_pos,coords):
    new_pos = king_pos
    while(True):
        new_pos = TranslatePos(new_pos,coords[0],coords[1])
        if (new_pos != None):
            for figure in chessboard:
                if (figure[2] == new_pos):
                    return figure
        else:
            return None

def TranslatePos(pos,x,y):
    hor = ord(pos[0])+x
    ver = int(pos[1])+y
    if (hor >= 97 and hor <= 104 and ver >=1 and ver <=8):
        return str(chr(hor))+str(ver)
    else:
        return None

def GetDistance(fig_a,fig_b):
    x = ord(fig_a[0]) - ord(fig_b[0])
    y = int(fig_a[1]) - int(fig_b[1])
    return (x,y)

def KingCheck(chessboard,king_pos,color):
    enemy = "b" if color == "w" else "w"
    diagonals = [(1,1),(-1,1),(1,-1),(-1,-1)]
    cardinals = [(0,1),(0,-1),(1,0),(-1,0)]
    knight = [(-2,1),(-2,-1),(-1,2),(-1,-2),(2,1),(2,-1),(1,2),(1,-2)]
    for diag in diagonals:
        figure = FirstFigure(chessboard,king_pos,diag)
        if (figure != None):
            if ((figure[1] == "q" or figure[1] == "b") and figure[0] == enemy):
                return True
            if (figure[1] == "k" and figure[0] == enemy and GetDistance(king_pos,figure[2]) in diagonals):
                return True
            if (figure[1] == "p" and figure[0] == enemy):
                if ((enemy == "w" and GetDistance(king_pos,figure[2]) in [(1,1),(-1,1)]) or (enemy == "b" and GetDistance(king_pos,figure[2]) in [(1,-1),(-1,-1)])):
                    return True


    for card in cardinals:
        figure = FirstFigure(chessboard,king_pos,card)
        if (figure != None):
            if ((figure[1] == "q" or figure[1] == "r") and figure[0] == enemy):
                return True
            if (figure[1] == "k" and figure[0] == enemy and GetDistance(king_pos,figure[2]) in cardinals):
                return True

    for figure in chessboard:
        if (figure[1] == "n" and GetDistance(king_pos,figure[2]) in knight and figure[0] == enemy):
            return True

    return False
'''
:param chess_match: A list of chess pieces and their location on the board. ie: ['w,p,a2', 'w,q,a6','w,k,c1','b,r,h1','b,k,g3']
:return: returns True or False if a King is in check
'''

def IsKingInCheck(chess_match):
    chessboard = [c.split(',') for c in chess_match]
    for color in ["w","b"]:
        king_pos = GetKingPos(chessboard, color)
        if(KingCheck(chessboard,king_pos,color)):
            return True

    return False



# Parses chess matches from raw_input and calls "IsKingInCheck" for each match. Result is then printed
result = []
chess_matches = ParseMatches(input())
for chess_match in chess_matches:
    result.append(IsKingInCheck(chess_match))
    
print(result)
