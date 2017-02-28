/* final compilar project
Programmers: Ayelet Kalderon & Avishag Daniely */

#include <stdio.h>
#include <stdlib.h>

/* change to 0 for no debug info to be printed: */
#define DO_SHOW 1

#define SOB_NIL 2

#define FALSE 102 

#define TRUE 104 

#define LOCAL_NUM_ARGS 1 

#define LOCAL_ENV 0

#define SYMTAB 369

#include "arch/cisc.h"
#include "arch/BenTest.h"

int main()
{
 START_MACHINE;

PUSH(IMM(397));
CALL(MALLOC);
DROP(1);
PUSH(IMM(0));
PUSH(IMM(0));
PUSH(LABEL(PROG_ENDING));
PUSH(FP);
MOV(FP,SP);

 JUMP(CONTINUE);

#include "arch/char.lib"
#include "arch/io.lib"
#include "arch/math.lib"
#include "arch/string.lib"
#include "arch/system.lib"
#include "arch/scheme.lib"
#include "arch/ours.lib"

ERROR:
HALT;

CONTINUE:

/* ----------initiating const table---------- */
MOV(IND(100), IMM(T_VOID));
MOV(IND(101), IMM(T_NIL));
MOV(IND(102), IMM(T_BOOL));
MOV(IND(103), IMM(0));
MOV(IND(104), IMM(T_BOOL));
MOV(IND(105), IMM(1));
MOV(IND(106), IMM(T_INTEGER));
MOV(IND(107), IMM(9));
MOV(IND(108), IMM(T_INTEGER));
MOV(IND(109), IMM(4));
MOV(IND(110), IMM(T_PAIR));
MOV(IND(111), IMM(108));
MOV(IND(112), IMM(101));
MOV(IND(113), IMM(T_PAIR));
MOV(IND(114), IMM(106));
MOV(IND(115), IMM(110));
MOV(IND(116), IMM(T_INTEGER));
MOV(IND(117), IMM(1));
MOV(IND(118), IMM(T_PAIR));
MOV(IND(119), IMM(116));
MOV(IND(120), IMM(101));
MOV(IND(121), IMM(T_INTEGER));
MOV(IND(122), IMM(2));
MOV(IND(123), IMM(T_PAIR));
MOV(IND(124), IMM(121));
MOV(IND(125), IMM(101));
MOV(IND(126), IMM(T_PAIR));
MOV(IND(127), IMM(118));
MOV(IND(128), IMM(123));
MOV(IND(129), IMM(T_INTEGER));
MOV(IND(130), IMM(3));
MOV(IND(131), IMM(T_INTEGER));
MOV(IND(132), IMM(4));
MOV(IND(133), IMM(T_INTEGER));
MOV(IND(134), IMM(5));
MOV(IND(135), IMM(T_PAIR));
MOV(IND(136), IMM(133));
MOV(IND(137), IMM(101));
MOV(IND(138), IMM(T_PAIR));
MOV(IND(139), IMM(108));
MOV(IND(140), IMM(135));
MOV(IND(141), IMM(T_PAIR));
MOV(IND(142), IMM(129));
MOV(IND(143), IMM(138));
MOV(IND(144), IMM(T_PAIR));
MOV(IND(145), IMM(126));
MOV(IND(146), IMM(141));
MOV(IND(147), IMM(T_PAIR));
MOV(IND(148), IMM(113));
MOV(IND(149), IMM(144));
MOV(IND(150), IMM(T_PAIR));
MOV(IND(151), IMM(147));
MOV(IND(152), IMM(101));
MOV(IND(153), IMM(T_PAIR));
MOV(IND(154), IMM(150));
MOV(IND(155), IMM(101));
MOV(IND(156), IMM(T_STRING));
MOV(IND(157), IMM(0));
MOV(IND(158), IMM(T_INTEGER));
MOV(IND(159), IMM(2));
MOV(IND(214), IMM(T_VOID));
MOV(IND(215), IMM(T_NIL));
MOV(IND(216), IMM(T_BOOL));
MOV(IND(217), IMM(1));
MOV(IND(218), IMM(T_BOOL));
MOV(IND(219), IMM(1));
MOV(IND(220), IMM(T_INTEGER));
MOV(IND(221), IMM(5));
MOV(IND(222), IMM(T_INTEGER));
MOV(IND(223), IMM(4));
MOV(IND(224), IMM(T_INTEGER));
MOV(IND(225), IMM(6));
MOV(IND(226), IMM(T_STRING));
MOV(IND(227), IMM(2));
MOV(IND(228), IMM(97));
MOV(IND(229), IMM(98));
MOV(IND(230), IMM(T_SYMBOL));
MOV(IND(231), IMM(226));
MOV(IND(232), IMM(T_INTEGER));
MOV(IND(233), IMM(7));
MOV(IND(234), IMM(T_CHAR));
MOV(IND(235), IMM(65));
MOV(IND(236), IMM(T_INTEGER));
MOV(IND(237), IMM(98));
MOV(IND(238), IMM(T_STRING));
MOV(IND(239), IMM(1));
MOV(IND(240), IMM(99));
MOV(IND(241), IMM(T_SYMBOL));
MOV(IND(242), IMM(238));
MOV(IND(243), IMM(T_INTEGER));
MOV(IND(244), IMM(65));
MOV(IND(245), IMM(T_INTEGER));
MOV(IND(246), IMM(97));
MOV(IND(247), IMM(T_INTEGER));
MOV(IND(248), IMM(10000));
MOV(IND(249), IMM(T_INTEGER));
MOV(IND(250), IMM(0));
MOV(IND(251), IMM(T_INTEGER));
MOV(IND(252), IMM(234));
MOV(IND(253), IMM(T_STRING));
MOV(IND(254), IMM(1));
MOV(IND(255), IMM(97));
MOV(IND(256), IMM(T_SYMBOL));
MOV(IND(257), IMM(253));
MOV(IND(258), IMM(T_VECTOR));
MOV(IND(259), IMM(3));
MOV(IND(260), IMM(256));
MOV(IND(261), IMM(104));
MOV(IND(262), IMM(101));
MOV(IND(263), IMM(T_STRING));
MOV(IND(264), IMM(1));
MOV(IND(265), IMM(97));
MOV(IND(266), IMM(T_SYMBOL));
MOV(IND(267), IMM(253));
MOV(IND(268), IMM(T_STRING));
MOV(IND(269), IMM(1));
MOV(IND(270), IMM(98));
MOV(IND(271), IMM(T_SYMBOL));
MOV(IND(272), IMM(268));
MOV(IND(273), IMM(T_PAIR));
MOV(IND(274), IMM(256));
MOV(IND(275), IMM(271));
MOV(IND(276), IMM(T_STRING));
MOV(IND(277), IMM(1));
MOV(IND(278), IMM(99));
MOV(IND(279), IMM(T_SYMBOL));
MOV(IND(280), IMM(238));
MOV(IND(281), IMM(T_STRING));
MOV(IND(282), IMM(1));
MOV(IND(283), IMM(97));
MOV(IND(284), IMM(T_SYMBOL));
MOV(IND(285), IMM(253));
MOV(IND(286), IMM(T_STRING));
MOV(IND(287), IMM(1));
MOV(IND(288), IMM(98));
MOV(IND(289), IMM(T_SYMBOL));
MOV(IND(290), IMM(268));
MOV(IND(291), IMM(T_VECTOR));
MOV(IND(292), IMM(3));
MOV(IND(293), IMM(256));
MOV(IND(294), IMM(271));
MOV(IND(295), IMM(241));
MOV(IND(296), IMM(T_INTEGER));
MOV(IND(297), IMM(3));
MOV(IND(298), IMM(T_STRING));
MOV(IND(299), IMM(6));
MOV(IND(300), IMM(108));
MOV(IND(301), IMM(97));
MOV(IND(302), IMM(109));
MOV(IND(303), IMM(98));
MOV(IND(304), IMM(100));
MOV(IND(305), IMM(97));
MOV(IND(306), IMM(T_SYMBOL));
MOV(IND(307), IMM(298));
MOV(IND(308), IMM(T_INTEGER));
MOV(IND(309), IMM(3));
MOV(IND(310), IMM(T_INTEGER));
MOV(IND(311), IMM(1));
MOV(IND(312), IMM(T_INTEGER));
MOV(IND(313), IMM(2));
MOV(IND(314), IMM(T_VECTOR));
MOV(IND(315), IMM(3));
MOV(IND(316), IMM(116));
MOV(IND(317), IMM(121));
MOV(IND(318), IMM(129));
MOV(IND(319), IMM(T_CHAR));
MOV(IND(320), IMM(97));
MOV(IND(321), IMM(T_STRING));
MOV(IND(322), IMM(3));
MOV(IND(323), IMM(97));
MOV(IND(324), IMM(98));
MOV(IND(325), IMM(99));
MOV(IND(326), IMM(T_STRING));
MOV(IND(327), IMM(1));
MOV(IND(328), IMM(97));
MOV(IND(329), IMM(T_SYMBOL));
MOV(IND(330), IMM(253));
MOV(IND(331), IMM(T_STRING));
MOV(IND(332), IMM(1));
MOV(IND(333), IMM(98));
MOV(IND(334), IMM(T_SYMBOL));
MOV(IND(335), IMM(268));
MOV(IND(336), IMM(T_STRING));
MOV(IND(337), IMM(1));
MOV(IND(338), IMM(99));
MOV(IND(339), IMM(T_SYMBOL));
MOV(IND(340), IMM(238));
MOV(IND(341), IMM(T_PAIR));
MOV(IND(342), IMM(241));
MOV(IND(343), IMM(101));
MOV(IND(344), IMM(T_PAIR));
MOV(IND(345), IMM(271));
MOV(IND(346), IMM(341));
MOV(IND(347), IMM(T_PAIR));
MOV(IND(348), IMM(256));
MOV(IND(349), IMM(344));
MOV(IND(350), IMM(T_INTEGER));
MOV(IND(351), IMM(1));
MOV(IND(352), IMM(T_STRING));
MOV(IND(353), IMM(1));
MOV(IND(354), IMM(97));
MOV(IND(355), IMM(T_SYMBOL));
MOV(IND(356), IMM(253));
MOV(IND(357), IMM(T_STRING));
MOV(IND(358), IMM(1));
MOV(IND(359), IMM(98));
MOV(IND(360), IMM(T_SYMBOL));
MOV(IND(361), IMM(268));
MOV(IND(362), IMM(T_INTEGER));
MOV(IND(363), IMM(1234));
MOV(IND(364), IMM(T_STRING));
MOV(IND(365), IMM(0));
MOV(IND(366), IMM(T_INTEGER));
MOV(IND(367), IMM(2));

PUSH(LABEL(PLUS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(160), R0);
PUSH(LABEL(MINUS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(161), R0);
PUSH(LABEL(MULTIPLY));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(162), R0);
PUSH(LABEL(DIVIDE));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(163), R0);
PUSH(LABEL(LOWER));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(164), R0);
PUSH(LABEL(GREATER));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(165), R0);
PUSH(LABEL(EQUAL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(166), R0);
PUSH(LABEL(IS_NUM));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(167), R0);
PUSH(LABEL(IS_INT));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(168), R0);
PUSH(LABEL(IS_BOOLEAN));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(169), R0);
PUSH(LABEL(IS_SYMBOL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(170), R0);
PUSH(LABEL(IS_CHAR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(171), R0);
PUSH(LABEL(IS_NULL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(172), R0);
PUSH(LABEL(IS_PAIR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(173), R0);
PUSH(LABEL(IS_STRING));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(174), R0);
PUSH(LABEL(OURS_IS_ZERO));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(175), R0);
PUSH(LABEL(IS_VECTOR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(176), R0);
PUSH(LABEL(IS_PROC));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(177), R0);
PUSH(LABEL(CHAR_2_INTEGER));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(178), R0);
PUSH(LABEL(INTEGER_2_CHAR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(179), R0);
PUSH(LABEL(STRING_LENGTH));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180), R0);
PUSH(LABEL(STRING_REF));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(181), R0);
PUSH(LABEL(STRING_SET));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(182), R0);
PUSH(LABEL(MAKE_STRING));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(183), R0);
PUSH(LABEL(VECTOR_LENGTH));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(184), R0);
PUSH(LABEL(VECTOR_REF));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(185), R0);
PUSH(LABEL(VECTOR_SET));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(186), R0);
PUSH(LABEL(MAKE_VECTOR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(187), R0);
PUSH(LABEL(CONS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(188), R0);
PUSH(LABEL(CAR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(189), R0);
PUSH(LABEL(CDR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(190), R0);
PUSH(LABEL(SET_CDR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(191), R0);
PUSH(LABEL(SET_CAR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(192), R0);
MOV(IND(193), IMM(999999));
PUSH(LABEL(VECTOR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(194), R0);
MOV(IND(195), IMM(999999));
MOV(IND(196), IMM(999999));
PUSH(LABEL(SYMBOL_2_STRING));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(197), R0);
PUSH(LABEL(STRING_2_SYMBOL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(198), R0);
PUSH(LABEL(CHECK_EQ_OBJECT));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(199), R0);
MOV(IND(200), IMM(999999));
MOV(IND(201), IMM(999999));
MOV(IND(202), IMM(999999));
MOV(IND(203), IMM(999999));
MOV(IND(204), IMM(999999));
MOV(IND(205), IMM(999999));
MOV(IND(206), IMM(999999));
MOV(IND(207), IMM(999999));
MOV(IND(208), IMM(999999));
MOV(IND(209), IMM(999999));
MOV(IND(210), IMM(999999));
MOV(IND(211), IMM(999999));
MOV(IND(212), IMM(999999));
MOV(IND(213), IMM(999999));
PUSH(LABEL(NOT));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(368), R0);

/* ----------initiating symbols string linked list---------- */
MOV(IND(369), IMM(230));
MOV(IND(370), IMM(371));
MOV(IND(371), IMM(241));
MOV(IND(372), IMM(373));
MOV(IND(373), IMM(256));
MOV(IND(374), IMM(375));
MOV(IND(375), IMM(266));
MOV(IND(376), IMM(377));
MOV(IND(377), IMM(271));
MOV(IND(378), IMM(379));
MOV(IND(379), IMM(279));
MOV(IND(380), IMM(381));
MOV(IND(381), IMM(284));
MOV(IND(382), IMM(383));
MOV(IND(383), IMM(289));
MOV(IND(384), IMM(385));
MOV(IND(385), IMM(306));
MOV(IND(386), IMM(387));
MOV(IND(387), IMM(329));
MOV(IND(388), IMM(389));
MOV(IND(389), IMM(334));
MOV(IND(390), IMM(391));
MOV(IND(391), IMM(339));
MOV(IND(392), IMM(393));
MOV(IND(393), IMM(355));
MOV(IND(394), IMM(395));
MOV(IND(395), IMM(360));
MOV(IND(396), IMM(0));

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel523:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel522);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel523);
closureEnvLoopEndLabel522: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel525:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel524);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel525);
closureParameterLoopEndLabel524: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel527));
JUMP(closureEndLabel526);
closureBodyLabel527:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(2));
JUMP_NE(ERROR);
/* code-gen on body */
/*ifExp*/
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(167));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse530);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(121));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(167));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse528);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(164));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

JUMP(labelIfExit529);
labelElse528:
/*const*/
MOV(R0, IMM(102));

labelIfExit529:

JUMP(labelIfExit531);
labelElse530:
/*const*/
MOV(R0, IMM(102));

labelIfExit531:

CMP(R0, FALSE);
JUMP_EQ(labelElse541);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

JUMP(labelIfExit542);
labelElse541:
/*ifExp*/
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(167));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse532);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(121));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(167));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

JUMP(labelIfExit533);
labelElse532:
/*const*/
MOV(R0, IMM(102));

labelIfExit533:

CMP(R0, FALSE);
JUMP_EQ(labelElse539);
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(161));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(200));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel534:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel535);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel534);
closureParameterLoopEndLabel535:
CMP(R5,R2);
JUMP_GE(greaterLabel537);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel536);
greaterLabel537:
CMP(R5,R2);
JUMP_EQ(equalLabel538);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel536);
equalLabel538:
DROP(R5);
DROP(1);endLabel536:
MOV(FP, R1);
JUMPA(INDD(R0, 2));


JUMP(labelIfExit540);
labelElse539:
/*const*/
MOV(R0, IMM(156));

labelIfExit540:

labelIfExit542:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel526:

MOV(IND(IMM(200)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel513:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel512);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel513);
closureEnvLoopEndLabel512: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel515:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel514);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel515);
closureParameterLoopEndLabel514: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel517));
JUMP(closureEndLabel516);
closureBodyLabel517:
PUSH(FP);
MOV(FP,SP);
/* lambda var body */
/* pop old fp */
POP(R10);
/* pop return address */
POP(R11);
/* pop env */
POP(R12);
/* pop number of arguments */
POP(R13);

/* no params */
CMP(R13,IMM(0));
JUMP_EQ(noParamsLabel518);
/* with params */
MOV(R14,R13);
MOV(R15,R13);
MOV(R4, IMM(0));
ADD(R15,IMM(1));
ADD(R14,IMM(2));
closurePushLoopLabel520:
CMP(R4,R13);
JUMP_EQ(closureParameterLoopEndLabel521);
MOV(R1, FPARG(R14));
PUSH(R1);
MOV(R1, FPARG(R15));
PUSH(R1);
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
MOV(FPARG(R14),R0);
INCR(R4);
DECR(R15);
JUMP(closurePushLoopLabel520);closureParameterLoopEndLabel521:
DROP(R13);
JUMP(EndLabel519);

noParamsLabel518:
MOV(R1, 101)
MOV(FPARG(IMM(1)),R1);
EndLabel519:
PUSH(R13);
PUSH(R12);
PUSH(R11);
PUSH(R10);
MOV(FP, SP);
/* code-gen on body */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel516:

MOV(IND(IMM(193)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(102));

PUSH(R0);
/*const*/
MOV(R0, IMM(102));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel464:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel463);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel464);
closureEnvLoopEndLabel463: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel466:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel465);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel466);
closureParameterLoopEndLabel465: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel468));
JUMP(closureEndLabel467);
closureBodyLabel468:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(2));
JUMP_NE(ERROR);
/* code-gen on body */
/* set-pvar */
/* box-pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));

MOV(IND(R0),FPARG(R10));

MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(FPARG(R10),R0);
MOV(R0,IMM(T_VOID));
/* set-pvar */
/* box-pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));

MOV(IND(R0),FPARG(R10));

MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(FPARG(R10),R0);
MOV(R0,IMM(T_VOID));
/* box-set-pvar */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel500:
CMP(R10,IMM(1));
JUMP_EQ(closureEnvLoopEndLabel499);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel500);
closureEnvLoopEndLabel499: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel502:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel501);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel502);
closureParameterLoopEndLabel501: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel504));
JUMP(closureEndLabel503);
closureBodyLabel504:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(2));
JUMP_NE(ERROR);
/* code-gen on body */
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(172));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse510);
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

JUMP(labelIfExit511);
labelElse510:
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(190));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/* box-get-bvar */
MOV(R1, FPARG(IMM(0)));
MOV(R1,INDD(R1,IMM(0)));
MOV(R1,INDD(R1,IMM(0)));
MOV(R0,IND(R1));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(188));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel505:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel506);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel505);
closureParameterLoopEndLabel506:
CMP(R5,R2);
JUMP_GE(greaterLabel508);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel507);
greaterLabel508:
CMP(R5,R2);
JUMP_EQ(equalLabel509);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel507);
equalLabel509:
DROP(R5);
DROP(1);endLabel507:
MOV(FP, R1);
JUMPA(INDD(R0, 2));


labelIfExit511:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel503:

MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(IND(R10),R0);
/* box-set-pvar */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel487:
CMP(R10,IMM(1));
JUMP_EQ(closureEnvLoopEndLabel486);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel487);
closureEnvLoopEndLabel486: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel489:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel488);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel489);
closureParameterLoopEndLabel488: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel491));
JUMP(closureEndLabel490);
closureBodyLabel491:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(2));
JUMP_NE(ERROR);
/* code-gen on body */
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(172));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse497);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

JUMP(labelIfExit498);
labelElse497:
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(190));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/* box-get-bvar */
MOV(R1, FPARG(IMM(0)));
MOV(R1,INDD(R1,IMM(0)));
MOV(R1,INDD(R1,IMM(1)));
MOV(R0,IND(R1));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/* box-get-bvar */
MOV(R1, FPARG(IMM(0)));
MOV(R1,INDD(R1,IMM(0)));
MOV(R1,INDD(R1,IMM(0)));
MOV(R0,IND(R1));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel492:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel493);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel492);
closureParameterLoopEndLabel493:
CMP(R5,R2);
JUMP_GE(greaterLabel495);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel494);
greaterLabel495:
CMP(R5,R2);
JUMP_EQ(equalLabel496);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel494);
equalLabel496:
DROP(R5);
DROP(1);endLabel494:
MOV(FP, R1);
JUMPA(INDD(R0, 2));


labelIfExit498:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel490:

MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(IND(R10),R0);
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel470:
CMP(R10,IMM(1));
JUMP_EQ(closureEnvLoopEndLabel469);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel470);
closureEnvLoopEndLabel469: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel472:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel471);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel472);
closureParameterLoopEndLabel471: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel474));
JUMP(closureEndLabel473);
closureBodyLabel474:
PUSH(FP);
MOV(FP,SP);
/* lambda var body */
/* pop old fp */
POP(R10);
/* pop return address */
POP(R11);
/* pop env */
POP(R12);
/* pop number of arguments */
POP(R13);

/* no params */
CMP(R13,IMM(0));
JUMP_EQ(noParamsLabel475);
/* with params */
MOV(R14,R13);
MOV(R15,R13);
MOV(R4, IMM(0));
ADD(R15,IMM(1));
ADD(R14,IMM(2));
closurePushLoopLabel477:
CMP(R4,R13);
JUMP_EQ(closureParameterLoopEndLabel478);
MOV(R1, FPARG(R14));
PUSH(R1);
MOV(R1, FPARG(R15));
PUSH(R1);
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
MOV(FPARG(R14),R0);
INCR(R4);
DECR(R15);
JUMP(closurePushLoopLabel477);closureParameterLoopEndLabel478:
DROP(R13);
JUMP(EndLabel476);

noParamsLabel475:
MOV(R1, 101)
MOV(FPARG(IMM(1)),R1);
EndLabel476:
PUSH(R13);
PUSH(R12);
PUSH(R11);
PUSH(R10);
MOV(FP, SP);
/* code-gen on body */
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(172));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse484);
/*const*/
MOV(R0, IMM(101));

JUMP(labelIfExit485);
labelElse484:
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(190));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/* box-get-bvar */
MOV(R1, FPARG(IMM(0)));
MOV(R1,INDD(R1,IMM(0)));
MOV(R1,INDD(R1,IMM(1)));
MOV(R0,IND(R1));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel479:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel480);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel479);
closureParameterLoopEndLabel480:
CMP(R5,R2);
JUMP_GE(greaterLabel482);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel481);
greaterLabel482:
CMP(R5,R2);
JUMP_EQ(equalLabel483);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel481);
equalLabel483:
DROP(R5);
DROP(1);endLabel481:
MOV(FP, R1);
JUMPA(INDD(R0, 2));


labelIfExit485:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel473:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel467:
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

MOV(IND(IMM(201)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel453:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel452);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel453);
closureEnvLoopEndLabel452: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel455:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel454);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel455);
closureParameterLoopEndLabel454: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel457));
JUMP(closureEndLabel456);
closureBodyLabel457:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(190));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel458:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel459);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel458);
closureParameterLoopEndLabel459:
CMP(R5,R2);
JUMP_GE(greaterLabel461);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel460);
greaterLabel461:
CMP(R5,R2);
JUMP_EQ(equalLabel462);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel460);
equalLabel462:
DROP(R5);
DROP(1);endLabel460:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel456:

MOV(IND(IMM(202)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel442:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel441);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel442);
closureEnvLoopEndLabel441: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel444:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel443);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel444);
closureParameterLoopEndLabel443: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel446));
JUMP(closureEndLabel445);
closureBodyLabel446:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel447:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel448);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel447);
closureParameterLoopEndLabel448:
CMP(R5,R2);
JUMP_GE(greaterLabel450);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel449);
greaterLabel450:
CMP(R5,R2);
JUMP_EQ(equalLabel451);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel449);
equalLabel451:
DROP(R5);
DROP(1);endLabel449:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel445:

MOV(IND(IMM(203)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel431:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel430);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel431);
closureEnvLoopEndLabel430: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel433:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel432);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel433);
closureParameterLoopEndLabel432: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel435));
JUMP(closureEndLabel434);
closureBodyLabel435:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(190));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(190));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel436:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel437);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel436);
closureParameterLoopEndLabel437:
CMP(R5,R2);
JUMP_GE(greaterLabel439);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel438);
greaterLabel439:
CMP(R5,R2);
JUMP_EQ(equalLabel440);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel438);
equalLabel440:
DROP(R5);
DROP(1);endLabel438:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel434:

MOV(IND(IMM(204)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel420:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel419);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel420);
closureEnvLoopEndLabel419: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel422:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel421);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel422);
closureParameterLoopEndLabel421: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel424));
JUMP(closureEndLabel423);
closureBodyLabel424:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(190));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(190));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel425:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel426);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel425);
closureParameterLoopEndLabel426:
CMP(R5,R2);
JUMP_GE(greaterLabel428);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel427);
greaterLabel428:
CMP(R5,R2);
JUMP_EQ(equalLabel429);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel427);
equalLabel429:
DROP(R5);
DROP(1);endLabel427:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel423:

MOV(IND(IMM(205)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel409:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel408);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel409);
closureEnvLoopEndLabel408: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel411:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel410);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel411);
closureParameterLoopEndLabel410: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel413));
JUMP(closureEndLabel412);
closureBodyLabel413:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(190));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel414:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel415);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel414);
closureParameterLoopEndLabel415:
CMP(R5,R2);
JUMP_GE(greaterLabel417);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel416);
greaterLabel417:
CMP(R5,R2);
JUMP_EQ(equalLabel418);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel416);
equalLabel418:
DROP(R5);
DROP(1);endLabel416:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel412:

MOV(IND(IMM(206)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel398:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel397);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel398);
closureEnvLoopEndLabel397: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel400:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel399);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel400);
closureParameterLoopEndLabel399: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel402));
JUMP(closureEndLabel401);
closureBodyLabel402:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(190));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(190));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(190));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel403:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel404);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel403);
closureParameterLoopEndLabel404:
CMP(R5,R2);
JUMP_GE(greaterLabel406);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel405);
greaterLabel406:
CMP(R5,R2);
JUMP_EQ(equalLabel407);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel405);
equalLabel407:
DROP(R5);
DROP(1);endLabel405:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel401:

MOV(IND(IMM(207)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel387:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel386);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel387);
closureEnvLoopEndLabel386: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel389:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel388);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel389);
closureParameterLoopEndLabel388: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel391));
JUMP(closureEndLabel390);
closureBodyLabel391:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel392:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel393);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel392);
closureParameterLoopEndLabel393:
CMP(R5,R2);
JUMP_GE(greaterLabel395);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel394);
greaterLabel395:
CMP(R5,R2);
JUMP_EQ(equalLabel396);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel394);
equalLabel396:
DROP(R5);
DROP(1);endLabel394:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel390:

MOV(IND(IMM(208)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel376:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel375);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel376);
closureEnvLoopEndLabel375: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel378:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel377);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel378);
closureParameterLoopEndLabel377: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel380));
JUMP(closureEndLabel379);
closureBodyLabel380:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(190));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel381:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel382);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel381);
closureParameterLoopEndLabel382:
CMP(R5,R2);
JUMP_GE(greaterLabel384);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel383);
greaterLabel384:
CMP(R5,R2);
JUMP_EQ(equalLabel385);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel383);
equalLabel385:
DROP(R5);
DROP(1);endLabel383:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel379:

MOV(IND(IMM(209)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel365:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel364);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel365);
closureEnvLoopEndLabel364: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel367:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel366);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel367);
closureParameterLoopEndLabel366: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel369));
JUMP(closureEndLabel368);
closureBodyLabel369:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(190));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(190));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel370:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel371);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel370);
closureParameterLoopEndLabel371:
CMP(R5,R2);
JUMP_GE(greaterLabel373);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel372);
greaterLabel373:
CMP(R5,R2);
JUMP_EQ(equalLabel374);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel372);
equalLabel374:
DROP(R5);
DROP(1);endLabel372:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel368:

MOV(IND(IMM(210)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel354:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel353);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel354);
closureEnvLoopEndLabel353: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel356:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel355);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel356);
closureParameterLoopEndLabel355: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel358));
JUMP(closureEndLabel357);
closureBodyLabel358:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(190));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(190));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(190));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel359:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel360);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel359);
closureParameterLoopEndLabel360:
CMP(R5,R2);
JUMP_GE(greaterLabel362);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel361);
greaterLabel362:
CMP(R5,R2);
JUMP_EQ(equalLabel363);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel361);
equalLabel363:
DROP(R5);
DROP(1);endLabel361:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel357:

MOV(IND(IMM(211)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel343:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel342);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel343);
closureEnvLoopEndLabel342: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel345:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel344);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel345);
closureParameterLoopEndLabel344: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel347));
JUMP(closureEndLabel346);
closureBodyLabel347:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(190));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(190));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(190));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(190));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel348:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel349);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel348);
closureParameterLoopEndLabel349:
CMP(R5,R2);
JUMP_GE(greaterLabel351);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel350);
greaterLabel351:
CMP(R5,R2);
JUMP_EQ(equalLabel352);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel350);
equalLabel352:
DROP(R5);
DROP(1);endLabel350:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel346:

MOV(IND(IMM(212)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel332:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel331);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel332);
closureEnvLoopEndLabel331: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel334:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel333);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel334);
closureParameterLoopEndLabel333: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel336));
JUMP(closureEndLabel335);
closureBodyLabel336:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel337:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel338);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel337);
closureParameterLoopEndLabel338:
CMP(R5,R2);
JUMP_GE(greaterLabel340);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel339);
greaterLabel340:
CMP(R5,R2);
JUMP_EQ(equalLabel341);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel339);
equalLabel341:
DROP(R5);
DROP(1);endLabel339:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel335:

MOV(IND(IMM(213)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(104));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(169));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse329);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(102));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(169));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse327);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(362));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(169));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(368));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse325);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(256));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(169));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(368));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse323);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(271));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(170));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse321);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*fvar */
MOV(R0, IND(177));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(177));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse319);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(256));

PUSH(R0);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(347));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(199));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse317);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(116));

PUSH(R0);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(121));

PUSH(R0);
/*const*/
MOV(R0, IMM(116));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(188));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(189));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(166));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse315);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(362));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(168));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse313);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(319));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(171));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse311);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(101));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(172));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse309);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(321));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(174));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse307);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(306));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(170));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse305);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(314));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(176));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse303);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(362));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(176));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(368));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse301);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(291));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(174));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(368));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse299);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(362));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(174));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(368));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse297);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(258));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(184));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/*const*/
MOV(R0, IMM(129));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(166));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse295);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(273));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(173));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse293);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(101));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(173));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(368));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse291);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(249));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(175));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse289);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(251));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(175));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(368));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse287);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(249));

PUSH(R0);
/*const*/
MOV(R0, IMM(321));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(181));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(178));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/*const*/
MOV(R0, IMM(245));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(166));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse285);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(247));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel214:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel213);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel214);
closureEnvLoopEndLabel213: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel216:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel215);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel216);
closureParameterLoopEndLabel215: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel218));
JUMP(closureEndLabel217);
closureBodyLabel218:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(183));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(180));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(166));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel219:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel220);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel219);
closureParameterLoopEndLabel220:
CMP(R5,R2);
JUMP_GE(greaterLabel222);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel221);
greaterLabel222:
CMP(R5,R2);
JUMP_EQ(equalLabel223);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel221);
equalLabel223:
DROP(R5);
DROP(1);endLabel221:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel217:
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse283);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(247));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel225:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel224);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel225);
closureEnvLoopEndLabel224: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel227:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel226);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel227);
closureParameterLoopEndLabel226: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel229));
JUMP(closureEndLabel228);
closureBodyLabel229:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(187));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(184));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(166));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel230:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel231);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel230);
closureParameterLoopEndLabel231:
CMP(R5,R2);
JUMP_GE(greaterLabel233);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel232);
greaterLabel233:
CMP(R5,R2);
JUMP_EQ(equalLabel234);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel232);
equalLabel234:
DROP(R5);
DROP(1);endLabel232:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel228:
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse281);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(291));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel236:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel235);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel236);
closureEnvLoopEndLabel235: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel238:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel237);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel238);
closureParameterLoopEndLabel237: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel240));
JUMP(closureEndLabel239);
closureBodyLabel240:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(121));

PUSH(R0);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(185));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/*const*/
MOV(R0, IMM(241));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(199));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel241:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel242);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel241);
closureParameterLoopEndLabel242:
CMP(R5,R2);
JUMP_GE(greaterLabel244);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel243);
greaterLabel244:
CMP(R5,R2);
JUMP_EQ(equalLabel245);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel243);
equalLabel245:
DROP(R5);
DROP(1);endLabel243:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel239:
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse279);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(234));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(178));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/*const*/
MOV(R0, IMM(243));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(166));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse277);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(121));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(183));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel247:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel246);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel247);
closureEnvLoopEndLabel246: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel249:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel248);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel249);
closureParameterLoopEndLabel248: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel251));
JUMP(closureEndLabel250);
closureBodyLabel251:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(245));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(179));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/*const*/
MOV(R0, IMM(249));

PUSH(R0);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(3));
/*fvar */
MOV(R0, IND(182));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(236));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(179));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/*const*/
MOV(R0, IMM(116));

PUSH(R0);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(3));
/*fvar */
MOV(R0, IND(182));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(198));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/*const*/
MOV(R0, IMM(230));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(199));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel252:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel253);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel252);
closureParameterLoopEndLabel253:
CMP(R5,R2);
JUMP_GE(greaterLabel255);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel254);
greaterLabel255:
CMP(R5,R2);
JUMP_EQ(equalLabel256);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel254);
equalLabel256:
DROP(R5);
DROP(1);endLabel254:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel250:
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse275);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(108));

PUSH(R0);
/*const*/
MOV(R0, IMM(232));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(200));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/*const*/
MOV(R0, IMM(129));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(166));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse273);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(129));

PUSH(R0);
/*const*/
MOV(R0, IMM(121));

PUSH(R0);
/*const*/
MOV(R0, IMM(116));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(3));
/*fvar */
MOV(R0, IND(162));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/*const*/
MOV(R0, IMM(224));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(166));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse271);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* push number of arguments */
PUSH(IMM(0));
/*fvar */
MOV(R0, IND(162));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/*const*/
MOV(R0, IMM(116));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(166));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse269);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(251));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(162));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/*const*/
MOV(R0, IMM(251));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(166));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse267);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(129));

PUSH(R0);
/*const*/
MOV(R0, IMM(121));

PUSH(R0);
/*const*/
MOV(R0, IMM(116));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(3));
/*fvar */
MOV(R0, IND(160));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/*const*/
MOV(R0, IMM(224));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(166));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse265);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* push number of arguments */
PUSH(IMM(0));
/*fvar */
MOV(R0, IND(160));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(175));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse263);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(251));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(160));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/*const*/
MOV(R0, IMM(251));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(166));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse261);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(121));

PUSH(R0);
/*const*/
MOV(R0, IMM(129));

PUSH(R0);
/*const*/
MOV(R0, IMM(224));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(3));
/*fvar */
MOV(R0, IND(161));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/*const*/
MOV(R0, IMM(116));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(166));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse259);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(133));

PUSH(R0);
/*const*/
MOV(R0, IMM(108));

PUSH(R0);
/*const*/
MOV(R0, IMM(129));

PUSH(R0);
/*const*/
MOV(R0, IMM(121));

PUSH(R0);
/*const*/
MOV(R0, IMM(116));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(5));
/*fvar */
MOV(R0, IND(164));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse257);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(116));

PUSH(R0);
/*const*/
MOV(R0, IMM(121));

PUSH(R0);
/*const*/
MOV(R0, IMM(129));

PUSH(R0);
/*const*/
MOV(R0, IMM(108));

PUSH(R0);
/*const*/
MOV(R0, IMM(133));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(5));
/*fvar */
MOV(R0, IND(165));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

JUMP(labelIfExit258);
labelElse257:
/*const*/
MOV(R0, IMM(102));

labelIfExit258:

JUMP(labelIfExit260);
labelElse259:
/*const*/
MOV(R0, IMM(102));

labelIfExit260:

JUMP(labelIfExit262);
labelElse261:
/*const*/
MOV(R0, IMM(102));

labelIfExit262:

JUMP(labelIfExit264);
labelElse263:
/*const*/
MOV(R0, IMM(102));

labelIfExit264:

JUMP(labelIfExit266);
labelElse265:
/*const*/
MOV(R0, IMM(102));

labelIfExit266:

JUMP(labelIfExit268);
labelElse267:
/*const*/
MOV(R0, IMM(102));

labelIfExit268:

JUMP(labelIfExit270);
labelElse269:
/*const*/
MOV(R0, IMM(102));

labelIfExit270:

JUMP(labelIfExit272);
labelElse271:
/*const*/
MOV(R0, IMM(102));

labelIfExit272:

JUMP(labelIfExit274);
labelElse273:
/*const*/
MOV(R0, IMM(102));

labelIfExit274:

JUMP(labelIfExit276);
labelElse275:
/*const*/
MOV(R0, IMM(102));

labelIfExit276:

JUMP(labelIfExit278);
labelElse277:
/*const*/
MOV(R0, IMM(102));

labelIfExit278:

JUMP(labelIfExit280);
labelElse279:
/*const*/
MOV(R0, IMM(102));

labelIfExit280:

JUMP(labelIfExit282);
labelElse281:
/*const*/
MOV(R0, IMM(102));

labelIfExit282:

JUMP(labelIfExit284);
labelElse283:
/*const*/
MOV(R0, IMM(102));

labelIfExit284:

JUMP(labelIfExit286);
labelElse285:
/*const*/
MOV(R0, IMM(102));

labelIfExit286:

JUMP(labelIfExit288);
labelElse287:
/*const*/
MOV(R0, IMM(102));

labelIfExit288:

JUMP(labelIfExit290);
labelElse289:
/*const*/
MOV(R0, IMM(102));

labelIfExit290:

JUMP(labelIfExit292);
labelElse291:
/*const*/
MOV(R0, IMM(102));

labelIfExit292:

JUMP(labelIfExit294);
labelElse293:
/*const*/
MOV(R0, IMM(102));

labelIfExit294:

JUMP(labelIfExit296);
labelElse295:
/*const*/
MOV(R0, IMM(102));

labelIfExit296:

JUMP(labelIfExit298);
labelElse297:
/*const*/
MOV(R0, IMM(102));

labelIfExit298:

JUMP(labelIfExit300);
labelElse299:
/*const*/
MOV(R0, IMM(102));

labelIfExit300:

JUMP(labelIfExit302);
labelElse301:
/*const*/
MOV(R0, IMM(102));

labelIfExit302:

JUMP(labelIfExit304);
labelElse303:
/*const*/
MOV(R0, IMM(102));

labelIfExit304:

JUMP(labelIfExit306);
labelElse305:
/*const*/
MOV(R0, IMM(102));

labelIfExit306:

JUMP(labelIfExit308);
labelElse307:
/*const*/
MOV(R0, IMM(102));

labelIfExit308:

JUMP(labelIfExit310);
labelElse309:
/*const*/
MOV(R0, IMM(102));

labelIfExit310:

JUMP(labelIfExit312);
labelElse311:
/*const*/
MOV(R0, IMM(102));

labelIfExit312:

JUMP(labelIfExit314);
labelElse313:
/*const*/
MOV(R0, IMM(102));

labelIfExit314:

JUMP(labelIfExit316);
labelElse315:
/*const*/
MOV(R0, IMM(102));

labelIfExit316:

JUMP(labelIfExit318);
labelElse317:
/*const*/
MOV(R0, IMM(102));

labelIfExit318:

JUMP(labelIfExit320);
labelElse319:
/*const*/
MOV(R0, IMM(102));

labelIfExit320:

JUMP(labelIfExit322);
labelElse321:
/*const*/
MOV(R0, IMM(102));

labelIfExit322:

JUMP(labelIfExit324);
labelElse323:
/*const*/
MOV(R0, IMM(102));

labelIfExit324:

JUMP(labelIfExit326);
labelElse325:
/*const*/
MOV(R0, IMM(102));

labelIfExit326:

JUMP(labelIfExit328);
labelElse327:
/*const*/
MOV(R0, IMM(102));

labelIfExit328:

JUMP(labelIfExit330);
labelElse329:
/*const*/
MOV(R0, IMM(102));

labelIfExit330:

CALL(PRINT_R0);


PROG_ENDING: 
  MOV(SP,FP);
  POP(FP);
  STOP_MACHINE;
  return 0;
}
