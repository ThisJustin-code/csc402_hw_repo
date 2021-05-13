module HW4

open System

type Polynomial = (float * int) list

let listProduct list = List.fold (fun acc elem -> acc * elem) 1 list //problem1
let app ys zs = List.foldBack (fun x xs -> x::xs) ys zs //ys @ zs //problem2
let doubleList list = List.foldBack (fun acc elem -> acc::elem) list list //problem3
let backwardsAndForwardsList list = List.fold (fun acc elem -> elem::acc) list list //problem4
let evaluate (p:Polynomial) x = List.fold (fun acc (e1, e2) -> acc + e1 * (pown x e2)) 0.0 p //problem5
let dom s = Set.fold (fun acc (a, _) -> Set.add a acc) Set.empty s //problem6
let mapDom m = Map.fold (fun acc a _ -> Set.add a acc) Set.empty m //problem7
let sumOfRangeElts m = Map.fold (fun acc _ r -> acc + r) 0 m //problem8
let prefixKeysToValues (m:Map<string, int>) = Map.map (fun str r -> str + (string r)) m //problem9
let compose m1 m2 = Map.fold (fun acc a b -> if (Map.containsKey b m2) then Map.add a (Map.find b m2) acc else acc) Map.empty m1 //problem10



