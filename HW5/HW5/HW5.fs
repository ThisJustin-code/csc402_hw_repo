module HW5
open System

// Problem 1
type Fexpr =
    | Const of float
    | X
    | Add of Fexpr * Fexpr
    | Sub of Fexpr * Fexpr
    | Mul of Fexpr * Fexpr
    | Div of Fexpr * Fexpr
    | Sin of Fexpr
    | Cos of Fexpr
    | Log of Fexpr
    | Exp of Fexpr
let rec toString = function
    | Const x      -> string x
    | X            -> "x"
    | Add(fe1,fe2) -> "(" + (toString fe1) + ")" + "+" + "(" + (toString fe2) + ")"
    | Sub(fe1,fe2) -> "(" + (toString fe1) + ")" + "-" + "(" + (toString fe2) + ")"
    | Mul(fe1,fe2) -> "(" + (toString fe1) + ")" + "*" + "(" + (toString fe2) + ")"
    | Div(fe1,fe2) -> "(" + (toString fe1) + ")" + "/" + "(" + (toString fe2) + ")"
    | Sin fe       -> "sin(" + (toString fe) + ")"
    | Cos fe       -> "cos(" + (toString fe) + ")"
    | Log fe       -> "log(" + (toString fe) + ")"
    | Exp fe       -> "exp(" + (toString fe) + ")"    
let rec eval x = function
    | Const x      -> float x
    | X            -> x
    | Add(fe1,fe2) -> (eval x fe1) + (eval x fe2)
    | Sub(fe1,fe2) -> (eval x fe1) - (eval x fe2)
    | Mul(fe1,fe2) -> (eval x fe1) * (eval x fe2)
    | Div(fe1,fe2) -> (eval x fe1) / (eval x fe2)
    | Sin fe       -> Math.Sin(eval x fe)
    | Cos fe       -> Math.Cos(eval x fe)
    | Log fe       -> Math.Log(eval x fe)
    | Exp fe       -> Math.Exp(eval x fe)

// Problem 2
type BinTree<'a> =
    | Leaf
    | Node of BinTree<'a> * 'a * BinTree<'a>
let rec preOrder = function
    | Leaf          -> []
    | Node(tl,x,tr) -> x::(preOrder tl) @ (preOrder tr)
let rec inOrder = function
    | Leaf          -> []
    | Node(tl,x,tr) -> (inOrder tl) @ [x] @ (inOrder tr)
let rec postOrder = function
    | Leaf          -> []
    | Node(tl,x,tr) -> (postOrder tl) @ (postOrder tr) @ [x]
let levelOrder tree =    
    let rec levelOrderHelper = function
        | []                   -> []
        | Leaf::trees          -> levelOrderHelper trees
        | Node(tl,x,tr)::trees -> x::levelOrderHelper (trees @ [tl; tr])
    levelOrderHelper[tree]

// Problem 3
type SizedBinTree<'a> =
    | SizedLeaf
    | SizedNode of SizedBinTree<'a> * 'a * SizedBinTree<'a> * int
let size = function
    | SizedLeaf             -> 0
    | SizedNode(tl,x,tr,sz) -> sz
let rec binTree2SizedBinTree = function
    | Leaf          -> SizedLeaf
    | Node(tl,x,tr) -> SizedNode(binTree2SizedBinTree tl, x, binTree2SizedBinTree tr,
                                 size (binTree2SizedBinTree tl) + 1 + size (binTree2SizedBinTree tr))
    
// Problem 4
let rec getOptionFromSizedBinTree i = function
    | sbt when i < 0         -> None
    | sbt when i >= size sbt -> None
    | SizedLeaf              -> None
    | SizedNode(tl,x,tr,sz)  -> if i < size tl then getOptionFromSizedBinTree i tl
                                elif i = size tl then Some x
                                else getOptionFromSizedBinTree (i - ((size tl) + 1)) tr
                                
// Problem 5
type Circuit<'a> =
    | Comp of 'a
    | Ser of Circuit<'a> * Circuit<'a>
    | Par of Circuit<'a> * Circuit<'a>
let rec circRec (c,s,p) = function
    | Comp x -> c x
    | Ser (c1,c2) ->s (circRec (c,s,p) c1) (circRec (c,s,p) c2)
    | Par (c1,c2) ->p (circRec (c,s,p) c1) (circRec (c,s,p) c2)
let count circ = circRec ((fun _ -> 1), (+), (+)) circ : int
let resistance = circRec ((fun r -> r),(+),(fun r1 r2 -> 1.0/(1.0/r1 + 1.0/r2)))
let sum = circRec ((fun (r:float) -> r),(+),(+))

// Problem 6
let sumAlongCheapestPath = circRec ((fun (r:float) -> r),(+),(fun r1 r2 -> min r1 r2))   