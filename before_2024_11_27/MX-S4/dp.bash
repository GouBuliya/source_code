t=0
while true;do
let t++
echo "# "$t
./data
./bf
./text
if diff a.ans a.out -Z;then
	printf "AC\n"
else
	printf "WA\n"
	break
fi
sleep 0.1
done

