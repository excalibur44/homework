.ORIG x3000

    WRONG   .STRINGZ "Invalid move. Try again."
    P1IN    .STRINGZ "Player 1, choose a column:"
    P2IN    .STRINGZ "Player 2, choose a column:"
    P1WIN   .STRINGZ "Player 1 Wins."
    P2WIN   .STRINGZ "Player 2 Wins."

DO
    JSR START;
    JSR OUTPUT;
    AND R4, R4, #0;
    JSR INSERT;
    JSR OUTPUT;
    JSR JUDGE;
    ADD R2, R2, #0;
    BRz END;

    ADD R4, R4, #1;
    JSR INSERT;
    JSR OUTPUT;
    ADD R4, R4, #1;
    JSR JUDGE;
    ADD R2, R2, #0;
    BRz END;

    BRnzp DO
END
HALT

START;//NO NEED
    LD R3, THREESIX;
    LD R5, LINE;
    LD R1, BOARD;
START1
    STR R5, R1, #0;
    ADD R1, R1, #1;
    ADD R3, R3, #-1;
    BRz START2;
    BRnzp START1;
START2
RET

OUTPUT;//NO NEED
    ST R7, SAVE7;
    LD R5, FUTHREESIX;
    LD R1, BOARD;
OUTPUT1
    LD R4, FUSIX;
OUTPUT2
    LDR R0, R1, #0;
    OUT;
    LD R0, BLANK;
    OUT;
    ADD R1, R1, #1;
    ADD R5, R5, #1;
    BRz OUTPUT3
    ADD R4, R4, #1;
    BRn OUTPUT2;
    LD R0, ENTER;
    OUT;
    ADD R4, R4, #0;
    BRz OUTPUT1;
OUTPUT3
    LD R0, ENTER;
    OUT;
    AND R4, R4, #0;
    LD R7, SAVE7;
RET

INSERT;//NEED R4
    ST R7, SAVE7;
INSERT1
    ADD R4, R4, #0;
    BRp INSERT2
    LEA R0, P1IN;
    PUTS;
    BRnzp INSERT3
INSERT2
    LEA R0, P2IN;
    PUTS;
INSERT3
    IN;
    LD R6, FUZERO;
    ADD R6, R6, R0;
    BRnz INSERT9
    ADD R6, R6, #-6;
    BRp INSERT9
    LD R2, THREESIX;
    ADD R2, R2, #-1;
    ADD R2, R2, R6;
    LD R1, BOARD;
    ADD R1, R1, R2;
    AND R3, R3, #0;
    ADD R3, R3, #6;
INSERT4
    LD R2, FULINE;
    LDR R5, R1, #0;
    ADD R5, R5, R2;
    BRnp INSERT7
    ADD R4, R4, #0;
    BRnp INSERT5
    LD R2, ROUND;
    STR R2, R1, #0;
    BRnzp INSERT6
INSERT5
    LD R2, CROSS;
    STR R2, R1, #0;
INSERT6
    LD R7, SAVE7;
RET;//RETURN
INSERT7
    ADD R1, R1, #-6;
    ADD R3, R3, #-1;
    BRnz INSERT8
    BRnzp INSERT4
INSERT8
    BRnzp INSERT9;
INSERT9
    LEA R0, WRONG;
    PUTS;
    LD R0, ENTER;
    OUT;
    BRnzp INSERT1;
;//INSERTEND

WIN
    ST R7, SAVE;
    ADD R4, R4, #0;
    BRp WIN1
    LEA R0, P1WIN;
    PUTS;
    BRnzp WIN2
WIN1
    LEA R0, P2WIN;
    PUTS;
WIN2
    LD R7, SAVE;
RET

;//DATA
    SIX .FILL #6;
    FUSIX .FILL #-6
    EIGHTEEN .FILL #18
    THREESIX .FILL #36
    FUTHREESIX .FILL #-36
    
    SAVE    .FILL x4000
    SAVE7   .FILL x4007
    
    BOARD   .FILL x4400
    MIDBO   .FILL x4412
    FUMIDBO .FILL xBBEE
    ENDBO   .FILL xBBDC
    FUZERO  .FILL xFFD0
    BLANK   .FILL x0020
    ENTER   .FILL x000A
    LINE    .FILL x002D
    FULINE  .FILL xFFD3
    CROSS   .FILL x0058
    FUCROSS .FILL xFFA8
    ROUND   .FILL x004F
    FUROUND .FILL xFFB1    

JUDGE;//NEED R4
    ST R7, SAVE7;//R4
;//'-'
    AND R3, R3, #0;
    ADD R3, R3, #3;
    AND R7, R7, #0;
    ADD R7, R7, #3;
    LD R1 BOARD;//R1,R3,R4,R7
JUDGE11 
    ;//{
    LDR R5, R1, #0;
    LD R6, FULINE;
    ADD R6, R5, R6;//R1,R2,R4,R5,R7
    BRz JUDGE12;//if (R1[R4 + 0] == '-' ||
    LDR R6, R1, #1;
    NOT R5, R5;
    ADD R5, R5, #1;
    ADD R5, R5, R6;
    BRnp JUDGE12;//R1[R4 + 0] - R1[R4 + 1] ||
    LDR R5, R1, #2;
    NOT R5, R5;
    ADD R5, R5, #1;
    ADD R6, R5, R6;
    BRnp JUDGE12;//R1[R4 + 1] - R1[R4 + 2] ||
    LDR R6, R1, #3;
    ADD R6, R5, R6;
    BRnp JUDGE12;//R1[R4 + 2] - R1[R4 + 3] )
    JSR WIN;
    AND R2, R2, #0;
    LD R7, SAVE7;
RET
JUDGE12
    ADD R1, R1, #1;
    ADD R7, R7, #-1;
    BRnp JUDGE13
    ADD R7, R7, #3;
    ADD R3, R3, #3;
    ADD R1, R1, #3;
JUDGE13
    LD R6, ENDBO;
    ADD R6, R1, R6;
    BRn JUDGE14
    AND R3, R3, #0;
JUDGE14
    ;//}
    ADD R3, R3, #-1;
;JUDGE15
    BRnz JUDGE16
    BRnzp JUDGE11
JUDGE16

;//'|'
    LD R3, EIGHTEEN;
    LD R1, BOARD;//R1,R3,R4,R7
JUDGE21 
    ;//{
    LDR R5, R1, #0;
    LD R6, FULINE;
    ADD R6, R5, R6;//R1,R2,R4,R5,R7
    BRz JUDGE22;//if (R1[R4 + 0] == '-' ||
    LDR R6, R1, #6;
    NOT R5, R5;
    ADD R5, R5, #1;
    ADD R5, R5, R6;
    BRnp JUDGE22;//R1[R4 + 0] - R1[R4 + 6] ||
    LDR R5, R1, #12;
    NOT R5, R5;
    ADD R5, R5, #1;
    ADD R6, R5, R6;
    BRnp JUDGE22;//R1[R4 + 6] - R1[R4 + 12] ||
    ADD R1, R1, #15;
    LDR R6, R1, #3;
    ADD R1, R1, #-15;
    ADD R6, R5, R6;
    BRnp JUDGE22;//R1[R4 + 12] - R1[R4 + 18] )
    JSR WIN;
    AND R2, R2, #0;
    LD R7, SAVE7;
RET
JUDGE22
ADD R1, R1, #1;
ADD R3, R3, #-1;
BRnz JUDGE23
BRnzp JUDGE21
JUDGE23

;//'/'
    AND R3, R3, #0;
    ADD R3, R3, #3;
    AND R7, R7, #0;
    ADD R7, R7, #3;
    LD R1 MIDBO;//R1,R3,R4,R7
JUDGE31 
    ;//{
    LDR R5, R1, #0;
    LD R6, FULINE;
    ADD R6, R5, R6;//R1,R2,R4,R5,R7
    BRz JUDGE32;//if (R1[R4 + 0] == '-' ||
    LDR R6, R1, #-5;
    NOT R5, R5;
    ADD R5, R5, #1;
    ADD R5, R5, R6;
    BRnp JUDGE32;//R1[R4 + 0] - R1[R4 - 5] ||
    LDR R5, R1, #-10;
    NOT R5, R5;
    ADD R5, R5, #1;
    ADD R6, R5, R6;
    BRnp JUDGE32;//R1[R4 - 5] - R1[R4 - 10] ||
    LDR R6, R1, #-15;
    ADD R6, R5, R6;
    BRnp JUDGE32;//R1[R4 - 10] - R1[R4 - 15] )
    JSR WIN;
    AND R2, R2, #0;
    LD R7, SAVE7;
RET
JUDGE32
    ADD R1, R1, #1;
    ADD R7, R7, #-1;
    BRnp JUDGE33
    ADD R7, R7, #3;
    ADD R3, R3, #3;
    ADD R1, R1, #3;
JUDGE33
    LD R6, ENDBO;
    ADD R6, R1, R6;
    BRn JUDGE34
    AND R3, R3, #0;
JUDGE34
    ;//}
    ADD R3, R3, #-1;
;JUDGE35
    BRnz JUDGE36
    BRnzp JUDGE31
JUDGE36

;//'\'
    AND R3, R3, #0;
    ADD R3, R3, #3;
    AND R7, R7, #0;
    ADD R7, R7, #3;
    LD R1 BOARD;//R1,R3,R4,R7
JUDGE41 
    ;//{
    LDR R5, R1, #0;
    LD R6, FULINE;
    ADD R6, R5, R6;//R1,R2,R4,R5,R7
    BRz JUDGE42;//if (R1[R4 + 0] == '-' ||
    LDR R6, R1, #7;
    NOT R5, R5;
    ADD R5, R5, #1;
    ADD R5, R5, R6;
    BRnp JUDGE42;//R1[R4 + 0] - R1[R4 + 7] ||
    LDR R5, R1, #14;
    NOT R5, R5;
    ADD R5, R5, #1;
    ADD R6, R5, R6;
    BRnp JUDGE42;//R1[R4 + 7] - R1[R4 + 14] ||
    ADD R1, R1, #10;
    LDR R6, R1, #11;
    ADD R1, R1, #-10;
    ADD R6, R5, R6;
    BRnp JUDGE42;//R1[R4 + 14] - R1[R4 + 21] )
    JSR WIN;
    AND R2, R2, #0;
    LD R7, SAVE7;
RET
JUDGE42
    ADD R1, R1, #1;
    ADD R7, R7, #-1;
    BRnp JUDGE43
    ADD R7, R7, #3;
    ADD R3, R3, #3;
    ADD R1, R1, #3;
JUDGE43
    LD R6, FUMIDBO;
    ADD R6, R1, R6;
    BRn JUDGE44
    AND R3, R3, #0;
JUDGE44
    ;//}
    ADD R3, R3, #-1;
;JUDGE45
    BRnz JUDGE46
    BRnzp JUDGE41
JUDGE46

;//FULL?
    LD R3, THREESIX;
    LD R1, BOARD;
FULL1
    LDR R5, R1, #0;
    LD R6, FULINE;
    ADD R6, R5, R6;
    BRnp FULL2;
    LD R7, SAVE7;
RET
FULL2
    ADD R1, R1, #1;
    ADD R3, R3, #-1;
    BRnz FULL3
    BRnzp FULL1
FULL3
    LEA R0, TIE;
    PUTS;
    AND R2, R2, #0;
    LD R7, SAVE7;
RET

    TIE .STRINGZ "Tie Game."

    .END
