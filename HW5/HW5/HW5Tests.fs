open System
open HW5

[<EntryPoint>]
let main argv =
    // Problem 1:  Evaluating expressions
    let fexprs = [X;
              Const 100.17;
              Add(Const 3.1, X);
              Sub(Const 3.1, X);
              Mul(Const 3.1, X);
              Div(Const 3.1, X);
              Sin X;
              Cos X;
              Exp X;
              Log X;
              Div(X, Log X);
              Div(Sin X, X);
              Div(X, Log X);
              Div(Sin(Exp (Mul(X,Log X))),Cos X)]
    let xs = [-10.0; -5.0; -1.0; -0.5; 0.0; 0.5; 1.0; 5.0; 10.0]
    let printRow f xs =
        printf "%-34s:" (toString f)
        List.iter (fun x -> printf "%10.3f " (eval x f)) xs
        printfn "" // print newline
    List.iter (fun f -> printRow f xs) fexprs

    let t3 = Node(Node(Leaf, -3, Leaf), 0, Node(Leaf, 2, Leaf))
    let t4 = Node(t3, 5, Node(Leaf, 7, Leaf))
    let t5 = Node(t4, 8, Node(Node(Leaf, 10, Leaf), 12, Node(Leaf, 14, Node(Leaf, 15, Node(Leaf, 20, Leaf)))))
    
    // Problem 2:  Tree traversal
    printfn "levelOrder t3 = %A" (levelOrder t3)
    printfn "levelOrder t4 = %A" (levelOrder t4)
    printfn "levelOrder t5 = %A" (levelOrder t5)
    
    // Problem 3:  Creating a SizedBinTree
    printfn "binTree2SizedBinTree t3 = %A" (binTree2SizedBinTree t3)
    printfn "binTree2SizedBinTree t4 = %A" (binTree2SizedBinTree t4)
    printfn "binTree2SizedBinTree t5 = %A" (binTree2SizedBinTree t5)
    
    // Problem 4:  Searching a SizedBinTree
    let sbt = (binTree2SizedBinTree t5)
    List.iter (fun index -> printfn "element in t4 at index %d is %A" index (getOptionFromSizedBinTree index sbt)) [-2..(size sbt + 1)]
    
    let cmp = Ser(Par(Comp 0.25, Comp 1.0), Comp 1.5)
    let cmp2 = (Ser (Comp 0.50, Par(Ser(Comp 1.0, cmp), Par(cmp, cmp))))
    
    // Problem 5:  Sum of circuit components
    printfn "sum cmp = %f" (sum cmp)
    printfn "sum cmp2 = %f" (sum cmp2)
    
    // Problem 6:  Sum along cheapest path
    printfn "sumAlongCheapestPath cmp = %f" (sumAlongCheapestPath cmp)
    printfn "sumAlongCheapestPath cmp2 = %f" (sumAlongCheapestPath cmp2)
    0 // return an integer exit code
