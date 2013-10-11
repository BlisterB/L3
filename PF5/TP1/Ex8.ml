let rec ack m n =
if (m == 0) 
	then (n + 1) 
	else if (m > 0 && n == 0)
		then ack (m-1) 1
		else ack (m - 1) (ack m (n-1)) ;;

print_string("Ack 0 0 : " ^ string_of_int(ack 0 0) ^ "\n") ;;
print_string("Ack 1 1 : " ^ string_of_int(ack 1 1) ^ "\n") ;;
print_string("Ack 2 2 : " ^ string_of_int(ack 2 2) ^ "\n") ;;
