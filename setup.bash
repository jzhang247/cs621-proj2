git clone https://gitlab.com/nsnam/ns-3-dev.git ns3
(cd ns3 & git checkout -b ns-3.44-branch ns-3.44)
cp -rf ./submission/* ./ns3/
cd ns3
pwd
./ns3 configure --enable-examples --enable-tests --cxx-standard 23
cp ./cmake-cache/compile_commands.json ./compile_commands.json
./ns3 build
# ./test.py
./ns3 run first