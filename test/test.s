cons
 token 29223648  ID           lim  dtype  0  link 0
 token 0  NULL
cons
 token 29223520  ID             i  dtype  0  link 29223648
 token 29223648  ID           lim  dtype  0  link 0
binop
 token 29289776  OP            :=  dtype  0  link 0  operands 29289712
 token 29289712  ID           lim  dtype  0  link 29289840
 token 29289840  NUM            7  dtype  0  link 0
binop
 token 29290096  OP            :=  dtype  0  link 0  operands 29290032
 token 29290032  ID             i  dtype  0  link 29290160
 token 29290160  NUM            0  dtype  0  link 0
makefuncall
 token 29290672  OP       funcall  dtype  0  link 0  operands 29290416
 token 29290416  ID       writeln  dtype  0  link 29290544
 token 29290544  STR            *  dtype  0  link 0
makeprogn
 token 29289968  OP         progn  dtype  0  link 0  operands 29290096
 token 29290096  OP            :=  dtype  0  link 0  operands 29290032
makeintc
 token 29290800  NUM            0  dtype  0  link 0
makelabel
 token 29290736  OP         label  dtype  0  link 0  operands 29290800
makeop
 token 29290864  OP            <=  dtype  0  link 0  operands 0
makeop
 token 29290928  OP             +  dtype  0  link 0  operands 0
makeprogn
 token 29290992  OP         progn  dtype  0  link 0  operands 29290672
 token 29290672  OP       funcall  dtype  0  link 0  operands 29290416
makeif
 token 29291056  OP            if  dtype  0  link 0  operands 29290864
 token 29290864  OP            <=  dtype  0  link 29290992  operands 0
 token 29290992  OP         progn  dtype  0  link 0  operands 29290672
 token 0  NULL
copytok
 token 29291120  ID             i  dtype  0  link 29290160
makeop
 token 29291184  OP            :=  dtype  0  link 0  operands 0
copytok
 token 29291248  ID             i  dtype  0  link 29290224
copytok
 token 29291312  ID             i  dtype  0  link 29290224
makeintc
 token 29291376  NUM            1  dtype  0  link 0
makeintc
 token 29291504  NUM            0  dtype  0  link 0
makegoto
 token 29291440  OP          goto  dtype  0  link 0  operands 29291504
makefor
 token 29289968  OP         progn  dtype  0  link 0  operands 29290096
 token 29290096  OP            :=  dtype  0  link 29290736  operands 29290032
 token 29290224  typ  2  whic  24  dty   0  sty 0 lnk 0  opnds 0
 token 29290288  ID           lim  dtype  0  link 0
 token 29290352  typ  2  whic   5  dty   0  sty 0 lnk 0  opnds 0
 token 29290864  OP            <=  dtype  0  link 29290992  operands 29291120
 token 29290928  OP             +  dtype  0  link 0  operands 29291312
 token 29291120  ID             i  dtype  0  link 29290224
 token 29291248  ID             i  dtype  0  link 29290928
 token 29291312  ID             i  dtype  0  link 29291376
cons
 token 29289968  OP         progn  dtype  0  link 0  operands 29290096
 token 0  NULL
cons
 token 29289776  OP            :=  dtype  0  link 29289968  operands 29289712
 token 29289968  OP         progn  dtype  0  link 0  operands 29290096
makeprogn
 token 29289648  OP         progn  dtype  0  link 0  operands 29289776
 token 29289776  OP            :=  dtype  0  link 29289968  operands 29289712
makeprogn
 token 29291760  OP         progn  dtype  0  link 0  operands 29223264
 token 29223264  ID        output  dtype  0  link 0
makeprogram
 token 29291696  OP       program  dtype  0  link 0  operands 29223136
 token 29291760  OP         progn  dtype  0  link 29289648  operands 29223264
 token 29223136  ID        graph1  dtype  0  link 29291760
 token 29223264  ID        output  dtype  0  link 0
Symbol table level 0
 29134864        real  BASIC  basicdt   1          siz     8
 29134960     integer  BASIC  basicdt   0          siz     4
 29135056        char  BASIC  basicdt   2          siz     1
 29135152     boolean  BASIC  basicdt   3          siz     4
 29135248         exp  knd 5 0  typ 29135344  lvl  0  siz     0  off     0
(FUNCTION real
          real)
 29135536       trexp  knd 5 0  typ 29135632  lvl  0  siz     0  off     0
(FUNCTION real
          real)
 29135824         sin  knd 5 0  typ 29135920  lvl  0  siz     0  off     0
(FUNCTION real
          real)
 29136112         cos  knd 5 0  typ 29136208  lvl  0  siz     0  off     0
(FUNCTION real
          real)
 29136400       trsin  knd 5 0  typ 29136496  lvl  0  siz     0  off     0
(FUNCTION real
          real)
 29136688        sqrt  knd 5 0  typ 29136784  lvl  0  siz     0  off     0
(FUNCTION real
          real)
 29136976       round  knd 5 0  typ 29137072  lvl  0  siz     0  off     0
(FUNCTION real
          real)
 29137264      iround  knd 5 0  typ 29137360  lvl  0  siz     0  off     0
(FUNCTION integer
          real)
 29137552         ord  knd 5 0  typ 29137648  lvl  0  siz     0  off     0
(FUNCTION integer
          integer)
 29137840         new  knd 5 0  typ 29137936  lvl  0  siz     0  off     0
(FUNCTION integer
          integer)
 29138128       trnew  knd 5 0  typ 29138224  lvl  0  siz     0  off     0
(FUNCTION integer
          integer)
 29138416       write  knd 5 0  typ 29138512  lvl  0  siz     0  off     0
(FUNCTION NULL
          char)
 29138704     writeln  knd 5 0  typ 29138800  lvl  0  siz     0  off     0
(FUNCTION NULL
          char)
 29138992      writef  knd 5 0  typ 29139088  lvl  0  siz     0  off     0
(FUNCTION NULL
          real)
 29139280    writelnf  knd 5 0  typ 29139376  lvl  0  siz     0  off     0
(FUNCTION NULL
          real)
 29139568      writei  knd 5 0  typ 29139664  lvl  0  siz     0  off     0
(FUNCTION NULL
          integer)
 29139856    writelni  knd 5 0  typ 29139952  lvl  0  siz     0  off     0
(FUNCTION NULL
          integer)
 29140144        read  knd 5 0  typ 29140240  lvl  0  siz     0  off     0
(FUNCTION NULL
          NULL)
 29140432      readln  knd 5 0  typ 29140528  lvl  0  siz     0  off     0
(FUNCTION NULL
          NULL)
 29140720         eof  knd 5 0  typ 29140816  lvl  0  siz     0  off     0
(FUNCTION boolean
          NULL)
Symbol table level 1
 29289392           i  VAR    0 typ integer  lvl  1  siz     4  off     0
 29289488         lim  VAR    0 typ integer  lvl  1  siz     4  off     4
yyparse result =        0
 token 29291696  OP       program  dtype  0  link 0  operands 29223136
(program graph1 (progn output)
                (progn (:= lim 7)
                       (progn (:= i 0)
                              (label 0)
                              (if (<= i )
                                  (progn (funcall writeln '*')
                                         (:= i (+ i 1))
                                         (goto 0))))))
