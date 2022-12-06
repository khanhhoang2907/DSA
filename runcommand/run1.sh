cd ..
cd source_code
g++ main.cpp functions.cpp -o main
echo couting-sort=================================================
./main -a counting-sort input.txt -both

echo selection-sort =================================================
./main -a selection-sort input.txt -both



echo insertion-sort =================================================
./main -a insertion-sort input.txt -both

echo bubble-sort =================================================
./main -a bubble-sort input.txt -both

echo shaker-sort =================================================
./main -a shaker-sort input.txt -both

echo shell-sort =================================================
./main -a shell-sort input.txt -both

echo heap-sort =================================================
./main -a heap-sort input.txt -both

echo merge-sort =================================================
./main -a merge-sort input.txt -both

echo radix-sort =================================================
./main -a radix-sort input.txt -both

echo flash-sort =================================================
./main -a flash-sort input.txt -both

echo quick-sort =================================================
./main -a quick-sort input.txt -both