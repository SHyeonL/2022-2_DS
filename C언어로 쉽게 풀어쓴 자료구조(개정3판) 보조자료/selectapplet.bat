@echo off 
echo "1 ->선택정렬""
echo "2 ->순차탐색""
echo "3 ->팩토리얼""
echo "4 ->하노이 타워""
echo "5 ->다항식""
echo "6 ->ArrayList""
echo "7 ->DoublyLinkedList""
echo "8 ->LinkedList""
echo "9 ->CalcExpr"
echo "10 ->CheckParen"
echo "11 ->InfixToPostfix"
echo "12 ->LinkedStack"
echo "13 ->maze"
echo "14 ->StackApplet"
echo "15 ->CircularQueue"
echo "16 ->LinearQueue"
echo "17 ->LinkedQueue"
echo "18 ->BinaryTreeTrav"
echo "19 ->BST"
echo "20 ->BSTCode"
echo "21 ->HeapTree"
echo "22 ->HeapSort"
echo "23 ->MergeSort"
echo "24 ->RadixSort"
echo "25 ->ShellSort"
echo "26 ->SortApplet"
echo "27 ->BfsDfs"
echo "28 ->GraphTerms"
echo "29 ->MST"
echo "30 ->ShortestPath"
echo "31 ->topo"
echo "32 ->HashChain"
echo "33 ->HashLinear"
echo "34 ->SearchApplet"
echo "35 ->Tree23"
echo "36 ->TreeAVL"
set /p number=실행을 원하는 애플릿 번호를 입력해주세요: 

IF %number%==1 (java -jar applet\chap01\applet1\sortapplet.jar)
IF %number%==2 (java -jar applet\chap01\applet2\sortapplet2.jar)

IF %number%==3 (cd applet\chap02\Factorial)
IF %number%==3 (java -jar sortapplet3.jar)

IF %number%==4 (cd applet\chap02\TowerOfHanoi)
IF %number%==4 (java -jar sortapplet4.jar)

IF %number%==5 (cd applet\chap03\Polynomial)
IF %number%==5 (java -jar sortapplet5.jar)

IF %number%==6 (cd applet\chap04\ArrayList)
IF %number%==6 (java -jar sortapplet6.jar)

IF %number%==7 (cd applet\chap04\DoubleLinkedList)
IF %number%==7 (java -jar sortapplet7.jar)

IF %number%==8 (cd applet\chap04\LinkedList)
IF %number%==8 (java -jar sortapplet8.jar)

IF %number%==9 (cd applet\chap05\CalcExpr)
IF %number%==9 (java -jar CalcExpr.jar)

IF %number%==10 (cd applet\chap05\CheckParen)
IF %number%==10 (java -jar CheckParen.jar)

IF %number%==11 (cd applet\chap05\InfixToPostfix)
IF %number%==11 (appletviewer SortApplet.html)

IF %number%==12 (cd applet\chap05\LinkedStackApplet)
IF %number%==12 (java -jar LinkedStack.jar)

IF %number%==13 (cd applet\chap05\maze)
IF %number%==13 (java -jar Maze.jar)

IF %number%==14 (cd applet\chap05\StackAppletCode)
IF %number%==14 (java -jar StackApplet.jar)

IF %number%==15 (cd applet\chap06\CircularQueueAppletCode)
IF %number%==15 (java -jar CircularQueue.jar)

IF %number%==16 (cd applet\chap06\LinearQueueAppletCode)
IF %number%==16 (java -jar LinearQueue.jar)

IF %number%==17 (cd applet\chap06\LinkedQueueApplet)
IF %number%==17 (java -jar LinkedQueue.jar)

IF %number%==18 (cd applet\chap07\BinaryTreeTravCodeApplet)
IF %number%==18 (java -jar TreeTrav.jar)

IF %number%==19 (cd applet\chap07\BSTApplet)
IF %number%==19 (java -jar BSTApplet.jar)

IF %number%==20 (cd applet\chap07\BSTCodeApplet)
IF %number%==20 (java -jar BSTCodeApplet.jar)

IF %number%==21 (cd applet\chap08\HeapTreeCodeApplet)
IF %number%==21 (java -jar HeapTreeCodeApplet.jar)

IF %number%==22 (cd applet\chap09\HeapSort)
IF %number%==22 (java -jar GraphApplet.jar)

IF %number%==23 (cd applet\chap09\MergeSortApplet)
IF %number%==23 (java -jar SortApplet.jar)

IF %number%==24 (cd applet\chap09\RadixSort)
IF %number%==24 (java -jar GraphApplet.jar)

IF %number%==25 (cd applet\chap09\ShellSort)
IF %number%==25 (java -jar GraphApplet.jar)

IF %number%==26 (cd applet\chap09\SortAppletCode)
IF %number%==26 (java -jar GraphApplet.jar)

IF %number%==27 (cd applet\chap10\BfsDfsCodeApplet)
IF %number%==27 (java -jar GraphApplet.jar)

IF %number%==28 (cd applet\chap10\GraphTermsApplet)
IF %number%==28 (java -jar GraphApplet.jar)

IF %number%==29 (cd applet\chap10\MST)
IF %number%==29 (java -jar GraphApplet.jar)

IF %number%==30 (cd applet\chap10\ShortestPath)
IF %number%==30 (java -jar GraphApplet.jar)

IF %number%==31 (cd applet\chap10\topo)
IF %number%==31 (java -jar GraphApplet.jar)

IF %number%==32 (cd applet\chap11\HashChain)
IF %number%==32 (java -jar GraphApplet.jar)

IF %number%==33 (cd applet\chap11\HashLinear)
IF %number%==33 (java -jar LinearHash.jar)

IF %number%==34 (cd applet\chap12\SearchApplet)
IF %number%==34 (java -jar SearchApplet.jar)

IF %number%==35 (cd applet\chap12\Tree23)
IF %number%==35 (java -jar SearchApplet.jar)

IF %number%==36 (cd applet\chap12\TreeAVL)
IF %number%==36 (java -jar SearchApplet.jar)



