FILE=sequences
g++ $FILE.cpp -o $FILE
echo "testing $FILE.cpp"

echo "101 1"
echo "101" | ./$FILE

echo "1101 2"
echo "1101" | ./$FILE

echo "?0? 3"
echo "?0?" | ./$FILE

echo "1??1 5"
echo "1??1" | ./$FILE

echo "??1 1"
echo "??1" | ./$FILE

echo "1?1 1"
echo "1?1" | ./$FILE

echo "0?0 1"
echo "0?0" | ./$FILE

echo "?1? 3"
echo "?1?" | ./$FILE

echo "1?1?1 7"
echo "1?1?1" | ./$FILE

echo "1?0?1 11"
echo "1?0?1" | ./$FILE

echo "1???1 18"
echo "1???1" | ./$FILE

echo "0?0?0 7"
echo "0?0?0" | ./$FILE

echo "???0 18"
echo "???0" | ./$FILE

echo "? 0"
echo "?" | ./$FILE

echo "?? 1"
echo "??" | ./$FILE

echo "??? 6"
echo "???" | ./$FILE

echo "???? 24"
echo "????" | ./$FILE

echo "????0??? 928"
echo "????0???" | ./$FILE

echo "1??0??1 88"
echo "1??0??1" | ./$FILE

echo "????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" | ./$FILE