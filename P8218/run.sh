
g++ data.cpp -o data -O2 
g++ P8218_baoli.cpp -o a.out -O2 
g++ P8218.cpp -o b.out -O2 
while true;do
# data>data.in
./data
./a.out
./b.out
if diff ans.a ans.b;then
echo AC
else
echo WA
exit 0
fi
done
