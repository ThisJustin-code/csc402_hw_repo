// Justin Gallagher
// HW3: F# Lists
// CSC 402 - 001
// 9/15/2020

open System

let rec count x xs =
    match xs with
    | [] -> 0
    | y::xs when y=x -> 1 + (count x xs)
    | _::xs -> 0  + (count x xs)
    //problem1
    
let rec keepSatisfiers f fs =
    match fs with
    | [] -> []
    | x::fs when f x -> x::(keepSatisfiers f fs)
    | _::fs -> (keepSatisfiers f fs)
    //problem2
    
let rec pairOfListsToListOfPairs = function
    | (x::xs,y::ys) -> (x,y)::pairOfListsToListOfPairs(xs,ys)
    | ([],ys) -> []
    | (xs,[]) -> []
    //problem3
    
let rec maxOfList = function
    | [] -> failwith "max of empty list undefined"
    | x::y::ls -> maxOfList((max x y)::ls)
    | [x] -> x
    //problem4
    
let rec merge xs ys =
    match (xs,ys) with
    | (x::xs,y::ys) when x<y -> x::(merge xs (y::ys))
    | (x::xs,y::ys) -> y::(merge (x::xs) ys)
    | (x::xs,[]) -> x::(merge xs ys)
    | ([],y::ys) -> y::(merge xs ys)
    | ([],[])-> []
    //problem5

[<EntryPoint>]
let main argv =
    printfn "Hello World from F#!"
    0 // return an integer exit code
