(* Fonctions *)

let rec list_sigma l = match l with
| [] -> 0
| a::l' -> a + list_sigma l'
;;

let rec mem l v = match l with
| [] -> false
| a::l' -> if(a=v) then true else mem l' v
;;

let rec map f l = match l with
| [] -> []
| a::l' -> (f a)::(map f l')
;;
let rec string_of_list l = match l with
| [] -> ""
| a::l' -> string_of_int(a) ^ string_of_list(l')
;;

let rec liste_min l = match l with
| [] -> failwith "Liste vide"
| [a] -> a
| a::l' -> min a (liste_min l')
;;

let rec is_sorted l = match l with
| a::(b::l' as l0) -> a <= b && (is_sorted l0) 
| _ -> true
;;

let rec append l1 l2 = match l1 with
| [] -> l2
| a::l1' -> a::(append l1' l2)
;;

let rec rev l = match l with
| [] -> []
| a::l' -> (rev l')@[a]
;;

let rec flatten l = match l with
| [] -> []
| a::l' -> a@(flatten l')

let rec rotation_d l = match l with
| [] -> []
| [a] -> [a]
| a::b::l' -> b::a::l'
;;

let rec moyenne_annexe l somme n= match l with
| [] -> somme / n
| a::l' -> moyenne_annexe l' (somme + a) (n+1)
;;

let moyenne l = match l with
| []-> failwith "Liste vide\n"
| _ -> moyenne_annexe l 0 0;;

(* Main *)

let l = [1; 2; 3; 4; 5];;

print_string("List_sigma : " ^ string_of_int(list_sigma l) ^ "\n");;

let v = 8;;
print_string("La liste contient " ^ string_of_int(v) ^ " ? " ^ string_of_bool(mem l v) ^ "\n");;

print_string("Exercice 3 : " ^ string_of_list(let succ x = x + 1 in map succ [1; 2; 3]) ^ "\n");;

print_string(string_of_int (liste_min l));;

print_string(string_of_list(l) ^ " est elle triée " ^ string_of_bool(is_sorted l) ^ "\n");;

print_string("On renverse l " ^ string_of_list(rev l) ^"\n");;

let l2 = [[2];[];[3;4;5]];;
print_string("Test de flatten : " ^ string_of_list(flatten l2) ^"\n");;

print_string("Rotation droite de l " ^ string_of_list(rotation_d l));;

print_string("Moyenne des elements de l " ^ string_of_int(moyenne l) ^ "\n");;

