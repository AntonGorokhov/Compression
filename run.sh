g++ helper.cpp -o helper -O2 -std=c++17
echo "Enter a line you want to endode : "
./helper > input.txt
./encode.sh
./analysis.sh
echo "If you want to see the encoding, type 'cat output.txt'"
echo "If you want to decode the message, type './decode.sh'" 
