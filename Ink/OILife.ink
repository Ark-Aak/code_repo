VAR day = 0
VAR hp = 100
VAR sp = 100
VAR ability = 50
VAR evaluate = 50
VAR relationStudents = 50
VAR month = 9
VAR date = 1
VAR ARCH = 0
VAR ARCHCSP = 0
VAR ARCHNOIP = 0
VAR ARCHSEL = 0
VAR ARCHNOI = 0
VAR hasSpecialContest = 0
VAR scoreSEL = 0
VAR limSEL = 0
VAR scoreNOI = 0
VAR limNOI = 0
CONST CSIM = 0
CONST CCSP = 1
CONST CNOIP = 2
CONST CSEL = 3
CONST CNOI = 4

// 10/21
// 11/30
// 3/2 ~ 3/3
// 7/16 ~ 7/23

-> Begining

=== function check ===
{
    - ability < 0:
        ~ ability = 0
    - ability > 100:
        ~ ability = 100
    - sp > 100:
        ~ sp = 100
    - sp < 0:
        ~ sp = 0
    - evaluate < 0:
        ~ evaluate = 0
    - evaluate > 100:
        ~ evaluate = 100
    - hp < 0:
        ~ hp = 0
    - hp > 100:
        ~ hp = 100
    - relationStudents < 0:
        ~ relationStudents = 0
    - relationStudents > 100:
        ~ relationStudents = 100
}

=== function calcDay ===
~ date += 1
{
    - date == 32 and (month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12):
        ~ date = 1
        ~ month += 1
    - date == 31 and (month == 4 or month == 6 or month == 9 or month == 11):
        ~ date = 1
        ~ month += 1
    - date == 29 and month == 2:
        ~ date = 1
        ~ month += 1
}
{
    - month == 13:
        ~ month = 1
    - month == 8 and date == 1:
        ~ ARCHCSP = 0
        ~ ARCHNOIP = 0
        ~ ARCHSEL = 0
        ~ ARCHNOI = 0
        ~ limSEL = 0
        ~ limNOI = 0
        ~ scoreSEL = 0
        ~ scoreNOI = 0
}

=== function randomNotice ===
~ temp chance_sp = 10 + (30 - sp) * 3
~ temp chance_hp = 10 + (30 - hp) * 3
~ temp dice_sp = RANDOM(1, 100)
~ temp dice_hp = RANDOM(1, 100)
{
    - sp <= 30 and dice_sp <= chance_sp:
        你感觉头脑有些不清醒。
    - hp <= 30 and dice_hp <= chance_hp:
        你感觉身体有些不舒服。
}

=== function checkSpecialContest() ===
{
    - month == 10 and date == 21:
        ~ return CCSP
    - month == 11 and date == 30 and ARCHCSP == 1:
        ~ return CNOIP
    - month == 3 and (date == 2 or date == 3) and ARCHNOIP == 1:
        ~ return CSEL
    - month == 7 and (date >= 16 and date <= 23) and ARCHSEL == 2:
        ~ return CNOI
    - else:
        ~ return 0
}

=== function checkHasContest() ===
{
    - month == 10 and date == 21:
        ~ return 1
    - month == 11 and date == 30:
        ~ return 1
    - month == 3 and (date == 2 or date == 3):
        ~ return 1
    - month == 7 and (date == 19 or date == 21):
        ~ return 1
    - else:
        ~ return 0
}

=== NextDay ===
~ calcDay()
~ check()
+ [下一天] -> Begining

=== SpecialContest ===

= CSP
{
    - hasSpecialContest:
        -> Contest(400, "CSP", CCSP)
    - else:
        -> GoHome
}

= NOIP
{
    - hasSpecialContest:
        -> Contest(400, "NOIP", CNOIP)
    - else:
        -> GoHome
}
-> GoHome

= SEL
{
    - hasSpecialContest:
        -> Contest(300, "省选", CSEL)
    - else:
        -> GoHome
}
-> GoHome

= NOI
{
    - hasSpecialContest:
        -> Contest(300, "NOI", CNOI)
    - else:
        今天没有考试，只是一些活动而已。
        -> GoHome
}
-> GoHome

=== Begining ===
~ day = day + 1
~ hp = hp - RANDOM(0, 3)
~ sp = sp - RANDOM(0, 10)
~ sp = sp - RANDOM(0, INT((100 - relationStudents) / 20))
{
    - relationStudents <= 30:
        ~ evaluate -= RANDOM(0, INT((100 - relationStudents) / 30))
}
~ check()
{
    - hp <= 0:
        -> Dead
    - sp <= 0:
        -> Crazy
    - evaluate <= 0:
        -> AFO(0)
    - day >= 630 and ARCH < 10:
        -> AFO(1)
    - day >= 995:
        -> AFO(2)
}
今天是 {month} 月 {date} 日。
~ randomNotice()
~ temp special = checkSpecialContest()
~ hasSpecialContest = checkHasContest()
+ {not special} [去上学] -> StartClass
+ {not special} [请假]   -> RunAway
+ {special == CCSP} [参加 CSP] -> SpecialContest.CSP
+ {special == CNOIP} [参加 NOIP] -> SpecialContest.NOIP
+ {special == CSEL} [参加 省选] -> SpecialContest.SEL
+ {special == CNOI} [参加 NOI] -> SpecialContest.NOI

=== StartClass ===
~ temp dice = RANDOM(1, 10)
{
    - dice > 4:
        -> Contest(400, "模拟赛", CSIM)
    - else:
        -> Practice
}

=== function showResult(score, lim, type) ===
分数线是 {lim}。
{
    - type == CCSP or type == CNOIP:
        {
            - score < lim:
                {
                    - type == CCSP:
                        你没通过 CSP。
                        ~ ARCHCSP = 0
                        ~ ARCH = 5
                    - type == CNOIP:
                        你没通过 NOIP。
                        ~ ARCHNOIP = 0
                        ~ ARCH = 6
                }
            - else:
                {
                    - type == CCSP:
                        你通过了 CSP。
                        ~ ARCHCSP = 1
                        ~ ARCH = 7
                    - type == CNOIP:
                        你通过了 NOIP。
                        ~ ARCHNOIP = 1
                        ~ ARCH = 7
                }
        }
    - type == CSEL:
        {
            - limSEL > 0:
                {
                    - limSEL + lim <= scoreSEL + score:
                        你进省队了。
                        ~ ARCHSEL = 1
                        ~ ARCH = 7
                    - else:
                        你没进省队。
                        ~ ARCHSEL = 0
                        ~ ARCH = 7
                }
        }
    - else:
        {
            - limNOI > 0:
                {
                    - limNOI + lim <= scoreNOI + score:
                        你 Au 了。
                        ~ ARCHNOI = 3
                        ~ ARCH = 10
                    - else:
                        {
                            - INT((limNOI + lim) * 0.7) <= scoreNOI + score:
                                你 Ag 了。
                                ~ ARCHNOI = 2
                                ~ ARCH = 9
                            - INT((limNOI + lim) * 0.5) <= scoreNOI + score:
                                你 Cu 了。
                                ~ ARCHNOI = 1
                                ~ ARCH = 8
                            - else:
                                你打铁了。
                                ~ ARCHNOI = 0
                                ~ ARCH = 7
                        }
                }
        }
}
{
    - type == CSEL:
        ~ limSEL += lim
        ~ scoreSEL += score
    - type == CNOI:
        ~ limNOI += lim
        ~ scoreNOI += score
}

=== Contest(maxScore, name, type) ===
~ temp difficulty = RANDOM(1, 99)
~ temp diff = difficulty - ability
~ temp scorePara = FLOAT(100 - difficulty) / FLOAT(ability)
{
    - scorePara > 1.0:
        ~ scorePara = 1.0
}
~ temp scoreLimit = INT(FLOAT(maxScore) * scorePara)
~ temp scoreMax = INT(FLOAT(maxScore) * (1 - (FLOAT(difficulty) / 100.0)))
~ temp score = RANDOM(0, INT(scoreLimit))
~ temp expect = INT(scoreLimit / 2.0)
~ temp scoreDiff = INT(score - expect)
今天是{name}，你觉得{diff > 20:很难|{diff <= 20 and diff > -20:还行|很简单}}。
// 考试的难度值是 {difficulty}，而你的能力是 {ability}。
你{scoreDiff < 0:挂了 {-scoreDiff}|多了 {scoreDiff}} 分，实际得了 {score} 分，{scoreDiff > 50:高于|{scoreDiff <= 50 and scoreDiff >= -50:符合|低于}}你的预期。
~ ability = ability + RANDOM(1, 5)
{
    - scoreDiff > 50:
        ~ evaluate = evaluate + RANDOM(5, 10)
        ~ relationStudents = relationStudents + RANDOM(1, 5)
        ~ sp = sp + RANDOM(3, 5)
    - scoreDiff <= 50 and scoreDiff >= -50:
        ~ evaluate = evaluate + RANDOM(-1, 6)
        ~ relationStudents = relationStudents + RANDOM(-1, 2)
        ~ sp = sp + RANDOM(-1, 2)
    - else:
        ~ evaluate = evaluate + RANDOM(-5, -1)
        ~ relationStudents = relationStudents + RANDOM(-3, 1)
        ~ sp = sp + RANDOM(-3, 0)
}
~ check()
你的预期是 {INT(expect)} 分。
{
    - type != 0:
        {
            - type == CCSP:
                ~ showResult(score, scoreMax, CCSP)
            - type == CNOIP:
                ~ showResult(score, scoreMax, CNOIP)
            - type == CSEL:
                ~ showResult(score, scoreMax, CSEL)
            - type == CNOI:
                ~ showResult(score, scoreMax, CNOI)
        }
}
~ check()
-> GoHome

=== Rest ===
= Start
你打算干什么
+ [看 Pixiv] -> pixiv
+ [看 知乎] -> zhihu
+ [看 洛谷灌水区] -> luogu
+ [返回] -> Practice

= pixiv
你看着你喜欢的角色被超市，越看越想看。
~ sp += RANDOM(5, 10)
~ hp -= RANDOM(3, 5)
~ relationStudents += RANDOM(-2, 1)
~ ability -= RANDOM(1, 2)
~ check()

-> GoHome

= zhihu
你不停的翻看着知乎，感觉不到时间的流逝。
~ sp += RANDOM(1, 2)
~ ability -= RANDOM(2, 3)
~ relationStudents -= RANDOM(1, 2)
~ check()

-> GoHome

= luogu
你在洛谷灌水区和猴子激情对线。
同学也来帮你。
~ relationStudents += RANDOM(1, 10)
~ ability += RANDOM(-2, 1)
~ sp -= RANDOM(2, 3)
~ check()

-> GoHome

=== Practice ===

= before
今天改题。
你要干什么？
+ [摸鱼] -> Rest
+ [改题] -> practice

= practice
~ temp dice = RANDOM(1, 10)
{
    - dice > 4:
        你遇到了一些问题。
        -> AskQuestion
    - else:
        改题一帆风顺。
        ~ sp = sp + RANDOM(1, 3)
        ~ ability = ability + RANDOM(1, 3)
}
~ check()
-> GoHome

=== AskQuestion ===
    + [问老师]你去问了老师。
    -> AskTeacher
    + [问同学]你去问了同学。
    -> AskStudent
    + [算了吧]你没有管这个问题。
    -> NoAsk

=== AskTeacher ===
老师告诉了你解法。
~ ability = ability + RANDOM(1, 3)
~ evaluate = evaluate + RANDOM(3, 5)
~ check()
-> GoHome

=== AskStudent ===
~ temp dice = RANDOM(0, 100)
{
    - dice <= relationStudents:
        同学告诉了你解法。
        ~ relationStudents = relationStudents + RANDOM(-2, 2)
        ~ ability = ability + RANDOM(1, 3)
    - else:
        同学没有理你。
        ~ sp = sp - RANDOM(5, 8)
}
~ check()
-> GoHome

=== NoAsk ===
~ ability = ability - RANDOM(1, 3)
~ check()
-> GoHome

=== RunAway ===
你请假在家休息。
~ sp = sp + RANDOM(5, 8)
~ hp = hp + RANDOM(0, 1)
~ ability = ability - RANDOM(3, 5)
~ evaluate = evaluate - RANDOM(5, 10)
~ relationStudents = relationStudents - RANDOM(10, 20)
~ check()
-> GoHome

=== GoHome ===
~ check()
你回家了。
+ [洗澡睡觉] -> Sleep
+ [熬夜内卷] -> StayUp
+ {Rest.pixiv} [熬夜打胶] -> Milking
+ {StayUp > 10} [通宵内卷] -> StayUpAllNight

=== Milking ===
~ sp = sp + RANDOM(25, 30)
~ hp = hp - RANDOM(15, 20)
~ check()
你爽到了，感觉要飞升了，不知不觉就睡着了。
-> NextDay

=== Sleep ===
~ sp = sp + RANDOM(5, 10)
~ hp = hp + RANDOM(3, 5)
~ ability = ability - RANDOM(0, 1)
~ check()
你困了，回家火速洗完澡就睡觉了。
睡得很舒服。
-> NextDay

=== StayUp ===
~ ability = ability + RANDOM(5, 10)
~ sp = sp - RANDOM(5, 10)
~ hp = hp - RANDOM(5, 10)
~ check()
卷了一些时候了，你有些疲倦了。
你去睡觉了。
-> NextDay

=== StayUpAllNight ===
~ ability = ability + RANDOM(15, 20)
~ sp = sp - RANDOM(25, 30)
~ hp = hp - RANDOM(25, 30)
~ check()
你卷了一通宵。
-> NextDay

=== Dead ===
你去世了。
-> End

=== Crazy ===
你疯了。
-> End

=== AFO(whk) ===
{
    - whk == 1:
        你高二还没 Au，不得不退役准备高考。
    - whk == 2:
        你上大学了。
    - else:
        你被教练勒令退役。
}
-> End

=== End ===
你存活了 {day} 天。
你的 CCF 等级达到了 {ARCH} 级。
你的能力值达到了 {ability}。
老师对你的评价是 {evaluate}。
你和同学的关系值为 {relationStudents}。
-> END
