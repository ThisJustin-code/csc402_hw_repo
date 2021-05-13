open System
open HW4

[<EntryPoint>]
let main argv =
    Console.Write("Enter the problem index (1-10): ")
    let index = (int (Console.ReadLine()))
    match index with
    |  1 -> printfn "listProduct [2;3;5;7] = %d" (listProduct [2;3;5;7])
            printfn "listProduct [] = %d" (listProduct [])
    |  2 -> printfn "app [1;2;3][4;5;6] = %A" (app [1;2;3][4;5;6])
    |  3 -> printfn "doubleList [1..4] = %A" (doubleList [1..4])
    |  4 -> printfn "backwardsAndForwardsList [1..4] = %A" (backwardsAndForwardsList [1..4])
    |  5 -> printfn "evaluate [(1.0,2);(2.0,1);(5.0,0)] 3.0 = %f" (evaluate [(1.0,2);(2.0,1);(5.0,0)] 3.0)
            printfn "evaluate [(3.5,4);(-3.0,0)] 2.1 = %f" (evaluate [(3.5,4);(-3.0,0)] 2.1)
            printfn "evaluate [] 4.0 = %f" (evaluate [] 4.0)
    |  6 -> printfn "dom (set [(\"Jill\",78);(\"Joe\",77);(\"Joe\",67);(\"Suzi\",66);(\"Zeke\",67);(\"Jill\",84)]) = %A"
              (dom (set [("Jill",78);("Joe",77);("Joe",67);("Suzi",66);("Zeke",67);("Jill",84)]))
            printfn "dom (Set.empty : ((int * float) Set)) = %A" (dom (Set.empty : ((int * float) Set)))
    |  7 -> printfn "mapDom (Map.ofList [(\"Jack\",11);(\"Jill\",12);(\"Hill\",23)]) = %A"
              (mapDom (Map.ofList [("Jack",11);("Jill",12);("Hill",23)]))
    |  8 -> printfn "sumOfRangeElts (Map.ofList [(\"Jack\",11);(\"Jill\",12);(\"Hill\",23)]) = %d"
              (sumOfRangeElts (Map.ofList [("Jack",11);("Jill",12);("Hill",23)]))
    |  9 -> printfn "prefixKeysToValues (Map.ofList [(\"Jack\",11);(\"Jill\",12);(\"Hill\",23)]) = %A"
              (prefixKeysToValues (Map.ofList [("Jack",11);("Jill",12);("Hill",23)]))
    | 10 -> printfn "compose (Map.add 2 5 (Map.add 1 3 (Map.add 0 2 Map.empty))) (Map.add 5 \"five\" (Map.add 3 \"three\" (Map.add 2 \"two\" Map.empty))) = %A"
              (compose (Map.add 2 5 (Map.add 1 3 (Map.add 0 2 Map.empty)))
                 (Map.add 5 "five" (Map.add 3 "three" (Map.add 2 "two" Map.empty))))
            printfn "compose (Map.ofList [(333,\"Jill\");(222,\"Hill\");(111,\"Jack\");(444,\"Jill\")]) (Map.ofList [(\"Jack\",32.7);(\"Jill\",31.6);(\"Fill\",46.2)]) = %A"
              (compose (Map.ofList [(333,"Jill");(222,"Hill");(111,"Jack");(444,"Jill")])
                 (Map.ofList [("Jack",32.7);("Jill",31.6);("Fill",46.2)]))
    | _ -> Console.WriteLine "Unrecognized problem index\n"
    0 // return an integer exit code
 