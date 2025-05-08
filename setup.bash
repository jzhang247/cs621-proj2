git clone https://github.com/jzhang247/ns3-fork.git ns3
cd ns3
git checkout -b dev



# git clone https://gitlab.com/nsnam/ns-3-dev.git ns3
# cd ns3
# git checkout -b ns-3.44-branch ns-3.44
# cp -rf ../submission/* ./


exit 0

# ./ns3 configure --enable-examples --enable-tests --cxx-standard 23
./ns3 configure --enable-examples --enable-tests
cp ./cmake-cache/compile_commands.json ./compile_commands.json
./ns3 build
./test.py
./ns3 run first
